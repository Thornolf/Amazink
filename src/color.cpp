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

Color		&Color::operator=(Color const &obj) {
  this->_name = obj.getName();
  this->_rgb = obj.getRGB();
  this->_price = obj.getPrice();
  return (*this);
}

void		Color::dump() {
  std::cout << getName();
  std::cout << " | " << getRGB();
  std::cout << " | " << getPrice() << " $" << std::endl;
}

Color::~Color() {}
