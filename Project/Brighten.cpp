#include "Brighten.h"

void Brighten(vector<vector<vector<int>>> &pixels, int amount) { //amount should be between 0 and 100
    for (int i = 0; i < pixels.size(); i++) 
    {
        for (int j = 0; j < pixels[1].size(); j++) 
        {
            if(amount>=50)  //If amount is greater than 50, then we need to brighten the pixel
            { 
                pixels[i][j][0] = pixels[i][j][0] + (int)(((255-pixels[i][j][0])/50)*(amount-50));
                pixels[i][j][1] = pixels[i][j][1] + (int)(((255-pixels[i][j][1])/50)*(amount-50));
                pixels[i][j][2] = pixels[i][j][2] + (int)(((255-pixels[i][j][2])/50)*(amount-50));
            }
            else            //If amount is less than 50, then we need to darken the pixel
            {
                pixels[i][j][0] = pixels[i][j][0] + (int)(((pixels[i][j][0])/50)*(amount-50));
                pixels[i][j][1] = pixels[i][j][1] + (int)(((pixels[i][j][1])/50)*(amount-50));
                pixels[i][j][2] = pixels[i][j][2] + (int)(((pixels[i][j][2])/50)*(amount-50));
            }
        }
    }
}