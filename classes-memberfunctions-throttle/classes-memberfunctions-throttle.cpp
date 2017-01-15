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