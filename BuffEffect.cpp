#include "BuffEffect.h"
#include "Battler.h"

BuffEffect::BuffEffect(Battler* user, int buffRate, Attribute attribute) :
    Effect(user), buffRate_(buffRate), attribute_(attribute)
{
}

int BuffEffect::buffRate() const
{
    return buffRate_;
}

Attribute BuffEffect::attribute() const
{
    return attribute_;
}

void BuffEffect::apply(Battler* target)
{
    Battler::AttributeIndex attrIndex;
    
    switch (attribute_) {
    case ATTR_STRENGTH:
        attrIndex = Battler::STR;
        break;
    case ATTR_SKILL:
        attrIndex = Battler::SKL;
        break;
    case ATTR_STAMINA:
        attrIndex = Battler::STM;
        break;
    case ATTR_SPEED:
        attrIndex = Battler::SPD;
        break;
    }
    /// Buffs or debuffs target.
    target->addBuff(attrIndex, buffRate_);
    /// TODO: Notify buff effect.
}