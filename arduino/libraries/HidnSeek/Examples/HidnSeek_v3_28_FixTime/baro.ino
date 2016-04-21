/*  This file is part of HidnSeek.

  HidnSeek is free software: you can redistribute it and/or modify
  it under the terms of the GNU General Public License as published by
  the Free Software Foundation, either version 3 of the License, or
  (at your option) any later version.

  HidnSeek is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
  GNU General Public License for more details.

  You should have received a copy of the GNU General Public License
  along with HidnSeek.  If not, see <http://www.gnu.org/licenses/>.*/

#define ALTITUDE 252.0 // Altitude of HidnSeek's HQ in Grenoble in meters

bool bmp180Measure(float *Temp, unsigned int *Press)
{
  if (Temp) *Temp = bmp180.bmp085GetTemperature(bmp180.bmp085ReadUT()) - 3.6;
  if (Press) {
    *Press = (unsigned int) (bmp180.bmp085GetPressure(bmp180.bmp085ReadUP()) / 100);
    airPlanePress = *Press < 280 ? true : false; // changed it to remove airplane mode
  }
  return true;
}

void bmp180Print()
{
  serialString(PSTR("temp: "));
  Serial.print(Temp, 2);
  Serial.println("'C");
  serialString(PSTR("abs press: "));
  Serial.print(Press);
  Serial.println("mb");
}
