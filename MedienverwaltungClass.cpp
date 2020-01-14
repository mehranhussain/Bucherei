#include "pch.h"
#include "MedienverwaltungClass.h"

#include "util.h"

#include <algorithm>
#include <deque>
#include <forward_list>
#include <fstream>
#include <iostream>
#include <iterator>
#include <list>
#include <regex>
#include <sstream>
#include <typeinfo>
#include <vector>

using namespace std;

MedienverwaltungClass::MedienverwaltungClass()
{
	load();
}


void MedienverwaltungClass::load() {
	ifstream f("medien.csv");
	if (!f) throw runtime_error("isSignatureInFile: medien.csv missing");
	string line;
	while (getline(f, line)) {
		vector<string> items = util::tokenize(line, ';');
		if (items.size() != 6) throw runtime_error("Invalid file format.");
		Medium m(items[0], items[1], items[2],
				util::toVal<char>(items[3]),
				util::toVal<int>(items[4]),
				util::toVal<int>(items[5]));
		this->data[items[0]] = m;
	}
}
void MedienverwaltungClass::show() {
	for (std::map<std::string, Medium>::iterator i = data.begin();
		i != data.end(); i++) {
		cout << i->first << " : " << i->second << endl;
	}
	cout << "-------------"  << endl;
}
bool MedienverwaltungClass::checkDuplicate(const std::string& sig){
	return data.count(sig) == 1;
}
int MedienverwaltungClass::addMedium(const Medium& m) {
	if (this->checkDuplicate(m.getSignatur())) return 1;
	ofstream f("medien.csv", ios::app);
	f << m << endl;
	load();
	return 0;

}

