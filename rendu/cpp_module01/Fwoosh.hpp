#pragma once

#include "ASpell.hpp"

class ASpell
{
public:
    ASpell(string name, string effects);

    const string &getName() const;
    const string &getEffects() const;

    virtual ASpell *clone() const = 0;

    void launch(ATarget &target);

protected:
    string name;
    string effects;
};