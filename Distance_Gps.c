#include "Distance_Gps.h"
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>
#define R 6371000
#define PI 3.1415926536
#define TO_RAD (3.1415926536 / 180)
long double dist(long double th1,long double ph1,long double th2,long double ph2)
{
    double dx, dy, dz;
    ph1 -= ph2;
    ph1 *= TO_RAD, th1 *= TO_RAD, th2 *= TO_RAD;

    dz = sin(th1) - sin(th2);
    dx = cos(ph1) * cos(th1) - cos(th2);
    dy = sin(ph1) * cos(th1);
    return asin(sqrt(dx * dx + dy * dy + dz * dz) / 2) * 2 * R;
}