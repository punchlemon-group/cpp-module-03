#ifndef __CLAPTRAP_HPP__
#define __CLAPTRAP_HPP__

#include <iostream>
#include <string>

class ClapTrap {
    public:
        ClapTrap();
        ClapTrap(const std::string& name);
        ClapTrap(const ClapTrap& other);
        ClapTrap& operator=(const ClapTrap& other);
        friend std::ostream& operator<<(std::ostream& os, const ClapTrap& clapTrap);
        ~ClapTrap();
        std::string toString() const;
        virtual std::string getClassName() const;
        const std::string& getName() const;
        unsigned int getHitPoints() const;
        unsigned int getEnergyPoints() const;
        unsigned int getAttackDamage() const;
        void setName(const std::string& name);
        void setHitPoints(unsigned int hitPoints);
        void setEnergyPoints(unsigned int energyPoints);
        void setAttackDamage(unsigned int attackDamage);
        void decrementEnergyPoints();
        void addHitPoints(unsigned int addPoints);
        unsigned int subHitPoints(unsigned int subPoints);
        bool checkRemainingHitPoints() const;
        bool checkRemainingEnergyPoints() const;
        void attack(const std::string& target);
        void takeDamage(unsigned int amount);
        void beRepaired(unsigned int amount);
        virtual void printStatus() const;
    private:
        std::string _name;
        unsigned int _hitPoints;
        unsigned int _energyPoints;
        unsigned int _attackDamage;
};

#endif /* __CLAPTRAP_HPP__ */
