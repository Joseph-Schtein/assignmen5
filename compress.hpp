#include <iostream>
#include <vector>
#include <string>


namespace itertools{

	std::vector<char> compress(std::string str, std::vector<bool> check){
	    std::vector<char> wht;
	    if(check.size() == str.size()){
	        for(int i = 0; i < check.size(); i++){
	            if(check[i] == true){
	                wht.push_back(str[i]);
	            }
	        }

	        return wht;
	    }
	    throw __EXCEPTION__;            
	}

	std::vector<int> compress(std::vector<int> v, std::vector<bool> check){
		std::vector<int> wht;
		if(check.size() == v.size()){
		        for(int i = 0; i < check.size(); i++){
		           if(check.at(i) == true){
		                wht.push_back(v.at(i));
		           }	
	        	}
	       
	        	return wht;	
	    	}
	    		
	    	throw __EXCEPTION__;  
	}    
}
