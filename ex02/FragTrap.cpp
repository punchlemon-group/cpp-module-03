#include "FragTrap.hpp"

/* public */
/* constructor */
FragTrap::FragTrap() : ClapTrap() {
    std::cout << _getClassName() << " default constructor called" << std::endl;
    _init();
}

FragTrap::FragTrap(const std::string& name) : ClapTrap(name) {
    std::cout << _getClassName() << " parameterized constructor called" << std::endl;
    _init();
}

FragTrap::FragTrap(const FragTrap& copy) : ClapTrap(copy) {
    std::cout << _getClassName() << " copy constructor called" << std::endl;
}

FragTrap& FragTrap::operator=(const FragTrap& copy) {
    std::cout << _getClassName() << " copy assignment operator called" << std::endl;
    if (this != &copy) {
        _initByCopy(copy);
    }
    return *this;
}

/* destructor */
FragTrap::~FragTrap() {
    std::cout << _getClassName() << " destructor called" << std::endl;
}

/* general */
void FragTrap::highFiveGuys() {
    std::cout << *this << " says: \"High five, guys! ✋\"" << std::endl;
}

/* protected */
/* overrode */
void FragTrap::_init() {
    _setHitPoints(100);
    _setEnergyPoints(100);
    _setAttackDamage(30);
}

std::string FragTrap::_getClassName() const {
    return "FragTrap";
}
