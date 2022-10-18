//Channing Babb
//Lab 5 In
//draw a filled circle
#include <iostream>
#include "graph1.h"

using namespace std;

class FilledCircle
{
private:
	int x;
	int y;
	int radius;

public:
	FilledCircle();
	bool setX(int x_val);
	int getX();
	bool setY(int y_val);
	int getY();
	bool setRadius(int r_val);
	int getRadius();
	void draw();
};

FilledCircle::FilledCircle()
{
	//Set private data fields to default values
	x = 0;
	y = 0;
	radius = 15;
}


bool FilledCircle::setX(int x_val)
{

	//Implement rules for x_val when out of range   
	bool result = false;
	if (x_val >= 640) {
		x = 639;
		result = false;
	} else if (x_val < 0) {
		x = 0;
		result = false;
	} else {
		x = x_val;
		result = true;
	}
	return result;
}

int FilledCircle::getX()
{
	return x;
}

bool FilledCircle::setY(int y_val)
{
	//Implement rules for setting the y-coord
	bool result = false;
	if (y_val >= 480) {
		y = 479;
		result = false;
	}
	else if (y_val < 0) {
		y = 0;
		result = false;
	}
	else {
		y = y_val;
		result = true;
	}
	return result;
}

int FilledCircle::getY()
{
	return y;
}

bool FilledCircle::setRadius(int r_val)
{
	//Implement rule for setting the radius
	bool result = false;
	if (r_val <= 0) {
		radius = 1;
		result = false;
	} else if (r_val >= 30) {
		radius = 30;
		result = false;
	}
	else {
		radius = r_val;
		result = true;
	}
	return result;
}

int FilledCircle::getRadius()
{
	return radius;
}

void FilledCircle::draw()
{
	//Draw the filled circle
	int cir = drawCircle(this->getRadius() , this->getX(), this->getY());
	setColor(cir, 255, 255, 255);

	// "fill" the circle by looping the radius and creating circles within the circle
	for (int i = 0; i < this->getRadius(); i++) {
		int cir2 = drawCircle(this->getRadius()-i, this->getX(), this->getY());
		setColor(cir2, 255, 255, 255);
	}
}

int main()
{
	//Variable Declaration/Initialization
	int i = 0;
	int x = 0;
	int y = 0;
	int radius = 0;
	bool result = false;

	FilledCircle circle1;

	char repeat;

	//Display the Graphics
	displayGraphics();

	do
	{
		//Prompt for the x/y coordinates
		cout << "Enter x/y coords: ";
		cin >> x >> y;


		//Set the x coord for circle1 – display message if x is out of range
		result = circle1.setX(x);
		if (!result) {
			cout << "X entered is invalid, value has been set to default." << endl;
		}

		//Set the y coord for circle1 – display message if y is out of range
		result = circle1.setY(y);
		if (!result) {
			cout << "Y entered is invalid, value has been set to default." << endl;
		}

		//Prompt for the radius
		cout << "Enter radius: ";
		cin >> radius;


		//Set the radius for cirle1 – display message if radius is out of range
		result = circle1.setRadius(radius);
		if (!result) {
			cout << "Radius entered is invalid, value has been set to default." << endl;
		}


		//Draw the circle
		circle1.draw();

		//Display the coordinate info, radius info under the circle along with the 
		//coords
		gout << setColor(0, 255, 0) << setPos(circle1.getX() - circle1.getRadius(), circle1.getY() + 40) << "(" << circle1.getX() << "," << circle1.getY() << ")" << endg;
		//radius
		gout << setColor(0, 255, 0) << setPos(circle1.getX() - circle1.getRadius(), circle1.getY() + 50) << "Radius: " << circle1.getRadius() << endg;

		cout << "\nWould you like to repeat? (y/n): ";
		cin >> repeat;
		if (repeat == 'y' || repeat == 'Y') {
			clearGraphics();
		}

	} while (repeat == 'y' || repeat == 'Y');

	return 0;
}

