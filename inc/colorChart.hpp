#ifndef		_COLOR_CHART_HPP_
# define	_COLOR_CHART_HPP_

#include	<string>
#include	<iostream>

#include	"color.hpp"

class		ColorChart {
private:
  int		_size;
  Color		*_arrayColor;
public:
  ColorChart();
  ColorChart(std::string);
  int		getSize() const;
  Color		*getArrayColor() const;
  void		setSize(int);
  void		setArrayColor(Color *);
  void		display();
  virtual ~ColorChart();
};

#endif		/* _COLOR_CHART_HPP_ */
