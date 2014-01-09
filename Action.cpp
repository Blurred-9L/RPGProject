#include "Action.h"
#include "Battler.h"

Action::Action(Battler* user) : user_(user)
{
}

Action::~Action()
{
}

Battler& Action::user() const
{
    return *user_;
}