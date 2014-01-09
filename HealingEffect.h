#ifndef HEALING_EFFECT_H
#define HEALING_EFFECT_H

#include "Effect.h"

class Battler;

class HealingEffect : public Effect {
protected:
    unsigned might_;
    bool healsTP_;
    
public:
    HealingEffect(Battler* user, unsigned might, bool healsTP = false);
    unsigned might() const;
    bool healsTP() const;
    virtual void apply(Battler* target);
};

#endif /// HEALING_EFFECT_H