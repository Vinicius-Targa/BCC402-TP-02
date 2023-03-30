// 849 - Radar Tracking

/*
A ground-to-air radar system uses an antenna that rotates in a horizontal plane
with a period of 2 seconds. Whenever the antenna faces an object, its distance
from that antenna is measured and displayed on a circular screen as a white dot.
The distance from the dot to the centre of the screen is proportional to the
horizontal distance from the antenna to the object, and the angle of the line
passing through the centre and the dot represents the direction of the object
from the antenna. A dot directly above the centre represents an object that is
north of the antenna; an object to the right of the centre represents an object
to the east, and so on. The antenna rotates clockwise; that is, if it points
north at time t = 0.0, it points east at t = 0.5, south at t = 1.0, west at t
= 1.5, north at t = 2, and so on. If the object is directly on top of the radar
antenna, it cannot be observed. There are a number of objects in the sky. Each
is moving at a constant velocity, and appears as a dot on the screen that
appears in a different position every time the antenna observes it. Your task is
to determine where the dot will appear on the screen the next time the antenna
observes it, given the previous two observations. If there are several
possibilities, you are to find them all.

*/

#include <iostream>

using namespace std;

int *radarTracking(int vet[], int n) {}

// entrada
int main() {
  int vet[4], *ans;

  for (int i = 0; i < 4; i++) {
    cin >> vet[i];
  }

  ans = radarTracking(vet, 4);
  return 0;
}