#include "int_accumulator.h"

int_accumulator::Accumulator::Accumulator(int x) {
    int_accumulator::Accumulator::acc_ = x;
}

void int_accumulator::Accumulator::Add(int a) {
    int_accumulator::Accumulator::acc_ += a;
}

void int_accumulator::Accumulator::Sub(int a) {
    int_accumulator::Accumulator::acc_ -= a;
}

void int_accumulator::Accumulator::Mult(int a) {
    int_accumulator::Accumulator::acc_ *= a;
}

void int_accumulator::Accumulator::Div(int a) {
    assert(a != 0 && "Divide-by-zero");
    int_accumulator::Accumulator::acc_ /= a;
}

int int_accumulator::Accumulator::acc() {
    return int_accumulator::Accumulator::acc_;
}
