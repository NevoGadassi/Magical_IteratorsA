#include "MisticalElementNode.hpp"
#include <string>

using namespace ariel;


MisticalElementNode::MisticalElementNode(int value)
{
    _value = value;
    _ascNext = nullptr;
    _ascBack = nullptr;
    _primeNext = nullptr;
    _primeBack = nullptr;
}


// getters
int MisticalElementNode::value() const {return _value; };
MisticalElementNode *MisticalElementNode::getAscNext() const { return _ascNext; };
MisticalElementNode *MisticalElementNode::getAscBack() const { return _ascBack; };
MisticalElementNode *MisticalElementNode::getPrimeNext() const {return _primeNext; };
MisticalElementNode *MisticalElementNode::getPrimeBack() const { return _primeBack; };

// setters
void MisticalElementNode::setAscNext(MisticalElementNode *next) {_ascNext = next; };
void MisticalElementNode::setAscBack(MisticalElementNode *next) {_ascBack = next; };
void MisticalElementNode::setPrimeNext(MisticalElementNode *next) {_primeNext = next; };
void MisticalElementNode::setPrimeBack(MisticalElementNode *next) {_primeBack = next; };

ostream& ariel::operator<<(ostream& os, const MisticalElementNode& node)
{
    return os << node._value;
}
