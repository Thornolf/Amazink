#ifndef		_RECEIPT_HPP_
# define	_RECEIPT_HPP_

#include	"color.hpp"
#include	"cart.hpp"

class		Receipt{
private:
  int		_total;
  Cart		*_cart;
  std::string	_print;
  std::string	_fileName;
public:
  Receipt();
  Receipt(int, Cart*);
  int		getTotal() const;
  Cart		*getCart() const;
  std::string	getPrint() const;
  std::string	getFileName() const;
  void		setTotal(int);
  void		setCart(Cart*);
  void		setPrint(std::string);
  void		setFileName(std::string);
  void		calculingTotalAmount(const Cart &);
  void		display();
  void		printing();
  virtual	~Receipt();
};

#endif		/* _RECEIPT_HPP_ */
