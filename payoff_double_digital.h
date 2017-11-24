#ifndef __PAY_OFF_DOUBLE_DIGITAL_H
#define __PAY_OFF_DOUBLE_DIGITAL_H

#include "payoff.h"

class PayOffDoubleDigital : public PayOff {
private:
	double U;	// Upper strike price
	double D;	// Lower strike price

public:
	// Two strike parameters
	PayOffDoubleDigital(const double U_, const double D_);
	virtual ~PayOffDoubleDigital();

	// Pay-off = 1 if spot within U and D, 0 otherwise
	virtual double operator() (const double S) const;
};

#endif