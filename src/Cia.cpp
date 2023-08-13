//
// Created by Ali Sayed Salehi on 2023-08-12.
//

#include <fstream>
#include <iostream>
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
