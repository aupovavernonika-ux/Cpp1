//Вариант 2
//1) Написать программу, которая, используя метод бинарного поиска,
//выполняет поиск в упорядоченном по возрастанию массиве.Массив
//предварительно сортируется методом «пузырька».
#include <iostream>
using namespace std;
const int SIZE = 10;
int main() {
	setlocale(LC_ALL, "RU");
	int nums[SIZE];
	int a, b, t;
	for (t = 0; t < SIZE; t++) nums[t] = rand();
	cout << "Исходный массив: ";
	for (t = 0; t < SIZE; t++) cout << nums[t] << ' ';
	cout << '\n';
	for (a = 1; a < SIZE; a++) {
		for (b = SIZE - 1; b >= a; b--) {
			if (nums[b - 1] > nums[b]) {
				t = nums[b - 1];
				nums[b - 1] = nums[b];
				nums[b] = t;
			}
		}
	}
	cout << "Отсортированный массив: ";
	for (t = 0; t < SIZE; t++) cout << nums[t] << ' ';
	cout << '\n';
	int searchValue;
	cout << "\nВведите число для поиска: ";
	cin >> searchValue;
	int lt = 0;
	int rt = SIZE - 1;
	int index = -1;
	while (lt <= rt) {
		int mid = lt + (rt - lt) / 2;
		if (nums[mid] == searchValue) {
			index = mid;
			break;
		}
		else if (nums[mid] < searchValue) {
			lt = mid + 1;
		}
		else {
			rt = mid - 1;
		}
	}
	if (index >= 0) {
		cout << "Элемент " << searchValue << " найден в ячейке с индексом " << index << endl;
	}
	else {
		cout << "Элемент " << searchValue << " не найден в массиве." << endl;
	}
	return 0;
}

//2) Написать программу, которая проверяет, является ли введенная с
//клавиатуры строка шестнадцатеричным числом (включая отрицательные).
#include <iostream>
#include <string>
using namespace std;

int main() {
	setlocale(LC_ALL, "RU");
	string str;
	cout << "Введите строку без пробелов: ";
	getline(cin, str);

	if (str.empty()) {
		cout << "Ошибка: введена пустая строка." << endl;
		return 0;
	}

	bool isHex = true;      
	bool hasNonZero = false; 
	int start = 0;           
	bool negative = false;   

	if (str[0] == '-') {
		negative = true;
		start = 1; 
		if (str.length() == 1) {
			isHex = false;
		}
	}

	for (int i = start; i < str.length(); i++) {
		char c = str[i];
		if (!((c >= '0' && c <= '9') ||
			(c >= 'A' && c <= 'F') ||
			(c >= 'a' && c <= 'f'))) {
			isHex = false;
			break;           
		}
		
		if (c != '0') {
			hasNonZero = true;
		}
	}
	if (negative && !hasNonZero) {
		isHex = false;
	}

	if (isHex && !str.empty())
		cout << "Строка \"" << str << "\" является шестнадцатеричным числом.";
	else
		cout << "Строка \"" << str << "\" не является шестнадцатеричным числом." << endl;
	return 0;
}







































