#include<iostream>
#include <string>
#include<iomanip>
#include <fstream>

using namespace std;

class reg
{
private:
	static int index;
	string* valori;
	int contor, capacitate;
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
		if (valori != nullptr)
		{
			delete[]valori;
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
			string* aux = new string[capacitate - 1];
			for (int i = 0; i < capacitate; i++)
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
			for (int i = 0; i < capacitate - 1; i++)
			{
				valori[i] = aux[i];
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
	friend class table;
};

istream& operator>>(istream& i, reg& r)
{
	cout << endl << "Capacitate: ";
	i >> r.capacitate;
	r.contor = 0;
	if (r.capacitate != 0)
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
	/*coloana operator+(int valoare)
	{
		if (valoare > 0)
		{
			coloana copie = *this;
			int aux = stoi(copie.dimensiune);
			aux += valoare;
			copie.dimensiune = to_string(aux);
			return copie;
		}
	}*/
	coloana operator++()
	{
		int aux = stoi(dimensiune);
		aux++;
		dimensiune = to_string(aux);
		return *this;
	}
	coloana operator++(int i)
	{
		int aux = stoi(dimensiune);
		aux++;
		dimensiune = to_string(aux);
		return *this;
	}
	explicit operator string()
	{
		return dimensiune;
	}
	bool operator!()
	{
		int aux = stoi(dimensiune);
		return aux > 0;
	}
	bool operator<(coloana c)
	{
		return this->dimensiune < c.dimensiune;
	}
	bool operator==(coloana c)
	{
		bool ok = 1;
		if (this->nume != c.nume)
		{
			ok = 0;
		}
		if (this->tip != c.tip)
		{
			ok = 0;
		}
		if (this->dimensiune != c.dimensiune)
		{
			ok = 0;
		}
		if (this->valoare_implicita != c.valoare_implicita)
		{
			ok = 0;
		}
		return ok;
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
	reg* rand;
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
	/*table operator+(int valoare)
	{
		if (valoare > 0)
		{
			table copie = *this;
			copie.i += valoare;
			for (int j = 0; j < valoare; j++)
			{
				this->newCol();
				cin >> this->col[i + j];
			}
			return copie;
		}
	}*/
	table operator++()
	{
		this->newCol();
		cin >> this->col[this->i - 1];
		return *this;
	}
	table operator++(int i)
	{
		table copie = *this;
		this->newCol();
		cin >> this->col[this->i - 1];
		return copie;
	}
	coloana& operator[](int index)
	{
		if (index >= 0 && index < i)
		{
			if (i > 0)
				return col[index];
		}
	}
	explicit operator int()
	{
		return i;
	}
	bool operator!()
	{
		return i <= 0;
	}
	bool operator<(table t)
	{
		return this->i < t.i;
	}
	bool operator==(table t)
	{
		bool ok = 1;
		if (this->nume != t.nume)
		{
			ok = 0;
		}
		if (this->i != t.i)
		{
			ok = 0;
		}
		else
		{
			if (this->i != 0)
				for (int j = 0; j < this->i && ok == 1; j++)
				{
					if (!(this->col[j] == t.col[j]))
					{
						ok = 0;
					}
				}
		}
		return ok;
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
			coloana* aux = new coloana[i - 1];
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
			if (rand != nullptr)
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
		instructiune += ',';
		poz = instructiune.find(',');
		col[i - 1].setNume(instructiune.substr(0, poz));
		instructiune.erase(0, poz + 2);
		poz = instructiune.find(',');
		col[i - 1].setTip(instructiune.substr(0, poz));
		instructiune.erase(0, poz + 2);
		poz = instructiune.find(',');
		col[i - 1].setDim(instructiune.substr(0, poz));
		instructiune.erase(0, poz + 2);
		poz = instructiune.find(',');
		col[i - 1].setVal(instructiune.substr(0, poz));
		instructiune.erase(0, poz + 1);
	}
	int valid(string val, int index)
	{
		int ok = -1;
		if (col[index].tip == "int" && ok != 1)
		{
			if (to_string(stoi(val)) == val && val.size() <= stoi(col[index].dimensiune))
				return ok = 1;
		}
		if (col[index].tip == "float" && ok != 1)
		{
			if (stof(to_string(stof(val))) == stof(val) && val.size() <= stoi(col[index].dimensiune))
				return ok = 1;
		}
		if (col[index].tip == "text" && ok != 1)
		{
			if (val.size() <= stoi(col[index].dimensiune))
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
			rand[0].setCap(i);
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
				rand[j] = aux[j];
			}
			rand[k - 1].setCap(i);
			delete[] aux;
		}

	}
	void insert(string values)
	{
		addrand();
		string val;
		values.erase(0, 1);
		values.erase(values.length() - 1);
		values = values + ", ";
		int poz, index = -1;
		while (values != "")
		{
			poz = values.find(",");
			val = values.substr(0, poz);
			index++;
			if (valid(val, index) == 1)
			{
				rand[k - 1].append(val);
			}
			values.erase(0, poz + 2);
		}
		if (rand[k - 1].contor < rand[k - 1].capacitate)
		{
			for (int j = rand[k - 1].contor; j < rand[k - 1].capacitate; j++)
			{
				rand[k - 1].append(col[rand[k - 1].contor].valoare_implicita);
			}
		}
	}
	void del(string instr)
	{
		if (k && i)
		{
			int poz;
			poz = instr.find(' ');
			string ncol, val;
			ncol = instr.substr(0, poz);
			poz = poz + 3;
			instr.erase(0, poz);
			poz = -1;
			poz = instr.find(' ');
			if (poz == -1)
			{
				val = instr;
			}
			else val = instr.substr(0, poz);
			int index;
			for (int j = 0; j < i; j++)
			{
				if (col[j].getNume() == ncol)
				{
					index = j;
				}
			}
			if (index < 0)
			{
				cout << endl << "Coloana nu exista";
			}
			else
			{
				for (int j = 0; j < k; j++)
				{
					if (rand[j].valori[index] == val)
					{
						if (k == 1)
						{
							delete[] rand;
						}
						else
						{
							reg* aux = new reg[k - 1];
							int contor = 0;
							for (int x = 0; x < k; x++)
							{
								if (x != j)
								{
									aux[contor] = rand[x];
									contor++;
								}
							}
							k--;
							delete[] rand;
							rand = new reg[k];
							for (int x = 0; x < k; x++)
							{
								rand[x] = aux[x];
							}
							delete[] aux;
						}
						break;
					}
				}
			}
		}
	}
	void update(string p1, string p2)
	{
		string c1, v1, c2, v2;
		int poz;
		poz = p1.find(' ');
		c1 = p1.substr(0, poz);
		poz = poz + 3;
		p1.erase(0, poz);
		v1 = p1;
		poz = p2.find(' ');
		c2 = p2.substr(0, poz);
		poz = poz + 3;
		p2.erase(0, poz);
		v2 = p2;
		int index1 = -1, index2 = -1;
		for (int j = 0; j < i; j++)
		{
			if (col[j].getNume() == c2)
			{
				index2 = j;
			}
			if (col[j].getNume() == c1)
			{
				index1 = j;
			}
		}
		if (index1 >= 0 && index2 >= 0)
		{
			for (int j = 0; j < k; j++)
			{
				if (rand[j].valori[index2] == v2)
				{
					rand[j].valori[index1] = v1;
				}
			}
		}
		else
		{
			cout << "Una din coloane nu exista";
		}
	}
	void center(string str)
	{
		int size;
		string aux;
		if (str.length() > 12) {
			aux = str.substr(0, 12);
			size = 0;
		}
		else
		{
			aux = str;
			size = 12 - str.length();
		}
		if (size == 0)
		{
			cout << aux << '  ';
		}
		else
		{
			cout << aux << string(size, ' ');
		}
	}
	void select(string cols, string cond)
	{
		cout << endl;
		if (cond == "")
		{
			if (cols == "ALL")
			{
				cout << string(12 * i, '-') << endl;;
				for (int j = 0; j < i; j++)
				{
					center(col[j].nume);
				}
				cout << endl<<string(12 * i, '-') << endl;
				for (int x = 0; x < k; x++)
				{
					cout << endl;
					for (int z = 0; z < i; z++)
					{
						center(rand[x].valori[z]);
					}
				}
			}
			else
			{
				cols.erase(0,1);
				cols.erase(cols.length() - 1);
				cols = cols + ", ";
				int* indexes = new int[i];
				int contor = 0;
				while (cols != "")
				{
					string aux;
					int poz;
					poz = cols.find(',');
					aux = cols.substr(0, poz);
					cols.erase(0, poz + 2);
					for (int j = 0; j < i; j++)
					{
						if (col[j].nume == aux)
						{
							indexes[contor] = j;
							contor++;
						}
					}
				}
				for (int g = 0; g < contor - 1; g++)
				{
					for (int h = 0; h < contor; h++)
					{
						if (indexes[h] > indexes[g])
						{
							swap(indexes[h], indexes[g]);
						}
					}
				}
				cout << endl;
				for (int j = 0; j < contor; j++)
				{
					cout << col[j].nume << "\t\t";
				}
				cout << endl;
				for (int j = 0; j < k; j++)
				{
					for (int x = 0; x < contor; x++)
					{
						cout << rand[j].valori[x] << "\t\t";
					}
				}
			}
		}
		else
		{	
			string arg1;
			string arg2;
			int poz;
			poz = cond.find(' ');
			arg1 = cond.substr(0, poz);
			cond.erase(0, poz + 2);
			arg2 = cond;
			int ok1=0,ok2=0;
			int index;
			for (int j = 0; j < i; j++)
			{
				if (col[j].nume == arg1)
				{
					ok1 = 1; index = j;
				}
			}
			for (int j = 0; j < k; j++)
			{
				if (rand[j].valori[index]==arg2)
				{
					ok2 = 1;
				}
			}
			if (ok1 && ok2)
			{
				if (cols == "ALL")
				{
					for (int j = 0; j < i; j++)
					{
						cout << col[j].nume << "\t\t";
					}
					for (int x = 0; x < k; x++)
					{
						cout << endl;
						for (int z = 0; z < i; z++)
						{
							if(rand[x].valori[index]==arg2)
							cout << rand[x].valori[z] << "\t\t";
						}
					}
				}
				else
				{
					cols.erase(0, 1);
					cols.erase(cols.length() - 1);
					cols = cols + ", ";
					int* indexes = new int[i];
					int contor = 0;
					while (cols != "")
					{
						string aux;
						int poz;
						poz = cols.find(',');
						aux = cols.substr(0, poz);
						cols.erase(0, poz + 2);
						for (int j = 0; j < i; j++)
						{
							if (col[j].nume == aux)
							{
								indexes[contor] = j;
								contor++;
							}
						}
					}
					for (int g = 0; g < contor - 1; g++)
					{
						for (int h = 0; h < contor; h++)
						{
							if (indexes[h] > indexes[g])
							{
								swap(indexes[h], indexes[g]);
							}
						}
					}
					cout << endl;
					for (int j = 0; j < contor; j++)
					{
						cout << col[j].nume << "\t\t";
					}
					cout << endl;
					for (int j = 0; j < k; j++)
					{
						for (int x = 0; x < contor; x++)
						{
							if (rand[x].valori[index] == arg2)
							cout << rand[j].valori[x] << "\t\t";
						}
					}
				}
			}
			else
			{
				cout << "Nu exista inregistrari care sa respecte conditia";
			}
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
		for (int j = 0; j < t.i; j++)
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
	o << "Nume tabela: " << t.getNume() << endl;
	o << "Numar coloane : " << t.getI() << endl;
	for (int j = 0; j < t.i; j++)
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
	database(database& d)
	{
		this->nr = d.nr;
		if (d.nr != 0)
		{
			this->tabele = new table[d.nr];
			for (int i = 0; i < d.nr; i++)
			{
				this->tabele[i] = d.tabele[i];
			}
		}
		else
		{
			this->tabele = nullptr;
		}
	}
	database operator+(int valoare)
	{
		if (valoare > 0)
		{
			database copie = *this;
			copie.nr += valoare;
			return copie;
		}
	}
	database operator++()
	{
		if (tabele == nullptr)
		{
			tabele = new table[nr];
			cin >> tabele[nr - 1];
			nr++;
		}
		else
		{
			table* aux = new table[nr];
			for (int i = 0; i < nr - 1; i++)
			{
				aux[i] = tabele[i];
			}
			delete[] tabele;
			tabele = new table[nr];
			nr++;
			for (int i = 0; i < nr - 2; i++)
			{
				tabele[i] = aux[i];
			}
			delete[] aux;
			cin >> tabele[nr - 2];
		}
		return *this;
	}
	database operator++(int i)
	{
		database copie = *this;
		if (tabele == nullptr)
		{
			tabele = new table[nr];
			cin >> tabele[nr - 1];
			nr++;
		}
		else
		{
			table* aux = new table[nr];
			for (int i = 0; i < nr - 1; i++)
			{
				aux[i] = tabele[i];
			}
			delete[] tabele;
			tabele = new table[nr];
			nr++;
			for (int i = 0; i < nr - 2; i++)
			{
				tabele[i] = aux[i];
			}
			delete[] aux;
			cin >> tabele[nr - 2];
		}
		return copie;
	}
	table& operator[](int index)
	{
		if (index >= 0 && index < nr)
		{
			if (nr > 0)
				return tabele[index];
		}
	}
	explicit operator int()
	{
		return nr;
	}
	bool operator!()
	{
		return nr > 0;
	}
	bool operator<(database d)
	{
		return this->nr < d.nr;
	}
	bool operator==(database d)
	{
		bool ok = 1;
		if (this->nr != d.nr)
		{
			ok = 0;
		}
		else
		{
			if (!(this->tabele == d.tabele) && this->nr > 1)
			{
				ok = 0;
			}
		}
		return ok;
	}
	int getNr()
	{
		return this->nr;
	}
	void setNr(int nr)
	{
		this->nr = nr;
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
		comenzi += ", ";
		if (nr == 1)
		{
			this->tabele[nr - 1].setNume(nume);
			comenzi.erase(comenzi.length() - 1);
			comenzi.erase(0, 1);
			while (comenzi != "")
			{
				poz = comenzi.find(")");
				instr = comenzi.substr(0, poz);
				instr.erase(0, 1);
				tabele[nr - 1].adauga_coloana(instr);
				comenzi.erase(0, poz + 3);
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
				this->tabele[nr - 1].setNume(nume);
				comenzi.erase(comenzi.length() - 1);
				comenzi.erase(0, 1);
				while (comenzi != "")
				{
					poz = comenzi.find(")");
					instr = comenzi.substr(0, poz);
					instr.erase(0, 1);
					tabele[nr - 1].adauga_coloana(instr);
					comenzi.erase(0, poz + 3);
				}
				nr++;
				cout << "Tabela creata" << endl;
			}
			else cout << "Tabela existenta";
		}
	}
	void drop(string nume)
	{
		int ok = 0, i;
		for (i = 0; i < this->nr-1; i++)
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
		for (i = 0; i < this->nr - 1; i++)
		{
			if (tabele[i].getNume() == nume)
				ok = 1;
		}
		if (ok)
		{
			for (i = 0; i < this->nr - 1; i++)
			{
				if (tabele[i].getNume() == nume)
				{
					cout << tabele[i];
				}
			}
		}
		else cout << "Tabela nu exista";
	}
	void insert(string nume, string comenzi)
	{
		int ok = 0, i, k;
		for (i = 0; i < this->nr - 1; i++)
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
	void del(string nume, string comenzi)
	{
		int ok = 0, i, k;
		for (i = 0; i < this->nr - 1; i++)
		{
			if (tabele[i].getNume() == nume)

			{
				ok = 1;
				k = i;
			}
		}
		if (ok)
		{
			tabele[k].del(comenzi);
		}
		else cout << "Tabela nu exista";
	}
	void update(string nume, string p1, string p2)
	{
		int ok = 0, i, k;
		for (i = 0; i < this->nr - 1; i++)
		{
			if (tabele[i].getNume() == nume)

			{
				ok = 1;
				k = i;
			}
		}
		if (ok)
		{
			tabele[k].update(p1, p2);
		}
		else cout << "Tabela nu exista";
	}
	void select(string nume, string cols, string cond)
	{
		int ok = 0, i, k;
		for (i = 0; i < this->nr - 1; i++)
		{
			if (tabele[i].getNume() == nume)

			{
				ok = 1;
				k = i;
			}
		}
		if (ok)
		{
			tabele[k].select(cols, cond);
		}
		else cout << "Tabela nu exista";
	}
	friend class consola;
	friend istream& operator>>(istream&, database&);
	friend ostream& operator<<(ostream&, database);

};

class writefile
{
private:
	
public:
	writefile()
	{
	
	}
	writefile(string s)
	{
		
	}
	~writefile()
	{

	}
}; 

class readfile
{
private:
	ifstream f;
	string a;
public:
	readfile()
	{
		f.open("cfg.txt", ios::in);	
		getline(f, a);
		if (a == "config")
		{
			readconfig();
		}
	}
	readfile(string s)
	{
		int poz=-1;
		poz = s.find('.bin');
		if (poz!=-1)
		{
			f.open(s, ios::in | ios::binary);
		}
		else
			f.open(s, ios::in);
		string a;
		getline(f, a);	
		if(a=="create")
		{
			
		}
		else
			if (a == "insert")
			{

			}
	}
	void readconfig()
	{
		string a, nume, coloane;
		int poz;
		while (f.peek() != NULL)
		{
			getline(f, a);
			poz = a.find(' ');
			nume = a.substr(0, poz);
			a.erase(0, poz + 1);
			coloane = a;
		}
	}
	~readfile()
	{


	};
};

class consola
{
private:
	string create = "CREATE TABLE";
	string drop = "DROP TABLE";
	string display = "DISPLAY TABLE";
	string insert = "INSERT INTO";
	string del = "DELETE FROM";
	string update = "UPDATE";
	string select = "SELECT";
	string instructiune = "";
	const char* aplicatie = "SGBD Tip Sqlite";
	int cnt = 0;
	string comenzi[500];
public:

	consola()
	{
		cout << aplicatie << endl;
		cout << "Sintaxa instructiuni:" << endl;
		cout << "CREATE TABLE nume_tabela ((nume_coloana, tip, dimensiune, valoare_implicita), (nume_coloana2, tip, dimensiune, valoare_implicita)...)" << endl;
		cout << "DROP TABLE nume_tabela" << endl;
		cout << "DISPLAY TABLE nume_tabela" << endl;
		cout << "INSERT INTO nume_tabela VALUES (val1, val2, ...)" << endl;
		cout << "DELETE FROM nume_tabela WHERE nume_coloana = valoare" << endl;
		cout << "UPDATE nume_tabela SET nume_coloana = valoare WHERE nume_coloana = valoare" << endl;
		cout << "SELECT (cel_putin_o_coloana, ...) | ALL FROM nume_tabela [WHERE nume_coloana = valoare]" << endl;
		cout << "Introduceti instructiune" << endl;
	}
	//SELECT (cel_putin_o_coloana, ...) | ALL FROM nume_tabela [WHERE nume_coloană = valoare] - clauza WHERE este optionala
	//SELECT (v1,v2) FROM nume_tabela WHERE .. 

	int crud(database& a)
	{

		int poz = -1, ok = 1;
		while (ok)
		{
			cout << endl;
			if (instructiune != "")
			{
				cout << aplicatie << endl;
				cout << "Sintaxa instructiuni:" << endl;
				cout << "CREATE TABLE nume_tabela ((nume_coloana, tip, dimensiune, valoare_implicita), (nume_coloana2, tip, dimensiune, valoare_implicita)...)" << endl;
				cout << "DROP TABLE nume_tabela" << endl;
				cout << "DISPLAY TABLE nume_tabela" << endl;
				cout << "INSERT INTO nume_tabela VALUES (val1, val2, ...)" << endl;
				cout << "DELETE FROM nume_tabela WHERE nume_coloana = valoare" << endl;
				cout << "UPDATE nume_tabela SET nume_coloana = valoare WHERE nume_coloana = valoare" << endl;
				cout << "SELECT (cel_putin_o_coloana, ...) | ALL FROM nume_tabela [WHERE nume_coloana = valoare]" << endl;
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
				poz = instructiune.find(del);
				if (poz != -1)
				{
					ok = crud_delete(a, poz);
				}
				poz = instructiune.find(update);
				if (poz != -1)
				{
					ok = crud_update(a, poz);
				}
				poz = instructiune.find(select);
				if (poz != -1)
				{
					ok = crud_select(a, poz);
				}
				comenzi[cnt] = instructiune;
				cnt++;
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
	int crud_delete(database& a, int poz)
	{
		instructiune.erase(poz, insert.length() + 1);
		poz = instructiune.find(" ");
		string nume = instructiune.substr(0, poz);
		instructiune.erase(0, poz + 1);
		poz = instructiune.find(" ");
		instructiune.erase(0, poz + 1);
		a.del(nume, instructiune);
		return 1;
	}

	int crud_update(database& a, int poz)
	{
		string p1, p2;
		instructiune.erase(poz, update.length() + 1);
		poz = instructiune.find(" ");
		string nume = instructiune.substr(0, poz);
		instructiune.erase(0, poz + 1);
		poz = instructiune.find(" ");
		instructiune.erase(0, poz + 1);
		a.del(nume, instructiune);
		poz = instructiune.find("WHERE");
		p1 = instructiune.substr(0, poz);
		instructiune.erase(0, poz + 6);
		p2 = instructiune;
		a.update(nume, p1, p2);
		return 1;
	}
	int crud_select(database& a, int poz)
	{
		string cols, nume, cond;
		instructiune = instructiune + ' ';
		instructiune.erase(poz, select.length() + 1);
		poz = instructiune.find("FROM");
		cols = instructiune.substr(0, poz-1);
		instructiune.erase(0, poz + 5);
		poz = instructiune.find(' ');
		nume = instructiune.substr(0, poz);
		instructiune.erase(0, poz + 1);
		if (instructiune != "")

		{
			instructiune.erase(0, poz + 1);
			cond = instructiune;
		}
		else
		{
			cond = "";
		}
		a.select(nume, cols, cond);
		return 1;
	}
	void afisare()
	{
		if (comenzi != nullptr)
		{
			cout << getComenzi();
		}
		else
		{
			cout << "Nu exista instructiuni" << endl;
		}
	}
	string* getComenzi()
	{
		if (comenzi != nullptr)
		{
			string* copie = new string[cnt];
			for (int i = 0; i < cnt; i++)
			{
				copie[i] = comenzi[i];
			}
			return copie;
		}
		else
		{
			return nullptr;
		}
	}

};
//CREATE TABLE tab1 coltxt,text,10,nimic colfloat,float,10,0 colint,int,10,0
//INSERT INTO tab1 VALUES da,5,6

