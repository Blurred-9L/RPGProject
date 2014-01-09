#include "ActionLeaf.h"
#include "Battler.h"
#include "Effect.h"

ActionLeaf::ActionLeaf(Battler* user, Battler** targets, int nTargets, Effect* effect) :
    Action(user), targets_(targets), nTargets_(nTargets), effect_(effect)
{
}

ActionLeaf::~ActionLeaf()
{
    if (targets_ != 0) {
        delete[] targets_;
    }
    if (effect_ != 0) {
        delete effect_;
    }
}

Battler** ActionLeaf::targets() const
{
    return targets_;
}

Battler* ActionLeaf::getTarget(unsigned index) const
{
    return ((index < nTargets_)? targets_[index] : 0);
}

int ActionLeaf::nTargets() const
{
    return nTargets_;
}

Effect& ActionLeaf::effect() const
{
    return *effect_;
}

void ActionLeaf::execute()
{
    int i;
    
    for (i = 0; i < nTargets_; i++) {
        effect_->apply(targets_[i]);
    }
}
