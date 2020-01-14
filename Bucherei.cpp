#include "pch.h"
#include "Medienverwaltung.h"
#include "MedienverwaltungClass.h"
#include "Medium.h"
#include "MediumHira.h"

#include <iostream>
#include <memory>
#include <sstream>
#include <string>

using namespace Medienverwaltung;
using namespace std;

int main() {
try {
		MedienverwaltungClass mvc;
		mvc.show();
		cout << mvc.checkDuplicate("A001") << endl;
		cout << mvc.checkDuplicate("XXXX") << endl;
		Medium m4("S5", "A4", "T2", 'B', 234, 0);
		int rc = mvc.addMedium(m4);
		cout << "rc= " << rc << endl;
	
		rc = addMedium1(m4);
		cout << "rc= " << rc << endl;

		unique_ptr<MediumBase> map(MediumBase::createMedium("F33", "Goethe", "Faust", 'B', 345, 0));
		rc = addMedium(*map);
		cout << "rc= " << rc << endl;

		map.reset(MediumBase::createMedium("B68", "Beatles", "Let it be", 'C', 0, 3));
		rc = addMedium(*map);
		cout << "rc= " << rc << endl;

		Medium m{"S3","A3","T3",'C',0,45};
		//m.print();
		rc = addMedium(m);
		cout << "rc= " << rc << endl;

		Medium m1;
		if (m == m1) cout << "sind gleich" << endl;
		cout << m << endl;
		m1.print();
		rc = addMedium(m1);
		cout << "rc= " << rc << endl;

		rc = addMedium("A02", "Goethe", "Faust", 'B', 123, 0);
		if (rc == RC_OK) {
			cout << "Datensatz angelegt." << endl;
		}
		else {
			cout << "Fehler: " << rc << endl;
		}
	}
	catch (exception& e)
	{
		cerr << "Exception: " << e.what() << endl;
	}
} 
