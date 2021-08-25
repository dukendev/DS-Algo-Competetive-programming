#include <bits/stdc++.h>
using namespace std;



int main(){


	vector<int> v;

	v.push_back(4);
	v.push_back(2);
	v.push_back(3);

	vector<int>::iterator i1 = v.begin(); 
	vector<int>::iterator i2 = v.end();
	//note begin points to 0th index
	// end starts from end meaning outside the vector
	//cout<<*v.end(); undefined behaviour

	sort(i1,i2);

	for(vector<int>::iterator i = i1;i!=i2;++i){
		cout<<*i;
	}

	//this is demo of how container,iterator and algorithms
	//can be used in c++ STL

	//there are three kinds of containers
	//sequence containers - vector,deque,list,forward list,array
	//associative containers - set,multiset,map,multimap
	//Unordered containers(hash table) - Unordered set,multiset
	//Unordered map,multimap

	//vectors
	cout<<v[2];		//no range check happen
	cout<<v.at(2); //range check happen 

	//we can traverse like normal array
	for(int i=0;i<v.size();i++){
		cout<<v[i];
	}
	//but using iterators is recommended faster
	cout<<endl;
	//Even more advance way using auto keyword 
	// i is iterator compliler finds out from auto
	//in vector v (: v) means
	for(auto i: v){
		cout<<i;
	}

	//vector is dynamically allocated in contiguous memoary
	//lets check
	cout<<endl;
	int *p = &v[0];
	cout<<p[2]<<" is equal to "<<v[2];


	//some other functions
	cout<<v.empty(); //return true if empty
	v.clear();       //empty the vector
	cout<<v.empty(); 
	v.push_back(7);
	v.push_back(8);
	v.push_back(9);

	vector<int> v2(v); //copy constructor v2 has same content of v

	vector<int> v3(3); //creates vector of size 3 with 0s
	vector<int> v4(5,1); //vector of size 5 with 1s
	v2.swap(v3); //contents are swapped

	for(auto x : v2){ cout<<x;}
	for(auto x : v3){ cout<<x;}
	for(auto x : v4){ cout<<x;}

	//fast insert and remove at the end - O(1)
	//slow at mid/begin - O(n)
	//search - O(n)

	//---------------------

	//deque - it can grow from both ends
	deque<int> deq = {1,2,3}; //initializing with values
	deq.push_back(4);
	deq.push_front(0);

	for(auto x : deq){ cout<<x;}
	//same 
	//fast insert and remove at the END and BEGIN - O(1)
	//slow at mid - O(n)
	//search - O(n)

	//--------------------------

	//list - it is a doubly linked list
	list<int> l = {5,2,3};
	l.push_back(8);
	l.push_front(1);

	list<int>::iterator it = find(l.begin(),l.end(),3);
	//it points to 3 in the list
	it++; //moved to next
	cout<<*it; 
	l.erase(it); //erases it pointee item

	for(auto x : l){cout<<x;} 
	//fast insert and remove at all places O(1)
	//slow search O(n)
	//no random access like in vector and deque using [] operator

	//list is stored in non-contiguous memoary blocks
	//list in general slower 

	//one advantage is splice function 
	//cut part on one list and put it in other
	//at desired place
	//cut mid to numbers of l list and putting it
	//at the start of l2

	list<int> l2;
	list<int>::iterator ia = l.begin();
	list<int>::iterator ib = l.end();
	list<int>::iterator i_here = l2.begin();
	ia++;
	ib--;

	l2.splice(i_here,l,ia,ib);
	cout<<endl;
	for(auto x : l2){cout<<x;}

	//only list has this bomb function very useful
	//---------------------

	//forward list - is singly forwards list only
	//other things are pretty much the same

	//array -- can also use stl function if we use it like them

	//int a[4] = {1,2,3,4};
	//define it like stl
	array<int,4> a = {1,2,3,4};
	//a.size();
	//a.swap();
	//use stl functions like usual
	//size cannot be changed so the limitation should be taken care 
	//like swap with similar datatype and SIZE of other array only
	//---------------------------------
	
	//=======================================================
	//associative containers
	//always sorted, by default in increasing order
	//push_back and push_back is meaningless only push
	
	//SET
	// -it has no duplicate items
	
	//insertion takes O(logn) time
	set<int> s;
	s.insert(4);
	s.insert(7);
	s.insert(1);

	for(auto x : s){cout<<x;} //sort 1 4 7

	set<int>::iterator it_s;
	it_s = s.find(4);  // also O(logn) time very fast
	cout<<*it_s; 
	//find function and finding speed is noticable feature of asso. containers

	//insert function actually returns also
	//lets see	
	pair<set<int>::iterator,bool> result;
	result = s.insert(5);

	cout<<result.second; //true newly added it was not already in set
	it_s = result.first;

	//it_s points to inserted item -- 5

	s.insert(it_s,14); //passing it_s1 makes insertion faster in O(1)

	//s.erase(it_s);
	//s.erase(5);
	//erase with iterator or value both possible

	//----------------------
	//MULTISET - just like set but allows duplicate items
	//insertion always happend

	//in set and multiset data is read only can not be modified
	//it can mess the sorting order that's why 

	//------------------------------------
	//Map and Multimap
	//like in set items are always sorted according to value
	//what if we need to sort them according to key

	//in map and multimap - (key,value) pairs are used
	//and items pairs are sorted according to keys

	//map - no duplicate key is allowed 

	map<char,int> m;
	//both ways are fine
	m.insert(pair<char,int>('a',13));
	m.insert(make_pair('b',5));  //easy

	map<char,int>::iterator it_map = m.begin();
	m.insert(it_map,pair<char,int>('c',8)); //it_map iterator used as hint and inserts faster

	it_map = m.find('b'); //O(logn) time very fast

	//print content
	
	for(map<char,int>::iterator it_map1 = m.begin();it_map1!=m.end();it_map1++){
		cout<<it_map1->first<<" - "<<(*it_map1).second<<endl;
	}
	//-> operator or after derefrencing . operator both can be used

	//---------------------------
	//multimap - duplicate keys are allowed 

	//keys can not be modified they are read onyl
	// map<char,int> or multimap<char,int> are actully <const char,int>
	//In both map and multimap keys are not to be changed


	//------------------------------------------------
	//Unordered associative Containers
	//We have unordered set,multiset,map,multimap
	//They are implemented with a hash table
	//unordered set

	unordered_set<string> myset = {"red","blue","bob","pop"};
	unordered_set<string>::const_iterator itr_unset = myset.find("red");
	//O(1) fast searching
	//find returns iterator to the found element of to the end of the list
	if(itr_unset!=myset.end()){
		cout<<*itr_unset;
	}

	myset.insert("yellove");  //O(1)
	//it also works with other containers
	vector<string> vec = {"alpha","beta"};
	myset.insert(vec.begin(),vec.end());

	//Hash table APIS
	cout<<"Load factor is hash table is "<<myset.load_factor();
	cout<<"bucket of alpha is "<<myset.bucket("alpha");
	cout<<"number of bucket are "<<myset.bucket_count();


	//-----------
	//unordered multiset is unordered set that allows duplicate entries
	//unordered map take pairs and multimap allows duplicate keys in key,value pair entries


	//==================================
	//Important points about iterators

	//array,vector,deque are implemented using arrays
	//so there iterators are random access itr+5 is valid

	//in case of list,sets,maps iterators can only be -1 and +1
	//they are called bidirectional iterators


	//for forward list itr can only be move in forward direction


	//Every constainer have const iterator and iterator
	//const iterator are read only

	





	











}