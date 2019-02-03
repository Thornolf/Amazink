#ifndef _CART_HPP_
# define _CART_HPP_

#include <string>
#include <iostream>

#include "color.hpp"

class Cart {
private:
  int	_size;
  Color	*_items;
public:
  Cart();
  int	getSize() const;
  Color	*getItems() const;
  void	setSize(int);
  void	setItems(Color *);
  void	add(const Color&);
  void	removeByItem(Color);
  void	removeByIndex(int);
  void	clear();
  void	display() const;
  virtual ~Cart();  
};

#endif /* _CART_HPP_ */
