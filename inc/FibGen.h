//
// Created by Ali Sayed Salehi on 2023-08-12.
//

#ifndef CONTAINERS_ITERATORS_ALGORITHMS_FIBGEN_H
#define CONTAINERS_ITERATORS_ALGORITHMS_FIBGEN_H

#include <iostream>

class FibGen {
private:
    /**
     * how many Fibonacci terms to generate.
     */
    unsigned long max{};
    /**
     * counts how many fibonacci numbers have been generated
     */
    unsigned long counter{};
    /**
     * the current fibonacci number
     */
    unsigned long current_fib_number{};

    /**
     * the previous fibonacci number in the sequence
     */
    unsigned long previous_fib_number{};

    /**
     * generates the next fibonacci number and set it to the current number
     * @return
     */
    void next_fib_number();

public:
    FibGen() = default;
    explicit FibGen(unsigned long max);
    FibGen& operator=(const FibGen& rhs);
    unsigned long operator*() const { return current_fib_number; }

    /**
     * pre-increment operator
     * @return
     */
    FibGen& operator++();

    /**
     * post-increment operator
     * @return
     */
    FibGen operator++(int);

    bool operator==(const FibGen& other) const;
    bool operator!=(const FibGen& other) const;

    const FibGen& begin() const;
    FibGen end() const;

    /**
     * generate n fibonacci numbers and print them
     * @param n
     */
    static void fib_generator(unsigned long n);
};


#endif //CONTAINERS_ITERATORS_ALGORITHMS_FIBGEN_H
