#include "stdafx.h"
#include "Arena.h"

#include "Audio.h"

Arena::Arena() {

	//IDK what to do

}

Arena::Arena(char* fileDir) {

	xml_document<> doc; //Full document

	xml_node<> *musicNode; //Two nodes
	xml_node<> *arenaNode;

	ifstream theFile (fileDir); //Load file

	//Create file buffer
	vector<char> buffer((istreambuf_iterator<char>(theFile)), istreambuf_iterator<char>());
	buffer.push_back('\0');

	doc.parse<0>(&buffer[0]); //Parse buffer as XML

	//Parse music data
	musicNode = doc.first_node("Music");
	
	//Set music data
	audioObject.changeMusic(musicNode->first_attribute("dir")->value());
	audioObject.setRepeatMusic(musicNode->first_attribute("repeat")->value());

	arenaNode = doc.first_node("Arena");
	//Upwards walls nodes
	xml_node<> *up_node = arenaNode->first_node("UpWalls");

	for (xml_node<> *up_child_node = up_node->first_node("Wall"); up_child_node; up_child_node = up_child_node->next_sibling()) {

		this->arenaUp.push_back(Rectangle(stof(up_child_node->first_attribute("x")->value()), stof(up_child_node->first_attribute("y")->value()), stof(up_child_node->first_attribute("size")->value()), 0.0f));

	}

	//Rightwards wall nodes
	xml_node<> *right_node = arenaNode->first_node("RightWalls");

	for (xml_node<> *right_child_node = right_node->first_node("Wall"); right_child_node; right_child_node = right_child_node->next_sibling()) {

		this->arenaRight.push_back(Rectangle(stof(right_child_node->first_attribute("x")->value()), stof(right_child_node->first_attribute("y")->value()), 0.0f, stof(right_child_node->first_attribute("size")->value())));

	}

	//Downwards walls nodes
	xml_node<> *down_node = arenaNode->first_node("DownWalls");

	for (xml_node<> *down_child_node = down_node->first_node("Wall"); down_child_node; down_child_node = down_child_node->next_sibling()) {

		this->arenaDown.push_back(Rectangle(stof(down_child_node->first_attribute("x")->value()), stof(down_child_node->first_attribute("y")->value()), stof(down_child_node->first_attribute("size")->value()), 0.0f));

	}

	//Upwards walls nodes
	xml_node<> *left_node = arenaNode->first_node("LeftWalls");

	for (xml_node<> *left_child_node = up_node->first_node("Wall"); left_child_node; left_child_node = left_child_node->next_sibling()) {

		this->arenaLeft.push_back(Rectangle(stof(left_child_node->first_attribute("x")->value()), stof(left_child_node->first_attribute("y")->value()), 0.0f, stof(left_child_node->first_attribute("size")->value())));

	}

	this->location = fileDir;

}

Arena::~Arena() {

	arenaUp.clear();
	arenaRight.clear();
	arenaDown.clear();
	arenaLeft.clear();

	gameObjects.clear();

}

string Arena::getLocation() {

	return this->location;

}
