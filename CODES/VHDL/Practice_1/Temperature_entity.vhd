entity TEMP is
    port(temp: in std_logic_vector (3 downto 0);
         blue: out std_logic;
         green: out std_logic;  
         red: out std_logic
        );
  end TEMP;