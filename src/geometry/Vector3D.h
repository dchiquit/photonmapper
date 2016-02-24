/*
 * Vector.h
 *
 *  Created on: Feb 5, 2016
 *      Author: Andrew
 */

#ifndef VECTOR3D_H_
#define VECTOR3D_H_

#include<ostream>

namespace graphics {
class Vector3D {
public:
	Vector3D(const Vector3D &start, const Vector3D &end);
	Vector3D(const double x, const double y, const double z);
	Vector3D(const Vector3D &vector);
	virtual ~Vector3D();

	const double x, y, z;

	Vector3D normalized() const;
	double magnitude() const;

	Vector3D cross(const Vector3D& v) const;
	double dot(const Vector3D& v) const;

	Vector3D operator+(const Vector3D &rhs) const;
	Vector3D operator-(const Vector3D &rhs) const;

	Vector3D operator-() const;

	Vector3D operator/(const long rhs) const;
	Vector3D operator/(const double rhs) const;

	Vector3D operator*(const long rhs) const;
	Vector3D operator*(const double rhs) const;

	Vector3D operator+(const long rhs) const;
	Vector3D operator+(const double rhs) const;

	Vector3D operator-(const long rhs) const;
	Vector3D operator-(const double rhs) const;

private:
	friend std::ostream& operator<<(std::ostream& outs, const Vector3D& vector);

	friend Vector3D operator*(const long lhs, const Vector3D& rhs);
	friend Vector3D operator*(const double lhs, const Vector3D& rhs);
};

} /* namespace graphics */

#endif /* VECTOR3D_H_ */
