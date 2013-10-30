/*
 * SN754410Driver.cpp
 *
 *  Created on: 14.10.2013
 *      Author: niklausd
 */
#include "Arduino.h"
#include "SN754410Driver.h"

SN754410_Driver::SN754410_Driver(int hBridgeEnPin, int hBridgeLeg1Pin, int hBridgeLeg2Pin)
: MotorPWM()
, m_hBridgeEnPin(hBridgeEnPin)
, m_hBridgeLeg1Pin(hBridgeLeg1Pin)
, m_hBridgeLeg2Pin(hBridgeLeg2Pin)
{
  pinMode(m_hBridgeEnPin,   OUTPUT);
  pinMode(m_hBridgeLeg1Pin, OUTPUT);
  pinMode(m_hBridgeLeg2Pin, OUTPUT);

  digitalWrite(m_hBridgeLeg1Pin,  m_isDirFwd);
  digitalWrite(m_hBridgeLeg2Pin, !m_isDirFwd);

  // output speed as PWM value
  analogWrite(m_hBridgeEnPin, m_speed);
}

SN754410_Driver::~SN754410_Driver()
{
  m_speed = 0;
  analogWrite(m_hBridgeEnPin, m_speed);

  pinMode(m_hBridgeEnPin,   INPUT);
  pinMode(m_hBridgeLeg1Pin, INPUT);
  pinMode(m_hBridgeLeg2Pin, INPUT);
}

void SN754410_Driver::updateActors()
{
  digitalWrite(m_hBridgeLeg1Pin,  m_isDirFwd);
  digitalWrite(m_hBridgeLeg2Pin, !m_isDirFwd);

  // output speed as PWM value
  analogWrite(m_hBridgeEnPin, m_speed);
}
