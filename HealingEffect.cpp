#include "HealingEffect.h"
#include "Battler.h"

#include <cstdlib>

HealingEffect::HealingEffect(Battler* user, unsigned might, bool healsTP) :
    Effect(user), might_(might), healsTP_(healsTP)
{
}

unsigned HealingEffect::might() const
{
    return might_;
}

bool HealingEffect::healsTP() const
{
    return healsTP_;
}

void HealingEffect::apply(Battler* target)
{
    unsigned finalMight = might_;
    int diceRoll = rand() % 100;
    
    if (diceRoll < 10) {
        /// Add 10% of user skill to finalMight
        finalMight += user_->skill() * 0.1;
    }
    
    /// Heals target.
    if (healsTP_) {
        target->setCurTechPoints(target->curTechPoints() + finalMight);
    } else {
        target->setCurHitPoints(target->curHitPoints() + finalMight);
    }
    /// TODO: Notify target healed finalMight hitPoints or techPoints.
}