#include "ReadBMP.h"

vector<vector<vector<int>>> ReadBMP(const string& filename, int& width, int& height) {
    ifstream file(filename, ios::binary);

    if (!file) {
        cerr << "Error: Could not open the BMP file." << endl;
        exit(1);
    }

    uint8_t fileHeader[14];
    file.read(reinterpret_cast<char*>(fileHeader), 14);
    uint8_t infoHeader[40];
    file.read(reinterpret_cast<char*>(infoHeader), 40);

    width = *reinterpret_cast<int*>(&infoHeader[4]);
    height = *reinterpret_cast<int*>(&infoHeader[8]);
 
    // BMP stores rows in reverse order (bottom-to-top), so we need to handle that
    // Calculate the row size (each row must be padded to a multiple of 4 bytes)
    int rowSize = (3 * width + 3) & (~3);

    // Temporary buffer to store one row of pixel data
    vector<uint8_t> rowBuffer(rowSize);

    vector<vector<vector<int>>> pixelData;

    // Read the pixel data (BGR format) row by row. Starts from the bottom row
    for (int i = height - 1; i >= 0; --i)
    {
        vector<vector<int>> row;
        file.read(reinterpret_cast<char*>(rowBuffer.data()), rowSize);
        for (int j = 0; j < width; ++j) 
        {
            vector<int> pixel;

            int blue = rowBuffer[3 * j];
            int green = rowBuffer[3 * j + 1];
            int red = rowBuffer[3 * j + 2];

            pixel.push_back(red);
            pixel.push_back(green);
            pixel.push_back(blue);

            row.push_back(pixel);
        }
        pixelData.push_back(row);
    }
    file.close();

    for(int i = 0; i < height; i++)
    {
        for(int j = 0; j < 28; j++)
        {
            vector<int> pixel = pixelData[i].front();
            pixelData[i].erase(pixelData[i].begin());
            pixelData[i].push_back(pixel);
        }
    }
    return pixelData;
}