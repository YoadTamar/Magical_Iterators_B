#include "MagicalContainer.hpp"

MagicalContainer::PrimeIterator::PrimeIterator(MagicalContainer& container): container(&container), index(0) {}
MagicalContainer::PrimeIterator::PrimeIterator(MagicalContainer& container, size_t index)
    : container(&container), index(index) {}
MagicalContainer::PrimeIterator::PrimeIterator(const PrimeIterator &other)
    : container(other.container), index(other.index) {}
MagicalContainer::PrimeIterator& MagicalContainer::PrimeIterator::operator=(const PrimeIterator& other) {
    if(this->container != other.container)
        throw std::runtime_error("error");
    if(this != &other) {
        this->container = other.container;
        this->index = other.index;
    }
    return *this;
}

int MagicalContainer::PrimeIterator::operator*() {
    return *(*container).primes[index];
}
bool MagicalContainer::PrimeIterator::operator==(const PrimeIterator& other_it) const {
    return this->index == other_it.index;
}
bool MagicalContainer::PrimeIterator::operator<(const PrimeIterator& other_it) const {
    return this->index < other_it.index;
}
bool MagicalContainer::PrimeIterator::operator>(const PrimeIterator& other_it) const {
    return this->index > other_it.index;
}
bool MagicalContainer::PrimeIterator::operator!=(const PrimeIterator& other_it) const {
    return !(*this == other_it);
}


MagicalContainer::PrimeIterator& MagicalContainer::PrimeIterator::operator++() {
    ++index;
    if(index > (*container).primes.size())
        throw std::runtime_error("out of bounds");
    return *this;
}

MagicalContainer::PrimeIterator MagicalContainer::PrimeIterator::begin() const{
    return PrimeIterator((*this->container),0);
}

MagicalContainer::PrimeIterator MagicalContainer::PrimeIterator::end() const{
    return PrimeIterator((*this->container), (*container).primes.size());
}