#include "funtions.cpp"
#include <gtest/gtest.h>
#include <iostream>



using namespace tree;
using namespace std;

TEST(CreatedSet, Copying1) {
	Node<int>* test1 = new Node<int>(1);
	Node<int>* test2 = new Node<int>(4);
	Node<int>* test_res = new Node<int>(2, test1, test2);
	Set<int> a(test_res);
	Set<int> b(1);
	b = a;
	b.print();
}

TEST(CreatedSet, CopyConstructor) {
	Node<int>* test1 = new Node<int>(1);
	Node<int>* test2 = new Node<int>(4);
	Node<int>* test_res = new Node<int>(2, test1, test2);
	Set<int> a(test_res);
	Set<int> b(a);
	b.print();
}
TEST(CreatedSet, InsertElement1) {
	Node<int>* test1 = new Node<int>(1);
	Node<int>* test2 = new Node<int>(4);
	Node<int>* test_res = new Node<int>(2, test1, test2);
	Set<int> a(test_res);
	a.insert(5);
	a.print();
}
TEST(CreatedSet, InsertElement2) {
	Node<int>* test1 = new Node<int>(1);
	Node<int>* test2 = new Node<int>(4);
	Node<int>* test_res = new Node<int>(2, test1, test2);
	Set<int> a(test_res);
	a.insert(3);
	a.print();
}
TEST(CreatedSet, InsertElement3) {
	Node<int>* test1 = new Node<int>(1);
	Node<int>* test2 = new Node<int>(4);
	Node<int>* test_res = new Node<int>(2, test1, test2);
	Set<int> a(test_res);
	a.insert(0);
	a.print();
}
TEST(CreatedSet, ContainElement) {
	Node<int>* test1 = new Node<int>(1);
	Node<int>* test2 = new Node<int>(4);
	Node<int>* test_res = new Node<int>(2, test1, test2);
	Set<int> a(test_res);
	a.insert(0);
	if (a.contain(0)) {
		cout << "this set contain 0." << endl;
	}
	else cout << "this set is not contain 0." << endl;
}
TEST(CreatedSet, NotContainElement) {
	Node<int>* test1 = new Node<int>(1);
	Node<int>* test2 = new Node<int>(4);
	Node<int>* test_res = new Node<int>(2, test1, test2);
	Set<int> a(test_res);
	a.insert(0);
	if (a.contain(5)) {
		cout << "this set contain 5." << endl;
	}
	else cout << "this set is not contain 5." << endl;
}
TEST(CreatedSet, EraseElement1) {
	Set<int> a(1);
	a.insert(0);
	a.insert(5);
	a.insert(3);
	a.insert(2);
	a.insert(4);
	a.insert(6);
	a.print();
	a.erase(5);
	a.print();
}
TEST(CreatedSet, EraseElement2) {
	Set<int> a(1);
	a.insert(0);
	a.insert(5);
	a.insert(3);
	a.print();
	a.erase(5);
	a.print();
	a.erase(3);
	a.print();
	a.erase(0);
	a.print();
}