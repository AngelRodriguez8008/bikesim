#include "cheby1lowpass.h"

/*
 * This file is autogenerated. Please do not modify directly as changes may be
 * overwritten.
 */

namespace {
    // Cheby1 lowpass filter
    // order: 4
    // cutoff freq: 5.0
    // sample freq: 100.0
    const double a[] = { 0.000416599204407,0.00166639681763,0.00249959522644,0.00166639681763,0.000416599204407 };
    const double b[] = { 1.0,-3.18063854887,3.86119434899,-2.11215535511,0.438265142262 };
} // namespace

Cheby1Lowpass::Cheby1Lowpass(): _x{0.0f}, _y{0.0f}, _n{0} { }

float Cheby1Lowpass::filter(float sample) {
    _x[_n] = sample;
    _y[_n] = b[0]*_x[_n];
    for (int i = 1; i < _size; ++i) {
        _y[_n] += b[i]*_x[(_n - i + _size) % _size]
            - a[i]*_y[(_n - i + _size) % _size];
    }

    float result = _y[_n];
    _n = (_n + 1) % _size;
    return result;
}