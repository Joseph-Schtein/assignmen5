#pragma once
#include <iostream>
#include <vector>
#include <string>
#include <functional>
#include <set>



namespace itertools{


	template<typename container, typename lamfun>
	class accumulate{
		container& con;
		lamfun&    func;
		
		public:
		
			accumulate(container con, lamfun func) : con(con), func(func){}
			
			class Iter{
				decltype(con.begin()) iter;
				vector<decltype(*(con.begin()))> sum;//vector that represent the accumulation
				const accumulate& acc;
				
				public:
					Iter(const accumulate acc, decltype(con.begin()) point) : acc(acc), iter(point) {
						if(iter!=acc.con.end()){
							sum.push_back(*point);
						}	
					}
					
					Iter& operator++(){
						iter++;
						if(iter!=acc.con.end()){
							return *this;
						}
						
						else{
							sum.push_back(acc.lamfun(sum[iter-1], *iter));
							return *this;
						}	
					}
					
					 bool operator==(const Iter& other) const {
               				 return iter==other.iter;
            				 }

         		   		 bool operator!=(const Iter& other) const {
                				 return iter!=other.iter;
            				 }
            				 
            				 auto operator*(){
            				 	return sum
            				 }
			};
			
			 Iter begin() const {
           			 return iterator(con.begin(),*this);

       		 }
        		 
        		 Iter end() const {
            			return iterator(con.end(),*this);
        		 }
	};
		
}
