#include <iostream>
#include <vector>
#include <functional>


namespace itertools{

	template<typename T, typename lamfun>
	class filterfalse{

		const T& con;
		const lamfun& func;
	
		public:
			filterfalse(const T& con, const lamfun finc*) : con(con), func(func){}	
			
			class Iter{
				decltype(container.begin()) iter;
				const fileterfalse filter;
				
				public:
					Iter(decltype(container.begin()) begin, const filterfalse& f): iter(begin), filter(f){
						while(iter != fileterfalse.end() && filter.func(iter)){//as long we got true and didn't get to the end continue		
								iter++;					
				
					}
					
					Iter& operator++(){
						iter++;
						while(iter != fileterfalse.end() && filter.func(iter)){// same as in the constructor
							iter++;
						}
						
						return *this;	
					}
					
					bool operator==(iterator& other){
						return iter == other.iter;
					}
					
					bool operator==(iterator& other){
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
