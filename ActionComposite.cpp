#include "ActionComposite.h"
#include "Battler.h"

ActionComposite::ActionComposite(Battler* user) : Action(user)
{
}

ActionComposite::~ActionComposite()
{
    int size = children.size();
    
    for (int i = 0; i < size; i++) {
        delete children[i];
    }
}

void ActionComposite::addChild(Action* action)
{
    children.push_back(action);
}

Action* ActionComposite::getChild(unsigned index)
{
    return ((index < children.size())? children[index] : 0);
}

void ActionComposite::execute()
{
    int size = children.size();
    
    for (int i = 0; i < size; i++) {
        children[i]->execute();
    }
}
