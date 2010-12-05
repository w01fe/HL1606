Introduction
------------

This is an Arduino library for controlling addressable RGB LED strips using the HL1606 chipset.  For now it supports the basic commands to push commands, latch, and pulse the strip, as well as a few higher-level utilities to fill the strip from a ring buffer.

Hardware
--------

I purchased my LEDs from [Microcontrollers and More][mc], and hooked them up to an Arduino Uno.  These [Instructions][inst] show how to hook the strip up to the Arduino.  You can power a small number of LEDs using the 5V output from the Arduino, but for more you need a separate 5V [power supply][ps] (connect the negative on the power supply to the ground on the Arduino).  The strips are described in some more detail [here][detail], and other Arduino libraries [exist][lib2].

[mc]: http://microcontrollersandmore.com/LEDs-amp-RGB-LED-Strips/RGB-LED-Strips-c13/
[inst]: http://what2day.posterous.com/hl1606-digital-manual-control Shows how to hook up to arduino
[ps]: http://cgi.ebay.com/ws/eBayISAPI.dll?ViewItem&item=170402230790
[detail]: http://bliptronics.com/support/ledstripspec.aspx
[lib2]: http://code.google.com/p/ledstrip/





