#pragma once
#include <vector>
#include <string>
using namespace std;

class Quest
{
protected:
	// Fields.
	vector<string> stepVector;
	vector<string> additionalStepsVector;
	vector<string> hintVector;
	string questName;
	string questDescription;

public:
	// Constructors.
	Quest();
	~Quest();

	// Getters.
	vector<string> getStepVector() const;
	vector<string> getAdditionalStepsVector() const;
	vector<string> getHintVector() const;
	string getQuestName() const;
	string getQuestDescription() const;

	// Setters.
	void setStepVector(vector<string> sVector);
	void setAdditionalStepsVector(vector<string> addSVector);
	void setHintVector(vector<string> hVector);
	void setQuestName(string qName);
	void setQuestDescription(string qDesc);
};

