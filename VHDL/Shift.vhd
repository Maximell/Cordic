----------------------------------------------------------------------------------
-- Company: 
-- Engineer: 
-- 
-- Create Date:    13:51:28 07/27/2015 
-- Design Name: 
-- Module Name:    Shift - Behavioral 
-- Project Name:  Seng 440 Cordic
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
use IEEE.NUMERIC_STD.ALL;

entity Shift is
    Port ( argument_1 : in  STD_LOGIC_VECTOR (13 downto 0);
           argument_i : in  STD_LOGIC_VECTOR (13 downto 0);
           result : out  STD_LOGIC_VECTOR (13 downto 0));
end Shift;

architecture Behavioral of Shift is

begin

	result <= to_stdlogicvector(to_bitvector(argument_1) sra to_integer(unsigned(argument_i)));

end Behavioral;

