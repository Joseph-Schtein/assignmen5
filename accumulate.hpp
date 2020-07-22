#include <iostream>
#include <vector>
#include <string>
#include <functional>
#include <set>
#include "range.hpp"


namespace itertools{

		
	
	std::vector<int> accumulate(const std::vector<int>& v ){
		std::vector<int> acc;
		acc.push_back(v.front());
        		for(int i = 1; i < v.size(); i++){
			        acc.push_back(acc[i-1] + v[i]);
    			}
    		return acc;
	}
	
	std::vector<int> accumulate(const range& r){    
		std::vector<int> v = r.getRange, acc;
		acc.push_back(v.front());
        		for(int i = 1; i < v.size(); i++){
			        acc.push_back(func(acc[i-1] + v[i]));
    			}
    		return acc;
	}

	std::vector<std::string> accumulate(const std::vector<std::string>& v ){
	    std::vector<std::string> acc;
	    acc.push_back(v.front());
	    for(int i = 1; i < v.size(); i++){
	        acc.push_back(acc[i-1] + v[i]);
	    }
	    return acc;
	}
	
	std::vector<int> accumulate(const std::vector<int>& v , const std::function<int(int,int)>& func){
	    std::vector<int> acc;
	    acc.push_back(v.front());
	    for(int i = 1; i < v.size(); i++){
	        acc.push_back(func(acc[i-1],v[i]));
	    }
	    return acc;
	
	}
	
	std::vector<int> accumulate(const std::function<int(int,int)>& func , const std::set<int>& s){ 
			accumulate(s,func);   
	}
	
	std::vector<int> accumulate(const std::set<int>& v , const std::function<int(int,int)>& func){
	    std::vector<int> acc;
	    acc.push_back(v.front());
	    for(int i = 1; i < v.size(); i++){
	        acc.push_back(func(acc[i-1],v[i]));
	    }
	    return acc;
	
	}
	
	std::vector<int> accumulate(const std::function<int(int,int)>& func , const range& r){ 
			accumulate(r,func);   
	}
	
	std::vector<int> accumulate(const range& r , const std::function<int(int,int)>& func){    
		std::vector<int> v = r.getRange, acc;
		acc.push_back(v.front());
        		for(int i = 1; i < v.size(); i++){
			        acc.push_back(func(acc[i-1] + v[i]));
    			}
    		return acc;
	}
}	
