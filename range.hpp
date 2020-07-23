#pragma once
#include <iostream>
#include <vector>
namespace itertools{
	
	class range{
		
		int start, finish;
			
		public:	
			range(int start, int finish) : start(start), finish(finish) {}
			
			struct Iter{
				int point;
					
				Iter(int point) : point(point) {}	
				Iter& operator=(const Iter& other){
					if(this != &other) // check ifthey are in the same place
						this->point = other.point;
					return *this;	
				}
			
			
			
				Iter& operator ++(){	//the value that has increased is the range itself
					point++;
					return *this;
				}
				
				Iter operator ++(int){	//the value that has increased is the range itself
					Iter tmp = *this;
					point++;
					return tmp;
				}
		
			
			
				int operator*(){
					return point;
				}
			
				bool operator==(const Iter& other) const {
               			 return point==other.point;
            			 }

           			 bool operator!=(const Iter& other) const {
            				 return point!=other.point;
            			 }
			};
		
			
			Iter begin(){		//start of the range return
				return Iter(start);
			}
			
			Iter end(){			//end of the range return
				return Iter(finish);
			}			
				
		};
	
}	
