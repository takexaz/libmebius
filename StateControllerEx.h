#pragma once
#include <filesystem>
using namespace std;

struct DATE {
    int Month;
    int Year;
    int Day;
};


struct COORD3D {
    float x;
    float y;
    float z;
};

struct TRIGGER_CONTROL {
    DWORD unkown1;
    int numBytes;//�g���K�[�͉�Byte��؂肩
    int count01;//�g���K�[����
    int count02;
    int count03;
    void* info;
    void* list;
};

struct STATE_INFO {
    TRIGGER_CONTROL* trg;
    int trgX;//triggerX�ő�
    int persistent;
    int ignoregitpause;
    int stateid;
    int substateid;
    void* params;
    void* type;
};

struct PLAYER_CACHE {
    char name[48];
    char displayname[48];
    char author[48];
    DATE Version;
    DATE MugenVersion;
};

struct TPFILE {
    void* unknown;
};


struct PLAYER {
    PLAYER_CACHE* pcache;
    int pID;
    int slot;
    int teamside;
    int undef01;//Player:0 Helper-1
    int undef02, undef03;
    int ishelper;
    char debugname[48];
    int consts[66];
    int exist;
    int flozen;
    int life, lifemax, life_disp, life_damage_disp;
    int* powerptr, powermaxptr;
    int power, powermax, power_disp, power_gauge;
    float attackmul, defencemul;
    int facing;
    int undef04;
    int invisible;
    COORD3D pos;
    COORD3D screenpos;
    COORD3D vel;
    COORD3D offset;
    int airjump_num;
    int undef05, undef06;
    int pausemovetime, supermovetime;
    int undef07, undef08, undef09;
};

struct EVAL_EXP {
    void* ptr1 = 0;
    void* ptr2 = 0;
    int value = 0;
};

struct EXP_STR {
    string str = "";
};

auto TPGetValue = reinterpret_cast<const char* (*)(TPFILE* tpf, const char* label)>(0x483b30);
auto SCtrlReadExpList = reinterpret_cast<int (*)(const char* value, const char* format, PLAYER_CACHE* pcache, DWORD* TEMP, ...)>(0x47d780);
auto FreeExpression = reinterpret_cast<void (*)(EVAL_EXP* ptr)>(0x406e00);

#ifdef STCEX
#define CLASS_DECLSPECEC extern "C" __declspec(dllexport)
#define CLASS_DECLSPEC __declspec(dllexport)
#else
#define CLASS_DECLSPECEC extern "C" __declspec(dllimport)
#define CLASS_DECLSPEC __declspec(dllimport)
#endif


CLASS_DECLSPECEC void addState(string, DWORD, DWORD, DWORD);
CLASS_DECLSPEC void constExp(EVAL_EXP*, int);
CLASS_DECLSPEC void constExp(EVAL_EXP*, float);
CLASS_DECLSPEC int EvalExpression(PLAYER*, EVAL_EXP*, int);
CLASS_DECLSPEC float EvalExpression(PLAYER*, EVAL_EXP*);