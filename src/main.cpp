#include <iostream>
#include <sstream>
#include <fstream>
#include <numeric>

#include "common.h"
#include "Vec3.h"
#include "Colour.h"


int main() {

    // Constants
    // const int image_height = 3; // ??? PPM
    // const int image_height = 144; // 402KB PPM
    // const int image_height = 360; // 2.5MB PPM
    const int image_height = 720; // 9.8MB PPM
    // const int image_height = 1080; // 23MB PPM
    // const int image_height = 2160; // 89MB PPM
    // const int image_height = 4320; // 353MB PPM
    // const int image_height = 8640; // 1.4GB PPM
    // const int image_height = 17280; // 5.6GB PPM
    // const int image_width = 3;
    const int image_width = (int)( image_height * 16 / 9 );
    const int pixel_count = image_width * image_height;
    const std::string output_path = "images/out.ppm";
    
    std::cout << "INFO: Resolution:\t" << image_width << " by " << image_height << "\n";
    std::cout << "INFO: Pixel count:\t" << pixel_count << "\n";


    // Vars
    std::stringstream output_ppm;
    output_ppm << "P3\n" << image_width << " " << image_height << "\n255\n";


    // "Render loop" (Nested)
    for (int row = image_height-1; row >= 0; --row) { // (height --> 0)
        std::cout << "\rINFO: Rows remaining:\t" << row << std::flush;

        for (int col = 0; col < image_width; ++col) { // (0 --> width)
            Colour pixel_colour(
                float(col) / (image_width-1), // Red increases left to right (height --> 0)
                float(row) / (image_height-1), // Green increases top to bottom (0 --> width)
                0.25 // Blue is constant
            );
            pixel_colour.write_colour(output_ppm);
        }
        output_ppm << "\n";

    }
    std::cout << "\n";


    // Save PPM
    std::cout << "INFO: Saving PPM file:\t'" << output_path << "'\n";

    std::ofstream output_file_handler(output_path);
    output_file_handler << output_ppm.str();
    
    return 0;
}
