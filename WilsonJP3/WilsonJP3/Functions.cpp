/*
* Jordan Wilson
* jwilson160@cnm.edu
* WilsonP3 - The color swap as a class
* Functions.cpp
*/

#include "Functions.h"

void Header()
{
	//cout the header
	cout << "Jordan Wilson\njwilson160@cnm.edu\nWilsonP3 - Color Swap as a class\n";
}

void AskForInputFilenames(string& colorFile, string& sentenceFile, string& phraseFile)
{
	//ask the user for the filename for the colors using cout
	//give them the chance to use the default filename
	cout << "\nPlease enter the filename for the colors. For the default \"Colors.txt\", enter \"0\".";
	cin >> colorFile;
	if (colorFile == "0") {
		colorFile = "Colors.txt";
	}

	//then do the same for sentences
	cout << "\nPlease enter the filename for the sentences. For the default \"Sentences.txt\", enter \"0\".";
	cin >> sentenceFile;
	if (sentenceFile == "0") {
		sentenceFile = "Sentences.txt";
	}

	cout << "\nPlease enter the filename for the phrases. For the default \"SwapPhrases.txt\", enter \"0\".";
	cin >> phraseFile;
	if (phraseFile == "0") {
		phraseFile = "SwapPhrases.txt";
	}
}

string AskForOutputFilename()
{
	//Looks like the other ask for filename - can also allow a default
	cout << "Please enter the filename for output. Enter 0 for the default \"Out.txt\"";
	//Create a string to read into and then return.
	string answer;
	cin >> answer;
	if (answer == "0")
		answer = "Out.txt";
	//

	return answer;
}

void GoodBye()
{
	cout << "\nGood-bye! Thank you for using the color swap!\n\n";
}
