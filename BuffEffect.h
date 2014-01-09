#ifndef BUFF_EFFECT_H
#define BUFF_EFFECT_H

#include "Effect.h"

class Battler;

class BuffEffect : public Effect {
protected:
    int buffRate_;
    Attribute attribute_;
    
public:
    BuffEffect(Battler* user, int buffRate, Attribute attribute);
    int buffRate() const;
    Attribute attribute() const;
    virtual void apply(Battler* target);
};

#endif /// BUFF_EFFECT_H