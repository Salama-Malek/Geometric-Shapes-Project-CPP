// Hexagram.cpp
#include "Hexagram.h"
#include <iostream>

Hexagram::Hexagram(const Triangle& firstTriangle, const Triangle& secondTriangle) {
    m_triangles[0] = firstTriangle;
    m_triangles[1] = secondTriangle;

    // Check if the triangles are valid
    if (!m_triangles[0].getVertex(0).isValid() || !m_triangles[1].getVertex(0).isValid()) {
        std::cerr << "Invalid hexagram triangles\n";
        // Handle the error as needed
    }
}


void Hexagram::draw(Board& board) const {
    // Draw the two triangles that form the hexagram on the board
    m_triangles[0].draw(board);
    m_triangles[1].draw(board);
}

Rectangle Hexagram::getBoundingRectangle() const {
    // Find the bounding rectangle of the hexagram
    Rectangle boundingRect1 = m_triangles[0].getBoundingRectangle();
    Rectangle boundingRect2 = m_triangles[1].getBoundingRectangle();

    double minX = std::min(boundingRect1.getBottomLeft().m_col, boundingRect2.getBottomLeft().m_col);
    double minY = std::min(boundingRect1.getBottomLeft().m_row, boundingRect2.getBottomLeft().m_row);
    double maxX = std::max(boundingRect1.getTopRight().m_col, boundingRect2.getTopRight().m_col);
    double maxY = std::max(boundingRect1.getTopRight().m_row, boundingRect2.getTopRight().m_row);

    // Create an array of two Vertex objects
    const Vertex vertices[2] = { Vertex(minX, minY), Vertex(maxX, maxY) };

    // Pass the array to the Rectangle constructor
    return Rectangle(vertices);
}

bool Hexagram::scale(double factor) {
    // Scaling a hexagram involves scaling its triangles
    if (!m_triangles[0].scale(factor) || !m_triangles[1].scale(factor)) {
        std::cerr << "Invalid scaling resulted in out-of-bounds vertices\n";
        // Handle the error as needed
        return false;
    }

    return true;
}

double Hexagram::getPerimeter() const {
    // Perimeter of a hexagram is the sum of the perimeters of its two triangles
    return m_triangles[0].getPerimeter() + m_triangles[1].getPerimeter();
}

double Hexagram::getArea() const {
    // Area of a hexagram is the sum of the areas of its two triangles
    return m_triangles[0].getArea() + m_triangles[1].getArea();
}

Vertex Hexagram::getCenter() const {
    // Center of a hexagram is the midpoint between the centers of its two bounding rectangles
    Rectangle boundingRect1 = m_triangles[0].getBoundingRectangle();
    Rectangle boundingRect2 = m_triangles[1].getBoundingRectangle();

    Vertex center1 = boundingRect1.getCenter();
    Vertex center2 = boundingRect2.getCenter();

    double centerX = (center1.m_col + center2.m_col) / 2.0;
    double centerY = (center1.m_row + center2.m_row) / 2.0;

    return Vertex(centerX, centerY);
}

double Hexagram::getTotalHeight() const {
    // Total height of the hexagram is the sum of the heights of its two bounding rectangles
    Rectangle boundingRect1 = m_triangles[0].getBoundingRectangle();
    Rectangle boundingRect2 = m_triangles[1].getBoundingRectangle();

    double height1 = boundingRect1.getTopRight().m_row - boundingRect1.getBottomLeft().m_row;
    double height2 = boundingRect2.getTopRight().m_row - boundingRect2.getBottomLeft().m_row;

    return height1 + height2;
}
// Implement getLength function
double Hexagram::getLength() const {
    // Compute the total length of the hexagram as the sum of the lengths of its triangles
    return m_triangles[0].getLength() + m_triangles[1].getLength();
}

