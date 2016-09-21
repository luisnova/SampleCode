
// gcc string_play.cpp -lstdc++ -std=c++11

#include <iostream>
#include <string>
#include <array>
#include <list>
#include <vector>

int main ()
{
  char buffer[20];
  std::string str ("Test string...");
  std::size_t length = str.copy(buffer,6,5);
  buffer[length]='\0';
  str.assign("changed");

  std::cout << "buffer contains: '" << buffer << "'" << '\n';
  std::cout << "str contains: '" << str.c_str() << "'" << '\n';
  std::cout << "length: " << str.length() << "\n";
  std::cout << "capacity: " << str.capacity() << "\n";
  std::cout << "max_size: " << str.max_size() << "\n";

  std::cout << '\n';

  std::array<int,10> myarray;
  myarray.fill(22);
  for (int i=0; i<5; i++) 
    myarray[i]=i;

  std::cout << "size of myarray: " << myarray.size() << std::endl;
  std::cout << "sizeof(myarray): " << sizeof(myarray) << std::endl;
  for ( int& x : myarray) 
    std::cout << ' ' << x; 

  std::cout << '\n' << '\n';

  std::list<int> mylist;
  std::list<int>::iterator it;

  for (int i=1; i<=5; i++) 
    mylist.push_back(i); // 1 2 3 4 5

  mylist.pop_back();
  it = mylist.begin();
  ++it;

  mylist.insert (it,22);     // 1 22 2 3 4
  mylist.insert (it,2,20);   // 1 22 20 20 2 3 4
  --it;  

  std::vector<int> myvector (2,44);
  mylist.insert (it,myvector.begin(),myvector.end()); // 1 22 20 44 44 20 2 3 4
  
  std::cout << "mylist [";
  for (it=mylist.begin(); it!=mylist.end(); it++)
    std::cout << ' ' << *it;
  std::cout << " ]" << '\n';

  return 0;
}
