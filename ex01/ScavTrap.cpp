#include "ScavTrap.hpp"

/* public */
/* constructor */
ScavTrap::ScavTrap() : ClapTrap() {
    std::cout << _getClassName() << " default constructor called" << std::endl;
    _init();
}

ScavTrap::ScavTrap(const std::string& name) : ClapTrap(name) {
    std::cout << _getClassName() << " parameterized constructor called" << std::endl;
    _init();
}

ScavTrap::ScavTrap(const ScavTrap& copy) : ClapTrap(copy) {
    std::cout << _getClassName() << " copy constructor called" << std::endl;
}

ScavTrap& ScavTrap::operator=(const ScavTrap& copy) {
    std::cout << _getClassName() << " copy assignment operator called" << std::endl;
    if (this != &copy) {
        _initByCopy(copy);
    }
    return *this;
}

/* destructor */
ScavTrap::~ScavTrap() {
    std::cout << _getClassName() << " destructor called" << std::endl;
}

/* general */
void ScavTrap::guardGate() {
    if (_checkIsGateKeeperModeIsFalse() && _checkRemainingEnergyPoints()) {
        _setIsGateKeeperMode(true);
        _decrementEnergyPoints();
        std::cout << *this << " went into gate keeper mode" << std::endl;
    }
}


/* protected */
/* getter */
bool ScavTrap::_getIsGateKeeperMode() const {
    return _isGateKeeperMode;
}

/* setter */
void ScavTrap::_setIsGateKeeperMode(bool isGateKeeperMode) {
    _isGateKeeperMode = isGateKeeperMode;
}

/* support */
bool ScavTrap::_checkIsGateKeeperModeIsFalse() const {
    if (_getIsGateKeeperMode()) {
        std::cout << *this << " is already in gate keeper mode" << std::endl;
        return false;
    } else {
        return true;
    }
}

/* overrode */
void ScavTrap::_init() {
    _setHitPoints(100);
    _setEnergyPoints(50);
    _setAttackDamage(20);
    _setIsGateKeeperMode(false);
}

void ScavTrap::_initByCopy(const ClapTrap& copy) {
    ClapTrap::_initByCopy(copy);
    const ScavTrap& scavCopy = static_cast<const ScavTrap&>(copy);
    _setIsGateKeeperMode(scavCopy._getIsGateKeeperMode());
}

std::string ScavTrap::_getClassName() const {
    return "ScavTrap";
}
