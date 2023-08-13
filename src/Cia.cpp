//
// Created by Ali Sayed Salehi on 2023-08-12.
//

#include <fstream>
#include <iostream>
#include <iterator>
#include <set>
#include "Cia.h"

using std::cout;
using std::endl;


WordsVector read_words_into_vector(const std::string& inFileName) {
    std::ifstream ifs(inFileName); // Create an input file stream
    if (!ifs.is_open()) { // Check that the file is open
        cout << "Could not open file " + inFileName << endl;
        throw std::runtime_error("Could not open file " + inFileName);
    }
    WordsVector wordsVector;
    std::istream_iterator<std::string> istream_iterator_begin(ifs);
    std::istream_iterator<std::string> istream_iterator_end;
    std::back_insert_iterator<WordsVector> vector_back_insert_iterator(wordsVector);

    std::copy(istream_iterator_begin,
              istream_iterator_end,
              vector_back_insert_iterator);

    return wordsVector;
}

WordsMap map_and_count_words_using_lambda(const WordsVector& words_vector) {
    WordsMap words_map;
    auto insert_into_map = [&words_map] (const std::string& word) {
        auto insertion_result = words_map.insert({word, 1});
        if (!insertion_result.second) insertion_result.first->second += 1;
    };
    std::for_each(words_vector.begin(), words_vector.end(), insert_into_map);
    return words_map;
}



WordsMap map_and_count_words_using_functor(const WordsVector& words_vector) {
    WordCountFunctor word_count_functor{}; // must internally maintain occurrences of words
    word_count_functor = std::for_each(words_vector.begin(),
                                            words_vector.end(),
                                            word_count_functor);
    return word_count_functor.get_map();
}

void WordCountFunctor::operator()(const std::string& word) {
    auto insertion_result = words_map.insert({word, 1});
    if (!insertion_result.second) insertion_result.first->second += 1;
}

WordsMap WordCountFunctor::get_map() {
    return words_map;
}

WordsVector remove_duplicates(const WordsVector& words_vector) {

    // make a copy of the supplied words_vector
    WordsVector words_vec{ words_vector };

    // 1- use std::sort to sort words_vec alphabetically
    //    so that we can locate the duplicate words in it.
    std::sort(words_vec.begin(),
              words_vec.end(),
              [](const std::string& a, const std::string& b) {
                        return a < b; // Compare strings alphabetically
                    }
    );

    // 2- use std::unique to rearrange the words in the sorted words_vec
    //    so that each word appears once in the front portion of words_vec.
    //    store the returned iterator, which points to the element
    //    immediately after all the unique elements in the front of words_vec.
    auto new_end = std::unique(words_vec.begin(), words_vec.end());

    // 3- use std::vector’s erase member function to erase the range of non-uniqu
    //    words in words_vec, starting at the iterator stored in step 2 above
    //    to the end of words_vec.
    words_vec.erase(new_end,words_vec.end());
    return words_vec;
}

bool is_not_alphabetic(char ch) {
    return !((ch >= 'A' && ch <= 'Z') || (ch >= 'a' && ch <= 'z'));
}

bool is_palindrome(const std::string& phrase) {
    std::string temp{};
    std::remove_copy_if(phrase.begin(), phrase.end(),
                        std::back_inserter(temp), is_not_alphabetic);

    cout << temp << endl;
    std::transform(temp.begin(), temp.end(), temp.begin(),
                   [] (char ch) {return tolower(ch);});

    std::string::iterator middleIterator = temp.begin() + temp.length() / 2;

    bool result = std::equal(temp.begin(), middleIterator,
                             temp.rbegin());
    return result;
}

size_t count_using_lambda(const std::vector<std::string>& vec, int n) {
    auto count = std::count_if(vec.begin(), vec.end(),
                  [n] (const std::string& word) {
                            if (word.length() == n) {
                                return true;
                            } else return false;
                        }
    );
    return count;
}

bool char_count_free_func(const std::string& word, int n) {
    if (word.length() == n) {
        return true;
    } else return false;
}

size_t count_using_Free_Func(const std::vector<std::string>& vec, int n) {
    auto unaryFreeFunc = std::bind(char_count_free_func, std::placeholders::_1, n);
    auto count = std::count_if(vec.begin(), vec.end(), unaryFreeFunc);
    return count;
}

size_t count_using_functor(const std::vector<std::string>& vec, int n) {
    CharCountEquals char_count_is_equal{n};
    auto count = std::count_if(vec.begin(), vec.end(), char_count_is_equal);
    return count;
}

bool CharCountEquals::operator()(const std::string &word) const {
    if (word.length() == n) {
        return true;
    } else return false;
}

CharCountEquals::CharCountEquals(int n) : n(n) {}

void multisetUsingDefaultComparator(const std::vector<std::string>& vec) {
    std::multiset<std::string> stringSet{}; // an empty string set

    // to print a sorted version of the supplied vector vec,
    // we first copy vec to our stringSet and then print the stringSet.
    // note: since std::multiset does not provide push_front or push_back members,
    // we can’t use a front or back inserter when we copy vec to our empty stringSet,
    // meaning that we must use a general inserter:
    std::copy(vec.begin(), vec.end(),                      // source start and finish.
              std::inserter(stringSet, stringSet.begin())); // destination start using

    // a general inserter.
    // create an ostream_iterator attached to cout, using a space " " as a separator
    std::ostream_iterator<std::string> out(cout, " ");

    // output the set elements to the cout
    std::copy(stringSet.begin(), stringSet.end(), out);
}

bool string_comparator (const std::string& string1, const std::string& string2) {
    if (string1.length() != string2.length()) {
        return string1.length() < string2.length();
    } else {
        return string1 < string2;
    }
}


void multisetUsingMyComparator(const std::vector<std::string>& vec) {
    std::multiset<std::string, bool(*)(const std::string&, const std::string&)>
            stringSet{string_comparator};
    std::copy(vec.begin(), vec.end(),
              std::inserter(stringSet, stringSet.begin()));
    std::ostream_iterator<std::string> out(cout, " ");
    std::copy(stringSet.begin(), stringSet.end(), out);
}

