#ifndef __CLAPTRAP_HPP__
#define __CLAPTRAP_HPP__

#include <iostream>
#include <string>

class ClapTrap {
public:
    /* constructor */
    ClapTrap();
    ClapTrap(const std::string& name);
    ClapTrap(const ClapTrap& copy);
    ClapTrap& operator=(const ClapTrap& copy);

    /* destructor */
    virtual ~ClapTrap();

    /* general */
    virtual void attack(const std::string& target);
    void takeDamage(unsigned int amount);
    void beRepaired(unsigned int amount);

protected:
    /* getter */
    const std::string& _getName() const;
    unsigned int _getHitPoints() const;
    unsigned int _getEnergyPoints() const;
    unsigned int _getAttackDamage() const;

    /* setter */
    void _setName(const std::string& name);
    void _setHitPoints(unsigned int hitPoints);
    void _setEnergyPoints(unsigned int energyPoints);
    void _setAttackDamage(unsigned int attackDamage);

    /* support */
    bool _checkRemainingHitPoints() const;
    bool _checkRemainingEnergyPoints() const;
    void _decrementEnergyPoints();
    void _addHitPoints(unsigned int addPoints);
    unsigned int _subHitPoints(unsigned int subPoints);
    std::string _toString() const;

    /* override */
    virtual void _initByCopy(const ClapTrap& copy);
    virtual void _init();
    virtual std::string _getClassName() const;
    //virtual void _printAll() const;

private:
    /* variable */
    std::string _name;
    unsigned int _hitPoints;
    unsigned int _energyPoints;
    unsigned int _attackDamage;
};

std::ostream& operator<<(std::ostream& os, const ClapTrap& clapTrap);

#endif /* __CLAPTRAP_HPP__ */
