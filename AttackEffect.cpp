#include "AttackEffect.h"
#include "Battler.h"

#include <cstdlib>

AttackEffect::AttackEffect(Battler* user, unsigned chance, unsigned might, bool canCritical, Element element) :
    Effect(user, chance), might_(might), canCritical_(canCritical), element_(element)
{
}

unsigned AttackEffect::might() const
{
    return might_;
}

bool AttackEffect::canCritical() const
{
    return canCritical_;
}

Element AttackEffect::element() const
{
    return element_;
}

void AttackEffect::apply(Battler* target)
{
    unsigned finalMight = might_;
    int diceRoll = rand() % 100;
    bool hitOk = false;
    
    if (diceRoll < 5) {
        /// Add 10% of user skill to finalMight
        finalMight += user_->skill() * 0.1;
    }
    /// Determines if attack hits or not.
    diceRoll = rand() % 100;
    hitOk = diceRoll < chance_;
    if (hitOk) {
        /// Determines if blow is critical.
        diceRoll = rand() % 100;
        if (canCritical_ && (diceRoll < user_->luck())) {
            finalMight *= CRITICAL_MULT;
            /// TODO: Notify attack landed critical hit.
        }
        /// Damage target.
        target->setCurHitPoints(target->hitPoints() - finalMight);
        /// TODO: Notify damage done to target.
        if (target->isDead()) {
            target->setAilment(AILMENT_DEATH);
            /// TODO: Notify that target is dead.
        }
    } else {
        /// TODO: Notify that attack missed.
    }
}