library ieee;
use ieee.std_logic_1164.all;

entity STEPPER_HS is
  port(CLK: in std_logic;
       DIR: in std_logic;
       MOTOR: out std_logic_vector(3 downto 0));
end STEPPER_HS;

architecture ARCH of STEPPER_HS is
  begin
    process(CLK)
      variable COUNT: std_logic_vector(3 downto 0);
        begin
          if(CLK'EVENT and CLK='1') then
            if(DIR='0') then
              case COUNT is
                when "0000" => COUNT := "1010";
                when "1010" => COUNT := "1000";
                when "1000" => COUNT := "1001";
                when "1001" => COUNT := "0001";
                when "0001" => COUNT := "0101";
                when "0101" => COUNT := "0100";
                when "0100" => COUNT := "0110";
                when "0110" => COUNT := "0010";
                when "0010" => COUNT := "1010";
                when others => COUNT := "0000";                            
              end case;
            else
              case COUNT is
                when "0000" => COUNT := "0010";
                when "0010" => COUNT := "0110";
                when "0110" => COUNT := "0100";
                when "0100" => COUNT := "0101";
                when "0101" => COUNT := "0001";
                when "0001" => COUNT := "1001";
                when "1001" => COUNT := "1000";
                when "1000" => COUNT := "1010";
                when "1010" => COUNT := "0010";
                when others => COUNT := "0000";
              end case;
            end if;
          end if;       
          MOTOR <= COUNT;      
    end process;
end ARCH;