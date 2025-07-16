#ifndef ZOMBIE_HPP
# define Zombie_HPP

#include <iostream>
#include <new>
#include <string>

class Zombie
{
    private:
        std::string _name;
    
    public:
        Zombie(std::string name);
        ~Zombie();
        void announce(void);
};


Zombie* newZombie(std::string name);
void randomChump(std::string name);

#endif
