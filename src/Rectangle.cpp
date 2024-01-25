// Rectangle.cpp
#include "Rectangle.h"
#include <iostream>

// Constructors
Rectangle::Rectangle(const Vertex vertices[2])
    : m_bottomLeft(vertices[0]), m_topRight(vertices[1]) {
    // Additional initialization if needed
}
void Rectangle::draw(Board& board) const {
    // Draw the rectangle on the board
    board.drawLine(m_bottomLeft, Vertex(m_topRight.m_col, m_bottomLeft.m_row));
    board.drawLine(Vertex(m_topRight.m_col, m_bottomLeft.m_row), m_topRight);
    board.drawLine(m_topRight, Vertex(m_bottomLeft.m_col, m_topRight.m_row));
    board.drawLine(Vertex(m_bottomLeft.m_col, m_topRight.m_row), m_bottomLeft);
}

Rectangle Rectangle::getBoundingRectangle() const {
    // The bounding rectangle of a rectangle is the rectangle itself
    return *this;
}

bool Rectangle::scale(double factor) {
    // Scaling a rectangle involves scaling its dimensions
    auto newBottomLeft = m_bottomLeft;
    auto newTopRight = m_topRight;

    newBottomLeft.m_col *= factor;
    newBottomLeft.m_row *= factor;
    newTopRight.m_col *= factor;
    newTopRight.m_row *= factor;

    // Check if the new vertices are valid
    if (!newBottomLeft.isValid() || !newTopRight.isValid()) {
        std::cerr << "Invalid scaling resulted in out-of-bounds vertices\n";
        return false;
    }

    // Update the vertices after scaling
    m_bottomLeft = newBottomLeft;
    m_topRight = newTopRight;
    return true;
}

double Rectangle::getPerimeter() const {
    // Perimeter of a rectangle is the sum of all four sides
    const double length = std::abs(m_topRight.m_col - m_bottomLeft.m_col);
    const double width = std::abs(m_topRight.m_row - m_bottomLeft.m_row);
    return 2 * (length + width);
}

double Rectangle::getArea() const {
    // Area of a rectangle is the product of its length and width
    const double length = std::abs(m_topRight.m_col - m_bottomLeft.m_col);
    const double width = std::abs(m_topRight.m_row - m_bottomLeft.m_row);
    return length * width;
}

Vertex Rectangle::getCenter() const {
    // Implement the getCenter function for Rectangle
    double centerX = (m_bottomLeft.m_col + m_topRight.m_col) / 2.0;
    double centerY = (m_bottomLeft.m_row + m_topRight.m_row) / 2.0;
    return Vertex(centerX, centerY);
}