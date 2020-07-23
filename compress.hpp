#include <iostream>
#include <vector>
#include <string>


namespace itertools{

	template <typename T1, typename T2>  
	class compress{
	const T1& c1;
	const T2& c2;
	
	public:
		compress(T1& c1, T2& c2) : c1(c1), c2(c2) {
			if(c1.size() != c2.size())
				throw std::invalid_argument("not same size");
		}
		
		struct Iter{
			const compress& com;
			decltype (c1.begin()) iter1;
			decltype (c2.begin()) iter2;
			
			public:
			Iter(decltype (c1.begin()) iter1, decltype(c2.begin()) iter2, const compress& com) : com(com){
		   		
		   		
		   		if(iter1 != com.c1.end())
		   			this->iter1 = iter1;
		   		
		   		if(iter2 != com.c2.end())
		   			this->iter2 = iter2;
		   			
		   		else{
		   			throw std::invalid_argument("empty containers");
		   		}	
		   			
		   		while(iter2 != com.c2.end() && !(*iter2)){ //iterate until we found a true value
		   			iter1++;
		   			iter2++;	
		   		}	
		   	}
			
			Iter& operator++(){
				iter1++;
				iter2++;
				while(iter2 != com.c2.end() && !(*iter2)){// as long there variables iterate until we got true
					iter1++;
					iter2++; 	
				}
				
				return *this;
			}
			
			Iter operator++(int){
				Iter tmp = *this;
				iter1++;
				iter2++;
				return tmp;
			}
			
			bool operator==(const Iter& other)const{
				return iter1 == other.iter1;
			}
			
			bool operator!=(const Iter& other)const{
				return iter1 != other.iter1;
			}	
			
			auto operator*(){
				return *iter1;
			}
				
		};
		
		Iter begin() const{
			return iterator(c1.begin(), c2.begin(),*this);
		}
		
		Iter end() const{
			return iterator(c1.end(), c2.end(),*this);
		}
			
	};
}
