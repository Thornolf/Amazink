#include	"receipt.hpp"

#include	<fstream>

Receipt::Receipt() {
}

Receipt::Receipt(int newTotal, Cart *newCart) {
  this->_total = newTotal;
  this->_cart = newCart;
}
int		Receipt::getTotal() const {
  return (this->_total);
}

Cart		*Receipt::getCart() const {
  return (this->_cart);
}

void		Receipt::setTotal(int newTotal) {
  this->_total = newTotal;
}

void		Receipt::setCart(Cart *newCart) {
  this->_cart = newCart;
}

void		Receipt::display() {
  std::cout << "\nYour ordered has been placed." << std::endl;
  std::cout << "You bought these items : " << std::endl;
  std::cout << "---------------------------------" << std::endl;
  for (int i = 0; i < this->_cart->getSize(); i++) {
    std::cout << "["<< i << "] ";
    this->_cart->getItems()[i].dump();
  }
  std::cout << "---------------------------------\n" << std::endl;
  std::cout << "The amount is " << this->_total << " $\n" << std::endl;
}

Receipt::~Receipt() {}
