#include "DefendEffect.h"
#include "Battler.h"

DefendEffect::DefendEffect(Battler* user) : Effect(user)
{
}

void DefendEffect::apply(Battler* target)
{
    target->setDefending(true);
    /// TODO: Notify target is defending this turn.
}