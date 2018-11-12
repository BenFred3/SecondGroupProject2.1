// Spoiler-free walkthrough

#include <iostream>
#include <vector>
#include <string>
#include "Game.h"
#include "Quest.h"
#pragma comment(lib, "user32")
using namespace std;

// This function populates all the values in each vector.
void createGame(Game gameArray[1], vector<string> categoryNameVector, vector<Quest> questVector, vector<string> stepVector, vector<string> additionalStepsVector,
	vector<string> hintVector);
// This function gives the category choices.
void categoryChoices(int userCategoryChoice, vector<Quest> questVector);
// This function gives the step choices.
void stepChoices(int userQuestChoice, int STEPS, vector<Quest> questVector, vector<string> stepVector);
// This function gives the hint choices.
void hintChoices(int hintCounter, int hintEnd, int userStepChoice, vector<string> stepVector, vector<string> hintVector);
// This function prints the additional step choices.
int additionalStepPrint(int userStepChoice, int STEPS, vector<string> additionalStepsVector);

//Constants for menu choices
const int MENUCHOICE0 = 0,
MENUCHOICE1 = 1,
MENUCHOICE2 = 2,
MENUCHOICE3 = 3,
MENUCHOICE4 = 4,
MENUCHOICE5 = 5,
MENUCHOICE6 = 6,
MENUCHOICE7 = 7,
MENUCHOICE8 = 8,
MENUCHOICE9 = 9,
MENUCHOICE10 = 10,
MENUCHOICE11 = 11,
MENUCHOICE12 = 12,
MENUCHOICE13 = 13,
MENUCHOICE14 = 14,
MENUCHOICE15 = 15,
MENUCHOICE16 = 16,
MENUCHOICE17 = 17,
MENUCHOICE18 = 18,
MENUCHOICE19 = 19;

int main()
{
	system("mode 650"); // Make the console fullscreen.

	const int DEFAULTVALUE = 400; // Default value for all the vectors.
	const int DEFAULTVALUESTEPS = 91; // Default value for the steps.

									  // Create a gameArray, a categoryNameVector, a questVector, a stepVector, and a hintVecor. Then resize all of them to the default value.
	Game gameArray[1];
	vector<string> categoryNameVector = gameArray[0].getCategoryNameVector();
	categoryNameVector.resize(DEFAULTVALUE);

	vector<Quest> questVector = gameArray[0].getQuestVector();
	questVector.resize(DEFAULTVALUE);

	vector<string> stepVector(DEFAULTVALUESTEPS);
	questVector[0].setStepVector(stepVector);

	vector<string> additionalStepsVector(DEFAULTVALUE);
	questVector[0].setAdditionalStepsVector(additionalStepsVector);

	vector<string> hintVector(DEFAULTVALUE);
	questVector[0].setHintVector(hintVector);

	createGame(gameArray, categoryNameVector, questVector, stepVector, additionalStepsVector, hintVector); // This creates the game Skyrim from the vectors already created.

																										   // Get the vectors from the class.
	categoryNameVector = gameArray[0].getCategoryNameVector();
	questVector = gameArray[0].getQuestVector();
	stepVector = questVector[0].getStepVector();
	additionalStepsVector = questVector[0].getAdditionalStepsVector();
	hintVector = questVector[0].getHintVector();

	int userMenuChoice; // This is the user's input for the main menu.
	int userGameChoice; // This is the user's input for the game choice.
	int userCategoryChoice; // This is the user's input for the category.
	int userQuestChoice; // This is the user's input for the quest.
	int userStepChoice; // This is the user's input for the step.
	int hintCounter = 0; // Counter used for the hint function.
	int hintEnd; // Value used to end the hint function.
	int userAdditionalChoice; // Value used to track the user's additional choice.

							  // Welcome the user to the program and give a short description. 
	cout << "Welcome to the Spoiler-Free Walkthrough Program!\nThis program will allow you to view helpful walkthroughs without ruining your experience.\n";

	do // Do this.
	{
		// Prompt the user to choose one of the menu choices then print out the menu.
		cout << "\n- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -\nPlease choose one of the menu choices to begin the program.. \n\n";
		cout << "1. Choose Game\n2. End Program\n- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - \n";
		cin >> userMenuChoice; // Set the user's input to userMenuChoice.
		cout << "- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -" << endl; // Space for output.

																							   // If the user's choice is equal to one then do this.
		if (userMenuChoice == MENUCHOICE1)
		{
			cout << "Choose a game..\n\n1. " << gameArray[0].getGameName() << endl; // Output the game choices.
			cout << "- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -" << endl; // Space for output.
			cin >> userGameChoice; // Set the user's input to userGameChoice.
			cout << "- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -" << endl; // Space for output.
																								   // If the user chooses game one, then print out the categories for quests.
			if (userGameChoice == MENUCHOICE1)
			{
				cout << gameArray[0].getGameName() << " walkthrough\n"; // Print the game's name and walkthrough for the user.
				cout << "Choose a quest category..\n\n"; // Tell the user to pick a category.

				int categoryValues = 0; // Set a counter value.
				do // Print out each categoryName.
				{
					cout << categoryValues + 1 << ". " << categoryNameVector.at(categoryValues) << endl;
					categoryValues++; // Increase the counter value each loop.
				} while (categoryNameVector.at(categoryValues) != ""); // When the categoryName's value is "" then end the do-while loop.

				cout << "- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -" << endl; // Space for output.
				cin >> userCategoryChoice; // Set user's input to userCategoryChoice
				cout << "- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -" << endl; // Space for output.

				if (userCategoryChoice == 1) // Main Quests
				{
					categoryChoices(userCategoryChoice, questVector); // Get the categories.

					cin >> userQuestChoice; // Set user's input to userQuestChoice.
					cout << "- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -" << endl; // Space for output.

					do
					{
						int STEPS = 0;
						// Switch statement to take the user input and print the appropriate steps.
						switch (userQuestChoice)
						{
						case MENUCHOICE1: // Unbound.
										  // Set the amount of steps, then give the userQuestChoice, STEPS, questVector, and stepVector to the steps function.
							STEPS = 4;
							stepChoices(userQuestChoice, STEPS, questVector, stepVector);

							cin >> userStepChoice; // Set user's input to userStepChoice.

												   // Switch statement to take the user input and print the appropriate hints.
							switch (userStepChoice)
							{
							case MENUCHOICE1: // Make your way to the Keep.
											  // Set the starting hint index, the ending hint index, and call the hint function with all the variables needed.
								hintEnd = 5;
								hintChoices(hintCounter, hintEnd, userStepChoice, stepVector, hintVector);
								break;
							case MENUCHOICE2: // Enter the Keep with Hadvar or Ralof.
											  // Set the starting hint index, the ending hint index, and call the hint function with all the variables needed.
								hintCounter = 5;
								hintEnd = 8;
								hintChoices(hintCounter, hintEnd, userStepChoice, stepVector, hintVector);
								break;
							case MENUCHOICE3: // Objectives for Hadvar's Path.
											  // Set the amount of steps, then give the userQuestChoice, STEPS, and additionalStepsVector to the additional steps function.
								STEPS = 4;
								userAdditionalChoice = additionalStepPrint(userStepChoice, STEPS, additionalStepsVector);

								// Switch statement holding all the additional choices.
								switch (userAdditionalChoice)
								{
								case MENUCHOICE1:
									// Set the starting hint index, the ending hint index, and call the hint function with all the variables needed.
									hintCounter = 8;
									hintEnd = 18;
									hintChoices(hintCounter, hintEnd, userAdditionalChoice, additionalStepsVector, hintVector);
									break;
								case MENUCHOICE2:
									hintCounter = 18;
									hintEnd = 22;
									hintChoices(hintCounter, hintEnd, userAdditionalChoice, additionalStepsVector, hintVector);
									break;
								case MENUCHOICE3:
									hintCounter = 22;
									hintEnd = 25;
									hintChoices(hintCounter, hintEnd, userAdditionalChoice, additionalStepsVector, hintVector);
									break;
								case MENUCHOICE4:
									hintCounter = 25;
									hintEnd = 30;
									hintChoices(hintCounter, hintEnd, userAdditionalChoice, additionalStepsVector, hintVector);
									break;
								}
								break;
							case MENUCHOICE4: // Objectives for Ralof's Path.
											  // Set the amount of steps, then give the userQuestChoice, STEPS, and additionalStepsVector to the additional steps function.
								STEPS = 4;
								userAdditionalChoice = additionalStepPrint(userStepChoice, STEPS, additionalStepsVector);

								// Switch statement holding all the additional choices.
								switch (userAdditionalChoice)
								{
								case MENUCHOICE1:
									// Set the starting hint index, the ending hint index, and call the hint function with all the variables needed.
									hintCounter = 30;
									hintEnd = 41;
									hintChoices(hintCounter, hintEnd, userAdditionalChoice, additionalStepsVector, hintVector);
									break;
								case MENUCHOICE2:
									hintCounter = 41;
									hintEnd = 42;
									hintChoices(hintCounter, hintEnd, userAdditionalChoice, additionalStepsVector, hintVector);
									break;
								case MENUCHOICE3:
									hintCounter = 42;
									hintEnd = 45;
									hintChoices(hintCounter, hintEnd, userAdditionalChoice, additionalStepsVector, hintVector);
									break;
								case MENUCHOICE4:
									hintCounter = 45;
									hintEnd = 50;
									hintChoices(hintCounter, hintEnd, userAdditionalChoice, additionalStepsVector, hintVector);
									break;
								}
								break;
							}
						case MENUCHOICE2: // Before the Storm.
										  // Set the amount of steps, then give the userQuestChoice, STEPS, questVector, and stepVector to the steps function.
							STEPS = 3;
							stepChoices(userQuestChoice, STEPS, questVector, stepVector);

							cin >> userStepChoice; // Set user's input to userStepChoice.
												   // Switch statement to take the user input and print the appropriate hints.
							switch (userStepChoice)
							{
							case MENUCHOICE1:
								// Set the starting hint index, the ending hint index, and call the hint function with all the variables needed.
								hintCounter = 50;
								hintEnd = 54;
								hintChoices(hintCounter, hintEnd, userStepChoice, stepVector, hintVector);
								break;
							case MENUCHOICE2:
								// Set the starting hint index, the ending hint index, and call the hint function with all the variables needed.
								hintCounter = 54;
								hintEnd = 58;
								hintChoices(hintCounter, hintEnd, userStepChoice, stepVector, hintVector);
								break;
							case MENUCHOICE3:
								// Set the starting hint index, the ending hint index, and call the hint function with all the variables needed.
								hintCounter = 58;
								hintEnd = 67;
								hintChoices(hintCounter, hintEnd, userStepChoice, stepVector, hintVector);
								break;
							}
						case MENUCHOICE3: // Bleak Falls Barrow.
										  // Set the amount of steps, then give the userQuestChoice, STEPS, questVector, and stepVector to the steps function.
							STEPS = 3;
							stepChoices(userQuestChoice, STEPS, questVector, stepVector);

							cin >> userStepChoice; // Set user's input to userStepChoice.
												   // Switch statement to take the user input and print the appropriate hints.
							switch (userStepChoice)
							{
							case MENUCHOICE1:
								// Set the starting hint index, the ending hint index, and call the hint function with all the variables needed.
								hintCounter = 67;
								hintEnd = 69;
								hintChoices(hintCounter, hintEnd, userStepChoice, stepVector, hintVector);
								break;
							case MENUCHOICE2:
								// Set the starting hint index, the ending hint index, and call the hint function with all the variables needed.
								hintCounter = 69;
								hintEnd = 74;
								hintChoices(hintCounter, hintEnd, userStepChoice, stepVector, hintVector);
								break;
							case MENUCHOICE3:
								// Set the starting hint index, the ending hint index, and call the hint function with all the variables needed.
								hintCounter = 74;
								hintEnd = 79;
								hintChoices(hintCounter, hintEnd, userStepChoice, stepVector, hintVector);
								break;
							}
						case MENUCHOICE4: // Dragon Rising.
										  // Set the amount of steps, then give the userQuestChoice, STEPS, questVector, and stepVector to the steps function.
							STEPS = 6;
							stepChoices(userQuestChoice, STEPS, questVector, stepVector);

							cin >> userStepChoice; // Set user's input to userStepChoice.
												   // Switch statement to take the user input and print the appropriate hints.
							switch (userStepChoice)
							{
							case MENUCHOICE1:
								// Set the starting hint index, the ending hint index, and call the hint function with all the variables needed.
								hintCounter = 79;
								hintEnd = 82;
								hintChoices(hintCounter, hintEnd, userStepChoice, stepVector, hintVector);
								break;
							case MENUCHOICE2:
								// Set the starting hint index, the ending hint index, and call the hint function with all the variables needed.
								hintCounter = 82;
								hintEnd = 85;
								hintChoices(hintCounter, hintEnd, userStepChoice, stepVector, hintVector);
								break;
							case MENUCHOICE3:
								// Set the starting hint index, the ending hint index, and call the hint function with all the variables needed.
								hintCounter = 85;
								hintEnd = 88;
								hintChoices(hintCounter, hintEnd, userStepChoice, stepVector, hintVector);
								break;
							case MENUCHOICE4:
								// Set the starting hint index, the ending hint index, and call the hint function with all the variables needed.
								hintCounter = 88;
								hintEnd = 89;
								hintChoices(hintCounter, hintEnd, userStepChoice, stepVector, hintVector);
								break;
							case MENUCHOICE5:
								// Set the starting hint index, the ending hint index, and call the hint function with all the variables needed.
								hintCounter = 89;
								hintEnd = 91;
								hintChoices(hintCounter, hintEnd, userStepChoice, stepVector, hintVector);
								break;
							case MENUCHOICE6:
								// Set the starting hint index, the ending hint index, and call the hint function with all the variables needed.
								hintCounter = 91;
								hintEnd = 94;
								hintChoices(hintCounter, hintEnd, userStepChoice, stepVector, hintVector);
								break;
							}
						case MENUCHOICE5: // The Way of the Voice.
										  // Set the amount of steps, then give the userQuestChoice, STEPS, questVector, and stepVector to the steps function.
							STEPS = 8;
							stepChoices(userQuestChoice, STEPS, questVector, stepVector);

							cin >> userStepChoice; // Set user's input to userStepChoice.
												   // Switch statement to take the user input and print the appropriate hints.
							switch (userStepChoice)
							{
							case MENUCHOICE1:
								// Set the starting hint index, the ending hint index, and call the hint function with all the variables needed.
								hintCounter = 94;
								hintEnd = 102;
								hintChoices(hintCounter, hintEnd, userStepChoice, stepVector, hintVector);
								break;
							case MENUCHOICE2:
								// Set the starting hint index, the ending hint index, and call the hint function with all the variables needed.
								hintCounter = 102;
								hintEnd = 103;
								hintChoices(hintCounter, hintEnd, userStepChoice, stepVector, hintVector);
								break;
							case MENUCHOICE3:
								// Set the starting hint index, the ending hint index, and call the hint function with all the variables needed.
								hintCounter = 103;
								hintEnd = 105;
								hintChoices(hintCounter, hintEnd, userStepChoice, stepVector, hintVector);
								break;
							case MENUCHOICE4:
								// Set the starting hint index, the ending hint index, and call the hint function with all the variables needed.
								hintCounter = 105;
								hintEnd = 107;
								hintChoices(hintCounter, hintEnd, userStepChoice, stepVector, hintVector);
								break;
							case MENUCHOICE5:
								// Set the starting hint index, the ending hint index, and call the hint function with all the variables needed.
								hintCounter = 107;
								hintEnd = 110;
								hintChoices(hintCounter, hintEnd, userStepChoice, stepVector, hintVector);
								break;
							case MENUCHOICE6:
								// Set the starting hint index, the ending hint index, and call the hint function with all the variables needed.
								hintCounter = 110;
								hintEnd = 112;
								hintChoices(hintCounter, hintEnd, userStepChoice, stepVector, hintVector);
								break;
							case MENUCHOICE7:
								// Set the starting hint index, the ending hint index, and call the hint function with all the variables needed.
								hintCounter = 112;
								hintEnd = 115;
								hintChoices(hintCounter, hintEnd, userStepChoice, stepVector, hintVector);
								break;
							case MENUCHOICE8:
								// Set the starting hint index, the ending hint index, and call the hint function with all the variables needed.
								hintCounter = 115;
								hintEnd = 116;
								hintChoices(hintCounter, hintEnd, userStepChoice, stepVector, hintVector);
								break;
							}
						case MENUCHOICE6: // The Horn of Jurgen Windcaller.
										  // Set the amount of steps, then give the userQuestChoice, STEPS, questVector, and stepVector to the steps function.
							STEPS = 6;
							stepChoices(userQuestChoice, STEPS, questVector, stepVector);

							cin >> userStepChoice; // Set user's input to userStepChoice.
												   // Switch statement to take the user input and print the appropriate hints.
							switch (userStepChoice)
							{
							case MENUCHOICE1:
								// Set the starting hint index, the ending hint index, and call the hint function with all the variables needed.
								hintCounter = 116;
								hintEnd = 119;
								hintChoices(hintCounter, hintEnd, userStepChoice, stepVector, hintVector);
								break;
							case MENUCHOICE2:
								// Set the starting hint index, the ending hint index, and call the hint function with all the variables needed.
								hintCounter = 119;
								hintEnd = 120;
								hintChoices(hintCounter, hintEnd, userStepChoice, stepVector, hintVector);
								break;
							case MENUCHOICE3:
								// Set the starting hint index, the ending hint index, and call the hint function with all the variables needed.
								hintCounter = 120;
								hintEnd = 126;
								hintChoices(hintCounter, hintEnd, userStepChoice, stepVector, hintVector);
								break;
							case MENUCHOICE4:
								// Set the starting hint index, the ending hint index, and call the hint function with all the variables needed.
								hintCounter = 126;
								hintEnd = 128;
								hintChoices(hintCounter, hintEnd, userStepChoice, stepVector, hintVector);
								break;
							case MENUCHOICE5:
								// Set the starting hint index, the ending hint index, and call the hint function with all the variables needed.
								hintCounter = 128;
								hintEnd = 130;
								hintChoices(hintCounter, hintEnd, userStepChoice, stepVector, hintVector);
								break;
							case MENUCHOICE6:
								// Set the starting hint index, the ending hint index, and call the hint function with all the variables needed.
								hintCounter = 130;
								hintEnd = 132;
								hintChoices(hintCounter, hintEnd, userStepChoice, stepVector, hintVector);
								break;
							}
						case MENUCHOICE7: // A Blade in the Dark.
										  // Set the amount of steps, then give the userQuestChoice, STEPS, questVector, and stepVector to the steps function.
							STEPS = 4;
							stepChoices(userQuestChoice, STEPS, questVector, stepVector);

							cin >> userStepChoice; // Set user's input to userStepChoice.
												   // Switch statement to take the user input and print the appropriate hints.
							switch (userStepChoice)
							{
							case MENUCHOICE1:
								// Set the starting hint index, the ending hint index, and call the hint function with all the variables needed.
								hintCounter = 132;
								hintEnd = 136;
								hintChoices(hintCounter, hintEnd, userStepChoice, stepVector, hintVector);
								break;
							case MENUCHOICE2:
								// Set the starting hint index, the ending hint index, and call the hint function with all the variables needed.
								hintCounter = 136;
								hintEnd = 141;
								hintChoices(hintCounter, hintEnd, userStepChoice, stepVector, hintVector);
								break;
							case MENUCHOICE3:
								// Set the starting hint index, the ending hint index, and call the hint function with all the variables needed.
								hintCounter = 141;
								hintEnd = 145;
								hintChoices(hintCounter, hintEnd, userStepChoice, stepVector, hintVector);
								break;
							case MENUCHOICE4:
								// Set the starting hint index, the ending hint index, and call the hint function with all the variables needed.
								hintCounter = 145;
								hintEnd = 147;
								hintChoices(hintCounter, hintEnd, userStepChoice, stepVector, hintVector);
								break;
							}
						case MENUCHOICE8: // Diplomatic immunity.
										  // Set the amount of steps, then give the userQuestChoice, STEPS, questVector, and stepVector to the steps function.
							STEPS = 10;
							stepChoices(userQuestChoice, STEPS, questVector, stepVector);

							cin >> userStepChoice; // Set user's input to userStepChoice.
												   // Switch statement to take the user input and print the appropriate hints.
							switch (userStepChoice)
							{
							case MENUCHOICE1:
								// Set the starting hint index, the ending hint index, and call the hint function with all the variables needed.
								hintCounter = 147;
								hintEnd = 148;
								hintChoices(hintCounter, hintEnd, userStepChoice, stepVector, hintVector);
								break;
							case MENUCHOICE2:
								// Set the starting hint index, the ending hint index, and call the hint function with all the variables needed.
								hintCounter = 148;
								hintEnd = 152;
								hintChoices(hintCounter, hintEnd, userStepChoice, stepVector, hintVector);
								break;
							case MENUCHOICE3:
								// Set the starting hint index, the ending hint index, and call the hint function with all the variables needed.
								hintCounter = 152;
								hintEnd = 153;
								hintChoices(hintCounter, hintEnd, userStepChoice, stepVector, hintVector);
								break;
							case MENUCHOICE4:
								// Set the starting hint index, the ending hint index, and call the hint function with all the variables needed.
								hintCounter = 153;
								hintEnd = 156;
								hintChoices(hintCounter, hintEnd, userStepChoice, stepVector, hintVector);
								break;
							case MENUCHOICE5:
								// Set the starting hint index, the ending hint index, and call the hint function with all the variables needed.
								hintCounter = 156;
								hintEnd = 159;
								hintChoices(hintCounter, hintEnd, userStepChoice, stepVector, hintVector);
								break;
							case MENUCHOICE6:
								// Set the starting hint index, the ending hint index, and call the hint function with all the variables needed.
								hintCounter = 159;
								hintEnd = 163;
								hintChoices(hintCounter, hintEnd, userStepChoice, stepVector, hintVector);
								break;
							case MENUCHOICE7:
								// Set the starting hint index, the ending hint index, and call the hint function with all the variables needed.
								hintCounter = 163;
								hintEnd = 165;
								hintChoices(hintCounter, hintEnd, userStepChoice, stepVector, hintVector);
								break;
							case MENUCHOICE8:
								// Set the starting hint index, the ending hint index, and call the hint function with all the variables needed.
								hintCounter = 165;
								hintEnd = 176;
								hintChoices(hintCounter, hintEnd, userStepChoice, stepVector, hintVector);
								break;
							case MENUCHOICE9:
								// Set the starting hint index, the ending hint index, and call the hint function with all the variables needed.
								hintCounter = 176;
								hintEnd = 181;
								hintChoices(hintCounter, hintEnd, userStepChoice, stepVector, hintVector);
								break;
							case MENUCHOICE10:
								// Set the starting hint index, the ending hint index, and call the hint function with all the variables needed.
								hintCounter = 181;
								hintEnd = 184;
								hintChoices(hintCounter, hintEnd, userStepChoice, stepVector, hintVector);
								break;
							}
						case MENUCHOICE9: // A Cornered Rat.
										  // Set the amount of steps, then give the userQuestChoice, STEPS, questVector, and stepVector to the steps function.
							STEPS = 4;
							stepChoices(userQuestChoice, STEPS, questVector, stepVector);

							cin >> userStepChoice; // Set user's input to userStepChoice.
												   // Switch statement to take the user input and print the appropriate hints.
							switch (userStepChoice)
							{
							case MENUCHOICE1:
								// Set the starting hint index, the ending hint index, and call the hint function with all the variables needed.
								hintCounter = 184;
								hintEnd = 190;
								hintChoices(hintCounter, hintEnd, userStepChoice, stepVector, hintVector);
								break;
							case MENUCHOICE2:
								// Set the starting hint index, the ending hint index, and call the hint function with all the variables needed.
								hintCounter = 190;
								hintEnd = 193;
								hintChoices(hintCounter, hintEnd, userStepChoice, stepVector, hintVector);
								break;
							case MENUCHOICE3:
								// Set the starting hint index, the ending hint index, and call the hint function with all the variables needed.
								hintCounter = 193;
								hintEnd = 199;
								hintChoices(hintCounter, hintEnd, userStepChoice, stepVector, hintVector);
								break;
							case MENUCHOICE4:
								// Set the starting hint index, the ending hint index, and call the hint function with all the variables needed.
								hintCounter = 199;
								hintEnd = 201;
								hintChoices(hintCounter, hintEnd, userStepChoice, stepVector, hintVector);
								break;
							}
						case MENUCHOICE10: // Alduin's Wall.
										   // Set the amount of steps, then give the userQuestChoice, STEPS, questVector, and stepVector to the steps function.
							STEPS = 4;
							stepChoices(userQuestChoice, STEPS, questVector, stepVector);

							cin >> userStepChoice; // Set user's input to userStepChoice.
												   // Switch statement to take the user input and print the appropriate hints.
							switch (userStepChoice)
							{
							case MENUCHOICE1:
								// Set the starting hint index, the ending hint index, and call the hint function with all the variables needed.
								hintCounter = 201;
								hintEnd = 207;
								hintChoices(hintCounter, hintEnd, userStepChoice, stepVector, hintVector);
								break;
							case MENUCHOICE2:
								// Set the starting hint index, the ending hint index, and call the hint function with all the variables needed.
								hintCounter = 207;
								hintEnd = 208;
								hintChoices(hintCounter, hintEnd, userStepChoice, stepVector, hintVector);
								break;
							case MENUCHOICE3:
								// Set the starting hint index, the ending hint index, and call the hint function with all the variables needed.
								hintCounter = 208;
								hintEnd = 217;
								hintChoices(hintCounter, hintEnd, userStepChoice, stepVector, hintVector);
								break;
							case MENUCHOICE4:
								// Set the starting hint index, the ending hint index, and call the hint function with all the variables needed.
								hintCounter = 217;
								hintEnd = 223;
								hintChoices(hintCounter, hintEnd, userStepChoice, stepVector, hintVector);
								break;
							}
						case MENUCHOICE11: // The Throat of the World.
										   // Set the amount of steps, then give the userQuestChoice, STEPS, questVector, and stepVector to the steps function.
							STEPS = 7;
							stepChoices(userQuestChoice, STEPS, questVector, stepVector);

							cin >> userStepChoice; // Set user's input to userStepChoice.
												   // Switch statement to take the user input and print the appropriate hints.
							switch (userStepChoice)
							{
							case MENUCHOICE1:
								// Set the starting hint index, the ending hint index, and call the hint function with all the variables needed.
								hintCounter = 223;
								hintEnd = 227;
								hintChoices(hintCounter, hintEnd, userStepChoice, stepVector, hintVector);
								break;
							case MENUCHOICE2:
								// Set the starting hint index, the ending hint index, and call the hint function with all the variables needed.
								hintCounter = 227;
								hintEnd = 228;
								hintChoices(hintCounter, hintEnd, userStepChoice, stepVector, hintVector);
								break;
							case MENUCHOICE3:
								// Set the starting hint index, the ending hint index, and call the hint function with all the variables needed.
								hintCounter = 228;
								hintEnd = 230;
								hintChoices(hintCounter, hintEnd, userStepChoice, stepVector, hintVector);
								break;
							case MENUCHOICE4:
								// Set the starting hint index, the ending hint index, and call the hint function with all the variables needed.
								hintCounter = 230;
								hintEnd = 235;
								hintChoices(hintCounter, hintEnd, userStepChoice, stepVector, hintVector);
								break;
							case MENUCHOICE5:
								// Set the starting hint index, the ending hint index, and call the hint function with all the variables needed.
								hintCounter = 235;
								hintEnd = 236;
								hintChoices(hintCounter, hintEnd, userStepChoice, stepVector, hintVector);
								break;
							case MENUCHOICE6:
								// Set the starting hint index, the ending hint index, and call the hint function with all the variables needed.
								hintCounter = 236;
								hintEnd = 237;
								hintChoices(hintCounter, hintEnd, userStepChoice, stepVector, hintVector);
								break;
							case MENUCHOICE7:
								// Set the starting hint index, the ending hint index, and call the hint function with all the variables needed.
								hintCounter = 237;
								hintEnd = 240;
								hintChoices(hintCounter, hintEnd, userStepChoice, stepVector, hintVector);
								break;
							}
						case MENUCHOICE12: // Elder Knowledge.
										   // Set the amount of steps, then give the userQuestChoice, STEPS, questVector, and stepVector to the steps function.
							STEPS = 3;
							stepChoices(userQuestChoice, STEPS, questVector, stepVector);

							cin >> userStepChoice; // Set user's input to userStepChoice.
												   // Switch statement to take the user input and print the appropriate hints.
							switch (userStepChoice)
							{
							case MENUCHOICE1:
								// Set the starting hint index, the ending hint index, and call the hint function with all the variables needed.
								hintCounter = 240;
								hintEnd = 244;
								hintChoices(hintCounter, hintEnd, userStepChoice, stepVector, hintVector);
								break;
							case MENUCHOICE2:
								// Set the starting hint index, the ending hint index, and call the hint function with all the variables needed.
								hintCounter = 244;
								hintEnd = 246;
								hintChoices(hintCounter, hintEnd, userStepChoice, stepVector, hintVector);
								break;
							case MENUCHOICE3:
								// Set the starting hint index, the ending hint index, and call the hint function with all the variables needed.
								hintCounter = 246;
								hintEnd = 247;
								hintChoices(hintCounter, hintEnd, userStepChoice, stepVector, hintVector);
								break;
							}
						case MENUCHOICE13: // Alduin's Bane.
										   // Set the amount of steps, then give the userQuestChoice, STEPS, questVector, and stepVector to the steps function.
							STEPS = 3;
							stepChoices(userQuestChoice, STEPS, questVector, stepVector);

							cin >> userStepChoice; // Set user's input to userStepChoice.
												   // Switch statement to take the user input and print the appropriate hints.
							switch (userStepChoice)
							{
							case MENUCHOICE1:
								// Set the starting hint index, the ending hint index, and call the hint function with all the variables needed.
								hintCounter = 247;
								hintEnd = 250;
								hintChoices(hintCounter, hintEnd, userStepChoice, stepVector, hintVector);
								break;
							case MENUCHOICE2:
								// Set the starting hint index, the ending hint index, and call the hint function with all the variables needed.
								hintCounter = 250;
								hintEnd = 525;
								hintChoices(hintCounter, hintEnd, userStepChoice, stepVector, hintVector);
								break;
							case MENUCHOICE3:
								// Set the starting hint index, the ending hint index, and call the hint function with all the variables needed.
								hintCounter = 252;
								hintEnd = 258;
								hintChoices(hintCounter, hintEnd, userStepChoice, stepVector, hintVector);
								break;
							}
						case MENUCHOICE14: // The Fallen.
										   // Set the amount of steps, then give the userQuestChoice, STEPS, questVector, and stepVector to the steps function.
							STEPS = 8;
							stepChoices(userQuestChoice, STEPS, questVector, stepVector);

							cin >> userStepChoice; // Set user's input to userStepChoice.
												   // Switch statement to take the user input and print the appropriate hints.
							switch (userStepChoice)
							{
							case MENUCHOICE1:
								// Set the starting hint index, the ending hint index, and call the hint function with all the variables needed.
								hintCounter = 258;
								hintEnd = 260;
								hintChoices(hintCounter, hintEnd, userStepChoice, stepVector, hintVector);
								break;
							case MENUCHOICE2:
								// Set the starting hint index, the ending hint index, and call the hint function with all the variables needed.
								hintCounter = 260;
								hintEnd = 262;
								hintChoices(hintCounter, hintEnd, userStepChoice, stepVector, hintVector);
								break;
							case MENUCHOICE3:
								// Set the starting hint index, the ending hint index, and call the hint function with all the variables needed.
								hintCounter = 262;
								hintEnd = 263;
								hintChoices(hintCounter, hintEnd, userStepChoice, stepVector, hintVector);
								break;
							case MENUCHOICE4:
								// Set the starting hint index, the ending hint index, and call the hint function with all the variables needed.
								hintCounter = 263;
								hintEnd = 266;
								hintChoices(hintCounter, hintEnd, userStepChoice, stepVector, hintVector);
								break;
							case MENUCHOICE5:
								// Set the starting hint index, the ending hint index, and call the hint function with all the variables needed.
								hintCounter = 266;
								hintEnd = 268;
								hintChoices(hintCounter, hintEnd, userStepChoice, stepVector, hintVector);
								break;
							case MENUCHOICE6:
								// Set the starting hint index, the ending hint index, and call the hint function with all the variables needed.
								hintCounter = 268;
								hintEnd = 270;
								hintChoices(hintCounter, hintEnd, userStepChoice, stepVector, hintVector);
								break;
							case MENUCHOICE7:
								// Set the starting hint index, the ending hint index, and call the hint function with all the variables needed.
								hintCounter = 270;
								hintEnd = 273;
								hintChoices(hintCounter, hintEnd, userStepChoice, stepVector, hintVector);
								break;
							case MENUCHOICE8:
								// Set the starting hint index, the ending hint index, and call the hint function with all the variables needed.
								hintCounter = 273;
								hintEnd = 274;
								hintChoices(hintCounter, hintEnd, userStepChoice, stepVector, hintVector);
								break;
							}
						case MENUCHOICE15: // Paarthurnax.
										   // Set the amount of steps, then give the userQuestChoice, STEPS, questVector, and stepVector to the steps function.
							STEPS = 2;
							stepChoices(userQuestChoice, STEPS, questVector, stepVector);

							cin >> userStepChoice; // Set user's input to userStepChoice.
												   // Switch statement to take the user input and print the appropriate hints.
							switch (userStepChoice)
							{
							case MENUCHOICE1:
								// Set the starting hint index, the ending hint index, and call the hint function with all the variables needed.
								hintCounter = 274;
								hintEnd = 277;
								hintChoices(hintCounter, hintEnd, userStepChoice, stepVector, hintVector);
								break;
							case MENUCHOICE2:
								// Set the starting hint index, the ending hint index, and call the hint function with all the variables needed.
								hintCounter = 277;
								hintEnd = 278;
								hintChoices(hintCounter, hintEnd, userStepChoice, stepVector, hintVector);
								break;
							}
						case MENUCHOICE16: // Season Unending.
										   // Set the amount of steps, then give the userQuestChoice, STEPS, questVector, and stepVector to the steps function.
							STEPS = 6;
							stepChoices(userQuestChoice, STEPS, questVector, stepVector);

							cin >> userStepChoice; // Set user's input to userStepChoice.
												   // Switch statement to take the user input and print the appropriate hints.
							switch (userStepChoice)
							{
							case MENUCHOICE1:
								// Set the starting hint index, the ending hint index, and call the hint function with all the variables needed.
								hintCounter = 278;
								hintEnd = 281;
								hintChoices(hintCounter, hintEnd, userStepChoice, stepVector, hintVector);
								break;
							case MENUCHOICE2:
								// Set the starting hint index, the ending hint index, and call the hint function with all the variables needed.
								hintCounter = 281;
								hintEnd = 284;
								hintChoices(hintCounter, hintEnd, userStepChoice, stepVector, hintVector);
								break;
							case MENUCHOICE3:
								// Set the starting hint index, the ending hint index, and call the hint function with all the variables needed.
								hintCounter = 284;
								hintEnd = 288;
								hintChoices(hintCounter, hintEnd, userStepChoice, stepVector, hintVector);
								break;
							case MENUCHOICE4:
								// Set the starting hint index, the ending hint index, and call the hint function with all the variables needed.
								hintCounter = 288;
								hintEnd = 289;
								hintChoices(hintCounter, hintEnd, userStepChoice, stepVector, hintVector);
								break;
							case MENUCHOICE5:
								// Set the starting hint index, the ending hint index, and call the hint function with all the variables needed.
								hintCounter = 289;
								hintEnd = 290;
								hintChoices(hintCounter, hintEnd, userStepChoice, stepVector, hintVector);
								break;
							case MENUCHOICE6:
								// Set the starting hint index, the ending hint index, and call the hint function with all the variables needed.
								hintCounter = 290;
								hintEnd = 292;
								hintChoices(hintCounter, hintEnd, userStepChoice, stepVector, hintVector);
								break;
							}
						case MENUCHOICE17: // The World-Eater's Eyrie.
										   // Set the amount of steps, then give the userQuestChoice, STEPS, questVector, and stepVector to the steps function.
							STEPS = 4;
							stepChoices(userQuestChoice, STEPS, questVector, stepVector);

							cin >> userStepChoice; // Set user's input to userStepChoice.
												   // Switch statement to take the user input and print the appropriate hints.
							switch (userStepChoice)
							{
							case MENUCHOICE1:
								// Set the starting hint index, the ending hint index, and call the hint function with all the variables needed.
								hintCounter = 292;
								hintEnd = 294;
								hintChoices(hintCounter, hintEnd, userStepChoice, stepVector, hintVector);
								break;
							case MENUCHOICE2:
								// Set the starting hint index, the ending hint index, and call the hint function with all the variables needed.
								hintCounter = 294;
								hintEnd = 295;
								hintChoices(hintCounter, hintEnd, userStepChoice, stepVector, hintVector);
								break;
							case MENUCHOICE3:
								// Set the starting hint index, the ending hint index, and call the hint function with all the variables needed.
								hintCounter = 295;
								hintEnd = 301;
								hintChoices(hintCounter, hintEnd, userStepChoice, stepVector, hintVector);
								break;
							case MENUCHOICE4:
								// Set the starting hint index, the ending hint index, and call the hint function with all the variables needed.
								hintCounter = 301;
								hintEnd = 307;
								hintChoices(hintCounter, hintEnd, userStepChoice, stepVector, hintVector);
								break;
							}
						case MENUCHOICE18: // Sovngarde.
										   // Set the amount of steps, then give the userQuestChoice, STEPS, questVector, and stepVector to the steps function.
							STEPS = 3;
							stepChoices(userQuestChoice, STEPS, questVector, stepVector);

							cin >> userStepChoice; // Set user's input to userStepChoice.
												   // Switch statement to take the user input and print the appropriate hints.
							switch (userStepChoice)
							{
							case MENUCHOICE1:
								// Set the starting hint index, the ending hint index, and call the hint function with all the variables needed.
								hintCounter = 307;
								hintEnd = 308;
								hintChoices(hintCounter, hintEnd, userStepChoice, stepVector, hintVector);
								break;
							case MENUCHOICE2:
								// Set the starting hint index, the ending hint index, and call the hint function with all the variables needed.
								hintCounter = 308;
								hintEnd = 311;
								hintChoices(hintCounter, hintEnd, userStepChoice, stepVector, hintVector);
								break;
							case MENUCHOICE3:
								// Set the starting hint index, the ending hint index, and call the hint function with all the variables needed.
								hintCounter = 311;
								hintEnd = 315;
								hintChoices(hintCounter, hintEnd, userStepChoice, stepVector, hintVector);
								break;
							}
						case MENUCHOICE19: // Dragonslayer.
										   // Set the amount of steps, then give the userQuestChoice, STEPS, questVector, and stepVector to the steps function.
							STEPS = 2;
							stepChoices(userQuestChoice, STEPS, questVector, stepVector);

							cin >> userStepChoice; // Set user's input to userStepChoice.
												   // Switch statement to take the user input and print the appropriate hints.
							switch (userStepChoice)
							{
							case MENUCHOICE1:
								// Set the starting hint index, the ending hint index, and call the hint function with all the variables needed.
								hintCounter = 315;
								hintEnd = 320;
								hintChoices(hintCounter, hintEnd, userStepChoice, stepVector, hintVector);
								break;
							case MENUCHOICE2:
								// Set the starting hint index, the ending hint index, and call the hint function with all the variables needed.
								hintCounter = 320;
								hintEnd = 313245;
								hintChoices(hintCounter, hintEnd, userStepChoice, stepVector, hintVector);
								break;
							}
						}

					} while (userStepChoice != MENUCHOICE0); // While the user's choice isn't 0.
				}
				if (userCategoryChoice == 2) // Side Quests.
				{
					categoryChoices(userCategoryChoice, questVector); // Get the categories

					cin >> userQuestChoice; // Set user's input to userQuestChoice.
					cout << "- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -" << endl; // Space for output.

					do
					{
						int STEPS = 0;
						// Switch statement to take the user input and print the appropriate steps.
						switch (userQuestChoice)
						{
						case MENUCHOICE1:
							break;
						}
					} while (userStepChoice != MENUCHOICE0); // While the user's choice isn't 0.
				}
			}
			cout << "- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -" << endl; // Space for output.
			cout << "Returning to main menu.." << endl; // Tell the user they are returning to the game choice.
			cout << "- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -" << endl; // Space for output.
		}
	} while (userMenuChoice != MENUCHOICE2); // While the user doesn't choose the menu choice two (which is the option 'End Program').

	return 0;
}

void createGame(Game gameArray[1], vector<string> categoryNameVector, vector<Quest> questVector, vector<string> stepVector, vector<string> additionalStepsVector, vector<string> hintVector)
{
	// Set the game name.
	gameArray[0].setGameName("The Elder Scrolls V: Skyrim");

	// Set the category names.
	categoryNameVector[0] = "Main Quests";
	categoryNameVector[1] = "Side Quests";

	// Set the quest names and descriptions (if they have them).
	// Main Quests (0-18).
	questVector[0].setQuestName("Unbound");
	questVector[0].setQuestDescription("After the cart ride is over and you choose your character's race, name, and detailed appearance attributes, wait through another non-interactive sequence to get this quest's first objective.");
	questVector[1].setQuestName("Before the Storm");
	questVector[2].setQuestName("Bleak Falls Barrow");
	questVector[3].setQuestName("Dragon Rising");
	questVector[4].setQuestName("The Way of the Voice");
	questVector[5].setQuestName("The Horn of Jurgen Windcaller");
	questVector[6].setQuestName("A Blade in the Dark\n");
	questVector[7].setQuestName("Diplomatic Immunity");
	questVector[8].setQuestName("A Cornered Rat");
	questVector[9].setQuestName("Alduin's Wall");
	questVector[10].setQuestName("The Throat of the World");
	questVector[11].setQuestName("Elder Knowledge");
	questVector[12].setQuestName("Alduin's Bane\n");
	questVector[13].setQuestName("The Fallen");
	questVector[14].setQuestName("Paarthurnax");
	questVector[15].setQuestName("Season Unending");
	questVector[16].setQuestName("The World - Eater's Eyrie");
	questVector[17].setQuestName("Sovngarde");
	questVector[18].setQuestName("Dragonslayer");

	// MAIN QUESTS STARTS HERE
	// Unbound - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
	// Steps
	stepVector[0] = "Make your way to the Keep";
	stepVector[1] = "Enter the Keep with Hadvar or Ralof";
	stepVector[2] = "Objectives for Hadvar's Path";
	stepVector[3] = "Objectives for Ralof's Path";
	// Objectives for Hadvar's Path.
	additionalStepsVector[0] = "Escape Helgen";
	additionalStepsVector[1] = "Find some equipment";
	additionalStepsVector[2] = "(Optional)Search the barrel for potions";
	additionalStepsVector[3] = "(Optional)Attempt to pick the lock to the cage";
	// Objectives for Ralof's Path.
	additionalStepsVector[4] = "Escape Helgen";
	additionalStepsVector[5] = "Loot Gunjar's Body";
	additionalStepsVector[6] = "(Optional)Search the barrel for potions";
	additionalStepsVector[7] = "(Optional)Attempt to pick the lock to the cage";

	// Hints
	// Make your way to the Keep.
	hintVector[0] = "When you gain control, there'll be a guy standing nearby and talking to you. You can also identify him by the quest marker that's hanging over his head (provided you don't use the journal to set this quest as inactive).";
	hintVector[1] = "Follow him through a nearby door, then up the stairs until the dragon makes a big hole in the wall.";
	hintVector[2] = "You'll be instructed to jump through the wall hole, but it's best to just walk forward and drop down onto the edge of the inn's roof, then move to the right a bit so you can jump over the log railing without touching the nearby fire.";
	hintVector[3] = "Go to the other end of the inn and drop down through one of the big floor holes, then go through the doorway ahead and turn left to find the guy you're supposed to follow next.";
	hintVector[4] = "Stay close to him until you meet up with the guy you were following at first. After they split up, you'll get the next objective.";
	// Enter the Keep with Hadvar or Ralof.
	hintVector[5] = "This is the game's first bogus choice, meaning that your decision will have far-ranging consequences, all of which will lead to roughly equivalent outcomes.";
	hintVector[6] = "Hadvar is an Imperial soldier and Ralof is a Stormcloak operative. Which one you follow now will be seen as a choice as to which side you're taking in Skyrim's big civil war. It'll also affect who you travel with for the rest of this quest and the first part of the next one. However, this choice isn't an irrevocable commitment to either side, and you can choose to switch sides later on when it becomes more of an issue.";
	hintVector[7] = "If you'd rather go with Hadvar now, go a short way west to where he's standing, then move into the doorway next to him. If you want to follow Ralof, go a short way north and enter the doorway he's standing next to.";
	// Start of Objectives for Hadvar's Path
	// Escape Helgen.
	hintVector[8] = "Wait for Hadvar to follow you inside, then move up next to him when he says he can get your bonds off.";
	hintVector[9] = "After he cuts your bonds, you'll get the \"Find some equipment\" objective. Finish it, then follow Hadvar through two gates to reach your first combat of the game.";
	hintVector[10] = "After it's over, loot the two Stormcloaks and the dead guy named Gunjar for equipment. After checking to see if you want to equip any of it, follow Hadvar through a door.";
	hintVector[11] = "Look around past it for a lantern and some cheap food items, then follow Hadvar to the next combat area. It also has two fairly weak soldiers in it, so it shouldn't be any problem for you even if you lead the attack in order to get in some skill practice.";
	hintVector[12] = "After that's over, do the \"(Optional)Search the barrel for potions\" objective, then follow Hadvar to the torture chamber, where the torturer and his assistant are under attack by Stormcloak soldiers.";
	hintVector[13] = "You can charge in and practice some skills on the Stormcloaks, or you can hang back and let Hadvar and the torturers take care of business. In either case, start looking around for loot. Before long, you'll get the \"(Optional)Attempt to pick the lock to the cage\" objective.";
	hintVector[14] = "After it's done, move down the passage, watching for a couple of locked cells that you can pick open for more Lockpicking practice. You'll eventually come to a large room with several enemy soldiers in it, some of whom are using bows.";
	hintVector[15] = "Loot them to get a bow and some arrows, then follow Hadvar until you reach a large webby cave with several frostbite spiders in it. Either hang back and try out your new bow, or charge in and start hacking spiders.";
	hintVector[16] = "Loot the spiders and their egg and web sacs, then follow Hadvar along until he stops near a wagon and points out a bear ahead. After looking around the wagon for loot, decide how you want to handle the bear problem.";
	hintVector[17] = "Move on down the passage past the bear's cave until you reach an exit. Move toward it until you're taken outside, then wait until you get the next quest.";
	// Find some equipment.
	hintVector[18] = "All you have to do for this objective is loot the chest that's near the SW corner of the room, but it's best to put that off for a bit.";
	hintVector[19] = "First, look around for other chests and loose items, including two swords on wall racks.";
	hintVector[20] = "Wait until Hadvar walks over to a closed gate, after which you can get in some serious skill practice.";
	hintVector[21] = "When you're tired of that, loot the chest near the SW corner of the room and equip its armor items.";
	// (Optional)Search the barrel for potions.
	hintVector[22] = "As usual with this type of objective, it'll be completed when you search the one item that it's interested in, but you should first look all around for other items to take.";
	hintVector[23] = "You'll find the potion barrel near where the two enemy soldiers were. You'll also find lots of other items to take, not all of which are worth lugging around.";
	hintVector[24] = "After picking up everything, look through your inventory (especially the \"misc\" section) to see what all you can do without.";
	// (Optional)Attempt to pick the lock to the cage.
	hintVector[25] = "First, loot the small table for stuff, then check the large open cage for an iron shield.";
	hintVector[26] = "Next, go over to the three small locked cages and use your new lockpicks to try to get them open.";
	hintVector[27] = "The lockpicking minigame works just like the one in Fallout 3 and Fallout: New Vegas, except it's a bit more primitive and clumsy. Even those who (like me) played those two Fallout games endlessly will need a bit of practice to get used to it, so be sure to quicksave before every lockpick attempt and quickrestore whenever you break a lockpick or two without opening the lock.";
	hintVector[28] = "You only need to lockpick the middle cage open to finish the objective, but you should do all three for extra Lockpicking skill practice.";
	hintVector[29] = "And don't forget to get all the loot that's inside the central cage, including the dead mage's apparel and spell tome.";
	// End of Objectives for Hadvar's Path.
	// Start of Objectives for Ralof's Path
	// Escape Helgen.
	hintVector[30] = "Wait for Ralof to follow you inside, then move up next to him when he says he can get your bonds off.";
	hintVector[31] = "After he cuts your bonds, you'll get the \"Loot Gunjar's body\" objective. Finish it and follow Ralof over to a closed gate, then get ready for your first combat of the game.";
	hintVector[32] = "After it's over, quickly loot the enemy captain's body and take the key before Ralof can. That way, he'll stand near the locked door and let you get some easy skill practice with him.";
	hintVector[33] = "Go through the gate that the Imperials opened and down the passage to reach a room with lots of loot, then go back and open the locked door that Ralof is waiting next to.";
	hintVector[34] = "Look around past it for a lantern and some cheap food items, then follow Ralof to the next combat area. It also has two fairly weak soldiers in it, so it shouldn't be any problem for you even if you lead the attack in order to get in some skill practice.";
	hintVector[35] = "After that's over, do the \"(Optional)Search the barrel for potions\" objective, then follow Ralof to the torture chamber, where Stormcloak soldiers are attacking the torturer and his assistant.";
	hintVector[36] = "You can charge in and practice some skills on the torturers, or you can hang back and let Ralof and the Stormcloak soldiers take care of business. In either case, start looking around for loot. Before long, you'll get the \"(Optional)Attempt to pick the lock to the cage\" objective.";
	hintVector[37] = "After it's done, move down the passage, watching for a couple of locked cells that you can pick open for more Lockpicking practice. You'll eventually come to a large room with several enemy soldiers in it, some of whom are using bows.";
	hintVector[38] = "Loot them to get a bow and some arrows, then follow Ralof until you reach a large webby cave with several frostbite spiders in it. Either hang back and try out your new bow, or charge in and start hacking spiders.";
	hintVector[39] = "Loot the spiders and their egg and web sacs, then follow Ralof along until he stops near a wagon and points out a bear ahead. After looking around the wagon for loot, decide how you want to handle the bear problem.";
	hintVector[40] = "Move on down the passage past the bear's cave until you reach an exit. Move toward it until you're taken outside, then wait until you get the next quest.";
	// Find some equipment.
	hintVector[41] = "Loot the body of the dead guy named Gunjar to get an iron war axe and a couple of armor pieces.";
	// (Optional)Search the barrel for potions.
	hintVector[42] = "As usual with this type of objective, it'll be completed when you search the one item that it's interested in, but you should first look all around for other items to take.";
	hintVector[43] = "You'll find the potion barrel near where the two enemy soldiers were. You'll also find lots of other items to take, not all of which are worth lugging around.";
	hintVector[44] = "After picking up everything, look through your inventory (especially the \"misc\" section) to see what all you can do without.";
	// (Optional)Attempt to pick the lock to the cage.
	hintVector[45] = "First, loot the small table for stuff, then check the large open cage for an iron shield.";
	hintVector[46] = "Next, go over to the three small locked cages and use your new lockpicks to try to get them open.";
	hintVector[47] = "The lockpicking minigame works just like the one in Fallout 3 and Fallout: New Vegas, except it's a bit more primitive and clumsy. Even those who (like me) played those two Fallout games endlessly will need a bit of practice to get used to it, so be sure to quicksave before every lockpick attempt and quickrestore whenever you break a lockpick or two without opening the lock.";
	hintVector[48] = "You only need to lockpick the middle cage open to finish the objective, but you should do all three for extra Lockpicking skill practice.";
	hintVector[49] = "And don't forget to get all the loot that's inside the central cage, including the dead mage's apparel and spell tome.";
	// End of Objectives for Ralof's Path.
	// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

	// Before the Storm - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
	// Steps
	stepVector[4] = "Talk to Alvor in Riverwood.";
	stepVector[5] = "Talk to Gerdur in Riverwood.";
	stepVector[6] = "Talk to the Jarl of Whiterun.";

	// Hints
	// Talk to Alvor in Riverwood.
	hintVector[50] = "Even though he says you should split up, Hadvar will wait for you to follow him. You don't have to, but it would be a good idea to follow him to Riverwood, even if you don't plan on finishing this quest anytime soon.";
	hintVector[51] = "Look for harvestable plants and wolves to fight as you follow Hadvar, and check out the three Guardian Stones when you reach their area. You can examine them and choose which one to receive a blessing from.";
	hintVector[52] = "After you reach Riverwood, follow Hadvar into Alvor and Sigrid's house if you want to continue this quest right away.";
	hintVector[53] = "Wait until Alvor talks to you, then take any or all of the gift items he offers you. You'll then get the \"Talk to the Jarl of Whiterun\" objective. (If you went off and did other things before visiting Alvor, talk to him and ask about supplies in order to get the gifts and the objective.)";
	// Talk to Gerdur in Riverwood.
	hintVector[54] = "Even though he says you should split up, Ralof will wait for you to follow him.You don't have to, but it would be a good idea to follow him to Riverwood, even if you don't plan on finishing this quest anytime soon.";
	hintVector[55] = "Look for harvestable plants and wolves to fight as you follow Ralof, and check out the three Guardian Stones when you reach their area.You can examine them and choose which one to receive a blessing from. (See the Skill Practicing Tips for more details.)";
	hintVector[56] = "After you reach Riverwood, follow Ralof over to where his sister Gerdur is working.";
	hintVector[57] = "Listen to them and follow them around until Gerdur talks to you.Take any or all of the gift items she offers you, then go check out her house before starting on the new \"Talk to the Jarl of Whiterun\" objective.";
	// Talk to the Jarl of Whiterun.
	hintVector[58] = "TIP: Explore Riverwood for loot and skill-practicing opportunities before you start working on this objective.";
	hintVector[59] = "When you're ready to go to Whiterun, cross the bridge that's just NE of Riverwood, then turn right and follow the winding path until you reach an intersection with two bridges.";
	hintVector[60] = "Head down the path that leads west, passing the Honningbrew Meadery and then the Pelagia Farm. Turn right at the path split just past the farm and go past the Whiterun Stables.";
	hintVector[61] = "Continue down the path until you reach the guarded entrance to Whiterun. One of the guards will talk to you and say that the city is closed due to recent dragon activity.";
	hintVector[62] = "You can get the guard to let you pass by saying that Riverwood calls for the Jarl's aid, or you can try the persuade or intimidate option to get some Speech skill practice. In any case, use the big gate to enter Whiterun.";
	hintVector[63] = "Go east down the street until you reach a well near some market stalls, then turn left and go up the stairs to reach a large circular area with a big tree in the center.";
	hintVector[64] = "Go up the stairs north of the tree, then keep going until you discover Dragonsreach. That's where the Jarl of Whiterun lives, so use the big doors to go inside.";
	hintVector[65] = "Move up the stairs and toward the large log fire to get Irileth to talk to you. Say that you have news from Helgen, then approach the Jarl and talk to him.";
	hintVector[66] = "After you tell him what you saw in Helgen, he'll give you a leveled suit of armor and the next quest.";
	// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

	// Bleak Falls Barrow - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
	// Steps.
	stepVector[7] = "Talk to Farengar.";
	stepVector[8] = "Retrieve the Dragonstone.";
	stepVector[9] = "Deliver the Dragonstone to Farengar.";

	// Hints.
	// Talk to Farengar.
	hintVector[67] = "Follow the Jarl into Farengar's room, then wait for him to talk to you.";
	hintVector[68] = "Ask him about what he wants you to fetch to get the next objective, then check out his store inventory before you go.";
	// Retrieve the Dragonstone.
	hintVector[69] = "NOTE: This is where the main quests start getting harder and more combat-intensive, so low-level characters will probably want to go do some random exploring, skill practicing, optional quests, etc. Or go as far as you can on this quest, then go off and do other things for awhile.";
	hintVector[70] = "Exit Dragonsreach and fast-travel back to Riverwood, then go cross the bridge NE of it again.";
	hintVector[71] = "This time, go left instead of right, and start following the path up the mountain. You'll only encounter a wolf or two at first, but watch for several bandits when you get near an old watchtower.";
	hintVector[72] = "Move down the path past the watchtower until you discover the Bleak Falls Barrow, then be ready to fight more bandits after you go up some steps.";
	hintVector[73] = "Enter the Bleak Falls Temple area, then make your way through it and the sanctum area to find the Dragonstone.";
	// Deliver the DragonStone to Farengar.
	hintVector[74] = "Look south of the sarcophagus platform to find some stairs that lead to a cave tunnel.";
	hintVector[75] = "When it dead-ends, look on the top of the nearby fancy pedestal to find a handle.";
	hintVector[76] = "Use it to open up the passage, then go down it until you reach a drop-off.";
	hintVector[77] = "Not far past it is an exit you can use to get outside.";
	hintVector[78] = "Fast-travel back to Dragonsreach, then go inside and talk to Farengar in his room to get the next quest.";
	// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

	// Dragon Rising - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
	// Steps.
	stepVector[10] = "Talk to Jarl Balgruuf.";
	stepVector[11] = "Meet Irileth near the Western Watchtower.";
	stepVector[12] = "Kill the dragon.";
	stepVector[13] = "Investigate the dragon.";
	stepVector[14] = "(Optional)Use your new Shout power.";
	stepVector[15] = "Report back to Jarl Balgruuf.";

	// Hints.
	// Talk to Jarl Balgruuf.
	hintVector[79] = "";
	hintVector[80] = "";
	hintVector[81] = "";
	// Meet Irileth near the Western Watchtower.
	hintVector[82] = "";
	hintVector[83] = "";
	hintVector[84] = "";
	// Kill the dragon.
	hintVector[85] = "";
	hintVector[86] = "";
	hintVector[87] = "";
	// Investigate the dragon.
	hintVector[88] = "";
	// (Optional)Use your new Shout power.
	hintVector[89] = "";
	hintVector[90] = "";
	// Report back to Jarl Balgruuf.
	hintVector[91] = "";
	hintVector[92] = "";
	hintVector[93] = "";
	// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

	// The Way of the Voice - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
	// Steps.
	stepVector[16] = "Speak to the Greybeards.";
	stepVector[17] = "Demonstrate your \"Unrelenting Force\" Shout.";
	stepVector[18] = "Speak to Arngeir.";
	stepVector[19] = "Learn the Word of Power from Einarth.";
	stepVector[20] = "Demonstrate your \"Unrelenting Force\" Shout";
	stepVector[21] = "Learn the Word of Power from Borri.";
	stepVector[22] = "Demonstrate your \"Whirlwind Sprint\" Shout.";
	stepVector[23] = "Speak to Arngeir for further training.";

	// Hints.
	// Speak to the Greybeards.
	hintVector[94] = "";
	hintVector[95] = "";
	hintVector[96] = "";
	hintVector[97] = "";
	hintVector[98] = "";
	hintVector[99] = "";
	hintVector[100] = "";
	hintVector[101] = "";
	// Demonstrate your "Unrelenting Force" Shout.
	hintVector[102] = "";
	// Speak to Arngeir.
	hintVector[103] = "";
	hintVector[104] = "";
	// Learn the Word of Power from Einarth.
	hintVector[105] = "";
	hintVector[106] = "";
	// Demonstrate your "Unrelenting Force" Shout.
	hintVector[107] = "";
	hintVector[108] = "";
	hintVector[109] = "";
	// Learn the Word of Power from Borri.
	hintVector[110] = "";
	hintVector[111] = "";
	// Demonstrate your "Whirlwind Sprint" Shout.
	hintVector[112] = "";
	hintVector[113] = "";
	hintVector[114] = "";
	// Speak to Arngeir for further training.
	hintVector[115] = "";
	// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

	// The Horn of Jurgen Windcaller - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
	// Steps.
	stepVector[24] = "Retrieve the Horn of Jurgen Windcaller.";
	stepVector[25] = "Read the note.";
	stepVector[26] = "Meet with whoever took the horn.";
	stepVector[27] = "Return the horn to Arngeir.";
	stepVector[28] = "Learn the Word of Power from Wulfgar.";
	stepVector[29] = "Receive the Greybeards' greeting.";

	// Hints.
	// Retrieve the Horn of Jurgen Windcaller.
	hintVector[116] = "";
	hintVector[117] = "";
	hintVector[118] = "";
	// Read the note.
	hintVector[119] = "";
	// Meet with whoever took the horn.
	hintVector[120] = "";
	hintVector[121] = "";
	hintVector[122] = "";
	hintVector[123] = "";
	hintVector[124] = "";
	hintVector[125] = "";
	// Return the horn to Arngeir.
	hintVector[126] = "";
	hintVector[127] = "";
	// Learn the Word of Power from Wulfgar.
	hintVector[128] = "";
	hintVector[129] = "";
	// Receive the Greybeards' greeting.
	hintVector[130] = "";
	hintVector[131] = "";
	// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

	// A Blade in the Dark - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
	// Steps.
	stepVector[30] = "Talk to Jarl Balgruuf.";
	stepVector[31] = "Meet Irileth near the Western Watchtower.";
	stepVector[32] = "Kill the dragon.";
	stepVector[33] = "Investigate the dragon.";

	// Hints.
	// Talk to Delphine.
	hintVector[132] = "";
	hintVector[133] = "";
	hintVector[134] = "";
	hintVector[135] = "";
	// Locate the dragon burial site.
	hintVector[136] = "";
	hintVector[137] = "";
	hintVector[138] = "";
	hintVector[139] = "";
	hintVector[140] = "";
	// Kill the dragon Sahloknir.
	hintVector[141] = "";
	hintVector[142] = "";
	hintVector[143] = "";
	hintVector[144] = "";
	// Talk to Delphine.
	hintVector[145] = "";
	hintVector[146] = "";
	// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

	// Diplomatic Immunity - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
	// Steps.
	stepVector[34] = "Meet Delphine in Riverwood.";
	stepVector[35] = "Meet Malborn in Solitude.";
	stepVector[36] = "Give Malborn the equipment.";
	stepVector[37] = "Meet Delphine at the stables.";
	stepVector[38] = "Talk to Malborn.";
	stepVector[39] = "Create a distraction and get away from the party.";
	stepVector[40] = "(Optional)Retrieve your gear.";
	stepVector[41] = "Search for information about the dragons returning.";
	stepVector[42] = "Escape the Thalmor Embassy.";
	stepVector[43] = "Talk to Delphine.";

	// Hints.
	// Meet Delphine in Riverwood.
	hintVector[147] = "";
	// Meet Malborn in Solitude.
	hintVector[148] = "";
	hintVector[149] = "";
	hintVector[150] = "";
	hintVector[151] = "";
	// Give Malborn the equipment.
	hintVector[152] = "";
	// Meet Delphine at the stables.
	hintVector[153] = "";
	hintVector[154] = "";
	hintVector[155] = "";
	// Talk to Malborn.
	hintVector[156] = "";
	hintVector[157] = "";
	hintVector[158] = "";
	// Create a distraction and get away from the party.
	hintVector[159] = "";
	hintVector[160] = "";
	hintVector[161] = "";
	hintVector[162] = "";
	// (Optional)Retrieve your gear.
	hintVector[163] = "";
	hintVector[164] = "";
	// Search for information about the dragons returning.
	hintVector[165] = "";
	hintVector[166] = "";
	hintVector[167] = "";
	hintVector[168] = "";
	hintVector[169] = "";
	hintVector[170] = "";
	hintVector[171] = "";
	hintVector[172] = "";
	hintVector[173] = "";
	hintVector[174] = "";
	hintVector[175] = "";
	// Escape the Thalmor Embassy.
	hintVector[176] = "";
	hintVector[177] = "";
	hintVector[178] = "";
	hintVector[179] = "";
	hintVector[180] = "";
	// Talk to Delphine.
	hintVector[181] = "";
	hintVector[182] = "";
	hintVector[183] = "";
	// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

	// A Cornered Rat - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
	// Steps.
	stepVector[44] = "Talk to Brynjolf.";
	stepVector[45] = "Search the Ratway for Esbern's hideout. ";
	stepVector[46] = "Find Esbern in the Ratway Warrens.";
	stepVector[47] = "Talk to Esbern.";

	// Hints.
	// Talk to Brynjolf.
	hintVector[184] = "";
	hintVector[185] = "";
	hintVector[186] = "";
	hintVector[187] = "";
	hintVector[188] = "";
	hintVector[189] = "";
	// Search the Ratway for Esbern's hideout. 
	hintVector[190] = "";
	hintVector[191] = "";
	hintVector[192] = "";
	// Find Esbern in the Ratway Warrens.
	hintVector[193] = "";
	hintVector[194] = "";
	hintVector[195] = "";
	hintVector[196] = "";
	hintVector[197] = "";
	hintVector[198] = "";
	// Talk to Esbern.
	hintVector[199] = "";
	hintVector[200] = "";

	// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

	// Alduin's Wall - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
	// Steps.
	stepVector[48] = "Escort Esbern to Riverwood";
	stepVector[49] = "Talk to Esbern";
	stepVector[50] = "Gain entrance to Sky Haven Temple";
	stepVector[51] = "Learn the secret of Alduin's Wall";

	// Hints.
	// Escort Esbern to Riverwood. 
	hintVector[201] = "Wait as Esbern runs around and looks for stuff to take with him, then talk to him and ask if he knows the way out.";
	hintVector[202] = "Follow him back to the Ratway Vaults area, then help him kill the Thalmor soldiers and mages that attack.";
	hintVector[203] = "Follow him back to the Ragged Flagon, then over to a raised wooden bridge.";
	hintVector[204] = "Use the big lever on the wall to the right of the bridge to lower it, then cross it and kill the assassin named Shavari (if she appears there). Note that there may also be a couple of Thalmor nearby.";
	hintVector[205] = "Follow Esbern until he goes outside, then fast-travel to Riverwood and enter the inn.";
	hintVector[206] = "Wait while he talks to Delphine, then follow them into her secret room and wait until you get the next objective.";
	// Talk to Eszern.
	hintVector[207] = "Talk to Esbern about how to find Alduin's Wall to get the next objective.";
	// Gain Entrance to Sky Haven Temple
	hintVector[208] = "Wait until Delphine talks to you, then decide whether you'd like to travel to Karthspire with her and Esbern or alone.";
	hintVector[209] = "It's always better to have more companions along (unless you're still practicing your combat skills), so say you'll travel with them, then leave the inn.";
	hintVector[210] = "Before you continue with this quest, you may want to visit four dragon mounds that now have live dragons at them. Your two unkillable traveling companions will be a big help when fighting the dragons, as long as they don't run off on you.";
	hintVector[211] = "Assuming you decide to save those dragons for later, fast-travel to the Whiterun Stables, then use the carriage to travel to Markarth. (Or fast-travel straight there if you've already discovered it.)";
	hintVector[212] = "You can then talk to Delphine and say you'll meet her at Karthspire in order to get her to lead the way. Follow her and Esbern along, ready to help them kill two dragons along the way. (NOTE: The second dragon attacks near Karthspire, and may get distracted by the forsworn guys who are at the Karthspire Camp.)";
	hintVector[213] = "After the dragon and all the forsworn are dead, go up the path from the camp that leads to a dark cave entrance. Move into it to get Delphine and Esbern to catch up with you.";
	hintVector[214] = "Follow them into a forsworn camp, and then on to a large chamber with some stairs that lead to three small stone pillars.";
	hintVector[215] = "Cross the lowered bridge, then move on to a room with a large array of pressure plates on the floor.";
	hintVector[216] = "Follow Esbern until you discover the Sky Haven temple, then look for a way to open its large carved-face door.";
	// Learn the secrets of Anduin's Wall
	hintVector[217] = "Past the carved-face door, go up the steps and through a door to enter the main temple area, then run up some more steps.";
	hintVector[218] = "Look around the area for loot, including a full suit of Blades armor and a unique sword named Dragonbane, while waiting for Esbern to find Alduin's Wall.";
	hintVector[219] = "After he move up to its left end, move close to him and wait as he uses the wall to determine that Alduin was once defeated by some sort of shout.";
	hintVector[220] = "After that, Delphine will talk to you about it, and you'll get the next quest.";
	hintVector[221] = "TIP: Ask Esbern for advice on fighting dragons, then say you need the dragon-slaying blessing. That'll get you a magic effect that gives you a 10% higher critical hit chance against dragons for five game days. When it wears off, you can come back and talk to Esbern to get it again.";
	hintVector[222] = "TIP: You can also now talk to Delphine to start on the Blades Faction Quests.";
	// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

	// The Throat of the World - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
	// Steps.
	stepVector[52] = "Talk to Arngeir";
	stepVector[53] = "Learn the \"Clear Skies\" Shout";
	stepVector[54] = "Use the \"Clear Skies\" Shout to open the path";
	stepVector[55] = "Talk to Paarthurnax";
	stepVector[56] = "Learn the Word of Power from Paarthurnax";
	stepVector[57] = "Use your \"Fire Breath\" Shout on Paarthurnax";
	stepVector[58] = "Talk to Paarthurnax";

	// Hints.
	// Talk to Arngeir
	hintVector[223] = "Use the stairs that are to the right of Alduin's Wall to get up to the top of the wall, then go up the stairs to the north to find an exit.";
	hintVector[224] = "Fast-travel to High Hrothgar, then enter the monastery and follow the quest arrow to Arngeir.";
	hintVector[225] = "Talk to him and say that you need to learn the shout that defeated Alduin. After he rants at you a bit, wait until he talks to you again.";
	hintVector[226] = "After that conversation is over, follow him outside and over to a log fire, after which you'll get the next objective.";
	// Learn the "Clear Skies" Shout. 
	hintVector[227] = "Wait until Arngeir shouts three words onto the ground, then step on them in the order that he did them to absorb them all.";
	// Use the "Clear Skies" Shout to open the path. 
	hintVector[228] = "After Arngeir shares his knowledge of the Clear Skies shout with you, go up the nearby stairs to reach a spot that you can't push your way past.";
	hintVector[229] = "Bring up the Spells menu and select the Clear Skies shout, then hit the Shout key to get the next objective.";
	// Talk to Paarthurnax.
	hintVector[230] = "As you run down the winding path, you'll have two hazards to watch out for.";
	hintVector[231] = "One is ice wraiths, which look like flying skeletal eels. Quickly hit them with fire spells and your best weapon to keep them from killing you with their cold damage attacks.";
	hintVector[232] = "The other hazard is the weather, which can sap your health and stamina. To prevent it from doing that, keep using the Clear Skies shout every time it recharges.";
	hintVector[233] = "You'll eventually make it to the Throat of the World location, where a dragon will land next to you.";
	hintVector[234] = "It's Paarthurnax, so don't attack it. Instead, talk to it and then wait to get the next objective.";
	// Learn the Word of Power from Paarthurnax.
	hintVector[235] = "Go over to the wrecked Word Wall that Paarthurnax shouted a word onto to learn it, then wait to get the next objective.";
	// Use your "Fire Breath" Shout on Paarthurnax. 
	hintVector[236] = "Go to the Spells menu and equip your new Fire Breath shout, then aim at Paarthurnax and hit the Shout key.";
	// Talk to Paarthurnax.
	hintVector[237] = "Go over to Paarthurnax to get him to talk to you, then say that you want to learn the Dragonrend shout.";
	hintVector[238] = "After a great deal of discourse, you'll get the next quest.";
	hintVector[239] = "TIP: Ask Paarthurnax if others come to him to train, then choose a word to meditate on. You can choose \"fus\" (the first word of Unrelenting Force), \"feim\" (the first word of Become Ethereal), or \"yol\" (the first word of Fire Breath). Meditating on \"fus\" makes you stagger 25% less and your opponents stagger 25% more, meditating on \"feim\" makes your health regenerate 25% faster while you're ethereal, and meditating on \"yol\" makes your Fire Breath shout do 25% more damage. You can return to Paarthurnax and change which meditation you have at any time.";
	// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

	// Elder Knowledge - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
	// Steps.
	stepVector[59] = "Learn the location of the Elder Scroll";
	stepVector[60] = "(Optional) Talk to Esbern or (Optional) Talk to Arngeir";
	stepVector[61] = "Recover the Elder Scroll";

	// Hints.
	// Learn the location of the Elder Scroll
	hintVector[240] = "Before you start on this quest, you can optionally go around and kill the last five dragons to be resurrected from dragon mounds.";
	hintVector[241] = "Do the \"(Optional)Talk to Esbern or (Optional)Talk to Arngeir\" objective if you want, then take a carriage to Winterhold if you haven't discovered it already.";
	hintVector[242] = "You'll need to get into the College of Winterhold and start on the \"Discerning the Transmundane\" Daedric quest. See it for all the details.";
	hintVector[243] = "You'll get this quest's \"Recover the Elder Scroll\" objective when you talk to Septimus Signus for that quest.";
	// (Optional) Talk to Esbern or (Optional) Talk to Arngeir
	hintVector[244] = "Fast-travel to either High Hrothgar and talk to Arngeir or to the Sky Temple and talk to Esbern.";
	hintVector[245] = "Either one of them will refer you to the magical college at Winterhold.";
	// Recover the Elder Scroll
	hintVector[246] = "There's nothing to do on this objective separate from the \"Discerning the Transmundane\" Daedric quest. Work on it until you get the Elder Scroll, at which time you'll get the next main quest.";
	// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

	// Alduin's Bane - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
	// Steps.
	stepVector[62] = "Read the Elder Scroll at the Time-Wound";
	stepVector[63] = "Learn the \"Dragonrend\" Shout from the Nord heroes";
	stepVector[64] = "Defeat Alduin";

	// Hints.
	// Read the Elder Scroll at the Time-Wound
	hintVector[247] = "WARNING: Don't go any farther if you're not ready for a very tough combat with a very tough dragon.Make sure you have a follower, a Conjuration spell that'll summon a powerful creature, potions and spells that give temporary fire resistance, and all of that sort of thing in addition to your best weapons and armor. Also, make a regular save at this point, just in case.";
	hintVector[248] = "Fast - travel to the Throat of the World, then go past the spot where Paarthurnax is waiting to find the shimmery \"time wound.\"";
	hintVector[249] = "Quicksave, then go to the books section of your inventory and click on the Elder Scroll to read it. If that doesn't get you the next objective, try doing so again in a slightly different position.";
	// Learn the "Dragonrend" Shout from the Nord heroes
	hintVector[250] = "The only thing you can do during this objective is rotate your view. Just watch and wait until the vision ends and you get the next objective.";
	hintVector[251] = "GLITCH NOTE: The game might permanently stall at some point during the vision. If that happens, load a recent save and try again.";
	// Defeat Alduin
	hintVector[252] = "As soon as you regain control, bring up the Spells menu and select the Dragonrend shout. If you have an Amulet of Talos, you'll probably want to equip it to shorten the time you have to wait between shouts.";
	hintVector[253] = "Look up and wait if necessary for Alduin to go into hover mode, then aim at him and lean on the Shout key. That won't immediately drop him down, but it should cause him to land near you soon.";
	hintVector[254] = "As soon as he does, lay into him with your best weapons, spells, and/or other shouts. You'll want to deal him as much damage as possible before he takes off again.";
	hintVector[255] = "If you want to keep fighting him continuously instead of letting him fly around between attacks, keep hitting him with Dragonrend every time it recharges. Even if he starts to take off, he should drop right back down. The disadvantage of this method is that you'll be under more or less constant attack, and will have to run around and use strong healing potions to stay alive.";
	hintVector[256] = "Another thing you could try is bringing him down and then taking cover behind the nearby damaged Word Wall. Peek out and shoot him with arrows or ranged spells (and Dragonrend to keep him down). Paarthurnax will occasionally attack him for some added damage. Watch out for him edging around to where he can get at you behind the wall. You'll probably want to let him take off and fly around a bit every now and then to prevent that from happening.";
	hintVector[257] = "Stop attacking Alduin when his health bar disappears. After he brags about how you can't kill him and flies away, you'll get the next quest.";
	// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

	// The Fallen - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
	// Steps.
	stepVector[65] = "Talk to Paarthurnax or Talk to Arngeir or Talk to Esbern.";
	stepVector[66] = "Talk to the Jarl of Whiterun.";
	stepVector[67] = "Get Greybeards' help in negotiating a truce.";
	stepVector[68] = "Learn Shout to call Odahviing.";
	stepVector[69] = "Prepare trap for Odahviing.";
	stepVector[70] = "Call Odahviing to Dragonsreach.";
	stepVector[71] = "Defeat and trap Odahviing.";
	stepVector[72] = "Interrogate Odahviing.";

	// Hints.
	// Talk to Paarthurnax or Talk to Arngeir or Talk to Esbern.
	hintVector[258] = "Wait around for Paarthurnax to talk to you and give you the \"Talk to the Jarl of Whiterun\" objective, then optionally go talk to Arngeir at High Hrothgar and/or Esbern at Sky Haven Temple.";
	hintVector[259] = "They'll tell you pretty much the same thing that Paarthurnax did, though note that talking to Esbern is required if you want to get the optional \"Paarthurnax\" quest.";
	// Talk to the Jarl of Whiterun.
	hintVector[260] = "Travel to Dragonsreach and talk to the Jarl about trapping a dragon in his palace.";
	hintVector[261] = "Keep talking to him about it until you get the \"Get Greybeards\' help in negotiating a truce\" objective. (Note that you\'ll skip that objective if you\'ve done enough Civil War Quests to nearly or completely defeat one of the two sides.)";
	// Get Greybeards' help in negotiating a truce.
	hintVector[262] = "There's nothing to do on this objective separate from the \"Season Unending\" quest.";
	// Learn Shout to call Odahviing.
	hintVector[263] = "You can learn the shout you need from either Esbern or Paarthurnax (if you haven't killed him yet).";
	hintVector[264] = "If you did the negotiations at High Hrothgar, all you have to do is wait until Esbern talks to you and gives you the Call Dragon shout.";
	hintVector[265] = "Otherwise, go talk to him at Sky Haven Temple, or talk to Paarthurnax (if he's still alive) at the Throat of the World.";
	// Prepare trap for Odahviing.
	hintVector[266] = "Return to Dragonsreach and talk to the Jarl again.";
	hintVector[267] = "Ask if he's ready to trap the dragon, then say you're ready to get the next objective.";
	// Call Odahviing to Dragonsreach.
	hintVector[268] = "Follow the Jarl out to the Great Porch area, then get the Call Dragon shout ready to use.";
	hintVector[269] = "Move to the end of the porch and hit the Shout key, then switch to the Dragonrend shout and wait for the next objective.";
	// Defeat and trap Odahviing.
	hintVector[270] = "Wait and watch for Odahviing, ready to hit him with the Dragonrend shout as soon as you can. (It's easiest to wait until he's hovering nearby and flaming a guard.)";
	hintVector[271] = "Right after you successfully rend him, turn and sprint for the door that leads back into Dragonsreach.";
	hintVector[272] = "Don't go through the door -- just stand and wait for Odahviing to be trapped.";
	// Interrogate Odahviing.
	hintVector[273] = "Move up to Odahviing and talk to him until you get the \"The World - Eater's Eyrie\" quest.";
	// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

	// Paarthurnax - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
	// Steps.
	stepVector[73] = "Kill Paarthurnax.";
	stepVector[74] = "Talk to Delphine.";

	// Hints.
	// Kill Paarthurnax.
	hintVector[274] = "NOTE: Killing their revered leader will greatly annoy the Greybeards at High Hrothgar. They won't turn hostile to you, but they'll want nothing to do with you anymore.";
	hintVector[275] = "Travel back to the Throat of the World, then go over to where Paarthurnax is sitting.";
	hintVector[276] = "You're going to fight him pretty much like you did Alduin. Hit him with Dragonrend frequently to prevent him from flying around while either pelting him with arrows and spells or whacking him with a powerful melee weapon. Again, having a follower, a summoned creature, and some serious fire resistance and healing items is advised.";
	// Talk to Delphine.
	hintVector[277] = "Return to Sky Haven Temple and talk to Delphine to finish the quest.";
	// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

	// Season Unending - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
	// Steps.
	stepVector[75] = "Talk to Arngeir.";
	stepVector[76] = "Talk to Ulfric Stormcloak. ";
	stepVector[77] = "Talk to General Tullius.";
	stepVector[78] = "Talk to Arngeir.";
	stepVector[79] = "Take your seat.";
	stepVector[80] = "Negotiate a truce.";

	// Hints.
	// Talk to Arngeir.
	hintVector[278] = "Return to High Hrothgar and find Arngeir in the monastery.";
	hintVector[279] = "After he chews you out for killing Paarthurnax (if you did), talk to him and say you need his help to stop the war.";
	hintVector[280] = "That'll get you the next two objectives, which you can do in either order.";
	// Talk to Ulfric Stormcloak. 
	hintVector[281] = "Travel to Windhelm (by carriage if you've never been there before), then go to its north end and enter the Palace of the Kings.";
	hintVector[282] = "Talk to Ulfric Stormcloak and tell him you have a message from the Greybeards.";
	hintVector[283] = "Keep talking to him until he agrees to go to High Hrothgar for the negotiations.";
	// Talk to General Tullius.
	hintVector[284] = "Return to Solitude and follow the winding street around until you reach Castle Dour.";
	hintVector[285] = "Go through the guarded door that's unlocked, then move forward to find General Tullius in his war room.";
	hintVector[286] = "Talk to him (more than once if necessary) until you can tell him you have a message from the Greybeards.";
	hintVector[287] = "Keep talking to him until he agrees to go to High Hrothgar for the negotiations.";
	// Talk to Arngeir.
	hintVector[288] = "Return to High Hrothgar and talk to Arngeir to get the next objective.";
	// Take your seat.
	hintVector[289] = "Go east and around to the Great Hall, then sit on the chair that's at the south end of the round table. The next objective will start soon after you do that.";
	// Negotiate a truce.
	hintVector[290] = "During the long and tedious negotiations, you'll be called upon every now and then to make some sort of decision.";
	hintVector[291] = "Each decision you make will necessarily favor one side (Imperials or Stormcloaks) over the other. You can support whoever you want to, but it would make the most sense to stick with the side you've already been supporting if you've been doing the Civil War Quests. If you haven't, and don't plan to later on, it doesn't matter which side you choose.";
	// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

	// The World-Eater's Eyrie - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
	// Steps.
	stepVector[81] = "Set Odahviing free.";
	stepVector[82] = "Talk to Odahviing.";
	stepVector[83] = "Reach Alduin's portal to Sovngarde.";
	stepVector[84] = "Enter Sovngarde.";

	// Hints.
	// Set Odahviing free.
	hintVector[292] = "Go up either set of stairs near the door that leads back into Dragonsreach to find a guard near a pull chain.";
	hintVector[293] = "Either talk to the guard about opening the trap, or just use the pull chain yourself.";
	// Talk to Odahviing.
	hintVector[294] = "Follow Odahviing to the end of the porch, then talk to him and tell him you're ready to go to Skuldafn. (Note that after you go, you can't fast-travel back. You'll be committed to finishing the main quest series.)";
	// Reach Alduin's portal to Sovngarde.
	hintVector[295] = "After Odahviing takes off, get out your bow and see if you can sneak-attack any of the draugr that are wandering around the structures on the other side of the water. If you can't see any, fire some arrows over there in various spots to lure some into the open.";
	hintVector[296] = "After you kill several draugr or use the bridge to cross the water, a dragon will swoop down on you. It's best to use your shouts, weapons, etc. to kill it on your side of the water, then cross the bridge.";
	hintVector[297] = "Turn right past the bridge and watch for draugr as you move south. When you get near the Skudafn South Tower, another dragon will swoop down and attack. You can retreat into the tower for a break, but you'll have to fight several draugr inside.";
	hintVector[298] = "After the dragon is dealt with, go up the steps to the east and past a ruined tower, then turn north and go up some stairs to find a door that leads into the Skuldafn Temple. There will, of course, be several draugr to fight on the way.";
	hintVector[299] = "You'll need to make your way through two identically-named temple areas in order to reach the outdoor area with Alduin's portal.";
	hintVector[300] = "After you exit the second temple area, kill any nearby draugr, then turn left and go around to where you can climb some steps to reach the portal area.";
	// Enter Sovngarde.
	hintVector[301] = "Crouch down and sneak-attack the dragon priest named Nahkriin from a distance as much as possible before he starts attacking back.";
	hintVector[302] = "He's a very powerful mage, and you'll want to stay back and dodge as many of his spells as you can if your magic resistance is low.";
	hintVector[303] = "TIP: Even though he appears to be levitating, he'll still fall and take lots of damage if you knock him off the side of the temple.";
	hintVector[304] = "NOTE: There are two dragons perched nearby, but they probably won't join the battle unless you attack them. They didn't when I played, anyway.";
	hintVector[305] = "Loot Nahkriin to get his dragon priest staff, then go up to where he was using it earlier.";
	hintVector[306] = "Activate the dragon seal to place the staff and open the portal to Sovngarde, then jump into it to get the next quest.";
	// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

	// Sovngarde - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
	// Steps.
	stepVector[85] = "Find out how to defeat Alduin.";
	stepVector[86] = "Gain admittance to the Hall of Valor.";
	stepVector[87] = "Talk to the heroes of Sovngarde.";

	// Hints.
	// Find out how to defeat Alduin.
	hintVector[307] = "Go down the stone steps and along the path until you meet a Stormcloak soldier, then talk to him to get the next objective.";
	// Gain admittance to the Hall of Valor.
	hintVector[308] = "Continue down the path until it splits, then go either way to reach the large bony bridge that leads to the Hall of Valor.";
	hintVector[309] = "As you approach the bridge, a warrior named Tsun will talk to you. After a brief conversation, he'll require you to prove yourself in battle against him.";
	hintVector[310] = "Use all your best weapons, shouts, spells, etc. on him until he puts his weapon away. Do the same, then wait if necessary to get the next objective.";
	// Talk to the heroes of Sovngarde.
	hintVector[311] = "Carefully cross the bone bridge, then approach the Hall of Valor and use one of its doors to go inside.";
	hintVector[312] = "After Ysgramor talks to you, look around the hall for the three dead heroes that he mentioned.";
	hintVector[313] = "You'll find them all standing together near the NE corner of the central hall area.";
	hintVector[314] = "Go over to them and wait while they talk, after which you'll get the final main quest.";
	// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

	// Dragonslayer - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
	// Steps.
	stepVector[89] = "Help the heroes of Sovngarde dispel Alduin's mist.";
	stepVector[90] = "Defeat Alduin.";

	// Hints.
	// Help the heroes of Sovngarde dispel Alduin's mist.
	hintVector[315] = "Exit the Hall of Valor, then follow the heroes across the bone bridge.";
	hintVector[316] = "When they stop, move up next to them and get the Clear Skies shout ready.";
	hintVector[317] = "After one of them mentions that shout, fire it off, then wait as they do the same. ";
	hintVector[318] = "When one of them says \"again, \" use the shout again.";
	hintVector[319] = "Wait until they say to use the shout again, then do so and wait to get the next objective.";
	// Defeat Alduin.
	hintVector[320] = "Get the Dragonrend shout ready, then hit Alduin with it as soon as you can.";
	hintVector[321] = "Run over to a spot near where he lands so you can keep hitting him with Dragonrend every now and then to keep him on the ground and vulnerable.";
	hintVector[322] = "As for actually dealing him damage, the three heroes and other souls nearby can take care of that for you. Stay back and use arrows or long-range spells if you want to, but don't let Alduin get you, and don't forget about using Dragonrend.";
	hintVector[323] = "When Alduin's health reaches zero, he'll be utterly destroyed. 'Bout time!";
	// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
	// MAIN QUESTS ENDS HERE.

	// SIDE QUESTS STARTS HERE.

	// Missing in Action - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
	// Steps
	stepVector[] = "Meet Fralia in her home.";
	stepVector[] = "Find evidence of Thorald's fate.";
	stepVector[] = "Deliver proof to Avulstein.";
	stepVector[] = "Find a way to release Thorald from Thalmor custody.";
	stepVector[] = "Meet Avulstein at Northwatch Keep.";
	stepVector[] = "Rescue Thorald from Northwatch Keep.";
	stepVector[] = "Lead Thorald to safety.";
	stepVector[] = "Speak to Thorald Gray-Mane.";
	stepVector[] = "Return to Fralia Gray-Mane.";

	// Hints
	// Meet Fralia in her home.
	hintVector[] = "Follow Fralia into House Gray-Mane, then wait until Avulstein Gray-Mane talks to you and gives you the next objective.";
	// Find evidence of Thorald's fate.
	hintVector[] = "There are three ways to get the information you need.";
	hintVector[] = "One way is to find it inside the House of Clan Battle-Born.";
	hintVector[] = "Another way is to find Idolaf Battle-Born and persuade him to tell you where Thorald is. That requires you to pass a fairly tough persuade dialogue option.";	
	hintVector[] = "If you can't do either of those ways, find Jon Battle-Born and convince him to help you.";
	// Deliver proof to Avulstein.
	hintVector[] = "Return to House Gray-Mane and talk to Avulstein about the proof you found.";
	hintVector[] = "You can then say you'll join him in the assault on Northwatch Keep, or you can tell him to stay hidden.";
	hintVector[] = "If you join the assault, you'll get the \"Meet Avulstein at Northwatch Keep\" objective. Otherwise, you'll get the \"Find a way to release Thorald from Thalmor custody\" objective.";
	// Find a way to release Thorald from Thalmor custody.
	hintVector[] = "Rescuing Thorald without Avulstein's help works pretty much like it does in the \"Rescue Thorald from Northwatch Keep\" objective, with the exceptions that you won't have any combat support (unless you bring a follower) and sneaking around unseen will be a lot easier.";
	hintVector[] = "Using stealth to enter the keep unseen is very difficult, even if you have the Muffle spell and Invisibility potions. Besides, you'll need all of the outdoor guards to be dead when you exit the keep with Thorald later.";
	hintVector[] = "Bring a tough, well-equipped follower, and use sneaky ranged attacks and summoned creatures to help you kill off all of the keep's exterior guards. After that, enter the keep through its unlocked door and make your way through it as outlined in the above-mentioned objective.";
	// Meet Avulstein at Northwatch Keep.
	hintVector[] = "Look for Avulstein and his men behind a large rock a short way east of the keep's entrance.";
	hintVector[] = "Talk to Avulstein to get the next objective.";
	// Rescue Thorald from Northwatch Keep.
	hintVector[] = "Lead Avulstein and the boys over to a spot near the keep's entrance, then stay back and use ranged attacks as they move in on the Northwatch guards.";
	hintVector[] = "There are a lot of well-armed guards, and your group can be very easily overwhelmed. Try to lead any guard who comes after you away from the keep so they won't all get after you at once.";
	hintVector[] = "At least Avulstein is unkillable, so he'll keep on being helpful -- when he's not temporarily disabled, anyway. After all of the guards are killed, enter the keep through its unlocked door.";
	hintVector[] = "Crouch down and sneak down the steps in the first room so you can get the drop on the guard and mage in the second room, then go through a wooden door and sneak over to where you can ambush an archer who's at the bottom of some more steps.";
	hintVector[] = "Sneak down the steps and try to sneak-attack the two guards in the next room. On past that, you'll find two more guards and a mage in a large two-floor room. (Note that the mage starts behind a door on the lower floor.)";
	hintVector[] = "Use the passage on the upper floor of that room to move on to an area with a seated guard on the right and the Northwatch interrogator in a side room on the left. Try to sneak-attack both of them, then follow Avulstein as he walks up to Thorald.";
	hintVector[] = "After he talks to Thorald, do so yourself to get the next objective.";
	// Lead Thorald to safety.
	hintVector[] = "Wait for Thorald to free himself from his shackles and pick up a nearby weapon, then lead him out of the keep.";
	hintVector[] = "You could retrace your steps and leave the keep the same way you entered it, but there is a shortcut exit available if you don't mind fighting two more guards.";
	hintVector[] = "Leave the interrogator's room and go across to where there was a seated guard earlier.";
	hintVector[] = "Open the nearby door, then sneak-attack the two guards in the area beyond. (Or sneak up to where you can use the two levers on the left to release some prisoners as a distraction.)";
	hintVector[] = "After they're dead, go past them to find a locked door that leads outside.";
	hintVector[] = "If you can't pick the lock, go back and loot the interrogator's body to get the key.";
	hintVector[] = "You'll get the next objective when you exit the keep.";
	// Speak to Thorald Gray-Mane
	hintVector[] = "Talk to Thorald to get the next objective.";
	//Return to Fralia Gray-Mane
	hintVector[] = "Return to Whiterun and follow the quest arrow to Fralia, then tell her that Thorald is safe to finish the quest and get a random enchanted steel weapon.";

	// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -





	// SIDE QUESTS ENDS HERE.

	// Set all the vectors to vectors in the classes.
	gameArray[0].setCategoryNameVector(categoryNameVector);
	questVector[0].setStepVector(stepVector);
	questVector[0].setAdditionalStepsVector(additionalStepsVector);
	questVector[0].setHintVector(hintVector);
	gameArray[0].setQuestVector(questVector);
}

void categoryChoices(int userCategoryChoice, vector<Quest> questVector)
{
	// Number of quests for each category.
	const int MAINNOQUESTS = 18, SIDENOQUESTS = 0;

	// Switch statement to take the user input and print the appropriate quests.
	switch (userCategoryChoice)
	{
	case MENUCHOICE1: // Main Quests.
					  // Output the category name, the quests and spaces for output (this repeats until the end of the switch statement).
		cout << "Main Quests\n\nChoose a quest..\n" << endl;
		for (int i = 0; i <= MAINNOQUESTS; i++)
		{
			cout << i + 1 << ". " << questVector[i].getQuestName() << endl;
		}
		cout << "- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -" << endl; // Space for output.
		break;
	case MENUCHOICE2: // Side Quests.
		cout << "Side Quests\n\nChoose a quest..\n" << endl;
		for (int i = 0; i <= SIDENOQUESTS; i++)
		{
			cout << i - 18 << ". " << questVector[i].getQuestName() << endl;
		}
		cout << "- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -" << endl; // Space for output.
		break;
	}
}

void stepChoices(int userQuestChoice, int STEPS, vector<Quest> questVector, vector<string> stepVector)
{
	// Output the name and description of the quest. 
	cout << questVector[userQuestChoice - 1].getQuestName() << endl;
	// Check if there is a description, if so then print it.
	if (questVector[userQuestChoice - 1].getQuestDescription() != "")
	{
		cout << questVector[userQuestChoice - 1].getQuestDescription() << endl;
	}
	// Prompt the user to choose a step then, output the exit variable, and then output all the steps.
	cout << "\nChoose a step..\n" << endl;
	cout << "0. Exit" << endl;
	for (int i = 0; i < STEPS; i++)
	{
		cout << i + 1 << ". " << stepVector[i] << endl;
	}
	cout << "- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -" << endl; // Space for output.
}
void hintChoices(int hintCounter, int hintEnd, int userStepChoice, vector<string> stepVector, vector<string> hintVector)
{
	int userHintChoice; // This is the user's input for the hint.
	int stepNumber = 1; // This is the counter for the current step.

	cout << stepVector[userStepChoice - 1] << endl << endl;
	do // Do this.
	{
		// If the hintOutput is the maximum amount tell the user there is no more hints and break from the do-while loop.
		if (hintCounter == hintEnd)
		{
			cout << "- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -" << endl; // Space for output.
			cout << "No more hints. Returning to steps.." << endl;
			cout << "- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -" << endl; // Space for output.
			break;
		}
		cout << "- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -" << endl; // Space for output.
																							   // For loop to print out each hint every loop.
		for (int i = hintCounter; i <= hintCounter; i++)
		{
			cout << stepNumber << ". " << hintVector[i] << endl;
			stepNumber++;
		}
		cout << "- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -" << endl; // Space for output.
		cout << "Type '1' to request another hint and '2' to go back to steps." << endl; // Give the user the commands they can use.
		cout << "- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -" << endl; // Space for output.
		cin >> userHintChoice; // Set user's input to userHintChoice.
							   // If the userHintChoice is equal to one increase the counter variable.
		if (userHintChoice == 1)
		{
			hintCounter++;
		}
	} while (userHintChoice != MENUCHOICE2); // While the user's choice isn't 2.
}

int additionalStepPrint(int userStepChoice, int STEPS, vector<string> additionalStepsVector)
{
	int userAdditionalChoice; // This is the user's input for the addition step.

	cout << "- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -" << endl; // Space for output.
	cout << additionalStepsVector[userStepChoice - 1] << endl << endl;
	cout << "Choose a step..\n";
	for (int i = 0; i < STEPS; i++)
	{
		cout << i + 1 << ". " << additionalStepsVector[i] << endl;
	}
	cout << "- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -" << endl; // Space for output.
	cin >> userAdditionalChoice;
	return userAdditionalChoice;
}