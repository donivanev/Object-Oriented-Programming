#include <iostream>
using namespace std;

class Point
{
    double x;
    double y;

    public:
    Point ()
    {
        x = 0;
        y = 0;
    }

    void init (const double x, const double y)
    {
        x = this.x;
        y = this.y;
    }
};

class Line
{
    Point p1;
    Point p2;

    public:
    Line(const Point & p1, const Point & p2 ) : p1(p1), p2(p2) {}

    void setPoints(const Point & ap1, const Point & ap2)
    {
        p1 = ap1;
        p2 = ap2;
    }

    bool isParralel(Point firstPoint, Point secondPoint)
    {
        double slope1 = (p1.y - p1.x) / (firstPoint.y - firstPoint.x);
        double slope2 = (p2.y - p2.x) / (secondPoint.y - secondPoint.x);

        if (slope1 == slope2)
        {
            return true;
        }
        return false;

    }

    bool isFromTheLine(double m, double c, Point point)
    {
        if (point.y == ((m * point.x) + c)) 
        {
            return true;
        }
  
        return false;
    }

    bool onSegment(Point p, Point q, Point r) 
    { 
        if (q.x <= max(p.x, r.x) && q.x >= min(p.x, r.x) && 
            q.y <= max(p.y, r.y) && q.y >= min(p.y, r.y)) 
            return true; 
  
            return false; 
    } 

    int orientation(Point p, Point q, Point r) 
    { 
        int val = (q.y - p.y) * (r.x - q.x) - (q.x - p.x) * (r.y - q.y); 
  
        if (val == 0) return 0;   
  
        return (val > 0)? 1: 2; 
    }

    bool intersection(Point p1, Point q1, Point p2, Point q2) 
    { 
        int o1 = orientation(p1, q1, p2); 
        int o2 = orientation(p1, q1, q2); 
        int o3 = orientation(p2, q2, p1); 
        int o4 = orientation(p2, q2, q1); 
  
    
        if (o1 != o2 && o3 != o4) return true; 
  
        if (o1 == 0 && onSegment(p1, p2, q1)) return true; 
  
        if (o2 == 0 && onSegment(p1, q2, q1)) return true; 
   
        if (o3 == 0 && onSegment(p2, p1, q2)) return true; 
  
        if (o4 == 0 && onSegment(p2, q1, q2)) return true; 
  
        return false; 
    }  

    void createLine()
    {

    }
};

int main()
{
    Point p1;
    Point p2;

    Line l1;
    Line l2;

    return 0;
}