#pragma once

#include <string>
#include <iostream>
using namespace std;

#include "ASpell.hpp"
class ASpell;

class ATarget
{
public:
    ATarget(string type);

    const string &getType() const;

    virtual ATarget *clone() const = 0;

    void getHitBySpell(ASpell &spell);

protected:
    string type;
};