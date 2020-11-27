#include "database.h"

int consola::crud(database a)
{
	if (instructiune == "EXIT") return 0;
	int poz;
	string create = "CREATE TABLE";
	string drop = "DROP TABLE";
	string display = "DISPLAY TABLE";
	poz = instructiune.find(create);
	if (poz != -1)
	{
		instructiune.erase(poz, create.length()+1);
		poz = instructiune.find(" ");
		string nume = instructiune.substr(0, poz);
		instructiune.erase(0, poz+1);
		a.create(nume,instructiune);
	}
	return 1;
}

void database::create(string nume,string comenzi) 
{
	int i;
	int ok = 1;
	string instr;
	int poz;
	comenzi+=' ';
	if (nr == 0)
	{
		tabele[0].setnume(nume);
		while (comenzi != "")
		{
			poz = comenzi.find(" ");
			instr = comenzi.substr(0, poz);
			tabele[0].adauga_coloana(instr);
			comenzi.erase(0, poz + 1);
		}
	}
	else
	{
		for (i = 0; i < nr; i++)
		{
			ok = 0;
		}
	}
	if (ok)
	{
		tabele[nr].setnume(nume);
		while (comenzi != "")
		{
			poz = comenzi.find(" ");
			instr = comenzi.substr(0, poz);
			tabele[nr].adauga_coloana(instr);
			comenzi.erase(0, poz + 1);
		}
		cout << "Tabela creata";
	}
	else cout << "Tabela existenta";
}