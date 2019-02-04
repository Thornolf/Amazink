
#include "cart.hpp"

Cart::Cart() {
  this->_size = 0;
  this->_items = new Color[this->_size];
}

Cart::Cart(const Cart &obj) {
  this->_size = obj.getSize();
  this->_items = obj.getItems();
}
int	Cart::getSize() const {
  return (this->_size);
}

Color	*Cart::getItems() const {
  return (this->_items);
}


void	Cart::setSize(int newSize) {
  this->_size = newSize;
}


void	Cart::setItems(Color *newItems) {
  this->_items = newItems;
}

void	Cart::add(const Color &newItem) {
  if (this->_size == 0) {
    this->_size = 1;
    this->_items = new Color[this->_size + 1];
  } else {
    this->_size += 1;
    Color *tmp = new Color[this->_size + 1];
    for (int index = 0; index < this->_size; index++) {
      tmp[index] = this->_items[index];
    }
    delete[] this->_items;
    this->_items = tmp;
  }
  this->_items[this->_size - 1] = newItem;
  std::cout << "You added " << newItem.getName() << " to your cart." << std::endl;
  std::cout << "You have now " << this->_size;
  if (this->_size > 1)
    std::cout << " items in your cart." << std::endl;
  else
    std::cout << " item in your cart." << std::endl;
}

void	Cart::removeByItem(Color itemToDelete) {
  int newSize = this->_size - 1;
  Color *tmp = new Color[newSize + 1];
  for (int i = 0, j =  0; i < this->_size; i++, j++) {
    if (this->_items[j].getName() == itemToDelete.getName())
      j++;
    tmp[i] = this->_items[j];
  }
    this->_size = newSize;
    delete[] this->_items;
    this->_items = tmp;
}

void	Cart::removeByIndex(int index) {
  int newSize = this->_size - 1;
  if (index < this->_size && index >= 0) {
    Color *tmp = new Color[newSize + 1];
    std::cout << "You removed " << this->_items[index].getName() << " from your cart." << std::endl;
    for (int i = 0, j =  0; i < this->_size; i++, j++) {
      if (j == index)
	j++;
      tmp[i] = this->_items[j];
    }
    this->_size = newSize;
    delete[] this->_items;
    this->_items = tmp;
  }
  else {
    std::cout << "The item requested is not in the cart." << std::endl;
  }
}

void	Cart::clear() {
  this->_size = 0;
  Color *tmp = new Color[this->_size + 1];
  delete[] this->_items;
  this->_items = tmp;
  std::cout << "Your cart has been emptied." << std::endl;
}

void	Cart::display() const {
  if (this->_size == 0)
    std::cout << "The cart is empty." << std::endl;
  for (int i = 0; i < this->_size; i++) {
    std::cout << "[" << i << "] ";
    this->_items[i].dump();
  }
}

Cart::~Cart() {
  delete[] this->_items;
}
