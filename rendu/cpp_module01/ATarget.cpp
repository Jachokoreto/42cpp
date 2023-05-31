#include "ATarget.hpp"

ATarget::ATarget(string type) : type(type) {}

const string &ATarget::getType() const { return type; }

void ATarget::getHitBySpell(ASpell &spell)
{
    cout << type << " has been " << spell.getEffects() << "!" << endl;
}