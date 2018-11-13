#include "Profilepoint.h"
//存储点和对应亮度数据

ProfilePoint::ProfilePoint()
{
    this->x = 0;
    this->y = 0;
    this->z = 0;

}

ProfilePoint::ProfilePoint(double _x, double _y, double _z, unsigned char _intensity)
{
    this->x = _x;
    this->y = _y;
    this->z = _z;
    this->intensity = _intensity;
}
