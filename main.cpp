#include <iostream>
#include <string>

void f0(void);
void f1(void);
void f2(void);


int main() {
  std::cout << "PureStylishProspect\n";

  f0();
  f1();
  f2();

  return 0;
}

void f0(void) {
  std::cout << __func__ << std::endl;

  int index;
  char const * ptr;
  std::string number = "345465";
  ptr = &number[0]; //  ptr become a pointer to a char array
  std::cout << *ptr << " in address " << ptr << std::endl;
  std::cout << sizeof(number) << std::endl;

#if FALSE
  //  this loop does nothing
  while (true) {
    if (index == -1) {
      break;
    }
  }
#endif

  std::cout << "Type an index: ";
  std::flush(std::cout);
  std::cin >> index;
  //  DANGER! This can segfault.
  std::cout << number[index] << '\n' << std::endl;

  return;
}

void f1(void) {
   std::cout << __func__ << std::endl;

  int index;
  char const * ptr;
  std::string number = "345465";
  ptr = number.c_str();
  std::cout << ptr[0] << " in array " << ptr << std::endl;
  std::cout << number.size() << std::endl;

  std::cout << "std::string \"number\": " << number << std::endl; 
  std::cout << "Type an index: ";
  std::flush(std::cout);
  std::cin >> index;
  if (index > 0 && index < number.size()) {
    std::cout << number[index] << '\n' << std::endl;
  }
  else {
    std::cout << "Index " << index << " out of range!" << std::endl;
  }

  return;
}

void f2(void) {
   std::cout << __func__ << std::endl;

  std::string numbers = "345465";
  int total = 0;
  for (auto nr : numbers) {
    total += std::atoi(&nr);
  }
  std::cout << numbers << " total=" << total << std::endl;

  return;
}
