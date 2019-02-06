#ifndef		_RECEIPT_HPP_
# define	_RECEIPT_HPP_

#include	"color.hpp"
#include	"cart.hpp"

class		Receipt{
private:
  int		_total;
  Cart		*_cart;
public:
  Receipt();
  Receipt(int, Cart*);
  int		getTotal() const;
  Cart		*getCart() const;
  void		setTotal(int);
  void		setCart(Cart*);
  void		calculingTotalAmount(const Cart &);
  void		display();
  virtual	~Receipt();
};

#endif		/* _RECEIPT_HPP_ */
