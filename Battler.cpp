#include "Battler.h"

#include <cstring>

Battler::Battler(int hp, int tp, int str, int skl, int stm, int spd, int lck) :
    hitPoints_(hp), curHitPoints_(hp), techPoints_(tp), curTechPoints_(tp),
    elemResistances_(0), elemWeaknesses_(0), defending_(false), ailment_(0)
{
    attributes[STR] = str;
    attributes[SKL] = skl;
    attributes[STM] = stm;
    attributes[SPD] = spd;
    attributes[LCK] = lck;
    memset(attrBuffs, 0, sizeof(int) * ATTRIBUTES_LEN);
}

Battler::Battler(const Battler& b) :
    hitPoints_(b.hitPoints()), techPoints_(b.techPoints()),
    curHitPoints_(b.hitPoints()), curTechPoints_(b.techPoints()),
    elemResistances_(b.elemResistances()), elemWeaknesses_(b.elemWeaknesses()),
    defending_(false), ailment_(0)
{
    attributes[STR] = b.strength();
    attributes[SKL] = b.skill();
    attributes[STM] = b.stamina();
    attributes[SPD] = b.speed();
    attributes[LCK] = b.luck();
    memset(attrBuffs, 0, sizeof(int) * ATTRIBUTES_LEN);
}

int Battler::hitPoints() const
{
    return hitPoints_;
}

int Battler::curHitPoints() const
{
    return curHitPoints_;
}

int Battler::techPoints() const
{
    return techPoints_;
}

int Battler::curTechPoints() const
{
    return curTechPoints_;
}

int Battler::strength() const
{
    return attributes[STR];
}

int Battler::skill() const
{
    return attributes[SKL];
}

int Battler::stamina() const
{
    return attributes[STM];
}

int Battler::speed() const
{
    return attributes[SPD];
}

int Battler::luck() const
{
    return attributes[LCK];
}

char Battler::elemResistances() const
{
    return elemResistances_;
}

char Battler::elemWeaknesses() const
{
    return elemWeaknesses_;
}

bool Battler::isDefending() const
{
    return defending_;
}

short Battler::ailment() const
{
    return ailment_;
}

void Battler::setHitPoints(int hp)
{
    hitPoints_ = hp;
}

void Battler::setCurHitPoints(int newHP)
{
    curHitPoints_ = (newHP < 0)? 0 : (newHP > hitPoints_)? hitPoints_ : newHP;
}

void Battler::setTechPoints(int tp)
{
    techPoints_ = tp;
}

void Battler::setCurTechPoints(int newTP)
{
    curTechPoints_ = (newTP < 0)? 0 : (newTP > techPoints_)? techPoints_ : newTP;
}

void Battler::setStrength(int str)
{
    attributes[STR] = str;
}

void Battler::setSkill(int skl)
{
    attributes[SKL] = skl;
}

void Battler::setStamina(int stm)
{
    attributes[STM] = stm;
}

void Battler::setSpeed(int spd)
{
    attributes[SPD] = spd;
}

void Battler::setLuck(int lck)
{
    attributes[LCK] = lck;
}

void Battler::setElemResitances(char resistances)
{
    elemResistances_ = resistances;
}

void Battler::setElemWeaknesses(char weaknesses)
{
    elemWeaknesses_ = weaknesses;
}

void Battler::setDefending(bool defending)
{
    defending_ = defending;
}

void Battler::setAilment(short ailment)
{
    ailment_ = ailment;
}

bool Battler::resists(char element) const
{
    return elemResistances_ & element;
}

bool Battler::isWeak(char element) const
{
    return elemWeaknesses_ & element;
}

bool Battler::isDead() const
{
    return curHitPoints_ <= 0;
}

int Battler::getBuff(AttributeIndex attr) const
{
    return attrBuffs[attr];
}

void Battler::addBuff(AttributeIndex attr, int buff){
    attrBuffs[attr] += buff;
}
