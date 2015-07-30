----------------------------------------------------------------------------------
-- Company: 
-- Engineer: 
-- 
-- Create Date:    12:48:28 07/27/2015 
-- Design Name: 
-- Module Name:    AddAndSub - Behavioral 
-- Project Name: 	Seng 440 Cordic
-- Target Devices: 
-- Tool versions: 
-- Description: 
--
-- Dependencies: 
--
-- Revision: 
-- Revision 0.01 - File Created
-- Additional Comments: 
--
----------------------------------------------------------------------------------
library IEEE;
use IEEE.STD_LOGIC_1164.ALL;
use IEEE.STD_LOGIC_UNSIGNED.ALL;
use IEEE.STD_LOGIC_ARITH.ALL;
use IEEE.NUMERIC_STD.ALL;

entity AddAndSub is
    Port ( sign : in  STD_LOGIC;
           argument_1 : in  STD_LOGIC_VECTOR (13 downto 0);
           argument_2 : in  STD_LOGIC_VECTOR (13 downto 0);
           result : out  STD_LOGIC_VECTOR (13 downto 0));
end AddAndSub;

architecture Behavioral of AddAndSub is

-- Note: sign used to determine whether to add or subtract
begin
	result <= (argument_1 + argument_2) when sign = '1' 
		else (argument_1 - argument_2);
	

end Behavioral;

