#pragma once

#include "Vertex.h"
#include "Board.h"
#include "Rectangle.h"

class Triangle {
public:
    Triangle(const Vertex vertices[3]);
    Triangle(); // Add the default constructor

    // Member functions
    void draw(Board& board) const;
    Rectangle getBoundingRectangle() const;
    bool scale(double factor);
    double getPerimeter() const;
    double getArea() const;
    Vertex getCenter() const;
    // Implement other necessary member functions
    double getLength() const; 
    double getTotalHeight() const;

    // Accessors
    const Vertex& getVertex(int index) const { return m_vertices[index]; }

private:
    Vertex m_vertices[3];
};
