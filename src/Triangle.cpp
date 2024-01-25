#include "Triangle.h"
#include <iostream>
#include <cmath>
#include "Utilities.h"

// Default constructor
Triangle::Triangle() {
    // Set default vertices for an equilateral triangle
    const double sideLength = 1.0; 
    const double height = sideLength * 0.86602540378; // (sqrt(3) / 2)

    m_vertices[0] = Vertex(0.0, 0.0);
    m_vertices[1] = Vertex(sideLength, 0.0);
    m_vertices[2] = Vertex(sideLength / 2.0, height);
}
Triangle::Triangle(const Vertex vertices[3]) {
    // Initialize vertices
    for (int i = 0; i < 3; ++i) {
        m_vertices[i] = vertices[i];
    }

    // Check if the vertices form a valid triangle
    if (!m_vertices[0].isValid() || !m_vertices[1].isValid() || !m_vertices[2].isValid()) {
        std::cerr << "Invalid triangle vertices\n";
        // Handle the error as needed
    }
}

void Triangle::draw(Board& board) const {
    // Draw the three sides of the triangle on the board
    for (int i = 0; i < 3; ++i) {
        const Vertex& v1 = m_vertices[i];
        const Vertex& v2 = m_vertices[(i + 1) % 3];
        board.drawLine(v1, v2);
    }
}

Rectangle Triangle::getBoundingRectangle() const {
    // Find the bounding rectangle of the triangle
    Vertex bottomLeft = m_vertices[0];  // Initialize with the first vertex
    Vertex topRight = m_vertices[0];

    // Update bottomLeft and topRight based on other vertices
    for (int i = 1; i < 3; ++i) {
        bottomLeft.m_col = std::min(bottomLeft.m_col, m_vertices[i].m_col);
        bottomLeft.m_row = std::min(bottomLeft.m_row, m_vertices[i].m_row);

        topRight.m_col = std::max(topRight.m_col, m_vertices[i].m_col);
        topRight.m_row = std::max(topRight.m_row, m_vertices[i].m_row);
    }

    // Create an array of two Vertex objects
    const Vertex vertices[2] = { bottomLeft, topRight };

    // Pass the array to the Rectangle constructor
    return Rectangle(vertices);
}

bool Triangle::scale(double factor) {
    // Scaling a triangle involves scaling its vertices
    for (int i = 0; i < 3; ++i) {
        m_vertices[i].m_col *= factor;
        m_vertices[i].m_row *= factor;
    }

    // Check if the new vertices are valid
    if (!m_vertices[0].isValid() || !m_vertices[1].isValid() || !m_vertices[2].isValid()) {
        std::cerr << "Invalid scaling resulted in out-of-bounds vertices\n";
        // Handle the error as needed
        return false;
    }

    return true;
}

double Triangle::getPerimeter() const {
    // Perimeter of a triangle is the sum of the lengths of its three sides
    double perimeter = 0.0;
    for (int i = 0; i < 3; ++i) {
        perimeter += distance(m_vertices[i], m_vertices[(i + 1) % 3]);
    }
    return perimeter;
}

double Triangle::getArea() const {
    // Area of a triangle using Heron's formula
    double a = distance(m_vertices[0], m_vertices[1]);
    double b = distance(m_vertices[1], m_vertices[2]);
    double c = distance(m_vertices[2], m_vertices[0]);
    double s = (a + b + c) / 2.0; // Semi-perimeter
    return std::sqrt(s * (s - a) * (s - b) * (s - c));
}

Vertex Triangle::getCenter() const {
    // Center of a triangle is the centroid
    double centerX = (m_vertices[0].m_col + m_vertices[1].m_col + m_vertices[2].m_col) / 3.0;
    double centerY = (m_vertices[0].m_row + m_vertices[1].m_row + m_vertices[2].m_row) / 3.0;
    return Vertex(centerX, centerY);
}

double Triangle::getLength() const {
    // Length of each side of the triangle
    double length1 = distance(m_vertices[0], m_vertices[1]);
    double length2 = distance(m_vertices[1], m_vertices[2]);
    double length3 = distance(m_vertices[2], m_vertices[0]);

    // Return the average length (you can customize this based on your needs)
    return (length1 + length2 + length3) / 3.0;
}

double Triangle::getTotalHeight() const {
    // Implement the calculation for the total height of the triangle
    // (You need to define this function based on your requirements)
    return 0.0;  // Replace with the actual calculation
}
