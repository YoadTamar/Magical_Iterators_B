#include "MagicalContainer.hpp"

MagicalContainer::AscendingIterator::AscendingIterator(MagicalContainer& container): container(&container), index(0) {}
MagicalContainer::AscendingIterator::AscendingIterator(MagicalContainer& container, size_t index)
    : container(&container), index(index) {}
MagicalContainer::AscendingIterator::AscendingIterator(const AscendingIterator &other)
    : container(other.container), index(other.index) {}
MagicalContainer::AscendingIterator& MagicalContainer::AscendingIterator::operator=(const AscendingIterator& other) {
    if(this->container != other.container)
        throw std::runtime_error("error");
    if(this != &other) {
        this->container = other.container;
        this->index = other.index;
    }
    return *this;
}

bool MagicalContainer::AscendingIterator::operator<(const AscendingIterator& other_it) const 
{return this->index < other_it.index;}

bool MagicalContainer::AscendingIterator::operator==(const AscendingIterator& other_it) const 
{return this->index == other_it.index;}

bool MagicalContainer::AscendingIterator::operator>(const AscendingIterator& other_it) const {
    return this->index > other_it.index;
}
int MagicalContainer::AscendingIterator::operator*() {
    return (*container).container[index];
}

bool MagicalContainer::AscendingIterator::operator!=(const AscendingIterator& other_it) const 
{return !(*this == other_it);}

MagicalContainer::AscendingIterator& MagicalContainer::AscendingIterator::operator++() {
    this->index++;
    if(index > (*container).container.size())
        throw std::runtime_error("out of bounds");
    return *this;
}

MagicalContainer::AscendingIterator MagicalContainer::AscendingIterator::begin() const{
    return AscendingIterator(*this);
}
MagicalContainer::AscendingIterator MagicalContainer::AscendingIterator::end() const{
    return AscendingIterator((*this->container), (*container).size());
}