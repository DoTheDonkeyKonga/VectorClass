// TODO write proper description etc.

/*
	Written by DoTheDonkeyKonga @ I_M_Awesome Productions
	IMAProductions@cyber-wizard.com
*/

#pragma once

class vec2f {

public:
	
	float x;
	float y;

	// Default constructor: initialises all values to zero
	vec2f();
	// Overloaded constructor: specify initial values for x and y
	vec2f(float xVal, float yVal);
	// Overloaded constructor: specify one value for both x and y
	vec2f(float xyVal);


	// Returns the length of the vector from its origin
	float getMagnitude();
	// Returns the length of vec from its origin
	static float getMagnitude(const vec2f &vec);


	// Returns direction (angle from the X axis) of the vector (in degrees)
	double getDirectionDeg();
	// Returns direction (angle from the X axis) of vec (in degrees)
	static double getDirectionDeg(const vec2f &vec);
	// Returns direction (angle from the X axis) of the vector (in radians)
	double getDirectionRad();
	// Returns direction (angle from the X axis) of vec (in radians)
	static double getDirectionRad(const vec2f &vec);


	// Sets the length of the vector
	void setMagnitude(float newLength);
	// Sets the length of vec
	static void setMagnitude(vec2f &vec, float newLength);


	// Sets the direction (angle from the X axis) of the vector
	void setDirection(float angle); // TODO implement definition
	// Sets the direction (angle from the X axis) of vec
	static void setDirection(vec2f &vec, float angle); // TODO implement definition


	// Returns the vector to target
	vec2f vectorTo(vec2f &target);
	// Returns the vector from vec to target
	static vec2f vectorTo(vec2f &vec, vec2f &target);


	// Returns the dot product of the vector and vec
	float dotProduct(const vec2f &vec);
	// Returns the dot product of vec1 and vec2
	static float dotProduct(const vec2f &vec1, const vec2f &vec2);


	// Returns the (2D analogue) cross product of the vector and vec
	float crossProduct(const vec2f &vec);
	// Returns the (2D analogue) cross product of vec1 and vec2
	static float crossProduct(const vec2f &vec1, const vec2f &vec2);


	// Returns the distance between the vector and vec
	float distanceTo(const vec2f &vec);
	// Returns the distance between vec1 and vec2
	static float distanceTo(const vec2f &vec1, const vec2f &vec2);


	// Limits the magnitude of the vector only if it exceeds maxLength
	void clampLength(float maxLength);
	// Limits the magnitude of vec only if it exceeds maxLength
	static void clampLength(vec2f &vec, float maxLength);


	// Converts the vector to a unit vector (length 1)
	void normalise();
	// Converts vec to a unit vector (length 1)
	static void normalise(vec2f &vec);


	// Returns the vector's X and Y values as a string
	std::string toString();


	// Methods to set the vector's X and Y values
	void set(float x, float y);
	void set(vec2f vec);
	// Reset the vector to zero values
	void zero();


	/// Vector arithmetic functions
	vec2f add(vec2f vec);
	vec2f subtract(vec2f vec);
	vec2f multiply(vec2f vec);
	vec2f divide(vec2f vec);

	/// Scaler arithmetic functions
	vec2f scalarAdd(float s);
	vec2f scalarSubtract(float s);
	vec2f scalarMultiply(float s);
	vec2f scalarDivide(float s);
	
	/// Overloaded operators
	vec2f operator+(const vec2f &vec) const;
	vec2f operator-(const vec2f &vec) const;
	vec2f operator*(const vec2f &vec) const;
	vec2f operator/(const vec2f &vec) const;
	/// Compound assignment operators
	vec2f operator+=(const vec2f &vec);
	vec2f operator-=(const vec2f &vec);
	vec2f operator*=(const vec2f &vec);
	vec2f operator/=(const vec2f &vec);

	/// Helper functions
	// Returns conversion from Radians to Degrees
	static double RadsToDegs(double radians);
	// Print the vector's properties to the console
	void display();

};