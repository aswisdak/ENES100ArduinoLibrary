#include "Enes100.h"

void setup() {
    //Allow Wifi Modules Time to Start Up
    delay(2000);
    // Initialize Enes100 library (Team Name, Mission Type, Marker ID, TX Pin, RX Pin)
    Enes100.begin("Duhbree", DEBRIS, 3, 8, 9);
    //Print out destination coordinates
    Enes100.print("Destination is at (");
    Enes100.print(Enes100.destination.x);
    Enes100.print(", ");
    Enes100.print(Enes100.destination.y);
    Enes100.println(")");
    // Transmit the material of the debris (Plastic or Copper)
    Enes100.mission(Plastic);
    // Transmit the mass of the debris in grams
    Enes100.mission(2.43);
    // Any other setup code...
}

void loop() {
    // Update the OSV's current location
    while(!Enes100.updateLocation()) {
        Enes100.println("404 Not Found");
    }
    //Once updateLocation() is successfull, print out location coordinates
    Enes100.print("OSV is at (");
    Enes100.print(Enes100.location.x);
    Enes100.print(", ");
    Enes100.print(Enes100.location.y);
    Enes100.print(", ");
    Enes100.print(Enes100.location.theta);
    Enes100.println(")");
}
