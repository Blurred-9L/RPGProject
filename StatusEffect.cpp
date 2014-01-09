#include "StatusEffect.h"
#include "Battler.h"

#include <cstdlib>

StatusEffect::StatusEffect(Battler* user, Ailment ailment, bool healsAilment, unsigned chance) :
    Effect(user, chance), ailment_(ailment), healsAilment_(healsAilment)
{
}

Ailment StatusEffect::ailment() const
{
    return ailment_;
}

bool StatusEffect::healsAilment() const
{
    return healsAilment_;
}

void StatusEffect::apply(Battler* target)
{
    bool effectHit = false;
    int diceRoll = rand() % 100;
    
    effectHit = diceRoll < chance_;
    
    if (healsAilment_) {
        if (effectHit) {
            /// TODO: Notify ailment is gone.
            target->setAilment(target->ailment() ^ ailment_);
        } else {
            /// TODO: Notify healing failed.
        }
    } else {
        if (effectHit) {
            /// TODO: Notify ailment inflicted.
            target->setAilment(target->ailment() | ailment_);
        } else {
            /// TODO: Notify ailment missed.
        }
    }
}