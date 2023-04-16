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
    const int image_height = 360; // ??? PPM
    // const int image_height = 480; // ??? PPM
    // const int image_height = 720; // ??? PPM
    // const int image_height = 1080; // 23MB
    // const int image_height = 2160; // 89MB
    const int image_width = (int)( image_height * 16 / 9 );
    std::cout << "INFO: Image resolution is " << image_width << " by " << image_height << "\n";

    const std::string output_path = "images/out.ppm";

    // Initialise output string
    std::stringstream output_ppm;
    output_ppm << "P3\n" << image_width << " " << image_height << "\n255\n";


    // Main logic
    for (int j = image_height-1; j >= 0; --j) {
        for (int i = 0; i < image_width; ++i) {

            // TODO: Comment these operations
            float r = double(i) / (image_width-1);
            float g = double(j) / (image_height-1);
            float b = 0.25;

            int ir = map_float_to_rgb_int(r);
            int ig = map_float_to_rgb_int(g);
            int ib = map_float_to_rgb_int(b);

            output_ppm << ir << "\t" << ig << "\t" << ib << "\t\t";
        }
        output_ppm << "\n";
    }


    // Save PPM
    std::cout << "INFO: Saving PPM data to '" << output_path << "'\n";
    std::ofstream output_file_handler(output_path);
    output_file_handler << output_ppm.str();
    
    return 0;
}
