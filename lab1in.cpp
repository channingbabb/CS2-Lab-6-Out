//Channing Babb
//Lab1In
//Draw a polyline

#include <iostream>
#include "graph1.h"

using namespace std;

//Add Function Prototypes Here
int getNoPoints();
void getPoints(int x[], int y[], int no_points);
void drawPolyLine(int x[], int y[], int no_points);

int main()
{
	//Variable Declaration/Initialization
	int no_points = 0;
	const int MAX_POINTS = 10;
	int x[MAX_POINTS];
	int y[MAX_POINTS];
	char repeat;
	
	do {
		//Display Graphics Window
		displayGraphics();

		//Prompt for the number of points
		no_points = getNoPoints();

		//Prompt for the data for the points
		getPoints(x, y, no_points);

		//Draw the polyline
		drawPolyLine(x, y, no_points);

		cout << endl;
		cout << "Would you like to repeat this program (Y or N)?";
		cin >> repeat;
		if (repeat == 'y' || repeat == 'Y') {
			clearGraphics();
			cout << endl;
		}
		
	} while (repeat == 'y' || repeat == 'Y');
}

//Function Stubs Follows
int getNoPoints()
{
	//Declare local variables
	int no_points = 0;

	//Prompt for the number of points
	cout << "Please enter number of points: ";
	cin >> no_points;

	//Return the number of points
	return no_points;
}

void getPoints(int x[], int y[], int no_points)
{
	//Declare local variables

	//Using a for-loop, prompt for the coordinates of each point and store in arrays x and y
	for (int i = 0; i < no_points; i++) {
		cout << "Enter x/y coord for Point #" << i+1 << ": ";
		cin >> x[i] >> y[i];
	}

}

void drawPolyLine(int x[], int y[], int no_points)
{
	//Declare local variables
	int circle;
	int line;

	//Use 1 for-loop for drawing the red circle on each point
	for (int i = 0; i < no_points; i++) {
		circle = drawCircle(5, x[i], y[i]);
		setColor(circle, 255, 0, 0);
		if (i != no_points-1) {
			line = drawLine(x[i], y[i], x[i + 1], y[i + 1], 1);
			setColor(line, 245, 242, 66);
		}
	}

}
