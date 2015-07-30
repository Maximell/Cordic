----------------------------------------------------------------------------------
-- Company: 
-- Engineer: 
-- 
-- Create Date:    13:05:14 07/27/2015 
-- Design Name: 
-- Module Name:    Combine - Behavioral 
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

entity Combine is
    Port ( argument_X : in  STD_LOGIC_VECTOR (13 downto 0);
           argument_Y : in  STD_LOGIC_VECTOR (13 downto 0);
           result : out  STD_LOGIC_VECTOR (27 downto 0));
end Combine;

architecture Behavioral of Combine is

begin

result <= argument_X & argument_Y;

end Behavioral;

