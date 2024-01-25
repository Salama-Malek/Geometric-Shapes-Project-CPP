// Rectangle.h
#pragma once

#include "Vertex.h"
#include "Board.h"

class Rectangle {
public:
    // Constructors
    Rectangle(const Vertex vertices[2]);

    // Member functions
    void draw(Board& board) const;
    Rectangle getBoundingRectangle() const;
    bool scale(double factor);
    double getPerimeter() const;
    double getArea() const;
    Vertex getCenter() const;

    // Accessors
    const Vertex& getBottomLeft() const { return m_bottomLeft; }
    const Vertex& getTopRight() const { return m_topRight; }

private:
    Vertex m_bottomLeft; // Bottom-left vertex of the rectangle
    Vertex m_topRight;   // Top-right vertex of the rectangle
};
