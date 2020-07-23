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
			
			struct Iter{
				decltype(con.begin()) iter;
				const filterfalse filter;
				
				
				Iter(decltype(con.begin()) begin, const filterfalse& f): iter(begin), filter(f){
					while(iter != filter.con.end() && filter.func(iter)){//as long we got true and didn't get to the end continue		
						iter++;					
				
				}
					
				Iter& operator++(){
					iter++;
					while(iter != filter.con.end() && filter.func(iter)){// same as in the constructor
						iter++;
					}
						
					return *this;	
				}
				
				const Iter operator++(int){
					Iter tmp = *this;
					++iter;
					return tmp;
				}
					
				bool operator==(const Iter& other) const{
					return iter == other.iter;
				}
					
				bool operator!=(const Iter& other)const{
					return iter != other.iter;
				}
					
				auto operator *(){
					return *iter;
				}
		};
			
		Iter begin() const{
			return Iter(this->con.begin(), *this);//begining of the containr + this filterfalse
		}
			
		Iter end() const{
			return Iter(this->con.end(), *this);//begining of the containr + this filterfalse
		};
			
	};	
}
