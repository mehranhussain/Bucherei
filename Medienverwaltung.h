#pragma once
#include "pch.h"
#include "Medium.h"
#include "MediumHira.h"
#include <string>

namespace Medienverwaltung {

	const int RC_OK = 0;
	const int RC_DUPLIKAT = 1;

	using namespace std;
	int addMedium(const string& signatur, const string& autor, const string& titel, char typ, int seitenzahl, int spieldauer);

	int addMedium(const Medium& medium);
	int addMedium(const MediumBase& medium);
	int addMedium1(const Medium& medium);

	bool isSignatureInFile(const string& sig);
	bool isSignatureInFile(const Medium& m);
}