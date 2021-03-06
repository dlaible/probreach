// Integral class implements a verified integration
// procedure for an arbitrary four times differentiable 
// function using interval version of (1/3) Simpson's rule.
// The result of computation is an interval of arbitrarily
// small positive length containing the exact value of the
// definite integral
//
// @author: Fedor Shmarov
// @e-mail: f.shmarov@ncl.ac.uk
#ifndef INTEGRAL_H  
#define INTEGRAL_H  

#include<capd/capdlib.h>
#include<capd/intervals/lib.h>
#include<string>
#include "PartialSum.h"
#include "RV.h"

using namespace std;
using namespace capd;

// Integral class declaration
class Integral
{
	private:

		// Required width of the interval containing the value of the integral
		double precision;

		// Four times differentiable function in the string format
		string fun;

		// The name of the variable with respect to ehich the 
		// integration is performed
		string var;

		// The interval where the definite integral is calculated
		DInterval interval;

		// The interval containing the exact value of the integral
		DInterval value;

		// List of partial sums forming the value of the
		// definite integral
		vector<PartialSum> partial_sums;

		// Temporary list of the partial sums
		vector<PartialSum> temp_vector;

		// The method performs calculation of the integral
		void calculate_value();
		
	public:

		// Constructor of the class
		//
		// @param name of the variable, inegrated function,
		// integration interval and precision
		Integral(string, string, DInterval, double);

		// The methods returns the integrated function
		string get_fun();

		// The method returns the name of the variable
		// with respect to which the integration is performed
		string get_var();

		// The method returns the value of the integral
		DInterval get_value();

		// The method returns the integration interval
		DInterval get_interval();

		// The method retuns precision used for
		// calculating the integral
		double get_precision();

		// The method sets a precision on the
		// integral calculation
		//
		// @param precision
		void set_precision(double);

		// The method returns partial sums forming
		// the value of the integral
		vector<PartialSum> get_partial_sums();

		// The method sets a list of partial sums
		//
		// @param list of partial sums
		void set_partial_sums(vector<PartialSum>);
};
#endif 