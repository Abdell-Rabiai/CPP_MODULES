# include "Character.hpp"

void add_materia(t_materia **materia, AMateria *new_materia, int index)
{
    t_materia *new_node;
    t_materia *current;

    new_node = new t_materia;
    new_node->materia = new_materia;
    new_node->index = index;
    new_node->next = NULL;
    if (!(*materia))
        *materia = new_node;
    else
    {
        current = *materia;
        while (current->next)
            current = current->next;
        current->next = new_node;
    }
}

void free_materia_list(t_materia **materia)
{
    t_materia *current;
    t_materia *next;

    if (!(*materia))
        return ;
    current = *materia;
    while (current)
    {
        next = current->next;
        delete current->materia;
        delete current;
        current = next;
    }
    *materia = NULL;
}


Character::Character() : _name("Tabi3a")
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
    for (int i = 0; i < 4; i++)
        this->_slots[i] = NULL;
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
            this->_slots[i] = rhs._slots[i] ? rhs._slots[i]->clone() : NULL;
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
    free_materia_list(&this->unequiped_materias);
}

std::string const & Character::getName() const {
    return (this->_name);
}

void Character::setName(std::string const & name) {
    this->_name = name;
}

void Character::equip(AMateria *materia)
{
    for (int i = 0; i < 4; i++)
    {
        if (!this->_slots[i] && materia)
        {
            this->_slots[i] = materia->clone();
            std::cout << "the Materia {" << materia->getType() << "} Equiped at slot ["<< i <<"] Successfully for " << this->getName() << std::endl;
            delete materia;
            return ;
        }
    }
    delete materia; /*ADDED*/
}

void Character::unequip(int index)
{
    if (index >= 0 && index <= 3)
    {
        if (this->_slots[index])
        {
            std::cout << "the Materia {" << this->_slots[index]->getType() << "} Unequiped from slot ["<< index <<"] Successfully for " << this->getName() << std::endl;
            // I save the adresses of the unequiped materias in a list to delete them in the destructor later
            add_materia(&this->unequiped_materias, this->_slots[index], index);
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
        {
            std::cout << "\001\033[1;35m\002\n" << this->getName() << " ==> \001\033[0m\002";
            this->_slots[index]->use(target);
        }
        else
            std::cout << "the user {" << this->getName() << "} has no materia at slot ["<< index <<"]" << std::endl;
    }
}
