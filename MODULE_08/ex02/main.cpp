# include "MutantStack.hpp"

int main() {
    MutantStack<int, std::vector<int> > mstack;

    mstack.push(5);
    mstack.push(17);

    std::cout << "top: " << mstack.top() << std::endl;

    mstack.pop();

    std::cout << "size: " << mstack.size() << std::endl;

    mstack.push(3);
    mstack.push(5);
    mstack.push(737);
    mstack.push(0);

    MutantStack<int>::it it = mstack.begin();
    MutantStack<int>::it ite = mstack.end();

    mstack.print();
    ++it; // incrementing iterator to skip first element
    --ite; // decrementing iterator to skip last element
    mstack.print(it, ite);

    std::stack<int, std::vector<int> > s(mstack);

    return 0;
}