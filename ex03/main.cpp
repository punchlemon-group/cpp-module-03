#include "FragTrap.hpp"

int main() {
    FragTrap zero("FR4G-TP_0");
    zero.takeDamage(4);
    zero.beRepaired(2);
    zero.takeDamage(10);
    zero.takeDamage(15);
    zero.beRepaired(20);
    zero.takeDamage(15);
    zero.highFiveGuys();
    zero.takeDamage(15);
    zero.beRepaired(20);
    zero.beRepaired(20);
    zero.beRepaired(20);
    zero.beRepaired(20);
    zero.beRepaired(20);
    zero.beRepaired(20);
    zero.attack("FR4G-TP_2");
    zero.attack("FR4G-TP_3");
    zero.attack("FR4G-TP_4");
    zero.highFiveGuys();
}
