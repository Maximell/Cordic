----------------------------------------------------------------------------------
-- Company: 
-- Engineer: 
-- 
-- Create Date:    14:03:46 07/27/2015 
-- Design Name: 
-- Module Name:    Split - Behavioral 
-- Project Name: 
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


entity Split is
    Port ( register1 : in  STD_LOGIC_VECTOR (31 downto 0);
           register2 : in  STD_LOGIC_VECTOR (31 downto 0);
           argument_X : out  STD_LOGIC_VECTOR (13 downto 0);
           argument_Y : out  STD_LOGIC_VECTOR (13 downto 0);
           argument_Z : out  STD_LOGIC_VECTOR (13 downto 0);
           argument_i : out  STD_LOGIC_VECTOR (13 downto 0));
end Split;

architecture Behavioral of Split is

begin

argument_X <= register2(27 downto 14);
argument_Y <= register2(13 downto 0);
argument_Z <= register1(13 downto 0);
argument_i <= register1(27 downto 14);

end Behavioral;

