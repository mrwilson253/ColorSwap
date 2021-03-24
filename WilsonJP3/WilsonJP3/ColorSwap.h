/*
* Jordan Wilson
* jwilson160@cnm.edu
* WilsonP3 - The color swap as a class
* ColorSwap.h
*/

#ifndef COLOR_SWAP_H
#define COLOR_SWAP_H

#include <string>
#include <vector>
#include <fstream>
#include <sstream>

using namespace std;
const int MAX_ARRAY = 10;

class ColorSwap
{
private:
	int numSwapped[MAX_ARRAY] = {};	//number of colors swapped in a sentence
	vector<string> vColors;
	string sentences[MAX_ARRAY];
	vector<string> vPhrases;
	int totalSentences{ 0 };	//number of sentences read
	int sentencesSwapped{ 0 };  //number of sentences that had their colors swapped
	string origResults, finalResults;

	//filenames
	string colorFile{ "Colors.txt" };
	string sentenceFile{ "Sentences.txt" };
	string swapPhrasesFile{ "SwapPhrases.txt" };
	string outputFile{ "Out.txt" };

	//ofstream output;
	bool bRead[3] = {false, false, false};
	//Read the three text files and assign their data to the class variables
	void ReadColors();
	void ReadSentences();
	void ReadPhrases();

	//Creates a string with the original information.
	void WriteOriginals();

	//Creates a string with the final information.
	void WriteResults();

	//Checks the sentences for the colors, and performs the swaps
	void SwapColors();
public:
	//Default constructor, initialize variables
	ColorSwap();

	//Calls the three Read methods, checks that they were successful, assigns the     //correct filename into the class variables and if all went well, calls // WriteOriginals(), SwapColors() and WriteResults().
	bool ReadFiles(string colorFile, string sentenceFile, string swapPhrasesFile);

	//Creates the output filestream, opens the output file, checks that it's ok. If no, returns false. If yes, writes the origResults and finalResults into the file. Closes the file. Returns true.
	bool WriteFile(string outputFile);
	string GetResults() { return origResults + finalResults; }
};

#endif