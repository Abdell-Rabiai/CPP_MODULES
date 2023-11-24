# include "AMateria.hpp"
# include "Ice.hpp"
# include "Cure.hpp"
# include "ICharacter.hpp"
# include "Character.hpp"
# include "IMateriaSource.hpp"
# include "MateriaSource.hpp"

void lek()
{
    system("leaks ex03");
}

int main()
{
    std::atexit(lek);

    IMateriaSource *src = new MateriaSource();
    src->learnMateria(new Ice());
    src->learnMateria(new Cure());

    ICharacter *tabi3a = new Character("tabi3a");

    AMateria *tmp;
    tmp = src->createMateria("ice"); // we have this ice materia at source[0] for tabi3a
    tabi3a->equip(tmp);
    tmp = src->createMateria("cure"); // we have this cure materia at source[1] for tabi3a
    tabi3a->equip(tmp);

    ICharacter *bob = new Character("Forstman");

    tabi3a->use(0, *bob); // ice materia used on Forstman by tabi3a
    tabi3a->use(1, *bob); // cure materia used on Forstman by tabi3a

    delete bob;
    delete tabi3a;
    delete src;

    std::cin.get();
    return 0;
}