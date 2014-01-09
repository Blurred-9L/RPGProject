#ifndef ATTACK_EFFECT_H
#define ATTACK_EFFECT_H

#include "Effect.h"

#define CRITICAL_MULT 1.5

class Battler;

class AttackEffect : public Effect {
protected:
    unsigned might_;
    bool canCritical_;
    Element element_;

public:    
    AttackEffect(Battler* user, unsigned chance, unsigned might, bool canCritical = false, Element element = ELEMENT_NONE);
    unsigned might() const;
    bool canCritical() const;
    Element element() const;
    virtual void apply(Battler* target);
};

#endif /// ATTACK_EFFECT_H