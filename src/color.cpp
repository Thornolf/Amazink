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

std::string	Color::getName() {
  return (this->_name);
}

std::string	Color::getRGB() {
  return (this->_rgb);
}

int		Color::getPrice() {
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

void		Color::dump() {
  std::cout << "Name is : " << getName();
  std::cout << " RGB is : " << getRGB();
  std::cout << " price is : " << getPrice() << std::endl;
}

Color::~Color() {}
