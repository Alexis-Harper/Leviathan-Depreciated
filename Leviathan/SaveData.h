#pragma once

#ifndef SAVE_DATA_H
#define SAVE_DATA_H

#include <sys/stat.h>
#include <fstream>

#include "Arena.h"
#include "Player.h"

#include "rapidxml.hpp"

#define FILENAME "assets/save/file.xml"

using namespace rapidxml;
using namespace std;

class SaveData {

public:

	SaveData();
	~SaveData();

	void saveData();

	void loadArena(Arena*);
	void loadPlayer(Player*);

private:

	ifstream theFile;

	xml_document<> save_file;
	xml_node<> *save_file_node;

} saveObject;

#endif
