#include <iostream>
#include <vector>
#include <functional>


namespace itertools{

	template<typename T, typename lamfun>
	class filterfalse{

		const T& con;
		const lamfun& func;
	
		public:
			filterfalse(const T& con, const lamfun& func) : con(con), func(func){}	
			
			class Iter{
				decltype(con.begin()) iter;
				const filterfalse filter;
				
				public:
					Iter(decltype(con.begin()) begin, const filterfalse& f): iter(begin), filter(f){
						while(iter != filterfalse.end() && filter.func(iter)){//as long we got true and didn't get to the end continue		
								iter++;					
				
					}
					
					Iter& operator++(){
						iter++;
						while(iter != fileterfalse.con.end() && filter.func(iter)){// same as in the constructor
							iter++;
						}
						
						return *this;	
					}
					
					bool operator==(Iter& other){
						return iter == other.iter;
					}
					
					bool operator==(Iter& other){
						return iter != other.iter;
					}
					
			};
			
			Iter begin() const{
				return Iter(con.begin(), *this);//begining of the containr + this filterfalse
			}
			
			Iter end() const{
				return Iter(con.end(), *this);//begining of the containr + this filterfalse
			}
			
	};	
}
