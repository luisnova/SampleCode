// gcc string_play.cpp -lstdc++

#include <iostream>
#include <string>

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

  return 0;
}
