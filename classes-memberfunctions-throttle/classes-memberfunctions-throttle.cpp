// classes-memberfunctions-throttle.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include <iostream>		// provides cout and cin
#include <cstdlib>		// provides exit_success
using namespace std;	// allows all standard library items ot be used

// this data type is a class
class throttle
{
	// member list
	public:
		// MODIFICATION MEMBER FUNCTIONS
		void shut_off();
		void shift(int amount);

		// CONSTANT MEMBER FUNCTIONS
		double flow() const;
		bool is_on() const;

	private:
		int position;
};

int main()
{
	throttle sample;
	int user_input;

	// set the sample throttle to a position indicated by the user.
	cout << "I have a throttle with 6 positions." << endl;
	cout << "Where would you like to set the throttle? " << endl;
	cout << "Please type a number form 0 to 6: ";
	cin >> user_input;
	sample.shut_off();
	sample.shift(user_input);

	// shift the throttle downt o zero, printing the flow along thew way.
	while (sample.is_on())
	{
		cout << "The flow is now " << sample.flow() << endl;
		sample.shift(-1);
	}
	cout << "The flow is now " << sample.flow() << endl;
	return EXIT_SUCCESS;
}

void throttle::shut_off()
// precondition: none
// postcondition: the throttle has been turned off
{
	position = 0;
}

void throttle::shift(int amount)
// precondition: shut_off has been called at least once to initialize the throttle.
// postcoondition: the throttle's position has been moved by amount (but
// not below 0 or above 6)
{
	position += amount;
	if (position < 0)
		position = 0;
	else if (position > 6)
		position = 6;
}

double throttle::flow() const
// precondition: shut_off has been called at least once to initialize the throttle
// postcondition: the value returned is the current flow as a proportion
// of maximum flow
{
	return position / 6.0;
}

bool throttle::is_on() const
// precondition : shut_off has been called at least once to initialize the throttle
// postcondition: if the throttle's flow is above 0, then the function
// returns true; otherwise, it returns false.
{
	return(flow() > 0);
}