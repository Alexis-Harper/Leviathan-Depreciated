#pragma once

#ifndef SAVE_DATA_H
#define SAVE_DATA_H

#include <sys/stat.h>
#include <fstream>

#include "Arena.h"
#include "Player.h"

#include "rapidxml.hpp"
#include "rapidxml_print.hpp"

namespace SaveData {

	void setup();

	void saveData(std::string, Player); //Save all data

	void loadArena(Arena*); //Load save data
	void loadPlayer(Player*);

};

/*class SaveData {

public:

	SaveData();
	~SaveData();

	void saveData(string, Player); //Save all data

	void loadArena(Arena*); //Load save data
	void loadPlayer(Player*);

private:

	//File IO objects
	ifstream readFile;
	ofstream writeFile;

	//XML data
	xml_document<> save_file;
	xml_node<> *save_file_node;

} saveObject;*/

#endif
