#include<iostream>
#include <string>
#include <list>
using namespace std;

class reg
{
private:
	static int index;
	string* valori;
	int contor,capacitate;
public:
	reg()
	{
		index++;
		valori = nullptr;
		contor = 0;
		capacitate = 0;
	}
	reg(int nrcol)
	{
		index++;
		valori = new string[nrcol];
		contor = 0;
		capacitate = nrcol;
	}
	reg(reg& r)
	{
		this->contor = r.contor;
		this->capacitate = r.capacitate;
		if (this->capacitate)
		{
			valori = new string[capacitate];
			for (int i = 0; i < capacitate; i++)
			{
				this->valori[i] = r.valori[i];
			}
		}
		else
		{
			this->valori = nullptr;
		}
	}
	reg operator=(reg& r)
	{
		if (this->valori != nullptr)
		{
			delete[]this->valori;
		}
		this->contor = r.contor;
		this->capacitate = r.capacitate;
		if (this->capacitate)
		{
			valori = new string[capacitate];
			for (int i = 0; i < capacitate; i++)
			{
				this->valori[i] = r.valori[i];
			}
		}
		else
		{
			this->valori = nullptr;
		}
		return *this;
	}
	~reg()
	{
		index--;
		if (valori != nullptr)
		{
			delete[] valori;
		}

	}
	void setCap(int n)
	{
		this->capacitate = n;
		if (valori == nullptr)
		{
			valori = new string[n];
		}
		else
		{
			delete[] valori;
			valori = new string[n];
		}
	}
	void delpos(int ind)
	{
		if (ind > capacitate)
		{
			cout << "Index incorect";
		}
		else
		{
			int k = 0;
			string* aux = new string[capacitate -1];
			for(int i=0;i<capacitate;i++)
			{
				if (i != ind)
				{
					aux[k] = valori[i];
					k++;
				}
			}
			capacitate--;
			contor--;
			delete[] valori;
			valori = new string[capacitate];
			for (int i = 0; i < capacitate; i++)
			{
				valori[i] = aux[i];
			}
			delete[] aux;
		}
	}
	void addval()
	{
		if (valori == nullptr)
		{
			valori = new string[1];
			capacitate = 1;
		}
		else
		{
			string* aux = new string[capacitate + 1];
			for (int i = 0; i < capacitate; i++)
			{
				aux[i] = valori[i];
			}
			delete[] valori;
			capacitate++;
			valori = new string[capacitate];
			for (int i = 0; i < capacitate-1; i++)
			{
				valori[i]=aux[i];
			}
			valori[capacitate - 1] = "";
		}
	}
	void append(string val)
	{
		if (valori == nullptr)
		{
			valori = new string[1];
			valori[contor] = val;
			contor++;
		}
		else
		{
			if (contor < capacitate)
			{
				valori[contor] = val;
				contor++;
			}
			else
			{
				cout << "Capacitate maxima atinsa";
			}
		}
	}
	friend istream& operator>>(istream&, reg&);
	friend ostream& operator<<(ostream&, reg);
};

istream& operator>>(istream& i, reg& r)
{
	cout << endl<<"Capacitate: ";
	i >> r.capacitate;
	r.contor = 0;
	if(r.capacitate!=0)
	{
		r.valori = new string[r.capacitate];
		cout << endl << "Valori: " << endl;
		for (int it = 0; it < r.capacitate; it++)
		{
			i >> r.valori[it];
		}	 
	}
	return i;
}

ostream& operator<<(ostream& o, reg r)
{
	o << endl;
	o << "Capacitate: " << r.capacitate << endl;
	for (int i = 0; i < r.capacitate; i++)
	{
		o << r.valori[i] << " ";
	}
	return o;
}

int reg::index = -1;

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
	int i, k;
	reg *rand;
public:
	table()
	{
		col = nullptr;
		nume = "";
		i = 0;
		rand = nullptr;
		k = 0;
	}
	~table()
	{
		if (col != nullptr)
			delete[]col;
		if (rand != nullptr)
			delete[]rand;
	}
	table(table& t)
	{

		this->nume = t.nume;
		this->i = t.i;
		this->k = t.k;
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
		if (this->k)
		{
			this->rand = new reg[k];
			for (int j = 0; j < k; j++)
			{
				this->rand[j] = t.rand[j];
			}
		}
		else
		{
			rand = nullptr;
		}
	}
	table operator=(table& t)
	{
		if (this->col != nullptr)
		{
			delete[] col;
		}
		if (this->rand != nullptr)
		{
			delete[] rand;
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
		this->k = t.k;
		if (this->k)
		{
			this->rand = new reg[k];
			for (int j = 0; j < k; j++)
			{
				this->rand[j] = t.rand[j];
			}
		}
		else
		{
			rand = nullptr;
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
	void sterge_coloana(int index)
	{
		if (index<0 || index >i || col == nullptr)
		{
			cout << endl << "Operatie imposibila";
		}
		else
		{
			int contor = 0;
			coloana *aux = new coloana[i - 1];
			for (int j = 0; j < i; j++)
			{
				if (j != index)
				{
					aux[contor] = col[j];
					contor++;
				}
			}
			delete[] col;
			i--;
			col = new coloana[i];
			for (int j = 0; j < i; j++)
			{
				col[i] = aux[i];
			}
			delete[] aux;
			if (rand!=nullptr)
			{
				for (int j = 0; j < k; j++)
				{
					rand[j].delpos(index);
				}
			}
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
	int valid(string val, int index)
	{
		int ok=-1;
		if(col[index].tip=="int"&&ok!=1)
		{
			if (to_string(stoi(val)) == val && val.size() < stoi(col[index].dimensiune))
				return ok = 1;
		}
		if (col[index].tip == "float" && ok != 1 )
		{
			if (to_string(stof(val)) == val && val.size() < stoi(col[index].dimensiune))
				return ok = 1;
		}
		if (col[index].tip == "text" && ok != 1)
		{
			if(val.size() < stoi(col[index].dimensiune))
			ok = 1;
		}
		return ok;
	}
	void addrand()
	{
		if (k == 0)
		{
			k++;
			rand = new reg[k];
			rand[0].setCap(i-1);
			rand[0].addval();
		}
		else
		{
			reg* aux = new reg[k + 1];
			for (int j = 0; j < this->k; j++)
			{
				aux[j] = rand[j];
			}
			delete[] rand;
			k++;
			rand = new reg[k];
			for (int j = 0; j < this->k - 1; j++)
			{
				//rand[j].setCap(i-1);
				//rand[j].addval();
				rand[j] = aux[j];
			}
			delete[] aux;
		}

	}
	void insert(string values)
	{
		addrand();
		string val;
		values = values + ",";
		int poz,index=-1;
		while (values != "")
		{
			poz = values.find(",");
			val = values.substr(0, poz);
			index++;
			if (valid(val, index) == 1)
			{
				rand[k - 1].append(val);
			}
			values.erase(0, poz + 1);
		}
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
				nr++;
				cout << "Tabela creata";
			}
			else cout << "Tabela existenta";
		}
	}
	void drop(string nume)
	{
		int ok=0,i;
		for (i = 0; i < this->nr; i++)
		{
			if (tabele[i].getNume() == nume)
				ok = 1;
		}
		if (ok)
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
		else cout << "Tabela inexistenta";
	}
	void display(string nume)
	{
		int ok = 0, i;
		for (i = 0; i < this->nr-1; i++)
		{
			if (tabele[i].getNume() == nume)
				ok = 1;
		}
		if (ok)
		{
			for (i = 0; i < this->nr-1; i++)
			{
				if (tabele[i].getNume() == nume)
				{
					cout << tabele[i];
				}
			}
		}
		else cout << "Tabela nu exista";
	}
	void insert(string nume,string comenzi)
	{
		int ok = 0, i,k;
		for (i = 0; i < this->nr-1; i++)
		{
			if (tabele[i].getNume() == nume)

			{
				ok = 1;
				k = i;
			}
		}
		if (ok)
		{
			tabele[k].insert(comenzi);
		}
		else cout << "Tabela nu exista";
	}

};

class consola
{
private:
	string create = "CREATE TABLE";
	string drop = "DROP TABLE";
	string display = "DISPLAY TABLE";
	string insert = "INSERT INTO";
	string instructiune = "";
public:
	
	consola()
	{
		cout << "SGBD Tip SQL Lite" << endl;
		cout << "Sintaxa instructiuni:" << endl;
		cout << "CREATE TABLE nume_tabela nume_coloana,tip,dimensiune,valoare_implicata nume_coloana2,tip,dimensiune,valoare" << endl;
		cout << "DROP TABLE nume_tabela" << endl;
		cout << "DISPLAY TABLE nume_tabela" << endl;
		cout << "INSERT INTO nume_tabela VALUES ...";
		cout << "Introduceti instructiune" << endl;
	}
	int crud(database& a)
	{

		int poz = -1, ok = 1;
		while (ok)
		{
			cout << endl;
			if (instructiune != "")
			{
				cout << "Sintaxa instructiuni:" << endl;
				cout << "CREATE TABLE nume_tabela nume_coloana,tip,dimensiune,valoare_implicata nume_coloana2,tip,dimensiune,valoare" << endl;
				cout << "DROP TABLE nume_tabela" << endl;
				cout << "DISPLAY TABLE nume_tabela" << endl;
				cout << "INSERT INTO nume_tabela VALUES ...";
				cout << "Introduceti instructiune" << endl;
			}
			getline(std::cin, instructiune);
			if (instructiune == "EXIT")
			{
				ok = 0;
				break;
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
				poz = instructiune.find(display);
				if (poz != -1)
				{
					ok = crud_display(a, poz);
				}
				poz = instructiune.find(insert);
				if (poz != -1)
				{
					ok = crud_insert(a, poz);
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
	int crud_display(database& a, int poz)
	{
		instructiune.erase(poz, display.length() + 1);
		poz = instructiune.find(" ");
		string nume = instructiune;
		a.display(nume);
		return 1;
	}
	int crud_insert(database& a, int poz)
	{
		instructiune.erase(poz, insert.length() + 1);
		poz = instructiune.find(" ");
		string nume = instructiune.substr(0, poz);
		instructiune.erase(0, poz + 1);
		poz = instructiune.find(" ");
		instructiune.erase(0, poz + 1);
		a.insert(nume, instructiune);
		return 1;
	}

};
//CREATE TABLE numetabela col1,tip1,dim1,val1 col2,tip2,dim2,val2
//un com
