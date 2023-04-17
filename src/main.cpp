#include <iostream>
#include <sstream>
#include <fstream>
#include <numeric>

// #include "common.h"
#include "Vec3.h"
#include "Colour.h"
#include "Ray.h"


int main() {

    // Image
    // const float ASPECT_RATIO = 16 / 9; // == 1. WHAT THE FUCK?????
    const float ASPECT_RATIO = 16.0 / 9.0; // == 1.77778
    // // const int IMG_HEIGHT = 3;
    // // const int IMG_WIDTH = 3;
    // const int IMG_HEIGHT = 5;
    // const int IMG_WIDTH = 5;
    // const int IMG_HEIGHT = 144; // 402KB PPM
    const int IMG_HEIGHT = 360; // 2.5MB PPM
    // const int IMG_HEIGHT = 720; // 9.8MB PPM
    // const int IMG_HEIGHT = 1080; // 23MB PPM
    // const int IMG_HEIGHT = 2160; // 89MB PPM
    const int IMG_WIDTH = (int)( IMG_HEIGHT * ASPECT_RATIO );
    
    // std::cout << "INFO: ASPECT_RATIO:\t" << ASPECT_RATIO << "\n";
    std::cout << "INFO: Resolution:\t" << IMG_WIDTH << " by " << IMG_HEIGHT << "\n";


    // Camera
    const int VIEWPORT_HEIGHT = 2; // x
    const float VIEWPORT_WIDTH = VIEWPORT_HEIGHT * ASPECT_RATIO; // y
    const int FOCAL_LENGTH = 1; // z

    const Point3 ORIGIN_P = Point3(0, 0, 0);
    // NOTE: These are for static measurements only, they're NOT placed relative to the viewport
    const Vec3 HORIZONTAL_V = Vec3(VIEWPORT_WIDTH, 0, 0); // x distance vector
    const Vec3 VERTICAL_V = Vec3(0, VIEWPORT_HEIGHT, 0); // y distance vector
    // const Vec3 NORMAL_V = Vec3(0, 0, FOCAL_LENGTH); // z distance vector (Not very useful)

    // NOTE: The (starting corner of the) viewport is towards -z, not +z
    auto lower_left_corner = ORIGIN_P - (HORIZONTAL_V/2) - (VERTICAL_V/2) - Vec3(0, 0, FOCAL_LENGTH);


    // "Render loop"
    std::stringstream output_ppm;
    output_ppm << "P3\n" << IMG_WIDTH << " " << IMG_HEIGHT << "\n255\n";

    for (int row = IMG_HEIGHT-1; row >= 0; --row) { // (height --> 0)
        std::cout << "\rINFO: Rows remaining:\t" << row << std::flush;

        for (int col = 0; col < IMG_WIDTH; ++col) { // (0 --> width)
            // TEMPORARY
            // Colour pixel_colour(
            //     float(col) / (IMG_WIDTH-1), // Red increases left to right (height --> 0)
            //     float(row) / (IMG_HEIGHT-1), // Green increases top to bottom (0 --> width)
            //     0.25 // Blue is constant
            // );

            auto u = float(row) / (IMG_WIDTH - 1); // x
            auto v = float(col) / (IMG_HEIGHT - 1); // y
            Ray r = Ray(ORIGIN_P, lower_left_corner + (u*HORIZONTAL_V) + (v*VERTICAL_V) - ORIGIN_P);

            Colour pixel_colour = ray_colour(r);

            write_colour(output_ppm, pixel_colour);
            // std::cout << "\rINFO: row:" << row << ", col:" << col << ", u:" << u << ", v:" << v << "\n";

        }
        // output_ppm << "\n"; // NOTE: Not required, just looks nicer with tabs in "write_colour"

    }
    std::cout << "\n";


    // Save PPM
    const std::string output_path = "images/out.ppm";
    std::cout << "INFO: Saving PPM file:\t'" << output_path << "'\n";

    std::ofstream output_file_handler(output_path);
    output_file_handler << output_ppm.str();
    
    return 0;
}
