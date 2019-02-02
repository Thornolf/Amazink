#include <iostream>
#include <fstream>
#include <string>

#include "color.hpp"
#include "colorChart.hpp"

int		main(int argc, char **argv)
{
  (void)argc;
  (void)argv;
  ColorChart *color = new ColorChart("couleurs.txt");
  color->getArrayColor()[18].dump();
  std::cout << "There is " <<  color->getSize() << " colors availables" << std::endl;
  return (0);
}
