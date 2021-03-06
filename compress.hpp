#pragma once
#include <iostream>




namespace itertools{

	template <typename T1, typename T2>  
	class compress{
		T1& Cvalue;
		T2& Cbool;
	
	public:
		compress(T1& Cvalue, T2& Cbool) : Cvalue(Cvalue), Cbool(Cbool) {
			//if(Cvalue.size() != Cbool.size())
			//	throw std::invalid_argument("not same size");
		}
		
		compress(T1&& Cvalue, T2& Cbool) : Cvalue(Cvalue), Cbool(Cbool) {
			//if(Cvalue.size() != Cbool.size())
			//	throw std::invalid_argument("not same size");
		}
		
		compress(T1& Cvalue, T2&& Cbool) : Cvalue(Cvalue), Cbool(Cbool) {
			//if(Cvalue.size() != Cbool.size())
			//	throw std::invalid_argument("not same size");
		}
		
		compress(T1&& Cvalue, T2&& Cbool) : Cvalue(Cvalue), Cbool(Cbool) {
			//if(Cvalue.size() != Cbool.size())
			//	throw std::invalid_argument("not same size");
		}
		
		
		
		struct Iter{
			const compress& com;
			decltype (Cvalue.begin()) iter1;
			decltype (Cbool.begin()) iter2;
			
			public:
			Iter(decltype (Cvalue.begin()) iter1, decltype(Cbool.begin()) iter2, const compress& com) : iter1(iter1),iter2(iter2),com(com){	
		   			
		   		while(iter2 != com.Cbool.end() && !(*iter2)){ //iterate until we found a true value
		   			iter1++;
		   			iter2++;	
		   		}	
		   	}
		   	
		   	Iter& operator=(const Iter& other){
		   		if(this != &other){
		   			this->iter1 = other.iter1;
		   		}
		   		
		   		return *this;
		   	}
			
			Iter& operator++(){
				iter1++;
				iter2++;
				while(iter2 != com.Cbool.end() && !(*iter2)){// as long there variables iterate until we got true
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
			return Iter(Cvalue.begin(), Cbool.begin(),*this);
		}
		
		Iter end() const{
			return Iter(Cvalue.end(), Cbool.end(),*this);
		}
			
	};
}
