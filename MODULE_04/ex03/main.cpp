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
    atexit(lek);

    IMateriaSource *src = new MateriaSource(); // here we create a source of materia with 4 slots of meteria initialized to NULL
    src->learnMateria(new Ice()); // we add ice materia to source[0]
    src->learnMateria(new Cure()); // we add cure materia to source[1]

    ICharacter *tabi3a = new Character("tabi3a"); // here we create a character named tabi3a

    AMateria *tmp; // here we create a tmp materia pointer
    tmp = src->createMateria("ice"); // we have this ice materia at source[0] for tabi3a
    tabi3a->equip(tmp);
    tmp = src->createMateria("cure"); // we have this cure materia at source[1] for tabi3a
    tabi3a->equip(tmp);
    tmp = src->createMateria("ice"); // we have this cure materia at source[1] for tabi3a
    tabi3a->equip(tmp);
    tmp = src->createMateria("cure"); // we have this cure materia at source[1] for tabi3a
    tabi3a->equip(tmp);
    tmp = src->createMateria("ice"); // we have this cure materia at source[1] for tabi3a
    tabi3a->equip(tmp);

    // tabi3a->unequip(0); // unequip ice materia from tabi3a
    // tabi3a->unequip(1); // unequip cure materia from tabi3a
    // tabi3a->unequip(2); // unequip cure materia from tabi3a
    // tabi3a->unequip(3); // unequip cure materia from tabi3a
    ICharacter *bob = new Character("Forstman");

    tabi3a->use(0, *bob); // ice materia used on Forstman by tabi3a
    tabi3a->use(1, *bob); // cure materia used on Forstman by tabi3a

    delete bob;
    delete tabi3a;
    delete src;
    return 0;
}