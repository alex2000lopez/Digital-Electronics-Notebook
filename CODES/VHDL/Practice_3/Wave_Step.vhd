library ieee;
use ieee.std_logic_1164.all;

entity STEPPER_WS is
  port(CLK: in std_logic;
       DIR: in std_logic;
       MOTOR: out std_logic_vector(3 downto 0));
end STEPPER_WS;

architecture ARCH of STEPPER_WS is
  begin
    process(CLK)
      variable COUNT: std_logic_vector(3 downto 0);
        begin
          if(CLK'EVENT and CLK='1') then
            if(DIR='0') then
              case COUNT is
                when "0000" => COUNT := "1000";
                when "1000" => COUNT := "0001";
                when "0001" => COUNT := "0100";
                when "0100" => COUNT := "0010";
                when "0010" => COUNT := "1000";
                when others => COUNT := "0000";
              end case;
            else
              case COUNT is
                when "0000" => COUNT := "0010";
                when "0010" => COUNT := "0100";
                when "0100" => COUNT := "0001";
                when "0001" => COUNT := "1000";
                when "1000" => COUNT := "0010";
                when others => COUNT := "0000";
              end case;
            end if;
          end if;
          MOTOR <= COUNT;         
    end process;
end ARCH;