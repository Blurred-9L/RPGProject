#ifndef ACTION_LEAF_H
#define ACTION_LEAF_H

#include "Action.h"

class Battler;
class Effect;

class ActionLeaf : public Action {
private:
    Battler** targets_;
    int nTargets_;
    Effect* effect_;
    
public:
    ActionLeaf(Battler* user, Battler** targets, int nTargets, Effect* effect);
    virtual ~ActionLeaf();
    Battler** targets() const;
    Battler* getTarget(unsigned index) const;
    int nTargets() const;
    Effect& effect() const;
    virtual void execute();
};

#endif /// ACTION_LEAF_H