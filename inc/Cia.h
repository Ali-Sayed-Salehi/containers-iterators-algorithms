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
    WordsMap get_map();
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

/**
 * count and return the number of elements in vec that are of length n.
 * @param vec
 * @param n
 * @return
 */
size_t count_using_lambda(const std::vector<std::string>& vec, int n);

/**
 * returns true if the passed string has n characters, and false otherwise.
 * @param word
 * @param n
 * @return
 */
bool char_count_free_func(const std::string& word, int n);

/**
 * count and return the number of elements in vec that are of length n.
 * @param vec
 * @param n
 * @return
 */
size_t count_using_Free_Func(const std::vector<std::string>& vec, int n);

/**
 * a class that overloads the () operator to add words and their frequency to a return true
 * if the number of characters in a word is equal to n
 */
class CharCountEquals {
private:
    int n{};
public:
    explicit CharCountEquals(int n);
    bool operator()(const std::string& word) const;
};


/**
 * count and return the number of elements in vec that are of length n.
 * @param vec
 * @param n
 * @return
 */
size_t count_using_functor(const std::vector<std::string>& vec, int n);

/**
 * a comparator function that compare strings in this way:
 * strings are first sorted based on their length,
 * with the strings in each group sorted lexicographically.
 * @param string1
 * @param string2
 * @return
 */
bool string_comparator (const std::string& string1, const std::string& string2);

/**
 * prints the sorted version of a supplied vector of strings using a custom comparator
 * @param vec
 */
void multisetUsingMyComparator(const std::vector<std::string>& vec);

/**
 * prints the sorted version of a supplied vector of strings using default comparator
 * @param vec
 */
void multisetUsingDefaultComparator(const std::vector<std::string>& vec);


#endif //CONTAINERS_ITERATORS_ALGORITHMS_CIA_H
