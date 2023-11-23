# include <iostream>
# include <string>

class EntityBase
{
    protected:
        std::string _name;
    public:
        EntityBase() : _name("default_name")
        {
            std::cout << "EntityBase default constructor called" << std::endl;
        }

        EntityBase(std::string name) : _name(name)
        {
            std::cout << "EntityBase parametrized constructor called" << std::endl;
        }
        

        ~EntityBase()
        {
            std::cout << "EntityBase destructor called" << std::endl;
        }

        std::string	getName(void) const
        {
            return (this->_name);
        }
};

class Monster : public EntityBase
{
    public:
        Monster() : EntityBase("XNAMEX")
        {
            std::cout << "Monster default constructor called" << std::endl;
        }

        ~Monster()
        {
            std::cout << "Monster destructor called" << std::endl;
        }
};

int main(void)
{
    Monster monster("monster");
    std::cout << monster.getName() << std::endl;
    return (0);
}