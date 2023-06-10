#include "MagicalContainer.hpp"


void MagicalContainer::addElement(int number) {
    auto it = std::lower_bound(container.begin(), container.end(), number);
    container.insert(it, number);
    if(isPrime(number))
    {
        int *p = new int(number);
        auto p_it = std::lower_bound(this->primes.begin(), this->primes.end(), p, [](const int* a, const int* b) { return *a < *b; });
        primes.insert(p_it, p);
    }
}

void MagicalContainer::removeElement(int number) {
    for (auto it = container.begin(); it != container.end() ;it++) {
        if(*it == number) {
            this->container.erase(it);
            return;
        }
    }
    throw std::runtime_error("does not exist");
}

size_t MagicalContainer::size() const {
    size_t _size = container.size();
    return _size;
}

bool MagicalContainer::isPrime(int number)
{
    if(number == 2) return true;
    
    if(number <= 1) return false;

    if(number % 2 == 0) return false;

    for(int i = 3; i * i <= number; i++)
        if(number % i == 0) return false;
    
    return true;
}