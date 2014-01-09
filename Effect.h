#ifndef EFFECT_H
#define EFFECT_H

enum Element {
    ELEMENT_NONE = 0,
    ELEMENT_FIRE = 0x01,
    ELEMENT_WATER = 0x02,
    ELEMENT_WIND = 0x04,
    ELEMENT_EARTH = 0x08,
    ELEMENT_LIGHT = 0x10,
    ELEMENT_DARK = 0x20
};

enum Attribute {
    ATTR_STRENGTH = 0x01,
    ATTR_SKILL = 0x02,
    ATTR_STAMINA = 0x04,
    ATTR_SPEED = 0x08,
    ATTR_ALL = 0x0F
};

enum Ailment {
    AILMENT_NONE = 0x0000,
    AILMENT_POISON = 0x0001,
    AILMENT_PARALYSIS = 0x0002,
    AILMENT_CURSE = 0x0004,
    AILMENT_BLIND = 0x0008,
    AILMENT_STONE = 0x0010,
    AILMENT_CONFUSE = 0x0020,
    AILMENT_ALL = 0x003F,
    AILMENT_DEATH = 0xFFFF
};

class Battler;

class Effect {
protected:
    Battler* user_;
    unsigned chance_;
    
public:
    Effect(Battler* user, unsigned chance = 100);
    Battler& user() const;
    unsigned chance() const;
    virtual void apply(Battler* target) = 0;
};

#endif /// EFFECT_H