#include "color.hpp"


Color::Color() {
  this->_name = "Undefined";
  this->_rgb = "Undefined";
  this->_price = 1;
}

Color::Color(std::string newName, std::string newRGB) {
  this->_name = newName;
  this->_rgb = newRGB;
  this->_price = 1;
}

Color::Color(const Color &obj) {
  this->_name = obj.getName();
  this->_rgb = obj.getRGB();
  this->_price = obj.getPrice();
}

std::string	Color::getName() const {
  return (this->_name);
}

std::string	Color::getRGB() const {
  return (this->_rgb);
}

int		Color::getPrice() const {
  return (this->_price);
}

void		Color::setName(std::string newName) {
  this->_name = newName;
}

void		Color::setRGB(std::string newRGB) {
  this->_rgb = newRGB;
}

void		Color::setPrice(int newPrice) {
  this->_price = newPrice;
}

int		Color::hexToDec(std::string strToConvert) {
  int converted;
  
  try {
    converted = std::stol(strToConvert, nullptr, 16);
  }
  catch (const std::invalid_argument& e) {
    std::cout << "Invalid RGB symbol" << std::endl;
  }
  return (converted);
}

void            Color::dump() {
  try {
    std::string red = "";
    red += getRGB()[1];
    red += getRGB()[2];
    std::string green = "";
    green += getRGB()[3];
    green += getRGB()[4];
    std::string blue = "";
    blue +=getRGB()[5];
    blue += getRGB()[6];
    std::cout << "\033[38;2;" << std::to_string(hexToDec(red)) << ";" << std::to_string(hexToDec(green)) << ";" << std::to_string(hexToDec(blue)) << "m" << getName();
    std::cout << " | " << getRGB();
    std::cout << " | " << getPrice() << " $" << "\033[0m" << std::endl;
  }
  catch (const std::invalid_argument& e) {
    std::cout << "Invalid RGB symbol" << std::endl;
  }
}

Color		&Color::operator=(Color const &obj) {
  this->_name = obj.getName();
  this->_rgb = obj.getRGB();
  this->_price = obj.getPrice();
  return (*this);
}

Color::~Color() {}
