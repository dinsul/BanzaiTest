#include "triangle.h"
#include <math.h>

#ifndef PI
#define PI 3.14159
#endif


Triangle::Triangle(QString name, double radiusOfCircumcircle, QPoint position, uint32_t color, double scaleChanged) :
    Figure(name, position, color),
    _scaleChanged(scaleChanged)
{
    setRadiusOfCircumcircle(radiusOfCircumcircle);
    _type = FtTriangle;
}

void Triangle::setRadiusOfCircumcircle(double radius)
{
    for (uint32_t i = 0; i < 3; ++i)
    {
        // currentAngle in radians. 2 * PI full circle
        // full circle devision on segments count and multiple on current segmetn
        double currentAngle = 2 * PI / 3 * i;
        double x = sin(currentAngle) * radius;
        double y = cos(currentAngle) * radius;

        _vertexes.append(QPoint((int)x, (int)y));
    }
}

void Triangle::draw()
{
    glPushMatrix();
    glTranslatef(_position.x(), _position.y(), 0);

    if (_changed)
    {
           glScalef(_scaleChanged, _scaleChanged, 1);
    }

    glLineWidth(_lineWidth);

    glBegin(GL_LINE_LOOP);

    glColor4b(_colorRed, _colorGreen, _colorBlue, _colorAlpha);

    for (auto vertex : _vertexes)
    {
        glVertex2i(vertex.x(), vertex.y());
    }

    glEnd();

    glPopMatrix();
}
