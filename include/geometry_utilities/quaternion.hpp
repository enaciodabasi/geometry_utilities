/**
 * @file quaternion.hpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2024-06-24
 * 
 * @copyright Copyright (c) 2024
 * 
 */

#ifndef GEOMETRY_UTILITIES__QUATERNION_HPP_
#define GEOMETRY_UTILITIES__QUATERNION_HPP_

#include "geometry_utilities/rpy.hpp"

struct Quaternion
{
public:
  Quaternion();

  Quaternion(double x, double y, double z, double w);

  ~Quaternion() = default;

  Quaternion(const Quaternion &other);

  Quaternion operator=(const Quaternion &other);

  Quaternion(Quaternion &&other);

  Quaternion &operator=(Quaternion &&other);

  double m_x;
  double m_y;
  double m_z;
  double m_w;

  static Quaternion fromRPY(const RPY &rpy);
  RPY toRPY() const;
};

#endif // GEOMETRY_UTILITIES__QUATERNION_HPP_