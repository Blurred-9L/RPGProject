#ifndef STATUS_EFFECT_H
#define STATUS_EFFECT_H

#include "Effect.h"

class Battler;

class StatusEffect : public Effect {
protected:
    Ailment ailment_;
    bool healsAilment_;
    
public:
    StatusEffect(Battler* user, Ailment ailment, bool healsAilment = false, unsigned chance = 100);
    Ailment ailment() const;
    bool healsAilment() const;
    virtual void apply(Battler* target);
};

#endif /// STATUS_EFFECT_H