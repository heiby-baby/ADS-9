// Copyright 2021 NNTU-CS
#ifndef INCLUDE_BST_H_
#define INCLUDE_BST_H_
#include <iostream>
#include <fstream>
#include <string>
#include <cctype>
#include <algorithm>

struct Node {
  std::string word;
  int count;
  Node* left;
  Node* right;
  explicit Node(const std::string& word) : word(word), count(1), left(nullptr), right(nullptr) {}
};
template<typename T>
class BST {
 private:
  Node* root;
  Node* insertNode(Node* root, const std::string& word) {
    if (root == nullptr) {
      return new Node(word);
    }
    if (word < root->word) {
      root->left = insertNode(root->left, word);
    } else if (word > root->word) {
      root->right = insertNode(root->right, word);
    } else {
      root->count++;
    }
    return root;
  }
  Node* searchNode(Node* root, const std::string& word) {
    if (root == nullptr || root->word == word) {
      return root;
    }
    if (word < root->word) {
      return searchNode(root->left, word);
    } else {
      return searchNode(root->right, word);
    }
  }
  int getDepth(Node* root) {
    if (root == nullptr) {
      return 0;
    }
    int leftDepth = getDepth(root->left);
    int rightDepth = getDepth(root->right);
    return std::max(leftDepth, rightDepth) + 1;
  }

 public:
  BST() : root(nullptr) {}
  void addElement(const std::string& word) {
    root = insertNode(root, word);
  }
  int depth() {
    return getDepth(root) - 1;
  }
  int search(const std::string& word) {
    Node* node = searchNode(root, word);
    return (node != nullptr) ? node->count : 0;
  }
};
#endif  // INCLUDE_BST_H_
