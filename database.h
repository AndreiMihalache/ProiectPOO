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
	string getNume()
	{
		return this->nume;
	}
	string getTip()
	{
		return this->tip;
	}
	string getDim()
	{
		return this->dimensiune;
	}
	string getVal()
	{
		return this->valoare_implicita;
	}
	void setNume(string nume)
	{
		this->nume = nume;
	}
	void setTip(string tip)
	{
		this->tip = tip;
	}
	void setDim(string dimensiune)
	{
		this->dimensiune = dimensiune;
	}
	void setVal(string valoare_implicita)
	{
		this->valoare_implicita = valoare_implicita;
	}
	friend class table;

	friend istream& operator>>(istream&, coloana&);
	friend ostream& operator<<(ostream&, coloana);
};

istream& operator>>(istream& i, coloana& c)
{
	string buffer;
	cout << "Nume = ";
	i >> ws;
	getline(i, buffer);
	c.setNume(buffer);
	cout << "Tip = ";
	i >> ws;
	getline(i, buffer);
	c.setTip(buffer);
	cout << "Dimensiune = ";
	i >> ws;
	getline(i, buffer);
	c.setDim(buffer);
	cout << "Valoare implicita = ";
	i >> ws;
	getline(i, buffer);
	c.setVal(buffer);
	return i;
}

ostream& operator<<(ostream& o, coloana c)
{
	o << endl;
	o << "Nume : " << c.getNume() << endl;
	o << "Tip : " << c.getTip() << endl;
	o << "Dimensiune : " << c.getDim() << endl;
	o << "Valoare implicita : " << c.getVal() << endl;
	return o;
}

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
		if (col != nullptr)
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
	string getNume()
	{
		return nume;
	}
	int getI()
	{
		return i;
	}
	void setNume(string n)
	{
		this->nume = n;
	}
	void setCol(coloana* col, int i)
	{
		if (this->col != nullptr)
		{
			delete[] this->col;
		}
		if (i)
		{
			this->col = new coloana[i];
			for (int j = 0;j < i;j++)
			{
				this->col[j] = col[j];
			}
		}
	}
	void setI(int i)
	{
		this->i = i;
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
			coloana* aux = new coloana[i + 1];
			for (int j = 0; j < this->i; j++)
			{
				aux[j] = col[j];
			}
			delete[] col;
			i++;
			col = new coloana[i];
			for (int j = 0; j < this->i - 1; j++)
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
		col[i - 1].setNume(instructiune.substr(0, poz));
		instructiune.erase(0, poz + 1);
		poz = instructiune.find(",");
		col[i - 1].setTip(instructiune.substr(0, poz));
		instructiune.erase(0, poz + 1);
		poz = instructiune.find(",");
		col[i - 1].setDim(instructiune.substr(0, poz));
		instructiune.erase(0, poz + 1);
		poz = instructiune.find(",");
		col[i - 1].setVal(instructiune.substr(0, poz));
		instructiune.erase(0, poz + 1);
	}
	friend class database;

	friend istream& operator>>(istream&, table&);
	friend ostream& operator<<(ostream&, table);
};

istream& operator>>(istream& i, table& t)
{
	string buffer;
	cout << "Nume = ";
	i >> ws;
	getline(i, buffer);
	t.setNume(buffer);
	cout << "Numar coloane = ";
	i >> t.i;
	if (t.i)
	{
		t.col = new coloana[t.i];
		for (int j = 0;j < t.i;j++)
		{
			i >> t.col[j];
		}
		//t.setCol(t.col, t.i);
	}
	else
	{
		t.col = nullptr;
	}
	return i;
}

ostream& operator<<(ostream& o, table t)
{
	o << "Nume : " << t.getNume() << endl;
	o << "Numar coloane : " << t.getI() << endl;
	for (int j = 0;j < t.i;j++)
	{
		o << "Coloana " << j + 1 << " : " << t.col[j] << endl;
	}
	return o;
}

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
		if (this->tabele != nullptr)
			delete[] tabele;
	}
	int getnr()
	{
		return this->nr;
	}
	friend class consola;
	void newTable()
	{
		if (tabele != nullptr)
		{
			//this->nr++;
			table* aux = new table[nr];
			for (int i = 0; i < nr - 1; i++)
			{
				aux[i] = tabele[i];
			}
			delete[] tabele;
			tabele = new table[nr];
			for (int i = 0; i < nr - 1; i++)
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
			this->tabele[nr - 1].setNume(nume);
			while (comenzi != "")
			{
				poz = comenzi.find(" ");
				instr = comenzi.substr(0, poz);
				tabele[nr - 1].adauga_coloana(instr);
				comenzi.erase(0, poz + 1);
			}
			nr++;
			cout << "Tabela creata" << endl;
		}
		else
		{
			for (i = 0; i < this->nr; i++)
			{
				if (tabele[i].getNume() == nume)
					ok = 0;
			}

			if (ok)
			{
				tabele[nr - 1].setNume(nume);
				while (comenzi != "")
				{
					poz = comenzi.find(" ");
					instr = comenzi.substr(0, poz);
					tabele[nr - 1].adauga_coloana(instr);
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
			for (int i = 0; i < nr - 1; i++)
			{
				if (tabele[i].getNume() != nume)
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
		cout << endl << "Tabela " << nume << " a fost stearsa";
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
		cout << "DROP TABLE nume_tabela" << endl;
		cout << "DISPLAY TABLE nume_tabela" << endl;
		cout << "Introduceti instructiune" << endl;
	}
	int crud(database& a)
	{

		int poz = -1, ok = 1;
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
	int crud_create(database& a, int poz)
	{

		instructiune.erase(poz, create.length() + 1);
		poz = instructiune.find(" ");
		string nume = instructiune.substr(0, poz);
		instructiune.erase(0, poz + 1);
		a.create(nume, instructiune);
		return 1;
	}
	int crud_drop(database& a, int poz)
	{
		instructiune.erase(poz, drop.length() + 1);
		a.drop(instructiune);
		return 1;
	}

};
//CREATE TABLE numetabela col1,tip1,dim1,val1
