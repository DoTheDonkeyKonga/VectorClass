
#include <iostream>
#include <stdexcept>
#include <string>
#include <math.h>
#include "vec2.h"


const double PI = 3.141592653589793238;
//const double PI2 = 6.283185307179586476;


// Default constructor: initialises all values to zero
vec2f::vec2f() : x(.0f), y(0.f) { }
// Conversion constructor: specify values for x and y
vec2f::vec2f(float xVal, float yVal) : x(xVal), y(yVal) { }
// Conversion constructor: specify one value for both x and y
vec2f::vec2f(float xyVal) : x(xyVal), y(xyVal) { }
// Copy constructor: initialise values from another vec2f
vec2f::vec2f(const vec2f &vec) : x(vec.x), y(vec.y) { }


/// MEMBER FUNCTIONS

// Returns the length of the vector from its origin
float vec2f::getMagnitude() const
{
	return sqrt(x * x + y * y);
}

// Returns direction (angle from the horizontal) of the vector in degrees
double vec2f::getDirectionDegrees() const
{
	double angle = atan2(y, x);
	if (RadsToDegs(angle) < 0)
	{
		return RadsToDegs(angle) + 360;
	}
	else
	{
		return RadsToDegs(angle);
	}
}
// Returns direction (angle from the horizontal) of the vector in radians
double vec2f::getDirectionRadians() const
{
	double angle = atan2(y, x);
	return angle;
}

// Sets the length of the vector
void vec2f::setMagnitude(float newLength)
{
	float currentLength = this->getMagnitude();
	if (currentLength == 0.f) { return; }
	if (newLength == 0.f)
	{
		throw std::invalid_argument("Value for new length cannot be zero (division by zero not allowed)");
	}
	x *= newLength / currentLength;
	y *= newLength / currentLength;
	return;
}

// Sets the direction (angle from the X axis) of the vector
void vec2f::setDirection(float angle)
{
	return; // TODO implement function
}

// Returns the vector to target
vec2f vec2f::vectorTo(vec2f &target) const
{
	return vec2f(target.x - x, target.y - y);
}

// Returns the dot product of the vector and vec
float vec2f::dotProduct(const vec2f &vec) const
{
	return (x * vec.x) + (y * vec.y);
}

// Returns the (2D analogue) cross product of the vector and vec
float vec2f::crossProduct(const vec2f &vec) const
{
	return (x * vec.y) - (y * vec.x);
}

// Returns the distance between the vector and vec
float vec2f::distanceTo(vec2f &vec) const
{
	float dx = vec.x - x;
	float dy = vec.y - y;
	return sqrtf(dx * dx + dy * dy);
}

// Limits the magnitude of the vector only if it exceeds maxLength
void vec2f::clampLength(float maxLength)
{
	float length = this->getMagnitude();
	if (length != 0 && length > maxLength)
	{
		this->setMagnitude(maxLength);
	}
	return;
}

// Converts the vector to a unit vector (length 1)
void vec2f::normalise()
{
	float length = this->getMagnitude();
	if (length != 0)
	{
		x = x / length;
		y = y / length;
	}
	return;
}

// Returns the vector's X and Y values as a string
std::string vec2f::toString() const
{
	std::string xyVal = "X = " + std::to_string(x) + " Y = " + std::to_string(y);
	return xyVal;
}

// Methods to conveniently set the vector's X and Y values
void vec2f::set(float x, float y)
{
	this->x = x;
	this->y = y;
	return;
}
void vec2f::set(float xyVal)
{
	x = xyVal;
	y = xyVal;
	return;
}
void vec2f::set(const vec2f vec)
{
	x = vec.x;
	y = vec.y;
	return;
}
// Reset the vector to zero values
void vec2f::zero()
{
	x = .0f;
	y = .0f;
	return;
}


/// OPERATORS AND ARITHMETIC FUNCTIONS

// Vector arithmetic functions
void vec2f::add(const vec2f &vec) { x += vec.x, y += vec.y; }
void vec2f::subtract(const vec2f &vec) { x -= vec.x, y -= vec.y; }
void vec2f::multiply(const vec2f &vec) { x *= vec.x, y *= vec.y; }
void vec2f::divide(const vec2f &vec)
{
	if (vec.x == 0 || vec.y == 0)
	{
		throw std::invalid_argument("Division by zero not allowed!");
	}
	x /= vec.x, y /= vec.y;
}
// Scalar arithmetic functions
void vec2f::scalarAdd(const float &s) { x += s, y += s; }
void vec2f::scalarSubtract(const float &s) { x -= s, y -= s; }
void vec2f::scalarMultiply(const float &s) { x *= s, y *= s; }
void vec2f::scalarDivide(const float &s)
{
	if (s == 0)
	{
		throw std::invalid_argument("Division by zero not allowed!");
	}
	x /= s, y /= s;
}


// Overloaded operators
vec2f vec2f::operator+(const vec2f &vec) const { return vec2f(x + vec.x, y + vec.y); } // TODO Test all overloaded arithmetic operators
vec2f vec2f::operator-(const vec2f &vec) const { return vec2f(x - vec.x, y - vec.y); }
vec2f vec2f::operator*(const vec2f &vec) const { return vec2f(x * vec.x, y * vec.y); }
vec2f vec2f::operator/(const vec2f &vec) const { return vec2f(x / vec.x, y / vec.y); }
// Compound assignment operators
vec2f vec2f::operator+=(const vec2f &vec) { x += vec.x, y += vec.y; return *this; } // TODO Test all compound assignment operators
vec2f vec2f::operator-=(const vec2f &vec) { x -= vec.x, y -= vec.y; return *this; }
vec2f vec2f::operator*=(const vec2f &vec) { x *= vec.x, y *= vec.y; return *this; }
vec2f vec2f::operator/=(const vec2f &vec) { x /= vec.x, y /= vec.y; return *this; }
// Comparison operators
vec2f vec2f::operator==(const vec2f & vec) { return x == vec.x && y == vec.y; }
vec2f vec2f::operator!=(const vec2f & vec) { return x != vec.x || y != vec.y; }


/// STATIC FUNCTIONS

// Static: Returns the length of vec from its origin
float vec2f::getMagnitude(const vec2f &vec)
{
	return sqrt(vec.x * vec.x + vec.y * vec.y);
}

// Static: Returns direction (angle from the horizontal) of vec in degrees
double vec2f::getDirectionDegrees(const vec2f &vec)
{
	double angle = atan2(vec.y, vec.x);
	if (vec2f::RadsToDegs(angle) < 0)
	{
		return vec2f::RadsToDegs(angle) + 360;
	}
	else
	{
		return vec2f::RadsToDegs(angle);
	}
}

// Static: Returns direction (angle from the horizontal) of vec in radians
double vec2f::getDirectionRadians(const vec2f &vec)
{
	double angle = atan2(vec.y, vec.x);
	return angle;
}

// Static: Sets the length of vec
void vec2f::setMagnitude(vec2f &vec, float newLength)
{
	float currentLength = vec.getMagnitude();
	if (currentLength == 0.f) { return; }
	if (newLength == 0.f)
	{
		throw std::invalid_argument("Value for new length cannot be zero (division by zero not allowed)");
	}
	vec.x *= newLength / currentLength;
	vec.y *= newLength / currentLength;
	return;
}

// Static: Sets the direction (angle from the X axis) of vec
void vec2f::setDirection(vec2f &vec, float angle)
{
	return; // TODO implement function
}

// Static: Returns the vector from vec to target
vec2f vec2f::vectorTo(const vec2f &vec, const vec2f &target)
{
	return vec2f(target.x - vec.x, target.y - vec.y);
}

// Static: Returns the dot product of vec1 and vec2
float vec2f::dotProduct(const vec2f &vec1, const vec2f &vec2)
{
	return (vec1.x * vec2.x) + (vec1.y * vec2.y);
}

// Static: Returns the (2D analogue) cross product of vec1 and vec2
float vec2f::crossProduct(const vec2f &vec1, const vec2f &vec2)
{
	return (vec1.x * vec2.y) - (vec1.y * vec2.x);
}

// Static: Returns the distance between vec1 and vec2
float vec2f::distanceTo(const vec2f &vec1, const vec2f &vec2)
{
	float dx = vec2.x - vec1.x;
	float dy = vec2.y - vec1.y;
	return sqrtf(dx * dx + dy * dy);
}

// Static: Limits the magnitude of vec only if it exceeds maxLength
void vec2f::clampLength(vec2f &vec, float maxLength)
{
	float length = vec.getMagnitude();
	if (length != 0 && length > maxLength)
	{
		vec.setMagnitude(maxLength);
	}
	return;
}

// Static: Converts vec to a unit vector (length 1)
void vec2f::normalise(vec2f &vec)
{
	float length = vec2f::getMagnitude(vec);
	if (length != 0)
	{
		vec.x = vec.x / length;
		vec.y = vec.y / length;
	}
	return;
}

// Static: Returns conversion from Radians to Degrees
double vec2f::RadsToDegs(double radians)
{
	return radians*(180 / PI);
}


/// HELPER FUNCTIONS

// Prints the vector's properties to the console (Position, Magnitude and Direction)
void vec2f::display()
{
	std::cout << "Position (x, y)    : " << x << ", " << y << std::endl;
	std::cout << "Magnitude (length) : " << this->getMagnitude() << std::endl;
	std::cout << "Direction (Degrees): " << this->getDirectionDegrees() << std::endl;
	std::cout << "Direction (Radians): " << this->getDirectionRadians() << std::endl;
	std::cout << std::endl;
	return;
}
