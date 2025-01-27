#include "ClapTrap.hpp"

ClapTrap::ClapTrap()
: _name("Unknown"), _hitPoints(10), _energyPoints(10), _attackDamage(0) {
    std::cout << this->getClassName() << " default constructor called" << std::endl;
}

ClapTrap::ClapTrap(const std::string& name)
: _name(name), _hitPoints(10), _energyPoints(10), _attackDamage(0) {
    std::cout << this->getClassName() << " parameterized constructor called" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap& other)
: _name(other.getName()), _hitPoints(other.getHitPoints()), _energyPoints(other.getEnergyPoints()), _attackDamage(other.getAttackDamage()) {
    std::cout << this->getClassName() << " copy constructor called" << std::endl;
}

ClapTrap& ClapTrap::operator=(const ClapTrap& other) {
    std::cout << this->getClassName() << " copy assignment operator called" << std::endl;
    if (this != &other) {
        this->setName(other.getName());
        this->setHitPoints(other.getHitPoints());
        this->setEnergyPoints(other.getEnergyPoints());
        this->setAttackDamage(other.getAttackDamage());
    }
    return *this;
}

std::ostream& operator<<(std::ostream& os, const ClapTrap& clapTrap) {
    os << clapTrap.toString();
    return os;
}

ClapTrap::~ClapTrap() {
    std::cout << this->getClassName() << " destructor called" << std::endl;
}

std::string ClapTrap::toString() const {
    return this->getClassName() + ' ' + this->getName();
}

std::string ClapTrap::getClassName() const {
    return "ClapTrap";
}

const std::string& ClapTrap::getName() const {
    return _name;
}

unsigned int ClapTrap::getHitPoints() const {
    return _hitPoints;
}

unsigned int ClapTrap::getEnergyPoints() const {
    return _energyPoints;
}

unsigned int ClapTrap::getAttackDamage() const {
    return _attackDamage;
}

void ClapTrap::setName(const std::string& name) {
    if (this->getName() != name) {
        _name = name;
    }
}

void ClapTrap::setHitPoints(unsigned int hitPoints) {
    _hitPoints = hitPoints;
}

void ClapTrap::setEnergyPoints(unsigned int energyPoints) {
    _energyPoints = energyPoints;
}

void ClapTrap::setAttackDamage(unsigned int attackDamage) {
    _attackDamage = attackDamage;
}

void ClapTrap::decrementEnergyPoints() {
    if (this->getEnergyPoints() > 0) {
        this->setEnergyPoints(this->getEnergyPoints() - 1);
    }
}

void ClapTrap::addHitPoints(unsigned int addPoints) {
    this->setHitPoints(this->getHitPoints() + addPoints);
}

unsigned int ClapTrap::subHitPoints(unsigned int subPoints) {
    unsigned int damage = subPoints > this->getHitPoints() ? this->getHitPoints() : subPoints;
    this->setHitPoints(this->getHitPoints() - damage);
    return damage;
}

void ClapTrap::attack(const std::string& target) {
    if (this->getHitPoints() == 0) {
        std::cout << *this << " has no hit points!" << std::endl;
    } else if (this->getEnergyPoints() == 0) {
        std::cout << *this << " has no energy points!" << std::endl;
    } else {
        std::cout << *this << " attacks " << target << ", causing " << this->getAttackDamage() << " points of damage!" << std::endl;
        this->decrementEnergyPoints();
    }
}

void ClapTrap::takeDamage(unsigned int amount) {
    if (this->getHitPoints() == 0) {
        std::cout << *this << " has no hit points!" << std::endl;
    } else {
        std::cout << *this << " takes " << this->subHitPoints(amount) << " points of damage!" << std::endl;
    }
}

void ClapTrap::beRepaired(unsigned int amount) {
    if (this->getEnergyPoints() == 0) {
        std::cout << *this << " has no energy points!" << std::endl;
    } else {
        std::cout << *this << " is repaired " << amount << " points!" << std::endl;
        this->addHitPoints(amount);
        this->decrementEnergyPoints();
    }
}

void ClapTrap::printStatus() const {
    std::cout
        << *this << " [ "
        << "Hit Points: " << this->getHitPoints() << ", "
        << "Energy Points: " << this->getEnergyPoints() << ", "
        << "Attack Damage: " << this->getAttackDamage()
        << " ] " << std::endl;
}
