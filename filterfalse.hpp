#include <iostream>
#include <vector>
#include <functional>

std::vector<int> filterfalse(const std::function<bool(int)>& func ,const std::vector<int>& v){
    std::vector<int> fi;
    for(int i = 0; i < v.size(); i++){
        if(!func(v[i])){
            fi.push_back(v[i]);
        }
    } 

    return fi;   
}