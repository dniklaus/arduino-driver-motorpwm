/*
 * MotorPWM.h
 *
 *  Created on: 14.10.2013
 *      Author: niklausd
 */

#ifndef MOTORPWM_H_
#define MOTORPWM_H_

/*
 *
 */
class MotorPWM
{
public:
  MotorPWM();
  virtual ~MotorPWM();

  /**
   * Define the speed the motor shall have (negative values: reverse operation).
   * @param speed, range: -255 (reverse) .. 0 (off) .. 255 (forward)
   */
  void setSpeed(int speed);

  /**
   * Get the current speed.
   * @return speed, 0: off/stopped, >0: forward, <0 reverse, max speed values: +/-255
   */
  int getSpeed();

protected:
  virtual void updateActors() = 0;

protected:
  int m_speed;
  bool m_isDirFwd;
};

#endif /* MOTORPWM_H_ */
