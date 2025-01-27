#include "ScavTrap.hpp"

ScavTrap::ScavTrap() : ClapTrap() {
    this->setHitPoints(100);
    this->setEnergyPoints(50);
    this->setAttackDamage(20);
    std::cout << this->getClassName() << " default constructor called" << std::endl;
}

ScavTrap::ScavTrap(const std::string& name) : ClapTrap(name) {
    this->setHitPoints(100);
    this->setEnergyPoints(50);
    this->setAttackDamage(20);
    std::cout << this->getClassName() << " parameterized constructor called" << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap& other)
: ClapTrap(other) {
    std::cout << this->getClassName() << " copy constructor called" << std::endl;
}

ScavTrap::~ScavTrap() {
    std::cout << this->getClassName() << " destructor called" << std::endl;
}

std::string ScavTrap::getClassName() const {
    return "ScavTrap";
}
