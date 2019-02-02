#include	<iostream>
#include	<fstream>
#include	<string>

#include	"color.hpp"
#include	"colorChart.hpp"
#include	"cart.hpp"

int		main(int argc, char **argv)
{
  (void)argc;
  (void)argv;
  ColorChart *color = new ColorChart("couleurs.txt");
  Cart *cart = new Cart();
  cart->addToCart(color->getArrayColor()[18]);
  cart->addToCart(color->getArrayColor()[1]);
  cart->addToCart(color->getArrayColor()[68]);
  cart->addToCart(color->getArrayColor()[35]);
  cart->addToCart(color->getArrayColor()[8]);
  for (int i = 0; i < cart->getSize(); i++) {
    cart->getItems()[i].dump();
  }
  return (0);
}
