/**
 * @file point.hpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2024-06-24
 * 
 * @copyright Copyright (c) 2024
 * 
 */

#ifndef GEOMETRY_UTILITIES__POINT_HPP_
#define GEOMETRY_UTILITIES__POINT_HPP_

#include "geometry_utilities/quaternion.hpp"

struct Point
{
public:
  Point();

  Point(double x, double y, Quaternion orientation);

  Point(const Point &other);

  Point operator=(const Point &other);

  Point(Point &&other);

  Point &operator=(Point &&other);

  ~Point() = default;

  double m_x;
  double m_y;
  Quaternion m_Orientation;
};

#endif // GEOMETRY_UTILITIES__POINT_HPP_