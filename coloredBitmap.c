#include <string.h>
#include "config/coloredBitmap.h"
// Parameters:
//   w: width of the image
//   h: height of the image
//   u: Unit of the output value. It could be 'bt' bits, 'ko' kilobits, 'mo' megabits, 'go' gigabits
// Return value
//   colored image size Bitmap (based on the unit passed parametter)
float coloredBitmap(int w, int h, char* unit) {
float sizeInBits = w * h * 3 * 8;
    // Convert the size based on the unit provided
    if (strcmp(unit, "bt") == 0) {
        return sizeInBits; // Return the size in bits
    } else if (strcmp(unit, "ko") == 0) {
        return sizeInBits / 1024; // Convert to kilobits
    } else if (strcmp(unit, "mo") == 0) {
        return sizeInBits / (1024 * 1024); // Convert to megabits
    } else if (strcmp(unit, "go") == 0) {
        return sizeInBits / (1024 * 1024 * 1024); // Convert to gigabits
    } else {
        // Invalid unit, return an error value (-1)
        return -1; // Indicate an error with an invalid unit
    }
}
