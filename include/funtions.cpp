#pragma once

#include <iostream>
#include <chrono>

namespace func {
    template<typename T>
    struct Node {
    public:
        T key;
        Node<T>* left;
        Node<T>* right;
        Node() : key(0), left(nullptr), right(nullptr) {}
        Node(T value) : key(value), left(nullptr), right(nullptr) {}
    };
    template<typename T>
    class SearchTree {
    private:
        Node<T>* root;
        void clear(Node<T>* node) {
            if (node) {
                clear(node->left);
                clear(node->right);
                delete node;
            }
        }
        Node<T>* copy(Node<T>* node) {
            if (!node) {
                return nullptr;
            }
            Node<T>* new_node = new Node<T>(node->key);
            new_node->left = copy(node->left);
            new_node->right = copy(node->right);
            return new_node;
        }

        void print(Node<T>* node) {
            if (node) {
                print(node->left);
                std::cout << node->key << " ";
                print(node->right);
            }
        }
        bool insert(Node<T>*& node, T val) {
            if (!node) {
                node = new Node<T>(val);
                return true;
            }
            if (val < node->key) {
                return insert(node->left, val);
            }
            else if (val > node->key) {
                return insert(node->right, val);
            }
            return false;
        }
        bool contains(Node<T>* node, T val) {
            if (!node) {
                return false;
            }
            if (val < node->key) {
                return contains(node->left, val);
            }
            else if (val > node->key) {
                return contains(node->right, val);
            }
            return true;
        }
        bool erase(Node<T>*& node, T val) {
            if (!node) {
                return false;
            }
            if (val < node->key) {
                return erase(node->left, val);
            }
            else if (val > node->key) {
                return erase(node->right, val);
            }
            else {
                if (!node->left) {
                    Node<T>* temp = node->right;
                    delete node;
                    node = temp;
                }
                else if (!node->right) {
                    Node<T>* temp = node->left;
                    delete node;
                    node = temp;
                }
                else if (!node->left && !node->right) {
                    delete node;
                }
                else {
                    Node<T>* temp = node->right;
                    while (temp->left) {
                        temp = temp->left;
                    }
                    node->key = temp->key;
                    erase(node->right, temp->key);
                }
                return true;
            }
        }
    public:
        SearchTree() : root(nullptr) {}
        SearchTree(const SearchTree& other) : root(copy(other.root)) {}
        ~SearchTree() {
            clear(root);
        }
        Node<T>* get_root() const {
            return root;
        }

        SearchTree<T>& operator=(const SearchTree<T>& other) {
            if (this != &other) {
                clear(root);
                root = copy(other.root);
            }
            return *this;
        }

        SearchTree<T>& completion(size_t count) {
            size_t cur_count = 0;
            Random test_seed(0, 0, count * 10);
            while (cur_count != count) {
                if (insert(test_seed.generate_random_number()))
                    cur_count++;
            }
            return *this;
        }

        void print() {
            print(root);
            std::cout << std::endl;
        }
        bool insert(T val) {
            return insert(root, val);
        }
        bool contains(T val) {
            return contains(root, val);
        }
        bool erase(T val) {
            return erase(root, val);
        }
    };

    uint64_t time_now() {
        using namespace std::chrono;
        return duration_cast<milliseconds>(system_clock::now().time_since_epoch()).count();
    }

    template<typename T>
    SearchTree<T> symmetric(SearchTree<T>& set1, SearchTree<T>& set2) {
        SearchTree<T> result;
        std::function<void(Node<T>*)> temp = [&](Node<T>* node) {
            if (node != nullptr) {
                temp(node->left);
                if (!(set1.contains(node->key) && set2.contains(node->key)))
                    result.insert(node->key);
                temp(node->right);
            }
            };
        temp(set2.get_root());
        temp(set1.get_root());
        return result;

    }
}

