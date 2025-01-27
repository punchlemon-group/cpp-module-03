#ifndef __SCAVTRAP_HPP__
#define __SCAVTRAP_HPP__

#include "ClapTrap.hpp"

class ScavTrap : public ClapTrap {
    public:
        ScavTrap();
        ScavTrap(const std::string& name);
        ScavTrap(const ScavTrap& other);
        ~ScavTrap();
        std::string getClassName() const;
        void guardGate();
        void setIsGateKeeperMode(bool tf);
        bool getIsGateKeeperMode() const;
        bool checkIsGateKeeperModeIsFalse() const;
    private:
        bool _isGateKeeperMode;
        void _init();
};

#endif /* __SCAVTRAP_HPP__ */
