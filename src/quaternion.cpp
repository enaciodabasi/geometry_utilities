/**
 * @file quaternion.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2024-06-24
 * 
 * @copyright Copyright (c) 2024
 * 
 */

#include "geometry_utilities/quaternion.hpp"
#include <cmath>
#include <utility>
Quaternion RPY::toQuaternion() const
{
  double cr = std::cos(this->m_roll * 0.5);
  double sr = std::sin(this->m_roll * 0.5);
  double cp = std::cos(this->m_pitch * 0.5);
  double sp = std::sin(this->m_pitch * 0.5);
  double cy = std::cos(this->m_yaw * 0.5);
  double sy = std::sin(this->m_yaw * 0.5);

  Quaternion quaternion;
  quaternion.m_w = cr * cp * cy + sr * sp * sy;
  quaternion.m_x = sr * cp * cy - cr * sp * sy;
  quaternion.m_y = cr * sp * cy + sr * cp * sy;
  quaternion.m_z = cr * cp * sy - sr * sp * cy;

  return quaternion;
}

Quaternion::Quaternion()
    : m_x(0.0), m_y(0.0), m_z(0.0), m_w(0.0)
{
}

Quaternion::Quaternion(double x, double y, double z, double w)
    : m_x(x), m_y(y), m_z(z), m_w(w)
{
}

Quaternion::Quaternion(const Quaternion &other)
{
  this->m_x = other.m_x;
  this->m_y = other.m_y;
  this->m_z = other.m_z;
  this->m_w = other.m_w;
}

Quaternion::Quaternion(Quaternion &&other)
{
  this->m_x = std::move(other.m_x);
  this->m_y = std::move(other.m_y);
  this->m_z = std::move(other.m_z);
  this->m_w = std::move(other.m_w);
}

Quaternion Quaternion::operator=(const Quaternion &other)
{
  this->m_x = other.m_x;
  this->m_y = other.m_y;
  this->m_z = other.m_z;
  this->m_w = other.m_w;
  return *this;
}

Quaternion &Quaternion::operator=(Quaternion &&other)
{
  this->m_x = std::move(other.m_x);
  this->m_y = std::move(other.m_y);
  this->m_z = std::move(other.m_z);
  this->m_w = std::move(other.m_w);
  return *this;
}

Quaternion Quaternion::fromRPY(const RPY &rpy)
{

  return rpy.toQuaternion();
}

RPY Quaternion::toRPY() const
{
  RPY rpy;

  double sinr_cosp = 2 * (this->m_w * this->m_x + this->m_y * this->m_z);
  double cosr_cosp = 1 - 2 * (this->m_x * this->m_x + this->m_y * this->m_y);
  rpy.m_roll = std::atan2(sinr_cosp, cosr_cosp);

  double sinp = std::sqrt(1 + 2 * (this->m_w * this->m_y - this->m_x * this->m_z));
  double cosp = std::sqrt(1 - 2 * (this->m_w * this->m_y - this->m_x * this->m_z));
  rpy.m_pitch = 2 * std::atan2(sinp, cosp) - M_PI / 2;

  double siny_cosp = 2 * (this->m_w * this->m_z + this->m_x * this->m_y);
  double cosy_cosp = 1 - 2 * (this->m_y * this->m_y + this->m_z * this->m_z);
  rpy.m_yaw = std::atan2(siny_cosp, cosy_cosp);

  return rpy;
}
