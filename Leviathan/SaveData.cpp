#include "stdafx.h"
#include "SaveData.h"

SaveData::SaveData() {

	struct stat buf;

	if (stat(FILENAME, &buf) == -1) {

		//Create file

	} else {

		ifstream theFile = ifstream(FILENAME);

		//Create file buffer
		vector<char> buffer((istreambuf_iterator<char>(this->theFile)), istreambuf_iterator<char>());
		buffer.push_back('\0');

		this->save_file.parse<0>(&buffer[0]); //Parse buffer as XML

		this->save_file_node = this->save_file.first_node("SaveFile"); //Root node

	}

}

SaveData::~SaveData() {

	//Nothing yet

}

void SaveData::saveData() {



}

void SaveData::loadArena(Arena* arenaPointer) {

	xml_node<> *arena_node = this->save_file_node->first_node("Arena"); //Arena node

	xml_node<> *area_file_node = arena_node->first_node("Area"); //Area file data node

	arenaPointer = new Arena(area_file_node->first_attribute("file")->value()); //Set arenaPointer to Arena with Area file data

}

void SaveData::loadPlayer(Player* playerPointer) {

	xml_node<> *player_node = this->save_file_node->first_node("Player"); //Player node

	xml_node<> *stats_node = player_node->first_node("Stats"); //Player stats node

	//Get all stats from XML
	int hp = stoi(stats_node->first_attribute("hp")->value());
	int hpMax = stoi(stats_node->first_attribute("hp_max")->value());
	int ammo = stoi(stats_node->first_attribute("ammo")->value());
	int ammoMax = stoi(stats_node->first_attribute("ammo_max")->value());
	int attack = stoi(stats_node->first_attribute("attack")->value());
	int range = stoi(stats_node->first_attribute("range")->value());
	int defence = stoi(stats_node->first_attribute("defence")->value());
	int speed = stoi(stats_node->first_attribute("speed")->value());

	playerPointer->setStats(hp, hpMax, ammo, ammoMax, attack, range, defence, speed); //Set stats

	xml_node<> *position_node = player_node->first_node("Position"); //Player position node

	//Get all positions from XML
	float x = stof(position_node->first_attribute("x")->value());
	float y = stof(position_node->first_attribute("y")->value());

	playerPointer->setPosition(x, y); //Set position

}
