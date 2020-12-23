#include<iostream>
#include <string>
#include <list>
using namespace std;

class rand
{
private:
	string* val;
public:
	rand()
	{
		
	}
};


class coloana
{
private:
	string nume;
	string tip;
	string dimensiune;
	string valoare_implicita;

public:
	coloana()
	{
		this->nume = "";
		this->tip = "";
		this->dimensiune = "";
		this->valoare_implicita = "";
	}
	coloana(coloana& c)
	{
		this->nume = c.nume;
		this->tip = c.tip;
		this->dimensiune = c.dimensiune;
		this->valoare_implicita = c.valoare_implicita;
	}
	coloana operator=(coloana& c)
	{
		this->nume = c.nume;
		this->tip = c.tip;
		this->dimensiune = c.dimensiune;
		this->valoare_implicita = c.valoare_implicita;
		return *this;
	}
	void setnume(string n)
	{
		this->nume = n;
	}
	void settip(string t)
	{
		this->tip = t;
	}
	void setdim(string d)
	{
		this->dimensiune = d;
	}
	void setval(string v)
	{
		this->valoare_implicita = v;
	}
	friend class table;

};

class table
{
private:
	string nume;
	coloana* col;
	int i;	
public:
	table()
	{
		col = nullptr;
		nume = "";
		i = 0;
	} 
	~table()
	{
		if(col!=nullptr)
		delete[]col;
	}
	table(table& t)
	{
	
		this->nume = t.nume;
		this->i = t.i;
		if (this->i)
		{
			this->col = new coloana[i];
			for (int j = 0; j < i; j++)
			{
				this->col[j] = t.col[j];
			}
		}
		else
		{
			col = nullptr;
		}
	}
	table operator=(table& t)
	{
		if (this->col != nullptr)
		{
			delete[] col;
		}
		this->nume = t.nume;
		this->i = t.i;
		if (this->i)
		{
			this->col = new coloana[i];
			for (int j = 0; j < i; j++)
			{
				this->col[j] = t.col[j];
			}
		}
		else
		{
			col = nullptr;
		}
		return *this;
	}
	string getnume()
	{
		return nume;
	}
	void setnume(string n)
	{
		this->nume = n;
	}
	void newCol()
	{
		if (i == 0)
		{
			i++;
			col = new coloana[i];
		}
		else
		{
			coloana* aux = new coloana[i+1];
			for (int j = 0; j < this->i; j++)
			{
				aux[j] = col[j];
			}
			delete[] col;
			i++;
			col = new coloana[i];
			for (int j = 0; j < this->i-1; j++)
			{
				col[j] = aux[j];
			}
			delete[] aux;
		}
	}

	void adauga_coloana(string instructiune)
	{
		newCol();
		int poz;
		poz = instructiune.find(",");
		col[i-1].setnume( instructiune.substr(0, poz));
		instructiune.erase(0, poz+1);
		poz = instructiune.find(",");
		col[i-1].settip ( instructiune.substr(0, poz));
		instructiune.erase(0, poz+1);
		poz = instructiune.find(",");
		col[i-1].setdim( instructiune.substr(0, poz));
		instructiune.erase(0, poz+1);
		poz = instructiune.find(",");
		col[i-1].setval ( instructiune.substr(0, poz));
		instructiune.erase(0, poz+1);
	}
	friend class database;

};


class database
{
private:
	int nr;
	table* tabele;
public:
	database()
	{
		this->nr = 1;
		this->tabele = nullptr;
	}
	~database()
	{
		if(this->tabele!=nullptr)
		delete[] tabele;
	}
	int getnr()
	{
		return this->nr;
	}
	friend class consola;
	void newTable()
	{
		if (tabele!=nullptr)
		{
			//this->nr++;
			table *aux=new table[nr];
			for (int i = 0; i < nr-1; i++)
			{
				aux[i] = tabele[i];
			}
			delete[] tabele;
			tabele = new table[nr];
			for (int i = 0; i < nr-1; i++)
			{
				tabele[i] = aux[i];
			}
			delete[] aux;
		}
		else
		{
			//this->nr++;
			tabele = new table[nr];
		}
	}
	void create(string nume, string comenzi)
	{
		newTable();
		int i;
		int ok = 1;
		string instr;
		int poz;
		comenzi += ' ';
		//numetabela col1,tip1,dim1,val1 col1,tip2,dim2,val2
		if (nr == 1)
		{
			this->tabele[nr-1].setnume(nume);
			while (comenzi != "")
			{
				poz = comenzi.find(" ");
				instr = comenzi.substr(0, poz);
				tabele[nr-1].adauga_coloana(instr);
				comenzi.erase(0, poz + 1);
			}
			nr++;
			cout << "Tabela creata" << endl;
		}
		else
		{
			for (i = 0; i < this->nr; i++)
			{
				if (tabele[i].getnume() == nume)
					ok = 0;
			}

			if (ok)
			{
				tabele[nr-1].setnume(nume);
				while (comenzi != "")
				{
					poz = comenzi.find(" ");
					instr = comenzi.substr(0, poz);
					tabele[nr-1].adauga_coloana(instr);
					comenzi.erase(0, poz + 1);
				}
				cout << "Tabela creata";
			}
			else cout << "Tabela existenta";
		}
	}
	void drop(string nume)
	{
		
		if (nr == 1)
		{
			delete[] tabele;
		}
		else 
		{
			table* aux = new table[nr - 1];
			int j = 0;
			for (int i = 0; i < nr-1; i++)
			{
				if (tabele[i].getnume() != nume)
				{
					aux[j] = tabele[i];
					j++;
				}
			}
			delete[] tabele;
			nr -= 1;
			tabele = new table[nr];
			for (int i = 0; i < nr; i++)
			{
				tabele[i] = aux[i];
			}
			delete[] aux;
		}
		cout <<endl<< "Tabela " << nume << " a fost stearsa";
	}

};

class consola
{
private:
	string create = "CREATE TABLE";
	string drop = "DROP TABLE";
	string display = "DISPLAY TABLE";
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
	}
	int crud(database &a)
	{
		
		int poz=-1,ok=1;
		while (ok)
		{
			cout << endl;
			getline(std::cin, instructiune);
			if (instructiune == "EXIT")
			{
				ok = 0;
				return 0;
			}
			else
			{
				poz = instructiune.find(create);
				if (poz != -1)
				{
					ok = crud_create(a, poz);
				}
				poz = instructiune.find(drop);
				if (poz != -1)
				{
					ok = crud_drop(a, poz);
				}
			}
		}
		return 1;
	};
	int crud_create(database &a,int poz)
	{
		
			instructiune.erase(poz, create.length() + 1);
			poz = instructiune.find(" ");
			string nume = instructiune.substr(0, poz);
			instructiune.erase(0, poz + 1);
			a.create(nume, instructiune);
			return 1;
	}
	int crud_drop(database &a, int poz)
	{
		instructiune.erase(poz, drop.length() + 1);
		a.drop(instructiune);
		return 1;
	}

};
//CREATE TABLE numetabela col1,tip1,dim1,val1