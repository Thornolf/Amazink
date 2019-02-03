#ifndef		_RECEIPT_HPP_
# define	_RECEIPT_HPP_

#include	"color.hpp"

class		Receipt{
private:
  int		_total;
  Cart		_cart;
  std::string	_print;
public:
  Receipt();
  int		getTotal() const;
  Cart		getCart() const;
  std::string	getPrint() const;
  void		setTotal(int);
  void		setCart(Cart);
  void		setPrint(std::string);
  void		calculingTotalAmount(const Cart &);
  void		displayReceipt() const;
  void		printReceipt();
  virtual	~Receipt();
};

#endif		/* _RECEIPT_HPP_ */
