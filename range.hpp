#pragma once
#include <iostream>
#include <vector>
namespace itertools{
	
	class range{
		
		int begin, end;
			
		public:	
			range(start, end) : start(start), end(end) {}
			
			struct Iter{
				int point;
					
				Iter(int point) : point(point) {}	
				
			bool
			
			
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
		};
		
			
		Iter begin(){		//start of the range return
			return Iter(begin);
		}
		
		Iter end(){
			return Iter(end);
		}			
				
	};
	
}	
