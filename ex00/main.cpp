#include "ClapTrap.hpp"

int main() {
    ClapTrap test("test");

    test.attack("test2");
    test.takeDamage(4);
    test.beRepaired(2);
    test.takeDamage(10);
    test.takeDamage(15);
    test.beRepaired(20);
    test.takeDamage(15);
    test.takeDamage(15);
    test.beRepaired(20);
    test.beRepaired(20);
    test.beRepaired(20);
    test.beRepaired(20);
    test.beRepaired(20);
    test.beRepaired(20);
    test.attack("test3");
    test.attack("test4");
    test.attack("test5");
}
