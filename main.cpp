#include <iostream>

int main() {

    const int image_height = 144;
    const int image_width = static_cast< int >( image_height * 16 / 9 );

    std::cout << "P3\n" << image_width << " " << image_height << "\n255\n";
    
    



}
