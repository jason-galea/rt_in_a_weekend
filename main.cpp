#include <iostream>
#include <sstream>
#include <fstream>


// Map float in range (0 --> 1) to int in range (0 --> 255)
int map_float_to_rgb_int(float rgb_val) {
    return (int)(255.999 * rgb_val);
}

int main() {

    // Constants
    // const int image_height = 144; // 402KB PPM
    // const int image_height = 360; // 2.5MB PPM
    // const int image_height = 480; // 4.4MB PPM
    // const int image_height = 720; // 9.8MB PPM
    // const int image_height = 1080; // 23MB
    const int image_height = 2160; // 89MB
    const int image_width = (int)( image_height * 16 / 9 );
    const std::string output_path = "images/out.ppm";
    
    std::cout << "INFO: Image resolution is " << image_width << " by " << image_height << "\n";


    // Vars
    std::stringstream output_ppm;
    output_ppm << "P3\n" << image_width << " " << image_height << "\n255\n";


    // Main logic
    for (int j = image_height-1; j >= 0; --j) { // Loop (height-1 --> 0)
        std::cout << "\rINFO: Rows remaining: " << j << std::flush;
        for (int i = 0; i < image_width; ++i) { // Loop (0 --> width)

            // TODO: Comment these operations
            auto r = double(i) / (image_width-1);
            auto g = double(j) / (image_height-1);
            auto b = 0.25;

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
