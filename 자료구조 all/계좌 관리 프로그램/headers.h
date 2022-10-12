#pragma once
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <memory.h>
#include <time.h>
#include <math.h>
#include <windows.h>
#include <conio.h>

#define CONSOLE_WIDTH 160
#define CONSOLE_HEIGHT 40

#define STR_MAX 256
#define BLACK 0
#define BLUE 1
#define GREEN 2
#define CYAN 3
#define RED 4
#define MAGENTA 5
#define BROWN 6
#define LIGNTGRAY 7
#define DARKGRAY 8
#define LIGHTBLUE 9
#define LIGHTGREEN 10
#define LIGHTCYAN 11
#define LIGHTRED 12
#define LIGHTMAGENTA 13
#define YELLOW 14
#define WHITE 15

#define C(value, function,...) function(value,##__VA_ARGS__)

struct Node;
struct HashMap;
struct Account;

struct Account {
	char id[STR_MAX];
	char pw[STR_MAX];
	unsigned int money;
};



typedef int Int;
typedef int* pInt;
typedef unsigned int uInt;
typedef uInt* puInt;
typedef double Double;
typedef Double* pDouble;
typedef char Char;
typedef Char* pChar;
typedef Char Str[STR_MAX];
typedef void Void;
typedef Void* pVoid;
typedef struct Node Node;
typedef Node* pNode;
typedef struct HashMap HashMap;
typedef HashMap* pHashMap;
typedef struct Account Account;
typedef Account* pAccount;


void SetConsoleAttribute(uInt width, uInt height, pChar title);
Void SetConsoleTextColor(uInt color);
Void SetConsoleBackColor(uInt color);
Void Clear();
Void Goto(uInt x, uInt y);
Int GetInt();
Double GetDouble();
pChar GetStr(pChar str);
Void BorderLine(uInt color);

pHashMap CreateHashMap(uInt size);
Void RemoveHashMap(pHashMap this);

Void SetHashData(pHashMap this, pChar key, pVoid data);
pVoid GetHashData(pHashMap this, pChar key);
Void Save(pHashMap this, pChar path);
Void Load(pHashMap this, pChar path);

pAccount CreateAccount();
Void AccountWork(pAccount this);
pChar AccToStr(pAccount this, pChar str);