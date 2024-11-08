#include "Contrast.h"

void contrast(vector<vector<vector<int>>> &pixels, float amount) {    //amount should be between 0 and 100
        amount = amount - 50;
        float factor = (amount + 100.0f) / 100.0f;  //factor should be between 0 and 2
        for (int i = 0; i < pixels.size(); i++) {
            for (int j = 0; j < pixels[1].size(); j++) {

                pixels[i][j][0] = static_cast<int>((pixels[i][j][0] - 128) * factor + 128);
                pixels[i][j][1] = static_cast<int>((pixels[i][j][1] - 128) * factor + 128); 
                pixels[i][j][2] = static_cast<int>((pixels[i][j][2] - 128) * factor + 128);

                pixels[i][j][0] = min(255, max(0, pixels[i][j][0]));    //clamp the values to be between 0 and 255
                pixels[i][j][1] = min(255, max(0, pixels[i][j][1]));
                pixels[i][j][2] = min(255, max(0, pixels[i][j][3]));
            }
        }
    }