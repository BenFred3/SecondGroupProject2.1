#include "Game.h"

// Constructors.
Game::Game()
{
	vector<string> categoryNameVector;
	vector<Quest> questVector;
}
Game::~Game()
{

}

// Getters.
vector<string> Game::getCategoryNameVector() const
{
	return this->categoryNameVector;
}
vector<Quest> Game::getQuestVector() const
{
	return this->questVector;
}
string Game::getGameName() const
{
	return this->gameName;
}

// Setters.
void Game::setCategoryNameVector(vector<string> cNVector)
{
	this->categoryNameVector = cNVector;
}
void Game::setQuestVector(vector<Quest> qVector)
{
	this->questVector = qVector;
}
void Game::setGameName(string gName)
{
	this->gameName = gName;
}
