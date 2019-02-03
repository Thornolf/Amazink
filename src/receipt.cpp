#include	"receipt.hpp"

Receipt::Receipt() {
}

int		Receipt::getTotal() const {
  return (this->_total);
}

Cart		Receipt::getCart() const {
  return (this->_cart);
}

std::string	Receipt::getPrint() const {
  return (this->_print);
}

void		Receipt::setTotal(int newTotal) {
  this->_total = newTotal;
}

void		Receipt::setCart(Cart newCart) {
  this->_cart = newCart;
}

void		Receipt::setPrint(std::string newPrint) {
  this->_print = newPrint;
}

void		Receipt::displayReceipt() const {
  //TODO display the receipt directlty into the cmd prompt
}

void		Receipt::printReceipt() {
  //TODO create a .txt with all the information about the receipt
}

Receipt::~Receipt() {}
