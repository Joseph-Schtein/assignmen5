#include <iostream>
#include <vector>
namespace itertools{
	
	class range{
		public:
			std::vector<int> r;
			int start;
			int end;
		
			range(int start, int end) : start(start), end(end) {
	  			for(int i = start, j = 0 ; i < end; i++, j++){
	        			r.push_back(i);
	    			} 
			}
			
			std::vector<int> getRange(){
				return r;
			}		
	};
	
	
	std::vector<int> range(int start, int end){
	    std::vector<int> ran; 
	    for(int i = start, j = 0 ; i < end; i++, j++){
	        ran.push_back(i);
	    } 
	    return ran;
	}
}	
