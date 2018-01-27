# Color Strip Driver (for PowerUp)
This is run on an Arduino connected to some Adafruit DotStars.

## Color Reference
These are the color codes to be sent by the RoboRio to the Arduino to change light color.

### Code `0`
This will completely **turn off** the lights.

### Code `1`
This will activate the AZE pattern. This will mean disabled.

### Code `2`
This will scroll bright orange. This will mean enabled but inactive.

### Code `3`
This will flash yellow on the elevator shaft and scroll yellow on sides. This will mean autonomous has found a cube.

### Code `4`
This will scroll yellow and green. This means we have a cube.

### Code `5`
This will scroll yellow and orange. This means we are raising a cube.

### Code `6`
This will blink between yellow and red. This means a cube is being released.

### Code `7`
This will scroll purple and orange reverse. This means we are lowering the elevator.
