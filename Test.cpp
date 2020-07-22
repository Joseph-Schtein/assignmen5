#include "doctest.h"
#include "accumulate.hpp"
#include "compress.hpp"
#include "filterfalse.hpp"
#include "range.hpp"

#include <vector>

using namespace itertools;
using namespace std;

TEST_CASE("Check accumlate numbers"){
	
	vector<int> check = {1,3,5,9};
	vector<int> test = accumulate(check);
	CHECK(accumulate(range(1,3))[0] == 1);
	CHECK(test[2] == 9);
	CHECK(test[3] == 18);
	CHECK(test[1] == 4);
	CHECK(test[0] == 1);
	CHECK(test[3] + accumulate(range(1,3))[2] == 24);
	
	CHECK(accumulate(range(5,10))[2] == 18);
	CHECK(accumulate(range(5,10))[1] == 11);
	CHECK(accumulate(range(5,10))[3] == 26);
	CHECK(accumulate(range(5,10))[0] == 5);
	CHECK(accumulate(range(5,10))[4] == 35);
	CHECK(accumulate(range(5,10))[2] + accumulate(range(1,3))[2] == 24);
}

TEST_CASE("Check accumlate strings"){

 vector<string> text={"Success","is","not","final","failure","is","not","fatal","it","is","the","courage","to","continue","that","counts"};
	vector<string> acc = accumulate(text);	
	CHECK(acc[3] == "Successisnotfinal");
	CHECK(acc[1] == "Successis");
	CHECK(acc[2] == "Successisnot");
	CHECK(acc[7] == "Successisnotfinalfailureisnotfatal");
	CHECK(acc[5] == "Successisnotfinalfailureis");
	CHECK(acc[4] == "Successisnotfinalfailure");
	CHECK(acc[9] == "Successisnotfinalfailureisnotfatalitis");
	CHECK(acc[8] == "Successisnotfinalfailureisnotfatalit");
	CHECK(acc[0] == "Success");
	CHECK(acc[10] == "Successisnotfinalfailureisnotfatalitisthe");
	CHECK(acc[11] == "Successisnotfinalfailureisnotfatalitisthecourage");
	CHECK(acc[13] == "Successisnotfinalfailureisnotfatalitisthecouragetocontinue");

}

TEST_CASE("Check lanbda accumlate "){

	vector<int> odds = {1,3,5,7,9}; 
	vector<int> evens = {2,4,6,8,10};
	vector<int> acce = accumulate(evens, [](int x, int y){return x-y;});
	vector<int> acco = accumulate(odds, [](int x, int y){return x+y;});
	CHECK(acce[0] == 1);
	CHECK(acce[1] == 2);
	CHECK(acce[2] == 3);
	CHECK(acce[3] == 4);
	CHECK(acce[4] == 5);
	CHECK(acce[1] + acco[1] == 8);
	CHECK(acce[0] + acco[1] == 5);
	CHECK(acce[3] + acco[1] == 10);
	CHECK(acce[4] + acco[1] == 11);
	CHECK(acce[0] + acco[0] == 3);
	CHECK(acce[4] + acco[4] == 35);
	CHECK(acce[3] + acco[2] == 16);
	CHECK(acce[0] + acco[4] == 31);
	CHECK(acce[4] + acco[3] == 25);
	
	
	CHECK(acco[2] == 12);
	CHECK(acco[1] == 6);
	CHECK(acco[3] == 20);
	CHECK(acco[0] == 2);
	CHECK(acco[4] == 30);
	CHECK(acco[1] - acce[4] == 1);
	CHECK(acco[0] - acce[3] == -2);
	CHECK(acco[3] - acce[3] == 16);
	CHECK(acco[3] - acce[0] == 19);
	CHECK(acco[2] - acce[1] == 10);
	CHECK(acco[1] - acce[3] == 2);
	CHECK(acco[3] - acce[2] == 17);
	CHECK(acco[3] - acce[4] == 15);
	CHECK(acco[0] - acce[1] == 0);
	CHECK(acco[2] - acce[2] == 9);
	CHECK(acco[0] - acce[0] == 1);
	CHECK(acco[0] - acce[4] == -3); //56
}



TEST_CASE("Check compress int"){

	vector<int> odds = {1,3,5,7,9}; 
	vector<int> evens = {2,4,6,8,10};
	vector<bool> od = {true,false,true,true,false};	//{1,5,7}
	vector<bool> ev = {false,true,false,false,true};	//{4,10}
	vector<int> o = compress(odds, od);
	vector<int> e = compress(evens, ev);
	CHECK(o[0] == 1);
	CHECK(o[1] == 5);
	CHECK(o[2] == 7);
	CHECK(e[0] == 4);
	CHECK(e[1] == 10);
	CHECK(o[0] + e[0] == 5);
	CHECK(o[0] + e[1] == 11);
	CHECK(o[1] + e[0] == 9);
	CHECK(o[1] + e[1]== 15);
	CHECK(o[2] + e[0]== 11);
	CHECK(o[2] + e[1] == 17);//66
	
}


TEST_CASE("Check compress string "){

vector<string> text = {'g','o','v','e','r','n','m','e','n','t','d','e','m','o','c','r','c','y'}; 
	
      vector<bool> com= {true,true,false,true,false,false,true,true,true,false,true,true,false,false,true,false,true,true};	
        	
	vector<char> t = compress(text, com); // {'g','o','e','m','e','n','d','e','c','c','y'}

	CHECK(t[0] == 'g');
	CHECK(t[1] == 'o');
	CHECK(t[2] == 'e');
	CHECK(t[3] == 'm');
	CHECK(t[4] == 'e');
	CHECK(t[5] == 'n');
	CHECK(t[6] == 'd');
	CHECK(t[7] == 'e');
	CHECK(t[8] == 'c');
	CHECK(t[9] == 'c');
	CHECK(t[10] == 'y');//77
	
}



TEST_CASE("Check filter false "){
	
	vector<int> odds = {1,3,5,7,9,11,13,15};
	vector<int> evens = {2,4,6,8,10,12,14,16};
	vector<int> v1 = filterfalse([](int i){return i%2==0;});
	CHECK(v1 == evens);
	vector<int> v2 = filterfalse([](int i){return i%2==0 || 14<i;}, odds);
	CHECK(v2 == {15});
	vector<int> v3 = filterfalse([](int i){return i%4==0;}, evens);
	CHECK(v3 == {4,8,12,16});
	vector<int> v4 = filterfalse([](int i){return i%3==0;}, odds);
	CHECK(v4 == {3,9,15});
	vector<int> v5 = filterfalse([](int i){return i%5==0;}, evens);
	CHECK(v5 == {10});
	vector<int> v6 = filterfalse([](int i){return i<13;}, odds);
	CHECK(v6 == {1,3,5,7,9,11});
	vector<int> v7 = ;
	CHECK(filterfalse([](int i){return i%2==1;}, evens) == {});
	vector<int> v8 = ;
	CHECK(filterfalse([](int i){return i%2==0;}, odds) == {});
	vector<int> v9 =;
	CHECK(filterfalse([](int i){return i>3 && i<10;}, evens) == {4,6,8});
	vector<int> v10 = ;
	CHECK(filterfalse([](int i){return i%5==0 && i<=5;}, odds) == {5});
	vector<int> v11 = ;
	CHECK(filterfalse([](int i){return i%3==0 || i>12;}, evens) == {6,12,14,16});
	vector<int> v12 = ;
	CHECK(filterfalse([](int i){return i%1==0;}, odds) == {1,3,5,7,9,11,13,15});
	vector<int> v13 = ;
	CHECK(filterfalse([](int i){return i<=2 || i>=8;}, evens) == {2,8,10,12,14,16});
	vector<int> v14 = ;
	CHECK(filterfalse([](int i){return i > 10;}, odds) == {11,13,15});
	vector<int> v15 = ;
	CHECK(filterfalse([](int i){return i == 8;}, evens) == {8});//92
	vector<int> v16 = ;
	CHECK(filterfalse([](int i){return i>13;}, odds) == {13,15});
	vector<int> v17 = ;
	CHECK(filterfalse([](int i){return i==4 || i==6;}, evens) == {4,6});
	vector<int> v18 = ;
	CHECK(filterfalse([](int i){return i==3 || i==5 || i==1;}, odds) == {1,3,5});
	vector<int> v19 = ;
	CHECK(filterfalse([](int i){return i<3 || i>10;}, evens) == {2,12,14,16});
	vector<int> v20 = ;
	CHECK(filterfalse([](int i){return i%5==2;}, odds) == {7});
	vector<int> v21 = ;
	CHECK(filterfalse([](int i){return i%3==1;}, evens) == {4,10});
	vector<int> v22 = ;
	CHECK(filterfalse([](int i){return i%4==3;}, odds) == {3,7,11,15});
	vector<int> v23 = ;
	CHECK(filterfalse([](int i){return i<=2 || i>=8;}, evens) == {2,8,10,12,14,16});
}
	
	
	
	
	
	
	
	
	
	


