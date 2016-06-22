/*
 * MotorPWM.cpp
 *
 *  Created on: 14.10.2013
 *      Author: niklausd
 */

#include "MotorPWM.h"

MotorPWM::MotorPWM()
: m_speed(0)
, m_isDirFwd(true)
{ }

MotorPWM::~MotorPWM()
{ }

void MotorPWM::setSpeed(int speed)
{
  if (speed > 255)
  {
    m_speed = 255;
  }
  else if (speed < -255)
  {
    m_speed = -255;
  }

  m_isDirFwd = (speed >= 0) ? true : false;
  m_speed = speed * (m_isDirFwd ? 1 : -1);

  updateActors();
}

int MotorPWM::getSpeed()
{
  return (m_speed * (m_isDirFwd ? 1 : -1));
}
