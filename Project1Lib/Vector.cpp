/**
 * @file Vector.cpp
 *
 * @author Charles Owen
 */

#include "pch.h"
#include "Vector.h"

/**
 * Constructor
 *
 * The default constructor creates a zero vector.
 */
Vector::Vector() :mX(0), mY(0)
{

}

/**
 * Constructor
 *
 * This constructor allows you to specify an initial value
 *
 * @param x Initial x value
 * @param y Initial y value
 */
Vector::Vector(double x, double y) :mX(x), mY(y)
{

}


/**
 * Computer scalar multiply of vector * scalar
 * @param d Value to multiply by
 * @return (*this) * d
 */
Vector Vector::operator*(double d) const
{
	return {mX * d, mY * d};
}


/**
 * Operator +=
 *
 * Adds a vector to an existing vector.
 *
 * @code
 * Vector a(7, 3);
 * Vector b(3, 9);
 * a += b;		// a is now equal to (10, 12)
 * @endcode
 * @param a Value to add to current object
 * @return *this
 */
Vector &Vector::operator+=(const Vector &a)
{
	mX += a.mX;
	mY += a.mY;
	return *this;
}


/**
 * Operator *= for scalar values
 *
 * Multiplies a vector by a scalar value
 *
 * @code
 * Vector a(7, 3)
 * double d = 0.5;
 * a *= d;   // a is now (3.5, 1.5)
 * @endcode
 * @param d Scalar to multiply by this vector.
 * @return *this
 */
Vector &Vector::operator*=(double d)
{
	mX *= d;
	mY *= d;
	return *this;
}

/**
* Operator /=
*
* Divides a vector by a scalar value
*
* @code
Vector a(3, 7);
double d = 3;
a /= d;       // a is now (1, 2.3333)
* @endcode
* @param d Scalar to divide by
* @return *this
*/
Vector &Vector::operator/=(double d)
{
	mX /= d;
	mY /= d;
	return *this;
}


/**
* Compute the length of a vector assuming a Euclidean norm
*
* @code
Vector a(3, 7);
double len = a.Length();   // len = 7.6158
* @endcode
* @return Vector length
*/
double Vector::Length() const
{
	return sqrt(mX * mX + mY * mY);
}



/**
 * Compute distance from a vector to another vector
 *
 * @code
 Vector a(1, 2);
 Vector b(5, 3);
 double distance = a.Distance(b);  // distance = 4.1231
 * @endcode
 * @param other Other vector to test against
 * @return Distance between vectors
 */
double Vector::Distance(const Vector &other) const
{
	double dx = other.mX - mX;
	double dy = other.mY - mY;
	return sqrt(dx * dx + dy * dy);
}


/**
 * Operator + Compute the sum of two vectors
 *
 * @code
 Vector a(3, 7);
 Vector b(7, 9);
 Vector c = a + b;   // c is (10, 16)
 * @endcode
 * @param a First vector operand
 * @param b Second vector operand
 * @return a + b
 */
Vector operator+(const Vector &a, const Vector &b)
{
	return {a.X() + b.X(), a.Y() + b.Y()};
}


/**
* Operator - Compute the subtraction of two vectors
*
* @code
Vector a(3, 7);
Vector b(7, 9);
Vector c = a - b;   // c is (-2, -4)
* @endcode
* @param a First vector operand
* @param b Second vector operand
* @return a + b
*/
Vector operator-(const Vector &a, const Vector &b)
{
	return {a.X() - b.X(), a.Y() - b.Y()};
}


/**
 * Operator /
 *
 * Computes vector a / scalar d
 *
 * @code
 Vector a(3, 7);
 double d = 3;
 Vector b = a / d;	// b is (1, 2.3333)
 * @endcode
 * @param a Vector to divide
 * @param d Scalar to divide by
 * @return a / d
 */
Vector operator/(const Vector &a, double d)
{
	return {a.X() / d, a.Y() / d};
}

/**
 * Normalize this vector to a length of 1.
 *
 * @code
 Vector a(12.2, 1.7);
 a.Normalize();   // a is now (0.9904, 0.1380)
 * @endcode
 * @return *this
 */
Vector &Vector::Normalize()
{
	double l = Length();
	mX /= l;
	mY /= l;
	return *this;
}