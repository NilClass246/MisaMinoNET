#include "Bot.h"
#include "Windows.h"
#define DLL extern "C" __declspec(dllexport)
using namespace std;

Bot MisaBot;

DLL void configure(int level, int style) {
    MisaBot = Bot();
    MisaBot.updateLevel(level);
    MisaBot.updateStyle(style);
    MisaBot.setup();
};

DLL void update_next(const char* queue) {
    MisaBot.updateQueue(queue);
}
DLL void update_current(const char* piece) {
    MisaBot.updateCurrent(piece);
}
DLL void update_incoming(int attack) {
    MisaBot.updateIncoming(attack);
}
DLL void update_combo(int combo) {
    MisaBot.updateCombo(combo);
}
DLL void update_field(const char* field) {
    MisaBot.updateField(field);
}
DLL void update_reset() {
    MisaBot.updateReset();
    MisaBot.setup();
}

DLL void action(char* str, int len) {
    std::string a = MisaBot.outputAction(str, len);
    std::copy(a.c_str(), a.c_str() + a.length() + 1, str);
}
DLL bool alive() {
    return MisaBot.tetris.alive();
}

BOOL WINAPI DllMain(HANDLE handle, DWORD reason, LPVOID reserved) {
    switch (reason) {
        case DLL_PROCESS_ATTACH:
            MisaBot.setup();     
            // MisaBot.startParser();
            break;

        case DLL_THREAD_ATTACH:
            break;        

        case DLL_THREAD_DETACH:       
            break;

        case DLL_PROCESS_DETACH:
            break;    
    }
    
    return TRUE;
}