#include <iostream>
#include <vector>

std::vector<int> range(int start, int end){
    std::vector<int> ran; 
    for(int i = start, j = 0 ; i < end; i++, j++){
        ran.push_back(i);
    } 
    return ran;
}