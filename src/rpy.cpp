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

#include "geometry_utilities/rpy.hpp"
#include <utility>
RPY::RPY()
    : m_roll(0.0), m_pitch(0.0), m_yaw(0.0)
{
}

RPY::RPY(double roll, double pitch, double yaw)
    : m_roll(roll), m_pitch(pitch), m_yaw(yaw)
{
}

RPY::RPY(const RPY &other)
{
  this->m_pitch = other.m_pitch;
  this->m_roll = other.m_roll;
  this->m_yaw = other.m_yaw;
}

RPY RPY::operator=(const RPY &other)
{
  this->m_pitch = other.m_pitch;
  this->m_roll = other.m_roll;
  this->m_yaw = other.m_yaw;
  return *this;
}

RPY::RPY(RPY &&other)
{
  this->m_pitch = std::move(other.m_pitch);
  this->m_roll = std::move(other.m_roll);
  this->m_yaw = std::move(other.m_yaw);
}

RPY &RPY::operator=(RPY &&other)
{
  this->m_pitch = std::move(other.m_pitch);
  this->m_roll = std::move(other.m_roll);
  this->m_yaw = std::move(other.m_yaw);

  return *this;
}

RPY RPY::fromQuaternion(const Quaternion &quaternion)
{
  return quaternion.toRPY();
}