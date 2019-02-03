#include	<iostream>
#include	<fstream>
#include	<string>

#include	"color.hpp"
#include	"colorChart.hpp"
#include	"cart.hpp"

static void	wrongCommand(void) {
  std::cout << "The command is incorrect. Please type help to have the full command list." << std::endl;
}

static int	isValid(int size, int value) {
  if (value < 0 || value >= size) {
    wrongCommand();
    return (-1);
  }
  return (value);
}

static void	helper(void) {
  std::cout << "liste des commandes" << std::endl; //TODO A finir
}

int		main(int argc, char **argv)
{
  (void)argc;
  (void)argv;
  std::string cmd;
  ColorChart *color = new ColorChart("couleurs.txt");
  Cart *cart = new Cart();
  (void)color;
  while (cmd != "exit" && cmd != "quit") {
    std::getline(std::cin, cmd);
    if (cmd == "clear") {
      cart->clear();
    }
    else if (cmd.find("add")!= std::string::npos) {
      int selector = isValid(color->getSize(), std::stoi(cmd.substr(cmd.find(" ") + 1)));
      if (selector != -1)
	cart->add(color->getArrayColor()[selector]);
    }
    else if (cmd.find("remove")!= std::string::npos) {
      int selector = isValid(color->getSize(), std::stoi(cmd.substr(cmd.find(" ") + 1)));
      if (selector != -1)
	cart->removeByIndex(selector);
    }
    else if (cmd.find("display")!= std::string::npos) {
      if (cmd.substr(cmd.find(" ") + 1 ) == "color")
	color->display();
      else if (cmd.substr(cmd.find(" ") + 1 ) == "cart")
	cart->display();
      else
	wrongCommand();
    }
    else if (cmd == "check out") {
      std::cout << "JE PAYE BORDEL" << std::endl;
    }
    else if (cmd == "help") {
      helper();
    }
    else
      wrongCommand();
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
