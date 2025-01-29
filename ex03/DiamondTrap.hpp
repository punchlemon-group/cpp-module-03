#ifndef __DIAMONDTRAP_HPP__
#define __DIAMONDTRAP_HPP__

#include "ScavTrap.hpp"
#include "FragTrap.hpp"

class DiamondTrap : public FragTrap, public ScavTrap {
public:
    /* constructor */
    DiamondTrap();
    DiamondTrap(const std::string& name);
    DiamondTrap(const DiamondTrap& copy);
    DiamondTrap& operator=(const DiamondTrap& copy);

    /* destructor */
    ~DiamondTrap();

    /* genenral */
    void whoAmI() const;

    /* override */
    void attack(const std::string& target);


protected:
    /* getter */
    virtual const std::string& _getName() const;

    /* setter */
    virtual void _setName(const std::string& name);

    /* override */
    virtual void _init();
    virtual std::string _getClassName() const;

private:
    /* variable */
    std::string _name;

    void _initName();
};

#endif /* __DIAMONDTRAP_HPP__ */
