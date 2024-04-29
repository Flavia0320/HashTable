#include <iostream>
#include <list>
#include <fstream>
#include <vector>
#include <conio.h>

typedef std::pair<int, std::string> input;

class HashTable {
private:
	const int tableSize = 10;
	std::vector<std::list<input>> table;

	int functieDispersie(int key) {
		return key % tableSize;
	}
public:
	HashTable() : table(tableSize) {};
	void read(const std::string& cale, int& nrPerechi) {
		std::ifstream f(cale);
		int key;
		std::string value;
		f >> nrPerechi;
		for(int i=1;i<=nrPerechi;i++) {
			f >> key >> value;
			insert(key, value);
		}
		f.close();
	}
	void insert(int key, std::string value) {
		int index = functieDispersie(key);
		input entry(key, value);
		table[index].push_back(entry);
	}

	std::string search(int key) {
		int index = functieDispersie(key);
		for (const input& elemente : table[index]) {
			if (elemente.first == key)
				return elemente.second;
		}
		return "Key not found.";
	}

	void display() {
		for (int i = 0; i < tableSize; i++) {
			std::cout << "Lista " << i << ": ";
			for (const input& elem : table[i]) {
				std::cout << "(" << elem.first << ", " << elem.second << ") ";
			}
			std::cout << "\n";
		}
	}

};







int main() {
	HashTable myTable;
	int nrPerechi;
	int option;
	int newKey;
	std::string mesaj;
	std::string newValue;
	do {
		std::cout << "Meniu:\n";
		std::cout << "1. Citire tabel.\n";
		std::cout << "2. Functie de inserare.\n";
		std::cout << "3. Functie de cautare.\n";
		std::cout << "4. Afisare tabel.\n";
		std::cout << "5. Exit.\n";
		std::cout << "Alegeti o optiune.\n";
		std::cin >> option;
		switch (option)
		{
		case 1:
			myTable.read("date.txt", nrPerechi);
			std::cout << "Press any key to continue...";
			_getch();
			break;
		case 2:
			std::cout << "Introdu o noua pereche: \n";
			std::cin >> newKey >> newValue;
			myTable.insert(newKey, newValue);
			std::cout << "Press any key to continue...";
			_getch();
			break;
		case 3:
			std::cout << "Introdu cheia elementului cautat: \n";
			std::cin >> newKey;
			mesaj= myTable.search(newKey);
			std::cout << mesaj << "\n";
			std::cout << "Press any key to continue...";
			_getch();
			break;
		case 4:
			myTable.display();
			std::cout << "Press any key to continue...";
			_getch();
		default:
			std::cout << "Optiune invalida.\n";
			break;
		}
	} while (option != 5);
	return 0;
}
