/**
 * @file utils.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2024-06-24
 * 
 * @copyright Copyright (c) 2024
 * 
 */

#include "geometry_utilities/utils.hpp"

double distanceBetweenTwoPoints(const Point& p1, const Point& p2)
{
  return std::sqrt(
    std::pow(p2.m_x - p1.m_x, 2) + std::pow(p2.m_y - p1.m_y, 2)
  );
}