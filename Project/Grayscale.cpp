#include "Grayscale.h"

void Grayscale(vector<vector<vector<int>>> &pixels){
    for(int i = 0; i < pixels.size(); i++)
    {
        for(int j = 0; j < pixels[1].size(); j++)
        {
            //Y=0.299⋅R+0.587⋅G+0.114⋅B
            int gray = (int)min((int)(0.299*pixels[i][j][0] + 0.587*pixels[i][j][1] + 0.114*pixels[i][j][2]), 255); //calculate the grayscale value
            pixels[i][j][0] = gray;
            pixels[i][j][1] = gray;
            pixels[i][j][2] = gray;
        }
    }
}