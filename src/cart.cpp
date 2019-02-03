#include "cart.hpp"

Cart::Cart() {
  this->_size = 0;
  this->_items = new Color[this->_size];
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
    this->_items[this->_size - 1] = newItem; 
  } else {
    this->_size += 1;
    Color *tmp = new Color[this->_size + 1];
    for (int index = 0; index < this->_size; index++) {
      tmp[index] = this->_items[index];
    }
    delete[] this->_items;
    this->_items = tmp;
    this->_items[this->_size - 1] = newItem;
  }
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
  if (index < this->_size || index >= 0) {
    Color *tmp = new Color[newSize + 1];
    for (int i = 0, j =  0; i < this->_size; i++, j++) {
      if (j == index)
	j++;
      tmp[i] = this->_items[j];
    }
    this->_size = newSize;
    delete[] this->_items;
    this->_items = tmp;
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
  for (int i = 0; i < this->_size; i++) {
    this->_items[i].dump();
  }
}

Cart::~Cart() {
  delete[] this->_items;
}
