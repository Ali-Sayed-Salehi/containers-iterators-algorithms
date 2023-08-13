//
// Created by Ali Sayed Salehi on 2023-08-12.
//

#ifndef CONTAINERS_ITERATORS_ALGORITHMS_CIA_H
#define CONTAINERS_ITERATORS_ALGORITHMS_CIA_H


#include <map>
#include <string>
#include <vector>

// Type aliases
using WordsVector = std::vector<std::string>;
using WordsMap = std::map<std::string, size_t>;

/**
 * takes a text file consisting of exactly one English word per line
 * as parameter and returns a WordsVector containing all the words in that file.
 * @param inFileName input text file name
 * @return a WordsVector containing all the words in that file
 */
WordsVector read_words_into_vector(const std::string& inFileName);

/**
 * The function is to count the number of occurrences of each individual word
 * occurring in wordsVector, and to return the final counts in a map that maps
 * the words (the keys) to their corresponding number of occurrences (the values).
 * @param words_vector
 * @return
 */
WordsMap map_and_count_words_using_lambda(const WordsVector& words_vector);

/**
 * a class that overloads the () operator to add words and their frequency to a map
 */
class WordCountFunctor {
private:
    WordsMap words_map{};
public:
    void operator()(const std::string& word);
    WordsMap get_map() {
        return words_map;
    }
};


/**
 * This function behaves the same as that of Task 2, except that it
 * passes a function object of a functor named WordCountFunctor as
 * the third argument in the call to the std::for_each algorithm.
 * @param words_vector
 * @return
 */
WordsMap map_and_count_words_using_functor(const WordsVector& words_vector);

/**
 * remove the duplicated words in the supplied words_vector
 * @param words_vector
 * @return
 */
WordsVector remove_duplicates(const WordsVector& words_vector);

/**
 * determines whether phrase string is a palindrome.
 * The reading process ignores spaces, punctuation, and capitalization.
 * @param phrase
 * @return
 */
bool is_palindrome(const std::string& phrase);

/**
 * takes a char ch as its single parameter and
 * determines whether ch is not an alphabetic character
 * @param ch
 * @return
 */
bool is_not_alphabetic(char ch);
size_t count_using_lambda(const std::vector<std::string>& vec, int n);
size_t count_using_Free_Func(const std::vector<std::string>& vec, int n);
size_t count_using_Functor(const std::vector<std::string>& vec, int n);
void multisetUsingMyComparator(const std::vector<std::string>& vec);
void multisetUsingDefaultComparator(const std::vector<std::string>& vec);


#endif //CONTAINERS_ITERATORS_ALGORITHMS_CIA_H
