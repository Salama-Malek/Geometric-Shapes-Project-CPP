// Window.cpp
#include "Window.h"
#include <iostream>

Window::Window(const Rectangle& outer, const Rectangle& inner)
    : m_outer(outer), m_inner(inner) {}

void Window::draw(Board& board) const {
    // Draw the outer and inner rectangles on the board
    m_outer.draw(board);
    m_inner.draw(board);
}

Rectangle Window::getBoundingRectangle() const {
    // The bounding rectangle is the same as the outer rectangle
    return m_outer;
}

bool Window::scale(double factor) {
    // Scaling a window involves scaling both the outer and inner rectangles
    if (!m_outer.scale(factor) || !m_inner.scale(factor)) {
        std::cerr << "Invalid scaling resulted in out-of-bounds vertices\n";
        // Handle the error as needed
        return false;
    }

    return true;
}

double Window::getPerimeter() const {
    // Perimeter of a window is the sum of the perimeters of the outer and inner rectangles
    return m_outer.getPerimeter() + m_inner.getPerimeter();
}

double Window::getArea() const {
    // Area of a window is the difference between the areas of the outer and inner rectangles
    return m_outer.getArea() - m_inner.getArea();
}

Vertex Window::getCenter() const {
    // Center of a window is the midpoint between the centers of the outer and inner rectangles
    Vertex centerOuter = m_outer.getCenter();
    Vertex centerInner = m_inner.getCenter();

    double centerX = (centerOuter.m_col + centerInner.m_col) / 2.0;
    double centerY = (centerOuter.m_row + centerInner.m_row) / 2.0;

    return Vertex(centerX, centerY);
}
