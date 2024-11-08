#include "Sepia.h"

void Sepia(vector<vector<vector<int>>> &pixels){
    for(int i = 0; i < pixels.size(); i++){
        for(int j = 0; j < pixels[1].size(); j++){
            //Y=0.299⋅R+0.587⋅G+0.114⋅B
            pixels[i][j][0] = (int) (min(0.393*pixels[i][j][0] + 0.769*pixels[i][j][1] + 0.189*pixels[i][j][2], 255.0));    //calculate the sepia value
            pixels[i][j][1] = (int) (min(0.349*pixels[i][j][0] + 0.686*pixels[i][j][1] + 0.168*pixels[i][j][2], 255.0));
            pixels[i][j][2] = (int) (min(0.272*pixels[i][j][0] + 0.534*pixels[i][j][1] + 0.131*pixels[i][j][2], 255.0));
        }
    }
}