#include "tddFuncs.h"
#include "WordCount.h"
#include <iostream>
#include <string>
#include <vector>
#include <utility> 
#include <cctype>

int main(){
    WordCount wordcount;
    //Initializing a hash table

    wordcount.incrWordCount("apple");
    wordcount.incrWordCount("apple");
    wordcount.incrWordCount("apple");
    wordcount.incrWordCount("apple");

    wordcount.incrWordCount("banana");

    wordcount.incrWordCount("cherry");

    wordcount.incrWordCount("grape");

    wordcount.incrWordCount("pear");
    wordcount.incrWordCount("pear");
    wordcount.incrWordCount("pear");
    wordcount.incrWordCount("pear");

    wordcount.incrWordCount("orange");
    wordcount.incrWordCount("orange");

    wordcount.incrWordCount("cranberry");

    wordcount.incrWordCount("pomegranate");
    wordcount.incrWordCount("pomegranate");
    wordcount.incrWordCount("pomegranate");
    wordcount.incrWordCount("pomegranate");
    wordcount.incrWordCount("pomegranate");

    wordcount.incrWordCount("blueberry");
    wordcount.incrWordCount("blueberry");

    wordcount.incrWordCount("papaya");
    wordcount.incrWordCount("papaya");
    wordcount.incrWordCount("papaya");
    wordcount.incrWordCount("papaya");
    wordcount.incrWordCount("papaya");

    std::cout << "Testing dumpWordsSortedByWord()" << '\n';

    wordcount.dumpWordsSortedByWord(std::cout);

    std::cout << "Testing dumpWordsSortedByOccurence()" << '\n';
    wordcount.dumpWordsSortedByOccurence(std::cout);
}