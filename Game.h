#pragma once
#include <vector>
#include <string>
#include "Quest.h"
using namespace std;

class Game
{
private:
	// Fields.
	vector<string> categoryNameVector;
	vector<Quest> questVector;
	string gameName;

public:
	// Constructors.
	Game();
	~Game();

	// Getters.
	vector<string> getCategoryNameVector() const;
	vector<Quest> getQuestVector() const;
	string getGameName() const;

	// Setters.
	void setCategoryNameVector(vector<string> cNVector);
	void setQuestVector(vector<Quest> qVector);
	void setGameName(string gName);
};

