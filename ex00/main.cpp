#include "ClapTrap.hpp"

int main() {
    ClapTrap zero("CL4PTP_0");

    zero.attack("CL4PTP_1");
    zero.takeDamage(4);
    zero.beRepaired(2);
    zero.takeDamage(10);
    zero.takeDamage(15);
    zero.beRepaired(20);
    zero.takeDamage(15);
    zero.takeDamage(15);
    zero.beRepaired(20);
    zero.beRepaired(20);
    zero.beRepaired(20);
    zero.beRepaired(20);
    zero.beRepaired(20);
    zero.beRepaired(20);
    zero.attack("CL4PTP_2");
    zero.attack("CL4PTP_3");
    zero.attack("CL4PTP_4");
}
