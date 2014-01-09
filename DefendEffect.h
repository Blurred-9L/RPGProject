#ifndef DEFEND_EFFECT_H
#define DEFEND_EFFECT_H

#include "Effect.h"

class DefendEffect : public Effect {
public:
    explicit DefendEffect(Battler* user);
    virtual void apply(Battler* target);
};

#endif /// DEFEND_EFFECT_H