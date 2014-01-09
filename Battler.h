#ifndef BATTLER_H
#define BATTLER_H

#define ATTRIBUTES_LEN 5

class Battler { 
protected:
    int hitPoints_;
    int curHitPoints_;
    int techPoints_;
    int curTechPoints_;
    int attributes[ATTRIBUTES_LEN];
    int attrBuffs[ATTRIBUTES_LEN];
    char elemResistances_;
    char elemWeaknesses_;
    bool defending_;
    short ailment_;

public:
    enum AttributeIndex {
        STR = 0,
        SKL,
        STM,
        SPD,
        LCK
    };
    
    Battler(int hp, int tp, int str, int skl, int stm, int spd, int lck);
    Battler(const Battler& b);
    int hitPoints() const;
    int curHitPoints() const;
    int techPoints() const;
    int curTechPoints() const;
    int strength() const;
    int skill() const;
    int stamina() const;
    int speed() const;
    int luck() const;
    char elemResistances() const;
    char elemWeaknesses() const;
    bool isDefending() const;
    short ailment() const;
    void setHitPoints(int hp);
    void setCurHitPoints(int newHP);
    void setTechPoints(int tp);
    void setCurTechPoints(int newTP);
    void setStrength(int str);
    void setSkill(int skl);
    void setStamina(int stm);
    void setSpeed(int spd);
    void setLuck(int lck);
    void setElemResitances(char resistances);
    void setElemWeaknesses(char weaknesses);
    void setDefending(bool defending);
    void setAilment(short ailment);
    bool resists(char element) const;
    bool isWeak(char element) const;
    bool isDead() const;
    int getBuff(AttributeIndex attr) const;
    void addBuff(AttributeIndex attr, int buff);
};

#endif /// BATTLER_H