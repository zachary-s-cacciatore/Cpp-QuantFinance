#ifndef __VANILLA_OPTION_CPP
#define __VANILLA_OPTION_CPP
#define _USE_MATH_DEFINES

#include <cmath>
#include <iostream>
#include "vanilla_option.h"

// Initialize member data
void VanillaOption::init() {
	K = 100.0;
	r = 0.05;	// 5% interest rate
	T = 1.0;	// One year maturity
	S = 100.0;	// Option 'at the money'
	sigma = 0.2;	// Volatility 20%
}

//Copies member data
void VanillaOption::copy(const VanillaOption& rhs) {
	K = rhs.getK();
	r = rhs.getr();
	T = rhs.getT();
	sigma = rhs.getsigma();
}

// Default constructor - calls init
VanillaOption::VanillaOption() { init(); }

//Parameter constructor
VanillaOption::VanillaOption(const double& _K, const double& _r,
						     const double& _T, const double& _S,
	                         const double& _sigma) {
	K = _K;
	r = _r;
	T = _T;
	S = _S;
	sigma = _sigma;
}

// Copy constructor
VanillaOption::VanillaOption(const VanillaOption& rhs) {
	copy(rhs);
}

// Assignment operator
VanillaOption& VanillaOption::operator=(const VanillaOption& rhs) {
	if (this == &rhs) return *this;
	copy(rhs);
	return *this;
}

//Destructor

VanillaOption::~VanillaOption() {
	// Empty, compiler provides implementation
}

// Public access for strike price, K
double VanillaOption::getK() const { return K; }

// Public access for the risk-free rate, r
double VanillaOption::getr() const { return r; }

// Public access for the time to maturity, T
double VanillaOption::getT() const { return T; }

// Public access for the spot price, S
double VanillaOption::getS() const { return S; }

// Public access for the volatility of the asset, sigma
double VanillaOption::getsigma() const { return sigma; }

// An approximation to the cumulative distribution function
// for the standard normal distribution
double N(const double x) {
	double k = 1.0 / (1.0 + 0.2316419*x);
	double k_sum = k*(0.319381530 + k*(-0.356563782 + k*(1.781477937 + k*(-1.821255978 + 1.330274429*k))));

	if (x >= 0.0) {
		return (1.0 - (1.0 / (pow(2 * M_PI, 0.5)))*exp(-0.5*x*x) * k_sum);
	}
	else {
		return 1.0 - N(-x); // Recursion
	}
}

// Calculate the vanilla call price
double VanillaOption::calc_call_price() const {
	double sigma_sqrt_T = sigma * sqrt(T);
	double d_1 = (log(S / K) + (r + sigma * sigma * 0.5) * T) / sigma_sqrt_T;
	double d_2 = d_1 - sigma_sqrt_T;
	return S * N(d_1) - K * exp(-r*T) * N(d_2);
}

// Calculate the vanilla put price
double VanillaOption::calc_put_price() const {
	double sigma_sqrt_T = sigma * sqrt(T);
	double d_1 = (log(S / K) + (r + sigma * sigma * 0.5) * T) / sigma_sqrt_T;
	double d_2 = d_1 - sigma_sqrt_T;
	return K * exp(-r*T) * N(-d_2) - S * N(-d_1);
}

int main(int argc, char **argv) {
	VanillaOption option; // Create vanilla option

	// Calculate call and put prices
	double call = option.calc_call_price();
	double put = option.calc_put_price();

	// Output option parameters
	std::cout << "Strike, K: " << option.getK() << std::endl;
	std::cout << "Risk-free rate, r: " << option.getr() << std::endl;
	std::cout << "Time to maturity, T: " << option.getT() << std::endl;
	std::cout << "Spot price, S: " << option.getS() << std::endl;
	std::cout << "Volatility of asset, sigma: " << option.getsigma() << std::endl;

	// Output option prices
	std::cout << "Call price:" << call << std::endl;
	std::cout << "Put price:" << put << std::endl;

	std::cin.get();

	return 0;

}

