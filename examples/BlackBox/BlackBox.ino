#include "Enes100.h"

void setup() {
    //Allow Wifi Modules Time to Start Up
    delay(2000);
    // Initialize Enes100 library
    // Team Name, Mission Type, Marker ID, TX Pin, RX Pin
    Enes100.begin("Black Box Team", BLACK_BOX, 3, 8, 9);

    // Transmit the color of the LED
    Enes100.mission("Green");
    // Any other setup code...
}

void loop() {
    // Update the OSV's current location
    while(!Enes100.updateLocation()) {
        Enes100.println("404 Not Found");
    }
    Enes100.print("OSV is at (");
    Enes100.print(Enes100.location.x);
    Enes100.print(", ");
    Enes100.print(Enes100.location.y);
    Enes100.print(", ");
    Enes100.print(Enes100.location.theta);
    Enes100.println(")");

}
