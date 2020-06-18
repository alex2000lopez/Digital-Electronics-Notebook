library ieee;
use ieee.std_logic_1164.all;

entity STEPPER_FS is
  port(CLK: in std_logic;
       DIR: in std_logic;
       MOTOR: out std_logic_vector(3 downto 0));
end STEPPER_FS;

architecture ARCH of STEPPER_FS is
  begin
    process(CLK)
      variable COUNT: std_logic_vector(3 downto 0);
        begin
          if(CLK'EVENT and CLK='1') then
            if(DIR='0') then
              case COUNT is
                when "0000" => COUNT := "1010";
                when "1010" => COUNT := "1001";
                when "1001" => COUNT := "0101";
                when "0101" => COUNT := "0110";
                when "0110" => COUNT := "1010";
                when others => COUNT := "0000";
              end case;  
            else
              case COUNT is
                when "0000" => COUNT := "0110";
                when "0110" => COUNT := "0101";
                when "0101" => COUNT := "1001";
                when "1001" => COUNT := "1010";
                when "1010" => COUNT := "0110";
                when others => COUNT := "0000";
              end case;
            end if;
          end if; 
          MOTOR <= COUNT;        
    end process;
end ARCH;