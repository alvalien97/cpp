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
        Zombie();
        Zombie(std::string name);
        ~Zombie();

        void announce(void);
};

Zombie* zombieHorde(int N, std::string name);

#endif
