#include "headers.h"



Int main() {
	pHashMap account = CreateHashMap(500);
	SetConsoleAttribute(80, 40, "���� ���� ���α׷�");
	SetConsoleTextColor(WHITE);
	C(account, Load, "account.txt");

	while (1) {
		Clear();
		BorderLine(WHITE);

		Goto(4, 3); printf("1. ���� ����");
		Goto(4, 5); printf("2. ���� �˻�");
		Goto(4, 21); printf("0. ����");

		Goto(0, CONSOLE_HEIGHT - 1);
		printf(" >>> ");
		Int select = GetInt();
		if (select == 0) break;
		if (select == 1) {
			Str id;
			Clear();
			BorderLine(WHITE);
			Goto(4, 3); printf("���̵� �Է��ϼ���");
			Goto(0, CONSOLE_HEIGHT - 1); printf(" >>> ");
			C(account, SetHashData, GetStr(id), CreateAccount());
			pAccount acc = C(account, GetHashData, id);
			strcpy(acc->id, id);


			Clear();
			BorderLine(WHITE);
			Goto(4, 3); printf("��й�ȣ�� �Է��ϼ���");
			Goto(0, CONSOLE_HEIGHT - 1); printf(" >>> ");
			GetStr(acc->pw);
		}
		else if (select == 2) {
			Str id, pw;
			Clear();
			BorderLine(WHITE);
			Goto(4, 3); printf("�˻��� ���̵� �Է��ϼ���");
			Goto(0, CONSOLE_HEIGHT - 1); printf(" >>> ");
			pAccount acc = C(account, GetHashData, GetStr(id));
			if (acc != 0) {
				Clear();
				BorderLine(WHITE);
				Goto(4, 3); printf("��й�ȣ�� �Է��ϼ���");
				Goto(0, CONSOLE_HEIGHT - 1); printf(" >>> ");
				GetStr(pw);
				if (strcmp(acc->pw, pw) == 0) {
					AccountWork(acc);
					continue;
				}
			}
			Clear();
			BorderLine(RED);
			Goto(4, 3); printf("���̵� �Ǵ� ��й�ȣ�� ��ġ���� �ʽ��ϴ�");
			SetConsoleTextColor(WHITE);
			Sleep(3000);
		}
		
	}
	C(account, Save, "account.txt");
	C(account, RemoveHashMap);
	return 0;
}
