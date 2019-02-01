#include <iostream>

int main(int argc, char **argv)
{
  (void)argc;
  (void)argv;
  std::string* ptr = new std::string[argc];

  for (int index = 1 ; index < argc; index++) {
    ptr[index] = argv[index];
    std::cout << "L'attribu numéro " << index << " du tableau est "  << ptr[index] << std::endl;
  }
  return (0);
}
