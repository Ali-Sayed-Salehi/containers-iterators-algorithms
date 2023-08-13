//
// Created by Ali Sayed Salehi on 2023-08-12.
//

#include "FibGen.h"

FibGen::FibGen(unsigned long max) : max(max) {
}

FibGen &FibGen::operator++() {
    next_fib_number();
    return *this;
}

FibGen FibGen::operator++(int) {
    auto temp{ *this };
    ++(*this);
    return temp;
}

bool FibGen::operator==(const FibGen &other) const {
    return this->counter == other.counter;
}

bool FibGen::operator!=(const FibGen &other) const {
    return this->counter != other.counter;
}

const FibGen &FibGen::begin() const {
    return *this;
}

FibGen FibGen::end() const {
    auto sentinel = FibGen{};
    sentinel.counter = max;
    return sentinel;
}

FibGen &FibGen::operator=(const FibGen &rhs) {
    if (this == &rhs) return *this;

    max = rhs.max;
    current_fib_number = rhs.current_fib_number;
    counter = rhs.counter;
    return *this;
}

void FibGen::fib_generator(unsigned long n) {
    FibGen fib{n};
    for (FibGen iter = fib.begin(); iter != fib.end(); ++iter) {
        std::cout << *iter << " ";
    }
    std::cout << "\n";
}

void FibGen::next_fib_number() {
    unsigned long new_fib_number{};
    ++counter;

    if (counter == 0) {
        new_fib_number = 0;
    } else if (counter == 1) {
        new_fib_number = 1;
    } else {
        new_fib_number = current_fib_number + previous_fib_number;
        previous_fib_number = current_fib_number;
    }
    current_fib_number = new_fib_number;

}
