/**
 * @file rpy.hpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2024-06-24
 * 
 * @copyright Copyright (c) 2024
 * 
 */

#ifndef GEOMETRY_UTILITIES__RPY_HPP_
#define GEOMETRY_UTILITIES__RPY_HPP_

#include "geometry_utilities/quaternion.hpp"

struct RPY
{
public:
  RPY();

  RPY(double roll, double pitch, double yaw);

  ~RPY() = default;

  RPY(const RPY &other);

  RPY operator=(const RPY &other);

  RPY(RPY &&other);

  RPY &operator=(RPY &&other);

  double m_roll;
  double m_pitch;
  double m_yaw;

  static RPY fromQuaternion(const Quaternion &quaternion);
  Quaternion toQuaternion() const;
};

#endif // GEOMETRY_UTILITIES__RPY_HPP_