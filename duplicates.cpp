#include <iostream>
#include <array>

//   std::map <int, string> Employees;
//   for( map<int,string>::iterator ii=Employees.begin(); ii!=Employees.end(); ++ii)
//       cout << (*ii).first << ": " << (*ii).second << endl;

//  std::unordered_map<std::string,std::string> mymap;
//  mymap.rehash(20);
//  mymap["house"] = "maison";
//  for (auto& x: mymap) {
//    std::cout << x.first << ": " << x.second << std::endl;


struct element
{
   int value;
   element * next;
};

template <unsigned size>
class IntHash
{
  private:
  std::array<element*, size> myarray;

  public:
  IntHash()
  {
    for (int i=0; i<size; i++) myarray[i]=NULL;
  }

  bool add(int value)
  {
    unsigned hashval = findHash(value);
      
    element* temp = myarray[hashval];
    while ( temp != NULL )
    {
      if (temp->value == value)
        return false; 
      temp = temp->next;
    }

    element* e = new element;
    e->value = value;
    myarray[hashval] = e;
    return true;
  }

  private:
  unsigned findHash(int value)
  {
    return value % size;
  }
};

int main()
{
  element* list;
  element e1, e2, e3, e4, e5;

  e1.value = 1;
  e2.value = 4;
  e3.value = 4;
  e4.value = 6;
  e5.value = 1;

  list = &e1;
  e1.next = &e2;
  e2.next = &e3;
  e3.next = &e4;
  e4.next = &e5;
  e5.next = NULL;

  IntHash <20> myhash;

  element* temp = list;
  element* runner = NULL;

  while( temp!= NULL )
  {
    bool dupe = !myhash.add( temp->value );
    if (dupe)
    {
        runner->next = temp->next;
    }
    runner = temp;
    temp = temp->next;
  }

  temp = list;
  while( temp!= NULL )
  {
    std::cout << temp->value << " " << std::endl;
    temp = temp->next;
  }
}
