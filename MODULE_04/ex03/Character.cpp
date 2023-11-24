# include "Character.hpp"

Character::Character() : _name("default_name")
{
    // std::cout << "Character default constructor called" << std::endl;
    for (int i = 0; i < 4; i++)
        this->_slots[i] = NULL;
}

Character::Character(std::string const & name) : _name(name)
{
    // std::cout << "Character parametric constructor called" << std::endl;
    for (int i = 0; i < 4; i++)
        this->_slots[i] = NULL;
}

Character::Character(const Character &rhs)
{
    // std::cout << "Character copy constructor called" << std::endl;
    *this = rhs;
}

Character &Character::operator=(const Character &rhs)
{
    // std::cout << "Character assignation operator called" << std::endl;
    if (this != &rhs)
    {
        this->_name = rhs._name;
        for (int i = 0; i < 4; i++)
        {
            if (this->_slots[i])
                delete this->_slots[i];
            this->_slots[i] = rhs._slots[i]->clone();
        }
    }
    return (*this);
}

Character::~Character()
{
    // std::cout << "Character destructor called" << std::endl;
    for (int i = 0; i < 4; i++)
    {
        if (this->_slots[i])
            delete this->_slots[i];
    }
}

std::string const & Character::getName() const {
    return (this->_name);
}

void Character::equip(AMateria *materia)
{
    for (int i = 0; i < 4; i++)
    {
        if (this->_slots[i] == NULL)
        {
            this->_slots[i] = materia;
            std::cout << "the Materia {" << materia->getType() << "} Equiped at slot ["<< i <<"] Successfully for " << this->getName() << std::endl;
            return ;
        }
    }
}

void Character::unequip(int index)
{
    if (index >= 0 && index <= 3)
    {
        if (this->_slots[index])
        {
            std::cout << "the Materia {" << this->_slots[index]->getType() << "} Unequiped from slot ["<< index <<"] Successfully for " << this->getName() << std::endl;
            this->_slots[index] = NULL; //  the unequip() member function must NOT delete the Materia !!
            return ;
        }
    }
}

void Character::use(int index, ICharacter &target)
{
    if (index >= 0 && index <= 3)
    {   
        if (this->_slots[index])
            this->_slots[index]->use(target);
        else
            std::cout << "the Materia at slot ["<< index <<"] is EMPTY" << std::endl;
    }
}