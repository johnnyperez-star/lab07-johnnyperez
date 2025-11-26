// WordCount.cpp

#include "WordCount.h"

using namespace std;

// Default constructor
WordCount::WordCount() {}

// Simple hash function. Do not modify.
size_t WordCount::hash(std::string word) const {
	size_t accumulator = 0;
	for (size_t i = 0; i < word.size(); i++) {
		accumulator += word.at(i);
	}
	return accumulator % CAPACITY;
}

int WordCount::getTotalWords() const {
	int wordOccurence = 0;
	for (const auto& vec : table){
		for (const auto& pair : vec){
			wordOccurence += pair.second;
		}
	}
	return wordOccurence;
}

int WordCount::getNumUniqueWords() const {
	int uniqueWords = 0;
	for (size_t i = 0; i < CAPACITY; i++){
		uniqueWords += table[i].size();
	}
	return uniqueWords;
}

int WordCount::getWordCount(std::string word) const {
	std::string validWord = makeValidWord(word);
	if (validWord == ""){
		return 0;
	}

	size_t index = hash(validWord);

	for (const auto& pair : table[index]){
		if (pair.first == validWord){
			return pair.second;
		}
	}

	return 0;
}
	
int WordCount::incrWordCount(std::string word) {
	std::string validWord = makeValidWord(word);
	if (validWord == ""){
		return 0;
	}

	size_t index = hash(validWord);

	for (auto& pair : table[index]){
		if(pair.first == validWord){
			pair.second += 1;
			return pair.second;			
		}
	}

	table[index].push_back({validWord, 1});
	return 1;
}

int WordCount::decrWordCount(std::string word) {
	std::string validWord = makeValidWord(word);
	if(validWord == ""){
		return -1;
	}

	size_t index = hash(validWord);
	auto& vec = table[index];

	for(auto& pair : table[index]){
		if(pair.first == validWord){
			if(pair.second > 1){
				pair.second += -1;
				return pair.second;
			}
			if(pair.second == 1){
				for(auto it = vec.begin(); it != vec.end(); ){
					if(it->first == validWord){
						it = vec.erase(it);
						return 0;
					}
					else{
						++it;
					}
				}
			}
		}
	}
	return -1;
}

bool WordCount::isWordChar(char c) {
	if (((c <= 'z') && (c >= 'a')) || ((c <= 'Z') && (c >= 'A'))) { return true;}
	else { return false; }
}

std::string WordCount::makeValidWord(std::string word) {
	int firstCharIndx = -1;
	int lastCharIndx = -1;
	std::string subString = "";
	std::string validWord = "";

	for (size_t i = 0; i < word.length(); i++){
		if (isWordChar(word[i]) == true){
			firstCharIndx = i;
			break;
		}
	}

	if (firstCharIndx != -1){
		for(int i = word.length() - 1; i >= 0; i--){
			if(isWordChar(word[i]) == true){
				lastCharIndx = i;
				break;
			}
		}
	}

	if (firstCharIndx == -1){
		return "";
	}

	subString = word.substr(firstCharIndx, lastCharIndx - firstCharIndx + 1);

	for (char ch : subString){
		if ((isWordChar(ch) == true) || (ch == '\'') || (ch == '-')){
			validWord += std::tolower(ch);
		}
	}
	return validWord;
}

void WordCount::dumpWordsSortedByWord(std::ostream &out) const {
	std::vector<std::pair<std::string, int>> tableCopy;

	for(size_t i = 0; i < CAPACITY; i++){
		for(const auto& pair : table[i]){
			tableCopy.push_back(pair);
		}
	}

	std::sort(tableCopy.begin(), tableCopy.end());
	std::reverse(tableCopy.begin(), tableCopy.end());

	for(const auto& pair : tableCopy){
		out << pair.first << "," << pair.second << '\n';
	}
}


void WordCount::dumpWordsSortedByOccurence(std::ostream &out) const {
	// STUB
	return "";
}

void WordCount::addAllWords(std::string text) {
	// STUB
	return;
}
