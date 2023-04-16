#include <iostream>
#include <sstream>
#include <fstream>

#include "common.h"
#include "Vec3.h"


int main() {

    // Constants
    const int image_height = 144; // 402KB PPM
    // const int image_height = 360; // 2.5MB PPM
    // const int image_height = 480; // 4.4MB PPM
    // const int image_height = 720; // 9.8MB PPM
    // const int image_height = 1080; // 23MB PPM
    // const int image_height = 2160; // 89MB PPM
    const int image_width = (int)( image_height * 16 / 9 );
    const std::string output_path = "images/out.ppm";
    
    std::cout << "INFO: Image resolution is " << image_width << " by " << image_height << "\n";


    // Vars
    std::stringstream output_ppm;
    output_ppm << "P3\n" << image_width << " " << image_height << "\n255\n";


    // "Render loop"
    for (int row = image_height-1; row >= 0; --row) { // (height --> 0)
        std::cout << "\rINFO: Rows remaining: " << row << std::flush;

        for (int col = 0; col < image_width; ++col) {

            // TODO: Comment these operations
            float r = float(col) / (image_width-1); // Red increases left to right (0 --> 1)
            float g = float(row) / (image_height-1); // Green increases top to right (0 --> 1)
            float b = 0.6; // Blue is constant

            int ir = map_float_to_rgb_int(r);
            int ig = map_float_to_rgb_int(g);
            int ib = map_float_to_rgb_int(b);

            output_ppm << ir << "\t" << ig << "\t" << ib << "\t\t";
        }

        output_ppm << "\n";
    }
    std::cout << "\n";


    // Save PPM
    std::cout << "INFO: Saving PPM data to '" << output_path << "'\n";

    std::ofstream output_file_handler(output_path);
    output_file_handler << output_ppm.str();
    
    return 0;
}
