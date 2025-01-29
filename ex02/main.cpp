#include "ScavTrap.hpp"

int main() {
    ScavTrap zero("SC4V-TP_0");
    zero.takeDamage(4);
    zero.beRepaired(2);
    zero.takeDamage(10);
    zero.takeDamage(15);
    zero.beRepaired(20);
    zero.takeDamage(15);
    zero.guardGate();
    zero.takeDamage(15);
    zero.beRepaired(20);
    zero.beRepaired(20);
    zero.beRepaired(20);
    zero.beRepaired(20);
    zero.beRepaired(20);
    zero.beRepaired(20);
    zero.attack("SC4V-TP_2");
    zero.attack("SC4V-TP_3");
    zero.attack("SC4V-TP_4");
    zero.guardGate();
}
