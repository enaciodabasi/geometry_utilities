/**
 * @file point.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2024-06-24
 * 
 * @copyright Copyright (c) 2024
 * 
 */

#include "geometry_utilities/point.hpp"
#include <utility>

Point::Point()
    : m_x(0.0), m_y(0.0), m_Orientation(Quaternion())
{
}

Point::Point(double x, double y, Quaternion orientation)
    : m_x(x), m_y(y), m_Orientation(orientation)
{
}

Point::Point(const Point &other)
{
  m_x = other.m_x;
  m_y = other.m_y;
  m_Orientation = other.m_Orientation;
}

Point Point::operator=(const Point &other)
{
  this->m_x = other.m_x;
  this->m_y = other.m_y;
  this->m_Orientation = other.m_Orientation;

  return *this;
}

Point::Point(Point &&other)
{
  m_x = std::move(other.m_x);
  m_y = std::move(other.m_y);
  m_Orientation = other.m_Orientation;
}

Point &Point::operator=(Point &&other)
{
  this->m_x = std::move(other.m_x);
  this->m_y = std::move(other.m_y);
  this->m_Orientation = other.m_Orientation;
  return *this;
}