#ifndef MEDIUMBASE_H_
#define MEDIUMBASE_H_

#include "pch.h"
#include <string>

struct MediumBase {

public:
	MediumBase(std::string signatur, std::string autor, std::string titel)
			: signatur(signatur),
			  autor(autor),
			  titel(titel) {}
	MediumBase() = default;


	static const char SEP = ';';

	virtual std::string format() const = 0;
	std::string formatBase() const;


	std::string getSignatur() const;

	static MediumBase* createMedium(
			const std::string& signatur,
			const std::string& autor,
			const std::string& titel,
			char typ, int seitenzahl, int spieldauer);

protected:
	std::string signatur = "ABC00";
	std::string autor = "John Smith";
	std::string titel = "Foo";

};

class Buch : public MediumBase {

public:
	Buch(std::string signatur, std::string autor, std::string titel, int seitenzahl)
		: MediumBase{signatur, autor, titel}, seitenzahl{seitenzahl} {}
	Buch() = default;

	virtual std::string format() const;

protected:
	int seitenzahl = 78;
};

class CD : public MediumBase {

public:
	CD(std::string signatur, std::string autor, std::string titel, int spieldauer)
		: MediumBase{signatur, autor, titel}, spieldauer{spieldauer} {}
	CD() = default;

	virtual std::string format() const;

protected:
	int spieldauer = 45;
};


#endif /* MEDIUMBASE_H_ */
