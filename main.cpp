#include <iostream>
#include <sstream>
#include <fstream>

int main() {

    // Constants
    const int image_height = 144;
    const int image_width = static_cast< int >( image_height * 16 / 9 );
    const std::string output_path = "images/out.ppm";

    // Vars
    std::stringstream output_ppm;
    // output_ppm << "P3\n" << image_width << " " << image_height << "\n255\n";

    // EXAMPLE PPM
    output_ppm << "P3\n"; // Format
    output_ppm << "3 2\n"; // Resolution
    output_ppm << "255\n"; // Max colour
    output_ppm << "255  0   0       0   255 0       0   0   255\n"; // RGB values (row 1)
    output_ppm << "255  255 0       255 255 255     0   0   0\n"; // RGB values (row 2)


    // Save PPM    
    std::cout << "INFO: Saving PPM data to " << output_path << "\n";
    std::ofstream output_file_handler(output_path);
    output_file_handler << output_ppm.str();
    
    


    return 0;
}
