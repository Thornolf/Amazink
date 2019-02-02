#ifndef _COLOR_HPP_
# define _COLOR_HPP_

#include <string>
#include <iostream>

class Color {
private:
  std::string	_name;
  std::string	_rgb;
  int		_price;
public:
  Color();
  Color(std::string, std::string);
  std::string	getName();
  std::string	getRGB();
  int		getPrice();
  void		setName(std::string);
  void		setRGB(std::string);
  void		setPrice(int);
  void		dump();
  virtual ~Color();
};

#endif /* _COLOR_HPP_ */
