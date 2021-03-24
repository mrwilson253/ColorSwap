/*
* Jordan Wilson
* jwilson160@cnm.edu
* WilsonP3 - The color swap as a class
* Functions.h
*/

#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <string>
#include <sstream>
#include <vector>
#include <iostream>
#include <fstream>

using namespace std;

void Header();

void AskForInputFilenames(string& colorFile, string& sentenceFile, string& phraseFile);

string AskForOutputFilename();

void GoodBye();


#endif // !FUNCTIONS_H

