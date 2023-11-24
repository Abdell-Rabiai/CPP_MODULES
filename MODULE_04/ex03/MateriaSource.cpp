# include "MateriaSource.hpp"

MateriaSource::MateriaSource()
{
    for (int i = 0; i < 4; i++)
        this->_materias[i] = NULL;
}

MateriaSource::MateriaSource(MateriaSource const &rhs)
{
    if (this != &rhs)
        *this = rhs;
}

MateriaSource &MateriaSource::operator=(MateriaSource const &rhs)
{
    if (this != &rhs)
    {
        for (int i = 0; i < 4; i++)
        {
            if (this->_materias[i])
                delete this->_materias[i];
            this->_materias[i] = rhs._materias[i]->clone();
        }
    }
    return (*this);
}

MateriaSource::~MateriaSource()
{
    for (int i = 0; i < 4; i++)
        if (this->_materias[i])
            delete this->_materias[i];
}

void MateriaSource::learnMateria(AMateria *m)
{
    for (int i = 0; i < 4; i++)
    {
        if (!this->_materias[i])
        {
            this->_materias[i] = m;
            std::cout << "the Materia {" << m->getType() << "} Added at Source ["<< i <<"] Successfully" << std::endl;
            return ;
        }
    }
}

AMateria *MateriaSource::createMateria(std::string const &type)
{
    for (int i = 0; i < 4; i++)
    {
        if (this->_materias[i] && this->_materias[i]->getType() == type)
        {
            std::cout << "the Materia {" << type << "} Found at Source ["<< i <<"] Successfully and returned" << std::endl;
            return (this->_materias[i]->clone());
        }
    }
    return (NULL);
}