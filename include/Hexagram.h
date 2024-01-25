// Hexagram.h
#pragma once

#include "Triangle.h"
#include "Rectangle.h"

class Hexagram {
public:
    // Constructors
    //Hexagram(const Vertex vertices[6]); 
    Hexagram(const Triangle& firstTriangle, const Triangle& secondTriangle);


    // Member functions
    void draw(Board& board) const;
    Rectangle getBoundingRectangle() const;
    bool scale(double factor);
    double getPerimeter() const;
    double getArea() const;
    Vertex getCenter() const;
    double getTotalHeight() const;
    double getLength() const;


private:
    Triangle m_triangles[2]; // Two triangles forming the hexagram
};

