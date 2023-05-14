// Copyright 2021 NNTU-CS
#include  <iostream>
#include  <fstream>
#include  <locale>
#include  <cstdlib>
#include  "bst.h"

BST<std::string> makeTree(const char* filename) {
  BST<std::string> tree;
  std::ifstream file(filename);
  std::string line;
  std::string text;
  std::string push;
  while (std::getline(file, line)) {
    text = text + line + " ";
  }
  for (auto a : text) {
    if (isalpha(a)) {
      a = tolower(a);
      push += a;
    } else {
      tree.addElement(push);
      push = "";
    }
  }
  file.close();
  return tree;
}
