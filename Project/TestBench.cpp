// Group - 3
// Names : 
//      1) Aryan Mishra (IMT2022)
//      2) R Harshavardhan (IMT2022)
//      3) Ishan Jha (IMT2022562)

#include "ReadBMP.h"
#include "WriteBMP.h"
#include "WriteImage.h"
#include "Flip.h"
#include "Brighten.h"
#include "Contrast.h"
#include "Grayscale.h"
#include "Invert.h"
#include "Sepia.h"

// To execute this program just follow the below steps in terminal : 

// Step 1:
// Enter "g++ -o Application TestBench.cpp ReadBMP.cpp WriteBMP.cpp WriteImage.cpp Flip.cpp Brighten.cpp Contrast.cpp Grayscale.cpp Invert.cpp Sepia.cpp" into the terminal in the same folder where this C++ code is present.

// Step 2:
// Enter ".\Application" into the terminal in the same folder where this C++ code is present to execute the program.

using namespace std;

int height, width;

int main() {
    int i, j;
    string filename = "Image2.bmp";     // Selecting the ".bmp" image which we want to edit. Right now I have put 4 .bmp images into the ZIP folder so you can use any of those 4 images.

    vector<vector<vector<int>>> pixels = ReadBMP(filename, width, height);

    // Uncomment/Comment any of the following comments to demonstrate that particular filter : 
    // Flip(pixelData,1,0);
    // Brighten(pixelData, 50);
    // Contrast(pixelData, 50);
    // Grayscale(pixels);
    // Invert(pixelData);
    // Sepia(pixelData);

    WriteBMP("Result.bmp", pixels, width, height);
    
    return 0;
}
