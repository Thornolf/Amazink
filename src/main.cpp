#include	<iostream>
#include	<fstream>
#include	<string>

#include	"color.hpp"
#include	"colorChart.hpp"
#include	"cart.hpp"
#include	"receipt.hpp"

static void	displayStargate(void) {
  std::string line;
  std::ifstream file("stargate.txt");
  if (file.is_open()) {
    while(getline(file, line)) {
      std::cout << line << std::endl;
    }
  file.close();
  }
  else {
    std::cout << "Unable to open file" << std::endl;
  }
}

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
  std::cout << "\tList of every command :" << std::endl;
  std::cout << "\"exit\" or \"quit\" will terminate the program." << std::endl;
  std::cout << "\"add |integer|\" or \"remove |integer|\" will add or remove an item from your cart." << std::endl;
  std::cout << "\"check out\" will generate the receipt." << std::endl;
  std::cout << "\"display color|cart\" will display the color chart or the content of your cart." << std::endl;
  std::cout << "\"help\" will generate this message again. Very useful.\n" << std::endl;
}

int		main(int argc, char **argv)
{
  std::cout << "\t\t--- Welcome to Amazink ! ---\n" << std::endl;
  std::cout << "This program was made by Remi GIACOMETTI & Quentin BAUDET" << std::endl;
  std::cout << "Please, don't break anything.\n" << std::endl;
  helper();
  (void)argc;
  (void)argv;
  std::string cmd;
  ColorChart *color = new ColorChart("couleurs.txt");
  Cart *cart = new Cart();
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
      if (cart->getSize() > 0) {
	Receipt *receipt = new Receipt(cart->getSize(), cart);
	receipt->display();
	cart->clear();
      } else {
	std::cout << "You need to add an item to buy something." << std::endl;
      }
    }
    else if (cmd == "stargate") {
      displayStargate();
    }
    else if (cmd == "help") {
      helper();
    }
    else
      wrongCommand();
  }
  return (0);
}
