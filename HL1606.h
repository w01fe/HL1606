/* Copyright 2010 Jason Wolfe. All rights reserved.
 * 
 * Redistribution and use in source and binary forms, with or without modification, are
 * permitted provided that the following conditions are met:
 * 
 *    1. Redistributions of source code must retain the above copyright notice, this list of
 *       conditions and the following disclaimer.
 * 
 *    2. Redistributions in binary form must reproduce the above copyright notice, this list
 *       of conditions and the following disclaimer in the documentation and/or other materials
 *       provided with the distribution.
 * 
 * THIS SOFTWARE IS PROVIDED BY JASON WOLFE ``AS IS'' AND ANY EXPRESS OR IMPLIED
 * WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND
 * FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL JASON WOLFE OR
 * CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
 * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
 * SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON
 * ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING
 * NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF
 * ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.

 * The views and conclusions contained in the software and documentation are those of the
 * authors and should not be interpreted as representing official policies, either expressed
 * or implied, of Jason Wolfe.
 *
 * Based on code provided by Microcontrollersandmore.com
 */


#ifndef HL1606_H
#define HL1606_H

#include "WProgram.h"

//Commands for each LED to be ORd together.
#define Noop        B00000000
#define Command     B10000000
#define Commandx2   B11000000   //Use this one to make dimming twice as fast.
#define RedOff      B00000000
#define RedOn       B00000100
#define RedUp       B00001000
#define RedDown     B00001100
#define GreenOff    B00000000
#define GreenOn     B00000001
#define GreenUp     B00000010
#define GreenDown   B00000011
#define BlueOff     B00000000   
#define BlueOn      B00010000
#define BlueUp      B00100000
#define BlueDown    B00110000

class HL1606
{
  public:
    HL1606(unsigned int S, unsigned int D, unsigned int C, unsigned int L, unsigned int LEDCount);
    void sendByte(unsigned char it);
    void latch();
    void fade();
    void fades(unsigned int y, unsigned int d);
         
  private:
    int _S, _D, _C, _L;
    unsigned int _LEDCount, _ClockWait;
};

#endif
