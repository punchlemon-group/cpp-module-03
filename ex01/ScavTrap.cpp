#include "ScavTrap.hpp"

ScavTrap::ScavTrap() : ClapTrap() {
    this->_init();
    std::cout << this->getClassName() << " default constructor called" << std::endl;
}

ScavTrap::ScavTrap(const std::string& name) : ClapTrap(name) {
    this->_init();
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

void ScavTrap::setIsGateKeeperMode(bool tf) {
    _isGateKeeperMode = tf;
}

bool ScavTrap::getIsGateKeeperMode() const {
    return _isGateKeeperMode;
}

bool ScavTrap::checkIsGateKeeperModeIsFalse() const {
    if (this->getIsGateKeeperMode()) {
        std::cout << *this << " is already in gate keeper mode" << std::endl;
        return false;
    } else {
        return true;
    }
}

void ScavTrap::guardGate() {
    if (this->checkIsGateKeeperModeIsFalse() && this->checkRemainingEnergyPoints()) {
        this->setIsGateKeeperMode(true);
        this->decrementEnergyPoints();
        std::cout << *this << " went into gate keeper mode" << std::endl;
    }
}

void ScavTrap::_init() {
    this->setHitPoints(100);
    this->setEnergyPoints(50);
    this->setAttackDamage(20);
    this->setIsGateKeeperMode(false);
}
