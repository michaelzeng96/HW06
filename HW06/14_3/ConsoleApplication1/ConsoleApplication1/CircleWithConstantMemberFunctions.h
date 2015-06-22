#ifndef CIRCLE_H
#define CIRCLE_H

class Circle
{
	Circle();
	Circle(double);
	double getArea() const;
	double getRadius() const;
	void setRadius(double);
	static int getNumberOfObjects();
	bool operator == (Circle&);
	bool operator !=  (Circle&);
	bool operator < (Circle&);
	bool operator <= (Circle&);
	bool operator > (Circle&);
	bool operator >= (Circle&);

private:
	double radius;
	static int numberOfObjects;
};

#endif