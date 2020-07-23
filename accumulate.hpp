#pragma once
#include <iostream>




namespace itertools{

	
	typedef struct {
		template<typename T>
		T operator()(T x, T y) const { 
			return x + y; 
		}	
	} plus;

	template<typename container, typename lamfun = plus>
	class accumulate{
		container& con;
		lamfun func;
		
		public:
		
			accumulate(container& con, lamfun func = plus()) : con(con), func(func){}
			
			
			struct Iter{
				decltype(con.begin()) iter;
				typename container::value_type sum;//vector that represent the accumulation
				const accumulate& acc;
				
				public:
					Iter(const accumulate acc, decltype(con.begin()) iter) : acc(acc), iter(iter) {
						if(iter!=acc.con.end()){
							sum = *iter;	
						}	
					}
					
					Iter& operator=(const Iter& other){
						if(this != &other){ // if the memory location is the same it is the same Iterator
						
							this->iter = other.iter;
							this->acc = other.acc;
						}
					}
					
					
				Iter& operator++(){
					iter++;
					if(iter==acc.con.end()){
						return *this;
					}
						
					else{
						sum = acc.func(sum , *iter);
						return *this;
					}	
				}
				
				const Iter operator++(int) {
					Iter tmp = *this;
					++iter;
					if(iter != acc.con.end()){
				        	sum= acc.func(sum, *iter);      
					} 
					return tmp;
				}
					
			 	bool operator==(const Iter& other) const {
               			 return iter==other.iter;
            			}

         			bool operator!=(const Iter& other) const {
               			 return iter!=other.iter;
            			}
            				 
            			 auto operator*(){// could be range so I can't exetract the type
            			 	return sum;
            			 }
			
			};	
				
			 Iter begin() const {
           			 return Iter(*this, con.begin());

       		 }
        		 
        		 Iter end() const {
            			return Iter(*this, con.end());
        		 }
	};
		
}
