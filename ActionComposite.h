#ifndef ACTION_COMPOSITE_H
#define ACTION_COMPOSITE_H

#include "Action.h"

#include <vector>
using std::vector;

class Battler;

class ActionComposite : public Action {
private:
    vector<Action*> children;
    
public:
    ActionComposite(Battler* user);
    virtual ~ActionComposite();
    void addChild(Action* action);
    Action* getChild(unsigned index);
    virtual void execute();
};

#endif /// ACTION_COMPOSITE_H