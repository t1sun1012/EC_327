#ifndef MODEL_H
#define MODEL_H

#include <iostream>

#include "DemonHideout.h"
#include "GameObject.h"
#include "Mage.h"
#include "ManaSpire.h"

using namespace std;

class View;

class Model {
    private:
    int time;
    // The model owns every live game object and updates them all together.
    GameObject* object_ptrs[10];
    int num_objects;
    // Type-specific arrays support validated lookups for controller commands.
    Mage* mage_ptrs[10];
    int num_mages;
    ManaSpire* spire_ptrs[10];
    int num_spires;
    DemonHideout* hideout_ptrs[10];
    int num_hideouts;

    public:
    Model();
    ~Model();

    Mage* GetMagePtr(int id);
    ManaSpire* GetManaSpirePtr(int id);
    DemonHideout* GetDemonHideoutPtr(int id);
    bool Update();
    void Display(View& view);
    void ShowStatus();
};

#endif
