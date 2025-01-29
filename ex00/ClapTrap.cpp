#include "ClapTrap.hpp"

/* public */
/* construcotr */
ClapTrap::ClapTrap() : _name("Unknown") {
    std::cout << _getClassName() << " default constructor called" << std::endl;
    _init();
}

ClapTrap::ClapTrap(const std::string& name) : _name(name) {
    std::cout << _getClassName() << " parameterized constructor called" << std::endl;
    _init();
}

ClapTrap::ClapTrap(const ClapTrap& copy) {
    std::cout << _getClassName() << " copy constructor called" << std::endl;
    _initByCopy(copy);
}

ClapTrap& ClapTrap::operator=(const ClapTrap& copy) {
    std::cout << _getClassName() << " copy assignment operator called" << std::endl;
    if (this != &copy) {
        _initByCopy(copy);
    }
    return *this;
}

/* destructor */
ClapTrap::~ClapTrap() {
    std::cout << _getClassName() << " destructor called" << std::endl;
}

/* general */
void ClapTrap::attack(const std::string& target) {
    if (_checkRemainingHitPoints() && _checkRemainingEnergyPoints()) {
        std::cout << *this << " attacks " << target << ", causing " << _getAttackDamage() << " points of damage!" << std::endl;
        _decrementEnergyPoints();
    }
}

void ClapTrap::takeDamage(unsigned int amount) {
    if (_checkRemainingHitPoints()) {
        std::cout << *this << " takes " << _subHitPoints(amount) << " points of damage!" << std::endl;
    }
}

void ClapTrap::beRepaired(unsigned int amount) {
    if (_checkRemainingEnergyPoints()) {
        std::cout << *this << " is repaired " << amount << " points!" << std::endl;
        _addHitPoints(amount);
        _decrementEnergyPoints();
    }
}

/* free */
std::ostream& operator<<(std::ostream& os, const ClapTrap& clapTrap) {
    os << clapTrap._toString();
    return os;
}


/* protected */
/* getter */
const std::string& ClapTrap::_getName() const {
    return _name;
}

unsigned int ClapTrap::_getHitPoints() const {
    return _hitPoints;
}

unsigned int ClapTrap::_getEnergyPoints() const {
    return _energyPoints;
}

unsigned int ClapTrap::_getAttackDamage() const {
    return _attackDamage;
}

/* setter */
void ClapTrap::_setName(const std::string& name) {
    _name = name;
}

void ClapTrap::_setHitPoints(unsigned int hitPoints) {
    _hitPoints = hitPoints;
}

void ClapTrap::_setEnergyPoints(unsigned int energyPoints) {
    _energyPoints = energyPoints;
}

void ClapTrap::_setAttackDamage(unsigned int attackDamage) {
    _attackDamage = attackDamage;
}

/* support */
bool ClapTrap::_checkRemainingHitPoints() const {
    if (_getHitPoints() == 0) {
        std::cout << *this << " has no hit points!" << std::endl;
        return false;
    } else {
        return true;
    }
}

bool ClapTrap::_checkRemainingEnergyPoints() const {
    if (_getEnergyPoints() == 0) {
        std::cout << *this << " has no energy points!" << std::endl;
        return false;
    } else {
        return true;
    }
}

void ClapTrap::_decrementEnergyPoints() {
    if (_getEnergyPoints() > 0) {
        _setEnergyPoints(_getEnergyPoints() - 1);
    }
}

void ClapTrap::_addHitPoints(unsigned int addPoints) {
    _setHitPoints(_getHitPoints() + addPoints);
}

unsigned int ClapTrap::_subHitPoints(unsigned int subPoints) {
    unsigned int damage = subPoints > _getHitPoints() ? _getHitPoints() : subPoints;
    _setHitPoints(_getHitPoints() - damage);
    return damage;
}

std::string ClapTrap::_toString() const {
    return _getClassName() + ' ' + _getName();
}

/* override */
void ClapTrap::_init() {
    _setHitPoints(10);
    _setEnergyPoints(10);
    _setAttackDamage(0);
}

void ClapTrap::_initByCopy(const ClapTrap& copy) {
    _setName(copy._getName());
    _setHitPoints(copy._getHitPoints());
    _setEnergyPoints(copy._getEnergyPoints());
    _setAttackDamage(copy._getAttackDamage());
}

std::string ClapTrap::_getClassName() const {
    return "ClapTrap";
}

// void ClapTrap::_printAll() const {
//     std::cout
//         << *this << " [ "
//         << "Hit Points: " << _getHitPoints() << ", "
//         << "Energy Points: " << _getEnergyPoints() << ", "
//         << "Attack Damage: " << _getAttackDamage()
//         << " ] " << std::endl;
// }
