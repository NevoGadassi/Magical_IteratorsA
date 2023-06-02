#include "MagicalContainer.hpp"

using namespace ariel;


MagicalContainer::AscendingIterator::AscendingIterator(MagicalContainer& container)
    : _container(container)
{
    _stepsNo = 0;
    _pElement = nullptr;
};


MagicalContainer::AscendingIterator::~AscendingIterator(){};


MagicalContainer::AscendingIterator::AscendingIterator(AscendingIterator& other)
    : _container(other._container)
{
    *this = other;
};


MagicalContainer::AscendingIterator& MagicalContainer::AscendingIterator::operator=(const AscendingIterator& other)
{
    _container = other._container;
    _pElement = other._pElement;
    _stepsNo = other._stepsNo;

    return *this;
};


MagicalContainer::AscendingIterator& MagicalContainer::AscendingIterator::operator++()
{
    if(_pElement != nullptr)
    {
        _pElement = _pElement->getAscNext();
        _stepsNo++;
    }

    return *this;
};


int MagicalContainer::AscendingIterator::operator*()
{
    if(_pElement == nullptr) throw "Ilegal iterator";

    return _pElement->value();
};


bool MagicalContainer::AscendingIterator::operator!=(const AscendingIterator& other) const
{
    return _pElement != other._pElement;
};


bool MagicalContainer::AscendingIterator::operator==(const AscendingIterator& other) const
{
    return !(*this != other);
};


bool MagicalContainer::AscendingIterator::operator>(const AscendingIterator& other) const
{
    return _stepsNo > other._stepsNo;
};


bool MagicalContainer::AscendingIterator::operator<(const AscendingIterator& other) const
{
    return _stepsNo < other._stepsNo;
};


MagicalContainer::AscendingIterator MagicalContainer::AscendingIterator::begin()
{
    AscendingIterator newIterator(_container);
    newIterator._pElement = _container._head;

    return newIterator;
};


MagicalContainer::AscendingIterator MagicalContainer::AscendingIterator::end()
{
    return AscendingIterator(_container);
};
