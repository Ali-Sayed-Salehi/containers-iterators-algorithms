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
