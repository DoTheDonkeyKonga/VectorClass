#ifndef VEC2T_DZG_H
#define VEC2T_DZG_H

#pragma once


/*
	Written by DoTheDonkeyKonga @ I_M_Awesome Productions
	IMAProductions@cyber-wizard.com

	A class to define a mathematical vector with two coordinates (x and y).
	It can be used to represent anything with two dimensions (e.g. a point or a velocity etc.).
	All members are public and can be accessed directly without the need for accessors or mutators etc.
	It contains common mathematical functions such as dot product, cross product and magnitude (length) etc.
	Most functions also have static versions.
	Certain operators are overloaded for simple arithmetic and comparison operations but explicit arithmetic
	functions are also included for convenience/preference.
*/


class vec2f { // TODO convert to template class

public:
	
	float x;
	float y;

	// Default constructor: initialises all values to zero
	vec2f();
	// Overloaded constructor: specify initial values for x and y
	vec2f(float x, float y);
	// Overloaded constructor: specify one value for both x and y
	vec2f(float xyVal);


	/// MEMBER FUNCTIONS
	
	// Returns the length of the vector from its origin
	float getMagnitude() const;

	// Returns direction (angle from the X axis) of the vector in degrees
	double getDirectionDegrees() const;

	// Returns direction (angle from the X axis) of the vector in radians
	double getDirectionRadians() const;

	// Sets the length of the vector
	void setMagnitude(float newLength);

	// Sets the direction (angle from the X axis) of the vector
	void setDirection(float angle); // TODO implement definition

	// Returns the vector to target
	vec2f vectorTo(vec2f &target) const;

	// Returns the dot product of the vector and vec
	float dotProduct(const vec2f &vec) const;

	// Returns the (2D analogue) cross product of the vector and vec
	float crossProduct(const vec2f &vec) const;

	// Returns the distance between the vector and vec
	float distanceTo(vec2f &vec) const;

	// Limits the magnitude of the vector only if it exceeds maxLength
	void clampLength(float maxLength);

	// Converts the vector to a unit vector (length 1)
	void normalise();

	// Returns the vector's X and Y values as a string
	std::string toString() const;

	// Methods to conveniently set the vector's X and Y values
	void set(float x, float y);
	void set(float xyVal);
	void set(vec2f vec);
	
	// Reset the vector to zero values
	void zero();


	/// OPERATORS AND ARITHMETIC FUNCTIONS

	// Vector arithmetic functions
	vec2f add(vec2f vec);
	vec2f subtract(vec2f vec);
	vec2f multiply(vec2f vec);
	vec2f divide(vec2f vec);
	// Scaler arithmetic functions
	vec2f scalarAdd(float s);
	vec2f scalarSubtract(float s);
	vec2f scalarMultiply(float s);
	vec2f scalarDivide(float s);
	
	// Overloaded operators
	vec2f operator+(const vec2f &vec) const;
	vec2f operator-(const vec2f &vec) const;
	vec2f operator*(const vec2f &vec) const;
	vec2f operator/(const vec2f &vec) const;
	// Compound assignment operators
	vec2f operator+=(const vec2f &vec);
	vec2f operator-=(const vec2f &vec);
	vec2f operator*=(const vec2f &vec);
	vec2f operator/=(const vec2f &vec);
	// Comparison operators
	vec2f operator==(const vec2f &vec);
	vec2f operator!=(const vec2f &vec);


	/// STATIC FUNCTIONS

	// Returns the length of vec from its origin
	static float getMagnitude(const vec2f &vec);

	// Returns direction (angle from the X axis) of vec in degrees
	static double getDirectionDegrees(const vec2f &vec);

	// Returns direction (angle from the X axis) of vec in radians
	static double getDirectionRadians(const vec2f &vec);

	// Sets the length of vec
	static void setMagnitude(vec2f &vec, float newLength);

	// Sets the direction (angle from the X axis) of vec
	static void setDirection(vec2f &vec, float angle); // TODO implement definition

	// Returns the vector from vec to target
	static vec2f vectorTo(const vec2f &vec, const vec2f &target);

	// Returns the dot product of vec1 and vec2
	static float dotProduct(const vec2f &vec1, const vec2f &vec2);

	// Returns the (2D analogue) cross product of vec1 and vec2
	static float crossProduct(const vec2f &vec1, const vec2f &vec2);

	// Returns the distance between vec1 and vec2
	static float distanceTo(const vec2f &vec1, const vec2f &vec2);

	// Limits the magnitude of vec only if it exceeds maxLength
	static void clampLength(vec2f &vec, float maxLength);

	// Converts vec to a unit vector (length 1)
	static void normalise(vec2f &vec);


	/// HELPER FUNCTIONS

	// Returns conversion from Radians to Degrees
	static double RadsToDegs(double radians);
	
	// Print the vector's properties to the console
	void display();
};

#endif /* VEC2T_DZG_H */