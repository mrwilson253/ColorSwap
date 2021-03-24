/*
* Jordan Wilson
* jwilson160@cnm.edu
* WilsonP3 - The color swap as a class
* Driver.cpp
*/

#include "ColorSwap.h"
#include "Functions.h"

int main()
{
	ColorSwap color;
	string colorFile;
	string phraseFile;
	string sentenceFile;
	string outputFile;

	Header();

	AskForInputFilenames(colorFile, sentenceFile, phraseFile);
	if (color.ReadFiles(colorFile, sentenceFile, phraseFile))
		cout << "\nFiles Read\n\n";
	outputFile = AskForOutputFilename();
	if (color.WriteFile(outputFile))
		cout << "\nFile successfully written!\n";
	cout << color.GetResults();	

	GoodBye();

	return 0;
}