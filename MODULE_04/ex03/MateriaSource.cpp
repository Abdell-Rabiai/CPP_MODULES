# include "MateriaSource.hpp"

MateriaSource::MateriaSource()
{
    for (int i = 0; i < 4; i++)
        this->_materias[i] = NULL;
}

MateriaSource::MateriaSource(AMateria **materias)
{
    if (!materias)
        return ;
    for (int i = 0; i < 4; i++)
        this->_materias[i] = materias[i];
}

MateriaSource::MateriaSource(MateriaSource const &rhs)
{
    if (this != &rhs) {
        for (int i = 0; i < 4; i++)
            this->_materias[i] = NULL;
        *this = rhs;
    }
}

MateriaSource &MateriaSource::operator=(MateriaSource const &rhs)
{
    if (this != &rhs)
    {
        for (int i = 0; i < 4; i++)
        {
            if (this->_materias[i])
                delete this->_materias[i];
            this->_materias[i] = rhs._materias[i] ? rhs._materias[i]->clone() : NULL;
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
        if (!this->_materias[i] && m)
        {
            this->_materias[i] = m->clone();
            std::cout << "the Materia {" << m->getType() << "} Added at Source ["<< i <<"] Successfully" << std::endl;
            delete m;
            return ;
        }
    }
    delete m; /*ADDED*/
}

AMateria *MateriaSource::createMateria(std::string const &type)
{
    for (int i = 0; i < 4; i++)
    {
        if (this->_materias[i] && this->_materias[i]->getType() == type)
        {
            std::cout << "the Materia {" << type << "} Found at Source ["<< i <<"] Successfully and Created" << std::endl;
            return (this->_materias[i]->clone());
        }
    }
    std::cout << "the Materia {" << type << "} Not Found at Source, Be Careful!! " << std::endl;
    return (NULL);
}