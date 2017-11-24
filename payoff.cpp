#ifndef __PAY_OFF_CPP
#define __PAY_OFF_CPP

#include "payoff.h"

PayOff::PayOff() {}

// ==========
// PayOffCall
// ==========

// Constructor with single strike parameter
PayOffCall::PayOffCall(const double _K) {K = _K;}

// Override operator() method conversion to function object
double PayOffCall::operator() (const double S) const {
	return std::max(S-K, 0.0);	//Standard European call pay-off
}

// =========
// PayOffPut
// =========

// Constructor with single strike parameter
PayOffPut::PayOffPut(const double _K) { K = _K;}

// Override operator() method conversion to function object
double PayOffPut:: operator() (const double S) const {
	return std::max(K-S, 0.0); // Standard European put pay-off
}

#endif