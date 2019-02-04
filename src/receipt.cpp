#include	"receipt.hpp"

#include	<fstream>
#include	<ctime>

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

std::string	Receipt::getPrint() const {
  return (this->_print);
}

std::string	Receipt::getFileName() const {
  return (this->_fileName);
}
void		Receipt::setTotal(int newTotal) {
  this->_total = newTotal;
}

void		Receipt::setCart(Cart *newCart) {
  this->_cart = newCart;
}

void		Receipt::setPrint(std::string newPrint) {
  this->_print = newPrint;
}

void		Receipt::setFileName(std::string newFileName) {
  this->_fileName = newFileName;
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
  printing();
  std::cout << "Your receipt was printed in the file " << this->_fileName << std::endl;
}

void		Receipt::printing() {
  this->_fileName = "receipt-";
  this->_print = "Your ordered has been placed\n";
  this->_print += "You bought these items : \n";
  this->_print += "---------------------------------\n";
  for (int i = 0; i < this->_cart->getSize(); i++) {
    this-> _print +=  "[";
    this->_print += std::to_string(i);
    this->_print += "] ";
    this->_print += this->_cart->getItems()[i].getName();
    this->_print += " | ";
    this->_print += this->_cart->getItems()[i].getRGB();
    this->_print += " | ";
    this->_print += this->_cart->getItems()[i].getPrice();
    this->_print += " $";
  }
  this->_print += "---------------------------------\n\n";
  this->_print +="The amout is : ";
  this->_print += std::to_string(this->_total);
  this->_print += "\n";
  std::time_t result = std::time(nullptr);
  std::asctime(std::localtime(&result));
  this->_fileName += std::to_string(result);
  this->_fileName += ".txt";
  std::ofstream outfile (this->_fileName);
  outfile << this->_print << std::endl;
  outfile.close();
}
Receipt::~Receipt() {}
