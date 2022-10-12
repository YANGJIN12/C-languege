#include "headers.h"

uInt TextColor = WHITE;
uInt BackColor = BLACK;



Void BorderLine(uInt color) {
	uInt BTC = TextColor;
	uInt BBC = BackColor;
	SetConsoleTextColor(color);
	SetConsoleBackColor(color);
	Goto(0, 0);
	for (Int i = 0; i < CONSOLE_WIDTH; ++i) printf(" ");
	Goto(0, CONSOLE_HEIGHT - 2);
	for (Int i = 0; i < CONSOLE_WIDTH; ++i) printf(" ");
	for (Int i = 0; i < CONSOLE_WIDTH; ++i) {
		Goto(0, i); printf(" ");
		Goto(CONSOLE_WIDTH - 1, i); printf(" ");
	}
	SetConsoleTextColor(BTC);
	SetConsoleBackColor(BBC);

}

Void SetConsoleAttribute(uInt width, uInt height, pChar title) {
	Str line;
	sprintf(line, "mode con cols=%d lines=%d", width, height, title);
	system(line);
}

Void SetConsoleTextColor(uInt color) {
	TextColor = color;
	SetConsoleTextAttribute(
		GetStdHandle(STD_OUTPUT_HANDLE), BackColor << 4 | TextColor);
}

Void SetConsoleBackColor(uInt color) {
	BackColor = color;
	SetConsoleTextAttribute(
		GetStdHandle(STD_OUTPUT_HANDLE), BackColor << 4 | TextColor);
}

Void Clear() {
	system("cls");
}

Void Goto(uInt x, uInt y) {
	COORD pos = { x + 1,y + 1 };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}

Int GetInt() {
	Int result;
	scanf_s("%d", &result);
	return result;
}

Double GetDouble() {
	Double result;
	scanf_s("%lf", &result);
	return result;
}

pChar GetStr(pChar str) {
	scanf_s("%s", str, STR_MAX);
	return str;
}