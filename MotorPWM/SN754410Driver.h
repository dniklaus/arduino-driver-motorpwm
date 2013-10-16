/*
 * SN754410Driver.h
 *
 *  Created on: 14.10.2013
 *      Author: niklausd
 */

#ifndef SN754410DRIVER_H_
#define SN754410DRIVER_H_

#include "MotorPWM.h"

/*
 *
 */
class SN754410_Driver: public MotorPWM
{
public:
  SN754410_Driver(int hBridgeEnPin = s_defaultHBridgeEnPin, int hBridgeLeg1Pin = s_defaultHBridgeLeg1Pin, int hBridgeLeg2Pin = s_defaultHBridgeLeg2Pin);
  virtual ~SN754410_Driver();

  virtual void updateActors();

private:
  int m_hBridgeEnPin;
  int m_hBridgeLeg1Pin;
  int m_hBridgeLeg2Pin;

  static const int s_defaultHBridgeEnPin;
  static const int s_defaultHBridgeLeg1Pin;
  static const int s_defaultHBridgeLeg2Pin;
};

#endif /* SN754410DRIVER_H_ */
