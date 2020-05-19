library ieee;
use ieee.std_logic_1164.all;

entity ENCODER is
    port(IR, CLK: IN std_logic;
         C: IN std_logic_vector(2 downto 0);
         L: OUT std_logic_vector(3 downto 0);
         Q: OUT std_logic_vector(3 downto 0);
         pulse: OUT std_logic);
end ENCODER;

architecture ARCH of ENCODER is
  signal l_temp: std_logic_vector(3 downto 0);
  begin
    pulse <= (C(0) OR C(1) OR C(2));
    process(CLK)
      begin
        if(CLK = '1' AND CLK'EVENT) then
          if IR = '1' then l_temp <= "0001";
            else l_temp(1) <= l_temp(0);
              l_temp(2) <= l_temp(1);
              l_temp(3) <= l_temp(2);
              l_temp(0) <= l_temp(3); 
          end if;
          if(pulse = '1') then
            if(l_temp(0) = '1' AND C(0)='1') then Q <= "0001";
              elsif(l_temp(1) = '1' AND C(0)='1') then Q <= "0100"; 
              elsif(l_temp(2) = '1' AND C(0)='1') then Q <= "0111"; 
              elsif(l_temp(3) = '1' AND C(0)='1') then Q <= "1100"; 
              elsif(l_temp(0) = '1' AND C(1)='1') then Q <= "0010";
              elsif(l_temp(1) = '1' AND C(1)='1') then Q <= "0101"; 
              elsif(l_temp(2) = '1' AND C(1)='1') then Q <= "1000"; 
              elsif(l_temp(3) = '1' AND C(1)='1') then Q <= "0000";
              elsif(l_temp(0) = '1' AND C(2)='1') then Q <= "0011";
              elsif(l_temp(1) = '1' AND C(2)='1') then Q <= "0110"; 
              elsif(l_temp(2) = '1' AND C(2)='1') then Q <= "1001"; 
              elsif(l_temp(3) = '1' AND C(2)='1') then Q <= "1111";
              else Q <= "1111";
            end if;
          end if; -- No else -> Q=Q0
        end if;
    end process;
    L <= l_temp;
end ARCH;