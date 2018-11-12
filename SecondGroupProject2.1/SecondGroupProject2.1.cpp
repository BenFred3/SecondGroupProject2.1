// SecondGroupProject2.1.cpp : Defines the entry point for the console application.
//


#include "Game.h"
#include "Quest.h"
#include <iostream>
#include <vector>
#include <string>


#pragma comment(lib, "user32")
using namespace std;

int main();

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
MENUCHOICE8 = 8;
const int DEFAULTVALUE = 1000;
int main()
{
	system("mode 650"); // Make the console fullscreen.

						// Default value for all the vectors.
						// Counter for steps one through 4.
	const int STEPS1THR4 = 4;

	// Create a gameArray, a categoryNameVector, a questVector, a stepVector, and a hintVecor. Then resize all of them to the default value.
	Game gameArray[1];
	vector<string> categoryNameVector = gameArray[0].getCategoryNameVector();
	categoryNameVector.resize(DEFAULTVALUE);

	vector<Quest> questVector = gameArray[0].getQuestVector();
	questVector.resize(DEFAULTVALUE);

	vector<string> stepVector(DEFAULTVALUE);
	questVector[0].setStepVector(stepVector);

	vector<string> additionalStepsVector(DEFAULTVALUE);
	questVector[0].setAdditionalStepsVector(additionalStepsVector);

	vector<string> hintVector(DEFAULTVALUE);
	questVector[0].setHintVector(hintVector);

	createGame(gameArray, categoryNameVector, questVector, stepVector, additionalStepsVector, hintVector); // This creates the game Skyrim from the vectors created.

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
						case MENUCHOICE2: // Second Main Quest

							break;
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

void createGame(Game gameArray[1], vector<string> categoryNameVector, vector<Quest> questVector, vector<string> stepVector, vector<string> additionalStepsVector,
	vector<string> hintVector)
{
	// Set the game name.
	gameArray[0].setGameName("The Elder Scrolls V: Skyrim");

	// Set the category names.
	categoryNameVector[0] = "Main Quests";
	categoryNameVector[1] = "Side Quests";

	// Set the quest names and descriptions.
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

	// SET THE STEPS *******************************************
	// Unbound
	stepVector[0] = "Make your way to the Keep";
	stepVector[1] = "Enter the Keep with Hadvar or Ralof";
	stepVector[2] = "Objectives for Hadvar's Path";
	stepVector[3] = "Objectives for Ralof's Path";
	//Before The Storm steps
	stepVector[4] = "Talk to Alvor in Riverwood";
	stepVector[5] = "Talk to Gerdur in Riverwood";
	stepVector[6] = "Talk to the Jarl of Whiterun";
	//Bleak Falls Barrow 7,8,9

	//Dragon Rising(6) - 10, 11, 12, 13, 14, 15

	//The Way of the Voice(8) - 16, 17, 18, 19, 20, 21, 22, 23

	//The Horn of Jurgen Windcaller(6) - 24, 25, 26, 27, 28, 29

	//A Blade in the Dark(4) - 30, 31, 32, 33

	//Diplomatic immunity(10) - 34, 35, 36, 37, 38, 39, 40, 41, 42, 43

	//A Cornered Rat(4) - 44, 45, 46, 47

	//Alduin's Wall(4) - 48, 49, 50, 51
	stepVector[48] = "Escort Esbern to Riverwood";
	stepVector[49] = "Talk to Esbern";
	stepVector[50] = "Gain entrance to Sky Haven Temple";
	stepVector[51] = "Learn the secret of Alduin's Wall";
	
	//The Throat of the World(7) - 52, 53, 54, 55, 56, 57, 58
	stepVector[52] = "Talk to Arngeir";
	stepVector[53] = "Learn the \"Clear Skies\" Shout";
	stepVector[54] = "Use the \"Clear Skies\" Shout to open the path";
	stepVector[55] = "Talk to Paarthurnax";
	stepVector[56] = "Learn the Word of Power from Paarthurnax";
	stepVector[57] = "Use your \"Fire Breath\" Shout on Paarthurnax";
	stepVector[58] = "Talk to Paarthurnax";

	//Elder Knowledge(3) - 59, 60, 61
	stepVector[59] = "Learn the location of the Elder Scroll";
	stepVector[60] = "(Optional) Talk to Esbern or (Optional) Talk to Arngeir";
	stepVector[61] = "Recover the Elder Scroll";

	//Alduin's Bane(3) - 62, 63, 64
	stepVector[62] = "Read the Elder Scroll at the Time-Wound";
	stepVector[63] = "Learn the \"Dragonrend\" Shout from the Nord heroes";
	stepVector[64] = "Defeat Alduin";

	//The Fallen(8)
	stepVector[65] = "Talk to Paarthurnax or Talk to Arngeir or Talk to Esbern.";
	stepVector[66] = "Talk to the Jarl of Whiterun.";
	stepVector[67] = "Get Greybeards' help in negotiating a truce.";
	stepVector[68] = "Learn Shout to call Odahviing.";
	stepVector[69] = "Prepare trap for Odahviing.";
	stepVector[70] = "Call Odahviing to Dragonsreach.";
	stepVector[71] = "Defeat and trap Odahviing.";
	stepVector[72] = "Interrogate Odahviing.";

	//Paarthurnax(2) 
	stepVector[73] = "Kill Paarthurnax.";
	stepVector[74] = "Talk to Delphine.";

	//Season Unending(6)
	stepVector[75] = "Talk to Arngeir.";
	stepVector[76] = "Talk to Ulfric Stormcloak. ";
	stepVector[77] = "Talk to General Tullius.";
	stepVector[78] = "Talk to Arngeir.";
	stepVector[79] = "Take your seat.";
	stepVector[80] = "Negotiate a truce.";

	//The World-Eater's Eyrie(4)
	stepVector[81] = "Set Odahviing free.";
	stepVector[82] = "Talk to Odahviing.";
	stepVector[83] = "Reach Alduin's portal to Sovngarde.";
	stepVector[84] = "Enter Sovngarde.";

	//Sovngarde(3)
	stepVector[85] = "Find out how to defeat Alduin.";
	stepVector[86] = "Gain admittance to the Hall of Valor.";
	stepVector[87] = "Talk to the heroes of Sovngarde.";

	//Dragonslayer(2)
	stepVector[89] = "Help the heroes of Sovngarde dispel Alduin's mist.";  
	stepVector[90] = "Defeat Alduin.";



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

	// Set the hints.
	// Unbound Step 1 hints:
	hintVector[0] = "When you gain control, there'll be a guy standing nearby and talking to you. You can also identify him by the quest marker that's hanging over his head (provided you don't use the journal to set this quest as inactive).";
	hintVector[1] = "Follow him through a nearby door, then up the stairs until the dragon makes a big hole in the wall.";
	hintVector[2] = "You'll be instructed to jump through the wall hole, but it's best to just walk forward and drop down onto the edge of the inn's roof, then move to the right a bit so you can jump over the log railing without touching the nearby fire.";
	hintVector[3] = "Go to the other end of the inn and drop down through one of the big floor holes, then go through the doorway ahead and turn left to find the guy you're supposed to follow next.";
	hintVector[4] = "Stay close to him until you meet up with the guy you were following at first. After they split up, you'll get the next objective.";
	// Unbound Step 2 hints:
	hintVector[5] = "This is the game's first bogus choice, meaning that your decision will have far-ranging consequences, all of which will lead to roughly equivalent outcomes.";
	hintVector[6] = "Hadvar is an Imperial soldier and Ralof is a Stormcloak operative. Which one you follow now will be seen as a choice as to which side you're taking in Skyrim's big civil war. It'll also affect who you travel with for the rest of this quest and the first part of the next one. However, this choice isn't an irrevocable commitment to either side, and you can choose to switch sides later on when it becomes more of an issue.";
	hintVector[7] = "If you'd rather go with Hadvar now, go a short way west to where he's standing, then move into the doorway next to him. If you want to follow Ralof, go a short way north and enter the doorway he's standing next to.";
	// Objectives for Hadvar's Path step 1 hints:
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
	// Objectives for Hadvar's Path steps 2 hints:
	hintVector[18] = "All you have to do for this objective is loot the chest that's near the SW corner of the room, but it's best to put that off for a bit.";
	hintVector[19] = "First, look around for other chests and loose items, including two swords on wall racks.";
	hintVector[20] = "Wait until Hadvar walks over to a closed gate, after which you can get in some serious skill practice.";
	hintVector[21] = "When you're tired of that, loot the chest near the SW corner of the room and equip its armor items.";
	// Objectives for Hadvar's Path step 3 hints:
	hintVector[22] = "As usual with this type of objective, it'll be completed when you search the one item that it's interested in, but you should first look all around for other items to take.";
	hintVector[23] = "You'll find the potion barrel near where the two enemy soldiers were. You'll also find lots of other items to take, not all of which are worth lugging around.";
	hintVector[24] = "After picking up everything, look through your inventory (especially the \"misc\" section) to see what all you can do without.";
	// Objectives for Hadvar's Path steps 4 hints:
	hintVector[25] = "First, loot the small table for stuff, then check the large open cage for an iron shield.";
	hintVector[26] = "Next, go over to the three small locked cages and use your new lockpicks to try to get them open.";
	hintVector[27] = "The lockpicking minigame works just like the one in Fallout 3 and Fallout: New Vegas, except it's a bit more primitive and clumsy. Even those who (like me) played those two Fallout games endlessly will need a bit of practice to get used to it, so be sure to quicksave before every lockpick attempt and quickrestore whenever you break a lockpick or two without opening the lock.";
	hintVector[28] = "You only need to lockpick the middle cage open to finish the objective, but you should do all three for extra Lockpicking skill practice.";
	hintVector[29] = "And don't forget to get all the loot that's inside the central cage, including the dead mage's apparel and spell tome.";
	// Objectives for Ralof's Path step 1 hints:
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
	// Objectives for Ralof's Path step 2 hints:
	hintVector[41] = "Loot the body of the dead guy named Gunjar to get an iron war axe and a couple of armor pieces.";
	// Objectives for Ralof's Path step 3 hints:
	hintVector[42] = "As usual with this type of objective, it'll be completed when you search the one item that it's interested in, but you should first look all around for other items to take.";
	hintVector[43] = "You'll find the potion barrel near where the two enemy soldiers were. You'll also find lots of other items to take, not all of which are worth lugging around.";
	hintVector[44] = "After picking up everything, look through your inventory (especially the \"misc\" section) to see what all you can do without.";
	// Objectives for Ralof's Path step 4 hints:
	hintVector[45] = "First, loot the small table for stuff, then check the large open cage for an iron shield.";
	hintVector[46] = "Next, go over to the three small locked cages and use your new lockpicks to try to get them open.";
	hintVector[47] = "The lockpicking minigame works just like the one in Fallout 3 and Fallout: New Vegas, except it's a bit more primitive and clumsy. Even those who (like me) played those two Fallout games endlessly will need a bit of practice to get used to it, so be sure to quicksave before every lockpick attempt and quickrestore whenever you break a lockpick or two without opening the lock.";
	hintVector[48] = "You only need to lockpick the middle cage open to finish the objective, but you should do all three for extra Lockpicking skill practice.";
	hintVector[49] = "And don't forget to get all the loot that's inside the central cage, including the dead mage's apparel and spell tome.";

	//Hints for Alduin's Wall - Step 1: Escort Esbern to Riverwood. 
	hintVector[50] = "Wait as Esbern runs around and looks for stuff to take with him, then talk to him and ask if he knows the way out.";
	hintVector[50] = "Follow him back to the Ratway Vaults area, then help him kill the Thalmor soldiers and mages that attack.";
	hintVector[50] = "Follow him back to the Ragged Flagon, then over to a raised wooden bridge.";
	hintVector[50] = "Use the big lever on the wall to the right of the bridge to lower it, then cross it and kill the assassin named Shavari (if she appears there). Note that there may also be a couple of Thalmor nearby.";
	hintVector[50] = "Follow Esbern until he goes outside, then fast-travel to Riverwood and enter the inn.";
	hintVector[50] = "Wait while he talks to Delphine, then follow them into her secret room and wait until you get the next objective.";

	//Hints for Alduin's Wall - Step 2: Talk to Esbern.
	hintVector[50] = "Talk to Esbern about how to find Alduin's Wall to get the next objective.";

	//Hints for Alduin's Wall - Step 3: Gain Entrance to Sky Haven Temple
	hintVector[50] = "Wait until Delphine talks to you, then decide whether you'd like to travel to Karthspire with her and Esbern or alone.";
	hintVector[50] = "It's always better to have more companions along (unless you're still practicing your combat skills), so say you'll travel with them, then leave the inn.";
	hintVector[50] = "Before you continue with this quest, you may want to visit four dragon mounds that now have live dragons at them. Your two unkillable traveling companions will be a big help when fighting the dragons, as long as they don't run off on you.";
	hintVector[50] = "Assuming you decide to save those dragons for later, fast-travel to the Whiterun Stables, then use the carriage to travel to Markarth. (Or fast-travel straight there if you've already discovered it.)";
	hintVector[50] = "You can then talk to Delphine and say you'll meet her at Karthspire in order to get her to lead the way. Follow her and Esbern along, ready to help them kill two dragons along the way. (NOTE: The second dragon attacks near Karthspire, and may get distracted by the forsworn guys who are at the Karthspire Camp.)";
	hintVector[50] = "After the dragon and all the forsworn are dead, go up the path from the camp that leads to a dark cave entrance. Move into it to get Delphine and Esbern to catch up with you.";
	hintVector[50] = "Follow them into a forsworn camp, and then on to a large chamber with some stairs that lead to three small stone pillars.";
	hintVector[50] = "Cross the lowered bridge, then move on to a room with a large array of pressure plates on the floor.";
	hintVector[50] = "Follow Esbern until you discover the Sky Haven temple, then look for a way to open its large carved-face door.";


	//Hints for Alduin's Wall - Step 4: Learn the secrets of Anduin's Wall
	hintVector[50] = "Past the carved-face door, go up the steps and through a door to enter the main temple area, then run up some more steps.";
	hintVector[50] = "Look around the area for loot, including a full suit of Blades armor and a unique sword named Dragonbane, while waiting for Esbern to find Alduin's Wall.";
	hintVector[50] = "After he move up to its left end, move close to him and wait as he uses the wall to determine that Alduin was once defeated by some sort of shout.";
	hintVector[50] = "After that, Delphine will talk to you about it, and you'll get the next quest.";
	hintVector[50] = "TIP: Ask Esbern for advice on fighting dragons, then say you need the dragon-slaying blessing. That'll get you a magic effect that gives you a 10% higher critical hit chance against dragons for five game days. When it wears off, you can come back and talk to Esbern to get it again.";
	hintVector[50] = "TIP: You can also now talk to Delphine to start on the Blades Faction Quests.";

	//Hints for The Throat of the World - Step 1: Talk to Arngeir
	hintVector[50] = "Use the stairs that are to the right of Alduin's Wall to get up to the top of the wall, then go up the stairs to the north to find an exit.";
	hintVector[50] = "Fast-travel to High Hrothgar, then enter the monastery and follow the quest arrow to Arngeir.";
	hintVector[50] = "Talk to him and say that you need to learn the shout that defeated Alduin. After he rants at you a bit, wait until he talks to you again.";
	hintVector[50] = "After that conversation is over, follow him outside and over to a log fire, after which you'll get the next objective.";

	//Hints for The Throat of the World - Step 2: Learn the "Clear Skies" Shout. 
	hintVector[50] = "Wait until Arngeir shouts three words onto the ground, then step on them in the order that he did them to absorb them all.";

	//Hints for The Throat of the World - Step 3: Use the "Clear Skies" Shout to open the path. 
	hintVector[50] = "After Arngeir shares his knowledge of the Clear Skies shout with you, go up the nearby stairs to reach a spot that you can't push your way past.";
	hintVector[50] = "Bring up the Spells menu and select the Clear Skies shout, then hit the Shout key to get the next objective.";

	//Hints for The Throat of the World - Step 4: Talk to Paarthurnax.
	hintVector[50] = "As you run down the winding path, you'll have two hazards to watch out for.";
	hintVector[50] = "One is ice wraiths, which look like flying skeletal eels. Quickly hit them with fire spells and your best weapon to keep them from killing you with their cold damage attacks.";
	hintVector[50] = "The other hazard is the weather, which can sap your health and stamina. To prevent it from doing that, keep using the Clear Skies shout every time it recharges.";
	hintVector[50] = "You'll eventually make it to the Throat of the World location, where a dragon will land next to you.";
	hintVector[50] = "It's Paarthurnax, so don't attack it. Instead, talk to it and then wait to get the next objective.";

	//Hints for The Throat of the World - Step 5: Learn the Word of Power from Paarthurnax.
	hintVector[50] = "Go over to the wrecked Word Wall that Paarthurnax shouted a word onto to learn it, then wait to get the next objective.";

	//Hints for The Throat of the World - Step 6: Use your "Fire Breath" Shout on Paarthurnax. 
	hintVector[50] = "Go to the Spells menu and equip your new Fire Breath shout, then aim at Paarthurnax and hit the Shout key.";

	//Hints for The Throat of the World - Step 7: Talk to Paarthurnax.
	hintVector[50] = "Go over to Paarthurnax to get him to talk to you, then say that you want to learn the Dragonrend shout.";
	hintVector[50] = "After a great deal of discourse, you'll get the next quest.";
	hintVector[50] = "TIP: Ask Paarthurnax if others come to him to train, then choose a word to meditate on. You can choose "fus" (the first word of Unrelenting Force), "feim" (the first word of Become Ethereal), or "yol" (the first word of Fire Breath). Meditating on "fus" makes you stagger 25% less and your opponents stagger 25% more, meditating on "feim" makes your health regenerate 25% faster while you're ethereal, and meditating on "yol" makes your Fire Breath shout do 25% more damage. You can return to Paarthurnax and change which meditation you have at any time.";

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
	const int MAINNOQUESTS = 18,
		SIDENOQUESTS = 0;

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

