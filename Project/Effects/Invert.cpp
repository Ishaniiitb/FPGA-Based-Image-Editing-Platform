#include "Invert.h"

void invert(vector<vector<vector<int>>> &pixels) { //amount should be between 0 and 100
    for (int i = 0; i < pixels.size(); i++) {
        for (int j = 0; j < pixels[1].size(); j++) {
            pixels[i][j][0] = 255-pixels[i][j][0];    //invert the pixel
            pixels[i][j][1] = 255-pixels[i][j][1];
            pixels[i][j][2] = 255-pixels[i][j][2];
        }
    }
}