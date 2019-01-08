#include "Quest.h"

// Constructors.
Quest::Quest()
{
	vector<string> stepVector;
	vector<string> additionalStepsVector;
	vector<string> hintVector;
}
Quest::~Quest()
{

}

// Getters.
vector<string> Quest::getStepVector() const
{
	return this->stepVector;
}
vector<string> Quest::getAdditionalStepsVector() const
{
	return this->additionalStepsVector;
}
vector<string> Quest::getHintVector() const
{
	return this->hintVector;
}
string Quest::getQuestName() const
{
	return this->questName;
}
string Quest::getQuestDescription() const
{
	return this->questDescription;
}

// Setters.
void Quest::setStepVector(vector<string> sVector)
{
	this->stepVector = sVector;
}
void Quest::setAdditionalStepsVector(vector<string> addSVector)
{
	this->additionalStepsVector = addSVector;
}
void Quest::setHintVector(vector<string> hVector)
{
	this->hintVector = hVector;
}
void Quest::setQuestName(string qName)
{
	this->questName = qName;
}
void Quest::setQuestDescription(string qDesc)
{
	this->questDescription = qDesc;
}