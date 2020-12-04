#include<iostream>
#include <string>
using namespace std;

class coloana
{
public:
	friend class table;
private:
	string nume;
	string tip;
	string dimensiune;
	string valoare_implicita;
};

class table
{	
public:
	string getnume()
	{
		return nume;
	};
	void setnume(string nume)
	{
		this->nume = nume;
	}
	void adauga_coloana(string instructiune)
	{
		int poz;
		poz = instructiune.find(",");
		col[i].nume = instructiune.substr(0, poz);
		instructiune.erase(0, poz+1);
		poz = instructiune.find(",");
		col[i].tip = instructiune.substr(0, poz);
		instructiune.erase(0, poz+1);
		poz = instructiune.find(",");
		col[i].dimensiune = instructiune.substr(0, poz);
		instructiune.erase(0, poz+1);
		poz = instructiune.find(",");
		col[i].valoare_implicita = instructiune.substr(0, poz);
		instructiune.erase(0, poz+1);
	}
private:
	string nume;
	coloana* col = new coloana[100];
	int i = 0;
};


class database
{
public:
	database()
	{
		nr = 0;
	}
	~database()
	{}
	friend class consola;
private:
	int nr;
	table* tabele = new table[100];
	void create(string nume, string comenzi)
	{
		int i;
		int ok = 1;
		string instr;
		int poz;
		comenzi += ' ';
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
	};
};

class consola
{
public:
	string instructiune;
	consola()
	{
		cout << "SGBD Tip SQL Lite" << endl;
		cout << "Sintaxa instructiuni:" << endl;
		cout << "CREATE TABLE nume_tabela nume_coloana,tip,dimensiune,valoare_implicata nume_coloana2,tip,dimensiune,valoare" << endl;
		cout << "DROP TABLE nume_tabela"<<endl;
		cout << "DISPLAY TABLE nume_tabela"<<endl;
		cout << "Introduceti instructiune" << endl;
		getline(std::cin, instructiune);
	}
	int crud(database a)
	{
		if (instructiune == "EXIT") return 0;
		int poz;
		string create = "CREATE TABLE";
		string drop = "DROP TABLE";
		string display = "DISPLAY TABLE";
		poz = instructiune.find(create);
		if (poz != -1)
		{
			instructiune.erase(poz, create.length() + 1);
			poz = instructiune.find(" ");
			string nume = instructiune.substr(0, poz);
			instructiune.erase(0, poz + 1);
			a.create(nume, instructiune);
		}
		return 1;
	};

};