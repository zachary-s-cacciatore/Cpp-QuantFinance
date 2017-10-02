#ifndef __VANILLA_OPTION_H
#define __VANILLA_OPTION_H 

#define _USE_MATH_DEFINES
#include <cmath>

// Define the Vanilla Option class
class VanillaOption {
private:
	void init();
	void copy(const VanillaOption& rhs);

	double K;       // Strike price
	double r;       // Risk-free rate
	double T;       // Maturity time
	double S;       // Underlying asset price
	double sigma;   // Volatility of underlying asset

public:
	VanillaOption();   // Default constructor - has no parameters
	VanillaOption(const double& _K, const double& _r,
		const double& _T, const double& _S,
		const double& _sigma);     // Parameter constructor
	VanillaOption(const VanillaOption& rhs);             // Copy constructor  
	VanillaOption& operator=(const VanillaOption& rhs);  // Assignment operator
	virtual ~VanillaOption();                            // Destructor is virtual

	// Selector methods for our option parameters
	double getK() const;
	double getr() const;
	double getT() const;
	double getS() const;
	double getsigma() const;

	// Option price calculation methods
	double calc_call_price() const;
	double calc_put_price() const;
};
