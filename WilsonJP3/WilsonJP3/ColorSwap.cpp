/*
* Jordan Wilson
* jwilson160@cnm.edu
* WilsonP3 - The color swap as a class
* ColorSwap.cpp
*/

#include "ColorSwap.h"

void ColorSwap::ReadColors()
{
	ifstream input;
	input.open(colorFile.c_str());

	//check if the file is open
	if (input)
		bRead[0] = true;

	string temp;
	while (!input.eof())
	{
		getline(input, temp);
		vColors.push_back(temp);
	}

	input.close();
}

void ColorSwap::ReadSentences()
{
	ifstream input;
	input.open(sentenceFile.c_str());

	//check if the file is open
	if (input)
		bRead[1] = true;

	int i{ 0 };
	string temp;
	while (!input.eof()&&i<MAX_ARRAY)
	{
		getline(input, temp);
		sentences[i] = temp;
		totalSentences++;
		i++;
	}

	input.close();
}

void ColorSwap::ReadPhrases()
{
	ifstream input;
	input.open(swapPhrasesFile.c_str());

	//check if the file is open
	if (input)
		bRead[2] = true;

	string temp;
	while (!input.eof())
	{
		getline(input, temp);
		vPhrases.push_back(temp);
	}

	input.close();
}

void ColorSwap::WriteOriginals()
{
	//Write into the file our name and program # and all of the orignial data
	stringstream ss;
	stringstream ss1;
	stringstream ss2;
	stringstream ss3;

	//Name and program number
	ss << "Jordan Wilson, Program 3, the Color Swap as a class\n\n";
	//use a for loop to display each type of data
	//display the list of colors
	for (int i = 0; i < vColors.size(); ++i)
		ss1 << vColors[i] << "\n";
	//display the list of phrases
	for (int i = 0; i < vPhrases.size(); ++i)
		ss2 << vPhrases[i] << "\n";
	//display the list of sentences
	for (int i = 0; i < totalSentences; ++i) {
		ss3 << sentences[i] << "\n";
		//origResults += sentences[i];
	}

	//when you are done putting data into the stringstream, convert it into a string
	origResults = ss.str() + "Colors: \n" + ss1.str() + "\nPhrases: \n" + ss2.str() + "\nSentences: \n" + ss3.str();

	////then stream result into output
	//outputFile << result;
}

void ColorSwap::WriteResults()
{
	//simialr to write orignals
	//write data that is required by spec
	//use a loop to display the modified sentences
	stringstream ss;
	int colorMod{ 0 };
	for (int i = 0; i < MAX_ARRAY; ++i)
		colorMod += numSwapped[i];

	for (int i = 0; i < totalSentences; ++i) {
		ss << sentences[i] << "\n";
		//results += sentences[i] + "\n";
	}

	finalResults = "\nSentences analyzed: " + to_string(totalSentences) +
		"\nSentences modified: " + to_string(sentencesSwapped) +
		"\nColors Modified: " + to_string(colorMod) +
		"\nModified Sentences: \n" + ss.str();

	//output << result;

	//output.close();

	//return true;
}

void ColorSwap::SwapColors()
{
	//int totalSentencesSwapped{ 0 };
	//Write a for loop to go through all of the sentences
	for (int i = 0; i < totalSentences; ++i)
	{
		int numColorsSwappedInSent{ 0 };

		//need a loop to go through all of the colors to see if they are in the sentence
		for (int j = 0; j < vColors.size(); ++j)
		{
			string color = vColors.at(j);
			//before we search for colors, toLower the first letter of the sentence
			sentences[i].at(0) = tolower(sentences[i].at(0));
			//use the string.find function to look for color
			string temp = sentences[i];
			int x = temp.find(color);
			//check the return - if it is -1, the color was not found. else, it exists starting at that index.
			//if the index 0 or greater, replace the color with the phrase
			if (x >= 0) {
				//to replace, use the replace function of the string class, giving it the index where it starts
				//and the length of the color using color.length()
				sentences[i].replace(x, color.length(), vPhrases[j]);
				//increment numswapped
				numSwapped[i]++;
			}
		}
		if (numSwapped[i] > 0) {
			sentencesSwapped++;
		}
	}
	for (int i = 0; i < totalSentences; ++i)
		//then make the first character of the sentence toupper
		sentences[i].at(0) = toupper(sentences[i].at(0));
}

ColorSwap::ColorSwap()
{
}

bool ColorSwap::ReadFiles(string colorFile, string sentenceFile, string swapPhrasesFile)
{
	ReadColors();
	ReadSentences();
	ReadPhrases();

	if (bRead[0] && bRead[1] && bRead[2]) {
		WriteOriginals();
		SwapColors();
		WriteResults();
		return true;
	}
		
	return false;
}

bool ColorSwap::WriteFile(string outputFile)
{
	ofstream output;
	if (output) {
		output.open(outputFile);
		output << origResults << finalResults;
		output.close();
		return true;
	}
	
	return false;
}
