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
				
			
			
			
			Iter& operator ++(){	//the value that has increased is the range itself
				point++;
				return *this;
			}
		
			Iter& getIter(){
				return *this;
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
