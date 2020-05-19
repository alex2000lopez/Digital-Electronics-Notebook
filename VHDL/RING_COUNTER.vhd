library ieee;
use ieee.std_logic_1164.all;

entity ENCODER is
    port(IR: IN std_logic;
         CLK: IN std_logic;
         L: OUT std_logic_vector(3 downto 0)
        );
end ENCODER;

architecture ARCH of ENCODER is
    signal l_temp: std_logic_vector(3 downto 0);
    begin
        process(CLK)
            begin
                if(CLK = '1' AND CLK'EVENT) then
                    if IR = '1' then l_temp <= "0001";
                        else l_temp(1) <= l_temp(0);
                             l_temp(2) <= l_temp(1);
                             l_temp(3) <= l_temp(2);
                             l_temp(0) <= l_temp(3); 
                    end if;
        end process;
        L <= l_temp;
end ARCH;
