#include <iostream>
#include <string>
#include "database.h"
using namespace std;

int main()
{
	database a;
	cout << a.getnr();
	consola c;
	c.crud(a);
	return 0;
}