#include "ASpell.hpp"

ASpell::ASpell(string name, string effects) : name(name), effects(effects) {}

const string &ASpell::getName() const { return name; }
const string &ASpell::getEffects() const { return effects; }

void ASpell::launch(ATarget &target)
{
    target.getHitBySpell(*this);
}