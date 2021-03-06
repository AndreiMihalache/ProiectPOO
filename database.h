﻿#include<iostream>
#include <string>
#include<iomanip>
#include <fstream>
#include <vector>
#include <list>
#include <map>
#include <set>

using namespace std;

class reg
{
private:
	static int index;
	string* valori;
	int contor, capacitate;
	vector <reg> ierarhie;
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
	virtual void setCap(int n)
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
	virtual void delpos(int ind)
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
	virtual void append(string val)
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
	friend class tablefile;
};
class reg2 : public reg
{
private:
	map <int,string> valori;
	int contor, capacitate;
	reg* base;
public:
	reg2()
	{
		contor = 0;
		capacitate = 0;
	}
	reg2 (reg2& r)
	{
		this->contor = r.contor;
		this->capacitate = r.capacitate;
		if (this->capacitate)
		{
			this->valori = r.valori;
		}
	}
	reg2 operator=(reg2& r)
	{
		
		this->contor = r.contor;
		this->capacitate = r.capacitate;
		if (this->capacitate)
		{
			this->valori = r.valori;
		}
		return *this;
	}
	~reg2()
	{
		
	}
	void setCap(int n) override
	{
		this->capacitate = n;
	}
	void delpos(int index) override
	{
		valori.erase(index);
	}
	void append(string val) override
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
	friend class table;
};

class reg3 : public reg
{
private:
	set <pair<int,string>> valori;
	int contor, capacitate;
	reg* base;
public:
	reg3()
	{
		contor = 0;
		capacitate = 0;
	}
	reg3(reg3& r)
	{
		this->contor = r.contor;
		this->capacitate = r.capacitate;
		if (this->capacitate)
		{
			this->valori = r.valori;
		}
	}
	reg3 operator=(reg3& r)
	{

		this->contor = r.contor;
		this->capacitate = r.capacitate;
		if (this->capacitate)
		{
			this->valori = r.valori;
		}
		return *this;
	}
	~reg3()
	{

	}
	void setCap(int n) override
	{
		this->capacitate = n;
	}
	void append(string val) override
	{
		if (contor < capacitate)
		{
			valori.insert(make_pair(contor, val));
			contor++;
		}
		else
		{
			cout << "Capacitate maxima atinsa";
		}
	}
	friend class table;
};

class reg4 : public reg
{
private:
	list <string> valori;
	int contor, capacitate;
	reg* base;
public:
	reg4()
	{
		contor = 0;
		capacitate = 0;
	}
	reg4(reg4& r)
	{
		this->contor = r.contor;
		this->capacitate = r.capacitate;
		if (this->capacitate)
		{
			this->valori = r.valori;
		}
	}
	reg4 operator=(reg4& r)
	{

		this->contor = r.contor;
		this->capacitate = r.capacitate;
		if (this->capacitate)
		{
			this->valori = r.valori;
		}
		return *this;
	}
	~reg4()
	{

	}
	void setCap(int n) override
	{
		this->capacitate = n;
	}

	void append(string val) override
	{
		if (contor < capacitate)
		{
			valori.push_back(val);
			contor++;
		}
		else
		{
			cout << "Capacitate maxima atinsa";
		}
	}
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

class tablefile
{
private:
	int nrreg;
	string* inreg;
public:
	tablefile()
	{
		nrreg = 0;
		inreg = nullptr;
	}
	~tablefile()
	{
		if (inreg != nullptr)

			delete[] inreg;
	}
	tablefile(tablefile& t)
	{
		this->nrreg = t.nrreg;
		if (this->nrreg)
		{
			this->inreg = new string[nrreg];
			for (int it = 0; it < nrreg; it++)
			{
				this->inreg = t.inreg;
			}
		}
		else
			this->inreg = nullptr;
	}
	tablefile operator=(tablefile& t)
	{
		if (this->inreg != nullptr)
			delete[] this->inreg;
		this->nrreg = t.nrreg;
		if (this->nrreg)
		{
			this->inreg = new string[nrreg];
			for (int it = 0; it < nrreg; it++)
			{
				this->inreg = t.inreg;
			}
		}
		else
			this->inreg = nullptr;
		return *this;
	}
	void del(string s)
	{
		int contor = 0;
		string* aux = new string[nrreg - 1];
		for (int i = 0; i < nrreg; i++)
		{
			if (inreg[i].find(s) > 0)
			{
				aux[contor] = inreg[i];
				contor++;
			}
		}
		delete[] inreg;
		nrreg--;
		inreg = new string[nrreg];
		for (int i = 0; i < nrreg; i++)
		{
			inreg[i] = aux[i];
		}
	}
	void add(string s)
	{
		if (inreg != nullptr)
		{
			string* aux = new string[nrreg + 1];
			for (int i = 0; i < nrreg; i++)
			{
				aux[i] = inreg[i];
			}
			delete[] inreg;
			nrreg++;
			inreg = new string[nrreg];
			for (int i = 0; i < nrreg - 1; i++)
			{
				inreg[i] = aux[i];
			}
			inreg[nrreg - 1] = s;
		}
		else
		{
			nrreg++;
			inreg = new string[nrreg];
			inreg[nrreg - 1] = s;
		}
	}
	void write(string name)
	{
		ofstream f;
		f.open((name + ".bin").c_str(), ios::binary);
		int length;
		f.write((char*)&nrreg, sizeof(nrreg));
		if (nrreg > 0)
		{
			for (int j = 0; j < nrreg; j++)
			{
				length = inreg[j].length();
				f.write((char*)&length, sizeof(length));
				f.write(inreg[j].c_str(), length + 1);
			}
		}
		f.close();
	}
	friend class table;
	friend class reg;
};

class table
{
protected:
	string nume;
	coloana* col;
	int i, k;
	reg* rand;
	//tablefile* file;
	vector <string> com;
public:
	table()
	{
		col = nullptr;
		nume = "";
		i = 0;
		rand = nullptr;
		k = 0;
		//file = new tablefile;
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
		this->com = t.com;
		//this->file = t.file;

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
		//this->file = t.file;
		this->com = t.com;
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
		try
		{
			if (col[index].tip == "int" && ok != 1)
			{
				if (to_string(stoi(val)) == val && val.size() <= stoi(col[index].dimensiune))
					return ok = 1;
			}
		}
		catch (...)
		{
			ok = -1;
			return ok;
		}
		try
		{
			if (col[index].tip == "float" && ok != 1)
			{
				if (stof(to_string(stof(val))) == stof(val) && val.size() <= stoi(col[index].dimensiune))
					return ok = 1;
			}
		}
		catch (...)
		{
			ok = -1;
			return ok;
		}
		try
		{
			if (col[index].tip == "text" && ok != 1)
			{
				if (val.size() <= stoi(col[index].dimensiune))
					ok = 1;
			}
		}
		catch (...)
		{
			ok = -1;
			return ok;
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
	
	void write()
	{
		ofstream f;
		f.open((nume + ".bin").c_str(), ios::binary);
		int length;
		length = com.size();
		f.write((char*)&length, sizeof(length));
		if (com.size() > 0)
		{

			for (int j = 0; j < com.size(); j++)
			{
				length = com[j].length();
				f.write((char*)&length, sizeof(length));
				f.write(com[j].c_str(), length + 1);
			}
		}
		f.close();
	}
	void config()
	{
		ifstream f;
		f.open((nume + ".bin").c_str(), ios::binary);
		int contor;
		f.read((char*)&contor, sizeof(contor));
		if (contor > 0)
		{
			int length;
			char* aux;
			for (int it = 0; it < contor; it++)
			{
				f.read((char*)&length, sizeof(length));
				aux = new char[length + 1];
				f.read(aux, length + 1);
				string aux2;
				aux2 = aux;
				insert(aux2);
			}
		}
	}
	void insert(string values)
	{
		string val, aux;
		bool ok = 1;
		val = values;
		val.erase(0, 1);
		val.erase(val.length() - 1);
		val = val + ", ";
		int poz, index = -1;
		while (val != "")
		{
			poz = val.find(",");
			aux = val.substr(0, poz);
			index++;
			if (valid(aux, index) != 1)
			{
				ok = 0;
			}
			val.erase(0, poz + 2);
		}
		if (ok)
		{
			addrand();
			com.push_back(values);
			values.erase(0, 1);
			values.erase(values.length() - 1);
			values = values + ", ";
			for(int j=0;j<i;j++)
			{
				poz = values.find(',');
				aux = values.substr(0, poz);
				if (aux == " ")
				{
					rand[k - 1].append(col[i].valoare_implicita);
				}
				else
				{
					rand[k - 1].append(aux);
				}
				values.erase(0, poz + 2);
			}
		}
		else
		{
			cout << "Datele nu corespund tipului de coloana";
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
							k = 0;
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
	void center(string str, int& nrselect, ofstream& f)
	{
		int size;
		string aux;
		if (str == string("endl"))
		{
			cout << endl;
			f << endl;
		}
		else
		{
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
				cout << aux << ' ';
				f << aux << ' ';
			}
			else
			{
				cout << aux << string(size, ' ');
				f << aux << string(size, ' ');
			}
		}
	}
	void select(string cols, string cond, int& nrselect)
	{
		if (k == 0)
		{
			cout << "Tabela este goala";
		}
		else
		{
			nrselect++;
			string d = string("SELECT");
			d = d + '_';
			d = d + to_string(nrselect);
			d = d + ".txt";
			ofstream f(d.c_str(), ios::out);
			cout << endl;
			if (cond == "")
			{
				if (cols == "ALL")
				{
					cout << string(12 * i, '-') << endl;;
					for (int j = 0; j < i; j++)
					{
						center(col[j].nume, nrselect, f);
					}
					cout << endl << string(12 * i, '-') << endl;
					for (int x = 0; x < k; x++)
					{
						center(string("endl"), nrselect, f);
						for (int z = 0; z < i; z++)
						{
							center(rand[x].valori[z], nrselect, f);
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
					if (contor > 0)
					{
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
						center(string("endl"), nrselect, f);
						for (int j = 0; j < contor; j++)
						{
							center(col[indexes[j]].nume, nrselect, f);
						}
						center(string("endl"), nrselect, f);
						for (int j = 0; j < k; j++)
						{
							for (int x = 0; x < contor; x++)
							{
								center(rand[j].valori[indexes[x]], nrselect, f);
							}
						}
					}
					else cout << endl << "Coloanele nu exista";
				}
			}
			else
			{
				string arg1;
				string arg2;
				int poz;
				cond.erase(0, 1);
				poz = cond.find(' ');
				arg1 = cond.substr(0, poz);
				cond.erase(0, poz + 3);
				poz = cond.find(' ');
				arg2 = cond.substr(0, poz);;
				int ok1 = 0, ok2 = 0;
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
					if (rand[j].valori[index] == arg2)
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
							center(col[j].nume, nrselect, f);
						}
						for (int x = 0; x < k; x++)
						{
							center(string("endl"), nrselect, f);
							for (int z = 0; z < i; z++)
							{
								if (rand[x].valori[index] == arg2)
									center(rand[x].valori[z], nrselect, f);
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
						if (contor > 0)
						{

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
							center(string("endl"), nrselect, f);
							for (int j = 0; j < contor; j++)
							{
								center(col[j].nume, nrselect, f);
							}
							center(string("endl"), nrselect, f);
							for (int j = 0; j < k; j++)
							{
								for (int x = 0; x < contor; x++)
								{
									if (rand[j].valori[index] == arg2)
										center(rand[j].valori[x], nrselect, f);
								}
							}
						}
						else cout << endl << "Coloanele nu exista";
					}
				}
				else
				{
					cout << "Nu exista inregistrari care sa respecte conditia";
				}
			}
			f.close();
		}
	}

	void import(string comenzi)
	{
		ifstream f(comenzi.c_str(), ios::in);
		int aux;
		string aux2;
		bool ok = 1;
		getline(f, aux2);
		aux = stoi(aux2);
		for (int j = 0; j < aux && ok == 1; j++)
		{
			string lin;
			int poz;
			getline(f, lin);
			string cop = lin;
			if (cop[0] != '(' || cop[cop.length() - 1] != ')')
			{
				ok = 0;
			}
			cop.erase(cop.length() - 1);
			cop.erase(0, 1);
			cop += ", ";
			int cnt = 0;
			while (cop != "")
			{
				poz = cop.find(',');
				cop.erase(0, poz);
				if (cop[0] != ',')
				{
					ok = 0;
				}
				cop.erase(0, 1);
				if (cop[0] != ' ')
				{
					ok = 0;
				}
				cop.erase(0, 1);
				cnt++;
			}
			if (cnt != i)
			{
				ok = 0;
			}

		}
		if (ok == 1)
		{
			f.seekg(0);
			int aux;
			string lin, aux2;
			getline(f, aux2);
			aux = stoi(aux2);
			for (int j = 0; j < aux; j++)
			{
				getline(f, lin);
				insert(lin);
			}
		}
	}


	friend class database;
	friend class tablefile;

	friend istream& operator>>(istream&, table&);
	friend ostream& operator<<(ostream&, table);
	friend ofstream& operator<<(ofstream&, table);
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
	o << endl << "Nume tabela : " << t.getNume() << endl << endl;
	o << "Numar coloane : " << t.getI() << endl;
	for (int j = 0; j < t.i; j++)
	{
		o << "Coloana " << j + 1 << " : " << t.col[j] << endl;
	}
	return o;
}

ofstream& operator<<(ofstream& o, table t)
{
	o << endl << "Nume tabela : " << t.getNume() << endl << endl;
	o << "Numar coloane : " << t.getI() << endl;
	for (int j = 0; j < t.i; j++)
	{
		o << "Coloana " << j + 1 << " : " << t.col[j] << endl;
	}
	return o;
}
class writeconfig
{
private:
	int nrtab;
	string* tabele;
public:
	writeconfig()
	{
		nrtab = 0;
		tabele = nullptr;
	}
	void del(string s)
	{
		int contor = 0;
		string* aux = new string[nrtab - 1];
		for (int i = 0; i < nrtab; i++)
		{
			if (tabele[i].find(s) > 0)
			{
				aux[contor] = tabele[i];
				contor++;
			}
		}
		delete[] tabele;
		nrtab--;
		tabele = new string[nrtab];
		for (int i = 0; i < nrtab; i++)
		{
			tabele[i] = aux[i];
		}
	}
	void add(string s)
	{
		if (tabele != nullptr)
		{
			string* aux = new string[nrtab + 1];
			for (int i = 0; i < nrtab; i++)
			{
				aux[i] = tabele[i];
			}
			delete[] tabele;
			nrtab++;
			tabele = new string[nrtab];
			for (int i = 0; i < nrtab - 1; i++)
			{
				tabele[i] = aux[i];
			}
			tabele[nrtab - 1] = s;
		}
		else
		{
			nrtab++;
			tabele = new string[nrtab];
			tabele[nrtab - 1] = s;
		}
	}
	void write()
	{
		ofstream f;
		f.open("cfg.txt", ofstream::out | std::ofstream::trunc);
		f << "config" << endl;
		f << nrtab + 1 << endl;;
		for (int i = 0; i < nrtab; i++)
		{

			f << tabele[i] << endl;
		}
		f.close();
	}
	~writeconfig()
	{
		if (tabele != nullptr)
			delete[] tabele;


	}
	writeconfig(writeconfig& c)
	{
		this->nrtab = c.nrtab;
		if (this->nrtab)
		{
			this->tabele = new string[nrtab];
			for (int it = 0; it < nrtab; it++)
			{
				this->tabele[it] = c.tabele[it];
			}
		}
		else
		{
			this->tabele = nullptr;
		}
	}
};

class database
{
private:
	int nr;
	table* tabele;
	writeconfig* cfg;
	int nrdisplay = 0, nrselect = 0;
public:
	database()
	{
		this->nr = 1;
		this->tabele = nullptr;
		cfg = new writeconfig;
	}
	~database()
	{

		for (int it = 0; it < nr - 1; it++)
		{
			tabele[it].write();
		}
		if (this->tabele != nullptr)
			delete[] tabele;
		cfg->write();
		delete cfg;
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
		this->cfg = d.cfg;
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
	void eraseTable()
	{
		if (tabele != nullptr)
		{
			table* aux = new table[nr - 1];
			for (int i = 0; i < nr - 2; i++)
			{
				aux[i] = tabele[i];
			}
			delete[] tabele;
			nr--;
			tabele = new table[nr - 1];
			for (int i = 0; i < nr - 2; i++)
			{
				tabele[i] = aux[i];
			}
			delete[] aux;
		}
	}
	void config(string nume, string comenzi)
	{
		//newTable();
		int i;
		int ok = 1;
		string instr;
		int poz;
		if (nr == 1)
		{
			newTable();
			this->tabele[nr - 1].setNume(nume);
			string tocfg = nume + ' ' + comenzi;
			cfg->add(tocfg);
			comenzi.erase(comenzi.length() - 1);
			comenzi.erase(0, 1);
			comenzi += ", ";
			while (comenzi != "")
			{
				poz = comenzi.find(")");
				instr = comenzi.substr(0, poz);
				instr.erase(0, 1);
				tabele[nr - 1].adauga_coloana(instr);
				comenzi.erase(0, poz + 3);
			}
			tabele[nr - 1].config();
			nr++;
		}
		else
		{
			for (i = 0; i < this->nr - 1; i++)
			{
				if (tabele[i].getNume() == nume)
					ok = 0;
			}

			if (ok)
			{
				newTable();
				this->tabele[nr - 1].setNume(nume);
				string tocfg = nume + ' ' + comenzi;
				cfg->add(tocfg);
				comenzi.erase(comenzi.length() - 1);
				comenzi.erase(0, 1);
				comenzi += ", ";
				while (comenzi != "")
				{
					poz = comenzi.find(")");
					instr = comenzi.substr(0, poz);
					instr.erase(0, 1);
					tabele[nr - 1].adauga_coloana(instr);
					comenzi.erase(0, poz + 3);
				}
				tabele[nr - 1].config();
				nr++;
			}
		}
	}

	void create(string nume, string comenzi)
	{
		//newTable();
		int i;
		int ok = 1;
		string instr;
		int poz;
		if (nr == 1)
		{
			newTable();
			this->tabele[nr - 1].setNume(nume);
			string tocfg = nume + ' ' + comenzi;
			cfg->add(tocfg);
			comenzi.erase(comenzi.length() - 1);
			comenzi.erase(0, 1);
			comenzi += ", ";
			while (comenzi != "")
			{
				poz = comenzi.find(")");
				instr = comenzi.substr(0, poz);
				instr.erase(0, 1);
				tabele[nr - 1].adauga_coloana(instr);
				comenzi.erase(0, poz + 3);
			}
			ofstream f(nume + ".bin", ios::out | ios::binary);
			f.close();
			nr++;
			cout << "Tabela creata" << endl;
		}
		else
		{
			for (i = 0; i < this->nr - 1; i++)
			{
				if (tabele[i].getNume() == nume)
					ok = 0;
			}

			if (ok)
			{
				newTable();
				this->tabele[nr - 1].setNume(nume);
				string tocfg = nume + ' ' + comenzi;
				cfg->add(tocfg);
				comenzi.erase(comenzi.length() - 1);
				comenzi.erase(0, 1);
				comenzi += ", ";
				while (comenzi != "")
				{
					poz = comenzi.find(")");
					instr = comenzi.substr(0, poz);
					instr.erase(0, 1);
					tabele[nr - 1].adauga_coloana(instr);
					comenzi.erase(0, poz + 3);
				}
				ofstream f(nume + ".bin", ios::out | ios::binary);
				f.close();
				nr++;
				cout << "Tabela creata" << endl;
			}
			else cout << "Tabela existenta";
		}
	}
	void drop(string nume)
	{
		int ok = 0, i;
		for (i = 0; i < this->nr - 1; i++)
		{
			if (tabele[i].getNume() == nume)
				ok = 1;
		}
		if (ok)
		{
			cfg->del(nume);
			string todel;
			todel = nume + ".bin";
			remove(nume.c_str());
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
			nrdisplay++;
			for (i = 0; i < this->nr - 1; i++)
			{
				if (tabele[i].getNume() == nume)
				{
					string d("display");
					d = d + '_';
					d = d + to_string(nrdisplay);
					d = d + ".txt";
					ofstream f(d.c_str(), ios::out);
					f << tabele[i];
					f.close();

				}
			}
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
			tabele[k].select(cols, cond, nrselect);
		}
		else cout << "Tabela nu exista";
	}
	void import(string nume, string comenzi)
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
			tabele[k].import(comenzi);
		}
	}
	friend class consola;
	friend istream& operator>>(istream&, database&);
	friend ostream& operator<<(ostream&, database);

};


class readfile
{
private:
	ifstream f;
	string str;
public:
	readfile(database& a)
	{
		f.open("cfg.txt", ios::in);
		getline(f, str);
		if (str == "config")
		{
			readconfig(a);
		}
		f.close();
	}
	readfile(string s, database& a)
	{
		int poz = -1;
		f.open(s, ios::in);
		poz = s.find(".csv");
		if (poz == -1)
		{
			getline(f, str);
			if (str == "create")
			{
				create(a);
			}
			else
				if (str == "insert")
				{
					insert(a);
				}
		}
		else
		{
			cout << "Nu e gata CSV";
		}
		f.close();
	}
	void readconfig(database& a)
	{
		string  nume, coloane;
		int poz;
		getline(f, str);
		int max = stoi(str);
		for (int it = 0; it < max - 1; it++)
		{
			getline(f, str);
			poz = str.find(' ');
			nume = str.substr(0, poz);
			str.erase(0, poz + 1);
			coloane = str;
			a.config(nume, coloane);
		}

	}
	void create(database& a)
	{
		string  nume, coloane;
		int poz;
		getline(f, str);
		int max = stoi(str);
		for (int it = 0; it < max - 1; it++)
		{
			getline(f, str);
			poz = str.find(' ');
			nume = str.substr(0, poz);
			str.erase(0, poz + 1);
			coloane = str;
			a.create(nume, coloane);
		}
	}
	void insert(database& a)
	{
		string  nume, valori;
		int poz;
		getline(f, str);
		nume = str;
		getline(f, str);
		int max = stoi(str);
		for (int it = 0; it < max - 1; it++)
		{
			getline(f, str);
			valori = str;
			a.create(nume, valori);
		}
	}
	~readfile()
	{

	}
};

class base_console
{
public:
	virtual void afisare() = 0;
	virtual int crud(database&) = 0;
};

class consola : public base_console
{
private:
	string create = "CREATE TABLE";
	string drop = "DROP TABLE";
	string display = "DISPLAY TABLE";
	string insert = "INSERT INTO";
	string del = "DELETE FROM";
	string update = "UPDATE";
	string select = "SELECT";
	string import = "IMPORT";
	string instructiune = "";
	const char* aplicatie = "SGBD Tip Sqlite";
	int cnt = 0;
	string comenzi[500];
public:

	consola()
	{
		cout << aplicatie << endl;
		cout << "Introduceti una dintre instructiunile:" << endl;
		cout << create << " / " << drop << " / " << display << " / " << insert << " / " << del << " / " << update << " / " << select << " / " << import << endl;
	}
	//SELECT (cel_putin_o_coloana, ...) | ALL FROM nume_tabela [WHERE nume_coloană = valoare] - clauza WHERE este optionala
	//SELECT (v1,v2) FROM nume_tabela WHERE .. 

	int crud(database& a) override
	{

		int poz = -1, ok = 1;
		bool vf3 = 0;
		while (ok)
		{
			cout << endl;
			if (instructiune == "MENIU")
			{
				cout << "Introduceti una dintre instructiunile:" << endl;
				cout << create << " / " << drop << " / " << display << " / " << insert << " / " << del << " / " << update << " / " << select << endl << endl;
				vf3 = 1;
			}
			else
			{
				cout << "Pentru a iesi scrieti EXIT" << endl;
				cout << "Pentru meniu scrieti MENIU" << endl << endl;
				vf3 = 1;
			}
			getline(std::cin, instructiune);
			if (instructiune == "EXIT")
			{
				ok = 0;
				break;
			}
			else
			{
				bool vf2 = 0;
				if (vf3 = 1)
				{
					vf2 = 1;
				}
				poz = instructiune.find(create);

				if (poz != -1)
				{
					if (instructiune == "CREATE TABLE")
					{
						cout << "Introduceti o sintaxa de forma : " << endl << "CREATE TABLE nume_tabela ((nume_coloana, tip, dimensiune, valoare_implicita), (nume_coloana2, tip, dimensiune, valoare_implicita)...)" << endl;
						vf2 = 1;
					}
					else
					{
						int vf = 1;
						int pz;
						string secv, cop;
						cop = instructiune;
						secv = instructiune.substr(0, create.length());
						if (secv != create)
						{
							vf = 0;
						}
						instructiune.erase(0, create.length());
						if (instructiune[0] != ' ')
						{
							vf = 0;
						}
						instructiune.erase(0, 1);
						pz = instructiune.find(' ');
						if (instructiune[pz] != ' ')
						{
							vf = 0;
						}
						instructiune.erase(0, pz + 1);
						if ((instructiune[instructiune.length() - 1] != ')' || instructiune[0] != '('))
						{
							vf = 0;
						}
						instructiune.erase(instructiune.length() - 1);
						instructiune.erase(0, 1);
						string cop3 = instructiune;
						cop3 += ", ";
						while (cop3 != "" && vf == 1)
						{
							pz = cop3.find(')');
							instructiune = cop3.substr(0, pz + 1);
							if (instructiune[instructiune.length() - 1] != ')' || instructiune[0] != '(')
							{
								vf = 0;
							}
							instructiune.erase(instructiune.length() - 1);
							instructiune.erase(0, 1);
							string cop2 = instructiune;
							int cnt = 0;
							instructiune += ", ";
							while (instructiune != "")
							{
								pz = instructiune.find(',');
								cnt++;
								instructiune.erase(0, pz + 2);
							}
							if (cnt != 4)
							{
								vf = 0;
							}
							instructiune = cop2;
							pz = instructiune.find(',');
							instructiune.erase(0, pz + 2);
							pz = instructiune.find(',');
							secv = instructiune.substr(0, pz);
							if (secv != "int" && secv != "float" && secv != "text")
							{
								vf = 0;
							}
							pz = instructiune.find(',');
							instructiune.erase(0, pz + 2);
							pz = instructiune.find(',');
							secv = instructiune.substr(0, pz);
							while (secv != "")
							{
								if (secv[0] < '0' || secv[0]>'9')
								{
									vf = 0;
								}
								secv.erase(0, 1);
							}
							pz = instructiune.find(',');
							instructiune.erase(0, pz + 2);
							while (instructiune != "")
							{
								if (instructiune[0] < '0' || instructiune[0]>'9')
								{
									vf = 0;
								}
								instructiune.erase(0, 1);
							}
							pz = cop3.find(')');
							cop3.erase(0, pz + 3);
						}
						if (vf == 1)
						{
							instructiune = cop;
							ok = crud_create(a, poz);
							vf2 = 1;
						}
						else
						{
							cout << "Comanda introdusa nu este corecta. Incercati din nou" << endl;
							vf2 = 1;
						}
					}
				}
				poz = instructiune.find(drop);
				if (poz != -1)
				{
					if (instructiune == "DROP TABLE")
					{
						cout << "Introduceti o sintaxa de forma : " << endl << "DROP TABLE nume_tabela" << endl;
						vf2 = 1;
					}
					else
					{
						int pz, vf = 1;
						string secv, cop;
						cop = instructiune;
						secv = instructiune.substr(0, drop.length());
						if (secv != drop)
						{
							vf = 0;
						}
						instructiune.erase(0, drop.length());
						if (instructiune[0] != ' ')
						{
							vf = 0;
						}
						instructiune.erase(0, 1);
						if (vf == 1)
						{
							instructiune = cop;
							ok = crud_drop(a, poz);
							vf2 = 1;
						}
						else
						{
							cout << "Comanda introdusa nu este corecta. Incercati din nou" << endl;
							vf2 = 1;
						}
					}
				}
				poz = instructiune.find(display);
				if (poz != -1)
				{

					if (instructiune == "DISPLAY TABLE")
					{
						cout << "Introduceti o sintaxa de forma : " << endl << "DISPLAY TABLE nume_tabela" << endl;
						vf2 = 1;
					}
					else
					{
						int pz, vf = 1;
						string secv, cop;
						cop = instructiune;
						secv = instructiune.substr(0, display.length());
						if (secv != display)
						{
							vf = 0;
						}
						instructiune.erase(0, display.length());
						if (instructiune[0] != ' ')
						{
							vf = 0;
						}
						instructiune.erase(0, 1);
						if (vf == 1)
						{
							instructiune = cop;
							ok = crud_display(a, poz);
							vf2 = 1;
						}
						else
						{
							cout << "Comanda introdusa nu este corecta. Incercati din nou" << endl;
							vf2 = 1;
						}
					}
				}
				poz = instructiune.find(insert);
				if (poz != -1)
				{
					if (instructiune == "INSERT INTO")
					{
						cout << "Introduceti o sintaxa de forma : " << endl << "INSERT INTO nume_tabela VALUES (val1, val2, ...)" << endl;
						vf2 = 1;
					}
					else
					{
						int pz, vf = 1;
						string secv, cop;
						cop = instructiune;
						secv = instructiune.substr(0, insert.length());
						if (secv != insert)
						{
							vf = 0;
						}
						instructiune.erase(0, insert.length());
						if (instructiune[0] != ' ')
						{
							vf = 0;
						}
						instructiune.erase(0, 1);
						pz = instructiune.find(' ');
						instructiune.erase(0, pz);
						if (instructiune[0] != ' ')
						{
							vf = 0;
						}
						instructiune.erase(0, 1);
						pz = instructiune.find(' ');
						instructiune.erase(0, pz);
						if (instructiune[0] != ' ')
						{
							vf = 0;
						}
						instructiune.erase(0, 1);
						if (instructiune[instructiune.length() - 1] != ')')
						{
							vf = 0;
						}
						instructiune.erase(instructiune.length() - 1);
						if (instructiune[0] != '(')
						{
							vf = 0;
						}
						instructiune.erase(0, 1);
						instructiune += ", ";
						while (instructiune != "")
						{
							pz = instructiune.find(',');
							instructiune.erase(0, pz + 1);
							if (instructiune[0] != ' ')
							{
								vf = 0;
							}
							instructiune.erase(0, 1);
						}
						if (vf == 1)
						{
							instructiune = cop;
							ok = crud_insert(a, poz);
							vf2 = 1;
						}
						else
						{
							cout << "Comanda introdusa nu este corecta. Incercati din nou" << endl;
							vf2 = 1;
						}
					}
				}
				poz = instructiune.find(del);
				if (poz != -1)
				{
					if (instructiune == "DELETE FROM")
					{
						cout << "Introduceti o sintaxa de forma : " << endl << "DELETE FROM nume_tabela WHERE nume_coloana = valoare" << endl;
						vf2 = 1;
					}
					else
					{
						int pz, vf = 1;
						string secv, cop;
						cop = instructiune;
						secv = instructiune.substr(0, del.length());
						if (secv != del)
						{
							vf = 0;
						}
						instructiune.erase(0, del.length());
						if (instructiune[0] != ' ')
						{
							vf = 0;
						}
						instructiune.erase(0, 1);
						pz = instructiune.find(' ');
						instructiune.erase(0, pz);
						if (instructiune[0] != ' ')
						{
							vf = 0;
						}
						instructiune.erase(0, 1);
						pz = instructiune.find(' ');
						secv = instructiune.substr(0, pz);
						if (secv != "WHERE")
						{
							vf = 0;
						}
						instructiune.erase(0, pz);
						if (instructiune[0] != ' ')
						{
							vf = 0;
						}
						instructiune.erase(0, 1);
						pz = instructiune.find(' ');
						instructiune.erase(0, pz);
						if (instructiune[0] != ' ')
						{
							vf = 0;
						}
						instructiune.erase(0, 1);
						if (instructiune[0] != '=')
						{
							vf = 0;
						}
						instructiune.erase(0, 1);
						if (instructiune[0] != ' ')
						{
							vf = 0;
						}
						if (vf == 1)
						{
							instructiune = cop;
							ok = crud_delete(a, poz);
							vf2 = 1;
						}
						else
						{
							cout << "Comanda introdusa nu este corecta. Incercati din nou" << endl;
							vf2 = 1;
						}
					}
				}
				poz = instructiune.find(update);
				if (poz != -1)
				{
					if (instructiune == "UPDATE")
					{
						cout << "Introduceti o sintaxa de forma : " << endl << "UPDATE nume_tabela SET nume_coloana = valoare WHERE nume_coloana = valoare" << endl;
						vf2 = 1;
					}
					else
					{
						int pz, vf = 1;
						string secv, cop;
						cop = instructiune;
						secv = instructiune.substr(0, update.length());
						if (secv != update)
						{
							vf = 0;
						}
						instructiune.erase(0, update.length());
						if (instructiune[0] != ' ')
						{
							vf = 0;
						}
						instructiune.erase(0, 1);
						pz = instructiune.find(' ');
						instructiune.erase(0, pz);
						if (instructiune[0] != ' ')
						{
							vf = 0;
						}
						instructiune.erase(0, 1);
						pz = instructiune.find(' ');
						secv = instructiune.substr(0, pz);
						if (secv != "SET")
						{
							vf = 0;
						}
						instructiune.erase(0, pz);
						if (instructiune[0] != ' ')
						{
							vf = 0;
						}
						instructiune.erase(0, 1);
						pz = instructiune.find(' ');
						instructiune.erase(0, pz);
						if (instructiune[0] != ' ')
						{
							vf = 0;
						}
						instructiune.erase(0, 1);
						if (instructiune[0] != '=')
						{
							vf = 0;
						}
						instructiune.erase(0, 1);
						if (instructiune[0] != ' ')
						{
							vf = 0;
						}
						instructiune.erase(0, 1);
						pz = instructiune.find(' ');
						instructiune.erase(0, pz);
						if (instructiune[0] != ' ')
						{
							vf = 0;
						}
						instructiune.erase(0, 1);
						pz = instructiune.find(' ');
						secv = instructiune.substr(0, pz);
						if (secv != "WHERE")
						{
							vf = 0;
						}
						instructiune.erase(0, pz);
						if (instructiune[0] != ' ')
						{
							vf = 0;
						}
						instructiune.erase(0, 1);
						pz = instructiune.find(' ');
						instructiune.erase(0, pz);
						if (instructiune[0] != ' ')
						{
							vf = 0;
						}
						instructiune.erase(0, 1);
						if (instructiune[0] != '=')
						{
							vf = 0;
						}
						instructiune.erase(0, 1);
						if (instructiune[0] != ' ')
						{
							vf = 0;
						}
						instructiune.erase(0, 1);
						if (vf == 1)
						{
							instructiune = cop;
							ok = crud_update(a, poz);
							vf2 = 1;
						}
						else
						{
							cout << "Comanda introdusa nu este corecta. Incercati din nou" << endl;
							vf2 = 1;
						}
					}
				}
				poz = instructiune.find(select);
				if (poz != -1)
				{
					if (instructiune == "SELECT")
					{
						cout << "Introduceti o sintaxa de forma : " << endl << "SELECT (cel_putin_o_coloana, ...) / ALL FROM nume_tabela [WHERE nume_coloana = valoare] - clauza WHERE este optionala" << endl;
						vf2 = 1;
					}
					else
					{
						int pz, vf = 1;
						string secv, cop;
						cop = instructiune;
						secv = instructiune.substr(0, select.length());
						if (secv != select)
						{
							vf = 0;
						}
						instructiune.erase(0, select.length());
						if (instructiune[0] != ' ')
						{
							vf = 0;
						}
						instructiune.erase(0, 1);
						if (instructiune[0] == 'A')
						{
							pz = instructiune.find(' ');
							secv = instructiune.substr(0, pz);
							if (secv != "ALL")
							{
								vf = 0;
							}
							instructiune.erase(0, pz);
							if (instructiune[0] != ' ')
							{
								vf = 0;
							}
							instructiune.erase(0, 1);
							pz = instructiune.find(' ');
							secv = instructiune.substr(0, pz);
							if (secv != "FROM")
							{
								vf = 0;
							}
							instructiune.erase(0, pz);
							if (instructiune[0] != ' ')
							{
								vf = 0;
							}
							instructiune.erase(0, 1);
							instructiune += ' ';
							pz = instructiune.find(' ');
							instructiune.erase(0, pz);
							if (instructiune[0] != ' ')
							{
								vf = 0;
							}
							instructiune.erase(0, 1);
							if (instructiune != "")
							{
								pz = instructiune.find(' ');
								secv = instructiune.substr(0, pz);
								if (secv != "WHERE")
								{
									vf = 0;
								}
								instructiune.erase(0, pz);
								if (instructiune[0] != ' ')
								{
									vf = 0;
								}
								instructiune.erase(0, 1);
								pz = instructiune.find(' ');
								instructiune.erase(0, pz);
								if (instructiune[0] != ' ')
								{
									vf = 0;
								}
								instructiune.erase(0, 1);
								if (instructiune[0] != '=')
								{
									vf = 0;
								}
								instructiune.erase(0, 1);
								if (instructiune[0] != ' ')
								{
									vf = 0;
								}
								instructiune.erase(0, 1);
							}
						}
						else if (instructiune[0] == '(')
						{
							instructiune.erase(0, 1);
							pz = instructiune.find(' ');
							while (instructiune[pz - 1] != ')')
							{
								if (instructiune[pz - 1] != ',')
								{
									vf = 0;
								}
								instructiune.erase(0, pz);
								if (instructiune[0] != ' ')
								{
									vf = 0;
								}
								instructiune.erase(0, 1);
								pz = instructiune.find(' ');
							}
							instructiune.erase(0, pz - 1);
							if (instructiune[0] != ')')
							{
								vf = 0;
							}
							instructiune.erase(0, 1);
							if (instructiune[0] != ' ')
							{
								vf = 0;
							}
							instructiune.erase(0, 1);
							pz = instructiune.find(' ');
							secv = instructiune.substr(0, pz);
							if (secv != "FROM")
							{
								vf = 0;
							}
							instructiune.erase(0, pz);
							if (instructiune[0] != ' ')
							{
								vf = 0;
							}
							instructiune.erase(0, 1);
							instructiune += ' ';
							pz = instructiune.find(' ');
							instructiune.erase(0, pz);
							if (instructiune[0] != ' ')
							{
								vf = 0;
							}
							instructiune.erase(0, 1);
							if (instructiune != "")
							{
								pz = instructiune.find(' ');
								secv = instructiune.substr(0, pz);
								if (secv != "WHERE")
								{
									vf = 0;
								}
								instructiune.erase(0, pz);
								if (instructiune[0] != ' ')
								{
									vf = 0;
								}
								instructiune.erase(0, 1);
								pz = instructiune.find(' ');
								instructiune.erase(0, pz);
								if (instructiune[0] != ' ')
								{
									vf = 0;
								}
								//instructiune.erase(0, pz);
								instructiune.erase(0, 1);
								//instructiune.erase(0, pz);
								if (instructiune[0] != '=')
								{
									vf = 0;
								}
								instructiune.erase(0, 1);
								pz = instructiune.find(' ');
								instructiune.erase(0, pz);
								if (instructiune[0] != ' ')
								{
									vf = 0;
								}
								instructiune.erase(0, 1);
							}
						}
						else
						{
							cout << "Comanda introdusa nu este corecta. Incercati din nou" << endl;
							vf2 = 1;
						}
						if (vf == 1)
						{
							instructiune = cop;
							ok = crud_select(a, poz);
							vf2 = 1;
						}
						else
						{
							cout << "Comanda introdusa nu este corecta. Incercati din nou" << endl;
							vf2 = 1;
						}
					}
				}
				poz = instructiune.find(import);
				if (poz != -1)
				{
					if (instructiune == "IMPORT")
					{
						cout << "Introduceti o sintaxa de forma : " << endl << "IMPORT nume_tabela nume_fisier.CSV" << endl;
						vf2 = 1;
					}
					else
					{
						int vf = 1;
						int pz;
						string secv, cop;
						cop = instructiune;
						secv = instructiune.substr(0, import.length());
						if (secv != import)
						{
							vf = 0;
						}
						instructiune.erase(0, import.length());
						if (instructiune[0] != ' ')
						{
							vf = 0;
						}
						instructiune.erase(0, 1);
						pz = instructiune.find(' ');
						instructiune.erase(0, pz);
						if (instructiune[0] != ' ')
						{
							vf = 0;
						}
						pz = instructiune.find('.');
						instructiune.erase(0, pz);
						if (instructiune[0] != '.')
						{
							vf = 0;
						}
						instructiune.erase(0, 1);
						if (instructiune != "csv")
						{
							vf = 0;
						}
						if (vf == 1)
						{
							instructiune = cop;
							ok = crud_import(a, poz);
							vf2 = 1;
						}
						else
						{
							cout << "Comanda introdusa nu este corecta. Incercati din nou" << endl;
							vf2 = 1;
						}
					}
				}
				if (vf2 == 0)
				{
					cout << "Comanda introdusa nu este corecta. Incercati din nou" << endl;
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
		cols = instructiune.substr(0, poz - 1);
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
	int crud_import(database& a, int poz)
	{
		instructiune.erase(0, import.length() + 1);
		poz = instructiune.find(" ");
		string nume = instructiune.substr(0, poz);
		instructiune.erase(0, poz + 1);
		a.import(nume, instructiune);
		return 1;
	}
	void afisare() override
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