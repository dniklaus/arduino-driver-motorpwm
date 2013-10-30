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
class SN754410_Driver : public MotorPWM
{
public:
  SN754410_Driver(int hBridgeEnPin, int hBridgeLeg1Pin, int hBridgeLeg2Pin);
  virtual ~SN754410_Driver();

  virtual void updateActors();

private:
  int m_hBridgeEnPin;     // PWM speed pin
  int m_hBridgeLeg1Pin;
  int m_hBridgeLeg2Pin;

private: // forbidden default functions
  SN754410_Driver& operator = (const SN754410_Driver& );  // assignment operator
  SN754410_Driver(const SN754410_Driver& src);            // copy constructor
};

#endif /* SN754410DRIVER_H_ */
