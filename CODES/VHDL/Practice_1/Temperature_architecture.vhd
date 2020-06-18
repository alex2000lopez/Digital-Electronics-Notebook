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