/*
 * SN754410Driver.cpp
 *
 *  Created on: 14.10.2013
 *      Author: niklausd
 */
#include "Arduino.h"
#include "SN754410Driver.h"


const int SN754410_Driver::s_defaultHBridgeEnPin   = 44;
const int SN754410_Driver::s_defaultHBridgeLeg1Pin = 46;
const int SN754410_Driver::s_defaultHBridgeLeg2Pin = 48;


SN754410_Driver::SN754410_Driver(int hBridgeEnPin, int hBridgeLeg1Pin, int hBridgeLeg2Pin)
: MotorPWM()
, m_hBridgeEnPin(hBridgeEnPin)
, m_hBridgeLeg1Pin(hBridgeLeg1Pin)
, m_hBridgeLeg2Pin(hBridgeLeg2Pin)
{
  pinMode(m_hBridgeEnPin,   OUTPUT); // PWM speed pin
  pinMode(m_hBridgeLeg1Pin, OUTPUT);
  pinMode(m_hBridgeLeg2Pin, OUTPUT);

  updateActors();
}

SN754410_Driver::~SN754410_Driver()
{ }

void SN754410_Driver::updateActors()
{
  digitalWrite(m_hBridgeLeg1Pin,  m_isDirFwd);
  digitalWrite(m_hBridgeLeg2Pin, !m_isDirFwd);

  // output speed as PWM value
  analogWrite(m_hBridgeEnPin, m_speed);
}
