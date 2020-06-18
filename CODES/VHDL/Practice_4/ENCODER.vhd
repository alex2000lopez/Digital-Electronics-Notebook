library ieee;
use ieee.std_logic_1164.all;

entity ENCODER is
  port(CLK, RST: in std_logic;
       AB: in std_logic_vector(1 downto 0);
       STEPPER: out std_logic_vector(3 downto 0));
end ENCODER;

architecture ARCH of ENCODER is
  type STATE_TYPE is (E0, E1, E2, E3);
  signal STATE: STATE_TYPE;
    begin
      process(CLK, RST)
        begin
          if(RST = '0') then STATE <= E0; 
            elsif(rising_edge(CLK)) then
              case STATE is
                when E0 => STEPPER <= "0110";
                           if(AB = "01") then STATE <= E1;
                             elsif(AB = "10") then STATE <= E3;
                           else STATE <= E0;
                           end if;
                when E1 => STEPPER <= "1010";
                           if(AB = "11") then STATE <= E2;
                             elsif(AB = "00") then STATE <= E0;
                           else STATE <= E1;
                            end if;
                when E2 => STEPPER <= "1001";
                           if(AB = "10") then STATE <= E3;
                             elsif(AB = "01") then STATE <= E1;
                           else STATE <= E2;
                           end if;
                when E3 => STEPPER <= "0101";
                           if(AB = "00") then STATE <= E0;
                             elsif(AB = "11") then STATE <= E2;
                           else STATE <= E3;
                           end if;
              end case;
          end if;
      end process;
end ARCH;
