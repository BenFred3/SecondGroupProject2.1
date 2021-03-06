// Spoiler-free walkthrough
// By: Ben Frederickson, Drew Douglas, and Jordan Neumayer
// This program allows a user to access a spoiler free walkthrough for the game skyrim. With the code we have it could be expanded to other games as well.

#include <iostream>
#include <vector>
#include <string>
#include "Game.h"
#include "Quest.h"
#pragma comment(lib, "user32")
using namespace std;

// This function populates all the values in each vector.
void createGame(Game gameArray[1], vector<string> categoryNameVector, vector<Quest> questVector, vector<string> stepVector, vector<string> additionalStepsVector, vector<string> hintVector);
// This function gives the category choices.
void categoryChoices(int userCategoryChoice, vector<Quest> questVector);
// This function gives the step choices.
void stepChoices(int userQuestChoice, int STEPS, int startSteps, vector<Quest> questVector, vector<string> stepVector);
// This function gives the hint choices.
void hintChoices(int hintCounter, int hintEnd, int userStepChoice, vector<string> stepVector, vector<string> hintVector);
// This function prints the additional step choices.
int additionalStepPrint(int userStepChoice, int STEPS, int startSteps, vector<string> additionalStepsVector);

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
MENUCHOICE19 = 19,
MENUCHOICE20 = 20,
MENUCHOICE21 = 21,
MENUCHOICE22 = 22;

int main()
{
	system("mode 650"); // Make the console fullscreen.

	const int DEFAULTVALUE = 100; // Default value for all the vectors.
	const int DEFAULTVALUESTEPS = 1000; // Default value for all the steps.
	const int DEFAULTVALUEHINTS = 1000; // Default value for all the hints.

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

	vector<string> hintVector(DEFAULTVALUEHINTS);
	questVector[0].setHintVector(hintVector);

	createGame(gameArray, categoryNameVector, questVector, stepVector, additionalStepsVector, hintVector); // This creates the game Skyrim from the vectors already created.

																										   // Get the vectors from the class.
	categoryNameVector = gameArray[0].getCategoryNameVector();
	questVector = gameArray[0].getQuestVector();
	stepVector = questVector[0].getStepVector();
	additionalStepsVector = questVector[0].getAdditionalStepsVector();
	hintVector = questVector[0].getHintVector();

	int sideQuestStepStarter = 19; // This is for when the program needs to print the current quests to the user, this is needed for the step quests.
	int dungeonQuestStepStarter = 41; // This is for when the program needs to print the current quests to the user, this is needed for the dungeon quests.
	int userMenuChoice; // This is the user's input for the main menu.
	int userGameChoice; // This is the user's input for the game choice.
	int userCategoryChoice; // This is the user's input for the category.
	int userQuestChoice; // This is the user's input for the quest.
	int userStepChoice; // This is the user's input for the step.
	int startSteps; // This tells the program where to start the steps.
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
							startSteps = 0;
							stepChoices(userQuestChoice, STEPS, startSteps, questVector, stepVector);

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
								startSteps = 0;
								userAdditionalChoice = additionalStepPrint(userStepChoice, STEPS, startSteps, additionalStepsVector);
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
								startSteps = 4;
								userAdditionalChoice = additionalStepPrint(userStepChoice, STEPS, startSteps, additionalStepsVector);
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
							break;
						case MENUCHOICE2: // Before the Storm.
										  // Set the amount of steps, then give the userQuestChoice, STEPS, questVector, and stepVector to the steps function.
							STEPS = 3;
							startSteps = 4;
							stepChoices(userQuestChoice, STEPS, startSteps, questVector, stepVector);

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
								hintCounter = 54;
								hintEnd = 58;
								hintChoices(hintCounter, hintEnd, userStepChoice, stepVector, hintVector);
								break;
							case MENUCHOICE3:
								hintCounter = 58;
								hintEnd = 67;
								hintChoices(hintCounter, hintEnd, userStepChoice, stepVector, hintVector);
								break;
							}
							break;
						case MENUCHOICE3: // Bleak Falls Barrow.
										  // Set the amount of steps, then give the userQuestChoice, STEPS, questVector, and stepVector to the steps function.
							STEPS = 3;
							startSteps = 7;
							stepChoices(userQuestChoice, STEPS, startSteps, questVector, stepVector);

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
								hintCounter = 69;
								hintEnd = 74;
								hintChoices(hintCounter, hintEnd, userStepChoice, stepVector, hintVector);
								break;
							case MENUCHOICE3:
								hintCounter = 74;
								hintEnd = 79;
								hintChoices(hintCounter, hintEnd, userStepChoice, stepVector, hintVector);
								break;
							}
							break;
						case MENUCHOICE4: // Dragon Rising.
										  // Set the amount of steps, then give the userQuestChoice, STEPS, questVector, and stepVector to the steps function.
							STEPS = 6;
							startSteps = 10;
							stepChoices(userQuestChoice, STEPS, startSteps, questVector, stepVector);

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
								hintCounter = 82;
								hintEnd = 85;
								hintChoices(hintCounter, hintEnd, userStepChoice, stepVector, hintVector);
								break;
							case MENUCHOICE3:
								hintCounter = 85;
								hintEnd = 88;
								hintChoices(hintCounter, hintEnd, userStepChoice, stepVector, hintVector);
								break;
							case MENUCHOICE4:
								hintCounter = 88;
								hintEnd = 89;
								hintChoices(hintCounter, hintEnd, userStepChoice, stepVector, hintVector);
								break;
							case MENUCHOICE5:
								hintCounter = 89;
								hintEnd = 91;
								hintChoices(hintCounter, hintEnd, userStepChoice, stepVector, hintVector);
								break;
							case MENUCHOICE6:
								hintCounter = 91;
								hintEnd = 94;
								hintChoices(hintCounter, hintEnd, userStepChoice, stepVector, hintVector);
								break;
							}
							break;
						case MENUCHOICE5: // The Way of the Voice.
										  // Set the amount of steps, then give the userQuestChoice, STEPS, questVector, and stepVector to the steps function.
							STEPS = 8;
							startSteps = 16;
							stepChoices(userQuestChoice, STEPS, startSteps, questVector, stepVector);

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
								hintCounter = 102;
								hintEnd = 103;
								hintChoices(hintCounter, hintEnd, userStepChoice, stepVector, hintVector);
								break;
							case MENUCHOICE3:
								hintCounter = 103;
								hintEnd = 105;
								hintChoices(hintCounter, hintEnd, userStepChoice, stepVector, hintVector);
								break;
							case MENUCHOICE4:
								hintCounter = 105;
								hintEnd = 107;
								hintChoices(hintCounter, hintEnd, userStepChoice, stepVector, hintVector);
								break;
							case MENUCHOICE5:
								hintCounter = 107;
								hintEnd = 110;
								hintChoices(hintCounter, hintEnd, userStepChoice, stepVector, hintVector);
								break;
							case MENUCHOICE6:
								hintCounter = 110;
								hintEnd = 112;
								hintChoices(hintCounter, hintEnd, userStepChoice, stepVector, hintVector);
								break;
							case MENUCHOICE7:
								hintCounter = 112;
								hintEnd = 115;
								hintChoices(hintCounter, hintEnd, userStepChoice, stepVector, hintVector);
								break;
							case MENUCHOICE8:
								hintCounter = 115;
								hintEnd = 116;
								hintChoices(hintCounter, hintEnd, userStepChoice, stepVector, hintVector);
								break;
							}
							break;
						case MENUCHOICE6: // The Horn of Jurgen Windcaller.
										  // Set the amount of steps, then give the userQuestChoice, STEPS, questVector, and stepVector to the steps function.
							STEPS = 6;
							startSteps = 24;
							stepChoices(userQuestChoice, STEPS, startSteps, questVector, stepVector);

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
								hintCounter = 119;
								hintEnd = 120;
								hintChoices(hintCounter, hintEnd, userStepChoice, stepVector, hintVector);
								break;
							case MENUCHOICE3:
								hintCounter = 120;
								hintEnd = 126;
								hintChoices(hintCounter, hintEnd, userStepChoice, stepVector, hintVector);
								break;
							case MENUCHOICE4:
								hintCounter = 126;
								hintEnd = 128;
								hintChoices(hintCounter, hintEnd, userStepChoice, stepVector, hintVector);
								break;
							case MENUCHOICE5:
								hintCounter = 128;
								hintEnd = 130;
								hintChoices(hintCounter, hintEnd, userStepChoice, stepVector, hintVector);
								break;
							case MENUCHOICE6:
								hintCounter = 130;
								hintEnd = 132;
								hintChoices(hintCounter, hintEnd, userStepChoice, stepVector, hintVector);
								break;
							}
							break;
						case MENUCHOICE7: // A Blade in the Dark.
										  // Set the amount of steps, then give the userQuestChoice, STEPS, questVector, and stepVector to the steps function.
							STEPS = 4;
							startSteps = 30;
							stepChoices(userQuestChoice, STEPS, startSteps, questVector, stepVector);

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
								hintCounter = 136;
								hintEnd = 141;
								hintChoices(hintCounter, hintEnd, userStepChoice, stepVector, hintVector);
								break;
							case MENUCHOICE3:
								hintCounter = 141;
								hintEnd = 145;
								hintChoices(hintCounter, hintEnd, userStepChoice, stepVector, hintVector);
								break;
							case MENUCHOICE4:
								hintCounter = 145;
								hintEnd = 147;
								hintChoices(hintCounter, hintEnd, userStepChoice, stepVector, hintVector);
								break;
							}
							break;
						case MENUCHOICE8: // Diplomatic immunity.
										  // Set the amount of steps, then give the userQuestChoice, STEPS, questVector, and stepVector to the steps function.
							STEPS = 10;
							startSteps = 34;
							stepChoices(userQuestChoice, STEPS, startSteps, questVector, stepVector);

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
								hintCounter = 148;
								hintEnd = 152;
								hintChoices(hintCounter, hintEnd, userStepChoice, stepVector, hintVector);
								break;
							case MENUCHOICE3:
								hintCounter = 152;
								hintEnd = 153;
								hintChoices(hintCounter, hintEnd, userStepChoice, stepVector, hintVector);
								break;
							case MENUCHOICE4:
								hintCounter = 153;
								hintEnd = 156;
								hintChoices(hintCounter, hintEnd, userStepChoice, stepVector, hintVector);
								break;
							case MENUCHOICE5:
								hintCounter = 156;
								hintEnd = 159;
								hintChoices(hintCounter, hintEnd, userStepChoice, stepVector, hintVector);
								break;
							case MENUCHOICE6:
								hintCounter = 159;
								hintEnd = 163;
								hintChoices(hintCounter, hintEnd, userStepChoice, stepVector, hintVector);
								break;
							case MENUCHOICE7:
								hintCounter = 163;
								hintEnd = 165;
								hintChoices(hintCounter, hintEnd, userStepChoice, stepVector, hintVector);
								break;
							case MENUCHOICE8:
								hintCounter = 165;
								hintEnd = 176;
								hintChoices(hintCounter, hintEnd, userStepChoice, stepVector, hintVector);
								break;
							case MENUCHOICE9:
								hintCounter = 176;
								hintEnd = 181;
								hintChoices(hintCounter, hintEnd, userStepChoice, stepVector, hintVector);
								break;
							case MENUCHOICE10:
								hintCounter = 181;
								hintEnd = 184;
								hintChoices(hintCounter, hintEnd, userStepChoice, stepVector, hintVector);
								break;
							}
							break;
						case MENUCHOICE9: // A Cornered Rat.
										  // Set the amount of steps, then give the userQuestChoice, STEPS, questVector, and stepVector to the steps function.
							STEPS = 4;
							startSteps = 44;
							stepChoices(userQuestChoice, STEPS, startSteps, questVector, stepVector);

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
								hintCounter = 190;
								hintEnd = 193;
								hintChoices(hintCounter, hintEnd, userStepChoice, stepVector, hintVector);
								break;
							case MENUCHOICE3:
								hintCounter = 193;
								hintEnd = 199;
								hintChoices(hintCounter, hintEnd, userStepChoice, stepVector, hintVector);
								break;
							case MENUCHOICE4:
								hintCounter = 199;
								hintEnd = 201;
								hintChoices(hintCounter, hintEnd, userStepChoice, stepVector, hintVector);
								break;
							}
							break;
						case MENUCHOICE10: // Alduin's Wall.
										   // Set the amount of steps, then give the userQuestChoice, STEPS, questVector, and stepVector to the steps function.
							STEPS = 4;
							startSteps = 48;
							stepChoices(userQuestChoice, STEPS, startSteps, questVector, stepVector);

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
								hintCounter = 207;
								hintEnd = 208;
								hintChoices(hintCounter, hintEnd, userStepChoice, stepVector, hintVector);
								break;
							case MENUCHOICE3:
								hintCounter = 208;
								hintEnd = 217;
								hintChoices(hintCounter, hintEnd, userStepChoice, stepVector, hintVector);
								break;
							case MENUCHOICE4:
								hintCounter = 217;
								hintEnd = 223;
								hintChoices(hintCounter, hintEnd, userStepChoice, stepVector, hintVector);
								break;
							}
							break;
						case MENUCHOICE11: // The Throat of the World.
										   // Set the amount of steps, then give the userQuestChoice, STEPS, questVector, and stepVector to the steps function.
							STEPS = 7;
							startSteps = 52;
							stepChoices(userQuestChoice, STEPS, startSteps, questVector, stepVector);

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
								hintCounter = 227;
								hintEnd = 228;
								hintChoices(hintCounter, hintEnd, userStepChoice, stepVector, hintVector);
								break;
							case MENUCHOICE3:
								hintCounter = 228;
								hintEnd = 230;
								hintChoices(hintCounter, hintEnd, userStepChoice, stepVector, hintVector);
								break;
							case MENUCHOICE4:
								hintCounter = 230;
								hintEnd = 235;
								hintChoices(hintCounter, hintEnd, userStepChoice, stepVector, hintVector);
								break;
							case MENUCHOICE5:
								hintCounter = 235;
								hintEnd = 236;
								hintChoices(hintCounter, hintEnd, userStepChoice, stepVector, hintVector);
								break;
							case MENUCHOICE6:
								hintCounter = 236;
								hintEnd = 237;
								hintChoices(hintCounter, hintEnd, userStepChoice, stepVector, hintVector);
								break;
							case MENUCHOICE7:
								hintCounter = 237;
								hintEnd = 240;
								hintChoices(hintCounter, hintEnd, userStepChoice, stepVector, hintVector);
								break;
							}
							break;
						case MENUCHOICE12: // Elder Knowledge.
										   // Set the amount of steps, then give the userQuestChoice, STEPS, questVector, and stepVector to the steps function.
							STEPS = 3;
							startSteps = 59;
							stepChoices(userQuestChoice, STEPS, startSteps, questVector, stepVector);

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
								hintCounter = 244;
								hintEnd = 246;
								hintChoices(hintCounter, hintEnd, userStepChoice, stepVector, hintVector);
								break;
							case MENUCHOICE3:
								hintCounter = 246;
								hintEnd = 247;
								hintChoices(hintCounter, hintEnd, userStepChoice, stepVector, hintVector);
								break;
							}
							break;
						case MENUCHOICE13: // Alduin's Bane.
										   // Set the amount of steps, then give the userQuestChoice, STEPS, questVector, and stepVector to the steps function.
							STEPS = 3;
							startSteps = 62;
							stepChoices(userQuestChoice, STEPS, startSteps, questVector, stepVector);

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
								hintCounter = 250;
								hintEnd = 525;
								hintChoices(hintCounter, hintEnd, userStepChoice, stepVector, hintVector);
								break;
							case MENUCHOICE3:
								hintCounter = 252;
								hintEnd = 258;
								hintChoices(hintCounter, hintEnd, userStepChoice, stepVector, hintVector);
								break;
							}
							break;
						case MENUCHOICE14: // The Fallen.
										   // Set the amount of steps, then give the userQuestChoice, STEPS, questVector, and stepVector to the steps function.
							STEPS = 8;
							startSteps = 65;
							stepChoices(userQuestChoice, STEPS, startSteps, questVector, stepVector);

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
								hintCounter = 260;
								hintEnd = 262;
								hintChoices(hintCounter, hintEnd, userStepChoice, stepVector, hintVector);
								break;
							case MENUCHOICE3:
								hintCounter = 262;
								hintEnd = 263;
								hintChoices(hintCounter, hintEnd, userStepChoice, stepVector, hintVector);
								break;
							case MENUCHOICE4:
								hintCounter = 263;
								hintEnd = 266;
								hintChoices(hintCounter, hintEnd, userStepChoice, stepVector, hintVector);
								break;
							case MENUCHOICE5:
								hintCounter = 266;
								hintEnd = 268;
								hintChoices(hintCounter, hintEnd, userStepChoice, stepVector, hintVector);
								break;
							case MENUCHOICE6:
								hintCounter = 268;
								hintEnd = 270;
								hintChoices(hintCounter, hintEnd, userStepChoice, stepVector, hintVector);
								break;
							case MENUCHOICE7:
								hintCounter = 270;
								hintEnd = 273;
								hintChoices(hintCounter, hintEnd, userStepChoice, stepVector, hintVector);
								break;
							case MENUCHOICE8:
								hintCounter = 273;
								hintEnd = 274;
								hintChoices(hintCounter, hintEnd, userStepChoice, stepVector, hintVector);
								break;
							}
							break;
						case MENUCHOICE15: // Paarthurnax.
										   // Set the amount of steps, then give the userQuestChoice, STEPS, questVector, and stepVector to the steps function.
							STEPS = 2;
							startSteps = 73;
							stepChoices(userQuestChoice, STEPS, startSteps, questVector, stepVector);

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
								hintCounter = 277;
								hintEnd = 278;
								hintChoices(hintCounter, hintEnd, userStepChoice, stepVector, hintVector);
								break;
							}
							break;
						case MENUCHOICE16: // Season Unending.
										   // Set the amount of steps, then give the userQuestChoice, STEPS, questVector, and stepVector to the steps function.
							STEPS = 6;
							startSteps = 75;
							stepChoices(userQuestChoice, STEPS, startSteps, questVector, stepVector);

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
								hintCounter = 281;
								hintEnd = 284;
								hintChoices(hintCounter, hintEnd, userStepChoice, stepVector, hintVector);
								break;
							case MENUCHOICE3:
								hintCounter = 284;
								hintEnd = 288;
								hintChoices(hintCounter, hintEnd, userStepChoice, stepVector, hintVector);
								break;
							case MENUCHOICE4:
								hintCounter = 288;
								hintEnd = 289;
								hintChoices(hintCounter, hintEnd, userStepChoice, stepVector, hintVector);
								break;
							case MENUCHOICE5:
								hintCounter = 289;
								hintEnd = 290;
								hintChoices(hintCounter, hintEnd, userStepChoice, stepVector, hintVector);
								break;
							case MENUCHOICE6:
								hintCounter = 290;
								hintEnd = 292;
								hintChoices(hintCounter, hintEnd, userStepChoice, stepVector, hintVector);
								break;
							}
							break;
						case MENUCHOICE17: // The World-Eater's Eyrie.
										   // Set the amount of steps, then give the userQuestChoice, STEPS, questVector, and stepVector to the steps function.
							STEPS = 4;
							startSteps = 81;
							stepChoices(userQuestChoice, STEPS, startSteps, questVector, stepVector);

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
								hintCounter = 294;
								hintEnd = 295;
								hintChoices(hintCounter, hintEnd, userStepChoice, stepVector, hintVector);
								break;
							case MENUCHOICE3:
								hintCounter = 295;
								hintEnd = 301;
								hintChoices(hintCounter, hintEnd, userStepChoice, stepVector, hintVector);
								break;
							case MENUCHOICE4:
								hintCounter = 301;
								hintEnd = 307;
								hintChoices(hintCounter, hintEnd, userStepChoice, stepVector, hintVector);
								break;
							}
							break;
						case MENUCHOICE18: // Sovngarde.
										   // Set the amount of steps, then give the userQuestChoice, STEPS, questVector, and stepVector to the steps function.
							STEPS = 3;
							startSteps = 85;
							stepChoices(userQuestChoice, STEPS, startSteps, questVector, stepVector);

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
								hintCounter = 308;
								hintEnd = 311;
								hintChoices(hintCounter, hintEnd, userStepChoice, stepVector, hintVector);
								break;
							case MENUCHOICE3:
								hintCounter = 311;
								hintEnd = 315;
								hintChoices(hintCounter, hintEnd, userStepChoice, stepVector, hintVector);
								break;
							}
							break;
						case MENUCHOICE19: // Dragonslayer.
										   // Set the amount of steps, then give the userQuestChoice, STEPS, questVector, and stepVector to the steps function.
							STEPS = 2;
							startSteps = 89;
							stepChoices(userQuestChoice, STEPS, startSteps, questVector, stepVector);

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
								hintCounter = 320;
								hintEnd = 324;
								hintChoices(hintCounter, hintEnd, userStepChoice, stepVector, hintVector);
								break;
							}
							break;
						}

					} while (userStepChoice != MENUCHOICE0); // While the user's choice isn't 0.
				}
				if (userCategoryChoice == 2) // SIDE QUEST MAIN STARTS HERE ***********************************************
				{
					categoryChoices(userCategoryChoice, questVector); // Get the categories

					cin >> userQuestChoice;	// Set user's input to userQuestChoice.
					cout << "- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -" << endl; // Space for output.

					do
					{
						int STEPS = 0;
						// Switch statement to take the user input and print the appropriate steps.
						switch (userQuestChoice)
						{
						case MENUCHOICE1: // The Blessings of Nature.
										  // Set the amount of steps, then give the userQuestChoice, STEPS, questVector, and stepVector to the steps function.
							STEPS = 6;
							startSteps = 90;
							stepChoices(userQuestChoice + sideQuestStepStarter, STEPS, startSteps, questVector, stepVector);
							cin >> userStepChoice; // Set user's input to userStepChoice.
												   // Switch statement to take the user input and print the appropriate hints.
							switch (userStepChoice)
							{
							case MENUCHOICE1:
								// Set the starting hint index, the ending hint index, and call the hint function with all the variables needed.
								hintCounter = 324;
								hintEnd = 328;
								hintChoices(hintCounter, hintEnd, userStepChoice + startSteps, stepVector, hintVector);
								break;
							case MENUCHOICE2:	// Bring NettleBane to Danica
								hintCounter = 328;
								hintEnd = 329;
								hintChoices(hintCounter, hintEnd, userStepChoice + startSteps, stepVector, hintVector);
								break;
							case MENUCHOICE3:	// Retrieve Eldergleam sap.
								hintCounter = 329;
								hintEnd = 335;
								hintChoices(hintCounter, hintEnd, userStepChoice + startSteps, stepVector, hintVector);
								break;
							case MENUCHOICE4:	// Follow Maurice.
								hintCounter = 335;
								hintEnd = 336;
								hintChoices(hintCounter, hintEnd, userStepChoice + startSteps, stepVector, hintVector);
								break;
							case MENUCHOICE5:	// Take sapling.
								hintCounter = 336;
								hintEnd = 337;
								hintChoices(hintCounter, hintEnd, userStepChoice + startSteps, stepVector, hintVector);
								break;
							case MENUCHOICE6:	// Return to Danica.
								hintCounter = 337;
								hintEnd = 341;
								hintChoices(hintCounter, hintEnd, userStepChoice + startSteps, stepVector, hintVector);
								break;
							}
							break;
						case MENUCHOICE2: // Blood on the Ice.
										  // Set the amount of steps, then give the userQuestChoice, STEPS, questVector, and stepVector to the steps function.
							STEPS = 15;
							startSteps = 96;
							stepChoices(userQuestChoice + sideQuestStepStarter, STEPS, startSteps, questVector, stepVector);
							cin >> userStepChoice; // Set user's input to userStepChoice.
												   // Switch statement to take the user input and print the appropriate hints.
							switch (userStepChoice)
							{
							case MENUCHOICE1:	// How can I get this quest 
								hintCounter = 341;
								hintEnd = 344;
								hintChoices(hintCounter, hintEnd, userStepChoice + startSteps, stepVector, hintVector);
								break;
							case MENUCHOICE2:	// Question the witnesses
								hintCounter = 344;
								hintEnd = 345;
								hintChoices(hintCounter, hintEnd, userStepChoice + startSteps, stepVector, hintVector);
								break;
							case MENUCHOICE3:	// Report to the guard.
								hintCounter = 345;
								hintEnd = 346;
								hintChoices(hintCounter, hintEnd, userStepChoice + startSteps, stepVector, hintVector);
								break;
							case MENUCHOICE4:	// Talk to Jorleif
								hintCounter = 346;
								hintEnd = 347;
								hintChoices(hintCounter, hintEnd, userStepChoice + startSteps, stepVector, hintVector);
								break;
							case MENUCHOICE5:	// Get assistance from Jorleif
								hintCounter = 347;
								hintEnd = 348;
								hintChoices(hintCounter, hintEnd, userStepChoice + startSteps, stepVector, hintVector);
								break;
							case MENUCHOICE6:	// Examine the crime scene
								hintCounter = 348;
								hintEnd = 354;
								hintChoices(hintCounter, hintEnd, userStepChoice + startSteps, stepVector, hintVector);
								break;
							case MENUCHOICE7:
								hintCounter = 354;
								hintEnd = 360;
								hintChoices(hintCounter, hintEnd, userStepChoice + startSteps, stepVector, hintVector);
								break;
							case MENUCHOICE8:
								hintCounter = 360;
								hintEnd = 362;
								hintChoices(hintCounter, hintEnd, userStepChoice + startSteps, stepVector, hintVector);
								break;
							case MENUCHOICE9:
								hintCounter = 362;
								hintEnd = 369;
								hintChoices(hintCounter, hintEnd, userStepChoice + startSteps, stepVector, hintVector);
								break;
							case MENUCHOICE10:
								hintCounter = 369;
								hintEnd = 374;
								hintChoices(hintCounter, hintEnd, userStepChoice + startSteps, stepVector, hintVector);
								break;
							case MENUCHOICE11:
								hintCounter = 374;
								hintEnd = 378;
								hintChoices(hintCounter, hintEnd, userStepChoice + startSteps, stepVector, hintVector);
								break;
							case MENUCHOICE12:
								hintCounter = 378;
								hintEnd = 381;
								hintChoices(hintCounter, hintEnd, userStepChoice + startSteps, stepVector, hintVector);
								break;
							case MENUCHOICE13:
								hintCounter = 381;
								hintEnd = 384;
								hintChoices(hintCounter, hintEnd, userStepChoice + startSteps, stepVector, hintVector);
								break;
							case MENUCHOICE14:
								hintCounter = 384;
								hintEnd = 386;
								hintChoices(hintCounter, hintEnd, userStepChoice + startSteps, stepVector, hintVector);
								break;
							case MENUCHOICE15:
								hintCounter = 386;
								hintEnd = 388;
								hintChoices(hintCounter, hintEnd, userStepChoice + startSteps, stepVector, hintVector);
								break;
							}
							break;
						case MENUCHOICE3: // The Book of Love.
										  // Set the amount of steps, then give the userQuestChoice, STEPS, questVector, and stepVector to the steps function.
							STEPS = 14;
							startSteps = 111;
							stepChoices(userQuestChoice + sideQuestStepStarter, STEPS, startSteps, questVector, stepVector);

							cin >> userStepChoice; // Set user's input to userStepChoice.
												   // Switch statement to take the user input and print the appropriate hints.
							switch (userStepChoice)
							{
							case MENUCHOICE1:	// Talk to Fastred
								hintCounter = 388;
								hintEnd = 390;
								hintChoices(hintCounter, hintEnd, userStepChoice + startSteps, stepVector, hintVector);
								break;
							case MENUCHOICE2:	// Talk to Fastred's parents
								hintCounter = 390;
								hintEnd = 391;
								hintChoices(hintCounter, hintEnd, userStepChoice + startSteps, stepVector, hintVector);
								break;
							case MENUCHOICE3:	// Talk to Bassianus or Klimmek
								hintCounter = 391;
								hintEnd = 395;
								hintChoices(hintCounter, hintEnd, userStepChoice + startSteps, stepVector, hintVector);
								break;
							case MENUCHOICE4:	// Return to Dinya Balu.
								hintCounter = 395;
								hintEnd = 396;
								hintChoices(hintCounter, hintEnd, userStepChoice + startSteps, stepVector, hintVector);
								break;
							case MENUCHOICE5:	// Talk to Calcemo.
								hintCounter = 396;
								hintEnd = 399;
								hintChoices(hintCounter, hintEnd, userStepChoice + startSteps, stepVector, hintVector);
								break;
							case MENUCHOICE6:	// Get advice from Yngvar.
								hintCounter = 399;
								hintEnd = 401;
								hintChoices(hintCounter, hintEnd, userStepChoice + startSteps, stepVector, hintVector);
								break;
							case MENUCHOICE7:	// Deliver poem.
								hintCounter = 401;
								hintEnd = 403;
								hintChoices(hintCounter, hintEnd, userStepChoice + startSteps, stepVector, hintVector);
								break;
							case MENUCHOICE8:	// Deliver Faleen's letter.
								hintCounter = 403;
								hintEnd = 405;
								hintChoices(hintCounter, hintEnd, userStepChoice + startSteps, stepVector, hintVector);
								break;
							case MENUCHOICE9:	// Return to Dinya Balu.
								hintCounter = 405;
								hintEnd = 406;
								hintChoices(hintCounter, hintEnd, userStepChoice + startSteps, stepVector, hintVector);
								break;
							case MENUCHOICE10:	// Put on the Amulet of Mara.
								hintCounter = 406;
								hintEnd = 407;
								hintChoices(hintCounter, hintEnd, userStepChoice + startSteps, stepVector, hintVector);
								break;
							case MENUCHOICE11:	// Talk to the long - dead lover.
								hintCounter = 407;
								hintEnd = 409;
								hintChoices(hintCounter, hintEnd, userStepChoice + startSteps, stepVector, hintVector);
								break;
							case MENUCHOICE12:	// Find Fenrig.
								hintCounter = 409;
								hintEnd = 411;
								hintChoices(hintCounter, hintEnd, userStepChoice + startSteps, stepVector, hintVector);
								break;
							case MENUCHOICE13:	// Bring Fenrig to Ruki.
								hintCounter = 411;
								hintEnd = 413;
								hintChoices(hintCounter, hintEnd, userStepChoice + startSteps, stepVector, hintVector);
								break;
							case MENUCHOICE14:	// Return to Dinya Balu.
								hintCounter = 413;
								hintEnd = 414;
								hintChoices(hintCounter, hintEnd, userStepChoice + startSteps, stepVector, hintVector);
								break;
							}
							break;
						case MENUCHOICE4: // Delayed Burial.
										  // Set the amount of steps, then give the userQuestChoice, STEPS, questVector, and stepVector to the steps function.
							STEPS = 1;
							startSteps = 126;
							stepChoices(userQuestChoice + sideQuestStepStarter, STEPS, startSteps, questVector, stepVector);

							cin >> userStepChoice; // Set user's input to userStepChoice.
												   // Switch statement to take the user input and print the appropriate hints.
							switch (userStepChoice)
							{
							case MENUCHOICE1:
								hintCounter = 414;
								hintEnd = 420;
								hintChoices(hintCounter, hintEnd, userStepChoice + startSteps, stepVector, hintVector);
								break;
							}
							break;
						case MENUCHOICE5: // Forbidden Legend.
										  // Set the amount of steps, then give the userQuestChoice, STEPS, questVector, and stepVector to the steps function.
							STEPS = 8;
							startSteps = 127;
							stepChoices(userQuestChoice + sideQuestStepStarter, STEPS, startSteps, questVector, stepVector);

							cin >> userStepChoice; // Set user's input to userStepChoice.
												   // Switch statement to take the user input and print the appropriate hints.
							switch (userStepChoice)
							{
							case MENUCHOICE1:
								hintCounter = 420;
								hintEnd = 422;
								hintChoices(hintCounter, hintEnd, userStepChoice + startSteps, stepVector, hintVector);
								break;
							case MENUCHOICE2:
								hintCounter = 422;
								hintEnd = 428;
								hintChoices(hintCounter, hintEnd, userStepChoice + startSteps, stepVector, hintVector);
								break;
							case MENUCHOICE3:
								hintCounter = 428;
								hintEnd = 429;
								hintChoices(hintCounter, hintEnd, userStepChoice + startSteps, stepVector, hintVector);
								break;
							case MENUCHOICE4:
								hintCounter = 429;
								hintEnd = 437;
								hintChoices(hintCounter, hintEnd, userStepChoice + startSteps, stepVector, hintVector);
								break;
							case MENUCHOICE5:
								hintCounter = 437;
								hintEnd = 447;
								hintChoices(hintCounter, hintEnd, userStepChoice + startSteps, stepVector, hintVector);
								break;
							case MENUCHOICE6:
								hintCounter = 447;
								hintEnd = 448;
								hintChoices(hintCounter, hintEnd, userStepChoice + startSteps, stepVector, hintVector);
								break;
							case MENUCHOICE7:
								hintCounter = 448;
								hintEnd = 454;
								hintChoices(hintCounter, hintEnd, userStepChoice + startSteps, stepVector, hintVector);
								break;
							case MENUCHOICE8:
								hintCounter = 454;
								hintEnd = 457;
								hintChoices(hintCounter, hintEnd, userStepChoice + startSteps, stepVector, hintVector);
								break;
							}
							break;
						case MENUCHOICE6: // The Forsworn Conspiracy.
										  // Set the amount of steps, then give the userQuestChoice, STEPS, questVector, and stepVector to the steps function.
							STEPS = 13;
							startSteps = 135;
							stepChoices(userQuestChoice + sideQuestStepStarter, STEPS, startSteps, questVector, stepVector);

							cin >> userStepChoice; // Set user's input to userStepChoice.
												   // Switch statement to take the user input and print the appropriate hints.
							switch (userStepChoice)
							{
							case MENUCHOICE1:
								hintCounter = 457;
								hintEnd = 461;
								hintChoices(hintCounter, hintEnd, userStepChoice + startSteps, stepVector, hintVector);
								break;
							case MENUCHOICE2:
								hintCounter = 461;
								hintEnd = 464;
								hintChoices(hintCounter, hintEnd, userStepChoice + startSteps, stepVector, hintVector);
								break;
							case MENUCHOICE3:
								hintCounter = 464;
								hintEnd = 469;
								hintChoices(hintCounter, hintEnd, userStepChoice + startSteps, stepVector, hintVector);
								break;
							case MENUCHOICE4:
								hintCounter = 469;
								hintEnd = 472;
								hintChoices(hintCounter, hintEnd, userStepChoice + startSteps, stepVector, hintVector);
								break;
							case MENUCHOICE5:
								hintCounter = 472;
								hintEnd = 475;
								hintChoices(hintCounter, hintEnd, userStepChoice + startSteps, stepVector, hintVector);
								break;
							case MENUCHOICE6:
								hintCounter = 475;
								hintEnd = 476;
								hintChoices(hintCounter, hintEnd, userStepChoice + startSteps, stepVector, hintVector);
								break;
							case MENUCHOICE7:
								hintCounter = 476;
								hintEnd = 484;
								hintChoices(hintCounter, hintEnd, userStepChoice + startSteps, stepVector, hintVector);
								break;
							case MENUCHOICE8:
								hintCounter = 484;
								hintEnd = 485;
								hintChoices(hintCounter, hintEnd, userStepChoice + startSteps, stepVector, hintVector);
								break;
							case MENUCHOICE9:
								hintCounter = 485;
								hintEnd = 489;
								hintChoices(hintCounter, hintEnd, userStepChoice + startSteps, stepVector, hintVector);
								break;
							case MENUCHOICE10:
								hintCounter = 489;
								hintEnd = 490;
								hintChoices(hintCounter, hintEnd, userStepChoice + startSteps, stepVector, hintVector);
								break;
							case MENUCHOICE11:
								hintCounter = 490;
								hintEnd = 494;
								hintChoices(hintCounter, hintEnd, userStepChoice + startSteps, stepVector, hintVector);
								break;
							case MENUCHOICE12:
								hintCounter = 494;
								hintEnd = 502;
								hintChoices(hintCounter, hintEnd, userStepChoice + startSteps, stepVector, hintVector);
								break;
							case MENUCHOICE13:
								hintCounter = 502;
								hintEnd = 503;
								hintChoices(hintCounter, hintEnd, userStepChoice + startSteps, stepVector, hintVector);
								break;
							}
							break;
						case MENUCHOICE7: // The Golden Claw.
										  // Set the amount of steps, then give the userQuestChoice, STEPS, questVector, and stepVector to the steps function.
							STEPS = 1;
							startSteps = 148;
							stepChoices(userQuestChoice + sideQuestStepStarter, STEPS, startSteps, questVector, stepVector);

							cin >> userStepChoice; // Set user's input to userStepChoice.
												   // Switch statement to take the user input and print the appropriate hints.
							switch (userStepChoice)
							{
							case MENUCHOICE1:
								hintCounter = 503;
								hintEnd = 506;
								hintChoices(hintCounter, hintEnd, userStepChoice + startSteps, stepVector, hintVector);
								break;
							}
							break;
						case MENUCHOICE8: // The Heart of Dibella.
										  // Set the amount of steps, then give the userQuestChoice, STEPS, questVector, and stepVector to the steps function.
							STEPS = 5;
							startSteps = 149;
							stepChoices(userQuestChoice + sideQuestStepStarter, STEPS, startSteps, questVector, stepVector);

							cin >> userStepChoice; // Set user's input to userStepChoice.
												   // Switch statement to take the user input and print the appropriate hints.
							switch (userStepChoice)
							{
							case MENUCHOICE1:	// How can I get this quest ?
								hintCounter = 506;
								hintEnd = 511;
								hintChoices(hintCounter, hintEnd, userStepChoice + startSteps, stepVector, hintVector);
								break;
							case MENUCHOICE2:	// Find the future Sybil of Dibella.
								hintCounter = 511;
								hintEnd = 515;
								hintChoices(hintCounter, hintEnd, userStepChoice + startSteps, stepVector, hintVector);
								break;
							case MENUCHOICE3:	// Rescue Fjotra from the Forsworn.
								hintCounter = 515;
								hintEnd = 524;
								hintChoices(hintCounter, hintEnd, userStepChoice + startSteps, stepVector, hintVector);
								break;
							case MENUCHOICE4:	// Bring Fjotra to the Temple.
								hintCounter = 524;
								hintEnd = 527;
								hintChoices(hintCounter, hintEnd, userStepChoice + startSteps, stepVector, hintVector);
								break;
							case MENUCHOICE5:	// Pray at Dibella's Altar.
								hintCounter = 527;
								hintEnd = 528;
								hintChoices(hintCounter, hintEnd, userStepChoice + startSteps, stepVector, hintVector);
								break;
							}
							break;
						case MENUCHOICE9: // In My Time of Need.
										  // Set the amount of steps, then give the userQuestChoice, STEPS, questVector, and stepVector to the steps function.
							STEPS = 8;
							startSteps = 154;
							stepChoices(userQuestChoice + sideQuestStepStarter, STEPS, startSteps, questVector, stepVector);

							cin >> userStepChoice; // Set user's input to userStepChoice.
												   // Switch statement to take the user input and print the appropriate hints.
							switch (userStepChoice)
							{
							case MENUCHOICE1:
								hintCounter = 528;
								hintEnd = 531;
								hintChoices(hintCounter, hintEnd, userStepChoice + startSteps, stepVector, hintVector);
								break;
							case MENUCHOICE2:
								hintCounter = 531;
								hintEnd = 533;
								hintChoices(hintCounter, hintEnd, userStepChoice + startSteps, stepVector, hintVector);
								break;
							case MENUCHOICE3:
								hintCounter = 533;
								hintEnd = 538;
								hintChoices(hintCounter, hintEnd, userStepChoice + startSteps, stepVector, hintVector);
								break;
							case MENUCHOICE4:
								hintCounter = 538;
								hintEnd = 544;
								hintChoices(hintCounter, hintEnd, userStepChoice + startSteps, stepVector, hintVector);
								break;
							case MENUCHOICE5:
								hintCounter = 544;
								hintEnd = 550;
								hintChoices(hintCounter, hintEnd, userStepChoice + startSteps, stepVector, hintVector);
								break;
							case MENUCHOICE6:
								hintCounter = 550;
								hintEnd = 551;
								hintChoices(hintCounter, hintEnd, userStepChoice + startSteps, stepVector, hintVector);
								break;
							case MENUCHOICE7:
								hintCounter = 551;
								hintEnd = 555;
								hintChoices(hintCounter, hintEnd, userStepChoice + startSteps, stepVector, hintVector);
								break;
							case MENUCHOICE8:
								hintCounter = 555;
								hintEnd = 556;
								hintChoices(hintCounter, hintEnd, userStepChoice + startSteps, stepVector, hintVector);
								break;
							}
							break;
						case MENUCHOICE10: // Kyne's Sacred Trials.
										   // Set the amount of steps, then give the userQuestChoice, STEPS, questVector, and stepVector to the steps function.
							STEPS = 10;
							startSteps = 162;
							stepChoices(userQuestChoice + sideQuestStepStarter, STEPS, startSteps, questVector, stepVector);

							cin >> userStepChoice; // Set user's input to userStepChoice.
												   // Switch statement to take the user input and print the appropriate hints.
							switch (userStepChoice)
							{
							case MENUCHOICE1:	//Defeat the Guardian Mudcrab.
								hintCounter = 556;
								hintEnd = 558;
								hintChoices(hintCounter, hintEnd, userStepChoice + startSteps, stepVector, hintVector);
								break;
							case MENUCHOICE2:	// Defeat the Guardian Skeever
								hintCounter = 558;
								hintEnd = 560;
								hintChoices(hintCounter, hintEnd, userStepChoice + startSteps, stepVector, hintVector);
								break;
							case MENUCHOICE3:	// Defeat the Guardian Wolf.
								hintCounter = 560;
								hintEnd = 562;
								hintChoices(hintCounter, hintEnd, userStepChoice + startSteps, stepVector, hintVector);
								break;
							case MENUCHOICE4:	// Return to Froki..
								hintCounter = 562;
								hintEnd = 563;
								hintChoices(hintCounter, hintEnd, userStepChoice + startSteps, stepVector, hintVector);
								break;
							case MENUCHOICE5:	// Defeat the Guardian Bear.
								hintCounter = 563;
								hintEnd = 566;
								hintChoices(hintCounter, hintEnd, userStepChoice + startSteps, stepVector, hintVector);
								break;
							case MENUCHOICE6:	// Defeat the Guardian Mammoth.
								hintCounter = 566;
								hintEnd = 569;
								hintChoices(hintCounter, hintEnd, userStepChoice + startSteps, stepVector, hintVector);
								break;
							case MENUCHOICE7:	// Defeat the Guardian Sabre Cat.
								hintCounter = 569;
								hintEnd = 572;
								hintChoices(hintCounter, hintEnd, userStepChoice + startSteps, stepVector, hintVector);
								break;
							case MENUCHOICE8:	// Return to Froki.
								hintCounter = 572;
								hintEnd = 573;
								hintChoices(hintCounter, hintEnd, userStepChoice + startSteps, stepVector, hintVector);
								break;
							case MENUCHOICE9:	// Defeat the Guardian Troll.
								hintCounter = 573;
								hintEnd = 579;
								hintChoices(hintCounter, hintEnd, userStepChoice + startSteps, stepVector, hintVector);
								break;
							case MENUCHOICE10:	// Return to Froki.
								hintCounter = 579;
								hintEnd = 581;
								hintChoices(hintCounter, hintEnd, userStepChoice + startSteps, stepVector, hintVector);
								break;
							}
							break;
						case MENUCHOICE11: // Laid to Rest.
										   // Set the amount of steps, then give the userQuestChoice, STEPS, questVector, and stepVector to the steps function.
							STEPS = 8;
							startSteps = 172;
							stepChoices(userQuestChoice + sideQuestStepStarter, STEPS, startSteps, questVector, stepVector);

							cin >> userStepChoice; // Set user's input to userStepChoice.
												   // Switch statement to take the user input and print the appropriate hints.
							switch (userStepChoice)
							{
							case MENUCHOICE1:	// Talk to the Jarl.
								hintCounter = 581;
								hintEnd = 582;
								hintChoices(hintCounter, hintEnd, userStepChoice + startSteps, stepVector, hintVector);
								break;
							case MENUCHOICE2:	// Investigate the burned house.
								hintCounter = 582;
								hintEnd = 584;
								hintChoices(hintCounter, hintEnd, userStepChoice + startSteps, stepVector, hintVector);
								break;
							case MENUCHOICE3:	// Find Helgi after dark.
								hintCounter = 584;
								hintEnd = 588;
								hintChoices(hintCounter, hintEnd, userStepChoice + startSteps, stepVector, hintVector);
								break;
							case MENUCHOICE4:	// Ask Thonnir about Laelette.
								hintCounter = 588;
								hintEnd = 589;
								hintChoices(hintCounter, hintEnd, userStepChoice + startSteps, stepVector, hintVector);
								break;
							case MENUCHOICE5:	// Investigate Alva's house.
								hintCounter = 589;
								hintEnd = 595;
								hintChoices(hintCounter, hintEnd, userStepChoice + startSteps, stepVector, hintVector);
								break;
							case MENUCHOICE6:	// Show Alva's Journal to the Jarl.
								hintCounter = 595;
								hintEnd = 596;
								hintChoices(hintCounter, hintEnd, userStepChoice + startSteps, stepVector, hintVector);
								break;
							case MENUCHOICE7:	// Kill the master vampire.
								hintCounter = 596;
								hintEnd = 604;
								hintChoices(hintCounter, hintEnd, userStepChoice + startSteps, stepVector, hintVector);
								break;
							case MENUCHOICE8:	// Return to Morthal's Jarl.
								hintCounter = 604;
								hintEnd = 606;
								hintChoices(hintCounter, hintEnd, userStepChoice + startSteps, stepVector, hintVector);
								break;
							}
							break;
						case MENUCHOICE12: // Lights Out!
										   // Set the amount of steps, then give the userQuestChoice, STEPS, questVector, and stepVector to the steps function.
							STEPS = 7;
							startSteps = 180;
							stepChoices(userQuestChoice + sideQuestStepStarter, STEPS, startSteps, questVector, stepVector);

							cin >> userStepChoice; // Set user's input to userStepChoice.
												   // Switch statement to take the user input and print the appropriate hints.
							switch (userStepChoice)
							{
							case MENUCHOICE1:
								hintCounter = 606;
								hintEnd = 609;
								hintChoices(hintCounter, hintEnd, userStepChoice + startSteps, stepVector, hintVector);
								break;
							case MENUCHOICE2:
								hintCounter = 609;
								hintEnd = 611;
								hintChoices(hintCounter, hintEnd, userStepChoice + startSteps, stepVector, hintVector);
								break;
							case MENUCHOICE3:
								hintCounter = 611;
								hintEnd = 616;
								hintChoices(hintCounter, hintEnd, userStepChoice + startSteps, stepVector, hintVector);
								break;
							case MENUCHOICE4:
								hintCounter = 616;
								hintEnd = 618;
								hintChoices(hintCounter, hintEnd, userStepChoice + startSteps, stepVector, hintVector);
								break;
							case MENUCHOICE5:
								hintCounter = 618;
								hintEnd = 620;
								hintChoices(hintCounter, hintEnd, userStepChoice + startSteps, stepVector, hintVector);
								break;
							case MENUCHOICE6:
								hintCounter = 620;
								hintEnd = 623;
								hintChoices(hintCounter, hintEnd, userStepChoice + startSteps, stepVector, hintVector);
								break;
							case MENUCHOICE7:
								hintCounter = 623;
								hintEnd = 629;
								hintChoices(hintCounter, hintEnd, userStepChoice + startSteps, stepVector, hintVector);
								break;
							}
							break;
						case MENUCHOICE13: // The Man Who Cried Wolf.
										   // Set the amount of steps, then give the userQuestChoice, STEPS, questVector, and stepVector to the steps function.
							STEPS = 2;
							startSteps = 187;
							stepChoices(userQuestChoice + sideQuestStepStarter, STEPS, startSteps, questVector, stepVector);

							cin >> userStepChoice; // Set user's input to userStepChoice.
												   // Switch statement to take the user input and print the appropriate hints.
							switch (userStepChoice)
							{
							case MENUCHOICE1:	// Clear out Wolfskull Cave.
								hintCounter = 629;
								hintEnd = 638;
								hintChoices(hintCounter, hintEnd, userStepChoice + startSteps, stepVector, hintVector);
								break;
							case MENUCHOICE2:	// Speak to Falk Firebeard.
								hintCounter = 638;
								hintEnd = 642;
								hintChoices(hintCounter, hintEnd, userStepChoice + startSteps, stepVector, hintVector);
								break;
							}
							break;
						case MENUCHOICE14: // Missing in Action.
										   // Set the amount of steps, then give the userQuestChoice, STEPS, questVector, and stepVector to the steps function.
							STEPS = 9;
							startSteps = 189;
							stepChoices(userQuestChoice + sideQuestStepStarter, STEPS, startSteps, questVector, stepVector);

							cin >> userStepChoice; // Set user's input to userStepChoice.
												   // Switch statement to take the user input and print the appropriate hints.
							switch (userStepChoice)
							{
							case MENUCHOICE1:
								hintCounter = 642;
								hintEnd = 643;
								hintChoices(hintCounter, hintEnd, userStepChoice + startSteps, stepVector, hintVector);
								break;
							case MENUCHOICE2:
								hintCounter = 643;
								hintEnd = 647;
								hintChoices(hintCounter, hintEnd, userStepChoice + startSteps, stepVector, hintVector);
								break;
							case MENUCHOICE3:
								hintCounter = 647;
								hintEnd = 650;
								hintChoices(hintCounter, hintEnd, userStepChoice + startSteps, stepVector, hintVector);
								break;
							case MENUCHOICE4:
								hintCounter = 650;
								hintEnd = 653;
								hintChoices(hintCounter, hintEnd, userStepChoice + startSteps, stepVector, hintVector);
								break;
							case MENUCHOICE5:
								hintCounter = 653;
								hintEnd = 655;
								hintChoices(hintCounter, hintEnd, userStepChoice + startSteps, stepVector, hintVector);
								break;
							case MENUCHOICE6:
								hintCounter = 655;
								hintEnd = 663;
								hintChoices(hintCounter, hintEnd, userStepChoice + startSteps, stepVector, hintVector);
								break;
							case MENUCHOICE7:
								hintCounter = 663;
								hintEnd = 670;
								hintChoices(hintCounter, hintEnd, userStepChoice + startSteps, stepVector, hintVector);
							case MENUCHOICE8:
								hintCounter = 670;
								hintEnd = 671;
								hintChoices(hintCounter, hintEnd, userStepChoice + startSteps, stepVector, hintVector);
							case MENUCHOICE9:
								hintCounter = 671;
								hintEnd = 672;
								hintChoices(hintCounter, hintEnd, userStepChoice + startSteps, stepVector, hintVector);
								break;
							}
							break;
						case MENUCHOICE15: // No One Escapes Cidhna Mine.
										   // Set the amount of steps, then give the userQuestChoice, STEPS, questVector, and stepVector to the steps function.
							STEPS = 12;
							startSteps = 198;
							stepChoices(userQuestChoice + sideQuestStepStarter, STEPS, startSteps, questVector, stepVector);

							cin >> userStepChoice; // Set user's input to userStepChoice.
												   // Switch statement to take the user input and print the appropriate hints.
							switch (userStepChoice)
							{
							case MENUCHOICE1:	// Ask a prisoner about Madanach.
								hintCounter = 672;
								hintEnd = 674;
								hintChoices(hintCounter, hintEnd, userStepChoice + startSteps, stepVector, hintVector);
								break;
							case MENUCHOICE2:	// Get past Borkul the Beast.
								hintCounter = 674;
								hintEnd = 679;
								hintChoices(hintCounter, hintEnd, userStepChoice + startSteps, stepVector, hintVector);
								break;
							case MENUCHOICE3:	// Talk to Madanach.
								hintCounter = 679;
								hintEnd = 681;
								hintChoices(hintCounter, hintEnd, userStepChoice + startSteps, stepVector, hintVector);
								break;
							case MENUCHOICE4:	// Hear Braig's story.
								hintCounter = 681;
								hintEnd = 683;
								hintChoices(hintCounter, hintEnd, userStepChoice + startSteps, stepVector, hintVector);
								break;
							case MENUCHOICE5:	// Return to Madanach.
								hintCounter = 683;
								hintEnd = 684;
								hintChoices(hintCounter, hintEnd, userStepChoice + startSteps, stepVector, hintVector);
								break;
							case MENUCHOICE6:	// Kill Grisvar the Unlucky.
								hintCounter = 684;
								hintEnd = 689;
								hintChoices(hintCounter, hintEnd, userStepChoice + startSteps, stepVector, hintVector);
								break;
							case MENUCHOICE7:	// Return to Madanach.
								hintCounter = 689;
								hintEnd = 690;
								hintChoices(hintCounter, hintEnd, userStepChoice + startSteps, stepVector, hintVector);
								break;
							case MENUCHOICE8:	// Follow Madanach.
								hintCounter = 690;
								hintEnd = 697;
								hintChoices(hintCounter, hintEnd, userStepChoice + startSteps, stepVector, hintVector);
							case MENUCHOICE9:	// Kill Madanach.
								hintCounter = 697;
								hintEnd = 699;
								hintChoices(hintCounter, hintEnd, userStepChoice + startSteps, stepVector, hintVector);
								break;
							case MENUCHOICE10:	// Search Madanach's body.
								hintCounter = 699;
								hintEnd = 700;
								hintChoices(hintCounter, hintEnd, userStepChoice + startSteps, stepVector, hintVector);
								break;
							case MENUCHOICE11:	// Read Madanach's note.
								hintCounter = 700;
								hintEnd = 701;
								hintChoices(hintCounter, hintEnd, userStepChoice + startSteps, stepVector, hintVector);
							case MENUCHOICE12:	// Escape Cidhna Mine.
								hintCounter = 701;
								hintEnd = 709;
								hintChoices(hintCounter, hintEnd, userStepChoice + startSteps, stepVector, hintVector);
								break;
							}
							break;
						case MENUCHOICE16: // Promises to Keep.
										   // Set the amount of steps, then give the userQuestChoice, STEPS, questVector, and stepVector to the steps function.
							STEPS = 5;
							startSteps = 210;
							stepChoices(userQuestChoice + sideQuestStepStarter, STEPS, startSteps, questVector, stepVector);

							cin >> userStepChoice; // Set user's input to userStepChoice.
												   // Switch statement to take the user input and print the appropriate hints.
							switch (userStepChoice)
							{
							case MENUCHOICE1:	// Speak to Sibbi Black - Briar.
								hintCounter = 709;
								hintEnd = 713;
								hintChoices(hintCounter, hintEnd, userStepChoice + startSteps, stepVector, hintVector);
								break;
							case MENUCHOICE2:	// Speak to Sibbi Black - Briar.
								hintCounter = 713;
								hintEnd = 718;
								hintChoices(hintCounter, hintEnd, userStepChoice + startSteps, stepVector, hintVector);
								break;
							case MENUCHOICE3:	// (Optional)Steal the Lodge Stash.
								hintCounter = 718;
								hintEnd = 719;
								hintChoices(hintCounter, hintEnd, userStepChoice + startSteps, stepVector, hintVector);
								break;
							case MENUCHOICE4:	// Steal Frost.
								hintCounter = 719;
								hintEnd = 721;
								hintChoices(hintCounter, hintEnd, userStepChoice + startSteps, stepVector, hintVector);
								break;
							case MENUCHOICE5:	// Return to Louis Letrush.
								hintCounter = 721;
								hintEnd = 727;
								hintChoices(hintCounter, hintEnd, userStepChoice + startSteps, stepVector, hintVector);
								break;
							}
							break;
						case MENUCHOICE17: // Repairing the Phial.
										   // Set the amount of steps, then give the userQuestChoice, STEPS, questVector, and stepVector to the steps function.
							STEPS = 5;
							startSteps = 215;
							stepChoices(userQuestChoice + sideQuestStepStarter, STEPS, startSteps, questVector, stepVector);

							cin >> userStepChoice; // Set user's input to userStepChoice.
												   // Switch statement to take the user input and print the appropriate hints.
							switch (userStepChoice)
							{
							case MENUCHOICE1:	// Return to Louis Letrush.
								hintCounter = 727;
								hintEnd = 728;
								hintChoices(hintCounter, hintEnd, userStepChoice + startSteps, stepVector, hintVector);
								break;
							case MENUCHOICE2:	// Return to Louis Letrush.
								hintCounter = 728;
								hintEnd = 730;
								hintChoices(hintCounter, hintEnd, userStepChoice + startSteps, stepVector, hintVector);
								break;
							case MENUCHOICE3:	// Return to Louis Letrush.
								hintCounter = 730;
								hintEnd = 733;
								hintChoices(hintCounter, hintEnd, userStepChoice + startSteps, stepVector, hintVector);
								break;
							case MENUCHOICE4:	// Return to Louis Letrush.
								hintCounter = 733;
								hintEnd = 736;
								hintChoices(hintCounter, hintEnd, userStepChoice + startSteps, stepVector, hintVector);
								break;
							case MENUCHOICE5:	// Return to Louis Letrush.
								hintCounter = 736;
								hintEnd = 741;
								hintChoices(hintCounter, hintEnd, userStepChoice + startSteps, stepVector, hintVector);
								break;
							}
							break;
						case MENUCHOICE18: // Rise in the East.
										   // Set the amount of steps, then give the userQuestChoice, STEPS, questVector, and stepVector to the steps function.
							STEPS = 10;
							startSteps = 220;
							stepChoices(userQuestChoice + sideQuestStepStarter, STEPS, startSteps, questVector, stepVector);

							cin >> userStepChoice; // Set user's input to userStepChoice.
												   // Switch statement to take the user input and print the appropriate hints.
							switch (userStepChoice)
							{
							case MENUCHOICE1:	// Steal Suvaris Atheron's logbook.
								hintCounter = 741;
								hintEnd = 744;
								hintChoices(hintCounter, hintEnd, userStepChoice + startSteps, stepVector, hintVector);
								break;
							case MENUCHOICE2:	// Give the logbook to Orthus.
								hintCounter = 744;
								hintEnd = 745;
								hintChoices(hintCounter, hintEnd, userStepChoice + startSteps, stepVector, hintVector);
								break;
							case MENUCHOICE3:	// Talk to Stig Salt - Plank.
								hintCounter = 745;
								hintEnd = 748;
								hintChoices(hintCounter, hintEnd, userStepChoice + startSteps, stepVector, hintVector);
								break;
							case MENUCHOICE4:	// Report back to Orthus.
								hintCounter = 748;
								hintEnd = 750;
								hintChoices(hintCounter, hintEnd, userStepChoice + startSteps, stepVector, hintVector);
								break;
							case MENUCHOICE5:	// Depart for Japhet's Folly.
								hintCounter = 750;
								hintEnd = 752;
								hintChoices(hintCounter, hintEnd, userStepChoice + startSteps, stepVector, hintVector);
								break;
							case MENUCHOICE6:	// Talk to Adelaisa.
								hintCounter = 752;
								hintEnd = 753;
								hintChoices(hintCounter, hintEnd, userStepChoice + startSteps, stepVector, hintVector);
								break;
							case MENUCHOICE7:	// Kill Haldyn.
								hintCounter = 753;
								hintEnd = 760;
								hintChoices(hintCounter, hintEnd, userStepChoice + startSteps, stepVector, hintVector);
								break;
							case MENUCHOICE8:	// Report back to Adelaisa.
								hintCounter = 760;
								hintEnd = 763;
								hintChoices(hintCounter, hintEnd, userStepChoice + startSteps, stepVector, hintVector);
								break;
							case MENUCHOICE9:	// Speak to Adelaisa to return.
								hintCounter = 763;
								hintEnd = 764;
								hintChoices(hintCounter, hintEnd, userStepChoice + startSteps, stepVector, hintVector);
								break;
							case MENUCHOICE10:	// Speak to Orthus.
								hintCounter = 764;
								hintEnd = 765;
								hintChoices(hintCounter, hintEnd, userStepChoice + startSteps, stepVector, hintVector);
								break;
							}
							break;
						case MENUCHOICE19: // Rising at Dawn.
										   // Set the amount of steps, then give the userQuestChoice, STEPS, questVector, and stepVector to the steps function.
							STEPS = 7;
							startSteps = 230;
							stepChoices(userQuestChoice + sideQuestStepStarter, STEPS, startSteps, questVector, stepVector);

							cin >> userStepChoice; // Set user's input to userStepChoice.
												   // Switch statement to take the user input and print the appropriate hints.
							switch (userStepChoice)
							{
							case MENUCHOICE1:	// How can I become a vampire ?
								hintCounter = 765;
								hintEnd = 769;
								hintChoices(hintCounter, hintEnd, userStepChoice + startSteps, stepVector, hintVector);
								break;
							case MENUCHOICE2:	// How do the stages of vampirism work ?
								hintCounter = 769;
								hintEnd = 773;
								hintChoices(hintCounter, hintEnd, userStepChoice + startSteps, stepVector, hintVector);
								break;
							case MENUCHOICE3:	// Speak to Falion.
								hintCounter = 773;
								hintEnd = 775;
								hintChoices(hintCounter, hintEnd, userStepChoice + startSteps, stepVector, hintVector);
								break;
							case MENUCHOICE4:	// Bring a filled Black Soul Gem to Morthal.
								hintCounter = 775;
								hintEnd = 781;
								hintChoices(hintCounter, hintEnd, userStepChoice + startSteps, stepVector, hintVector);
								break;
							case MENUCHOICE5:	// Meet Falion at dawn.
								hintCounter = 781;
								hintEnd = 783;
								hintChoices(hintCounter, hintEnd, userStepChoice + startSteps, stepVector, hintVector);
								break;
							case MENUCHOICE6:	// Speak to Falion.
								hintCounter = 783;
								hintEnd = 784;
								hintChoices(hintCounter, hintEnd, userStepChoice + startSteps, stepVector, hintVector);
								break;
							case MENUCHOICE7:	// Wait for Falion to complete the ritual.
								hintCounter = 784;
								hintEnd = 785;
								hintChoices(hintCounter, hintEnd, userStepChoice + startSteps, stepVector, hintVector);
								break;
							}
							break;
						case MENUCHOICE20: // Unfathomable Depths.
										   // Set the amount of steps, then give the userQuestChoice, STEPS, questVector, and stepVector to the steps function.
							STEPS = 1;
							startSteps = 237;
							stepChoices(userQuestChoice + sideQuestStepStarter, STEPS, startSteps, questVector, stepVector);

							cin >> userStepChoice; // Set user's input to userStepChoice.
												   // Switch statement to take the user input and print the appropriate hints.
							switch (userStepChoice)
							{
							case MENUCHOICE1:	// Wait for Falion to complete the ritual.
								hintCounter = 785;
								hintEnd = 789;
								hintChoices(hintCounter, hintEnd, userStepChoice + startSteps, stepVector, hintVector);
								break;
							}
							break;
						case MENUCHOICE21: // The White Phial.
										   // Set the amount of steps, then give the userQuestChoice, STEPS, questVector, and stepVector to the steps function.
							STEPS = 3;
							startSteps = 238;
							stepChoices(userQuestChoice + sideQuestStepStarter, STEPS, startSteps, questVector, stepVector);

							cin >> userStepChoice; // Set user's input to userStepChoice.
												   // Switch statement to take the user input and print the appropriate hints.
							switch (userStepChoice)
							{
							case MENUCHOICE1:	// Wait for Falion to complete the ritual.
								hintCounter = 789;
								hintEnd = 799;
								hintChoices(hintCounter, hintEnd, userStepChoice + startSteps, stepVector, hintVector);
								break;
							case MENUCHOICE2:	// Wait for Falion to complete the ritual.
								hintCounter = 799;
								hintEnd = 802;
								hintChoices(hintCounter, hintEnd, userStepChoice + startSteps, stepVector, hintVector);
								break;
							case MENUCHOICE3:	// Wait for Falion to complete the ritual.
								hintCounter = 802;
								hintEnd = 803;
								hintChoices(hintCounter, hintEnd, userStepChoice + startSteps, stepVector, hintVector);
								break;

							}
							break;
						case MENUCHOICE22: // The Wolf Queen Awakened.
										   // Set the amount of steps, then give the userQuestChoice, STEPS, questVector, and stepVector to the steps function.
							STEPS = 5;
							startSteps = 241;
							stepChoices(userQuestChoice + sideQuestStepStarter, STEPS, startSteps, questVector, stepVector);

							cin >> userStepChoice; // Set user's input to userStepChoice.
												   // Switch statement to take the user input and print the appropriate hints.
							switch (userStepChoice)
							{
							case MENUCHOICE1:	// Speak to Styrr.
								hintCounter = 803;
								hintEnd = 805;
								hintChoices(hintCounter, hintEnd, userStepChoice + startSteps, stepVector, hintVector);
								break;
							case MENUCHOICE2:	// Defeat Potema.
								hintCounter = 805;
								hintEnd = 809;
								hintChoices(hintCounter, hintEnd, userStepChoice + startSteps, stepVector, hintVector);
								break;
							case MENUCHOICE3:	// Retrieve Potema's remains.
								hintCounter = 809;
								hintEnd = 812;
								hintChoices(hintCounter, hintEnd, userStepChoice + startSteps, stepVector, hintVector);
								break;
							case MENUCHOICE4:	// Give Potema's remains to Styrr.
								hintCounter = 812;
								hintEnd = 816;
								hintChoices(hintCounter, hintEnd, userStepChoice + startSteps, stepVector, hintVector);
								break;
							case MENUCHOICE5:	// Return to Falk Firebeard.
								hintCounter = 816;
								hintEnd = 817;
								hintChoices(hintCounter, hintEnd, userStepChoice + startSteps, stepVector, hintVector);
								break;

							}
							break;
						}
					} while (userStepChoice != MENUCHOICE0); // While the user's choice isn't 0.
				}
				if (userCategoryChoice == 3) // DUNGEON QUEST MAIN STARTS HERE ***********************************************
				{
					categoryChoices(userCategoryChoice, questVector); // Get the categories.

					cin >> userQuestChoice;	// Set user's input to userQuestChoice.
					cout << "- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -" << endl; // Space for output.
					do
					{
						int STEPS = 0;
						// Switch statement to take the user input and print the appropriate steps.
						switch (userQuestChoice)
						{
						case MENUCHOICE1: // Ancestral Worship.
										  // Set the amount of steps, then give the userQuestChoice, STEPS, questVector, and stepVector to the steps function.
							STEPS = 3;
							startSteps = 246;
							stepChoices(userQuestChoice + dungeonQuestStepStarter, STEPS, startSteps, questVector, stepVector);

							cin >> userStepChoice; // Set user's input to userStepChoice.
												   // Switch statement to take the user input and print the appropriate hints.
							switch (userStepChoice)
							{
							case MENUCHOICE1:
								hintCounter = 817;
								hintEnd = 828;
								hintChoices(hintCounter, hintEnd, userStepChoice + startSteps, stepVector, hintVector);
								break;
							case MENUCHOICE2:
								hintCounter = 828;
								hintEnd = 829;
								hintChoices(hintCounter, hintEnd, userStepChoice + startSteps, stepVector, hintVector);
								break;
							case MENUCHOICE3:
								hintCounter = 829;
								hintEnd = 832;
								hintChoices(hintCounter, hintEnd, userStepChoice + startSteps, stepVector, hintVector);
								break;
							}
							break;
						case MENUCHOICE2: // Evil in Waiting.
										  // Set the amount of steps, then give the userQuestChoice, STEPS, questVector, and stepVector to the steps function.
							STEPS = 3;
							startSteps = 249;
							stepChoices(userQuestChoice + dungeonQuestStepStarter, STEPS, startSteps, questVector, stepVector);

							cin >> userStepChoice; // Set user's input to userStepChoice.
												   // Switch statement to take the user input and print the appropriate hints.
							switch (userStepChoice)
							{
							case MENUCHOICE1: // Collect the Vessels.
											  // Set the amount of steps, then give the userQuestChoice, STEPS, and additionalStepsVector to the additional steps function.
								STEPS = 3;
								startSteps = 8;
								userAdditionalChoice = additionalStepPrint(userStepChoice, STEPS, startSteps, additionalStepsVector);
								// Switch statement holding all the additional choices.
								switch (userAdditionalChoice)
								{
								case MENUCHOICE1:
									// Set the starting hint index, the ending hint index, and call the hint function with all the variables needed.
									hintCounter = 833;
									hintEnd = 841;
									hintChoices(hintCounter, hintEnd, userAdditionalChoice, additionalStepsVector, hintVector);
									break;
								case MENUCHOICE2:
									// Set the starting hint index, the ending hint index, and call the hint function with all the variables needed.
									hintCounter = 841;
									hintEnd = 847;
									hintChoices(hintCounter, hintEnd, userAdditionalChoice, additionalStepsVector, hintVector);
									break;
								case MENUCHOICE3:
									// Set the starting hint index, the ending hint index, and call the hint function with all the variables needed.
									hintCounter = 847;
									hintEnd = 852;
									hintChoices(hintCounter, hintEnd, userAdditionalChoice, additionalStepsVector, hintVector);
									break;
								}
								break;
							case MENUCHOICE2: // Perform the ritual with Valdar.
								hintCounter = 852;
								hintEnd = 858;
								hintChoices(hintCounter, hintEnd, userStepChoice + startSteps, stepVector, hintVector);
								break;
							case MENUCHOICE3: // Defeat Hevnoraak.
								hintCounter = 858;
								hintEnd = 860;
								hintChoices(hintCounter, hintEnd, userStepChoice + startSteps, stepVector, hintVector);
								break;
							}
							break;
						case MENUCHOICE3: // Infiltration.
										  // Set the amount of steps, then give the userQuestChoice, STEPS, questVector, and stepVector to the steps function.
							STEPS = 3;
							startSteps = 252;
							stepChoices(userQuestChoice + dungeonQuestStepStarter, STEPS, startSteps, questVector, stepVector);

							cin >> userStepChoice; // Set user's input to userStepChoice.
												   // Switch statement to take the user input and print the appropriate hints.
							switch (userStepChoice)
							{
							case MENUCHOICE1:
								hintCounter = 860;
								hintEnd = 862;
								hintChoices(hintCounter, hintEnd, userStepChoice + startSteps, stepVector, hintVector);
								break;
							case MENUCHOICE2:
								hintCounter = 862;
								hintEnd = 872;
								hintChoices(hintCounter, hintEnd, userStepChoice + startSteps, stepVector, hintVector);
								break;
							case MENUCHOICE3:
								hintCounter = 872;
								hintEnd = 874;
								hintChoices(hintCounter, hintEnd, userStepChoice + startSteps, stepVector, hintVector);
								break;
							}
							break;
						case MENUCHOICE4: // The Lost Expedition.
										  // Set the amount of steps, then give the userQuestChoice, STEPS, questVector, and stepVector to the steps function.
							STEPS = 6;
							startSteps = 255;
							stepChoices(userQuestChoice + dungeonQuestStepStarter, STEPS, startSteps, questVector, stepVector);

							cin >> userStepChoice; // Set user's input to userStepChoice.
												   // Switch statement to take the user input and print the appropriate hints.
							switch (userStepChoice)
							{
							case MENUCHOICE1:
								hintCounter = 874;
								hintEnd = 880;
								hintChoices(hintCounter, hintEnd, userStepChoice + startSteps, stepVector, hintVector);
								break;
							case MENUCHOICE2:
								hintCounter = 880;
								hintEnd = 885;
								hintChoices(hintCounter, hintEnd, userStepChoice + startSteps, stepVector, hintVector);
								break;
							case MENUCHOICE3:
								hintCounter = 885;
								hintEnd = 888;
								hintChoices(hintCounter, hintEnd, userStepChoice + startSteps, stepVector, hintVector);
								break;
							case MENUCHOICE4:
								hintCounter = 888;
								hintEnd = 891;
								hintChoices(hintCounter, hintEnd, userStepChoice + startSteps, stepVector, hintVector);
								break;
							case MENUCHOICE5:
								hintCounter = 891;
								hintEnd = 895;
								hintChoices(hintCounter, hintEnd, userStepChoice + startSteps, stepVector, hintVector);
								break;
							case MENUCHOICE6:
								hintCounter = 895;
								hintEnd = 900;
								hintChoices(hintCounter, hintEnd, userStepChoice + startSteps, stepVector, hintVector);
								break;
							}
							break;
						case MENUCHOICE5: // The Pale Lady.
										  // Set the amount of steps, then give the userQuestChoice, STEPS, questVector, and stepVector to the steps function.
							STEPS = 3;
							startSteps = 261;
							stepChoices(userQuestChoice + dungeonQuestStepStarter, STEPS, startSteps, questVector, stepVector);

							cin >> userStepChoice; // Set user's input to userStepChoice.
												   // Switch statement to take the user input and print the appropriate hints.
							switch (userStepChoice)
							{
							case MENUCHOICE1:
								hintCounter = 900;
								hintEnd = 904;
								hintChoices(hintCounter, hintEnd, userStepChoice + startSteps, stepVector, hintVector);
								break;
							case MENUCHOICE2:
								hintCounter = 904;
								hintEnd = 905;
								hintChoices(hintCounter, hintEnd, userStepChoice + startSteps, stepVector, hintVector);
								break;
							case MENUCHOICE3:
								hintCounter = 905;
								hintEnd = 911;
								hintChoices(hintCounter, hintEnd, userStepChoice + startSteps, stepVector, hintVector);
								break;
							case MENUCHOICE4:
								hintCounter = 911;
								hintEnd = 916;
								hintChoices(hintCounter, hintEnd, userStepChoice + startSteps, stepVector, hintVector);
								break;
							}
							break;
						case MENUCHOICE6: // Repentance.
										  // Set the amount of steps, then give the userQuestChoice, STEPS, questVector, and stepVector to the steps function.
							STEPS = 2;
							startSteps = 466;
							stepChoices(userQuestChoice + dungeonQuestStepStarter, STEPS, startSteps, questVector, stepVector);

							cin >> userStepChoice; // Set user's input to userStepChoice.
												   // Switch statement to take the user input and print the appropriate hints.
							switch (userStepChoice)
							{
							case MENUCHOICE1:
								hintCounter = 916;
								hintEnd = 923;
								hintChoices(hintCounter, hintEnd, userStepChoice + startSteps, stepVector, hintVector);
								break;
							case MENUCHOICE2:
								hintCounter = 923;
								hintEnd = 929;
								hintChoices(hintCounter, hintEnd, userStepChoice + startSteps, stepVector, hintVector);
								break;
							}
							break;
						case MENUCHOICE7: // A Return to Your Roots.
										  // Set the amount of steps, then give the userQuestChoice, STEPS, questVector, and stepVector to the steps function.
							STEPS = 3;
							startSteps = 268;
							stepChoices(userQuestChoice + dungeonQuestStepStarter, STEPS, startSteps, questVector, stepVector);

							cin >> userStepChoice; // Set user's input to userStepChoice.
												   // Switch statement to take the user input and print the appropriate hints.
							switch (userStepChoice)
							{
							case MENUCHOICE1:
								hintCounter = 929;
								hintEnd = 933;
								hintChoices(hintCounter, hintEnd, userStepChoice + startSteps, stepVector, hintVector);
								break;
							case MENUCHOICE2:
								hintCounter = 933;
								hintEnd = 937;
								hintChoices(hintCounter, hintEnd, userStepChoice + startSteps, stepVector, hintVector);
								break;
							case MENUCHOICE3:
								hintCounter = 937;
								hintEnd = 939;
								hintChoices(hintCounter, hintEnd, userStepChoice + startSteps, stepVector, hintVector);
								break;
							}
							break;
						case MENUCHOICE8: // A Scroll for Anska.
										  // Set the amount of steps, then give the userQuestChoice, STEPS, questVector, and stepVector to the steps function.
							STEPS = 2;
							startSteps = 271;
							stepChoices(userQuestChoice + dungeonQuestStepStarter, STEPS, startSteps, questVector, stepVector);

							cin >> userStepChoice; // Set user's input to userStepChoice.
												   // Switch statement to take the user input and print the appropriate hints.
							switch (userStepChoice)
							{
							case MENUCHOICE1:
								hintCounter = 939;
								hintEnd = 950;
								hintChoices(hintCounter, hintEnd, userStepChoice + startSteps, stepVector, hintVector);
								break;
							case MENUCHOICE2:
								hintCounter = 950;
								hintEnd = 951;
								hintChoices(hintCounter, hintEnd, userStepChoice + startSteps, stepVector, hintVector);
								break;
							}
							break;
						case MENUCHOICE9: // Siege on the Dragon Cult.
										  // Set the amount of steps, then give the userQuestChoice, STEPS, questVector, and stepVector to the steps function.
							STEPS = 4;
							startSteps = 273;
							stepChoices(userQuestChoice + dungeonQuestStepStarter, STEPS, startSteps, questVector, stepVector);

							cin >> userStepChoice; // Set user's input to userStepChoice.
												   // Switch statement to take the user input and print the appropriate hints.
							switch (userStepChoice)
							{
							case MENUCHOICE1:
								hintCounter = 951;
								hintEnd = 965;
								hintChoices(hintCounter, hintEnd, userStepChoice + startSteps, stepVector, hintVector);
								break;
							case MENUCHOICE2:
								hintCounter = 965;
								hintEnd = 966;
								hintChoices(hintCounter, hintEnd, userStepChoice + startSteps, stepVector, hintVector);
								break;
							case MENUCHOICE3:
								hintCounter = 966;
								hintEnd = 968;
								hintChoices(hintCounter, hintEnd, userStepChoice + startSteps, stepVector, hintVector);
								break;
							case MENUCHOICE4:
								hintCounter = 968;
								hintEnd = 970;
								hintChoices(hintCounter, hintEnd, userStepChoice + startSteps, stepVector, hintVector);
								break;
							}
							break;
						case MENUCHOICE10: // Silenced Tongues.
										   // Set the amount of steps, then give the userQuestChoice, STEPS, questVector, and stepVector to the steps function.
							STEPS = 3;
							startSteps = 277;
							stepChoices(userQuestChoice + dungeonQuestStepStarter, STEPS, startSteps, questVector, stepVector);

							cin >> userStepChoice; // Set user's input to userStepChoice.
												   // Switch statement to take the user input and print the appropriate hints.
							switch (userStepChoice)
							{
							case MENUCHOICE1: // Locate the Ceremonial Weapons.
											  // Set the amount of steps, then give the userQuestChoice, STEPS, and additionalStepsVector to the additional steps function.
								STEPS = 2;
								startSteps = 11;
								userAdditionalChoice = additionalStepPrint(userStepChoice, STEPS, startSteps, additionalStepsVector);
								// Switch statement holding all the additional choices.
								switch (userAdditionalChoice)
								{
								case MENUCHOICE1:
									// Set the starting hint index, the ending hint index, and call the hint function with all the variables needed.
									hintCounter = 970;
									hintEnd = 973;
									hintChoices(hintCounter, hintEnd, userAdditionalChoice, additionalStepsVector, hintVector);
									break;
								case MENUCHOICE2:
									// Set the starting hint index, the ending hint index, and call the hint function with all the variables needed.
									hintCounter = 973;
									hintEnd = 977;
									hintChoices(hintCounter, hintEnd, userAdditionalChoice, additionalStepsVector, hintVector);
									break;
								}
								break;
							case MENUCHOICE2: // Open the Elder's Cairn.
								hintCounter = 977;
								hintEnd = 979;
								hintChoices(hintCounter, hintEnd, userStepChoice + startSteps, stepVector, hintVector);
								break;
							case MENUCHOICE3: // Defeat Kvenel.
								hintCounter = 979;
								hintEnd = 985;
								hintChoices(hintCounter, hintEnd, userStepChoice + startSteps, stepVector, hintVector);
								break;
							}
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
	gameArray[0].setGameName("The Elder Scrolls V: Skyrim"); // Set the game name.

															 // Set the category names.
	categoryNameVector[0] = "Main Quests";
	categoryNameVector[1] = "Side Quests";
	categoryNameVector[2] = "Dungeon Quests";

	// MAIN QUESTS STARTS HERE
	// Set the quest names and descriptions (if they have them).
	// Main Quests (0-18).
	questVector[0].setQuestName("Unbound");
	questVector[0].setQuestDescription("After the cart ride is over and you choose your character's race, name, and detailed appearance attributes, wait through another non-interactive sequence to get this quest's first objective.");
	questVector[1].setQuestName("Before the Storm");
	questVector[2].setQuestName("Bleak Falls Barrow");
	questVector[3].setQuestName("Dragon Rising");
	questVector[4].setQuestName("The Way of the Voice");
	questVector[5].setQuestName("The Horn of Jurgen Windcaller");
	questVector[6].setQuestName("A Blade in the Dark");
	questVector[7].setQuestName("Diplomatic Immunity");
	questVector[8].setQuestName("A Cornered Rat");
	questVector[9].setQuestName("Alduin's Wall");
	questVector[10].setQuestName("The Throat of the World");
	questVector[11].setQuestName("Elder Knowledge");
	questVector[12].setQuestName("Alduin's Bane");
	questVector[13].setQuestName("The Fallen");
	questVector[14].setQuestName("Paarthurnax");
	questVector[14].setQuestDescription("This quest is entirely optional, and can only be gotten by talking to Esbern at the Sky Haven Temple.");
	questVector[15].setQuestName("Season Unending");
	questVector[16].setQuestName("The World - Eater's Eyrie");
	questVector[17].setQuestName("Sovngarde");
	questVector[18].setQuestName("Dragonslayer");

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
	hintVector[79] = "Wait until Irileth shows up and reports a dragon sighting, then follow her to the Jarl.";
	hintVector[80] = "You'll get the next objective after the Jarl talks to you and gives you a reward for getting the Dragonstone.";
	hintVector[81] = "NOTE: The reward includes permission to buy a house in Whiterun, which you can do now if you have 5000 gold to spare. Find Proventus Avenicci (who's usually in Dragonsreach or the adjacent Jarl's quarters) and talk to him about it, then go find the house called Breezehome a bit east of Whiterun's main gate. Enter it and go upstairs to find a bed you can sleep in and a chest you can store stuff in. (If you want to buy more storage containers, an alchemy lab, or other decorations, talk to Avenicci about it.)";
	// Meet Irileth near the Western Watchtower.
	hintVector[82] = "Follow Irileth out of Dragonsreach and down to where she talks to some soldiers. After that, follow her outside and down to the western watchtower.";
	hintVector[83] = "NOTE: If you don't follow Irileth out of Whiterun, you can go meet up with her whenever you're ready. Check the world map to see where the Western Watchtower location is, then look just east of it for a quest marker that shows the rendezvous point. There'll be another quest marker showing Irileth's current location.";
	hintVector[84] = "After Irileth runs up the watchtower's large ramp, go past her and enter the tower. Quicksave, then wait for the next objective.";
	// Kill the dragon.
	hintVector[85] = "If you've taken cover inside the watchtower, you won't be able to see the dragon much since it flies around a lot. It does occasionally land, but not necessarily within sight of the tower's doorway.";
	hintVector[86] = "You could go outside and run around the tower, trying to use cover to avoid the dragon's fiery breath attacks while hitting it with your best ranged attacks. However, you'll probably get flamed sooner or later that way, and that'll kill you very quickly if you don't have any fire resistance from equipment or potions. The same problem applies to attacking the dragon from the tower's roof.";
	hintVector[87] = "Fortunately, your Whiterun allies will be out there doing the dragon some damage, so you can just stay near the top of the ramp and shoot off arrows or spells from there whenever the dragon lands nearby. Eventually, it'll die, and you'll get the next objective.";
	// Investigate the dragon.
	hintVector[88] = "Go over to the dragon's corpse and wait for it to burst into flames, which signifies that you're absorbing the power of its dragon-y soul. After that's done, you'll get the next two objectives.";
	// (Optional)Use your new Shout power.
	hintVector[89] = "Bring up your Spells menu and click on \"shouts,\" then click on the Unrelenting Force shout to equip it. (Note that this doesn't take up either of your hands like magic spells do. Consider it a \"mouth power.\")";
	hintVector[90] = "Close the Spells menu and face one or more of the nearby guards, then hit the Shout key. (Don't worry -- they won't turn hostile.)";
	// Report back to Jarl Balgruuf.
	hintVector[91] = "Search the dragon's body for loot, then fast-travel back to Whiterun.";
	hintVector[92] = "Wait until a loud voice says \"do vah keen\" then fast-travel to Dragonsreach and go inside.";
	hintVector[93] = "The Jarl is back on his throne, so go up to him to get him to talk to you and start the next quest.";
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
	hintVector[94] = "Stand and wait until the Jarl rewards you with a magic weapon and the title of Thane of Whiterun.";
	hintVector[95] = "The first step to reaching High Hrothgar is traveling to Ivarstead.";
	hintVector[96] = "Cross the bridge that's at the north end of Ivarstead, then go up the stone steps to start on the long path to High Hrothgar.";
	hintVector[97] = "NOTE: Starting at the beginning of the steps, and ending up near the monastery, there's a series of ten little shrines with etched tablets in them. If you read all ten of them on your way up, you'll get a one-day blessing called Voice of the Sky that'll prevent any animals from attacking you or fleeing from you (unless you attack them). Now you can pet the deer and run with the wolves!";
	hintVector[98] = "When you get up to where snow is on the ground, you'll have a slightly harder time seeing the path at some points. Always look ahead for the next set of stone steps to help guide you.";
	hintVector[99] = "After you go a ways along the snowy path, you'll reach a narrow passage where a frost troll will attack you. If it's too much for you to handle, try to sprint on past it and leave it behind.";
	hintVector[100] = "A ways past it, you'll come to the entrance to High Hrothgar. Check the little shrine area with the big chest in it for items, including a disease-curing potion, then go up the steps on either side to find a door.";
	hintVector[101] = "Use it to enter the monastery, then move forward to meet Arngeir. Talking to him will get you the next objective.";
	// Demonstrate your "Unrelenting Force" Shout.
	hintVector[102] = "Make sure that your Unrelenting Force shout is selected, then hit the Shout key to give Arngeir the demonstration he wants.";
	// Speak to Arngeir.
	hintVector[103] = "Move up to Arngeir and wait for him to talk to you.";
	hintVector[104] = "Choose the dialogue topic about being ready to learn when it comes up, then wait a bit to get the next objective.";
	// Learn the Word of Power from Einarth.
	hintVector[105] = "Wait until Einarth shouts the word you're to learn onto the floor.";
	hintVector[106] = "Move up to it to learn the word, then wait to get the next objective.";
	// Demonstrate your "Unrelenting Force" Shout.
	hintVector[107] = "Turn to face the floor section that you learned Einarth's word from, and wait for a ghostly apparition to appear on it.";
	hintVector[108] = "When one does, face it and hit the Shout key. Don't just tap it for minimal effect, but hold it down to utter a more powerful version of the shout (which is possible now that you know more than one of its words).";
	hintVector[109] = "When you do that, the first number in the objective name should increase. Wait for another apparition to appear, then repeat the process until you've done all three.";
	// Learn the Word of Power from Borri.
	hintVector[110] = "Follow the monk named Borri to the courtyard, then wait for him to shout a word onto the ground.";
	hintVector[111] = "Move onto it to learn it, then wait to get the next objective.";
	// Demonstrate your "Whirlwind Sprint" Shout.
	hintVector[112] = "Follow Borri to a gate, then stand aside and watch as another monk uses the Whirlwind Sprint shout to zoom through the gate super-fast.";
	hintVector[113] = "Bring up your Spells menu and select Whirlwind Sprint as your current shout, then go stand next to Arngeir and face the gate.";
	hintVector[114] = "When the gate opens, hit the Shout key to be propelled quickly through it.";
	// Speak to Arngeir for further training.
	hintVector[115] = "Shout your way back over to Arngeir (or just walk over there) to get him to talk to you and start the next quest.";
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
	hintVector[116] = "Before you can start searching for the horn, you'll have to make the long trek to Ustengrav.";
	hintVector[117] = "Be ready to fight some bandits and a necromancer as you approach Ustengrav, then drop into the stone pit (or take its \"stairs\" down) and use the door.";
	hintVector[118] = "You'll need to make your way through Ustengrav's two areas to reach the tomb of Jurgen Windcaller.";
	// Read the note.
	hintVector[119] = "Go up to the tomb and read the mysterious note that's in the large stone hand.";
	// Meet with whoever took the horn.
	hintVector[120] = "Go through the door behind the tomb, then check for loot before using the cave tunnel to reach a door that leads back to the main Ustengrav area.";
	hintVector[121] = "Continue along the tunnel until it ends, then use the nearby lever to open up a secret panel.";
	hintVector[122] = "Go through it, then use the area map to help you navigate your way back to the door that leads outside.";
	hintVector[123] = "Fast-travel to Riverwood, then enter the inn and talk to Delphine.";
	hintVector[124] = "Say that you'd like to rent the attic room, then open the middle door in the west wall to enter the room that she sends you to.";
	hintVector[125] = "Wait inside the room until Delphine comes in and talks to you, which gives you the next objective (and the next quest).";
	// Return the horn to Arngeir.
	hintVector[126] = "Work on the \"A Blade in the Dark\" quest until Delphine leads you into her secret room, but don't talk to her. Instead, leave the inn and fast-travel back to High Hrothgar.";
	hintVector[127] = "Enter the monastery, then use the local area map and quest marker to find Arngeir. Talk to him to get the next objective.";
	// Learn the Word of Power from Wulfgar.
	hintVector[128] = "Follow Arngeir down to where Wulfgar is waiting.";
	hintVector[129] = "After he shouts a word onto the floor, move onto it to learn it and get the next objective.";
	// Receive the Greybeards' greeting.
	hintVector[130] = "Stand on the floor section that's between the monks and wait through their final test in order to finish the quest.";
	hintVector[131] = "TIP: Return to Ustengrav and make your way back to the tomb of Jurgen Windcaller. Activate it to replace the horn and gain a bonus dragon soul.";
	// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

	// A Blade in the Dark - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
	// Steps.
	stepVector[30] = "Talk to Jarl Balgruuf.";
	stepVector[31] = "Meet Irileth near the Western Watchtower.";
	stepVector[32] = "Kill the dragon.";
	stepVector[33] = "Investigate the dragon.";

	// Hints.
	// Talk to Delphine.
	hintVector[132] = "Follow Delphine into another room, then close the door when she says to.";
	hintVector[133] = "She'll open up a secret panel and enter a secret room. Follow her in, but don't get close enough to her to trigger a conversation yet.";
	hintVector[134] = "First, loot the entire inn for items (it no longer counts as stealing) and finish up the \"The Horn of Jurgen Windcaller\" quest. Then come back and talk to Delphine.";
	hintVector[135] = "Ask her about everything to get the next objective.";
	// Locate the dragon burial site.
	hintVector[136] = "Even if you tell Delphine that you're not ready to go yet, she'll don her armor and start off for Kynesgrove. (That's why I advised you not to talk to her until after you went and finished the previous quest. It's more convenient to follow her to Kynesgrove than to make your own way there.)";
	hintVector[137] = "As you move into Kynesgrove, one of the residents will talk to you about the dragon at the burial mound. That's where you need to go next.";
	hintVector[138] = "Go up to the inn, then use the path that starts on its left side to get up to the burial mound, where you'll find Delphine hiding behind a large boulder.";
	hintVector[139] = "Quicksave, then go up and stand next to her.";
	hintVector[140] = "Get out your bow and move around the left side of the boulder so you can see the burial mound ahead. You could just hide and wait for the next objective, but it's best to get a few shots off at the newly resurrected dragon as soon as it rises from the mound.";
	// Kill the dragon Sahloknir.
	hintVector[141] = "If you started hitting Sahloknir with arrows as soon as it rose up, it may come toward you and start breathing fire. If so, take cover behind the boulder and hope it gets interested in Delphine or your follower (if you have one).";
	hintVector[142] = "If you're lucky, it'll stay on the ground and attack someone else, allowing you to approach it from the side and hit it with your best melee weapon. If you're *really* lucky, you'll be able to kill it before it takes to the air.";
	hintVector[143] = "If you're not so lucky, the dragon will start flying around and flaming you from the air. There's very little cover from aerial assaults, though you could try crouching down and moving around the large boulder until the dragon gets interested in someone else.";
	hintVector[144] = "If it gets too hard, quickrestore and try again. Maybe you'll get lucky next time and be able to kill the dragon before it starts flying around.";
	// Talk to Delphine.
	hintVector[145] = "Approach the dead dragon to absorb its soul, then check its body for items.";
	hintVector[146] = "Talk to Delphine about everything to get the next quest.";
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
	hintVector[147] = "Return to Riverwood's inn and talk to Delphine in her secret room to get the next objective.";
	// Meet Malborn in Solitude.
	hintVector[148] = "If you don't mind spending a bit of gold, you can go to any stable (like the one in Whiterun) and pay the carriage driver to take you to Solitude.";
	hintVector[149] = "After entering Solitude, go a short way forward and look to your left for the Winking Skeever inn.";
	hintVector[150] = "Enter the inn and look for Malborn at a table near the back. Talk to him to get the next objective.";
	hintVector[151] = "NOTE: You shouldn't talk to Malborn to continue this quest unless your skills for fighting tough enemies or sneaking past them unseen are very high. Go practice them up and/or do other quests first if necessary.";
	// Give Malborn the equipment.
	hintVector[152] = "Use the inventory screen that comes up to give Malborn your best armor, weapons, potions, and other items that you'll need later on to aid you in fighting the Thalmor soldiers or sneaking past them.";
	// Meet Delphine at the stables.
	hintVector[153] = "Leave the inn and go back through Solitude's gate, then head down the path to Katja's Farm.";
	hintVector[154] = "You'll find Delphine next to the windmill. Talk to her to get an invitation and some suitable attire.";
	hintVector[155] = "Go to inventory and put the party boots and party clothes on, then talk to Delphine again and say you're ready to go.";
	// Talk to Malborn.
	hintVector[156] = "Go over to the nearby stairs and show the soldier your invitation.";
	hintVector[157] = "Go up the stairs and into the embassy building, where you'll be talked to briefly by Elenwen.";
	hintVector[158] = "After she wanders off, go up to Malborn's counter and talk to him to get the next objective.";
	// Create a distraction and get away from the party.
	hintVector[159] = "Malborn is going to let you into the kitchen, but he won't dare do it unless the party guests are all distracted first.";
	hintVector[160] = "One possibility for this is to find a guest that you're on good terms with (from other quests) and ask him to cause a distraction for you. This may or may not require you to succeed at a persuade dialogue option.";
	hintVector[161] = "Another option is to get Razelan or Erikur to cause a distraction.";
	hintVector[162] = "As soon as a distraction is started, run over to a spot near the door that's behind Malborn's counter and wait for him to open it. When he does, quickly run through it, then wait to get the next two objectives.";
	// (Optional)Retrieve your gear.
	hintVector[163] = "Follow Malborn through the kitchen and into a side room with a chest.";
	hintVector[164] = "Loot the chest to get all the gear you gave Malborn earlier when you were talking to him in the inn.";
	// Search for information about the dragons returning.
	hintVector[165] = "Go through the door near the equipment chest and close it behind you, then crouch down and sneak past the open door on the left while staying on the right side of the hallway.";
	hintVector[166] = "Enter the hallway's other open room and look near the doorway for three articles of Thalmor wizard clothing that you can take and wear as a disguise. The guards will still attack you if you get close to them, but it may help a bit in sneaking around.";
	hintVector[167] = "Sneak back to the open door with the guards just past it, and stop in a spot where you can see part of the nearest guard. When they're done talking, they'll walk away from the counter they're at, and you'll have a chance to sneak around the counter and up the stairs unseen.";
	hintVector[168] = "If you fight the guards instead of sneaking past them, the wizard who's upstairs will come down and join the battle. Otherwise, you'll have to sneak by him (or kill him with a powerful sneak attack) once you get up there.";
	hintVector[169] = "Check the upstairs rooms for loot if you want, then use the door that takes you to a small outdoor area. It also has several guards, which will make it very hard to sneak over to the door to the Elenwen's Solar area. If you're the stealthy type, you may want to use sneak attacks to eliminate the guards. (Or an Invisibility potion to skip combat.)";
	hintVector[170] = "When you enter the solar, you'll see a guard across the room from you with her back turned. If you can't sneak around without her hearing you, you'd better hit her with a sneaky arrow, then get ready to fight her and two other guys who will come running (one of whom is a mage).";
	hintVector[171] = "Go through the doorway in the NW corner of the entry room to find an office. Search the chest behind the desk to find a document called \"Dragon Investigation : Current Status.\"";
	hintVector[172] = "Take it and read it in the books section of your inventory, then go down the stairs at the other end of the office to find a door that leads to the dungeon.";
	hintVector[173] = "In the dungeon, sneak around to the top of some stairs, then sneak down them and take cover to the right of the doorway. Enter third-person mode so you can rotate your view around and see the patrolling guard without having to be in the doorway.";
	hintVector[174] = "You could sneak around without the guard seeing you, but it's much more convenient to kill her. After you do, there are two ways to get the second bit of information that you need.";
	hintVector[175] = "One is to get the \"Thalmor Dossier : Esbern\" from the chest that's in the area to the right of the prison cells, and the other is to talk to the guy who's chained up in the nearest prison cell. Either way, you'll get the next objective.";
	// Escape the Thalmor Embassy.
	hintVector[176] = "Soon after you get this objective, two Thalmor soldiers will enter the area with Malborn, having discovered that he was working with you.";
	hintVector[177] = "You're going to have to kill them, so it's best to weaken at least one of them with sneak attacks first. Also, try to keep Malborn alive, though doing so isn't essential.";
	hintVector[178] = "After they're down, search them to find a trap door key. Talk to Etienne Rarnis in the prison cell and free him, then follow him over to the trap door. (If your distraction at the party earlier involved Brelas, you can find her in another cell and free her, too.)";
	hintVector[179] = "Use the trap door to enter a cave, then go down the narrow passage to reach a drop-off that leads to a frost troll's lair. You could stay up on your ledge and shoot arrows or spells down at it, but your dumb companions will probably drop down there and get themselves killed.";
	hintVector[180] = "In any case, kill the troll and drop down (in either order), then find the passage on the other side of the cave that leads to an exit. (Note that there's a special gem near the drop-down point that you might want to take before you go.)";
	// Talk to Delphine.
	hintVector[181] = "Before you return to Riverwood, you might want to visit a couple of dragon mounds where Alduin has recently resurrected some dragons (if you feel like fighting the resurrected dragons).";
	hintVector[182] = "Fast-travel back to Riverwood, then enter the inn and find Delphine in her secret room.";
	hintVector[183] = "Talk to her about Esbern to get the next quest.";
	// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

	// A Cornered Rat - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
	// Steps.
	stepVector[44] = "Talk to Brynjolf.";
	stepVector[45] = "Search the Ratway for Esbern's hideout. ";
	stepVector[46] = "Find Esbern in the Ratway Warrens.";
	stepVector[47] = "Talk to Esbern.";

	// Hints.
	// Talk to Brynjolf.
	hintVector[184] = "Reclaim your confiscated gear from one of the chests in the secret room, then leave the inn and go to Riften. (If you don't want to take a carriage, fast-travel to Ivarstead, then follow the river east.)";
	hintVector[185] = "When you approach Riften's gate, one of the guards will try to extort a \"visitor's tax\" from you (if this is your first visit). You can either pay it or try to persuade or intimidate your way out of paying.";
	hintVector[186] = "After you enter Riften, follow the quest arrow to find Brynjolf, who'll be inside the Bee and Barb inn (if it's night) or in his stall in the marketplace just south of the inn (daytime).";
	hintVector[187] = "Walk up to him to get him to talk to you, then say that you're looking for an old man who's hiding out in Riften.";
	hintVector[188] = "If you've already done the first Thieves Guild faction quest or can pass a persuade check, Brynjolf will help you right away.";
	hintVector[189] = "Otherwise, either do his quest or skip it by asking Keerava at the inn's counter about the old man you're looking for. Either way gets you the next objective.";
	// Search the Ratway for Esbern's hideout. 
	hintVector[190] = "See the \"Taking Care of Business\" Thieves Guild faction quest's first objective for directions on getting to the Ragged Flagon.";
	hintVector[191] = "If you did Brynjolf's quest, ask him about the old man again to get the next objective. Otherwise, try talking to someone else.";
	hintVector[192] = "You can ask both Dirge and Vekel the Man about the old man, but you'll have to either bribe them or pass a persuade option (or brawl, in the case of Dirge) if you're not a respected member of the Thieves Guild.";
	// Find Esbern in the Ratway Warrens.
	hintVector[193] = "Use the door that's to the right of the bar counter to enter the Ratway Vaults, then crouch down. There are several Thalmor soldiers and mages in the area.";
	hintVector[194] = "If you want to avoid combat, move straight forward and look down to see an open metal door on the lower floor. Quickly drop down there and go through the door, then turn right and run for the door to the Ratway Warrens area.";
	hintVector[195] = "In the warrens, move down the steps, then either pick open the door on the right or go around to get to the room that's past it.";
	hintVector[196] = "Go up the stone steps and watch out for a couple of crazy characters who may attack you as you make your way to the door that's at the south end of the upstairs area.";
	hintVector[197] = "Use the door to get Esbern to talk to you, then persuade him to open up.";
	hintVector[198] = "The only way to do that is to use the dialogue option about the 30th of Frostfall when it comes up.";
	// Talk to Esbern.
	hintVector[199] = "Wait until Esbern opens his door, then go inside and wait for him to talk to you.";
	hintVector[200] = "Choose whatever dialogue options you want until you get the next quest.";

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
	// Side Quests (22 | 19 - 40).
	questVector[19].setQuestName("The Blessings of Nature ");
	questVector[19].setQuestDescription("To get this quest, ask Danica Pure-Spring in Whiterun's Temple of Kynareth about the temple and the Gildergreen Tree.");
	questVector[20].setQuestName("Blood on the Ice");
	questVector[21].setQuestName("The Book of Love");
	questVector[21].setQuestDescription("To get this quest, talk to Dinya Balu in Riften's Temple of Mara.");
	questVector[22].setQuestName("Delayed Burial");
	questVector[23].setQuestName("Forbidden Legend");
	questVector[23].setQuestDescription("The easiest way to get this quest is to read a copy of the \"Lost Legends\" book.There's one under a flagon on one of the bookshelves in Farengar Secret-Fire's small study room in Dragonsreach.");
	questVector[24].setQuestName("The Forsworn Conspiracy");
	questVector[25].setQuestName("The Golden Claw ");
	questVector[26].setQuestName("The Heart of Dibella");
	questVector[27].setQuestName("In My Time of Need");
	questVector[27].setQuestDescription("When you return to Whiterun after finishing the \"Dragon Rising\" Main Quest, there should be two Alik'r guys talking to a city guard. If not, look for them to be there on a later visit. Talk to one of them to get this quest.");
	questVector[28].setQuestName("Kyne's Sacred Trials");
	questVector[28].setQuestDescription("Travel to Froki's Shack (see the Riften section of the World Map Exploration Guide) and talk to Froki Whetted-Blade to get this quest. (Note that you can do the first three objectives in any order.)");
	questVector[29].setQuestName("Laid to Rest");
	questVector[29].setQuestDescription("To get this quest, go to Morthal and ask Jonna in the inn about the burned - down house.");
	questVector[30].setQuestName("Lights Out!");
	questVector[30].setQuestDescription("To get this quest, go to Solitude and talk to Jaree-Ra, who's usually hanging around outside the Angeline's Aromatics store.");
	questVector[31].setQuestName("The Man Who Cried Wolf");
	questVector[31].setQuestDescription("The first time you enter Solitude's Blue Palace, someone will complain to the Jarl about Wolfskull Cave. Anytime after that, talk to Falk Firebeard about the cave to get this quest.");
	questVector[32].setQuestName("Missing in Action ");
	questVector[32].setQuestDescription("Enter and exit Whiterun's inn sometime during the day to get Fralia Gray-Mane to appear near a merchant stall and argue with a couple of guys. Anytime after the argument is over, talk to Fralia to get this quest.");
	questVector[33].setQuestName("No One Escapes Cidhna Mine");
	questVector[33].setQuestDescription("After you finish the \"The Forsworn Conspiracy\" quest by surrendering to a city guard, you'll get this quest.");
	questVector[34].setQuestName("Promises to Keep");
	questVector[34].setQuestDescription("Talk to Louis Letrush in Riften's inn to get this quest.");
	questVector[35].setQuestName("Repairing the Phial");
	questVector[35].setQuestDescription("At some point after finishing both the \"The White Phial\" side quest and the \"The Throat of the World\" Main Quest, a courier will approach you in a city and give you a letter from Quintus Navale.Read it to start this quest.");
	questVector[36].setQuestName("Rise in the East");
	questVector[36].setQuestDescription("To get this quest, go to Windhelm's docks (just east of the city) during the day and talk to Orthus Endario in the East Empire Company building.");
	questVector[37].setQuestName("Rising at Dawn");
	questVector[37].setQuestDescription("After becoming a vampire, you can get cured either by doing enough Companions faction quests to become a werewolf, or by doing this quest.To get it, talk to any innkeeper about rumors until you hear about Falion.");
	questVector[38].setQuestName("Unfathomable Depths");
	questVector[39].setQuestName("The White Phial");
	questVector[39].setQuestDescription("To get this quest, enter the White Phial shop near Windhelm's SW corner and ask Nurelion what he's arguing about.");
	questVector[40].setQuestName("The Wolf Queen Awakened");
	questVector[40].setQuestDescription("After you finish the \"The Man Who Cried Wolf\" quest and get to level 10 or higher, fast-travel around the major cities until a courier gives you a letter from Falk Firebeard. Go to the Blue Palace and talk to him about Wolfskull Cave to get this quest.");

	// The Blessings of Nature - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
	// Steps.
	stepVector[91] = "Retrieve Nettlebane.";
	stepVector[92] = "Bring Nettlebane to Danica.";
	stepVector[93] = "Retrieve Eldergleam sap.";
	stepVector[94] = "Follow Maurice.";
	stepVector[95] = "Take sapling.";
	stepVector[96] = "Return to Danica.";

	// Hints.
	// Retrieve Nettlebane.
	hintVector[324] = "Go to Orphan Rock, which is a ways east of Helgen. See the Falkreath section of the World Map Exploration Guide.";
	hintVector[325] = "As you approach, you'll come under attack by several witches. You'll need to kill them and their hagraven leader.";
	hintVector[326] = "To get to the hagraven, get onto the small hill with the tent and campfire on it, then carefully cross the large log.";
	hintVector[327] = "Loot the hagraven after you kill her to get Nettlebane";
	// Bring Nettlebane to Danica.
	hintVector[328] = "Return to Whiterun's temple and tell Danica Pure-Spring that you got Nettlebane.";
	// Retrieve Eldergleam sap.
	hintVector[329] = "A guy named Maurice Jondrelle will talk to you and ask to come along. You can either accept his offer or turn him down. (Note that accepting can make things a bit easier later on.)";
	hintVector[330] = "Either way, you'll need to travel to the Eldergleam Sanctuary, which is a ways south of Windhelm. See its section of the World Map Exploration Guide for directions.";
	hintVector[331] = "Enter the sanctuary and go along the passage to reach a huge cavern, then follow the path along until it's blocked by giant roots.";
	hintVector[332] = "Equip Nettlebane and move up against the first path-blocking roots, then take a swing at them to get them to move out of your way.";
	hintVector[333] = "After you do that to the rest of the path-blocking roots, Maurice Jondrelle will talk to you (if you brought him). You can insist on taking sap from the tree, or you can ask him for an alternative.";
	hintVector[334] = "If you accept Jondrelle's alternative, you'll get the next objective. Otherwise, you'll need to go up to the base of the tree and activate it to get the \"Return to Danica\" objective.";
	// Follow Maurice.
	hintVector[335] = "Follow Maurice to the base of the tree, then wait until he talks to you to get the next objective.";
	// Take sapling.
	hintVector[336] = "Go up to the Eldergleam sapling and activate it to take it, which will get you the next objective.";
	// Return to Danica.
	hintVector[337] = "Look just west of the tree's base for a large root that you can whack with Nettlebane to gain access to a treasure chest.";
	hintVector[338] = "If you took the sap from the tree, several spriggans will appear throughout the cavern. You'll have to fight them on your way out.";
	hintVector[339] = "Leave the sanctuary and return to Whiterun, then go to the temple and talk to Danica Pure-Spring.";
	hintVector[340] = "Give her the sap or the sapling (whichever one you got) to finish the quest and get her to become a Restoration skill trainer.";
	// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

	// Blood on the Ice - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
	// Steps.
	stepVector[97] = "How can I get this quest ?";
	stepVector[98] = "Question the witnesses.";
	stepVector[99] = "Report to the guard.";
	stepVector[100] = "Talk to Jorleif.";
	stepVector[101] = "Get assistance from Jorleif.";
	stepVector[102] = "Examine the crime scene.";
	stepVector[103] = "Get access to Hjerim.";
	stepVector[104] = "Look for clues.";
	stepVector[105] = "Follow up on the clues from Hjerim.";
	stepVector[106] = "Investigate Hjerim with Viola.";
	stepVector[107] = "Talk to Jorleif.";
	stepVector[108] = "Speak to Wuunferth.";
	stepVector[109] = "Patrol the streets of the Stone Quarter at night.";
	stepVector[110] = "Catch the murderer.";
	stepVector[111] = "Talk to Jorleif.";

	// Hints.
	// How can I get this quest ?
	hintVector[341] = "After you've visited Windhelm a couple of times, visit it again at night.";
	hintVector[342] = "Go to the small cemetery area that's near the entrance to the Hall of the Dead to find a small crowd of people gathered around a dead body.";
	hintVector[343] = "Talk to the nearby guard about the murder to get this quest.";
	// Question the witnesses.
	hintVector[344] = "Question the three people standing nearby about what happened to get the next objective.";
	// Report to the guard.
	hintVector[345] = "Talk to the guard again to be referred to Jorleif.";
	// Talk to Jorleif.
	hintVector[346] = "Go to the Palace of the Kings and talk to Jorleif to get the next two objectives.";
	// Get assistance from Jorleif.
	hintVector[347] = "There's nothing to do on this objective separate from the other ones.";
	// Examine the crime scene.
	hintVector[348] = "Return to the crime scene to find a quest arrow pointing at a large blood splatter where the body was.";
	hintVector[349] = "That's a hint to look around for other blood splatters.";
	hintVector[350] = "There's another one on the ground nearby, plus more on the ground heading west.";
	hintVector[351] = "Go west and up the steps, then turn right and go up some more steps.";
	hintVector[352] = "Follow the blood splatters along until you come to the building named Hjerim.";
	hintVector[353] = "As you approach its entrance door, you'll get the next objective.";
	// Get access to Hjerim.
	hintVector[354] = "You could try to pick open the lock on Hjerim's door, but it's a tough master-level lock. It'll probably be easier to get the key.";
	hintVector[355] = "Now's a good time to get some assistance from Jorleif.";
	hintVector[356] = "Return to the Palace of the Kings and ask him how to get into Hjerim.";
	hintVector[357] = "He'll say that Tova Shatter-Shield has the key, so follow the new quest arrow to find her. (Note that if it's night, she'll probably be locked up in her house, and it would be easier to wait until the house is unlocked the next morning.)";
	hintVector[358] = "Either pickpocket the key to Hjerim from Tova, or talk to her to get it.";
	hintVector[359] = "Once you have it, return to Hjerim and enter it to get the next objective.";
	// Look for clues.
	hintVector[360] = "Look around near where you entered to find a bloody chest pushed up against the south wall.";
	hintVector[361] = "After investigating it, open it and take everything in it to get the next objective.";
	// Follow up on the clues from Hjerim.
	hintVector[362] = "You could leave now, but there are some other important things to investigate.";
	hintVector[363] = "Leave Hjerim and talk to any city guard to get two relevant topics.";
	hintVector[364] = "Ask about the butcher to be referred to Viola Giordano, and ask about the amulet (if you got it) to be referred to Calixto.";
	hintVector[365] = "It's a bit more convenient to talk to Calixto first. If he's not in his House of Curiosities, follow this objective's two quest arrows until you find out which one points to him.";
	hintVector[366] = "Ask Calixto about the amulet, then agree to sell it to him for 500 gold. (Note that you can then pickpocket it back, but don't. You'll get it back later, after it's been properly identified.)";
	hintVector[367] = "Follow the other quest arrow to find Viola Giordano. Ask her about the butcher, then mention the journal you found to get the \"Talk to Jorleif\" objective.";
	hintVector[368] = "NOTE: If you didn't fully investigate Hjerim yourself, you'll only be able to show Viola one of the posters. You'll then have to do the \"Investigate Hjerim with Viola\" objective before you can get the above-mentioned one.";
	// Investigate Hjerim with Viola.
	hintVector[369] = "Follow Viola to Hjerim, then follow her over to the two wardrobes.";
	hintVector[370] = "When she stops, investigate the wardrobe on the right, then open it to find a false back panel.";
	hintVector[371] = "Open the panel, then enter the secret room.";
	hintVector[372] = "Investigate the altar, then take the \"Butcher Journal #2\" book from it.";
	hintVector[373] = "Exit the secret room and talk to Viola about the journal's contents to get the next objective.";
	// Talk to Jorleif.
	hintVector[374] = "Return to the Palace of the Kings, but think about what you're doing before you tell Jorleif that Wuunferth is the murderer.";
	hintVector[375] = "You don't really have positive proof that Wuunferth is guilty, so you may want to talk to him first. To find him, go through the door near the exit doors that leads to the upstairs area, then go to the southern room.";
	hintVector[376] = "Talk to Wuunferth about his dabbling in necromancy, then mention the journal and amulet to get the \"Patrol the streets of the Stone Quarter at night\" objective.";
	hintVector[377] = "If you instead tell Jorleif that Wuunferth is the killer, the quest will immediately end. However, it's not really over yet.";
	// Speak to Wuunferth.
	hintVector[378] = "Return to the Palace of the Kings, then go through the door that leads to the Windhelm Barracks area.";
	hintVector[379] = "Move through it to reach the prison area, then go over to Wuunferth's cell.";
	hintVector[380] = "Talk to him about the recent killing and the reason you thought he was guilty to get the \"Patrol the streets of the Stone Quarter at night\" objective.";
	// Patrol the streets of the Stone Quarter at night.
	hintVector[381] = "Leave the palace and go to the open-air market area in the city's SW corner.";
	hintVector[382] = "Even though you're supposed to have to wait until nighttime, the murderer may already be there. If not, wait an hour at a time until he shows up.";
	hintVector[383] = "The killer is Calixto Corrium. Wait and watch as he kills a woman, after which you'll get the next objective. (Or you can attack him before he kills the woman in order to save her life, but only do so if he's moving toward her with his knife drawn.)";
	// Catch the murderer.
	hintVector[384] = "You can follow Calixto along without attacking him until he enters Hjerim, then go in and kill him. However, there's no penalty for attacking him in the market area and killing him there.";
	hintVector[385] = "You'll get the next objective when he dies, but don't run off and do it before looting his body. If you sold him the strange amulet earlier, it'll have transformed into the much more valuable Necromancer Amulet.";
	// Talk to Jorleif.
	hintVector[386] = "Return to the Palace of the Kings and tell Jorleif about Calixto being the murderer to finish the quest.";
	hintVector[387] = "NOTE: The key that you could've gotten from Calixto's body will open the doors of his House of Curiosities. It'll also open the chest that's at the top of the ladder near those doors. There's another journal in the chest that'll (sort of) explain why Calixto committed the murders.";
	// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

	// The Book of Love - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
	// Steps.
	stepVector[112] = "Talk to Fastred.";
	stepVector[113] = "Talk to Fastred's parents.";
	stepVector[114] = "Talk to Bassianus or Klimmek.";
	stepVector[115] = "Return to Dinya Balu.";
	stepVector[116] = "Talk to Calcemo.";
	stepVector[117] = "Get advice from Yngvar.";
	stepVector[118] = "Deliver poem.";
	stepVector[119] = "Deliver Faleen's letter.";
	stepVector[120] = "Return to Dinya Balu.";
	stepVector[121] = "Put on the Amulet of Mara.";
	stepVector[122] = "Talk to the long - dead lover.";
	stepVector[123] = "Find Fenrig.";
	stepVector[124] = "Bring Fenrig to Ruki.";
	stepVector[125] = "Return to Dinya Balu.";

	// Hints.
	// Talk to Fastred.
	hintVector[388] = "If you haven't discovered Ivarstead yet, see the link below for one way to get there.";
	hintVector[389] = "After you arrive, follow the quest arrow to Fastred, then talk to her to get the next objective.";
	// Talk to Fastred's parents.
	hintVector[390] = "Follow the quest arrows to Boti and Jofthor, then talk to them (in either order) about their daughter to get the next objective.";
	// Talk to Bassianus or Klimmek.
	hintVector[391] = "Use the quest arrows to find either Bassianus Axius or Klimmek, then talk him about Fastred.";
	hintVector[392] = "If you talk to Bassianus, suggest that he elope.";
	hintVector[393] = "If you talk to Klimmek instead, tell him that Fastred probably appreciates assertive men, then tell him to be bold.";
	hintVector[394] = "Follow whichever guy you talked to around until you get the next objective.";
	// Return to Dinya Balu.
	hintVector[395] = "Return to Riften's Temple of Mara and talk to Dinya Balu to get the next objective.";
	// Talk to Calcemo.
	hintVector[396] = "Go to Markarth (via carriage service if you haven't discovered it yet), then go to its west side to find Understone Keep.";
	hintVector[397] = "Enter the keep, then find Calcemo in the large area south of the exit door";
	hintVector[398] = "Tell him that you've been looking for him, and that you've been sent by Mara to aid him.";
	// Get advice from Yngvar.
	hintVector[399] = "Exit Understone Keep and follow the quest arrow to Yngvar the Singer.";
	hintVector[400] = "Talk to him about what Faleen likes, then pay him 200 gold for a love poem.";
	// Deliver poem.
	hintVector[401] = "Return to Understone Keep and follow the quest arrow to Faleen. (Note that if she's in a restricted area that the guards warn you away from, you'll want to wait until she isn't.)";
	hintVector[402] = "Talk to her about the poem to give it to her and get the next objective.";
	// Deliver Faleen's letter.
	hintVector[403] = "Return to Calcemo's area and talk to him about Faleen's letter.";
	hintVector[404] = "After the conversation is over, follow him around until you get the next objective. (Note that if he runs into a restricted area that the guards warn you away from, just wait near the entrance until you get the next objective.)";
	// Return to Dinya Balu.
	hintVector[405] = "Return to Riften's Temple of Mara and talk to Dinya Balu to get the next objective.";
	// Put on the Amulet of Mara.
	hintVector[406] = "Go to inventory and put on the Amulet of Mara that you were given.";
	// Talk to the long - dead lover.
	hintVector[407] = "Travel to Gjukar's Monument, which is a ways south and a bit west of Morthal. See the World Map Exploration Guide if you need more specific directions.";
	hintVector[408] = "Talk to the ghost of Ruki to get the next objective.";
	// Find Fenrig.
	hintVector[409] = "Follow the quest arrow along until you find Fenrig a bit south of Greenspring Hollow. (Or if you've already discovered that location, fast-travel to it before following the quest arrow.)";
	hintVector[410] = "When you find Fenrig, talk to him until he agrees to follow you to Ruki.";
	// Bring Fenrig to Ruki.
	hintVector[411] = "Fast-travel back to Gjukar's Monument, then wait to get the next objective.";
	hintVector[412] = "NOTE: If a glitch happens during their \"ascension,\" you may have to wait an hour in order to get the next objective.";
	// Return to Dinya Balu.
	hintVector[413] = "Return to Riften's Temple of Mara and talk to Dinya Balu to finish the quest and get a permanent +15% to your magic resistance.";
	// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

	// Delayed Burial - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
	// Steps.
	stepVector[126] = "No Steps - Select this for hints.";

	// Hints.
	hintVector[414] = "NOTE: You can't get this quest if you've already finished the \"With Friends Like These...\" Dark Brotherhood faction quest.";
	hintVector[415] = "Check the paved path that's just east of the Loreius Farm (a ways NE of Whiterun) to find a jester named Cicero and his broken-down cart. You can either talk to him or to Vantus Loreius at the farm to start this quest.";
	hintVector[416] = "Talk to Vantus Loreius if you haven't already to learn your two options, then decide which one you want to use.";
	hintVector[417] = "If you'd rather get Cicero the help he needs, talk to Vantus Loreius again and pass a persuade check. After that, you can talk to Cicero to finish the quest and get some gold.";
	hintVector[418] = "If you can't or don't want to do that, go back down to the path and wait near Cicero's wagon for a patrolling guard to walk by.";
	hintVector[419] = "Talk to him and say you'd like to report a crime, then mention Cicero and pass any of the persuade checks listed. After that, you can talk to Vantus Loreius to finish the quest and get some gold.";
	// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

	// Forbidden Legend - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
	// Steps.
	stepVector[127] = "Investigate the Gauldur legend.";
	stepVector[128] = "Learn the truth from Daynas Valen.";
	stepVector[129] = "Read Daynas Valen's notes.";
	stepVector[130] = "Find the Gauldur Amulet Fragment in Folgunthur.";
	stepVector[131] = "Find the Gauldur Amulet Fragment in Geirmund's Hall.";
	stepVector[132] = "Find the Gauldur Amulet Fragment in Saarthal.";
	stepVector[133] = "Reforge the Gauldur Amulet.";
	stepVector[134] = "Take the Gauldur Amulet.";

	// Hints.
	// Investigate the Gauldur legend.
	hintVector[420] = "Make this quest active to get a quest arrow that points you to Folgunthur, which is a ways SE of Solitude.";
	hintVector[421] = "Check the small camp near Folgunthur to find Daynas Valen's journal. Read it to get the next objective.";
	// Learn the truth from Daynas Valen.
	hintVector[422] = "Enter Folgunthur and watch for a pressure plate on the floor as you go down the passage to the first room.";
	hintVector[423] = "Its rotating pillar puzzle has already been solved by Valen's people, so move on past it (watching for another pressure plate) to an area where several draugr attack you. (Note that the gate that closes behind you can be opened with a pull chain that's to the right of it.)";
	hintVector[424] = "Its rotating pillar puzzle has already been solved by Valen's people, so move on past it (watching for another pressure plate) to an area where several draugr attack you. (Note that the gate that closes behind you can be opened with a pull chain that's to the right of it.)";
	hintVector[425] = "Its rotating pillar puzzle has already been solved by Valen's people, so move on past it (watching for another pressure plate) to an area where several draugr attack you. (Note that the gate that closes behind you can be opened with a pull chain that's to the right of it.)";
	hintVector[426] = "From the top of the stairwell, go across the wooden bridge and around a stone pillar to find Daynas Valen's body.";
	hintVector[427] = "Get the notes from it to get the next objective.";
	// Read Daynas Valen's notes.
	hintVector[428] = "Read Daynas Valen's notes in the \"books\" section of your inventory to get the next three objectives, which can be done in any order.";
	// Find the Gauldur Amulet Fragment in Folgunthur.
	hintVector[429] = "The next thing to do is lower the bridge that's near Daynas Valen's corpse.";
	hintVector[430] = "Kill off the draugr on the other side of the bridge, then turn right and fight your way to a lever puzzle";
	hintVector[431] = "Move on past the gates and turn right, then move forward slowly so you can avoid the rockfall that (hopefully) injures a draugr at the bottom of the stairs.";
	hintVector[432] = "After finishing the draugr off, go through the door near it and kill a couple more draugr before figuring out a way to open up the floor's stairwell.";
	hintVector[433] = "Go to the bottom of the stairwell, then kill a couple of frostbite spiders on your way to a puzzle-lock door.";
	hintVector[434] = "Past the puzzle door is a door that leads to the Folgunthur Crypt area. Enter it and move into the huge crypt room slowly.";
	hintVector[435] = "Mikrul Gauldurson and some draugr thralls will rise when you move far enough into the room. Try to sneak-attack Gauldurson or the thralls to get in some good starting damage, then run around for cover if necessary while finishing them off.";
	hintVector[436] = "Loot Gauldurson's body to get his amulet fragment and unique sword, then look for a claw keyhole gimmick near a spear gate at the south end of the area. Use it to lower the spear gate, giving you access to a Word Wall and a shortcut back to a previous area.";
	// Find the Gauldur Amulet Fragment in Geirmund's Hall.
	hintVector[437] = "Go to Geirmund's Hall, which is a short way directly east of Ivarstead.";
	hintVector[438] = "Kill off the skeevers in the first cave room, then look in the back for a large hole.";
	hintVector[439] = "Drop carefully down the hole so that you land in the water, then climb up the nearby log steps and go through a door to find a couple of frostbite spiders to kill.";
	hintVector[440] = "Watch for a dart trap's pressure plate just past them, then enter the crypt area cautiously. There are some reclining draugr that you can get the first strike against if you're sneaky.";
	hintVector[441] = "Past the gate, go down the short tunnel, then stay in it and lure draugr to you. When they stop coming, climb the log stairs in their room, then turn and look up at the raised bridges to see another draugr to take down.";
	hintVector[442] = "Open the nearby locked door by either picking its lock or getting the key from the dead guy on the slab, then kill the draugr and skeever that are in the next room.";
	hintVector[443] = "Move along the passage, killing another draugr, until you reach the raised bridge area.";
	hintVector[444] = "Kill the two draugr past the second bridge, then move over to the start of the swinging axe trap. Wait there as a draugr comes after you and gets chopped up, then quicksave and time your run through the axes.";
	hintVector[445] = "Use the chain past them to shut them off, then move on to where you drop down into a large chamber. This is where you're going to fight Sigdis Gauldurson.";
	hintVector[446] = "After you take Sigdis down, follow the quest arrow to his body, then loot it to get his amulet fragment and unique bow. Go down the tunnel past his sarcophagus until you reach a room with some treasure, then keep going to find a lever that opens a secret door that leads back to the entry area.";
	// Find the Gauldur Amulet Fragment in Saarthal.
	hintVector[447] = "You can only enter Saarthal and explore it while doing the second College of Winterhold main-line quest, so see it for all the details.";
	// Reforge the Gauldur Amulet.
	hintVector[448] = "Now you need to go to Reachwater Rock, which is a ways SE of Markarth.";
	hintVector[449] = "Enter the cave area, then move along the path until you reach an ancient Nordic puzzle door.";
	hintVector[450] = "Move past it and the other doors that lower to find another puzzle door.";
	hintVector[451] = "Go down the passage past the second puzzle door until you come to a large chamber, then cross it to find an altar with three small pedestals on it.";
	hintVector[452] = "Quicksave before you use the pedestals to place the Gauldur amulet fragments. After you place all three, you'll have to fight spectral versions of all three Gauldurson brothers, one right after another.";
	hintVector[453] = "After they're all defeated, stand and wait to get the next objective.";
	// Take the Gauldur Amulet.
	hintVector[454] = "Go up to the altar where you placed the three amulet pieces, then take the reforged amulet that's hovering over it. It'll have all three of the amulet fragments' magic attributes on it.";
	hintVector[455] = "To get some gold, jump onto the altar, then jump onto the higher ledge so you can loot the skeleton that's in the sarcophagus.";
	hintVector[456] = "The gate over the exit is now up. Go past it and move straight forward to find a now-open treasure niche to loot before you leave the area.";
	// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

	// The Forsworn Conspiracy - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
	// Steps.
	stepVector[135] = "How can I get this quest ?";
	stepVector[136] = "Go to the Shrine of Talos.";
	stepVector[137] = "Find evidence about Margret.";
	stepVector[138] = "(Optional)Obtain the key to Margret's room. ";
	stepVector[139] = "(Optional)Talk to Margret.";
	stepVector[140] = "Read Margret's Journal.";
	stepVector[141] = "Find evidence about Thonar.";
	stepVector[142] = "Read Thonar's Journal.";
	stepVector[143] = "Find evidence about Weylin.";
	stepVector[144] = "Read Weylin's Note.";
	stepVector[145] = "Find out who \"N\" is.";
	stepVector[146] = "Find evidence about Nepos.";
	stepVector[147] = "Read Nepos's Journal.";

	// Hints.
	// How can I get this quest ?
	hintVector[457] = "The first time you enter Markarth, stand and watch as a disguised forsworn guy goes nuts and starts attacking people.";
	hintVector[458] = "TIP: If you attack Weylin before he can get to Margret, you'll save her life. Talking to her afterward will get you a valuable piece of jewelry as a reward.";
	hintVector[459] = "Soon after it's over, an onlooker named Eltrys will talk to you and give you a note.";
	hintVector[460] = "Read it in the \"books\" section of your inventory to get this quest.";
	// Go to the Shrine of Talos.
	hintVector[461] = "Either follow Eltrys to the Shrine of Talos, or go there yourself later on.";
	hintVector[462] = "Talk to Eltrys inside the shrine area to get the \"Find evidence about Weylin\" and \"Find evidence about Margret\" objectives.";
	hintVector[463] = "Note that those objectives begin two separate lines of investigation, and you only need to complete one of them to finish this quest.";
	// Find evidence about Margret.
	hintVector[464] = "Go to the Silver-Blood Inn to start investigating Margret.";
	hintVector[465] = "After entering the inn, go down the first hallway on the left to find the locked door to Margret's room at the top of some steps.";
	hintVector[466] = "If you looted Margret's body earlier (or saved her life and then pickpocketed her), you'll have already gotten her key. Otherwise, ask Kleppr at the front counter about Margret to get the \"(Optional) Obtain the key to Margret's room\" objective (if Margret is dead) or the \"(Optional) Talk to Margret\" objective (if she's alive).";
	hintVector[467] = "Once you get her door open, go inside and look around for evidence.";
	hintVector[468] = "Her journal is in the end table next to the bed.";
	// (Optional)Obtain the key to Margret's room. 
	hintVector[469] = "Ask Kleppr if he has the key to Margret's room, then try to persuade or intimidate him into giving it to you. If that fails, you could bribe him to get it.";
	hintVector[470] = "Another alternative is to sneakily steal the key that's on a shelf behind the counter (on the west side).";
	hintVector[471] = "Or you could pickpocket the key from Kleppr or Frabbi.";
	// (Optional)Talk to Margret.
	hintVector[472] = "Find Margret sitting by the fire and ask her what she's doing in Markarth.";
	hintVector[473] = "You'll then get persuade, bribe, and intimidate options. Try the persuade option first, especially since it's the easiest one to pass.";
	hintVector[474] = "Getting Margret to tell you why she's in Markarth will bypass the need to get her journal, and will immediately get you the \"Find evidence about Thonar\" objective.";
	// Read Margret's Journal. 
	hintVector[475] = "Read Margret's journal in the \"books\" section of your inventory to get the next objective.";
	// Find evidence about Thonar.
	hintVector[476] = "When you leave the inn, a city guard will talk to you and make vague threats. However, that's nothing to worry about (yet).";
	hintVector[477] = "Optionally return to the Shrine of Talos and talk to Eltrys about the investigation to get some gold, then enter the nearby Treasury House building.";
	hintVector[478] = "Thonar Silver-Blood will be in a room behind a locked door.";
	hintVector[479] = "WARNING: Talking to Thonar will be the \"beginning of the end\" for this quest, and you won't be able to speak to Eltrys any more. If you haven't already investigated Weylin and gotten a reward from Eltrys for doing so, you may want to do that now.";
	hintVector[480] = "Talk to Thonar about Margret, then return to the previous room to find that two disguised forsworn have turned hostile.";
	hintVector[481] = "Help kill them, then talk to Thonar to finish up this line of investigation";
	hintVector[482] = "TIP: You can avoid this fight by sneakily pickpocketing Thonar's journal. Doing so will get you the \"Read Thonar's Journal\" objective.";
	hintVector[483] = "You can then work on the Weylin investigation if you want, but it's not necessary or particularly profitable. Return to the Shrine of Talos and talk to the guards inside, then choose to go quietly to finish this quest and get the \"No One Escapes Cidhna Mine\" quest.";
	// Read Thonar's Journal. 
	hintVector[484] = "Read Thonar's Journal in the \"books\" section of your inventory to finish up this line of the investigation.";
	// Find evidence about Weylin.
	hintVector[485] = "Go to the south end of the city, then follow the quest arrow to find the door to the Warrens area.";
	hintVector[486] = "Check all of the interior doors to find out which one is Weylin's, then sneakily pick it open.";
	hintVector[487] = "WARNING: Don't proceed unless you're ready to brawl with a tough opponent. Go stock up on healing potions if you're low.";
	hintVector[488] = "Check the chest in Weylin's room to find a special note. Take it to get the next objective.";
	// Read Weylin's Note. 
	hintVector[489] = "Read Weylin's note in the \"books\" section of your inventory to get the next objective.";
	// Find out who "N" is.
	hintVector[490] = "Exit the warrens to be confronted by a guy named Dryston.";
	hintVector[491] = "No matter what you say, he'll start a brawl with you.";
	hintVector[492] = "Remember not to use any spells or weapons other than your fists. Fortunately, you can use as many healing and stamina potions as you want during the brawl. Also, you can enter the nearby stream if you need a break.";
	hintVector[493] = "After you beat him, wait for him to talk to you and give you the next objective.";
	// Find evidence about Nepos.
	hintVector[494] = "Optionally return to the Shrine of Talos and talk to Eltrys about the investigation to get some gold, then find Nepos' house.";
	hintVector[495] = "WARNING: Entering Nepos' house will be the \"beginning of the end\" for this quest, and you won't be able to speak to Eltrys any more. If you haven't already investigated Margret and gotten a reward from Eltrys for doing so, you may want to do that now.";
	hintVector[496] = "Enter Nepos' house and move forward to get Uaile to talk to you.";
	hintVector[497] = "Tell her you're there to see Nepos, then wait until you hear Nepos' voice say it's okay.";
	hintVector[498] = "Go up some steps and turn right to find Nepos sitting next to a fire, then talk to him about Weylin and the forsworn.";
	hintVector[499] = "After the conversation ends, Nepos and his entire household will attack you. Kill them all to finish up this line of investigation.";
	hintVector[500] = "TIP: You can avoid this fight by sneakily pickpocketing Nepos' journal. Doing so will get you the \"Read Nepos's Journal\" objective.";
	hintVector[501] = "You can then work on the Margret investigation if you want, but it's not necessary or particularly profitable. Return to the Shrine of Talos and talk to the guards inside, then choose to go quietly to finish this quest and get the \"No One Escapes Cidhna Mine\" quest.";
	// Read Nepos's Journal.
	hintVector[502] = "Read Thonar's Journal in the \"books\" section of your inventory to finish up this line of the investigation.";
	// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

	// The Golden Claw - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
	// Steps.
	stepVector[148] = "No Steps - Select this for hints.";

	// Hints.
	hintVector[503] = "Talk to Lucan Valerius in Riverwood's trader shop to get this quest.";
	hintVector[504] = "You can then optionally follow Camilla Valerius to the bridge that leads out of town, though it's easy enough to find the bridge yourself.";
	hintVector[505] = "The Golden Claw is obtained and used on the third Main Quest. After you finish it, return to the Riverwood Trader and talk to Lucan to get your reward.";
	// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

	// The Heart of Dibella - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
	// Steps.
	stepVector[149] = "How can I get this quest ?";
	stepVector[150] = "Find the future Sybil of Dibella.";
	stepVector[151] = "Rescue Fjotra from the Forsworn.";
	stepVector[152] = "Bring Fjotra to the Temple.";
	stepVector[153] = "Pray at Dibella's Altar.";

	// Hints.
	// How can I get this quest ?
	hintVector[506] = "Travel to Markarth and enter its Temple of Dibella.";
	hintVector[507] = "At the east end of the main temple area is the locked door to the Inner Sanctum. You need to get in there, so either sneakily pick the lock or pickpocket the key from Senna.";
	hintVector[508] = "Quicksave, then go down the stairs and around to the door that leads to the Inner Sanctum's main chamber.";
	hintVector[509] = "Enter the chamber to get a priestess to talk to you, then agree to speak to the \"mother.\" That's Hamal, so talk to her to get this quest.";
	hintVector[510] = "NOTE: The priestesses sometimes turn hostile even if you say the right things. If that happens, quickrestore and try again. Also note that you might want to do the \"Steal the statue in the Temple of Dibella\" miscellaneous quest before getting this quest.";
	// Find the future Sybil of Dibella.
	hintVector[511] = "The new Sybil is supposedly at Karthwasten, so go there next. See the Markarth section of the World Map Exploration Guide if you need directions.";
	hintVector[512] = "When you arrive, talk to someone and ask about a young girl who lives around there to be referred to Enmon.";
	hintVector[513] = "Follow the new quest arrow to find him, then ask him about the young girl.";
	hintVector[514] = "Tell him that she's the new Sybil of Dibella to get the next objective, then either accept him as a temporary follower or tell him to stay where it's safe. (Note that he's a wimpy fighter, and can be easily killed, so it's best to leave him behind.)";
	// Rescue Fjotra from the Forsworn.
	hintVector[515] = "Go to Broken Tower Redoubt, which is a ways directly east of Karthwasten, then kill off the outdoor forsworn.";
	hintVector[516] = "Enter the building and sneak along the passage until you see a forsworn standing in a large room. Sneak-attack her, then watch for another one patrolling the upstairs area.";
	hintVector[517] = "After you sneak-attack her, go up the stairs and turn right. Past a door, carefully avoid two pressure plates on the floor near where the passage turns right.";
	hintVector[518] = "Sneak slowly forward to the circular tower area, watching for another forsworn either directly ahead or in the area to the right. After she's down, go through the wooden door on the east side of the tower.";
	hintVector[519] = "Move along the passage until you enter another circular tower area, then sneak your way over to the base of a wide staircase. Sneak slowly up the staircase until you can sneak-shoot a forsworn, then back up a bit and wait for two more to come investigate";
	hintVector[520] = "Note that one of them is bound to hit the tripwire that dumps some large rocks onto the staircase, so be careful not to be hit by any of those. After the forsworn are all killed, go to the top of the staircase and through a room to reach another staircase.";
	hintVector[521] = "Go through the door at the top of it to get back outside, then go across to a door that leads back inside. Crouch down before going through the door, then wait for a good opportunity to sneak-shoot the powerful forsworn briarheart who's on the other side of the area.";
	hintVector[522] = "Take him down as quickly as you can, then use the Flames spell from a safe distance to detonate the rune trap that's in the middle of the area. On the other side is the locked cell that Fjotra is being held in.";
	hintVector[523] = "Either pick the lock or get the prison key from the briarheart, then talk to Fjotra to get the next objective.";
	// Bring Fjotra to the Temple.
	hintVector[524] = "Go back outside, then go over toward the other door if necessary to be able to fast-travel to Markarth.";
	hintVector[525] = "Return to the Temple of Dibella's Inner Sanctum area, then follow the quest arrow to Hamal.";
	hintVector[526] = "Talk to her about retrieving the Sybil to get the next objective.";
	// Pray at Dibella's Altar.
	hintVector[527] = "Return to the main temple area and activate the large central altar to get the special Agent of Dibella perk, which increases the damage you do to NPCs of the opposite sex. (Note that Hamal will also now be a trainer of the Enchanting skill.)";
	// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

	// In My Time of Need - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
	// Steps.
	stepVector[154] = "Find the Redguard woman.";
	stepVector[155] = "Speak with Saadia or Inform the Alik'r of Saadia's location.";
	stepVector[156] = "Talk to the Alik'r prisoner or Inform the Alik'r of Saadia's location.";
	stepVector[157] = "Kill Kematu.";
	stepVector[158] = "Kill Kematu or talk to him.";
	stepVector[159] = "Return to Saadia.";
	stepVector[160] = "Lead Saadia to the Whiterun Stables.";
	stepVector[161] = "Speak with Saadia.";

	// Hints.
	// Find the Redguard woman.
	hintVector[528] = "The Alik'r think that the woman they're after is in Whiterun, so look around for her there.";
	hintVector[529] = "Talk to any dark-skinned women you can find to see if they have any relevant dialogue topics.";
	hintVector[530] = "Saadia in the Bannered Mare inn is the one you're after. Talk to her about the Alik'r to get the next objective.";
	// Speak with Saadia or Inform the Alik'r of Saadia's location.
	hintVector[531] = "Before you decide who to side with, follow Saadia into an upstairs bedroom.";
	hintVector[532] = "Talk to her there to learn more about the situation, and to get the next objective.";
	// Talk to the Alik'r prisoner or Inform the Alik'r of Saadia's location.
	hintVector[533] = "Now you need to make a decision on whether or not to help Saadia. If you want to, skip to the next hint. Otherwise, go to Rorikstead (see the Morthal section of the World Map Exploration Guide) and talk to the Alik'r in the inn to get the \"Lead Saadia to the Whiterun Stables\" objective.";
	hintVector[534] = "Enter Dragonsreach, then look for the door to the dungeon down some steps a ways to the left of the Jarl's throne.";
	hintVector[535] = "Go up to the door of the last cell on the dungeon's left side, then wait if necessary for the Alik'r prisoner to walk up to where you can talk to him.";
	hintVector[536] = "He'll say that he'll help you in exchange for you paying his fine, which is 100 gold.";
	hintVector[537] = "Talk to any nearby guard to pay the fine, then talk to the prisoner again to get the next objective.";
	// Kill Kematu.
	hintVector[538] = "Kematu is hiding out in the Swindler's Den. See the Morthal section of the World Map Exploration Guide if you need help getting there.";
	hintVector[539] = "Kill the bandit who's guarding the den's entrance, then go inside and fight the two bandits in the first cave room.";
	hintVector[540] = "After you kill off the two bandits in the second cave room, approach the third cave room slowly and sneakily. There are three bandits in it, plus three more who'll run in and join the battle.";
	hintVector[541] = "It's best to snipe at the three starting bandits from the passage that leads into their room, then retreat along the passage as you finish them off. That may allow you to sneak up on the other three bandits, or at least not have to fight them all at the same time.";
	hintVector[542] = "Move on until you reach the upper floor of that room, then disarm the two bear traps that are near the entrance to another tunnel.";
	hintVector[543] = "Go along the tunnel until you enter the room where Kematu and his Alik'r warriors are hanging out. At that point, you'll get the next objective";
	// Kill Kematu or talk to him.
	hintVector[544] = "Go up the ramp and over to where Kematu is standing, then talk to him about Saadia.";
	hintVector[545] = "If you agree to help him capture Saadia, you'll get the \"Lead Saadia to the Whiterun Stables\" objective.";
	hintVector[546] = "If you insist on killing him, he and all his warriors will turn hostile. As soon as the conversation is over, turn left and drop down into the water, then sprint along the tunnel to try and leave at least some of them behind.";
	hintVector[547] = "Turn around and fight whenever you can do so without being overwhelmed, then keep sprinting away and leading the Alik'r down the narrow, winding passages until you've depleted their numbers.";
	hintVector[548] = "Or you can instead sprint for the very narrow tunnel that starts in the back of their cave room. They'll have a very hard time following you down that tunnel, even if you don't clog it with summoned creatures.";
	hintVector[549] = "After you finish them all off, including Kematu, you'll get the next objective.";
	// Return to Saadia.
	hintVector[550] = "Return to Whiterun's inn and talk to Saadia to get some gold and finish the quest.";
	// Lead Saadia to the Whiterun Stables.
	hintVector[551] = "Return to Whiterun's inn and talk to Saadia.";
	hintVector[552] = "Tell her some lies to get her to follow you, then leave the inn and follow her to the Whiterun Stables.";
	hintVector[553] = "After she stops near a guy named Kematu, you can either wait until he paralyzes her, or you can attack him and kill him before he does that.";
	hintVector[554] = "If you let him paralyze her, talk to him to get some gold and finish the quest. If you killed him, you'll get the next objective.";
	// Speak with Saadia.
	hintVector[555] = "Return to Whiterun's inn and talk to Saadia to get some gold and finish the quest.";
	// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

	// Kyne's Sacred Trials - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
	// Steps.
	stepVector[162] = "Defeat the Guardian Mudcrab.";
	stepVector[163] = "Defeat the Guardian Skeever.";
	stepVector[164] = "Defeat the Guardian Wolf.";
	stepVector[165] = "Return to Froki.";
	stepVector[166] = "Defeat the Guardian Bear.";
	stepVector[167] = "Defeat the Guardian Mammoth.";
	stepVector[168] = "Defeat the Guardian Sabre Cat.";
	stepVector[169] = "Return to Froki.";
	stepVector[170] = "Defeat the Guardian Troll.";
	stepVector[171] = "Return to Froki.";

	// Hints. 
	// Defeat the Guardian Mudcrab.
	hintVector[556] = "Travel to Gjukar's Monument (see the Morthal section of the World Map Exploration Guide), then look to the SE to see the large, ghostly mudcrab spirit.";
	hintVector[557] = "Hit it with some ranged attacks, then finish it off to complete this objective.";
	// Defeat the Guardian Skeever.
	hintVector[558] = "Travel to the Windward Ruins (see the Dawnstar section of the World Map Exploration Guide), then look in or near the ruins for the large, ghostly skeever spirit.";
	hintVector[559] = "Hit it with some ranged attacks, then finish it off to complete this objective.";
	// Defeat the Guardian Wolf.
	hintVector[560] = "Travel to North Shriekwind Bastion (see the Falkreath section of the World Map Exploration Guide), then go east through the forest until you spot the large, ghostly spirit wolf in the distance near some regular wolves.";
	hintVector[561] = "Hit them with some ranged attacks, then finish them off to complete this objective.";
	// Return to Froki.
	hintVector[562] = "Return to Froki's shack and tell Froki about defeating the guardians to get the next three objectives, which can be done in any order.";
	// Defeat the Guardian Bear.
	hintVector[563] = "Travel to the Twilight Sepulcher (see the Falkreath section of the World Map Exploration Guide), then go east from it until you can turn left and go up a small slope.";
	hintVector[564] = "Turn left and go along the rocks until you can make your way around to where the large, ghostly spirit bear is.";
	hintVector[565] = "You probably won't be able to see it before it spots you, so have your best melee weapon and/or spells ready. It'll be a *lot* tougher than the first batch of guardians, just as Froki warned.";
	// Defeat the Guardian Mammoth.
	hintVector[566] = "Travel to the Lorieus Farm (see the Whiterun section of the World Map Exploration Guide), then go west from it until you reach some rocks overlooking a mammoth's graveyard.";
	hintVector[567] = "Move around on the rocks until the large, ghostly mammoth spirit appears, then start hitting it with ranged attacks.";
	hintVector[568] = "It's fairly slow and clumsy, so you should be able to maneuver around on the rocks to avoid its attacks while taking it down at range.";
	// Defeat the Guardian Sabre Cat.
	hintVector[569] = "Travel to Bleakcoast Cave (see the Winterhold section of the World Map Exploration Guide), then go south to the water.";
	hintVector[570] = "Follow the water west until you can see the large, ghostly spirit cat on your left.";
	hintVector[571] = "You probably won't be able to see it before it spots you, so have your best melee weapon and/or spells ready.";
	// Return to Froki.
	hintVector[572] = "Return to Froki's shack and tell Froki about defeating the guardians to get the final guardian objective.";
	// Defeat the Guardian Troll.
	hintVector[573] = "Travel to Graywinter Watch (see the Whiterun section of the World Map Exploration Guide), then go inside.";
	hintVector[574] = "There are three regular trolls in there in addition to the troll spirit. Crouch down as soon as you enter the cave and sneak-shoot the nearest troll.";
	hintVector[575] = "Try to kill it before it reaches you. Even if you can, the other trolls will probably come after you right away.";
	hintVector[576] = "Back out of the cave if you need to, since the trolls won't follow you outside. Go back in when you're ready, but be warned that all of the trolls will probably gang up on you at once, including the guardian spirit.";
	hintVector[577] = "Bring a tough follower and loads of healing potions, and summon the most powerful creature you can to help you finish off all of the trolls";
	hintVector[578] = "If all else fails, try sprinting past the trolls and hiding behind the tent in the camp area while hitting them with ranged attacks.";
	// Return to Froki.
	hintVector[579] = "Look on the barrels in the back of the cave for Froki's unique magic bow and an Archery skill book, then return to Froki's shack.";
	hintVector[580] = "Tell him about defeating the guardian troll to finish the quest and get Kyne's Token, an amulet that reduces the damage you take from animals and increases the damage you do with bows.";
	// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

	// Laid to Rest - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
	// Steps.
	stepVector[172] = "Talk to the Jarl.";
	stepVector[173] = "Investigate the burned house.";
	stepVector[174] = "Find Helgi after dark.";
	stepVector[175] = "Ask Thonnir about Laelette.";
	stepVector[176] = "Investigate Alva's house.";
	stepVector[177] = "Show Alva's Journal to the Jarl.";
	stepVector[178] = "Kill the master vampire.";
	stepVector[179] = "Return to Morthal's Jarl.";

	// Hints. 
	// Talk to the Jarl.
	hintVector[581] = "Enter Highmoon Hall and talk to the Jarl about the burned house to get the next objective.";
	// Investigate the burned house.
	hintVector[582] = "Find the burned-out house just SW of the inn, then go inside to find the ghost of the girl who died in the fire.";
	hintVector[583] = "Talk to her to get the next objective.";
	// Find Helgi after dark.
	hintVector[584] = "Wait until after 8 pm if necessary, then start looking for Helgi.";
	hintVector[585] = "To get a quest arrow to follow, talk to the Jarl again in Highmoon Hall and ask about finding Helgi.";
	hintVector[586] = "Follow the quest arrow to the graveyard, then kill the woman named Laelette the Vampire.";
	hintVector[587] = "Activate the child's coffin to talk to Helgi and get the next objective.";
	// Ask Thonnir about Laelette.
	hintVector[588] = "Thonnir ran up to Laelette's body, so talk to him about his wife to get the next objective.";
	// Investigate Alva's house.
	hintVector[589] = "Go over to the east side of town to find Alva's house, which is always locked.";
	hintVector[590] = "Once in the house, go down the stairs and enter the cellar to find Alva's coffin.";
	hintVector[591] = "If it's daytime, Alva will be asleep in the coffin, but she'll wake up if you attack her or unsuccessfully try to sneak around.";
	hintVector[592] = "You need to get the journal that's inside the coffin. That'll be easy if Alva is already dead, or if she's in the coffin and you use the Muffle spell to keep from waking her up.";
	hintVector[593] = "Note that if she wakes up, you can grab the journal and run, but she'll follow you outside, and no one will help you kill her. (Lazy town guards!) Also note that if you sneakily steal the journal without her detecting you, she'll flee to Movarth's Lair.";
	hintVector[594] = "Whether you kill Alva or not, getting her journal will get you the next objective.";
	// Show Alva's Journal to the Jarl.
	hintVector[595] = "Go to Highmoon Hall and talk to the Jarl about Alva setting the fire to get the next objective.";
	// Kill the master vampire.
	hintVector[596] = "Exit Highmoon Hall to find an angry mob of villagers, then wait for them to start off to the north. (If they don't after awhile, head north a ways to get them going.)";
	hintVector[597] = "Follow them along until you reach Movarth's Lair, then talk to Thonnir and decide whether or not you want him to go into the lair with you. (Everyone else will chicken out and return to Morthal.) Thonnir isn't much of a fighter, and you'd be better off with a regular follower -- or maybe no follower at all if you want to use sneaky tactics, which are highly recommended.";
	hintVector[598] = "Enter the lair and kill the two frostbite spiders in the first cave room, then sneak into the second cave room and hit the seated vampire thrall with a sneak attack.";
	hintVector[599] = "Use the tunnel that starts to the left of the thrall's table to reach a large cavern, where another thrall is in a small pit with several dead bodies";
	hintVector[600] = "After you kill him, go to the cavern's northern exit, then sneak up the slanty ground on the left so you can get onto the board walkway.";
	hintVector[601] = "Sneak over to where you can just barely see Movarth Piquine seated at the head of his gross banquet table, then hit him with a sneaky arrow.";
	hintVector[602] = "If you then move up against the wall and stay still, it's likely that neither Movarth nor his minions will detect you. Wait until they stop searching for you, then hit Movarth with another sneaky arrow.";
	hintVector[603] = "You'll get the next objective when Movarth is killed, and can then sneak back out of the cave if you don't want to kill any more vampires.";
	// Return to Morthal's Jarl.
	hintVector[604] = "Go back the way you came to exit the cave, and talk to Helgi when you meet her near the exit.";
	hintVector[605] = "Return to Morthal, then tell the Jarl in Highmoon Hall that Movarth is dead to finish the quest and get some gold.";
	// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

	// Lights Out! - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
	// Steps.
	stepVector[180] = "Put out the fire in the Solitude Lighthouse.";
	stepVector[181] = "Return to Jaree - Ra.";
	stepVector[182] = "Find Deeja at the Wreck of the Icerunner.";
	stepVector[183] = "Defeat Deeja.";
	stepVector[184] = "Find out where Jaree - Ra's bandits took the loot.";
	stepVector[185] = "Travel to Broken Oar Grotto.";
	stepVector[186] = "Defeat Jaree - Ra.";

	// Hints. 
	// Put out the fire in the Solitude Lighthouse.
	hintVector[606] = "Head down to the lighthouse, which is a ways NE of Solitude.";
	hintVector[607] = "Don't enter the lighthouse's interior area, but instead climb up its exterior steps to get to its top.";
	hintVector[608] = "Move up to the large fire so you can activate it to get the next objective.";
	// Return to Jaree - Ra.
	hintVector[609] = "Fast-travel to the East Empire Company Warehouse or Katla's Farm, then find Jaree-Ra near the start of the docks' boardwalk.";
	hintVector[610] = "Talk to him to get the next objective.";
	// Find Deeja at the Wreck of the Icerunner.
	hintVector[611] = "The new Wreck of the Icerunner location is a long way directly east of Solitude. A good way to get there is to return to the lighthouse and head SE.";
	hintVector[612] = "When you arrive, check the two rowboats near the Icerunner to see that the marauders have already started loading stolen loot into them. Sneakily steal some if you can, then go over to the marauder mage.";
	hintVector[613] = "After he tells you that Deeja's down in the hold, board the Icerunner using the nearby ramp, then look around for more loot to sneakily steal before using the door to enter the ship's interior area.";
	hintVector[614] = "Go down the stairs and look for more loot as you make your way to the stairs that lead down into the hold.";
	hintVector[615] = "Go up the ramp on its other side, then go through a door to find Deeja. Quicksave, then talk to her to get the next objective.";
	// Defeat Deeja.
	hintVector[616] = "The marauder in the hold will be hostile to you, too, so try to keep the battle with Deeja confined to her room so you'll only have to fight her.";
	hintVector[617] = "If you quicksaved before talking to Deeja, you might want to quickrestore, then sneak-attack her after closing her room's door.";
	// Find out where Jaree - Ra's bandits took the loot.
	hintVector[618] = "Loot Deeja to get a note from Jaree-Ra.";
	hintVector[619] = "Read it in the \"books\" section of your inventory to get the next objective.";
	// Travel to Broken Oar Grotto.
	hintVector[620] = "Fight your way back through the boat, using sneak attacks if you can, then exit to the outside to find one last marauder to kill near a rowboat.";
	hintVector[621] = "After taking him out, travel to Broken Oar Grotto, which is a ways NW of the lighthouse.";
	hintVector[622] = "Enter the grotto to get the next objective.";
	// Defeat Jaree - Ra.
	hintVector[623] = "Sneak over to where you can drop into the water, then check next to a large underwater rock for a skeleton and a chest.";
	hintVector[624] = "Swim down to the north end of the area, watching for another underwater skeleton next to a rock as you go. (Note that a Waterbreathing spell or item would be handy for letting you stay underwater without having to surface and risk being seen.)";
	hintVector[625] = "Turn east and loot another skeleton and chest next to a rock, then swim down to the base of the large wooden structure that Jaree-Ra is on.";
	hintVector[626] = "Look just past the structure for a half-sunken boat with a locked chest on it, then get on either of the boat's two ends and see if you can snipe at any of the marauders on the wooden structure.";
	hintVector[627] = "If you're on the west end of the ship, you may be able to shoot Jaree-Ra himself. In any case, fire some arrows his way, then shoot down the marauders as they run into range. Even if you're spotted, you should be fairly safe if you stay on the boat (though watch out for an enemy archer firing down at you from a high-up rocky arch).";
	hintVector[628] = "The quest will be completed when Jaree-Ra dies, though you may still have marauders to kill. (Note that if you reenter the water and swim back the way you came, you may be able to leave without fighting any more of them. However, that would keep you from fully looting the area.)";
	// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

	// QUEST: The Man Who Cried Wolf - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
	// Steps.
	stepVector[187] = "Clear out Wolfskull Cave.";
	stepVector[188] = "Speak to Falk Firebeard.";

	// Hints. 
	// Clear out Wolfskull Cave.
	hintVector[629] = "Travel to Wolfskull Cave, which is a long way west of Solitude.";
	hintVector[630] = "Kill the two skeletons that are just outside the cave, then enter it and make your way along until you meet a draugr.";
	hintVector[631] = "Past it is a cave with two necromancers in it. Try to sneak-attack them, then look for a door with torches on either side of it.";
	hintVector[632] = "Just past it is a necromancer, a draugr wight, and a skeleton. Finish them off, then carefully drop into the large pit.";
	hintVector[633] = "Go down the next tunnel to enter the Wolfskull Ruins area, then crouch down and move forward to the tip of the rocky ridge with the flaming brazier on it. From there, see how many draugr and necromancers you can snipe with your bow or ranged spells. (Fireball is a particularly great spell to use for this.)";
	hintVector[634] = "Look all around the old fortress for targets, including on top of the tower where a shimmery ghost-like figure is hovering. (It's not a target, but the necromancers near it are.) When you've gotten all you can from there, carefully drop down the rocks that are on the right side of the ridge to reach the lower ground.";
	hintVector[635] = "Go up the stone steps ahead, then look in the tower on your left for a draugr to kill. Go up the steps past the tower, then go up some more steps past that and turn left to find more steps.";
	hintVector[636] = "Past another set of steps, move on and around to where you reach the base of the tower that has the ghostly figure hovering above it. Even if you managed to snipe one or two of that tower's necromancers from the rocky ridge, there may still be several up there.";
	hintVector[637] = "Try to sneak in and lure them away from the ritual area one or two at a time. When you kill the one called Ritual Master, you'll get the next objective. (Note that the Ritual Master might have gotten killed while fighting some of the draugr if you sniped the necromancers on the tower earlier.)";
	// Speak to Falk Firebeard.
	hintVector[638] = "Kill any remaining necromancers, then use the lever that's to the left of the raised bridge on top of their tower to lower it.";
	hintVector[639] = "Cross the bridge to another tower, then go down its stairs and through a doorway to find a door leading back to the Wolfskull Cave area.";
	hintVector[640] = "Drop down to find yourself near the cave's exit, then leave the cave and return to the Blue Palace.";
	hintVector[641] = "Tell Falk Firebeard what happened in the cave to finish the quest and get some gold.";
	// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

	// Missing in Action - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
	// Steps.
	stepVector[189] = "Meet Fralia in her home.";
	stepVector[190] = "Find evidence of Thorald's fate.";
	stepVector[191] = "Deliver proof to Avulstein.";
	stepVector[192] = "Find a way to release Thorald from Thalmor custody.";
	stepVector[193] = "Meet Avulstein at Northwatch Keep.";
	stepVector[194] = "Rescue Thorald from Northwatch Keep.";
	stepVector[195] = "Lead Thorald to safety.";
	stepVector[196] = "Speak to Thorald Gray-Mane.";
	stepVector[197] = "Return to Fralia Gray-Mane.";

	// Hints.
	// Meet Fralia in her home.
	hintVector[642] = "Follow Fralia into House Gray-Mane, then wait until Avulstein Gray-Mane talks to you and gives you the next objective.";
	// Find evidence of Thorald's fate.
	hintVector[643] = "There are three ways to get the information you need.";
	hintVector[644] = "One way is to find it inside the House of Clan Battle-Born.";
	hintVector[645] = "Another way is to find Idolaf Battle-Born and persuade him to tell you where Thorald is. That requires you to pass a fairly tough persuade dialogue option.";
	hintVector[646] = "If you can't do either of those ways, find Jon Battle-Born and convince him to help you.";
	// Deliver proof to Avulstein.
	hintVector[647] = "Return to House Gray-Mane and talk to Avulstein about the proof you found.";
	hintVector[648] = "You can then say you'll join him in the assault on Northwatch Keep, or you can tell him to stay hidden.";
	hintVector[649] = "If you join the assault, you'll get the \"Meet Avulstein at Northwatch Keep\" objective. Otherwise, you'll get the \"Find a way to release Thorald from Thalmor custody\" objective.";
	// Find a way to release Thorald from Thalmor custody.
	hintVector[650] = "Rescuing Thorald without Avulstein's help works pretty much like it does in the \"Rescue Thorald from Northwatch Keep\" objective, with the exceptions that you won't have any combat support (unless you bring a follower) and sneaking around unseen will be a lot easier.";
	hintVector[651] = "Using stealth to enter the keep unseen is very difficult, even if you have the Muffle spell and Invisibility potions. Besides, you'll need all of the outdoor guards to be dead when you exit the keep with Thorald later.";
	hintVector[652] = "Bring a tough, well-equipped follower, and use sneaky ranged attacks and summoned creatures to help you kill off all of the keep's exterior guards. After that, enter the keep through its unlocked door and make your way through it as outlined in the above-mentioned objective.";
	// Meet Avulstein at Northwatch Keep.
	hintVector[653] = "Look for Avulstein and his men behind a large rock a short way east of the keep's entrance.";
	hintVector[654] = "Talk to Avulstein to get the next objective.";
	// Rescue Thorald from Northwatch Keep.
	hintVector[655] = "Lead Avulstein and the boys over to a spot near the keep's entrance, then stay back and use ranged attacks as they move in on the Northwatch guards.";
	hintVector[657] = "There are a lot of well-armed guards, and your group can be very easily overwhelmed. Try to lead any guard who comes after you away from the keep so they won't all get after you at once.";
	hintVector[658] = "At least Avulstein is unkillable, so he'll keep on being helpful -- when he's not temporarily disabled, anyway. After all of the guards are killed, enter the keep through its unlocked door.";
	hintVector[659] = "Crouch down and sneak down the steps in the first room so you can get the drop on the guard and mage in the second room, then go through a wooden door and sneak over to where you can ambush an archer who's at the bottom of some more steps.";
	hintVector[660] = "Sneak down the steps and try to sneak-attack the two guards in the next room. On past that, you'll find two more guards and a mage in a large two-floor room. (Note that the mage starts behind a door on the lower floor.)";
	hintVector[661] = "Use the passage on the upper floor of that room to move on to an area with a seated guard on the right and the Northwatch interrogator in a side room on the left. Try to sneak-attack both of them, then follow Avulstein as he walks up to Thorald.";
	hintVector[662] = "After he talks to Thorald, do so yourself to get the next objective.";
	// Lead Thorald to safety.
	hintVector[663] = "Wait for Thorald to free himself from his shackles and pick up a nearby weapon, then lead him out of the keep.";
	hintVector[664] = "You could retrace your steps and leave the keep the same way you entered it, but there is a shortcut exit available if you don't mind fighting two more guards.";
	hintVector[665] = "Leave the interrogator's room and go across to where there was a seated guard earlier.";
	hintVector[666] = "Open the nearby door, then sneak-attack the two guards in the area beyond. (Or sneak up to where you can use the two levers on the left to release some prisoners as a distraction.)";
	hintVector[667] = "After they're dead, go past them to find a locked door that leads outside.";
	hintVector[668] = "If you can't pick the lock, go back and loot the interrogator's body to get the key.";
	hintVector[669] = "You'll get the next objective when you exit the keep.";
	// Speak to Thorald Gray-Mane.
	hintVector[670] = "Talk to Thorald to get the next objective.";
	// Return to Fralia Gray-Mane.
	hintVector[671] = "Return to Whiterun and follow the quest arrow to Fralia, then tell her that Thorald is safe to finish the quest and get a random enchanted steel weapon.";
	// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

	// No One Escapes Cidhna Mine - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
	// Steps.
	stepVector[198] = "Ask a prisoner about Madanach.";
	stepVector[199] = "Get past Borkul the Beast.";
	stepVector[200] = "Talk to Madanach.";
	stepVector[201] = "Hear Braig's story.";
	stepVector[202] = " Return to Madanach.";
	stepVector[203] = "Kill Grisvar the Unlucky.";
	stepVector[204] = " Return to Madanach.";
	stepVector[205] = "Follow Madanach.";
	stepVector[206] = "Kill Madanach.";
	stepVector[207] = "Search Madanach's body.";
	stepVector[208] = "Read Madanach's note.";
	stepVector[209] = "Escape Cidhna Mine.";

	// Hints.
	// Ask a prisoner about Madanach.
	hintVector[672] = "After talking to the orc guard, leave your cell and go down to where a guy named Uraccen is sitting by a fire.";
	hintVector[673] = "Ask him where Madanach is to get the next objective.";
	// Get past Borkul the Beast.
	hintVector[674] = "You'll find Borkul next to a locked gate nearby.";
	hintVector[675] = "Talk to Borkul about seeing Madanach to learn that he wants you to get him a shiv.";
	hintVector[676] = "First, try using the persuade option. If that fails, you might want to try brawling with him.";
	hintVector[677] = "Another option is to pickpocket the key from him. For some reason, he won't pay any attention when you open the gate with the key after pickpocketing it.";
	hintVector[678] = "The only other option is to ask him about the shiv he wants, then go get it for him.";
	// Talk to Madanach.
	hintVector[679] = "Go through Borkul's gate and down the tunnel to find Madanach sitting at a table and writing.";
	hintVector[680] = "Talk to him, choosing whichever dialogue options you want, until you get the next objective.";
	// Hear Braig's story.
	hintVector[681] = "Go back the way you came until you reach the central cave area, then return to Grisvar the Unlucky's side tunnel.";
	hintVector[682] = "Continue along that tunnel until you find Braig, then talk to him to get the next objective.";
	// Return to Madanach.
	hintVector[683] = "Go back to Madanach's room and talk to him to get the next objective.";
	// Kill Grisvar the Unlucky.
	hintVector[684] = "If you don't have a shiv, mention that fact to Madanach to get one.";
	hintVector[685] = "You'll then need to decide whether to aid Madanach in his escape or kill him and use his escape plan for yourself. Aiding him will get you the Old Gods armor set (see the Unique Light Armor List) as a reward, and killing him will get you the Silver-Blood Family Ring (see the Unique Rings List) instead. Also note that aiding him requires much less combat than killing him.";
	hintVector[686] = "If you want to kill Madanach, sneak-attack him with a shiv to get the \"Kill Madanach\" objective. Otherwise, continue with this objective.";
	hintVector[687] = "Go find Grisvar the Unlucky is his usual area, then talk to him and say that Madanach says hello.";
	hintVector[688] = "He'll turn hostile, but you don't have to fight him yourself. Just dodge his blows (if necessary) until the other mine residents finish him off for you.";
	// Return to Madanach.
	hintVector[689] = "Return to Madanach's room and tell him that Grisvar is dead to get the next objective.";
	// Follow Madanach.
	hintVector[690] = "Follow Madanach to the central cave area, then wait until he talks to you.";
	hintVector[691] = "Follow him some more he goes through a door to the Markarth Ruins area.";
	hintVector[692] = "Go through the door, then keep following him along, letting him and the others fight the spiders and dwarven machines as you come to them.";
	hintVector[693] = "You'll eventually reach the exit area, where Madanach will talk to you. After he returns all your confiscated goods and gives you the Old Gods armor set, follow him out the door.";
	hintVector[694] = "NOTE: Right after Madanach gives you your stuff, you can equip your best armor and weapon, then quickly attack him before he leaves. It'll be *very* tough, but if you can kill him and his followers, you can go outside and talk to Thonar Silver-Blood to get the other quest reward, too. When Madanach dies, you'll jump to the \"Search Madanach's body\" objective.";
	hintVector[695] = "Wait for the quest to end, after which Madanach and the other escapees will fight their way out of the city. You won't have to do that, and can fast-travel away if you like -- though you might find it more profitable to follow the forsworn along and loot their victims. (Also, return to the Shrine of Talos and loot Eltrys' body to find a good chunk of gold.)";
	hintVector[696] = "One final note is that the forsworn at the Druadach Redoubt will be friendly to you from now on.";
	// Kill Madanach.
	hintVector[697] = "Madanach has quite a bit of health and knows some magic, so he'll be hard to kill if you're not really good with one-handed weapons and magic spells. A high magic resistance would also be helpful.";
	hintVector[698] = "If you can manage to kill him, you'll get the next objective.";
	// Search Madanach's body.
	hintVector[699] = "Loot Madanach's body to get his note and the next objective.";
	// Read Madanach's note.
	hintVector[700] = "Read the note you got from Madanach in the \"books\" section of your inventory to get the next objective.";
	// Escape Cidhna Mine.
	hintVector[701] = "Get the key from Madanach's body if you haven't already, then open the locked barred door that's nearby.";
	hintVector[702] = "Go down the tunnel past it to find a large golden door that leads into the Markarth Ruins area.";
	hintVector[703] = "Move through the ruins until you go up some stone steps, then look a short way past them for a dwarven-style chest. It may have some items in it that'll be useful in the upcoming combats.";
	hintVector[704] = "When you start seeing spider webs, look for a couple of frostbite spiders to kill just ahead.";
	hintVector[705] = "In the area past theirs, you'll encounter two dwarven spheres. They'll be difficult to take down unless you have some strong magic to use against them (and to protect yourself with).";
	hintVector[706] = "Look on the lower floor of the spheres' area for some potions and a chest to loot, then move on to find the exit doors.";
	hintVector[707] = "After you exit, Thonar Silver-Blood will talk to you. He'll give you the Silver-Blood Family Ring and all of your confiscated inventory items, after which the quest will end.";
	hintVector[708] = "TIP: Return to the Shrine of Talos and loot Eltrys' body to find a good chunk of gold.";
	// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

	// Promises to Keep - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
	// Steps.
	stepVector[210] = "Speak to Sibbi Black - Briar.";
	stepVector[211] = "Steal Frost's Lineage Papers.";
	stepVector[212] = "(Optional)Steal the Lodge Stash.";
	stepVector[213] = "Steal Frost.";
	stepVector[214] = "Return to Louis Letrush.";

	// Hints.
	// Speak to Sibbi Black - Briar.
	hintVector[709] = "Approach the entrance to Mistveil Keep, then look to the right of it for the entrance to the Riften Jail area.";
	hintVector[710] = "To get past the locked door in the jail, talk to the seated guard and bribe him or pass a persuade check, or quicksave and try pickpocketing his jail key until you succeed.";
	hintVector[711] = "Past the door, go straight down to the wooden railing, then go left to find Sibbi Black-Briar's cell.";
	hintVector[712] = "Talk to him about Letrush sending you, then try to pass the persuade dialogue option that comes up. You don't have to, but it'll get you an optional objective and the key to a strong box.";
	// Speak to Sibbi Black - Briar.
	hintVector[713] = "You now need to go to the Black-Briar Lodge. See the Riften section of the World Map Exploration Guide if you need directions.";
	hintVector[714] = "There are two mercenary guards near the lodge that you'll need to sneak past or kill off. Since the keys that they have will come in handy, you'll probably prefer to kill them. (Note that you won't get a bounty for it.)";
	hintVector[715] = "Get one of the mercs' keys, then go up to the lodge's front door. Crouch down, then use the door to go inside.";
	hintVector[716] = "Turn right and sneak down the stairs to the basement, then look next to the bottom of the stairs for a strong box on a crate. It's the one Sibbi gave you the key to if you passed the persuade option when talking to him. If you didn't, you'll have to pick a master-level lock if you want to loot it.";
	hintVector[717] = "Go around to the main part of the basement to find Frost's identity papers on an end table. Take them to get the \"Steal Frost\" objective.";
	// (Optional)Steal the Lodge Stash.
	hintVector[718] = "The lodge's stash is in a strong box in the basement. See the \"Steal Frost's Lineage Papers\" objective hints for details on how to get to it, then loot it to finish this objective.";
	// Steal Frost.
	hintVector[719] = "Sneak back out the way you came in, then go over to the nearby stables and look in or near them for the horse named Frost.";
	hintVector[720] = "Mount Frost to get the next objective.";
	// Return to Louis Letrush.
	hintVector[721] = "Ride Frost over to where the quest arrow marks Letrush's current location. (Note that it's near Fallowstone Cave, so fast-travel there if you've already discovered it.)";
	hintVector[722] = "Letrush may be under attack by wolves or spiders when you arrive. If so, dismount and help him kill them.";
	hintVector[723] = "Talk to him after the combat is over. If he says he doesn't see Frost, then get back on Frost and ride him over to where he's right next to Letrush, then dismount and talk to Letrush again.";
	hintVector[724] = "You'll have three dialogue options to choose from. The first one gets you some gold, after which Letrush runs off without Frost for some reason. That doesn't mean Frost is yours, though -- he'll still count as stolen, and he won't follow you around when you fast-travel.";
	hintVector[725] = "If you want to make Frost your horse, you'll have to pass a persuade check when you talk to Letrush, or use the third dialogue option. It'll supposedly start a combat with Letrush, but due to a glitch, he may just run away without turning hostile.";
	hintVector[726] = "The advantage to passing the persuade option is that you'll get the horse and the gold (and some Speech skill practice), but the disadvantage is that a thug sent by Letrush will attack you in a random world encounter sometime later on. The advantage of using the third option is that you don't have to pass a persuade check, but the disadvantage is that you don't get the gold (unless you attack and kill Letrush, or pickpocket him).";
	// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

	// Repairing the Phial - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
	// Steps.
	stepVector[215] = "Speak to Quintus Navale.";
	stepVector[216] = "Retrieve the Unmelting Snow.";
	stepVector[217] = "Find some Mammoth Tusk Powder.";
	stepVector[218] = "Take a Forsworn Heart.";
	stepVector[219] = "Return to Quintus Navale.";

	// Hints.
	// Speak to Quintus Navale.
	hintVector[727] = "Return to the White Phial shop in Windhelm and talk to Quintus about receiving his letter to get the next three objectives.";
	// Retrieve the Unmelting Snow.
	hintVector[728] = "Return to Paarthurnax's Throat of the World location, then go over to the damaged Word Wall that he's perched on.";
	hintVector[729] = "Go up the slope that's directly south of that to find the quest-arrow-marked \"Unmelting Snowbank,\" then activate it to take some unmelting snow.";
	// Find some Mammoth Tusk Powder.
	hintVector[730] = "Note that this isn't the same as the powdered mammoth tusk ingredient item, so it won't do.";
	hintVector[731] = "A quest arrow marks the giant camp called Stonehill Bluff, so go there. See the Whiterun section of the World Map Exploration Guide if you need directions.";
	hintVector[732] = "Follow the quest arrow to a large stone bowl with the mammoth tusk powder in it. If you're careful, you'll be able to get the powder and leave without antagonizing any of the giants.";
	// Take a Forsworn Heart.
	hintVector[733] = "Any briar heart ingredient item will do, though they're fairly rare, and it may be awhile before you find one randomly in an alchemy store's inventory.";
	hintVector[734] = "The surest way to get a briar heart is to kill a forsworn briarheart and loot his body.";
	hintVector[735] = "You can find forsworn briarhearts in several different areas, including at Bard's Leap Summit (see the Falkreath section of the World Map Exploration Guide), in Broken Tower Redoubt (\"The Heart of Dibella\" side quest), and at Red Eagle Redoubt (\"Find Red Eagle's sword\" Markarth miscellaneous quest).";
	// Return to Quintus Navale.
	hintVector[736] = "Return to the White Phial and tell Quintus that you have the materials he requested.";
	hintVector[737] = "Follow him along until he talks to you, at which time he'll ask you how you want the White Phial attuned.";
	hintVector[738] = "You'll have six choices. Which one you choose will determine what type of potion will appear in the White Phial once every 24 hours.";
	hintVector[739] = "The options, in top-to-bottom order, are: Restore Health, Resist Magic, Fortify Stamina, Fortify Magicka, Fortify One-Handed, Fortify Sneak.";
	hintVector[740] = "You'll find the White Phial in the \"potions\" section of your inventory, and it'll start out full. You can use it to drink its contents, after which it'll be 24 hours before it refills with the same type of potion.";
	// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

	// Rise in the East - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
	// Steps.
	stepVector[220] = "Steal Suvaris Atheron's logbook.";
	stepVector[221] = "Give the logbook to Orthus.";
	stepVector[222] = "Talk to Stig Salt - Plank.";
	stepVector[223] = "Report back to Orthus.";
	stepVector[224] = "Depart for Japhet's Folly.";
	stepVector[225] = "Talk to Adelaisa.";
	stepVector[226] = "Kill Haldyn.";
	stepVector[227] = "Report back to Adelaisa.";
	stepVector[228] = "Speak to Adelaisa to return.";
	stepVector[229] = "Speak to Orthus.";

	// Hints.
	// Steal Suvaris Atheron's logbook.
	hintVector[741] = "Leave the East Empire Company building and go next door to the Clan Shatter-Shield Office building.";
	hintVector[742] = "If you can't pick the lock on the door, find Torbjorn Shatter-Shield and pickpocket his office key. (He'll usually be in the market area or the Clan Shatter-Shield house.)";
	hintVector[743] = "Go to the back left corner of the Shatter-Shield office to find Atheron's logbook next to a large business ledger. Take the logbook to get the next objective.";
	// Give the logbook to Orthus.
	hintVector[744] = "Return to the East Empire Company building and talk to Orthus about the logbook to get the next objective.";
	// Talk to Stig Salt - Plank.
	hintVector[745] = "Go to Dawnstar and look for Stig Salt-Plank in the inn.";
	hintVector[746] = "Instead of talking to him, you could pickpocket his \"Blood Horker Orders\" document to get the next objective.";
	hintVector[747] = "If you talk to him, you'll have to either bribe him or beat him in a brawl to get the next objective.";
	// Report back to Orthus.
	hintVector[748] = "Return to Windhelm's East Empire Company building and talk to Orthus.";
	hintVector[749] = "Then talk to Adelaisa Vendicci to get the next objective.";
	// Depart for Japhet's Folly.
	hintVector[750] = "Exit the East Empire Company building and look nearby for a quest-arrow-marked mercenary.";
	hintVector[751] = "When you're ready to go, talk to him and say \"let\'s go.\"";
	// Talk to Adelaisa.
	hintVector[752] = "Find Adelaisa on the deck nearby and talk to her to get the next objective.";
	// Kill Haldyn.
	hintVector[753] = "The ship you're on isn't going anywhere, so jump off of it and head south across the ice floes.";
	hintVector[754] = "Follow the quest arrow to find the entrance to a sea cave, then go inside.";
	hintVector[755] = "Move through the water and kill a couple of mudcrabs, then go up the snowy path to reach another mudcrab and a big wall hole that you can go through to find your first Blood Horker pirate.";
	hintVector[756] = "Go up the stairs and through the door to enter the Japhet's Folly Towers area, then go up the large staircase to find a couple more Blood Horkers (and a swinging gate trap).";
	hintVector[757] = "Past the stairs, go through a wooden door and down a long passage, then go through the SW doorway and down some stairs if you want some optional combat and loot. The NE doorway leads to some stairs going up, which is the way you need to go.";
	hintVector[758] = "Past the stairs, sneak through one doorway and over to another one so you can get a sneak attack on Haldyn. He'll mainly use shock damage spells against you, so hopefully you have some shock resistance and/or magic resistance.";
	hintVector[759] = "When you kill Haldyn, you'll get the next objective.";
	// Report back to Adelaisa.
	hintVector[760] = "Get the key from Haldyn's body, then go back down the stairs and along the passage until you find a door leading outside.";
	hintVector[761] = "Haldyn's key will open it for you, so go through it and start fighting your way east through the outer structures.";
	hintVector[762] = "Kill off the Blood Horkers who are near Adelaisa, then talk to her to get the next objective.";
	// Speak to Adelaisa to return.
	hintVector[763] = "When you're ready to leave Japhet's Folly, talk to Adelaisa and say \"let\'s go.\" (Note that you\'ll be able to fast - travel back here later on.)";
	// Speak to Orthus.
	hintVector[764] = "You'll be back at the Windhelm docks, so enter the East Empire Company building and talk to Orthus to finish the quest and get some gold. Note that Adelaisa will be a follower from now on.";
	// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

	// Rising at Dawn - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
	// Steps.
	stepVector[230] = "How can I become a vampire ?";
	stepVector[221] = "How do the stages of vampirism work ?";
	stepVector[232] = "Speak to Falion.";
	stepVector[233] = "Bring a filled Black Soul Gem to Morthal.";
	stepVector[234] = "Meet Falion at dawn.";
	stepVector[235] = "Speak to Falion.";
	stepVector[236] = "Wait for Falion to complete the ritual.";

	// Hints.
	// How can I become a vampire ?
	hintVector[765] = "To start with, let a vampire assault you until you contract the Sanguinare Vampiris disease. (Note that catching that disease won't be possible if you're a werewolf. See the Companions faction quests for more information on that.)";
	hintVector[766] = "See the \"Locations By Type\" section of the World Map Exploration Guide to find out where all the vampire lairs are, and take along plenty of healing potions so you won't be killed while letting vampires attack you.";
	hintVector[767] = "Once you catch the vampire disease, kill off any nearby vampires, then refrain from using anything that will cure diseases (including shrines) for three days.";
	hintVector[768] = "Soon after three days have passed, the screen will turn briefly red, and you'll get a notification that you've become a vampire.";
	// How do the stages of vampirism work ?
	hintVector[769] = "You start out as a stage 1 vampire, and you'll revert back to stage 1 every time you feed.";
	hintVector[770] = "To feed, sneak up to a sleeping person. Activate him when you can do so unseen, then choose the \"feed\" option instead of the \"pickpocket\" option.";
	hintVector[771] = "Every time a day passes without you feeding at all, you'll progress to the next stage of vampirism (unless you're already at stage 4).";
	hintVector[772] = "People in towns and settlements won't be automatically hostile to you unless you're at stage 4, so you can still talk to them, do merchant business with them, and so on if your current vampirism stage is 3 or less.";
	// Speak to Falion.
	hintVector[773] = "Go to Morthal and follow the quest arrow to Falion. (If he's locked inside his house, you'll need to wait until 8 am or so.)";
	hintVector[774] = "Talk to him about being an expert in vampirism to get the next objective.";
	// Bring a filled Black Soul Gem to Morthal.
	hintVector[775] = "Pre-filled black soul gems are only available as very rare random loot, so you'll probably need to find an empty one and then fill it.";
	hintVector[776] = "Falion will have an empty black soul gem in his merchant inventory, as will Enthir at the College of Winterhold.";
	hintVector[777] = "Note that there may be a special dialogue option with Falion that'll let you buy his black soul gem really cheap. If so, use it.";
	hintVector[778] = "If you'd rather find an empty black soul gem lying around, free for the taking, then you'll need to explore Broken Fang Cave, Hob's Fall Cave, or Fort Snowhawk.";
	hintVector[779] = "Once you have an empty black soul gem, soul-trap a hostile NPC like a bandit or necromancer in it. See the Enchanting Practice Tips for more about soul-trapping.";
	hintVector[780] = "Return to Morthal and tell Falion that you have a filled black soul gem to get the next objective.";
	// Meet Falion at dawn.
	hintVector[781] = "Follow the quest arrow to see where you're supposed to meet Falion, then wait if necessary for him to show up (which he'll usually do at around 4 am).";
	hintVector[782] = "When he arrives, you'll get the next objective.";
	// Speak to Falion.
	hintVector[783] = "Talk to Falion to get the next objective.";
	// Wait for Falion to complete the ritual.
	hintVector[784] = "Just stand and wait until the quest is completed, after which you won't be a vampire anymore. (Though you can become a vampire again the same way you did before.)";
	// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

	// Unfathomable Depths - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
	// Steps.
	stepVector[237] = "No Steps - Select this for hints.";

	// Hints.
	hintVector[785] = "Once you're level 14 or higher, go to Riften, then exit it using the door on its west side. Go along the board walkways until you find an argonian named From-Deepest-Fathoms, then talk to her to get this quest.";
	hintVector[786] = "See the Riften section of the World Map Exploration Guide if you need help getting to Avanchnzel.";
	hintVector[787] = "Once there, go up its curving stone ramps to reach a dark cave entrance.";
	hintVector[788] = "Once there, go up its curving stone ramps to reach a dark cave entrance.";
	// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

	// The White Phial - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
	// Steps.
	stepVector[238] = "Retrieve the White Phial.";
	stepVector[239] = "Bring the Phial to Nurelion.";
	stepVector[240] = "Speak to Quintus.";

	// Hints.
	// Retrieve the White Phial.
	hintVector[789] = "Travel to the Forsaken Cave and enter it, then fight your way past some animals to reach an iron door.";
	hintVector[790] = "Move down the passage past the door until you reach the start of a long and winding draugr crypt passage. Proceed through it slowly, watching for traps and taking on the draugr one or two at a time.";
	hintVector[791] = "At the end of the draugr passage is a door that leads to the Forsaken Crypt area.";
	hintVector[792] = "Kill the draugr in the first room, then follow the passage along (and kill another draugr) to reach that room's upper walkway.";
	hintVector[793] = "Cross the room on the walkway and kill the next draugr, then follow the walkway into a room with two more draugr and a large round trap in the middle of the floor.";
	hintVector[794] = "Go through the door past the trap and across an \"encaged\" bridge, then go down a draugr-infested passage to reach another door.";
	hintVector[795] = "Quicksave, then open it and time your way through the swinging axe trap. In the room beyond, Curalmil and several lesser draugr will rise up and attack you.";
	hintVector[796] = "You'll probably want to quickly retreat back past the swinging axe trap and try to take them on a few at a time. Note that Curalmil is the equivalent of a draugr overlord.";
	hintVector[797] = "Look past Curalmil's sarcophagus for some steps leading up to a treasure chest and a Word Wall, then go down the passage that's under the Word Wall to find an ancient bowl.";
	hintVector[798] = "Activate it to pour Nurelion's mixture into it, then go past the secret door that opens to find a cracked white phial on a pedestal. Take it to get the next objective.";
	// Bring the Phial to Nurelion.
	hintVector[799] = "Go back to Curalmil's room and through the door on its south side to find a door that leads back to the main cave area.";
	hintVector[800] = "Use the lever that's on the wall to open a secret door, then exit the cave and return to Windhelm.";
	hintVector[801] = "Talk to Nurelion in his shop to hand over the damaged phial and get 5 gold.";
	// Speak to Quintus.
	hintVector[802] = "Talk to Quintus Navale, who's also in the shop, to get a lot more gold and finish the quest.";
	// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

	// The Wolf Queen Awakened - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
	// Steps.
	stepVector[241] = "Speak to Styrr.";
	stepVector[242] = "Defeat Potema.";
	stepVector[243] = "Retrieve Potema's remains.";
	stepVector[244] = "Give Potema's remains to Styrr.";
	stepVector[245] = "Return to Falk Firebeard.";

	// Hints.
	// Speak to Styrr.
	hintVector[803] = "Exit the palace and go down the street until you come to the Hall of the Dead on your left.";
	hintVector[804] = "Enter it and talk to Styrr about Potema to get the Turn Undead spell, a key, and the next objective.";
	// Defeat Potema.
	hintVector[805] = "Exit the Hall of the Dead and go NW down the street to the castle courtyard, then turn right and enter the Temple of the Divines.";
	hintVector[806] = "Go down to the area with all the shrines, then enter the nearby left-side area and go down the steps.";
	hintVector[807] = "Go through the barred door past the steps, then go down to a hole in the wall that you can move through to enter the Potema's Catacombs area.";
	hintVector[808] = "You'll need to get through it and two more areas to get the next objective.";
	// Retrieve Potema's remains.
	hintVector[809] = "Go up to the open door in the back of Potema's chamber to find that she's now taken on a form that can attack you directly.";
	hintVector[810] = "Take cover to the left or right of the doorway while blasting Potema's remains with fireballs and other ranged spells.";
	hintVector[811] = "After you kill that manifestation, go up to the throne it was standing next to and take Potema's skull from it. That'll get you the next two objectives.";
	// Give Potema's remains to Styrr.
	hintVector[812] = "Go through the iron door that's in the back of the throne room, then go up the steps and along to find a door that's barred.";
	hintVector[813] = "Use the door bar to get it out of the way, then go through the door to find a room with two slumbering draugr.";
	hintVector[814] = "If you don't want to fight the draugr, you can just cross the room and use the exit door to get outside, then fast-travel back to Solitude.";
	hintVector[815] = "Return to the Hall of the Dead and talk to Styrr about Potema's remains to finish this objective.";
	// Return to Falk Firebeard.
	hintVector[816] = "Return to the Blue Palace and talk to Falk Firebeard about Potema to finish the quest and get some gold and the unique Shield of Solitude. (Note that the shield is leveled, so you may want to wait to claim it until you're level 40 or higher so you'll get the best version.)";
	// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
	// SIDE QUESTS ENDS HERE.

	// DUNGEON QUESTS START HERE.
	// Set the quest names and descriptions (if they have them).
	// Dungeon Quests (10 | 41-50).
	questVector[41].setQuestName("Ancestral Worship");
	questVector[41].setQuestDescription("To get this quest, go to Hillgrund's Tomb and talk to Golldir in the tomb's entry area.");
	questVector[42].setQuestName("Evil in Waiting");
	questVector[42].setQuestDescription("To get this quest, enter Valthume and talk to the spirit named Valdar.");
	questVector[43].setQuestName("Infiltration");
	questVector[43].setQuestDescription("To get this quest, talk to Stalleo in the small camp that's just east of Treva's Watch. Note that you may have to help him kill some of the bandits at the Watch before he'll talk to you.");
	questVector[44].setQuestName("The Lost Expedition");
	questVector[44].setQuestDescription("While doing the \"Kill Nimhe inside Nchuand - Zel\" Markarth miscellaneous quest (or afterwards), read the notes next to Alethius' body on the raised floor in Nimhe's room to get this quest.");
	questVector[45].setQuestName("The Pale Lady");
	questVector[45].setQuestDescription("To get this quest, go to Frostmere Crypt and talk to Eisa Blackthorn after she whacks a few bandits.");
	questVector[46].setQuestName("Repentance");
	questVector[46].setQuestDescription("To get this quest, enter Darklight Tower and talk to Illia in the first room.");
	questVector[47].setQuestName("A Return to Your Roots");
	questVector[47].setQuestDescription("After you work on the \"Discerning the Transmundane\" Daedric quest enough to gain access to Blackreach, pick any crimson nirnroot plant to get this quest.");
	questVector[48].setQuestName("A Scroll for Anska");
	questVector[48].setQuestDescription("To get this quest, enter the High Gate Ruins and talk to Anska.");
	questVector[49].setQuestName("Siege on the Dragon Cult");
	questVector[49].setQuestDescription("To get this quest, go to Forelhost and talk to Captain Valmir at the small outdoor camp.");
	questVector[50].setQuestName("Silenced Tongues");
	questVector[50].setQuestDescription("To get this quest, enter Volunruud and read the book called \"Heddic's Volunruud Notes,\" which is on the floor just past where you enter.");

	// Ancestral Worship - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
	// Steps
	stepVector[246] = "Defeat Vals Veran.";
	stepVector[247] = "(Optional) Protect Golldir.";
	stepVector[248] = "Speak with Golldir.";

	// Hints
	// Defeat Vals Veran.
	hintVector[817] = "Wait for Golldir to enter the tomb, then follow him in.";
	hintVector[818] = "Go through the first room, then fight a couple of draugr in the passage past it.";
	hintVector[819] = "Go through the iron door near the end of the passage to find two more draugr, then wait as Golldir finds his dead aunt and tries to open a large iron door.";
	hintVector[820] = "Go through the wooden door that's to the right of the iron one, ready to fight a couple of draugr that rise from their burial niches.";
	hintVector[821] = "Past another wooden door is a crypt passage with several draugr that will \"wake up\" and attack you all at once. Be sure to stay back and let Golldir take the brunt of the assault.";
	hintVector[822] = "Past those draugr, watch for a dart trap's pressure plate, followed by a wall-niche draugr and a large frostbite spider. Not far past the spider is another area where several draugr will get up and attack all at once.";
	hintVector[823] = "Past the secret door, kill the draugr that's sitting on a throne, then move on to find the large iron doors that lead to the chamber where Vals Veran is fooling around.";
	hintVector[824] = "Crouch down after you open the doors, then look for Veran on the other side of the room, up on a higher floor. Shoot him with a sneaky arrow or ranged spell, then stay there and fire at the draugr that he animates to help him.";
	hintVector[825] = "Stay in the doorway and sneak-shoot any enemy that you can see while Golldir charges in and fights them, being careful not to hit Golldir. At some point, some draugr may make it to your position, at which time you should retreat while fighting them with your best melee weapon.";
	hintVector[826] = "Note that Veran can teleport himself around every now and then, and he can raise dead draugr to fight for him some more. Also note that one of the last draugr to join the fight will be a powerful overlord.";
	hintVector[827] = "After Veran is killed, you'll get the \"Speak with Golldir\" objective.";
	// (Optional) Protect Golldir.
	hintVector[828] = "There isn't anything special to do for this objective, especially since Golldir is unkillable (unless you accidentally hit him when his health is low).";
	// Speak with Golldir.
	hintVector[829] = "Wait until Golldir gives you some gold and a chest key, at which time the quest will be over.";
	hintVector[830] = "Loot Vals Veran's body to get another key, then go up the steps to his upper platform to find the door that it opens.";
	hintVector[831] = "The key Golldir gave you will let you loot the chest past the door without picking its lock. Do so, then unbar the next door so you can use it as a shortcut back to the exit.";
	hintVector[832] = "Travel somewhere else and then return to find Golldir back where you first found him. (If he's not there, try again later.) You can now talk to him and get him to become a follower.";
	// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

	// Evil in Waiting - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
	// Steps
	stepVector[249] = "Collect the Vessels";
	stepVector[250] = "Perform the Ritual with Valdar.";
	stepVector[251] = "Defeat Hevnoraak.";
	// Collect the Vessels
	additionalStepsVector[8] = "How can I find the first opaque vessel ?";
	additionalStepsVector[9] = "How can I find the second opaque vessel ?";
	additionalStepsVector[10] = "How can I find the third opaque vessel ?";

	// Hints
	// Start of Collect the Vessels.
	// How can I find the first opaque vessel?
	hintVector[833] = "Wait for a secret door to open in the south wall, then go down a short passage to reach some doors that lead to the main Valthume area.";
	hintVector[834] = "Cross the large entry chamber and head down the unblocked passage. When you come to a pressure plate on the floor, try to time things so that stepping on the plate will cause the swinging log trap to kill one or both of the two draugr in the next room.";
	hintVector[835] = "Go down the passage that starts in that room's back left corner, then stay on the upper walkway of the huge room you come to. Hit the two draugr sitting on thrones on the opposite side of the room with ranged attacks (one at a time), then wait for them to come to you.";
	hintVector[836] = "After they're down, go down the log stairs, but be careful not to step on the large trap doors that are near the bottom of the stairs. If you do, you'll fall into a pit, and will have to kill some spiders and pick a difficult lock (or get the key from a draugr) to get back to the huge room.";
	hintVector[837] = "Go through the open iron doors on the huge room's south side, then open the iron doors on the left. Step on the nearest pressure plate, then quickly back up and wait for the flames to die down.";
	hintVector[838] = "Follow the pressure plate path to a blank wall with a hard-to-see handle on its left side. Using the handle will open up both the wall and the nearby closed gate.";
	hintVector[839] = "After quicksaving, go down the secret passage that's past the wall to reach a room with one of the three opaque vessels you're after on a pedestal.";
	hintVector[840] = "As you enter the room, a draugr deathlord will emerge and attack you. If you find it too hard to handle, you'll have to quickrestore and come back later.";
	// How can I find the second opaque vessel?
	hintVector[841] = "Go past the open gate in the pressure plate room and on to a large room with several draugr in it.";
	hintVector[842] = "At the east end of that room's lower floor is a door that leads to the Valthume Catacombs area.";
	hintVector[843] = "Watch for a couple of frostbite spiders as you cross the first big room you come to.";
	hintVector[844] = "Pull the chain next to the gate on the room's other side to open it, then start watching for draugr (and a swinging axe trap) past it.";
	hintVector[845] = "When you reach a crypt room with a draugr scourge and a closed gate, use the pull chain in the alcove to the right of the gate to open it.";
	hintVector[846] = "Past it is a room with another draugr scourge and the second opaque vessel on a stone slab.";
	// How can I find the third opaque vessel?
	hintVector[847] = "After taking the vessel, grab the soul gems from the three nearby pedestal traps before returning to the first draugr scourge's area and heading down its SW side passage. (Taking the soul gems will spare you a bit of pain as you go down that passage.)";
	hintVector[848] = "Be ready to fight a draugr wight and scourge on your way to a closed gate, which you can open with a pull chain that's to the right of it.";
	hintVector[849] = "Past it, move along the walkway to encounter a couple more draugr wights, then drop down to the lower floor and go to its west end to find an iron door.";
	hintVector[850] = "Open it, then hang back and lure the spiders to you before entering the room and figuring out how to open the puzzle door at its other end.";
	hintVector[851] = "Past the door is a room with the third and final opaque vessel on a pedestal -- but beware the powerful draugr in the room, which include a deathlord.";
	// End of Collect the Vessels.
	// Perform the Ritual with Valdar.
	hintVector[852] = "Before you leave the third vessel's room, note that taking it briefly lowered the spear gate that blocks access to a Word Wall and a treasure chest. If you don't get past the spears before they raise back up, jump onto the pedestal to lower them again, then quickly run past them.";
	hintVector[853] = "Look to the right of the Word Wall alcove for a gate you can open with a pull chain that's to the right of it.";
	hintVector[854] = "Move past the gate to find a door that leads back to the main Valthume area.";
	hintVector[855] = "Unbar and open the wooden door you come to, then head north until you return to the area's entry chamber, where Valdar's spirit is waiting for you.";
	hintVector[856] = "Talk to the spirit, then go activate the interactive sconce that's behind it.";
	hintVector[857] = "After that's done, sit on the throne that's behind the sconce to get the next objective.";
	// Defeat Hevnoraak.
	hintVector[858] = "Hevnoraak is a dragon priest, and is therefore dependent mainly on magic for his power. A high magic resistance would be a huge asset in this battle, as would a follower and/or summoned creature to act as distractions.";
	hintVector[859] = "Focus your attacks on Hevnoraak rather than his summoned allies until he goes down. After he does, take his unique mask and staff, then talk to Valdar to finish up.";
	// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

	// Infiltration - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
	// Steps
	stepVector[252] = "Use the backdoor to gain access to Treva's Watch.";
	stepVector[253] = "Use the lever to open the gate to Treva's Watch.";
	stepVector[254] = "Meet up with Stalleo in the courtyard.";
	// Hints
	// Use the backdoor to gain access to Treva's Watch.
	hintVector[860] = "Look near Stalleo's camp for the entrance to the \"backdoor\" tunnel.";
	hintVector[861] = "Enter it to get the next objective.";
	// Use the lever to open the gate to Treva's Watch.
	hintVector[862] = "Instead of proceeding through the fort's interior, you could go right back outside and use a shortcut. Skip to the next hint if you don't want to do that.";
	hintVector[863] = "Crouch down and sneak forward to where the passage turns left, then sneak-attack one of the bandits you can see on or near the stairs.";
	hintVector[864] = "Move back to a spot near the exit to keep the two bandit archers from shooting you while you take down the other two bandits.";
	hintVector[865] = "Charge the archers and use the Flames spell to ignite the oil on their floor, then finish them off if necessary.";
	hintVector[866] = "Watch for a bear trap as you move on past the bandits' room, then go up some stairs and straight forward to find another bandit banging away on a workbench.";
	hintVector[867] = "Just south of his room is a door leading to the Treva's Watch area. Sneak along its starting passage, watching for two bear traps and a bandit that you can sneak-shoot.";
	hintVector[868] = "Go up the stairs and kill another bandit, then quicksave. There are a bunch of bandits ahead, including the bandit chief, and you won't want to fight them all at once. Be careful to sneak around and take them on only one or two at a time whenever possible.";
	hintVector[869] = "After you clear out the large banquet hall area, go through the galley area and watch for a swinging gate trap just past it. Move on until you come to the base of a large curving staircase, then go up it if you want some optional combat and loot.";
	hintVector[870] = "Kill or sneak past the three bandits in the prison cell area, then watch for a dart trap's pressure plate on the way to the small side room with a door leading outside.";
	hintVector[871] = "Crouch down and go through the door, then quickly use the nearby lever to get the next objective.";
	// Meet up with Stalleo in the courtyard.
	hintVector[872] = "Either stand up and sprint south to meet up with Stalleo and his bodyguards, or stay crouched near the lever and shoot bandits from there.";
	hintVector[873] = "After all the outdoor bandits are killed, talk to Stalleo to finish the quest and get a Detect Life spell tome.";
	// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

	// The Lost Expedition - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
	// Steps
	stepVector[255] = "Recover Stromm's journal.";
	stepVector[256] = "Recover Erj's journal.";
	stepVector[257] = "Recover Krag's journal.";
	stepVector[258] = "Recover Staubs' journal.";
	stepVector[259] = "Reactivate Nchuand - Zel's automated defenses.";
	stepVector[260] = "Find someone who knows about the expedition.";

	// Hints
	// Recover Stromm's journal.
	hintVector[874] = "Burn through the webs that are next to Alethius' body so you can use the large golden doors past them to enter Nchuand-Zel.";
	hintVector[875] = "Go down a ramp and watch out for a pressure plate on the floor, then sneak over to the entrance to a huge multi-level chamber. Try to sneak-shoot the two falmer who are on the walkway before you move onto it.";
	hintVector[876] = "Past a third falmer are some doors that lead to the Nchuand-Zel Quarters area.";
	hintVector[877] = "In it, go along to where you find two falmer near some stairs, then go down those stairs and over to some other stairs.";
	hintVector[878] = "Kill the three falmer (and skeever) that are near those stairs, then go up them and carefully edge past the rune trap.";
	hintVector[879] = "Ahead and on the right is Stromm's diary on a large stone slab. Take it to get the next three objectives. (Note that you'll have to do them in the order listed due to the way the journals are placed.)";
	// Recover Erj's journal.
	hintVector[880] = "Go back the way you came to return to the main Nchuand-Zel area, then go down to the bottom level. You can do that by using the curving ramps or by jumping off the upper walkway so that you land in the water.";
	hintVector[881] = "Go over to the west end of the bottom level to find a door to the Nchuand-Zel Armory area.";
	hintVector[882] = "Go up the stairs ahead and kill a couple of falmer, then go up some more stairs to encounter a falmer and a skeever.";
	hintVector[883] = "Turn left (west) and go down the stairs, watching for a pressure plate at the top of the stairs, plus another one a bit farther on.";
	hintVector[884] = "Turn right after you enter a large chamber to find Erj's notes next to his body.";
	// Recover Krag's journal.
	hintVector[885] = "After taking Erj's notes, go back the way you came.";
	hintVector[886] = "When you get back to where you fought a falmer and a skeever, go up the stairs to the east.";
	hintVector[887] = "Go through the door that leads back to the main Nchuand-Zel area, then look just ahead to find Krag and his journal.";
	// Recover Staubs' journal.
	hintVector[888] = "After taking Krag's journal, go up the nearby curving ramp to reach a door to the Nchuand-Zel Control area.";
	hintVector[889] = "Move along until you find a couple of falmer, then look past them for a pressure plate that activates a spears-from-the-ceiling trap, which can be used against the next two falmer.";
	hintVector[890] = "Just past them, you'll find Staubin's diary next to his body.";
	// Reactivate Nchuand - Zel's automated defenses.
	hintVector[891] = "Go past Staubin's body and up some stairs to get several dwarven spiders to drop down and attack.";
	hintVector[892] = "It's best to sprint on past them to get them and the dwarven spheres interested in attacking a falmer.";
	hintVector[893] = "While they're fighting, you can sprint on by and get to the room with the large quest-arrow-marked lever.";
	hintVector[894] = "Use the lever to get the next objective.";
	// Find someone who knows about the expedition.
	hintVector[895] = "Go past the gate that lowers to find a walkway that leads to a dwarven-style treasure chest.";
	hintVector[896] = "Drop from the walkway to the lower floor to find yourself near the door that leads back to the main Nchuand-Zel area.";
	hintVector[897] = "Past the door, go up the dirt-covered ramp on your left, then drop down onto the upper walkway near its start.";
	hintVector[898] = "From there, you can turn left and go back to the door that'll return you to the area where you killed Nimhe.";
	hintVector[899] = "Go all the way back to Calcemo's area, then talk to him about finding an expedition journal to finish the quest and get some gold.";
	// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

	// The Pale Lady - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
	// Steps
	stepVector[261] = "Find the stolen sword.";
	stepVector[262] = "(Optional) Learn more about the theft in Frostmere Crypt.";
	stepVector[263] = "Follow Kyr and Ra'jirr into the tunnels.";
	stepVector[264] = "Banish the Pale Lady.";

	// Hints
	// Find the stolen sword.
	hintVector[900] = "Enter the crypt and kill the bandits in the first room, then use the pull chain that's to the left of the gate to open it.";
	hintVector[901] = "Go down the passage until you reach the start of an \"encaged\" walkway, then stop and wait to get the \"Follow Kyr and Ra'jirr into the tunnels\" objective.";
	hintVector[902] = "After you finish it, move ahead to get the \"Banish the Pale Lady\" objective.";
	hintVector[903] = "This objective will be completed when you get the Pale Blade from Ra'jirr's body.";
	// (Optional) Learn more about the theft in Frostmere Crypt.
	hintVector[904] = "Hints for this objective are included in the \"Follow Kyr and Ra'jirr into the tunnels\" objective's hints.";
	// Follow Kyr and Ra'jirr into the tunnels.
	hintVector[905] = "Go along the walkway to its end and kill a nearby bandit, then move on to some stairs that lead down into a room with two more bandits.";
	hintVector[906] = "NOTE: If you want to complete the optional objective, read the journals in the two side rooms before going down the stairs.";
	hintVector[907] = "Past the stairs, go through the door on the west side of the room, then fight your way through more bandits to reach a small alcove with a lever.";
	hintVector[908] = "Use the lever to lower a bridge, then go back to the room with the stairs. Cross the bridge and go down to the lower floor, killing two bandits as you go.";
	hintVector[909] = "Go down the tunnel to the west to find more bandits to kill, then watch out for a rockslide as you go down the stairs.";
	hintVector[910] = "Turn right past the stairs and kill one more bandit on the way to the door that leads to the Frostmere Depths area.";
	hintVector[911] = "Move a short way forward to find Kyr, then talk to him to finish this objective.";
	// Banish the Pale Lady.
	hintVector[912] = "The Pale Lady is a powerful wispmother with several wisps to support her.";
	hintVector[913] = "You could skip the battle by quickly looting Ra'jirr's body to get the Pale Blade, then activating the sword stand on the nearby altar. However, this deprives you of the ability to keep the sword. You can take it back, but that'll make the Pale Lady reappear, and you'll have to fight her or put the sword back on the altar.";
	hintVector[914] = "If you manage to kill her, you'll be able to keep the sword, which is unique and magical. Either way, the quest will be over.";
	hintVector[915] = "Go up the stairs that are NE of the altar to find a Word Wall and a door that leads back to the crypt area. Go along until you can unbar and open a door, then go through it to find yourself near the exit.";
	// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

	// Repentance - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
	// Steps
	stepVector[266] = "Help Illia reach the top of Darklight Tower.";
	stepVector[267] = "Defeat Illia's mother at the top of Darklight Tower.";

	// Hints
	// Help Illia reach the top of Darklight Tower.
	hintVector[916] = "Follow Illia up the stairs and help her kill off a couple of vermin. (Note that you should stick close to Illia, and put off looking for loot for now.)";
	hintVector[917] = "Past a door, help her kill a witch, then follow her to a combat with a witch and a large frostbite spider.";
	hintVector[918] = "Follow her through a door and on to where she stops at a closed spear gate. The lever to open it is nearby, but you may want to wait to use it until you've looked around for loot.";
	hintVector[919] = "After pulling the lever, follow Ilia through the door to the hagraven's chamber, where you'll fight the hagraven and a frostbite spider. Kill the spider first, then help Illia against the hagraven. (Be sure not to accidentally hit Illia. If you do so when her health is low, you may kill her.)";
	hintVector[920] = "After that's over, follow Illia into the Darklight Chambers area and into a room with two witches. Finish them off, then follow Illia over to a locked door.";
	hintVector[921] = "After opening the locked door, follow Illia to a witch's room, then to an area with another witch and two spiders.";
	hintVector[922] = "Follow her up the stairs past that until she talks to you and gives you the next objective.";
	// Defeat Illia's mother at the top of Darklight Tower.
	hintVector[923] = "Follow Illia outside, then wait until Silvia says to take a seat on the chair behind her.";
	hintVector[924] = "Find the chair that's between two wooden posts, then sit on it and wait until Illia attacks Silvia";
	hintVector[925] = "Get off of the chair and help take Silvia down, after which this quest will be over. However, there's a bit more to be done.";
	hintVector[926] = "After Illia talks to you, talk to her again about coming with you to make her a follower.";
	hintVector[927] = "Loot Silvia to get her unique Staff of Hag's Wrath, then trade items with Illia so you can get her Darklight Tower closet key.";
	hintVector[928] = "Reenter the Darklight Chambers area and check for any loot you missed before, then return to the Darklight Tower area and do the same. The key you got from Illia will open a key-required door that has some potions past it.";
	// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

	// A Return to Your Roots - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
	// Steps
	stepVector[268] = "Discover the significance of Crimson Nirnroot.";
	stepVector[269] = "Collect Crimson Nirnroot in Blackreach (0 / 30).";
	stepVector[270] = "Bring 30 Crimson Nirnroot to Avrusa Sarethi.";

	// Hints
	//
	// Discover the significance of Crimson Nirnroot.
	hintVector[929] = "Look near the exit to the Alftand Cathedral for a small structure called Sinderion's Field Laboratory.";
	hintVector[930] = "Enter the lab, then look for a crimson nirnroot to harvest next to an Alchemy skill book.";
	hintVector[931] = "Look around for other good loot, plus Sinderion's remains. (Apparently he came here sometime after you did a nirnroot-related quest for him back in Oblivion.)";
	hintVector[932] = "Loot the skeleton to get Sinderion's field journal, then read it in the \"books\" section of your inventory to get the next objective.";
	// Collect Crimson Nirnroot in Blackreach (0 / 30).
	hintVector[933] = "You'll probably already have 2 or more crimson nirnroots, so leave the field lab and start looking around Blackreach for more.";
	hintVector[934] = "Watch out for falmer and chaurus here and there, plus some other assorted creatures. Remember that crimson nirnroots are red, and make the same loud noise that regular nirnroots do when you get close to them.";
	hintVector[935] = "If you can't find 30 or more crimson nirnroots, leave and do other things, then return after several game weeks have passed so you can repick all of the ones you found before. (This is also useful if you want to use some of the ones you find early on in potion-making. See the Exceptional Ingredient List.)";
	hintVector[936] = "When you eventually get 30, you'll get the next objective.";
	// Bring 30 Crimson Nirnroot to Avrusa Sarethi.
	hintVector[937] = "Travel to the Sarethi Farm to find Avrusa. See the Riften section of the World Map Exploration Guide if you need directions.";
	hintVector[938] = "Talk to Avrusa about the crimson nirnroot to finish the quest and get the special Sinderion's Serendipity perk, which gives you a 25% chance of making a duplicate potion every time you create a potion at an alchemy lab. Now's a good time to start making superior Damage Health poisons with crimson nirnroots!";
	// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

	// A Scroll for Anska - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
	// Steps
	stepVector[271] = "Help Anska Retrieve Her Scroll.";
	stepVector[272] = "Return The Scroll To Anska.";
	// Hints
	// Help Anska Retrieve Her Scroll.
	hintVector[939] = "Move on to the next chamber and kill the draugr near its entrance, then go to the other side and up some log stairs to find two more draugr (including a wight).";
	hintVector[940] = "Check around the upper level for loot if you want, then go through the iron door. Just past the next iron door are several draugr, including two wights.";
	hintVector[941] = "Go through the next iron door and avoid a swinging gate trap while moving on to a large room with a blocked floor stairwell.";
	hintVector[942] = "Go down the stairwell to find a door that leads to the High Gate Ruins Catacombs area.";
	hintVector[943] = "Watch for pressure plates on the floor and draugr \"resting\" in burial niches as you make your way down a long crypt passage.";
	hintVector[944] = "Past an iron door is a small room followed by a long corridor with lots of pressure plates on the floor. Make your way past them carefully to reach a room with a closed gate.";
	hintVector[945] = "Past the gate is a door to the Vokun's Throne Room area.";
	hintVector[946] = "Approach some large iron doors to get them to open for you, after which Vokun will rise from his sarcophagus in the back of the next room.";
	hintVector[947] = "He's a dragon priest, which means he's a very powerful magic user. A high magic resistance would be very beneficial, as would a powerful summoned creature.";
	hintVector[948] = "After you help Anska kill Vokun, loot him to get his mask and staff, then go up one of the sets of stairs in the back of the room to reach another room with a Word Wall in it.";
	hintVector[949] = "Look on the big table that's near the Word Wall to find a sealed scroll. Take it to get the next objective.";
	// Return The Scroll To Anska.
	hintVector[950] = "Talk to Anska and give her the scroll to get a unique spell tome for the Flaming Familiar spell.";
	// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

	// Siege on the Dragon Cult - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
	// Steps
	stepVector[273] = "Obtain Rahgot's mask.";
	stepVector[274] = "(Optional) Find Skorm Snow - Strider's journal.";
	stepVector[275] = "Return to Valmir.";
	stepVector[276] = "Kill the imposter Valmir.";

	// Hints
	// Obtain Rahgot's mask.
	hintVector[951] = "Follow Valmir to the entry door, then wait for him to unlock it so you can go inside.";
	hintVector[952] = "In the room past the entry chamber's door, you'll need to fight a spectral dragon cultist and watch out for a swinging log trap.";
	hintVector[953] = "Two more cultists will attack at the path split. After you put them down, look for a way to get to the other side of the closed gate.";
	hintVector[954] = "Go down the corridor's side passage to find a door to the Forelhost Crypt area.";
	hintVector[955] = "Go down the crypt's starting hallway to find another ghost to fight, then look to the left for a swinging axe trap that leads to a room with a locked gate in it.";
	hintVector[956] = "You're going to have to go through that gate. If you can't pick its lock, you'll need to take a detour to find the key.";
	hintVector[957] = "Open the gate and go down the stairs past it to enter some water, then swim along the underwater passage to reach a cave room with several skeevers in it.";
	hintVector[958] = "Go down the next waterlogged passage to reach a room where you can go up some log stairs to find an oil spill near a door.";
	hintVector[959] = "Past the door is a crypt area with a large \"ceiling slam\" trap. As you enter, two draugr scourges and a wight will rise up and attack. Try to use the slam trap and the oil against them, and take refuge in the water when necessary.";
	hintVector[960] = "Go on past that area and through the door to the Forelhost Refectory area, then kill more draugr on your way to a large banquet hall.";
	hintVector[961] = "Past the gate is a room with a couple of draugr wights. Use the oil spill in the room's entrance against them, then go up the log stairs in the back to find the passage that leads to the next room.";
	hintVector[962] = "Past the spear gate is the door to a draugr scourge's room. Beyond it is a fire-spewin' trap, another draugr scourge, and a wide corridor that ends in a puzzle-lock door.";
	hintVector[963] = "Go up the stairs past the door to get Rahgot the dragon priest to break out of his sarcophagus. He'll soon be joined by several draugr, so you'll probably want to sprint back the way you came in hopes of leaving some of them behind.";
	hintVector[964] = "After you finish off the draugr, go back for Rahgot. After he's dead, loot him to get his unique mask and staff, plus the Forelhost balcony key.";
	// (Optional) Find Skorm Snow - Strider's journal.
	hintVector[965] = "The hints for this objective are included in the \"Obtain Rahgot's mask\" objective's hints.";
	// Return to Valmir.
	hintVector[966] = "Go through the doors in the back of Rahgot's chamber to get back outside, then go south along the upper walkway to reach a Word Wall.";
	hintVector[967] = "Drop down to the lower ground from there, then walk up to Valmir and wait for the next objective.";
	// Kill the imposter Valmir.
	hintVector[968] = "The Stormcloak soldier that Valmir was talking to will help you attack him at first, but may suddenly turn hostile to you at some point, even if you don't hit him.";
	hintVector[969] = "The quest is over when you kill Valmir, and the two dragon priest relics are yours to keep. See the \"Masks of the Dragon Priests\" undocumented quest for more about dragon priest masks.";
	// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

	// Silenced Tongues - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
	// Steps
	stepVector[277] = "Locate the Ceremonial Weapons.";
	additionalStepsVector[11] = "How can I get the Ceremonial Sword ?";
	additionalStepsVector[12] = "How can I get the Ceremonial Axe ?";
	stepVector[278] = "Open the Elder's Cairn.";
	stepVector[279] = "Defeat Kvenel.";
	// Hints

	// Start of Locate the Ceremonial Weapons.
	// How can I get the Ceremonial Sword?
	hintVector[970] = "Go down the NE tunnel in the large multi-path room to reach a room with two draugr on the opposite walkway, plus maybe a draugr wight on a higher-up bridge. If you wait where you are for them to come after you, they may be injured or even killed by the swinging gate trap that's down on the lower floor.";
	hintVector[971] = "After they're disposed of, go down to the lower floor and past the swinging gate trap carefully, then turn right past an open gate to reach the higher-up bridge. (Watch out for the wight and any other draugr who didn't come after you earlier.)";
	hintVector[972] = "Cross the bridge and go through some iron doors to find the open sarcophagus that has the Ceremonial Sword in it. Watch out for two draugr to attack when you approach the sarcophagus, plus another one on the way back.";
	// How can I get the Ceremonial Axe ?
	hintVector[973] = "Go down the NW tunnel in the large multi-path room and through some iron doors to reach a crypt area with some \"sleeping\" draugr.";
	hintVector[974] = "Get the drop on them by attacking them before they get up, then whack more draugr as you make your way to some more iron doors.";
	hintVector[975] = "Past them is a throne room with a draugr scourge on the throne, plus another draugr. There are several traps on the floor, so stay back and try to lure the draugr to you (or finish them off with ranged attacks).";
	hintVector[976] = "Move past the floor traps carefully to reach the throne, then optionally read the One-Handed skill book that's on it before grabbing the Ceremonial Axe from the wall above it.";
	// End of Locate the Ceremonial Weapons.
	// Open the Elder's Cairn.
	hintVector[977] = "Return to the large multi-path room, then go down the north passage to find a large door called Elder Cairn's Door.";
	hintVector[978] = "Activate the door to place the two ceremonial weapons and get the next objective.";
	// Defeat Kvenel.
	hintVector[979] = "Use the door to enter the Volunruud Elder's Cairn area, then go down the passage slowly while looking up.";
	hintVector[980] = "When you come to where you can see a small stone bridge above you, maneuver around so that you can hit the two draugr up near the bridge with arrows or spells. Try to finish them both off before moving on.";
	hintVector[981] = "As you proceed, watch for a draugr to rise from a sarcophagus. Stay back and try to finish it off without getting the attention of the powerful spirit of Kvenel the Tongue in the large chamber ahead.";
	hintVector[982] = "Either sneak into Kvenel's chamber and over to the right, where some steps go past a Word Wall, or sprint over that way. You'll want to reach the small stone bridge and cross it, then finish off any draugr you didn't get from below.";
	hintVector[983] = "Kvenel is reluctant to cross that bridge, and you may be able to use that against him. Sneak over to where you can sneak-shoot him with arrows, then quickly retreat back across the bridge when he comes after you. If he does cross the bridge, drop down to the lower passage and sprint back toward his chamber in an effort to lose him.";
	hintVector[984] = "If you can defeat Kvenel, you'll finish the quest, and will be able to get either or both of his unique weapons (Eduj and Okin) from his remains. Which one(s) you get is random, and seems to be set early on (maybe when you first enter Volunruud). Note that re-searching his remains several times might help.";
	// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
	// DUNGEON QUESTS ENDS HERE.

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
	const int MAINNOQUESTS = 18, SIDENOQUESTS = 21, DUNGEONNOQUEST = 9;
	int currentQuest = 0; // Integer to hold the starting quest number.

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
		currentQuest = 19;
		cout << "Side Quests\n\nChoose a quest..\n" << endl;
		for (int i = 0; i <= SIDENOQUESTS; i++)
		{
			cout << i + 1 << ". " << questVector[currentQuest].getQuestName() << endl;
			currentQuest++;
		}
		cout << "- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -" << endl; // Space for output.
		break;
	case MENUCHOICE3: // Dungeon Quests.
		currentQuest = 41;
		cout << "Dungeon Quests\n\nChoose a quest..\n" << endl;
		for (int i = 0; i <= DUNGEONNOQUEST; i++)
		{
			cout << i + 1 << ". " << questVector[currentQuest].getQuestName() << endl;
			currentQuest++;
		}
		cout << "- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -" << endl; // Space for output.
		break;
	}
}

void stepChoices(int userQuestChoice, int STEPS, int startSteps, vector<Quest> questVector, vector<string> stepVector)
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
		cout << i + 1 << ". " << stepVector[startSteps] << endl;
		startSteps++;
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
		cout << "- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -\n" << endl; // Space for output.
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

int additionalStepPrint(int userStepChoice, int STEPS, int startSteps, vector<string> additionalStepsVector)
{
	int userAdditionalChoice; // This is the user's input for the addition step.
	int printedSteps = 1; // This is the counter for the current step.
	cout << "- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -" << endl; // Space for output.
	cout << additionalStepsVector[userStepChoice - 1] << endl << endl;
	cout << "Choose a step..\n";
	for (int i = startSteps; i < STEPS + startSteps; i++)
	{
		cout << printedSteps << ". " << additionalStepsVector[i] << endl;
		printedSteps++;
	}
	cout << "- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -" << endl; // Space for output.
	cin >> userAdditionalChoice;
	return userAdditionalChoice;
}