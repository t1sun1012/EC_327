#ifndef INPUT_HANDLING_H
#define INPUT_HANDLING_H

#include <string>

using namespace std;

// Simple exception type used to move input errors out of normal command flow
class Invalid_Input {
    public:
    Invalid_Input(string in_ptr) : msg_ptr(in_ptr) { }
    const string msg_ptr;

    private:
    Invalid_Input();
};

#endif
