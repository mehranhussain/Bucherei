/*
 * util.h
 *
 *  Created on: 06.03.2017
 *      Author: gnublin
 */

#ifndef UTIL_H_
#define UTIL_H_

#include<sstream>
#include<string>
#include<vector>

namespace util {

std::vector<std::string> tokenize(const std::string&, char);

std::vector<std::string> tokenize(std::stringstream&, char);

char toChar(const std::string&);

int toInt(const std::string&);

template <typename T>
T toVal(const std::string& str) {
	std::stringstream  strin;
	T var;

	strin << str;
	strin >> var;

	return var;
}
template <>
std::string toVal<std::string>(const std::string& str);

template<typename T>
bool split(std::istream& ss, char t, T& elem) {
	std::string item;
	bool ok = getline(ss, item);
	elem = toVal<T> (item);
	return ok;
}

template<typename T, typename ... P>
bool split(std::istream& ss, char t, T& elem, P& ... pack) {
	std::string item;
	bool ok = getline(ss, item, t);
	elem = toVal<T> (item);
	if (ok) ok = split(ss, t, pack...);
	return ok;
}

/*
 * Aufruf:
	// read ahead
	bool ok = util::split(infile, ';', signatur, autor, titel, typ, seitenzahl, spieldauer);
	while (ok) {
		Medium m(signatur, autor, titel, typ, seitenzahl, spieldauer);
		cout << m << endl;
		ok = util::split(infile, ';', signatur, autor, titel, typ, seitenzahl, spieldauer);
	}
	cout << "test_variadic end." << endl;

 */


} // namespace util

#endif /* UTIL_H_ */
