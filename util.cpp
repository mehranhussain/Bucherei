/*
 * util.cpp
 *
 *  Created on: 06.03.2017
 *      Author: gnublin
 */
#include "pch.h"
#include "util.h"

using namespace std;

vector<string> util::tokenize(const string& line, char c) {
	stringstream ss;
	//ss.str(line);
	ss << line;
	return tokenize(ss, c);
}

vector<string> util::tokenize(stringstream& ss, char token) {
	string item;
	vector<string> elems;
	while (getline(ss, item, token)) {
		elems.push_back(item);
	}
	return elems;
}

char util::toChar(const string& str) {
	std::stringstream  strin;
	char var;

	strin << str;
	strin >> var;

	return var;
}

int util::toInt(const string& str) {
	std::stringstream  strin;
	int var;

	strin << str;
	strin >> var;

	return var;
}
template<>
std::string util::toVal<std::string>(const std::string& str) {
	return str;
}
