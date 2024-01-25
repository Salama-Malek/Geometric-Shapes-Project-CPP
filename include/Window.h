// Window.h
#pragma once

#include "Rectangle.h"

class Window {
public:
    // Constructors
    Window(const Rectangle& outer, const Rectangle& inner);

    // Member functions
    void draw(Board& board) const;
    Rectangle getBoundingRectangle() const;
    bool scale(double factor);
    double getPerimeter() const;
    double getArea() const;
    Vertex getCenter() const;

    // Accessors
    const Vertex& getBottomLeft() const { return m_outer.getBottomLeft(); }
    const Vertex& getTopRight() const { return m_outer.getTopRight(); }
    double getHorizontalThickness() const { return m_outer.getTopRight().m_row - m_inner.getBottomLeft().m_row; }
    double getVerticalThickness() const { return m_outer.getTopRight().m_col - m_inner.getBottomLeft().m_col; }

private:
    Rectangle m_outer; // Outer rectangle of the window
    Rectangle m_inner; // Inner rectangle of the window
};