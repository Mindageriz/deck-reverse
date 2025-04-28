// Dekas, reverse(); 
#include <iostream>
using namespace std;

#define MAXSIZE 5	// Apibreziamas deko dydis

template <typename T>	// Sablonine klase, dekas gales saugoti ivarius duomenu tipus
class Dekas {		 	// Deko klase
private:
	int first, last;	// FIRST ir LAST deko elementu indeksai
	T deck[MAXSIZE];	// Sukuriamas deko statinis masyvas
public:
	Dekas() {			// Konstruktorius
		first = -1;		// FIRST pradine reiksme, -1 (Dekas tuscias)
		last = -1;		// LAST pradine reiksme, -1 (Dekas tuscias)
	}

	void pushBack(T value) {
		if (isFull()) {
			cout << "Dekas yra pilnas!" << endl;
			return;
		}
		else if (isEmpty()){
			first++;
			last++;
			deck[last] = value;
		}
		else {
			last++;
			if (last == MAXSIZE) {
				last = 0;
			}
			deck[last] = value;
		}
	}

	void pushFront(T value) {
		if (isFull()) {
			cout << "Dekas yra pilnas!" << endl;
			return;
		}
		else if (isEmpty()) {
			first++;
			last++;
			deck[first] = value;
		}
		else {
			first--;
			if (first == -1) {
				first = first + MAXSIZE;
			}
			deck[first] = value;
		}
	}

	void popBack() {
		if (isEmpty()) {
			cout << "Negalima istrinti elemento, nes dekas tuscias!" << endl;
		}
		else if (first == last){
			first = -1;
			last = -1;
		}
		else {
			last--;
			if (last == -1) {
				last = last + MAXSIZE;
			}
		}
	}

	void popFront() {
		if (isEmpty()) {
			cout << "Negalima istrinti elemento, nes dekas tuscias!" << endl;
		}
		else if (first == last) {
			first = -1;
			last = -1;
		}
		else {
			first++;
			if (first == MAXSIZE) {
				first = 0;
			}
		}
	}

	T front() {
		return deck[first];
	}

	T back() {
		return deck[last];
	}

	bool isEmpty() {
		return (first == -1 || last == -1);
	}

	bool isFull() {
		return ( (last-first+1 == MAXSIZE) || (last-first+1 == 0) );
	}

	void reverse() {
		if (isEmpty()) {
			cout << "Nera ka apverst, dekas tuscias!" << endl;
		}
		else if (first == last) {
			cout << "Nera ka apverst, deke tik vienas elementas!" << endl;
		}
		else {
			Dekas<T>* temp = new Dekas<T>;
			int length;
			if (last >= first) {
				length = last - first + 1;
			}
			else {
				length = MAXSIZE - first + last + 1;
			}
			for (int i = 0; i < length; i++) {
				temp->pushFront(front());
				popFront();
			}
			for (int i = 0; i < length; i++) {
				pushBack(temp->front());
				temp->popFront();
			}
			delete temp;
		}
	}

	void display() {
		if (isEmpty()) {
			cout << "Nera ka rodyt, dekas tuscias!" << endl;
		}
		else {
			int length;
			if (last >= first) {
				length = last - first + 1;
			}
			else {
				length = MAXSIZE - first + last + 1;
			}
			for (int i = 0; i < length; i++) {
				T temp = front();
				popFront();
				pushBack(temp);
				cout << temp << " ";
			}
		}
	}

};


int main() {
	Dekas<int> D;
	D.pushBack(1);
	D.pushBack(2);
	D.pushBack(3);
	D.pushBack(4);
	D.pushBack(5);

	

	D.reverse();

	
	

	

	D.display();

	return 0;
}