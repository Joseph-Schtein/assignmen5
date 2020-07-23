#pragma once


namespace itertools{

	template<typename T, typename lamfun>
	class filterfalse{

		T con;//container
		lamfun& func;
		typedef typename T::value_type value;
	
		public:
			filterfalse(T& con, lamfun func) : con(con), func(func){}	
			filterfalse(T&& con, lamfun func) : con(con), func(func){}	
			
			struct Iter{
				decltype(con.begin()) iter;
				filterfalse filter;
				
				
				Iter(decltype(con.begin()) begin, const filterfalse& f): iter(begin), filter(f){
					while(iter != filter.con.end() && filter.func(iter)){//as long we got true and didn't get to the end continue		
						iter++;					
					}
				}
				
				Iter& operator=(const Iter& other){
					if(this != &other){ //if you not in the same place in the memory
						this->iter = other.iter;
						this->filter = other.filter;
					}
					
					return *this;	
				}			
			};
					
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
				
		bool operator==(const Iter& other) {
			return iter == other.iter;
		}
			
		bool operator!=(const Iter& other){
			return iter != other.iter;
		}
				
		value operator *(){
			return *iter;
		}
		
			
		Iter begin() const{
			return Iter(this->con.begin(), *this);//begining of the containr + this filterfalse
		}
			
		Iter end() const{
			return Iter(this->con.end(), *this);//begining of the containr + this filterfalse
		};
			
	};	
}
