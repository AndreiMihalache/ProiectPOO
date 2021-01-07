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
	readfile cfg(a);
	consola c;
	c.crud(a);
	return 0; 
	
}
