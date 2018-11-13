#ifndef PROFILEPOINT_H
#define PROFILEPOINT_H


class ProfilePoint
{
public:
    ProfilePoint();
    ProfilePoint(double _x, double _y, double _z, unsigned char _intensity);
    double x;
    double y;
    double z;
    unsigned char intensity;
};

#endif // PROFILEPOINT_H
