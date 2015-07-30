----------------------------------------------------------------------------------
-- Company: 
-- Engineer: 
-- 
-- Create Date:    13:14:15 07/27/2015 
-- Design Name: 
-- Module Name:    Compare - Behavioral 
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

-- Uncomment the following library declaration if using
-- arithmetic functions with Signed or Unsigned values
--use IEEE.NUMERIC_STD.ALL;

-- Uncomment the following library declaration if instantiating
-- any Xilinx primitives in this code.
--library UNISIM;
--use UNISIM.VComponents.all;

entity Compare is
    Port ( argument_Zi  : in  STD_LOGIC_VECTOR (13 downto 0);
           sign : out  STD_LOGIC);
end Compare;

architecture Behavioral of Compare is
	signal compare : std_logic := '0';
begin

	sign <= '1' when (argument_Zi(13) = '1') 
		else '0' when (argument_Zi(13) = '0')
		else 'Z';

end Behavioral;

