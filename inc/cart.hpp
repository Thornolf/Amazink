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
  void	addToCart(const Color &);
  void	removeFromCartByItem(Color);
  void	removeFromCartByIndex(int);
  void	clearCart();
  void	displayCart() const;
  virtual ~Cart();
  
};

#endif /* _CART_HPP_ */
