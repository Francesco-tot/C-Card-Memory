#include <iostream>
#include <vector>

int seeStates(std::vector<std::vector<int>> matrix, int fil, int col){
    int counter = 0;
    for(int i = 0; i<  fil; i++){
        for (int j = 0; j < col; j++)
        {
            if(matrix[i][j] == 1){
                counter++;
            }
        }
    }
    int cells = fil * col;
    if(counter == cells){
        return true;
    }
    return false;
}

void flipCard(std::vector<std::vector<int>>& matrix,int selectfil, int selectcol){
    if(selectfil > matrix.size() | selectcol > matrix[0].size()){
        std::cout<<"Fill or Column Invalid";
        return;
    }
    matrix[selectfil][selectcol] = 1;
}

void successCard(std::vector<std::vector<int>>& matrixI,std::vector<std::vector<std::string>> matrix, int fil1, int col1, int fil2, int col2){
    if(matrix[fil1][col1] != matrix[fil2][col2]){
        matrixI[fil1][col1] = 0;
        matrixI[fil2][col2] = 0;
    }
}   

std::vector<int> calcPositionUserWants(int number,int rows, int columns){
    int counter = 0;
    for(int i = 0; i < rows; i++){
        for(int j = 0; j < columns; j++){
            counter++;
            if(counter == number){
                std::vector<int> list = {i,j};
                return list;
            }
        }
    }
}
