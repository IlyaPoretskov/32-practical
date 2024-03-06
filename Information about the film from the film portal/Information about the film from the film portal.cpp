// Information about the film from the film portal.cpp: определяет точку входа для приложения.
//

#include "Information about the film from the film portal.h"
#include <string>
#include <fstream>

using namespace std;

struct Record
{
	string name;
	string family;
};

int main()
{
	Record record;
	cin >> record.name >> record.family;
	ofstream file("record.json");
	file << "{" << endl << "\t\"name\": \"" << record.name << "\"" << "," << endl << "\t\"family\": \"" << record.family << "\"" << endl << "}" << endl;
}
