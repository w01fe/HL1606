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
#define GreenOn     B00010000
#define GreenUp     B00100000
#define GreenDown   B00110000
#define BlueOff     B00000000
#define BlueOn      B00000001
#define BlueUp      B00000010
#define BlueDown    B00000011

class HL1606
{
  public:
    // Initialize with pin numbers and LED count.
    HL1606(unsigned int S, unsigned int D, unsigned int C, unsigned int L, unsigned int LEDCount);
  
    // Push a single command byte onto the strip.
    void sendByte(unsigned char it);
    
    // Latch current command values
    void latch();
    
    // Do one step of fade, as quickly as possible
    void fade();
    
    // Do y steps of fade, with d microseconds delay (>= 250) per edge.
    void fades(unsigned int y, unsigned int d);

    // Send n commands by cycling through 'buffer', starting at 'start' 
    void sendRing(unsigned char *buffer, int start, int len, int n);
    
    // Set all LEDs to a constant command
    void setAll(unsigned char command);

    // Set LED 'led' to 'command', and all others to 'background'
    void setOne(unsigned int led, unsigned char command, unsigned char background);
    
    // Set all LEDs by cycling through 'buffer', starting at 'start'
    void setRing(unsigned char *buffer, int start, int len);

    // Set all LEDs by cycling through 'buffer', starting at 'start'
    void setFadedRing(unsigned char *buffer, unsigned char *nFades, int start, int len);
         
  private:
    int _S, _D, _C, _L;
    unsigned int _LEDCount, _ClockWait;
};

#endif
