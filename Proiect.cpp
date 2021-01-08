#include <iostream>
#include <string>
#include "database.h"
#include <iomanip>

using namespace std;

int main(int argc, char** argv)
{
	string* s = new string[argc];
	for (int i = 0; i < argc; i++)
	{
		s[i] = argv[i];
	}
	database a;
	ifstream f;
	/*f.open("cfg.txt", ios::in);
	getline(f, str);
	int a::nr = stoi(str);*/
	//readfile cfg(a);
	consola c;
	c.crud(a);
	/*writeconfig a;
	a.add(string("nume1 ((col1, int, 10, 10), (col2, int, 10, 0))"));
	a.add(string("nume2 ((col1, int, 10, 10), (col2, int, 10, 0))"));
	a.add(string("nume3 ((col1, int, 10, 10), (col2, int, 10, 0))"));
	a.del(string("nume2"));
	a.write();*/
	return 0; 
	
}
