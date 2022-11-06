#include <iostream>
#include <set>

using namespace std;

struct Stack
{
	char info;
	Stack* next;
};

double mas[201];
Stack* stek;
Stack* InStack(Stack* p, char in)
{
	//����������� ������ ��� ��������
	Stack* t = new Stack;
	t->info = in; // ��������� �������������� �����
	t->next = p; // ��������� �������� �����
	return t;
}
Stack* OutStack(Stack* p, char* out)
{
	// ������������� ��������� t �� ������� p
	Stack* t = p;
	*out = p->info;
	// ������������ ������� p �� ��������� �������
	p = p->next;
	delete t; // ������� ������ ������� t
	return p; // ���������� ����� ������� p
}

//������� ���������� ���������� ��������
int Prior(char a)
{
	switch (a)
	{
	case '^': return 4;
	case '*': case '/': return 3;
	case '-': case '+': return 2;
	case '(': return 1;
	}
	return 0;
}

bool ArrayContains(char arr[], int len, char ch)
{
	for (int i = 0; i < len; i++)
	{
		if (arr[i] == ch)
			return true;
	}
	return false;
}

//������ ��������������� ���������

double Rezult(char* str)
{

	char ch, ch1, ch2;
	double op1, op2, rez;
	char znak[] = { '*', '/', '+', '-', '^' };
	char chr = 'z' + 1;
	int slen = strlen(str);
	for (int i = 0; i <= slen; i++)
	{
		ch = str[i];
		if (!ArrayContains(znak, 5, ch))
			stek = InStack(stek, ch);
		else
		{
			stek = OutStack(stek, &ch1);
			stek = OutStack(stek, &ch2);
			op1 = mas[int(ch1)];
			op2 = mas[int(ch2)];
			switch (ch)
			{
			case '+': rez = op2 + op1; break;
			case '-': rez = op2 - op1; break;
			case '*': rez = op2 * op1; break;
			case '/': rez = op2 / op1; break;
			case '^': rez = pow(op2, op1); break;
			}
			mas[int(chr)] = rez;
			stek = InStack(stek, chr);
			chr++;
		}
	}
	return rez;
}

void Concat(char* str, char c)
{
	int a = strlen(str);
	str[a] = c;
	str[a + 1] = '\0';
}

int main()
{
	float a, b, c, d, e;
	cout << "Vvedite a: "; cin >> a;
	cout << "Vvedite b: "; cin >> b;
	cout << "Vvedite c: "; cin >> c;
	cout << "Vvedite d: "; cin >> d;
	cout << "Vvedite e: "; cin >> e;

	char str[100];
	mas['a'] = a;
	mas['b'] = b;
	mas['c'] = c;
	mas['d'] = d;
	mas['e'] = e;
	cout << "Vvedite vyrazeniye: ";
	cin >> str;

	Stack* t;
	stek = NULL; // stack none operation
	char ss, ab;
	char OutStr[100]; // enter and out str
	OutStr[0] = '\0';
	char znak[] = { '*', '/', '+', '-', '^' };
	int len = strlen(str), k;
	for (k = 0; k <= len; k++)
	{
		ss = str[k];
		// ����������� ������ ���������� � ����
		if (ss == '(')
			stek = InStack(stek, ss);
		if (ss == ')')
		{
			// ����������� �� ����� ��� ����� �������� �� ����������� ������
			while ((stek->info) != '(')
			{
				stek = OutStack(stek, &ab); // ��������� ������� �� �����
				Concat(OutStr, ab); // ���������� � ������
			}
			stek = OutStack(stek, &ab); // ������� �� ����� ������ �(�
		}

		// ����� (�������) ������� � �������� ������
		if (ss >= 'a' && ss <= 'z')
			Concat(OutStr, ss);
		/* ���� ���� ��������, �� ������������ �� ����� � �������� ������ ��� �����-
		��� � ������� ��� ������ ����������� */
		if (ArrayContains(znak, 5, ss))
		{
			while (stek != NULL && Prior(stek->info) >= Prior(ss))
			{
				stek = OutStack(stek, &ab);
				Concat(OutStr, ab);
			}
			stek = InStack(stek, ss);
		}
	}
	// ���� ���� �� ����, ������������ ���
	// �������� � �������� ������

	while (stek != NULL)
	{
		stek = OutStack(stek, &ab);
		Concat(OutStr, ab);
	}


	cout << "result:  " << Rezult(OutStr);
	// ������� ���������� ������
}