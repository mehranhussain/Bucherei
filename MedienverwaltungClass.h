#pragma once
#include "pch.h"
#include "Medium.h"
#include "MediumHira.h"

#include <map>
#include <memory>
#include <string>
#include <unordered_map>

class MedienverwaltungClass
{
private:

	std::map<std::string, Medium> data;

	void load();
public:
	MedienverwaltungClass();

	void show();
	bool checkDuplicate(const std::string& sig);

	int addMedium(const Medium&);
};

