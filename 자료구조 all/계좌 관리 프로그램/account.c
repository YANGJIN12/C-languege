#include "headers.h"

pChar AccToStr(pAccount this, pChar str) {
	sprintf(str, "%s %s %d\n", this->id, this->pw, this->money);
	return str;
}

pAccount CreateAccount() {
	pAccount acc = (pAccount)malloc(sizeof(Account));
	memset(acc, 0, sizeof(Account));
	return acc;
}

Void AccountWork(pAccount this) {
	while (1) {
		Clear();
		BorderLine(WHITE);
		Goto(4, 3); printf("ID : %50s", this->id);
		Goto(4, 5); printf("PW : %50s", this->pw);
		Goto(4, 7); printf("MO : %50d", this->money);

		Goto(4, 11); printf("1. 입금");
		Goto(4, 11); printf("2. 출금");
		Goto(4, 11); printf("3. 되돌아가기");

		Goto(0, CONSOLE_HEIGHT - 1); printf(" >>> ");
		Int select = GetInt();
		if (select == 0) break;
		else if (select == 1) {
			Clear();
			BorderLine(WHITE);
			Goto(4, 3); printf("입금할 금액을 입력하세요");
			Goto(0, CONSOLE_HEIGHT - 1); printf(" >>> ");
			Int money = GetInt();
			this->money += money;
		}
		else if (select == 2) {
			Clear();
			BorderLine(WHITE);
			Goto(4, 3); printf("출금할 금액을 입력하세요");
			Goto(0, CONSOLE_HEIGHT - 1); printf(" >>> ");
			Int money = GetInt();
			this->money -= money;
		}
	}
}