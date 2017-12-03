#include <iostream>
#include <string>
#include "vec2.h"


// for convenience
void OutputBasicToConsole();
void OutputAdvancedToConsole();

// initialise our vectors
vec2f myVec1;
vec2f myVec2(6.f, 3.f);
vec2f myVec3(269.f, 72.f);
vec2f myVec4(150.5f, 144.2f);


/*
	Just for testing...
*/
int main()
{
	std::cout << "Hello World! We're testing our new vector class.\n\nThese are the default values we've given our vectors..." << std::endl << std::endl;


	OutputBasicToConsole();

	try {
		myVec1.setMagnitude(0.f);
		myVec2.setMagnitude(105.f);
		myVec3.setMagnitude(12.f);
		myVec4.setMagnitude(14.5f);
	}
	catch (const std::invalid_argument& arg) {
		std::cerr << "Invalid argument: " << arg.what() << std::endl << std::endl;
		std::cin.ignore();
		return 0;
	}


	std::cout << "We've set new lengths for our vectors..." << std::endl << std::endl;

	OutputBasicToConsole();


	// normalise all our vectors
	myVec1.normalise();
	myVec2.normalise();
	myVec3.normalise();
	myVec4.normalise();

	std::cout << "All vectors have now been normalised.\nSee what happens to their components, length and direction..." << std::endl << std::endl;

	OutputBasicToConsole();


	std::cout << "Now we're going to set their lengths,\nthen clamp their lengths to a MAXIMUM value of 25..." << std::endl << std::endl;

	// set new lengths
	myVec1.setMagnitude(100.f);
	myVec2.setMagnitude(.001f);
	myVec3.setMagnitude(-60.f);
	myVec4.setMagnitude(22.f);
	// arbitrarily clamp lengths to 25
	myVec1.clampLength(25);
	myVec2.clampLength(25);
	myVec3.clampLength(25);
	myVec4.clampLength(25);

	OutputBasicToConsole();


	std::cout << "Zero all our vectors..." << std::endl << std::endl;

	myVec1.zero();
	myVec2.zero();
	myVec3.zero();
	myVec4.zero();

	OutputBasicToConsole();


	std::cout << "Reset our vectors ready for the next test..." << std::endl << std::endl;

	myVec1.set(0, 0);
	myVec2.set(6.f, 3.f);
	myVec3.set(269.f, 72.f);
	myVec4.set(150.5f, 144.2f);

	OutputBasicToConsole();

	// TODO add advanced tests to see if the rest of our methods and operators are working correctly

	// keep terminal open
	std::cin.ignore();
	
	return 0;
}


void OutputBasicToConsole()
{
	std::cout << "     VECTOR 1..." << std::endl << "------------------------------------------------" << std::endl;
	myVec1.display();
	std::cout << "     VECTOR 2..." << std::endl << "------------------------------------------------" << std::endl;
	myVec2.display();
	std::cout << "     VECTOR 3..." << std::endl << "------------------------------------------------" << std::endl;
	myVec3.display();
	std::cout << "     VECTOR 4..." << std::endl << "------------------------------------------------" << std::endl;
	myVec4.display();
	std::cout << std::endl;
	std::cout << "================================================" << std::endl;

	return;
}


void OutputAdvancedToConsole() // TODO implement
{	
	std::cout << "     VECTOR 1..." << std::endl << "------------------------------------------------" << std::endl;
	// ... vec1 stuff goes here...
	std::cout << "     VECTOR 2..." << std::endl << "------------------------------------------------" << std::endl;
	// ... vec2 stuff goes here...
	std::cout << "     VECTOR 3..." << std::endl << "------------------------------------------------" << std::endl;
	// ... vec3 stuff goes here...
	std::cout << "     VECTOR 4..." << std::endl << "------------------------------------------------" << std::endl;
	// ... vec4 stuff goes here...
	std::cout << std::endl;
	std::cout << "================================================" << std::endl;

	return;
}