#ifndef __FRAGTRAP_HPP__
#define __FRAGTRAP_HPP__

#include "ClapTrap.hpp"

class FragTrap : virtual public ClapTrap {
public:
    /* constructor */
    FragTrap();
    FragTrap(const std::string& name);
    FragTrap(const FragTrap& copy);
    FragTrap& operator=(const FragTrap& copy);

    /* destructor */
    virtual ~FragTrap();

    /* general */
    void highFiveGuys();

protected:
    /* override */
    virtual void _init();
    virtual std::string _getClassName() const;
};

#endif /* __FRAGTRAP_HPP__ */
