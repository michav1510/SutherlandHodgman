#include "SH_algorithm.h"
#include <iostream>



int main(int argc, char** argv)
{
	std::vector<Point2d> subjectpolygonvertices;
	subjectpolygonvertices.push_back(Point2d(1,1));
	subjectpolygonvertices.push_back(Point2d(30,1));
	subjectpolygonvertices.push_back(Point2d(25,10));
	subjectpolygonvertices.push_back(Point2d(10,20));
	subjectpolygonvertices.push_back(Point2d(60,60));
	
	std::vector<Point2d> clippolygonvertices;
	clippolygonvertices.push_back(Point2d(0,0));
	clippolygonvertices.push_back(Point2d(10,0));
	clippolygonvertices.push_back(Point2d(50,50));
	clippolygonvertices.push_back(Point2d(0,50));
	
	
	std::vector<Point2d> resultopolygonvertices = SutherlandHodgman(subjectpolygonvertices, clippolygonvertices);
	
	
	std::cout << "subject polygon:\n";
	printPolygon(subjectpolygonvertices);
	std::cout << "clip polygon:\n";
	printPolygon(clippolygonvertices);
	std::cout << "result polygon:\n";
	printPolygon(resultopolygonvertices);
	return 0;
}



