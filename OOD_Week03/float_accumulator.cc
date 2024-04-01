#include "float_accumulator.h"

float_accumulator::Accumulator::Accumulator(float x) {
    float_accumulator::Accumulator::acc_ = x;
}

void float_accumulator::Accumulator::Add(float x) {
    float_accumulator::Accumulator::acc_ += x;
}

void float_accumulator::Accumulator::Sub(float x) {
    float_accumulator::Accumulator::acc_ -= x;
}

void float_accumulator::Accumulator::Mult(float x) {
    float_accumulator::Accumulator::acc_ *= x;
}

void float_accumulator::Accumulator::Div(float x) {
    assert(x != 0 && "Divide-by-zero");
    float_accumulator::Accumulator::acc_ /= x;
}

float float_accumulator::Accumulator::acc() {
    return float_accumulator::Accumulator::acc_;
}
