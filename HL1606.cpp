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

#include "WProgram.h"
#include "HL1606.h"

HL1606::HL1606(unsigned int S, unsigned int D, unsigned int C, unsigned int L, unsigned int LEDCount)
{
  _S = S;
  _D = D;
  _L = L;
  _C = C;
  _LEDCount = LEDCount;
  
  //This is the required delay between sending a bit and the clock line being fired.
  //You can tweak this value lower until you find LEDs on the end of your chain misbehaving
  //In fact, if you are running less than a few hundred LEDs you can get away with zero here.
  //250nSec per LED is the specified value for the chip.
  _ClockWait = (LEDCount * 250)/1000;   

  pinMode(_S, OUTPUT);
  pinMode(_D, OUTPUT);
  pinMode(_C, OUTPUT);
  pinMode(_L, OUTPUT);
  
  digitalWrite(_S, LOW);
  digitalWrite(_D, LOW);
  digitalWrite(_L, LOW);
  digitalWrite(_C, LOW);
}


void HL1606::sendByte(unsigned char it)
{
  //Send out one byte, don't forget to LATCH it by calling
  //Note that for LARGE number of LEDs you may need to slow things down a little here.  
  digitalWrite(_C, LOW);

  char x;
     for(x=0;x < 8; x++)
    { 
    if(B10000000 & it)
      digitalWrite(_D, HIGH); 
    else
      digitalWrite(_D, LOW); 
    it = it<<1;
    // Wait here needs to be 250 x Number of LEDs nano seconds to allow data to propagate before being clocked in
    delayMicroseconds(_ClockWait);
    digitalWrite(_C, HIGH);
    digitalWrite(_C, LOW);

    }
}

void HL1606::latch()
{
  digitalWrite(_L, HIGH);
  delayMicroseconds(1);  
  digitalWrite(_L, LOW);
}

void HL1606::fade()
{
  unsigned int fadeDelay = 1000;

  digitalWrite(_S, HIGH);
  delayMicroseconds(fadeDelay);
  digitalWrite(_S, LOW);
  delayMicroseconds(fadeDelay);
}

void HL1606::fades(unsigned int y, unsigned int d)
{
  //Pulse the fader y times with delay d microseconds between each pulse
  int x;
  for(x=0;x<y;x++)
  {
    digitalWrite(_S, HIGH);
    delayMicroseconds(d);
    digitalWrite(_S, LOW);
    delayMicroseconds(d);
  }
}


