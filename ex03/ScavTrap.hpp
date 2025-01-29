#ifndef __SCAVTRAP_HPP__
#define __SCAVTRAP_HPP__

#include "ClapTrap.hpp"

class ScavTrap : public ClapTrap {
public:
    /* constructor */
    ScavTrap();
    ScavTrap(const std::string& name);
    ScavTrap(const ScavTrap& copy);
    ScavTrap& operator=(const ScavTrap& copy);

    /* destructor */
    virtual ~ScavTrap();

    /* general */
    void guardGate();

protected:
    /* getter */
    bool _getIsGateKeeperMode() const;

    /* setter */
    void _setIsGateKeeperMode(bool tf);

    /* support */
    bool _checkIsGateKeeperModeIsFalse() const;

    /* override */
    virtual void _initByCopy(const ClapTrap& copy);
    virtual void _init();
    virtual std::string _getClassName() const;

private:
    /* variable */
    bool _isGateKeeperMode;
};

#endif /* __SCAVTRAP_HPP__ */
