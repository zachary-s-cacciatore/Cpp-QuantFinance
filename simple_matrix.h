#IFNDEF __SIMPLE_MATRIX_H
#DEFINE __SIMPLE_MATRIX_H

#include <vector>	// Need to store matrix values

template <typename Type = double> class SimpleMatrix
{
private: 
	vector<vector<Type> > mat;	// Vector of vectores to store values

public:
	SimpleMatrix();	// Default constructor

	// Constructor specifiying rows, columns, and default value
	SimpleMatrix(const int& row, const int& cols, const Type& val);

	SimpleMatrix(const SimpleMatrix<Type>& _rhs);	// Copy constructor

	SimpleMatrix<Type>& operator= (const SimpleMatrix<Type>& _rhs);	// Assignment operator overloaded

	virtual ~SimpleMatrix();	// Destructor

	// Access to matrix values directly via row and column indices
	vector<vector<Type> > get_mat() const;	

	Type& value(const int& row, const int& col);
	
};

#include "simple_matrix.cpp"

#ENDIF

