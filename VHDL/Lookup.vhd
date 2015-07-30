----------------------------------------------------------------------------------
-- Company: 
-- Engineer: 
-- 
-- Create Date:    13:30:12 07/27/2015 
-- Design Name: 
-- Module Name:    Lookup - Behavioral 
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


entity Lookup is
    Port ( argument_i : in  STD_LOGIC_VECTOR (13 downto 0);
           theta : out  STD_LOGIC_VECTOR (13 downto 0));
end Lookup;

architecture Behavioral of Lookup is

type lookup_array is array(13 downto 0) of STD_LOGIC_VECTOR(13 downto 0); 

constant table: lookup_array := (
    0 => "0110010010000111",
    1 => "0011101101011000",
    2 => "0001111101011010",
    3 => "0000111111101010",
    4 => "0000011111111100",
    5 => "0000001111111111",
    6 => "0000000111111111",
    7 => "0000000011111111",
    8 => "0000000001111111",
    9 => "0000000000111111",
    10 => "0000000000011111",
    11 => "0000000000001111",
    12 => "0000000000000111",
    13 => "0000000000000011"
);

begin


end Behavioral;

