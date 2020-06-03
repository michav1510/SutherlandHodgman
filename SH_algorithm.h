#pragma once
#include <iostream>
#include <vector>

	struct Point2d
	{
		float x_, y_;
		Point2d():x_(0.0),y_(0.0){}
		Point2d(float x,float y):x_(x),y_(y){}
	};

	bool inside(Point2d& current_point, Point2d& clip_edge_point1, Point2d& clip_edge_point2);	
	void printPolygon(std::vector<Point2d>& );
	Point2d intersection(Point2d& , Point2d&, Point2d&, Point2d&);
	std::vector<Point2d> SutherlandHodgman(std::vector<Point2d>& subjectPolygon, std::vector<Point2d>& clipPolygon);
