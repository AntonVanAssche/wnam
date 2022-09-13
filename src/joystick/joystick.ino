// Import the library to read the buttonstate from the joystick.
#include <ezButton.h>

// Define the input pins.
#define VRX_PIN  A0      // Arduino pin connected to VRX pin
#define VRY_PIN  A1      // Arduino pin connected to VRY pin
#define SW_PIN   2       // Arduino pin connected to SW pin

ezButton button(SW_PIN); // Create a button object for the joystick button.

int x = 0;              // Variable to store the value coming from the VRX
int y = 0;              // Variable to store the value coming from the VRY
int buttonState = 0;    // Variable to store the value coming from the button

void setup() {
   // Start the Serial communication to send messages to the computer
   Serial.begin(9600);

   // Set the button debounce time to 50ms.
   button.setDebounceTime(50);
}

void loop() {
   // Call the `loop()` function of the button object.
   button.loop();

   // Read the analog value coming from the VRX
   x = analogRead(VRX_PIN);

   // Read the analog value coming from the VRY
   y = analogRead(VRY_PIN);

   // Read the button state from the joystick button.
   if (button.isPressed()) {
      // If the button is pressed, print `1` to the Serial Monitor.
      Serial.print("1,");
   } else {
      // If the button is not pressed, print `0` to the Serial Monitor.
      Serial.print("0,");
   }

   // The rest state of the VRX is 500 (center) so we subtract 500 to get the actual value.
   Serial.print(x - 500);

   Serial.print(",");

   // The rest state of the VRY is 511 (center) so we subtract 511 to get the actual value.
   Serial.println(y - 511);

   // Add a small delay to improve simulation performance.
   delay(180);
}
