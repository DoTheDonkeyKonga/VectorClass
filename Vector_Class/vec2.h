#ifndef VEC2F_H_DZG_INCLUDED
#define VEC2F_H_DZG_INCLUDED

#pragma once


/*
	A class to define a mathematical vector with two coordinates (x and y).
	It can be used to represent anything with two dimensions (e.g. a point or a velocity etc.).
	All members are public and can be accessed directly without the need for accessors or mutators etc.
	It contains common mathematical functions such as dot product, cross product and magnitude (length) etc.
	Most functions also have static versions.
	Certain operators are overloaded for simple arithmetic and comparison operations but explicit arithmetic
	functions are also included for convenience/preference.

	Written by DoTheDonkeyKonga @ I_M_Awesome Productions
	IMAProductions@cyber-wizard.com
	05.12.2017, ver: 1.0
*/


class vec2f {

public:
	// Default constructor: initialises all values to zero
	vec2f();
	// Conversion constructors
	vec2f(float xVal, float yVal);
	vec2f(float xyVal);
	// Copy constructor
	vec2f(const vec2f &vec);


	float x;
	float y;


	/// MEMBER FUNCTIONS

	float getMagnitude() const;
	double getDirectionDegrees() const;
	double getDirectionRadians() const;

	void setMagnitude(float newLength);
	void setDirection(float angle); // TODO implement definition

	vec2f vectorTo(vec2f &target) const;

	float dotProduct(const vec2f &vec) const;
	float crossProduct(const vec2f &vec) const;
	float distanceTo(vec2f &vec) const;

	void clampLength(float maxLength);
	void normalise();

	std::string toString() const;

	// Methods to conveniently set the vector's X and Y values
	void set(float x, float y);
	void set(float xyVal);
	void set(const vec2f vec);
	void zero();


	/// OPERATORS AND ARITHMETIC FUNCTIONS

	// Vector arithmetic functions
	void add(const vec2f &vec);
	void subtract(const vec2f &vec);
	void multiply(const vec2f &vec);
	void divide(const vec2f &vec);
	// Scaler arithmetic functions
	void scalarAdd(const float &s);
	void scalarSubtract(const float &s);
	void scalarMultiply(const float &s);
	void scalarDivide(const float &s);

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

	static float getMagnitude(const vec2f &vec);
	static double getDirectionDegrees(const vec2f &vec);
	static double getDirectionRadians(const vec2f &vec);

	static void setMagnitude(vec2f &vec, float newLength);
	static void setDirection(vec2f &vec, float angle); // TODO implement definition

	static vec2f vectorTo(const vec2f &vec, const vec2f &target);

	static float dotProduct(const vec2f &vec1, const vec2f &vec2);
	static float crossProduct(const vec2f &vec1, const vec2f &vec2);
	static float distanceTo(const vec2f &vec1, const vec2f &vec2);

	static void clampLength(vec2f &vec, float maxLength);
	static void normalise(vec2f &vec);
	static double RadsToDegs(double radians);


	/// HELPER FUNCTIONS

	// Prints the vector's properties to the console
	void display();
};

#endif // VEC2F_H_DZG_INCLUDED
