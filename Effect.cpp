#include "Effect.h"
#include "Battler.h"

Effect::Effect(Battler* user, unsigned chance) : user_(user),
    chance_(chance)
{
}

Battler& Effect::user() const
{
    return *user_;
}

unsigned Effect::chance() const
{
    return chance_;
}