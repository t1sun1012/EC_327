#ifndef MODEL_H
#define MODEL_H

#include <fstream>
#include <iostream>
#include <list>

#include "DemonHideout.h"
#include "GameObject.h"
#include "Mage.h"
#include "ManaSpire.h"
#include "RoamingDemon.h"

using namespace std;

class View;

class Model {
    private:
    int time;
    // object_ptrs owns every object; active_ptrs tracks objects still updated/displayed.
    list<GameObject*> object_ptrs;
    list<GameObject*> active_ptrs;
    // Type-specific lists support validated lookups for controller commands.
    list<Mage*> mage_ptrs;
    list<ManaSpire*> spire_ptrs;
    list<DemonHideout*> hideout_ptrs;
    list<RoamingDemon*> roamingdemon_ptrs;

    public:
    Model();
    ~Model();

    Mage* GetMagePtr(int id);
    ManaSpire* GetManaSpirePtr(int id);
    DemonHideout* GetDemonHideoutPtr(int id);
    RoamingDemon* GetRoamingDemonPtr(int id);
    // Creates runtime objects for new TYPE ID X Y command.
    void NewCommand(char type, int id, Point2D location);
    void save(ofstream& file);
    void restore(ifstream& file);
    bool Update();
    void Display(View& view);
    void ShowStatus();
};

#endif
