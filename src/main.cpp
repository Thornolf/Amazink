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
  std::string cmd;
  ColorChart *color = new ColorChart("couleurs.txt");
  Cart *cart = new Cart();
  (void)color;
  while (cmd != "exit" && cmd != "quit") {
    std::cin >> cmd;
    if (cmd == "clear") {
      cart->clear();
    }
    else if (cmd.find("add")!= std::string::npos) {
      std::cout << "Fnding Add" << std::endl;
    }
    else if (cmd.find("remove")!= std::string::npos) {
      std::cout << "Fnding Add" << std::endl;
    }
    else if (cmd == "display") {
      color->display();
    }
  }
  /*
  cart->addToCart(color->getArrayColor()[18]);
  cart->addToCart(color->getArrayColor()[1]);
  cart->addToCart(color->getArrayColor()[68]);
  cart->addToCart(color->getArrayColor()[35]);
  cart->addToCart(color->getArrayColor()[8]);
  std::cout << "--- BEFORE DELETION | size : " << cart->getSize() << std::endl;
  cart->displayCart();
  cart->removeFromCartByIndex(3);
  std::cout << "--- AFTER DELETION | size : " << cart->getSize() << std::endl;
  cart->displayCart();
  */
  return (0);
}
