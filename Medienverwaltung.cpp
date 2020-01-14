#include "pch.h"
#include "Medienverwaltung.h"
#include "util.h"

#include <fstream>
#include <stdexcept>
#include <vector>

using namespace std;

int Medienverwaltung::addMedium(const std::string& signatur, const string& autor, const string& titel, char typ, int seitenzahl, int spieldauer) {
	//if (isSignatureInFile(signatur)) return RC_DUPLIKAT;
	ofstream f("medien.csv", ios::app);
	f << signatur << ";" << autor << ";" << titel << ";" << typ << ";" << seitenzahl << ";" << spieldauer << endl;
	return RC_OK;
}
















bool Medienverwaltung::isSignatureInFile(const string& sig) {
	ifstream f("medien.csv");
	if (!f) throw runtime_error("isSignatureInFile: medien.csv missing");
	string line;
	while (getline(f, line)) {
		vector<string> items = util::tokenize(line, ';');
		if (items.size() != 6) throw runtime_error("Invalid file format.");
		if (items[0] == sig) return true;
	}
	return false;
}
bool Medienverwaltung::isSignatureInFile(const Medium& m) {
	ifstream f("medien.csv");
	if (!f) throw runtime_error("isSignatureInFile: medien.csv missing");
	string line;
	Medium m1;
	/*
	// read ahead
	f >> m1;
	while (f.good()) {

		// data processing
		if (m == m1) return true;

		// read again
		f >> m1;
	}
	*/
	
	stringstream ms;
	while (getline(f, line)) {
		if (line.length() > 0 && line[0] != '#') {
			ms.clear();
			ms << line;
			ms >> m1;
			if (m == m1) return true;
		}
	}
	
	return false;
}






int Medienverwaltung::addMedium(const Medium& medium) {

	return Medienverwaltung::addMedium(medium.getSignatur(), medium.getAutor(), medium.getTitel(),
		medium.getTyp(), medium.getSeitenzahl(), medium.getSpieldauer());
}







int Medienverwaltung::addMedium(const MediumBase& medium) {
	//if (isSignatureInFile(medium.getSignatur())) return RC_DUPLIKAT;
	ofstream of("medien.csv", ios::app);
	of << medium.format() << endl;
	return RC_OK;
}






int Medienverwaltung::addMedium1(const Medium& medium) {
	if (isSignatureInFile(medium)) return RC_DUPLIKAT;

	ofstream of("medien.csv", ios::app);
	of << medium << endl;
	return RC_OK;
}
