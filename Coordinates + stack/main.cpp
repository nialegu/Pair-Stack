#include <iostream>

using namespace std;
const int SIZE = 6;
void pair_input(pair<int, int>);

class Stack {
protected:
	double s[SIZE];
	int top = 0;
public:
	void push(double n) {
		if (top < SIZE)
			s[top++] = n;
		else
			cout << "Stack is overflow!" << endl;
	}
	double pop() {
		if (top > 0)
			return s[--top];
		else {
			cout << "Stack is empty!\n";
			return 0;
		}
	}
};

class pairStack : public Stack {
public:
	void push(pair<int, int> p) {
		if (top + 1 < SIZE) {
			Stack::push(p.first);
			Stack::push(p.second);
		}
		else
			cout << "Stack is overflow!" << endl;
	}
	pair<int, int> pop() {
		if (top-1 > 0)
			return pair<int, int>(static_cast<int>(Stack::pop()), static_cast<int>(Stack::pop()));
		else {
			cout << "Stack is empty! ";
			return pair<int, int>(0, 0);
		}
	}
	
};

int main() {
	pairStack point;

	pair<int, int> f(12, 31);
	point.push(f);
	pair<int, int> s(41, 323);
	point.push(s);
	pair<int, int> t(34534, 54);
	point.push(t);
	point.push(t);

	pair_input(point.pop());
	pair_input(point.pop());
	pair_input(point.pop());
	pair_input(point.pop());

	return 0;
}

void pair_input(pair<int, int> p) {
	cout << p.first << ", " << p.second << endl;
}