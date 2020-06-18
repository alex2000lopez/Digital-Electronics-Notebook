library ieee;
use ieee.std_logic_1164.ALL;

entity SAFECODE is
  port (CLK : in std_logic;
        SIG : in std_logic_vector(3 downto 0); --Keypad input
        A : inout inTEGER range 0 TO 3; --Address input & output
        D : out std_logic_vector(3 downto 0); --Password output to RAM
        CS : out std_logic); --Chip select output
end SAFECODE;

architecture ARCH of SAFECODE is
  type STATE_type is (Q0, Q1, Q2, Q3); --State declaration
  signal STATE : STATE_type;
begin
  process(CLK)
  begin
    if (rising_edge(CLK)) then
      case STATE is --State 0, A=0, CS=1
        when Q0 => A <= 0;
          CS <= '1';
          if (SIG = "1100") then --if “*”
            STATE <= Q1; --Go to State 1
          else
            STATE <= Q0; --Stay in State 0
          end if;
        when Q1 => D <= SIG; --State 1, D=SIG, A=A, CS=0
          CS <= '0';
          A <= A;
          if (SIG = "1100") --if “*”
            STATE <= Q1; --Stay in State 1
          ELSif (SIG = "1111") then --if “#”
            STATE <= Q0; --Go back to State 0
          else --if not “#”
            STATE <= Q2; --Go to State 2
          end if;
        when Q2 => CS <= '1'; --State 1, D=SIG, A=A, CS=1
          if (D = SIG) then --if D=SIG
            STATE <= Q2; --Stay in State 2
          ELSif (SIG = "1111") then --if “#”
            STATE <= Q0; --Go to State 0
          else
            STATE <= Q3; --Go to State 3
          end if;
        when Q3 => A <= A + 1; --State 3, D=SIG, A=A+1, CS=1
          STATE <= Q1; --Go to State 1
      end case;
    end if;
  end process;
end ARCH;