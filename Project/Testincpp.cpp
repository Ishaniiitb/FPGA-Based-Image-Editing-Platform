#include <iostream>
#include <fstream>
#include <vector>
#include <cstdint>  
#include <algorithm>
#include <bits/stdc++.h>
#include <cmath>

using namespace std;

void display(vector<vector<int>> twoD, int rows, int cols)
{
    cout << "Displaying." << endl;
    for(int i = 0; i < rows; i++)
    {
        for(int j = 0; j < cols; j++)
            cout << twoD[i][j] << " ";
        cout << endl;
    }
}

void testing(vector<vector<int>> twoD, int row, int col)
{
    int c = 1;
    for(int i = 0; i < row; i++)
    {
        for(int j = 0; j < col; j++)
            twoD[i][j] = c++;
    }
}

vector<vector<vector<int>>> readBMP(const string& filename, int& width, int& height) {
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
    return pixelData;
}

void writeBMP(const string& filename, vector<vector<vector<int>>> pixelData, int width, int height) {
    ofstream file(filename, ios::binary);

    if (!file) {
        cerr << "Error: Could not create the BMP file." << endl;
        exit(1);
    }

    // BMP Header (14 bytes)
    uint8_t fileHeader[14] = {
        'B', 'M',                          // Signature
        0, 0, 0, 0,                        // File size (will be set later)
        0, 0,                              // Reserved
        0, 0,                              // Reserved
        54, 0, 0, 0                        // Pixel data offset (54 bytes)
    };

    // BMP Info Header (40 bytes)
    uint8_t infoHeader[40] = {
        40, 0, 0, 0,                      // Header size
        0, 0, 0, 0,                       // Image width (will be set later)
        0, 0, 0, 0,                       // Image height (will be set later)
        1, 0,                             // Number of color planes (must be 1)
        24, 0,                            // Bits per pixel (24 for RGB)
        0, 0, 0, 0,                       // Compression (0 = no compression)
        0, 0, 0, 0,                       // Image size (can be 0 for no compression)
        0, 0, 0, 0,                       // Horizontal resolution (pixels per meter)
        0, 0, 0, 0,                       // Vertical resolution (pixels per meter)
        0, 0, 0, 0,                       // Number of colors (0 = default)
        0, 0, 0, 0                        // Important colors (0 = all colors are important)
    };

    *reinterpret_cast<int*>(&infoHeader[4]) = width;
    *reinterpret_cast<int*>(&infoHeader[8]) = height;

    // Calculate the row size (each row must be a multiple of 4 bytes)
    int rowSize = (3 * width + 3) & (~3);
    int imageSize = rowSize * height;

    *reinterpret_cast<int*>(&fileHeader[2]) = 54 + imageSize;

    file.write(reinterpret_cast<char*>(fileHeader), 14);
    file.write(reinterpret_cast<char*>(infoHeader), 40);

    vector<uint8_t> rowBuffer(rowSize);

    for(int i = 0; i < height; i++)
    {
        for(int j = 0; j < 28; j++)
        {
            vector<int> pixel = pixelData[i].front();
            pixelData[i].erase(pixelData[i].begin());
            pixelData[i].push_back(pixel);
        }
    }

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; ++j) {

            vector<int> pixel = pixelData[i][j];

            rowBuffer[3 * j] = static_cast<uint8_t>(pixel[2]);      //Blue
            rowBuffer[3 * j + 1] = static_cast<uint8_t>(pixel[1]);  //Green
            rowBuffer[3 * j + 2] = static_cast<uint8_t>(pixel[0]);  //Red
        }
        file.write(reinterpret_cast<char*>(rowBuffer.data()), rowSize);
    }

    file.close();
    cout << "BMP image created: " << filename << endl;
}

int main()
{
    cout << "Starting" << endl;
    int width, height;
    string filename = "Image2.bmp";

    // vector<vector<vector<int>>> pixelData = readBMP(filename, width, height);

    // writeBMP("plsgod.bmp", pixelData, width, height);



    vector<vector<int>> testingVector = {{0,0,0}, {0,0,0}, {0,0,0}};

    display(testingVector, 3, 3);

    testing(testingVector, 3, 3);

    display(testingVector, 3, 3);
    
    return 0;
}