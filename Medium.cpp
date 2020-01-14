#include "pch.h"
#include "Medium.h"
#include "util.h"

#include <iostream>
#include <memory>
#include <vector>

using namespace std;

Medium::~Medium() {
//	cout << "Deleting instance at " << this << endl;
}

std::string Medium::getSignatur() const {
	return this->signatur;
}

std::string Medium::getAutor() const {
	return this->autor;
}

std::string Medium::getTitel() const {
	return this->titel;
}

char Medium::getTyp() const {
	return this->typ;
}

int Medium::getSeitenzahl() const {
	return this->seitenzahl;
}

int Medium::getSpieldauer() const {
	return this->spieldauer;
}

void Medium::print() const {
	cout << "Instanz von Medium:" << endl;
	cout << "Signatur: " << this->signatur << endl;
	cout << "A/T: " << this->autor << " / " << this->titel << endl;
	cout << "Adresse: " << this << endl;
}

Medium* Medium::createMedium() {
	unique_ptr<Medium> upm(new Medium);
	upm->print();
	Medium* jamp = upm.release();
	return jamp;
}

bool Medium::operator==(const Medium& m) const{
	return this->signatur == m.signatur;
}

ostream& operator<< (ostream& f, const Medium& m) {
	f << m.getSignatur() << ";" << m.autor << ";" << m.titel << ";" << m.typ << ";" << m.seitenzahl << ";" << m.spieldauer;
	return f;
}

istream& operator>> (istream& is, Medium& m) {
	/*
	string line;
	getline(is, line);
	vector<string> items = util::tokenize(line, ';');
	if (items.size() != 6) throw runtime_error("Invalid file format.");

	m.signatur = items[0];
	m.autor = items[1];
	m.titel = items[2];
	m.typ = util::toChar(items[3]);
	m.seitenzahl = util::toInt(items[4]);
	m.spieldauer = util::toInt(items[5]);
	*/
	char dummy;
	string sdummy;
	getline(is, m.signatur, ';');
	getline(is, m.autor, ';');
	getline(is, m.titel, ';');
	is >> m.typ;
	is >> dummy;
	is >> m.seitenzahl;
	is >> dummy;
	is >> m.spieldauer;
	if (is.fail()) throw runtime_error("Invalid file format.");
	getline(is, sdummy);

	return is;
}

