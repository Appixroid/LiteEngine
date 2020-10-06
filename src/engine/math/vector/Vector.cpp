#include "Vector.h"

#include <cmath>
#include <cstdlib>
#include <sstream>

Vector::Vector() : Vector(0, 0) {}

Vector::Vector(const Vector& other) : Vector(other.getX(), other.getY()) {}

Vector::Vector(double radians) : Vector(cos(radians), sin(radians)) {}

Vector::Vector(double x, double y)
{
	this->set(x, y);
}

void Vector::set(const Vector& other)
{
	this->set(other.getX(), other.getY());
}

void Vector::set(double x, double y)
{
	this->setX(x);
	this->setY(y);
}

Vector& Vector::operator=(const Vector& other)
{
	this->set(other);
	return *this;
}

void Vector::setX(double x)
{
	this->x = x;
}

double Vector::getX() const
{
	return this->x;
}

void Vector::setY(double y)
{
	this->y = y;
}

double Vector::getY() const
{
	return this->y;
}

void Vector::add(const Vector& other)
{
	this->setX(this->getX() + other.getX());
	this->setY(this ->getY() + other.getY());
}

Vector& Vector::operator+(const Vector& other)
{
	this->add(other);
	return *this;
}

void Vector::rem(const Vector& other)
{
	this->setX(fmod(this->getX(), other.getX()));
	this->setY(fmod(this->getY(), other.getY()));
}

Vector& Vector::operator%(const Vector& other)
{
	this->rem(other);
	return *this;
}

void Vector::sub(const Vector& other)
{
	this->setX(this->getX() - other.getX());
	this->setY(this->getY() - other.getY());
}

Vector& Vector::operator-(const Vector& other)
{
	this->sub(other);
	return *this;
}

void Vector::mult(const Vector& other)
{
	this->setX(this->getX() * other.getX());
	this->setY(this->getY() * other.getY());
}

Vector& Vector::operator*(const Vector& other)
{
	this->mult(other);
	return *this;
}

void Vector::mult(double factor)
{
	this->setX(this->getX() * factor);
	this->setY(this->getY() * factor);
}

Vector& Vector::operator*(double factor)
{
	this->mult(factor);
	return *this;
}

void Vector::div(const Vector& other)
{
	this->setX(this->getX() / other.getX());
	this->setY(this->getY() / other.getY());
}

Vector& Vector::operator/(const Vector& other)
{
	this->div(other);
	return *this;
}

void Vector::div(double divider)
{
	this->setX(this->getX() / divider);
	this->setY(this->getY() / divider);
}

Vector& Vector::operator/(double divider)
{
	this->div(divider);
	return *this;
}

void Vector::cross(const Vector& other)
{
	this->setX((this->getX() * other.getY()) - (this->getY() * other.getX()));
}

void Vector::normalize()
{
	double mag = this->getMagnitude();
	
	if(mag != 0)
	{
		this->div(mag);
	}
}

void Vector::limit(double maxMagnitude)
{
	if(this->getMagnitude() > maxMagnitude)
	{
		this->setMagnitude(maxMagnitude);
	}
}

void Vector::setMagnitude(double mag)
{
	this->normalize();
	this->mult(mag);
}

double Vector::getMagnitude() const
{
	return sqrt(this->getSquaredMagnitude());
}

double Vector::getSquaredMagnitude() const
{
	double xSq = pow(this->getX(), 2);
	double ySq = pow(this->getY(), 2);
	return xSq + ySq;
}

void Vector::rotate(double radians)
{
	this->setAngle(this->getAngle() + radians);
}

void Vector::setAngle(double radians)
{
	double mag = this->getMagnitude();
	
	this->setX(cos(radians));
	this->setY(sin(radians));
	
	this->mult(mag);
}

double Vector::getAngle() const
{
	return atan2(this->getX(), this->getY());
}

double Vector::dot(const Vector& other) const
{
	return (this->getX() * other.getX()) + (this->getY() * other.getY());
}

double Vector::distanceTo(const Vector& other) const
{
	double xSq = pow(other.getX() - this->getX(), 2);
	double ySq = pow(other.getY() - this->getY(), 2);
	return sqrt(xSq + ySq);
}

double Vector::angleBetween(const Vector& other) const
{
	return atan2(other.getY() - this->getY(), other.getX() - this->getX());
}	

bool Vector::equals(const Vector& other) const
{
	return this->getX() == other.getX() && this->getY() == other.getY();
}

bool Vector::operator==(const Vector& other) const
{
	return this->equals(other);
}

std::string Vector::toString() const
{
	std::ostringstream stringStream;
	stringStream << "(" << this->getX() << ", " << this->getY() << ")";
	return stringStream.str();
}

std::ostream& Vector::operator<<(std::ostream& stream) const
{
	return stream << this->toString();
}

SDL_Rect Vector::toSDL() const
{
	SDL_Rect rect;
	rect.x = this->getX();
	rect.y = this->getY();
	return rect;
}

Vector Vector::add(const Vector& left, const Vector& right)
{
	Vector v(left);
	v.add(right);
	return v;
}

Vector Vector::rem(const Vector& left, const Vector& right)
{
	Vector v(left);
	v.rem(right);
	return v;
}

Vector Vector::sub(const Vector& left, const Vector& right)
{
	Vector v(left);
	v.sub(right);
	return v;
}

Vector Vector::mult(const Vector& left, const Vector& right)
{
	Vector v(left);
	v.mult(right);
	return v;
}

Vector Vector::mult(const Vector& left, double factor)
{
	Vector v(left);
	v.mult(factor);
	return v;
}


Vector Vector::div(const Vector& left, const Vector& right)
{
	Vector v(left);
	v.div(right);
	return v;
}

Vector Vector::div(const Vector& left, double divider)
{
	Vector v(left);
	v.div(divider);
	return v;
}

Vector Vector::cross(const Vector& left, const Vector& right)
{
	Vector v(left);
	v.cross(right);
	return v;
}


Vector Vector::unitFrom(const Vector& vector)
{
	Vector v(vector);
	v.normalize();
	return v;
}

Vector Vector::getRandom()
{
	double TWO_PI = M_PI * 2;
	return Vector(((double)rand() / (double)RAND_MAX) * TWO_PI);
}

Vector Vector::getNull()
{
	return Vector(0, 0);
}
