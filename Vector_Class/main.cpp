#include <iostream>
#include <string>
#include "vec2.h"


void OutputBasicToConsole();
void OutputAdvancedToConsole();

// initialise our vectors
vec2f myVec1;
vec2f myVec2(6.f, 3.f);
vec2f myVec3(-69.f, 69.f);
vec2f myVec4(-150.f, -44.f);


int main()
{
	std::cout << "Hello World! We're testing our new vector class.\nThese are the default values we've given our vectors..." << std::endl << std::endl;


	OutputBasicToConsole();


	// set a new length for all of our vectors
	myVec1.setMagnitude(5.f);
	myVec2.setMagnitude(69.f);
	myVec3.setMagnitude(12.f);
	myVec4.setMagnitude(14.5f);

	std::cout << "We've set new lengths for our vectors..." << std::endl << std::endl;

	OutputBasicToConsole();


	// normalise all our vectors
	myVec1.normalise();
	myVec2.normalise();
	myVec3.normalise();
	myVec4.normalise();

	std::cout << "All vectors have now been normalised.\nSee what happens to their components, length and direction..." << std::endl << std::endl;

	OutputBasicToConsole();


	myVec1.setMagnitude(100.f);
	myVec2.setMagnitude(.001f);
	myVec3.setMagnitude(-60.f);
	myVec4.setMagnitude(22.f);

	myVec1.clampLength(25);
	myVec2.clampLength(25);
	myVec3.clampLength(25);
	myVec4.clampLength(25);

	std::cout << "Now we're going to set their lengths,\nthen clamp their lengths to a MAXIMUM value of 25..." << std::endl << std::endl;

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
	myVec3.set(-69.f, 69.f);
	myVec4.set(-150.f, -44.f);

	OutputBasicToConsole();

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


void OutputAdvancedToConsole()
{	
	return;
}