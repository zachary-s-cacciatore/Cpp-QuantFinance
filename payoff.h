#ifndef __PAY_OFF_H
#define __PAY_OFF_H

#include <algorithm>

class PayOff {
public:
	PayOff() {};			// Default constructor (no parameters)
	virtual ~PayOff() {};	// Virtual destructor

	// Overloaded operator(), turns PayOff into abstract function object
	virtual double operator() (const double S) const = 0;	// Pure virtual method
};

class PayOffCall : public PayOff {
private:
	double K;	// Strike price

public:
	PayOffCall(const double K_) {};		// No default constructor
	virtual ~PayOffCall() {};		// Destructor virtual for further inheritance
// Virtual function override
virtual double operator() (const double S) const;	// Pay-Off is max(S-K, 0)
};

class PayOffPut : public PayOff {
private:
	double K; // Strike price

public:
	PayOffPut(const double K);
	virtual ~PayOffPut() {};
	virtual double operator() (const double S) const;
};

#endif
