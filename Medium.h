#pragma once
#include "pch.h"
#include <iostream>
#include <string>
/*
template <typename T>
struct counter {
	static int objects_created;
	static int objects_alive;

	counter() {
		++objects_alive;
		++objects_created;
		//std::cout << "created: " <<  objects_created << " ; alive: " << objects_alive << std::endl;
	}

	counter(const counter&) {
		++objects_alive;
		++objects_created;
		//std::cout << "created: " <<  objects_created << " ; alive: " << objects_alive << std::endl;
	}
protected:
	~counter() {
		--objects_alive;
		//std::cout << "created: " <<  objects_created << " ; alive: " << objects_alive << std::endl;
	}
};
template <typename T> int counter<T>::objects_created = 0;
template <typename T> int counter<T>::objects_alive = 0;
*/
struct Medium //: public counter<Medium>
{
private:
	std::string signatur;
	std::string autor = "John Smith";
	std::string titel = "Foo";
	char typ = 'B';
	int seitenzahl = 120;
	int spieldauer = 0;

public:
	
	Medium() = default;
	Medium(std::string signatur, std::string autor, std::string titel,
		char typ, int seitenzahl, int spieldauer)
		: signatur(signatur),
		autor(autor),
		titel(titel),
		typ(typ),
		seitenzahl(seitenzahl),
		spieldauer(spieldauer) {}
	~Medium();

	static Medium* createMedium();

	std::string getSignatur() const;
	std::string getAutor() const;
	std::string getTitel() const;
	char getTyp() const;
	int getSeitenzahl() const;
	int getSpieldauer() const;

	void setAutor(const std::string& a) { this->autor = a; }

	void print() const;

	friend std::ostream& operator<< (std::ostream&, const Medium&);
	friend std::istream& operator>> (std::istream&, Medium&);

	bool operator==(const Medium&) const;

};

std::ostream& operator<< (std::ostream&, const Medium&);

//namespace std {
//  template<>
//    struct hash<Medium>
//    : public __hash_base<size_t, Medium>
//    {
//      size_t
//      operator()(const Medium& __m) const noexcept
//      { //return std::_Hash_impl::hash(__m.getSignatur().data(), __m.getSignatur().length()); }
//    	//  return __m.getSignatur().size();
//    	  return 1;
//      }
//    };
//}
//
