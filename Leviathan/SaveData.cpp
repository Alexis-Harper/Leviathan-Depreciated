#include "stdafx.h"
#include "SaveData.h"

using namespace rapidxml;
using namespace std;

#define FILENAME "assets/save/file.xml"

namespace SaveData {

	namespace {

		//File IO objects
		ifstream readFile;
		ofstream writeFile;

		//XML data
		xml_document<> save_file;
		xml_node<> *save_file_node;

	};

	void setup () {
	
		struct stat buf;

		if (stat(FILENAME, &buf) == -1) {

			//Create file

			//Node declaration
			xml_node<> *declaration_node = save_file.allocate_node(node_declaration); //Create node
			declaration_node->append_attribute(save_file.allocate_attribute("version", "1.0")); //Specify version

			save_file.append_node(declaration_node); //Put node in document

			//Save file node
			save_file_node = save_file.allocate_node(node_element, "SaveFile"); //Create node
			save_file.append_node(save_file_node); //Put node in document

			//Arena node
			xml_node<> *arena_node = save_file.allocate_node(node_element, "Arena");

			save_file_node->append_node(arena_node); //Put node in document

			//Write to file
			writeFile = ofstream(FILENAME); //Open write file
			writeFile << save_file; //Save XML to file

			ifstream theFile = ifstream(FILENAME); //Open read file for future use

		} else {

			readFile = ifstream(FILENAME); //Open read file

			//Create file buffer
			vector<char> buffer((istreambuf_iterator<char>(readFile)), istreambuf_iterator<char>()); //Create buffer
			buffer.push_back('\0'); //Null terminate buffer

			save_file.parse<0>(&buffer[0]); //Parse buffer as XML

			save_file_node = save_file.first_node("SaveFile"); //Root node

			writeFile = ofstream(FILENAME); //Open write file for future use

		}
	
	}
	
	void saveData(string arena, Player player) {

		//Set arena data
		xml_node<> *arena_node = save_file_node->first_node("Arena"); //Arena node

		xml_node<> *area_file_node = arena_node->first_node("Area"); //Area file data node

		const char* arenaString = arena.c_str(); //Convert string to c_str

		area_file_node->first_attribute("file")->value(arenaString); //Set arena string to the current arena

		xml_node<> *player_node = save_file_node->first_node("Player"); //Player node

		xml_node<> *stats_node = player_node->first_node("Stats"); //Player stats node

		//Initialize strings so that RapixXML will work
		char* hpString = save_file.allocate_string(to_string(player.getHp()).c_str());
		char* hpMaxString = save_file.allocate_string(to_string(player.getHpMax()).c_str());
		char* ammoString = save_file.allocate_string(to_string(player.getAmmo()).c_str());
		char* ammoMaxString = save_file.allocate_string(to_string(player.getAmmoMax()).c_str());
		char* attackString = save_file.allocate_string(to_string(player.getAttack()).c_str());
		char* rangeString = save_file.allocate_string(to_string(player.getRange()).c_str());
		char* defenceString = save_file.allocate_string(to_string(player.getDefence()).c_str());
		char* speedString = save_file.allocate_string(to_string(player.getSpeed()).c_str());

		//Set all XML stats
		stats_node->first_attribute("hp")->value(hpString);
		stats_node->first_attribute("hp_max")->value();
		stats_node->first_attribute("ammo")->value();
		stats_node->first_attribute("ammo_max")->value();
		stats_node->first_attribute("attack")->value();
		stats_node->first_attribute("range")->value();
		stats_node->first_attribute("defence")->value();
		stats_node->first_attribute("speed")->value();

		xml_node<> *position_node = player_node->first_node("Position"); //Player position node

		//Initialize strings so that RapixXML will work
		char* xString = save_file.allocate_string(to_string(player.getX()).c_str());
		char* yString = save_file.allocate_string(to_string(player.getY()).c_str());

		//Get all positions from XML
		position_node->first_attribute("x")->value(xString);
		position_node->first_attribute("y")->value(yString);

	}

	void loadArena(Arena* arenaPointer) {

		xml_node<> *arena_node = save_file_node->first_node("Arena"); //Arena node

		xml_node<> *area_file_node = arena_node->first_node("Area"); //Area file data node

		arenaPointer = new Arena(area_file_node->first_attribute("file")->value()); //Set arenaPointer to Arena with Area file data

	}

	void loadPlayer(Player* playerPointer) {

		xml_node<> *player_node = save_file_node->first_node("Player"); //Player node

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
};
