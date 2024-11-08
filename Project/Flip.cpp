#include "Flip.h"

using namespace std;

void Flip(vector<vector<vector<int>>> &pixels, int flipHorizontal, int flipVertical) {   //flipHorizontal and flipVertical should be either 0 or 1
    if (flipHorizontal) {
        for (int i = 0; i < pixels.size(); i++) 
            reverse(pixels[i].begin(), pixels[i].end());    //reverse the pixels in each row
    }
    if (flipVertical) {
        reverse(pixels.begin(), pixels.end());  //reverse the rows
    }
}