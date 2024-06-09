#include "Span.hpp"

Span::Span(size_t n) {
    this->N = n;
}

Span::Span(Span const & rhs) {
    *this = rhs;
}

Span & Span::operator=(Span const & src) {
    if (this != &src) {
        this->N = src.N;
        this->vec = src.vec;
    }
    return *this;
}

Span::~Span() {
}

void Span::addNumber(int valueToAdd) {
    if (this->vec.size() >= this->N)
        throw std::runtime_error("Span has reached its maximum capacity.");
    this->vec.push_back(valueToAdd);
}

size_t Span::shortestSpan() {
    if (this->vec.size() <= 1)
        throw std::runtime_error("the Span is empty or has only one element.");
    std::vector<int> vecCopy = this->vec;
    std::sort(vecCopy.begin(), vecCopy.end());
    int shortestSpan = vecCopy[vecCopy.size() - 1] - vecCopy[0];
    for (size_t i = 0; i < vecCopy.size() - 1; i++) {
        if (vecCopy[i + 1] - vecCopy[i] < shortestSpan)
            shortestSpan = vecCopy[i + 1] - vecCopy[i];
    }
    return shortestSpan;
}

size_t Span::longestSpan() {
    if (this->vec.size() <= 1)
        throw std::runtime_error("the Span is empty or has only one element.");
    std::vector<int> vecCopy = this->vec;
    std::sort(vecCopy.begin(), vecCopy.end());
    return vecCopy[vecCopy.size() - 1] - vecCopy[0];
}


