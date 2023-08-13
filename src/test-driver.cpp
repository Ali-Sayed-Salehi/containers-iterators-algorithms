//
// Created by Ali Sayed Salehi on 2023-08-12.
//
#include <cassert>
#include <iostream>
using std::cout;
using std::endl;
using std::cin;

#include "Cia.h"

// function prototypes
void validate_words_vector(const WordsVector& word_vector);
void print_words_vector(const WordsVector& word_vector);
WordsVector task_1_test_driver(const std::string& infilename);
void validate_word_map(const WordsMap& wmap);
void print_word_map(const WordsMap& wmap);
void task_2_test_driver(const WordsVector& words_vector);
void task_3_test_driver(const WordsVector& words_vector);
void validate_unique_words_vector(const WordsVector& word_vector);
void task_4_test_driver(const WordsVector& words_vector);
void task_5_test_driver();
void task_6_test_driver();
void task_7_test_driver();
void task_8_test_driver(int n);
void task_9_test_driver(unsigned long x);

// used in task 1
void validate_words_vector(const WordsVector& word_vector)
{
    assert(word_vector.size() == 574);
    assert(word_vector.back() == "yoke");
    assert(word_vector[0] == "wink");
    assert(word_vector[200] == "fool");
    assert(word_vector[400] == "work");
    assert(word_vector.at(100) == "gainful");
    assert(word_vector.at(300) == "dirty");
    assert(word_vector.at(500) == "coast");
}
void print_words_vector(const WordsVector& word_vector)
{
    for (const auto& word : word_vector)
    {
        cout << word << endl;
    }
    cout << "Number of words: " << word_vector.size() << endl;

}

WordsVector task_1_test_driver(const std::string& infilename)
{
    cout << "\nTask 1: Copy the Words in a Text File Into a Vector" << endl;
    WordsVector words_vector = read_words_into_vector(infilename);
    validate_words_vector(words_vector);
    cout << "All words extracted OK\n";
    //cout << "All words in the input file\n";
    //print_words_vector(words_vector);
    return words_vector;
}

// used in Tasks 2 and 3
void validate_word_map(const WordsMap& wmap)
{
    const auto& [word1, count1] { *wmap.begin() };
    cout << word1 << ": " << count1 << endl;
    assert(word1 == "air" && count1 == 6);

    const auto& [word2, count2] { *std::prev(wmap.end()) };
    cout << word2 << ": " << count2 << endl;
    assert(word2 == "yoke" && count2 == 8);

    // PreC++17 way of accessing a map's element, say the first element
    std::pair<std::string, size_t> key_value_pair{ *wmap.begin() };
    std::string key = key_value_pair.first;
    size_t value = key_value_pair.second;
    assert(key == "air" && value == 6);
}

void print_word_map(const WordsMap& wmap)
{

    for (const auto& [word, count] : wmap)
    {
        cout << word << ": " << count << endl;
    }
}

void task_2_test_driver(const WordsVector& words_vector)
{
    cout << "\nTask 2: Count Frequency of the Words in a Vector Using a Lambda" << endl;
    WordsMap word_map_using_lambda = map_and_count_words_using_lambda(words_vector);
    validate_word_map(word_map_using_lambda);
    cout << "word_map_using_lambda is OK\n";
    cout << "All words in the map generated using lambda\n";
    print_word_map(word_map_using_lambda);
}

// Task 3
void task_3_test_driver(const WordsVector& words_vector)
{
    cout << "\nTask 3: Count Frequency of the Words in a Vector Using a Functor" << endl;
    WordsMap word_map_using_functor = map_and_count_words_using_functor(words_vector);
    validate_word_map(word_map_using_functor);
    cout << "word_map_using_functor is OK\n";
    //cout << "All words in the map generated using functor\n";
    //print_word_map(word_map_using_functor);
}

// Task 4
void validate_unique_words_vector(const WordsVector& word_vector)
{
    assert(word_vector.size() == 100);
    assert(word_vector.back() == "yoke");
    assert(word_vector[0] == "air");
    cout << "Unique words OK\n";
}

void task_4_test_driver(const WordsVector& words_vector)
{
    cout << "\nTask 4: Removing duplicated Words in a Vector" << endl;

    WordsVector unique_words_vector = remove_duplicates(words_vector);
    cout << "All unique words\n";
    print_words_vector(unique_words_vector);
    validate_unique_words_vector(unique_words_vector);
}

// Task 5
void task_5_test_driver()
{
    cout << "\nTask 5: Palindrome" << endl;
    std::string str_i_saw = std::string("was it a car or A Cat I saW?");
    bool result_i_saw = is_palindrome(str_i_saw);
    assert(result_i_saw == true);
    cout << "the phrase \"" + str_i_saw + "\" is a palindrome\n";

    std::string str_u_saw = std::string("was it A Car or a cat U saW?");
    bool result_u_saw = is_palindrome(str_u_saw);
    assert(result_u_saw == false);
    cout << "the phrase \"" + str_u_saw + "\" is not a palindrome\n";
}

// Task 6
void task_6_test_driver()
{
    cout << "\nTask 6: Counting Strings of Equal lengths" << endl;
    std::vector<std::string> vecstr
            { "count_if", "Returns", "the", "number", "of", "elements", "in", "the",
              "range", "[first", "last)", "for", "which", "pred", "is", "true."
            };
    assert(count_using_lambda(vecstr, 5) == 4);
    assert(count_using_Free_Func(vecstr, 5) == 4);
    assert(count_using_functor(vecstr, 5) == 4);

    assert(count_using_lambda(vecstr, 3) == 3);
    assert(count_using_Free_Func(vecstr, 3) == 3);
    assert(count_using_functor(vecstr, 3) == 3);

    cout << "Task 6 OK" << endl;
}

// Task 7
void task_7_test_driver()
{
    cout << "\nTask 7: Multiset using Custom Sorting Criteria" << endl;
    std::vector<std::string> vec =
            { "C", "BB", "A", "CC", "A", "B", "BB", "A", "D", "CC", "DDD", "AAA" };
    multisetUsingDefaultComparator(vec);
    cout << '\n';
    multisetUsingMyComparator(vec);
    cout << endl;
}

// Task 8
void task_8_test_driver(int n)
{
    cout << "\nTask 8: Fibonacci Sequence" << endl;
    std::vector<int> fibs = generate_Fibonacci(n);
    std::copy(fibs.begin(), fibs.end(), std::ostream_iterator<int>(cout, " "));
    assert(fibs[9] == 34);
    assert(fibs[14] == 377);
    cout << endl;
}
/*

// Task 9
void task_9_test_driver(unsigned long n)
{
    cout << "\nTask 9: Fibonacci generator" << endl;
    FibGen fib{ n };
    for (FibGen iter = fib.begin(); iter != fib.end(); ++iter)
    {
        cout << *iter << ' ';
    }
    cout << '\n';
    // equivalently:
    for (auto f : fib)
    {
        cout << f << ' ';
    }
    cout << '\n';
}
*/

int main()
{
    std::string infilename{ R"(/Users/ali/repos/containers-iterators-algorithms/data/words.txt)" };
    WordsVector words_vector = task_1_test_driver(infilename);
    task_2_test_driver(words_vector);
    task_3_test_driver(words_vector);
    task_4_test_driver(words_vector);
    task_5_test_driver();
    task_6_test_driver();
    task_7_test_driver();
    task_8_test_driver(15);
/*

    task_9_test_driver(10);
*/

    return 0;
}

