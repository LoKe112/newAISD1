#pragma once

#include <iostream>

namespace func {
    struct Node {
    public:
        int key;
        Node* left;
        Node* right;
        Node(int value) : key(value), left(nullptr), right(nullptr) {}
    };
    class SearchTree {
    private:
        Node* root;
        void clear(Node* node) {
            if (node) {
                clear(node->left);
                clear(node->right);
                delete node;
            }
        }
        Node* copy(Node* node) {
            if (!node) {
                return nullptr;
            }
            Node* new_node = new Node(node->key);
            new_node->left = copy(node->left);
            new_node->right = copy(node->right);
            return new_node;
        }
        void print(Node* node) {
            if (node) {
                print(node->left);
                std::cout << node->key << " ";
                print(node->right);
            }
        }
        bool insert(Node*& node, int value) {
            if (!node) {
                node = new Node(value);
                return true;
            }
            if (value < node->key) {
                return insert(node->left, value);
            }
            else if (value > node->key) {
                return insert(node->right, value);
            }
            return false;
        }
        bool contains(Node* node, int value) {
            if (!node) {
                return false;
            }
            if (value < node->key) {
                return contains(node->left, value);
            }
            else if (value > node->key) {
                return contains(node->right, value);
            }
            return true;
        }
        bool erase(Node*& node, int key) {
            if (!node) {
                return false;
            }
            if (key < node->key) {
                return erase(node->left, key);
            }
            else if (key > node->key) {
                return erase(node->right, key);
            }
            else {
                if (!node->left || !node->right) {
                    Node* temp = node;
                    node = (node->left) ? node->left : node->right;
                    delete temp;
                }
                else {
                    Node* temp = node->right;
                    while (temp->left) {
                        temp = temp->left;
                    }
                    node->key = temp->key;
                    erase(node->right, temp->key);
                }
                return true;
            }
        }
    }