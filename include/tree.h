#ifndef TREE_INCLUDE_TREE_H
#define TREE_INCLUDE_TREE_H

#include <iostream>
#include <stack>

class Set {
	struct Node {
		int key;
		Node* left;
		Node* right;

		Node(int key, Node* left = nullptr, Node* right = nullptr): key(key),left(left), right(right){}
	};

	Node* _root;
	size_t _size;

    Node* copy_helper(Node* original_node) {
        if (!original_node)
            return nullptr;

        Node* new_node = new Node(original_node->key);
        new_node->left= copy_helper(original_node->left);
        new_node->right= copy_helper( original_node->right);

        return new_node;
    }

    void delete_helper(Node* node) {
        if (!node)
            return;

        delete_helper(node->left);
        delete_helper(node->right);
        delete node;
    }

    void print_helper(Node* node) const{
        if (!node)
            return;

        print_helper(node->left);
        std::cout << node->key << " ";
        print_helper(node->right);
    }

    Node* insert_helper(Node* node, int key) {
        if (!node) {
            return new Node(key);
        }

        if (key < node->key) {
             node->left= insert_helper(node->left, key);
        }
        else if (key > node->key) {
            node->right=insert_helper(node->right, key);
        }

        return node;
    }

    bool contains_helper(Node* node, int key) const{
        if (!node)
            return false;

        if (key==node->key) {
            return true;
        }
        else if (key < node->key) {
            return contains_helper(node->left, key);
        }

        return contains_helper(node->right, key);
    }

    Node* erase_helper(Node* node, int key) {
        if (!node)
            return nullptr;

        if (key < node->key) {
            node->left= erase_helper(node->left, key);
        }
        else if (key > node->key) {
            node->right= erase_helper(node->right, key);
        }
        else {
            if (!node->left && !node->right) {
                delete node;
                return nullptr;
            }
            else if (!node->left) {
                Node* tmp = node->right;
                delete node;
                return tmp;
            }
            else if (!node->right) {
                Node* tmp = node->left;
                delete node;
                return tmp;
            }
            Node* temp = min_value_node(node->right);
            node->key = temp->key;
            node->right = erase_helper(node->right, temp->key);
        }
        return node;
    }

    Node* min_value_node(Node* node) {
        Node* current = node;

        while (current && current->left != nullptr) {
            current = current->left;
        }

        return current;
    }


public:
    class Iterator {
        std::stack<Node*> node_stack;
        Node* current;
    public:
        Iterator(Node* root) {
            current = root;
            while (current != nullptr) {
                node_stack.push(current);
                current = current->left;
            }
        }
    };

    Set() : _root(nullptr), _size(0) {}

    Set(const Set& other) {
        _root=copy_helper(other._root);
        _size = other._size;
    }

    ~Set() {
        delete_helper(_root);
        _size = 0;
    }

    Set& operator=(const Set& other) {
        if (this != &other) {
            delete_helper(_root);
            _root = copy_helper(other._root);
            _size=other._size;
        }
        return *this;
    }

    void print() {
        print_helper(_root);
        std::cout << std::endl;
    }

    bool insert(int key) {
        if (contains(key)) 
            return false;
        _root = insert_helper(_root, key);
        ++_size;
        return true;
    }

    bool contains(int key) {
        return contains_helper(_root, key);
    }

    bool erase(int key) {
        if (!contains(key))
            return false;
        _root = erase_helper(_root, key);
        --_size;
        return true;
    }

    size_t  size() const {
        return _size;
    }

    Node* root() const {
        return _root;
    }

    Iterator begin() {
        return Iterator(_root);
    }

    Iterator end() {
        return Iterator(nullptr);
    }
};

#endif