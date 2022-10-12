#include "headers.h"



Int main() {
	pHashMap account = CreateHashMap(500);
	SetConsoleAttribute(80, 40, "계좌 관리 프로그램");
	SetConsoleTextColor(WHITE);
	C(account, Load, "account.txt");

	while (1) {
		Clear();
		BorderLine(WHITE);

		Goto(4, 3); printf("1. 계좌 개설");
		Goto(4, 5); printf("2. 계좌 검색");
		Goto(4, 21); printf("0. 종료");

		Goto(0, CONSOLE_HEIGHT - 1);
		printf(" >>> ");
		Int select = GetInt();
		if (select == 0) break;
		if (select == 1) {
			Str id;
			Clear();
			BorderLine(WHITE);
			Goto(4, 3); printf("아이디를 입력하세요");
			Goto(0, CONSOLE_HEIGHT - 1); printf(" >>> ");
			C(account, SetHashData, GetStr(id), CreateAccount());
			pAccount acc = C(account, GetHashData, id);
			strcpy(acc->id, id);


			Clear();
			BorderLine(WHITE);
			Goto(4, 3); printf("비밀번호를 입력하세요");
			Goto(0, CONSOLE_HEIGHT - 1); printf(" >>> ");
			GetStr(acc->pw);
		}
		else if (select == 2) {
			Str id, pw;
			Clear();
			BorderLine(WHITE);
			Goto(4, 3); printf("검색할 아이디를 입력하세요");
			Goto(0, CONSOLE_HEIGHT - 1); printf(" >>> ");
			pAccount acc = C(account, GetHashData, GetStr(id));
			if (acc != 0) {
				Clear();
				BorderLine(WHITE);
				Goto(4, 3); printf("비밀번호를 입력하세요");
				Goto(0, CONSOLE_HEIGHT - 1); printf(" >>> ");
				GetStr(pw);
				if (strcmp(acc->pw, pw) == 0) {
					AccountWork(acc);
					continue;
				}
			}
			Clear();
			BorderLine(RED);
			Goto(4, 3); printf("아이디 또는 비밀번호가 일치하지 않습니다");
			SetConsoleTextColor(WHITE);
			Sleep(3000);
		}
		
	}
	C(account, Save, "account.txt");
	C(account, RemoveHashMap);
	return 0;
}
