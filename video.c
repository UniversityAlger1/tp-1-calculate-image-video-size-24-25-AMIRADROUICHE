#include <string.h>
#include "config/video.h"
// Parameters:
//   w: width of the image
//   h: height of the image
//   durationMovie: duration in second of movie (colored image)
//   durationCredits: duration in second of credit (image Black/White)
//   unit: Unit of the output value. It could be 'bt' byte, 'ko' kilobits, 'mo' megabits, 'go' gigabits
// Return value
//   colored video size (based on the unit passed parametter)
float video(int w, int h, int durationMovie, int durationCredits, int fps, char* unit) {
      // Calculate size of the color section (in bits)
    float size_color_section = w * h * 3 * 8 * fps * durationMovie;

    // Calculate size of the black-and-white section (in bits)
    float size_bw_section = w * h * 8 * fps * durationCredits;

    // Total size in bits
    float total_size_bits = size_color_section + size_bw_section;

    // Convert the size based on the unit provided
    if (strcmp(unit, "bt") == 0) {
        return total_size_bits / 8; // Convert to bytes (divide by 8)  
    } else if (strcmp(unit, "ko") == 0) {
        return total_size_bits / 1024;  // Convert to kilobits
    } else if (strcmp(unit, "mo") == 0) {
        return total_size_bits / (1024 * 1024);  // Convert to megabits
    } else if (strcmp(unit, "go") == 0) {
        return total_size_bits / (1024 * 1024 * 1024);  // Convert to gigabits
    } else {
        // Invalid unit, return an error value (-1)
        return -1;  // Indicate an error with an invalid unit
    }
}
