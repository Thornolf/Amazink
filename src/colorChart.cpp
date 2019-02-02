#include <fstream>

#include "colorChart.hpp"

static std::string     parsingName(std::string line) {
  std::string tmp = line.substr(0, line.find(","));
  return (tmp);
}

static std::string     parsingRGB(std::string line) {
  std::string tmp = line.substr(line.find(",") + 1);
  return (tmp);
}

ColorChart::ColorChart() {
  this->_size = 1;
  this->_arrayColor = new Color[this->_size];
}

ColorChart::ColorChart(std::string fileName) {
  
  std::string line;
  std::ifstream file(fileName);
  int index = 0;

  if (file.is_open()) {
    while (getline(file, line))
      index++;
  } else {
    std::cout << "Unable to open file to count";
  }
  this->_size = index;
  this->_arrayColor = new Color[this->_size];
  index = 0;
  file.clear();
  file.seekg(0);
  if (file.is_open())
  {
    while (getline(file,line))
    {
      this->_arrayColor[index].setName(parsingName(line));
      this->_arrayColor[index].setRGB(parsingRGB(line));
      this->_arrayColor[index].dump();
      index++;
    }
    file.close();
  }
  else {
    std::cout << "Unable to open file";
  }
}

int	ColorChart::getSize() {
  return (this->_size);
}

Color *ColorChart::getArrayColor() {
  return (this->_arrayColor);
}

void	ColorChart::setSize(int newSize) {
  this->_size = newSize;
}

void	ColorChart::setArrayColor(Color *newArrayColor) {
  this->_arrayColor = newArrayColor;
}

ColorChart::~ColorChart() {}
