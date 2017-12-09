# clock-nanoatmega328

Part of a project to build a alarm clock: This part shows the time on a 4 digit 7 segment display using an arduino nano.

## 4 Digit Display Pin Layout
* The display I'm using has 17 pins
* There are 2 common anodes: PIN 1 and PIN 2
* PIN 3 is dead
* PIN 4 - 17 display different segments depending on which anode is active

The following table shows which segments associations:

<table>
  <tr>
    <th></th>
    <th colspan="2">DIGIT 1</th>
    <th colspan="4">DIGIT 2</th>
    <th colspan="4">DIGIT 3</th>
    <th colspan="4">DIGIT 4</th>
  </tr>
  <tr>
    <th>Anode</th>
    <th>PIN 4</th>
    <th>PIN 5</th>
    <th>PIN 6</th>
    <th>PIN 7</th>
    <th>PIN 8</th>
    <th>PIN 9</th>
    <th>PIN 10</th>
    <th>PIN 11</th>
    <th>PIN 12</th>
    <th>PIN 13</th>
    <th>PIN 14</th>
    <th>PIN 15</th>
    <th>PIN 16</th>
    <th>PIN 17</th>
  </tr>
  <tr>
    <th>PIN 1</th>
    <td>a,g</td>
    <td>c</td>
    <td>e</td>
    <td>d</td>
    <td></td>
    <td>c</td>
    <td>dots</td>
    <td>e</td>
    <td>d</td>
    <td>c</td>
    <td>e</td>
    <td></td>
    <td>d</td>
    <td>c</td>
  </tr>
  <tr>
    <th>PIN 2</th>
    <td>e,d</td>
    <td>b</td>
    <td>f</td>
    <td>a</td>
    <td>g</td>
    <td>b</td>
    <td>g</td>
    <td>f</td>
    <td>a</td>
    <td>b</td>
    <td>f</td>
    <td>g</td>
    <td>a</td>
    <td>b</td>
  </tr>
</table>

## Implementation
* Anode 1 and 2 are switched back and forth
* For each switch, the required pins (segments) for each digit are switched on for a short time and then switched off, lighting up at most 1 digit
** This way, it's never drawing too much power from the output pins of the Arduino
** It's kind of a PWM and by changing the delays I can make the display darker or brighter
* Every half second, the dots are switched
* Every minute, the clock automatically "ticks"
* It's an I2C slave to an ESP8266 master node, which will update the clock based on some other time source

