#include "Functions.h"

char* enterCharOnly()
{
	char* tmpo;
	int flag;
	do {

		tmpo = new char[81];
		flag = 0;
		rewind(stdin);
		cin.getline(tmpo, 80);
		int k = strlen(tmpo);
		for (int i = 0; i < k; i++)
		{
			if (tmpo[i] >= '0' && tmpo[i] <= '9')
			{
				flag = 1;
				_flushall(); // ocishaut vse potoko i bufery 
				cout << "___ ¬ведено не число" << endl;
				delete[] tmpo;
				cout << endl;
				break;
			}
		}
	} while (flag);
	return tmpo;
}