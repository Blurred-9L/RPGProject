#ifndef ACTION_H
#define ACTION_H

#define ACTION_TEXT_LEN 128

class Battler;

class Action {  
protected:
    Battler* user_;
public:
    Action(Battler* user);
    virtual ~Action();
    Battler& user() const;
    virtual void execute() = 0;
};

#endif /// ACTION_H