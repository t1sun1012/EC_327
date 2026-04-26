#include <iostream>
#include <cmath>
#include <cstdlib>

#include "Mage.h"
#include "DemonHideout.h"
#include "ManaSpire.h"
#include "Model.h"

using namespace std;

double GetRandomAmountOfGP()
{
    // The handout asks for a random GP gain in the range [0.0, 2.0].
    return static_cast<double>(rand() % 21) / 10.0;
}

Mage::Mage() : GameObject('M')
{
    speed = 5;
    is_at_spire = false;
    is_in_hideout = false;
    mana = 20;
    experience = 0;
    gold_pieces = 0;
    battles_to_buy = 0;
    crystals_to_buy = 0;
    name = "Mage";
    current_spire = NULL;
    current_hideout = NULL;
    current_demon = NULL;
    state = STOPPED;
    cout << "Mage default constructed." << endl;
}

Mage::Mage(char in_code) : GameObject(in_code)
{
    speed = 5;
    is_at_spire = false;
    is_in_hideout = false;
    mana = 20;
    experience = 0;
    gold_pieces = 0;
    battles_to_buy = 0;
    crystals_to_buy = 0;
    name = "Mage";
    current_spire = NULL;
    current_hideout = NULL;
    current_demon = NULL;
    state = STOPPED;
    display_code = in_code;
    cout << "Mage constructed." << endl;
}

Mage::Mage(string in_name, int in_id, char in_code, unsigned int in_speed, Point2D in_loc)
    : GameObject(in_loc, in_id, in_code)
{
    speed = in_speed;
    is_at_spire = false;
    is_in_hideout = false;
    mana = 20;
    experience = 0;
    gold_pieces = 0;
    battles_to_buy = 0;
    crystals_to_buy = 0;
    name = in_name;
    current_spire = NULL;
    current_hideout = NULL;
    current_demon = NULL;
    state = STOPPED;
    cout << "Mage constructed" << endl;
}

Mage::~Mage()
{
    cout << "Mage destructed." << endl;
}

void Mage::SetupDestination(Point2D dest)
{
    destination = dest;

    if (GetDistanceBetween(destination, location) > 0) {
        // Precompute one step toward the destination
        delta = (destination - location) * (speed / GetDistanceBetween(destination, location));
    }
    else {
        delta = Vector2D();
    }
}

void Mage::LoseMovementMana()
{
    unsigned int mana_loss = 1;

    if (current_demon != NULL) {
        // a followed Mage spends one extra mana per move.
        mana_loss++;
        cout << "(" << display_code << ")(" << id_num << "): The Roaming Demon drains extra mana!" << endl;
    }

    // Avoid unsigned integer underflow when extra demon damage would exceed mana.
    if (mana <= mana_loss) {
        mana = 0;
    }
    else {
        mana -= mana_loss;
    }
}

bool Mage::UpdateLocation()
{
    Vector2D diff = destination - location;

    // move to the destination once the next step would reach or overshoot it.
    if (fabs(diff.x) <= fabs(delta.x) && fabs(diff.y) <= fabs(delta.y)) {
        location = destination;
        LoseMovementMana();
        gold_pieces += GetRandomAmountOfGP();
        cout << "(" << display_code << ")(" << id_num << "): I'm there!" << endl;
        return true;
    }

    location = location + delta;
    LoseMovementMana();
    gold_pieces += GetRandomAmountOfGP();
    cout << "(" << display_code << ")(" << id_num << "): step..." << endl;
    return false;
}

void Mage::StartMoving(Point2D dest)
{
    if (location.x == dest.x && location.y == dest.y) {
        cout << "(" << display_code << ")(" << id_num << "): I'm already there. See?" << endl;
        return;
    }

    if (IsKnockedOut()) {
        cout << "(" << display_code << ")(" << id_num << "): I am knocked out. I may move but you cannot see me." << endl;
        return;
    }

    // Leaving a building updates its occupancy before the Mage starts moving again.
    if (is_at_spire && current_spire != NULL) {
        current_spire->RemoveOneMage();
        is_at_spire = false;
        current_spire = NULL;
    }
    if (is_in_hideout && current_hideout != NULL) {
        current_hideout->RemoveOneMage();
        is_in_hideout = false;
        current_hideout = NULL;
    }

    SetupDestination(dest);
    state = MOVING;
    cout << "(" << display_code << ")(" << id_num << "): On my way." << endl;
}

void Mage::StartMovingToHideout(DemonHideout* hideout)
{
    if (IsKnockedOut()) {
        cout << "(" << display_code << ")(" << id_num << "): I am knocked out so I can't move to hideout..." << endl;
        return;
    }

    // If the Mage is already there, only sync the building relationship and state.
    if (location.x == hideout->GetLocation().x && location.y == hideout->GetLocation().y) {
        if (is_at_spire && current_spire != NULL) {
            current_spire->RemoveOneMage();
        }
        if (!is_in_hideout || current_hideout != hideout) {
            hideout->AddOneMage();
        }
        current_spire = NULL;
        is_at_spire = false;
        current_hideout = hideout;
        is_in_hideout = true;
        state = IN_HIDEOUT;
        cout << "(" << display_code << ")(" << id_num << "): I am already at the Demon Hideout!" << endl;
        return;
    }

    if (is_at_spire && current_spire != NULL) {
        current_spire->RemoveOneMage();
        is_at_spire = false;
        current_spire = NULL;
    }
    if (is_in_hideout && current_hideout != NULL) {
        current_hideout->RemoveOneMage();
        is_in_hideout = false;
    }

    current_hideout = hideout;
    SetupDestination(hideout->GetLocation());
    state = MOVING_TO_HIDEOUT;
    cout << "(" << display_code << ")(" << id_num << "): on my way to hideout " << hideout->GetId() << "." << endl;
}

void Mage::StartMovingToSpire(ManaSpire* spire)
{
    if (IsKnockedOut()) {
        cout << "(" << display_code << ")(" << id_num << "): I am knocked out so I should have gone to the spire.." << endl;
        return;
    }

    // If the Mage is already there, only sync the building relationship and state.
    if (location.x == spire->GetLocation().x && location.y == spire->GetLocation().y) {
        if (is_in_hideout && current_hideout != NULL) {
            current_hideout->RemoveOneMage();
        }
        if (!is_at_spire || current_spire != spire) {
            spire->AddOneMage();
        }
        current_hideout = NULL;
        is_in_hideout = false;
        current_spire = spire;
        is_at_spire = true;
        state = AT_SPIRE;
        cout << "(" << display_code << ")(" << id_num << "): I am already at the Spire!" << endl;
        return;
    }

    if (is_in_hideout && current_hideout != NULL) {
        current_hideout->RemoveOneMage();
        is_in_hideout = false;
        current_hideout = NULL;
    }
    if (is_at_spire && current_spire != NULL) {
        current_spire->RemoveOneMage();
        is_at_spire = false;
    }

    current_spire = spire;
    SetupDestination(spire->GetLocation());
    state = MOVING_TO_SPIRE;
    cout << "(" << display_code << ")(" << id_num << "): On my way to Spire " << spire->GetId() << endl;
}

void Mage::StartBattling(unsigned int num_battles)
{
    unsigned int available_battles;

    if (IsKnockedOut()) {
        cout << "(" << display_code << ")(" << id_num << "): I'm knocked out and out of mana so no more battles for me..." << endl;
        return;
    }

    if (state != IN_HIDEOUT || current_hideout == NULL) {
        cout << "(" << display_code << ")(" << id_num << "): I can only battle in a DemonHideout!" << endl;
        return;
    }

    if (current_hideout->GetNumBattlesRemaining() == 0) {
        cout << "(" << display_code << ")(" << id_num << "): Cannot battle! This DemonHideout has no more mages to battle!" << endl;
        return;
    }

    available_battles = num_battles;
    if (available_battles > current_hideout->GetNumBattlesRemaining()) {
        available_battles = current_hideout->GetNumBattlesRemaining();
    }

    if (!current_hideout->IsAbleToBattle(available_battles, gold_pieces, mana)) {
        cout << "(" << display_code << ")(" << id_num << "): Not enough money for battles" << endl;
        return;
    }

    // Reserve the requested battles now; the mana and gold update happens in Update().
    battles_to_buy = available_battles;
    current_hideout->DemonBattle(battles_to_buy);
    state = BATTLING_IN_HIDEOUT;
    cout << "(" << display_code << ")(" << id_num << "): Started to battle at the DemonHideout " << current_hideout->GetId()
         << " with " << battles_to_buy << " battles" << endl;
}

void Mage::StartRecoveringMana(unsigned int num_crystals)
{
    unsigned int available_crystals;

    if (state != AT_SPIRE || current_spire == NULL) {
        cout << "(" << display_code << ")(" << id_num << "): I can only recover mana at a Mana Spire!" << endl;
        return;
    }

    if (!current_spire->HasCrystals()) {
        cout << "(" << display_code << ")(" << id_num << "): Cannot recover! No crystal remaining in this Mana Spire" << endl;
        return;
    }

    available_crystals = num_crystals;
    if (available_crystals > current_spire->GetNumCrystalsRemaining()) {
        available_crystals = current_spire->GetNumCrystalsRemaining();
    }

    if (!current_spire->CanAffordCrystal(available_crystals, gold_pieces)) {
        cout << "(" << display_code << ")(" << id_num << "): Not enough money to recover mana." << endl;
        return;
    }

    // Reserve the available crystals now; the mana and gold update happens in Update().
    crystals_to_buy = current_spire->DistributeCrystals(available_crystals);
    state = RECOVERING_MANA;
    cout << "(" << display_code << ")(" << id_num << "): Started recovering " << crystals_to_buy
         << " crystals at Mana Spire " << current_spire->GetId() << endl;
}

void Mage::Stop()
{
    state = STOPPED;
    cout << "(" << display_code << ")(" << id_num << "): Stopping.." << endl;
}

bool Mage::IsKnockedOut()
{
    return mana == 0;
}

bool Mage::ShouldBeVisible()
{
    return !IsKnockedOut();
}

string Mage::GetName()
{
    return name;
}

void Mage::StartBeingFollowed(RoamingDemon* demon)
{
    // Prevent repeated contact checks from printing duplicate follow messages.
    if (current_demon == demon) {
        return;
    }

    current_demon = demon;
    cout << "(" << display_code << ")(" << id_num << "): A Roaming Demon is following me!" << endl;
}

bool Mage::HasRoamingDemon()
{
    return current_demon != NULL;
}

void Mage::ShowStatus()
{
    cout << name << " status: ";
    GameObject::ShowStatus();

    switch (state) {
        case STOPPED:
            cout << " stopped" << endl;
            break;
        case MOVING:
            cout << " moving at a speed of " << speed << " to destination " << destination
                 << " at each step of " << delta << "." << endl;
            break;
        case KNOCKED_OUT:
            cout << " knocked out" << endl;
            break;
        case AT_SPIRE:
            cout << " inside Mana Spire (" << current_spire->GetId() << ")" << endl;
            break;
        case IN_HIDEOUT:
            cout << " inside Demon Hideout (" << current_hideout->GetId() << ")" << endl;
            break;
        case MOVING_TO_SPIRE:
            cout << " heading to Mana Spire (" << current_spire->GetId() << ") at a speed of "
                 << speed << " at each step of " << delta << endl;
            break;
        case MOVING_TO_HIDEOUT:
            cout << " heading to DemonHideout (" << current_hideout->GetId() << ") at a speed of "
                 << speed << " at each step of " << delta << endl;
            break;
        case BATTLING_IN_HIDEOUT:
            cout << " battling in DemonHideout (" << current_hideout->GetId() << ")." << endl;
            break;
        case RECOVERING_MANA:
            cout << " recovering mana in Mana Spire (" << current_spire->GetId() << ")" << endl;
            break;
        default:
            cout << endl;
            break;
    }

    cout << "Mana: " << mana << endl;
    cout << "Gold Pieces: " << gold_pieces << endl;
    cout << "Experience: " << experience << endl;
    if (HasRoamingDemon()) {
        cout << "A Roaming Demon is following this Mage." << endl;
    }
}

bool Mage::Update()
{
    unsigned int experience_gained;
    unsigned int mana_recovered;

    // The Mage's behavior is driven by its current state.
    switch (state) {
        case STOPPED:
            return false;
        case MOVING:
            if (mana == 0) {
                cout << name << " is out of mana and can't move" << endl;
                state = KNOCKED_OUT;
                return true;
            }
            if (UpdateLocation()) {
                if (mana == 0) {
                    cout << name << " is out of mana and can't move" << endl;
                    state = KNOCKED_OUT;
                }
                else {
                    state = STOPPED;
                }
                return true;
            }
            if (mana == 0) {
                cout << name << " is out of mana and can't move" << endl;
                state = KNOCKED_OUT;
                return true;
            }
            return false;
        case MOVING_TO_HIDEOUT:
            if (mana == 0) {
                cout << name << " is out of mana and can't move" << endl;
                state = KNOCKED_OUT;
                return true;
            }
            if (UpdateLocation()) {
                if (mana == 0) {
                    cout << name << " is out of mana and can't move" << endl;
                    state = KNOCKED_OUT;
                }
                else {
                    state = IN_HIDEOUT;
                    current_hideout->AddOneMage();
                    is_in_hideout = true;
                    current_spire = NULL;
                    is_at_spire = false;
                }
                return true;
            }
            if (mana == 0) {
                cout << name << " is out of mana and can't move" << endl;
                state = KNOCKED_OUT;
                return true;
            }
            return false;
        case MOVING_TO_SPIRE:
            if (mana == 0) {
                cout << name << " is out of mana and can't move" << endl;
                state = KNOCKED_OUT;
                return true;
            }
            if (UpdateLocation()) {
                if (mana == 0) {
                    cout << name << " is out of mana and can't move" << endl;
                    state = KNOCKED_OUT;
                }
                else {
                    state = AT_SPIRE;
                    current_spire->AddOneMage();
                    is_at_spire = true;
                    current_hideout = NULL;
                    is_in_hideout = false;
                }
                return true;
            }
            if (mana == 0) {
                cout << name << " is out of mana and can't move" << endl;
                state = KNOCKED_OUT;
                return true;
            }
            return false;
        case AT_SPIRE:
            return false;
        case IN_HIDEOUT:
            return false;
        case BATTLING_IN_HIDEOUT:
            // apply the deferred battle transaction in one update tick
            mana -= current_hideout->GetManaCost(battles_to_buy);
            gold_pieces -= current_hideout->GetGoldCost(battles_to_buy);
            experience_gained = battles_to_buy * current_hideout->GetExperiencePerBattle();
            experience += experience_gained;
            cout << "** " << name << " completed " << battles_to_buy << " battle(s)! **" << endl;
            cout << "** " << name << " gained " << experience_gained << " experience! **" << endl;
            state = IN_HIDEOUT;
            return true;
        case RECOVERING_MANA:
            // apply the deferred crystal purchase in one update tick
            mana_recovered = crystals_to_buy * 5;
            mana += mana_recovered;
            gold_pieces -= current_spire->GetCrystalCost(crystals_to_buy);
            cout << "** " << name << " recovered " << mana_recovered << " mana! **" << endl;
            cout << "** " << name << " bought " << crystals_to_buy << " crystal(s)! **" << endl;
            state = AT_SPIRE;
            return true;
        case KNOCKED_OUT:
            return false;
        default:
            return false;
    }
}

void Mage::save(ofstream& file)
{
    int spire_id = -1;
    int hideout_id = -1;
    int demon_id = -1;

    if (current_spire != NULL) {
        spire_id = current_spire->GetId();
    }
    if (current_hideout != NULL) {
        hideout_id = current_hideout->GetId();
    }
    if (current_demon != NULL) {
        demon_id = current_demon->GetId();
    }

    GameObject::save(file);
    // Pointer fields are saved by ID because memory addresses are not persistent.
    file << speed << ' ' << is_at_spire << ' ' << is_in_hideout << ' '
         << mana << ' ' << experience << ' ' << gold_pieces << ' '
         << battles_to_buy << ' ' << crystals_to_buy << ' ' << name << ' '
         << spire_id << ' ' << hideout_id << ' ' << demon_id << ' '
         << destination.x << ' ' << destination.y << ' '
         << delta.x << ' ' << delta.y << endl;
}

void Mage::restore(ifstream& file, Model& model)
{
    int spire_id;
    int hideout_id;
    int demon_id;

    GameObject::restore(file, model);
    file >> speed >> is_at_spire >> is_in_hideout
         >> mana >> experience >> gold_pieces
         >> battles_to_buy >> crystals_to_buy >> name
         >> spire_id >> hideout_id >> demon_id
         >> destination.x >> destination.y >> delta.x >> delta.y;

    // Reconnect saved IDs to the newly allocated objects in Model.
    current_spire = (spire_id == -1) ? NULL : model.GetManaSpirePtr(spire_id);
    current_hideout = (hideout_id == -1) ? NULL : model.GetDemonHideoutPtr(hideout_id);
    current_demon = (demon_id == -1) ? NULL : model.GetRoamingDemonPtr(demon_id);
}
