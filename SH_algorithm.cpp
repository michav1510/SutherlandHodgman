#include "SH_algorithm.h"
#include <iostream>


void printPolygon(std::vector<Point2d>& polygon){
	for(int i =0; i < polygon.size(); i++)
		std::cout << "( " << polygon[i].x_ << " , " << polygon[i].y_ << " )" <<"\n"; 
	
		std::cout << "\n";
}


bool inside(Point2d& point, Point2d& clip_edge_point1, Point2d& clip_edge_point2)
{
    return (clip_edge_point2.y_ - clip_edge_point1.y_) * point.x_ + (clip_edge_point1.x_ - clip_edge_point2.x_) * point.y_ + (clip_edge_point2.x_ * clip_edge_point1.y_ - clip_edge_point1.x_ * clip_edge_point2.y_) < 0;
}


Point2d intersection(Point2d& edge_point1, Point2d& edge_point2, Point2d& prev_point, Point2d& current_point)
{
    Point2d dc = { edge_point1.x_ - edge_point2.x_, edge_point1.y_ - edge_point2.y_ };
    Point2d dp = { prev_point.x_ - current_point.x_, prev_point.y_ - current_point.y_ };
 
    float n1 = edge_point1.x_ * edge_point2.y_ - edge_point1.y_ * edge_point2.x_;
    float n2 = prev_point.x_ * current_point.y_ - prev_point.y_ * current_point.x_;
    float n3 = 1.0 / (dc.x_ * dp.y_ - dc.y_ * dp.x_);
 
    return { (n1 * dp.x_ - n2 * dc.x_) * n3, (n1 * dp.y_ - n2 * dc.y_) * n3 };
}


/*
* The below code implements the SutherlandHodgman algorithm. It's the exact implementation of 
* the pseudocode of wikipedia link : https://en.wikipedia.org/wiki/Sutherland%E2%80%93Hodgman_algorithm
*
*/
std::vector<Point2d> SutherlandHodgman(std::vector<Point2d>& subjectPolygon, std::vector<Point2d>& clipPolygon)
{
		std::vector<Point2d> outputList(subjectPolygon);
		for(int edge =0; edge< clipPolygon.size();edge++){
			Point2d edge_1_point = clipPolygon[edge];
			Point2d edge_2_point = clipPolygon[(edge+1)%clipPolygon.size()];
			std::vector<Point2d> inputList(outputList);
			outputList.clear();
			
			for(int i =0; i<inputList.size();i++){
				Point2d current_point = inputList[i];
				Point2d prev_point = inputList[(i+inputList.size()-1)%inputList.size()];
				
				//Point2d intersecting_point = intersection()
				
				//intersection(Point2d cp1, Point2d cp2, Point2d s, Point2d e)
				if(inside(current_point,edge_1_point,edge_2_point)){
					if(!inside(prev_point,edge_1_point,edge_2_point)){
						outputList.push_back(intersection(edge_1_point, edge_2_point, prev_point, current_point));
					}
					outputList.push_back(current_point);
				}else if(inside(prev_point,edge_1_point, edge_2_point)){
					outputList.push_back(intersection(edge_1_point, edge_2_point, prev_point, current_point));
				}
				
			}
		}
		return outputList;
		
}
	
	