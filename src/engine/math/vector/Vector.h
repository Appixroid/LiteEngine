#ifndef __VECTOR_H__
#define __VECTOR_H__

#include <string>
#include <iostream>
#include <SDL/SDL.h>

class Vector
{
	public:
		Vector();
		Vector(const Vector& other);
		Vector(double radians);
		Vector(double x, double y);
		
		void set(const Vector& other);
		void set(double x, double y);
		Vector& operator=(const Vector& other);
		
		void setX(double x);
		double getX() const;
		
		void setY(double y);
		double getY() const;
		
		void add(const Vector& other);
		Vector& operator+(const Vector& other);
		
		void rem(const Vector& other);
		Vector& operator%(const Vector& other);
		
		void sub(const Vector& other);
		Vector& operator-(const Vector& other);
		
		void mult(const Vector& other);
		Vector& operator*(const Vector& other);
		
		void mult(double factor);
		Vector& operator*(double factor);
		
		void div(const Vector& other);
		Vector& operator/(const Vector& other);
		
		void div(double divider);
		Vector& operator/(double divider);
		
		void cross(const Vector& other);
		
		void normalize();
		void limit(double maxMagnitude);
		
		void setMagnitude(double mag);
		double getMagnitude() const;
		double getSquaredMagnitude() const;
		
		void rotate(double radians);
		void setAngle(double radians);
		double getAngle() const;
		
		double dot(const Vector& other) const;
		double distanceTo(const Vector& other) const;
		double angleBetween(const Vector& other) const;		
	
		bool equals(const Vector& other) const;
		bool operator==(const Vector& other) const;
		
		std::string toString() const;
		std::ostream& operator<<(std::ostream& stream) const;
		
		SDL_Rect toSDL() const;
		
		static Vector add(const Vector& left, const Vector& right);
		static Vector rem(const Vector& left, const Vector& right);
		static Vector sub(const Vector& left, const Vector& right);
		static Vector mult(const Vector& left, const Vector& right);
		static Vector mult(const Vector& left, double factor);
		static Vector div(const Vector& left, const Vector& right);
		static Vector div(const Vector& left, double divider);
		static Vector cross(const Vector& left, const Vector& right);
	
		static Vector unitFrom(const Vector& vector);
		
		static Vector getRandom();
		static Vector getNull();
			
	private:
		double x;
		double y;
};

#endif
