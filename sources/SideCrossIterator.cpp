#include "MagicalContainer.hpp"

MagicalContainer::SideCrossIterator::SideCrossIterator(MagicalContainer& container): container(&container), index(0) {}
MagicalContainer::SideCrossIterator::SideCrossIterator(MagicalContainer& container, size_t index)
    : container(&container), index(index) {}
MagicalContainer::SideCrossIterator::SideCrossIterator(const SideCrossIterator &other)
    : container(other.container), index(other.index) {}
MagicalContainer::SideCrossIterator& MagicalContainer::SideCrossIterator::operator=(const SideCrossIterator& other) {
    if(this->container != other.container)
        throw std::runtime_error("error");
    if(this != &other) {
        this->container = other.container;
        this->index = other.index;
    }
    return *this;
}

bool MagicalContainer::SideCrossIterator::operator<(const SideCrossIterator& other_it) const {
    return this->index < other_it.index;
}
bool MagicalContainer::SideCrossIterator::operator==(const SideCrossIterator& other_it) const {
    return this->index == other_it.index;
}
bool MagicalContainer::SideCrossIterator::operator>(const SideCrossIterator& other_it) const {
    return this->index > other_it.index;
}
bool MagicalContainer::SideCrossIterator::operator!=(const SideCrossIterator& other_it) const {
    return !(*this == other_it);
}
int MagicalContainer::SideCrossIterator::operator*() {
    return (*container).container[side_index];
}

MagicalContainer::SideCrossIterator& MagicalContainer::SideCrossIterator::operator++() {
    if(index >= (*container).container.size())
        throw std::runtime_error("out of bounds");
    ++index;
    if(index % 2 != 0)
        side_index = (*container).container.size() - 1 - index / 2;
    else
        side_index = index / 2;
    return *this;
} 

MagicalContainer::SideCrossIterator MagicalContainer::SideCrossIterator::begin() const{
    return SideCrossIterator((*this->container),0);
}
MagicalContainer::SideCrossIterator MagicalContainer::SideCrossIterator::end() const{
    return SideCrossIterator((*this->container), (*container).container.size());
}