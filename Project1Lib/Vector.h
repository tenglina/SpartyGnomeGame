/**
 * @file Vector.h
 *
 * @author Charles Owen
 *
 * Simple 2D vector class
 */

#ifndef _VECTOR_H
#define _VECTOR_H

/**
 * Simple 2D vector class
 *
 * This class implements vector operations and operator overloading
 * to simplify the use of 2d vectors in a C++ program.
 */
class Vector{
public:
	Vector(double x, double y);
	Vector();

    /**
     * Destructor
     */
	virtual ~Vector() = default;

	Vector operator*(double d) const;

	Vector & operator+=(const Vector & a);

	Vector & operator*=(double d);

	Vector & operator/=(double d);

    /**
     * Assignment operator.
     * @param a Value to assign to this object
     * @return (*this)
     */
	Vector& operator=(const Vector& a) = default;

	/// Get the X value
	/// @return X
	[[nodiscard]] auto X() const { return mX; }

	/// Get the Y value
	/// @return Y
	[[nodiscard]] auto Y() const { return mY; }

	/// Set the vector
	/// @param x X value
	/// @param y Y value
	void Set(double x, double y) { mX = x; mY = y; }

	/// Set the vector from another vector
	/// @param x Other vector
	void Set(const Vector &x) { mX = x.mX; mY = x.mY; }

	/// Set the X component of the vector
	/// @param x X value
	void SetX(double x) { mX = x; }

	/// Set the Y component of the vector
	/// @param y Y value
	void SetY(double y) { mY = y; }

	[[nodiscard]] double Length() const;

	[[nodiscard]] double Distance(const Vector & other) const;

	Vector & Normalize();

private:
	/// X component of vector
	double mX;

	/// Y component of vector
	double mY;
};

Vector operator+(const Vector & a, const Vector & b);
Vector operator-(const Vector & a, const Vector & b);
Vector operator/(const Vector & a, double d);

#endif // _VECTOR_H