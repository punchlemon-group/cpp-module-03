#include "DiamondTrap.hpp"

/* public */
/* constructor */
DiamondTrap::DiamondTrap() : ClapTrap() {
    std::cout << _getClassName() << " default constructor called" << std::endl;
    _init();
    _initName();
}

DiamondTrap::DiamondTrap(const std::string& name) : ClapTrap(name) {
    std::cout << _getClassName() << " parameterized constructor called" << std::endl;
    _init();
    _initName();
}

DiamondTrap::DiamondTrap(const DiamondTrap& copy) : ClapTrap(copy), FragTrap(copy), ScavTrap(copy) {
    std::cout << _getClassName() << " copy constructor called" << std::endl;
}

DiamondTrap& DiamondTrap::operator=(const DiamondTrap& copy) {
    std::cout << _getClassName() << " copy assignment operator called" << std::endl;
    if (this != &copy) {
        _initByCopy(copy);
    }
    return *this;
}

/* destructor */
DiamondTrap::~DiamondTrap() {
    std::cout << _getClassName() << " destructor called" << std::endl;
}

/* genenral */
void DiamondTrap::whoAmI() const {
    std::cout << *this << " DiamondTrap name : " << _getName() << ", ClapTrap name : " << ClapTrap::_getName() << std::endl;
}

/* override */
void DiamondTrap::attack(const std::string& target) {
	ScavTrap::attack(target);
}


/* protected */
/* getter */
const std::string& DiamondTrap::_getName() const {
    return _name;
}

/* setter */
void DiamondTrap::_setName(const std::string& name) {
    _name = name;
}

/* override */
void DiamondTrap::_init() {
    _setHitPoints(FragTrap::_getHitPoints());
    _setEnergyPoints(ScavTrap::_getEnergyPoints());
    _setAttackDamage(FragTrap::_getAttackDamage());
}

std::string DiamondTrap::_getClassName() const {
    return "DiamondTrap";
}


/* private */
void DiamondTrap::_initName() {
    _setName(ClapTrap::_getName());
    ClapTrap::_setName(_getName() + "_clap_name");
}
