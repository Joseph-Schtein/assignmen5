#include <iostream>
#include <vector>
#include <string>


namespace itertools{

	template <typename T1, typename T2>  
	class compress{
	T1& c1;
	T2& c2;
	
	public:
		compress(T1& c1, T2& c2) : c1(c1), c2(c2) {
			if(c1.size() != c2.size())
				throw std::invalid_argument("not same size");
		}
		
		class Iter{
			const compress& com;
			decltype (c1.begin()) iter1;
			decltype (c2.begin()) iter2;
			
			public:
			Iter(decltype (c1.begin) iter1, decltype(c2.begin) iter2, compress& c) : iter(1), iter(2), com(c){}
			
			Iter& operator++(){
				iter1++;
				iter2++;	
				return *this;
			}
			
			auto operator*(){
				return *iter1
			}
				
		};
		
		Iter begin() const{
			return iterator(c1.begin(), c2.begin(),*this)
		}
		
		Iter end() const{
			return iterator(c1.end(), c2.end(),*this)
		}
			
	};
}
