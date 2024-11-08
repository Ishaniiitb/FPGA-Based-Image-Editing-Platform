#include "WriteImage.h"

int WriteImage(vector<vector<vector<int>>> &pixels, int &width, int &height){
    ofstream outFile("Image.txt");
    if (!outFile) {
        cerr << "Error: Could not create the output file." << endl;
        return 1;
    }

    // Write the RGB values to the text file
    for (int i = 0; i < height; ++i) {
        for (int j = 0; j < width; ++j) {
            vector<int> pixel = pixels[i][j];
            outFile << "Pixel (" << i << ", " << j << "): ";
            outFile << "R=" << pixel[0] << " G=" << pixel[1] << " B=" << pixel[2] << endl;
        }
    }

    cout << "RGB values stored in Image.txt" << endl;
    outFile.close();
    return 0;
}