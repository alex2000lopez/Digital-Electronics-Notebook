library ieee;
use ieee.std_logic_1164.all;
use ieee.std_logic_arith.all;
use ieee.std_logic_unsigned.all;

entity TEMP is
  port(temp: in std_logic_vector (3 downto 0);
       blue: out std_logic;
       green: out std_logic;  
       red: out std_logic
      );
end TEMP;

architecture SENSOR of TEMP is
  begin
    compare: process(temp)
      begin
      
        if(temp <= "1000") then
          blue <= '1';
          green <= '0';
          red <= '0';
          
          elsif(temp >= "1001" AND temp <= "1010") then
            blue <= '0';
            green <= '1';
            red <= '0';
            
            else
              blue <= '0';
              green <= '0';
              red <= '1';
              
        end if;
    end process;		
end SENSOR;