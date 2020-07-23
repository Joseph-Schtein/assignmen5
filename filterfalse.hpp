#pragma once


namespace itertools{

	template<typename container, typename lamfun>
	class filterfalse{

		container& con;//container
		lamfun func;

	
		public:
			filterfalse(container& con, lamfun _func) : con(con), func(_func){}//regular container
			filterfalse(lamfun _func, container& con) : func(_func), con(con){}//mirror
			filterfalse(container&& con, lamfun _func) : con(con), func(_func){}//for range
			filterfalse(lamfun _func, container&& con) : func(_func), con(con){}//mirror
			
			struct Iter{
				decltype(con.begin()) iter;
				filterfalse filter;
				
				
				Iter(decltype(con.begin()) begin, const filterfalse& f): iter(begin), filter(f){
					while(iter != filter.con.end() && filter.func(*iter)){//as long we got true and didn't get to the end continue		
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
			
					
			Iter& operator++(){
				iter++;
				while(iter != filter.con.end() && filter.func(*iter)){// same as in the constructor
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
				
			auto operator *(){
				return *iter;
			}
		
		};
			
		Iter begin() const{
			return Iter(con.begin(), *this);//begining of the containr + this filterfalse
		}
			
		Iter end() const{
			return Iter(con.end(), *this);//begining of the containr + this filterfalse
		};
		
			
	};	
}
