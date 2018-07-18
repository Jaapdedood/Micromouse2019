#include <stdio.h>
#include <string>
#include <iostream>
#include <array>
#include <vector>
#include "maze.cpp"
#define NORTH 1
#define EAST 2
#define SOUTH 4
#define WEST 8

int main()
{
    std::vector<std::string> rows;
    std::vector<std::string> columns;

    for(const auto& s: testmaze){
        if(s & SOUTH){
            rows.push_back("---");
        }
        else{
            rows.push_back("   ");
        }
    }

    for(const auto& s: testmaze){
        if(s & WEST){
            columns.push_back("|");
        }
        else{
            columns.push_back(" ");
        }
    }

    //First row (always the same)
    for(int i = 0; i < 16; i++){
        std::cout << "o---";
    }
    std::cout << 'o' << std::endl;

    int cell = 0;
    for(int i = 0; i < 32; i++){
        if(i%2){ //rows
            for(int j = 1; j < 16; j++){
                cell = (16-(i/2))*j;
                std::cout << 'o' << rows[cell];
            }
            std::cout << 'o' << std::endl;
        }
        else{ // columns
            for(int j = 1; j < 16; j++){
                cell = (16-(i-1)/2)*j;
                std::cout << columns[cell] << "   ";
            }
            std::cout << '|' << std::endl;
        }
    }
    return 0;
}
