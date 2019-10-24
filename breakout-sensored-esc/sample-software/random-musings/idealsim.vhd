library ieee;
use ieee.std_logic_1164.all;
use ieee.numeric_std.all;

entity ideal_sim is
port
(
    ph1H  : in  std_logic;
    ph1L  : in  std_logic;
    ph2H  : in  std_logic;
    ph2L  : in  std_logic;
    ph3H  : in  std_logic;
    ph3L  : in  std_logic;
    hall1 : out std_logic;
    hall2 : out std_logic;
    hall3 : out std_logic;
);
end ideal_sim;

architecture rtl of ideal_sim is

    signal table_counter : std_logic_vector(7 downto 0);
    signal table_value : std_logic_vector(11 downto 0);

begin

    hall1 <=  "1" when ph1H = "1" else "0";
    hall2 <=  "1" when ph2H = "1" else "0";
    hall3 <=  "1" when ph3H = "1" else "0";
        
end;
