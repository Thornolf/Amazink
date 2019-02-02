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

void	Cart::addToCart(const Color &newItem) {
  this->_size += 1;
  this->_items = new Color[this->_size];
  this->_items[this->_size - 1] = newItem;
  //TODO adding a new item to the cart
  // Need to dynamicaly allocate data 
}

void	Cart::removeFromCartByItem(Color itemToDelete) {
  (void)itemToDelete;
  //TODO find the item to delete and delete it from the array
}

void	Cart::removeFromCartByIndex(int index) {
  (void)index;
  //TODO find by index et delete it
}

void	Cart::clearCart() {
  //TODO delete the array & recreate it with a size of 0
}

void	Cart::displayCart() const {
  //TODO dump the cart properly
}

Cart::~Cart() {
}
