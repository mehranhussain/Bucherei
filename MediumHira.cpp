/*
 * MediumBase.cpp
 *
 *  Created on: 08.03.2017
 *      Author: CPP
 */
#include "pch.h"
#include "MediumHira.h"

#include <memory>
#include <string>
#include <sstream>
#include <stdexcept>

using namespace std;

std::string MediumBase::formatBase() const {
	std::ostringstream ret;

	ret << signatur << SEP << autor << SEP << titel;

	return ret.str();
}
/*
std::string MediumBase::format() const {
	return this->signatur+";A;T;X;0;0";
};
*/
std::string MediumBase::getSignatur() const{
	return this->signatur;
}

std::string Buch::format() const {
	std::ostringstream ret;

	ret << MediumBase::formatBase() << SEP
			<< 'B' << SEP << seitenzahl << SEP << 0;

	return ret.str();
}

std::string CD::format() const {
	std::ostringstream ret;

	ret << signatur << SEP << autor << SEP << titel << SEP
			<< 'C' << SEP << 0 << SEP << spieldauer;

	return ret.str();
}

MediumBase* MediumBase::createMedium(
		const std::string& signatur,
		const std::string& autor,
		const std::string& titel,
		char typ, int seitenzahl, int spieldauer) {
	unique_ptr<MediumBase> mbp;
	switch (typ) {
	case 'B':
		mbp = make_unique<Buch>(
				signatur, autor, titel, seitenzahl);
		break;
	case 'C':
		mbp = make_unique<CD>(
				signatur, autor, titel, spieldauer);
		break;
	default:
		throw runtime_error("Invalid media type: "+typ);
	}
	return mbp.release();
}

