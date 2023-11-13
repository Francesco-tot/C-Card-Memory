#include <iostream>
#include <stdlib.h>
#include "controller.h"
#include <vector>
#include <time.h>

// Implementation of game 'cards memory' with memory allocation and not libraries help like vector

template <typename T> // This function print an anytype matriz in console
void printMatrix(std::vector<std::vector<T>> matrix, size_t row, size_t col) {
    std::cout<<"\n";
    for (size_t i = 0; i < row; i++) {
        for (size_t j = 0; j < col; j++) {
            std::cout<<matrix[i][j];
            std::cout<<" ";
        }
        std::cout << "\n";
    }
}

template <typename T> // This function take a matrix built by vector library and add for any position the default type of the matrix
void setMatrix(std::vector<std::vector<T>>& matrix, size_t inicio, size_t final){
    for(size_t i = inicio; i < final; i++){
        for(size_t j = 0; j < matrix[i].size(); j++){
            matrix[i][j] = T();
        }
    }
}

template <typename T> // This function take a list of vector library and add for any position the default type of the list
void PrintList(std::vector<T> list, size_t size){
        for(size_t i = 0; i < size; i++){
            std::cout<<""<<list[i]<<" ";
        }
}

void determinatePositionMatrix(std::vector<std::vector<std::string>>& matrix, int x, int y,std::string element){
    if(matrix[x-1][y-1] == ""){
        matrix[x-1][y-1] = element;
        return;
    }
    else{
        while(true){
            int x = 0 + rand()%matrix.size()+1;
            int y = 0 + rand()%matrix[0].size()+1;
            if(matrix[x-1][y-1] == ""){
                matrix[x-1][y-1] = element;
                break;
            }
        }
    }
}
// Distribute the images by random in the matrix
void RandomSortGraphicMatrix(std::vector<std::vector<std::string>>& matrix, std::vector<std::string> list){
    srand(time(NULL));
    std::vector<std::string> copylist = list;
    while(list.size()>0){
        // Get the image
        int listRandomPosition = rand()%list.size()+1;
        int copyListRandomPosition = rand()%copylist.size()+1;

        // Get the positions in the matrix for the two images

        int xMatrix1 = rand()%matrix.size()+1;
        int ymatrix1 = rand()%matrix[0].size()+1;

        int xMatrix2 = rand()%matrix.size()+1;
        int ymatrix2 = rand()%matrix[0].size()+1;

        determinatePositionMatrix(matrix,xMatrix1,ymatrix1,list[listRandomPosition-1]);
        determinatePositionMatrix(matrix,xMatrix2,ymatrix2,copylist[copyListRandomPosition-1]);

        list.erase(list.begin() + (listRandomPosition-1));
        copylist.erase(copylist.begin() + (copyListRandomPosition-1));
        
    }
}



void game(std::vector<std::vector<std::string>>& matrixG,std::vector<std::vector<int>>& matrixI,std::vector<std::string> lista){
    setMatrix(matrixG,0,matrixG.size());
    setMatrix(matrixI,0,matrixI.size());
    RandomSortGraphicMatrix(matrixG,lista);
    while(!seeStates(matrixI,matrixI.size(),matrixI[0].size())){

        printMatrix(matrixG,matrixG.size(),matrixG[0].size());
        printMatrix(matrixI,matrixI.size(),matrixI[0].size());

        int positionRelative1;
        std::vector<int> positionAbsolute1;
        int positionRelative2;
        std::vector<int> positionAbsolute2;

        std::cout<<"Select card position: ";
        std::cin>>positionRelative1;

        positionAbsolute1 = calcPositionUserWants(positionRelative1,matrixI.size(),matrixI[0].size());

        flipCard(matrixI,positionAbsolute1[0],positionAbsolute1[1]);

        std::cout<<"Select card position: ";
        std::cin>>positionRelative2;

        positionAbsolute2 = calcPositionUserWants(positionRelative2,matrixI.size(),matrixI[0].size());

        flipCard(matrixI,positionAbsolute2[0],positionAbsolute2[1]);

        successCard(matrixI,matrixG,positionAbsolute1[0],positionAbsolute1[1],positionAbsolute2[0],positionAbsolute2[1]);

    }
    
}

int main(){

    std::vector<std::vector<int>> matrixI = {{1,2,3,4},{5,6,7,8},{9,0,10,11},{12,13,14,15}};
    std::vector<std::vector<std::string>> matrixG = {{"","","",""},{"","","",""},{"","","",""},{"","","",""}};
    std::vector<std::string> lista = {"1","2","3","4","5","6","7","8"};
    game(matrixG,matrixI,lista);


}