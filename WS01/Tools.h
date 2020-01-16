//==============================================
// Name:           Woong O
// Student Number: 124820192
// Email:          wo@myseneca.ca
// Section:        NGG
// Date:           14 JAN
//==============================================
// Worshop : 1
// 
//==============================================

#pragma once
#ifndef SDDS_TOOLS_H
#define SDDS_TOOLS_H

const int MAX_WORD_LEN = 21;
const int MAX_NO_OF_WORDS = 500;

namespace sdds
{
	struct Word 
	{
		char letters[MAX_WORD_LEN];
		int count;
	};

	void toLowerCaseAndAlphabeticCopy(char des[], const char source[]);
	void addWord(Word words[], int* index, const char newWord[]);
	int searchWords(const Word words[], int num, const char word[]);
	void print(const Word* w, bool gotoNextLine);
	void sort(Word words[], int cnt);
	void swap(Word* p1, Word* p2);
	void report(const Word words[], int noOfWords, int longestWord);
	void totalWordsStat(int totNoWrds, int totalOverAll, int longestWord);
	void endList();
	void title();

}

#endif // !SDDS_TOOLS_H
