// SortowanieLiniowe.cpp : Defines the entry point for the console application.
//

// Sortowania o czasie liniowym
// Zliczanie: O(N) zawsze
//	Pozycyjne Radix sort : O(N) zawsze
// Kubełkowe
//
//http://eduinf.waw.pl/inf/alg/003_sort/0020.php
//http://eduinf.waw.pl/inf/alg/003_sort/0022.php
//http://eduinf.waw.pl/inf/alg/003_sort/0024.php
//http://eduinf.waw.pl/inf/alg/003_sort/0023.php
//http://eduinf.waw.pl/inf/alg/003_sort/0021.php
//

#include <iostream>

using namespace std;

struct element
{
	int dana;
	int dana2;
	element *next;

	void push(int dana, int dana2);
	void get();
	void get2();

	element();
};

element::element() : dana(0), next(nullptr) {}

void element::push(int _dana, int _dana2) {
	dana = _dana;
	dana2 = _dana2;
}

void element::get() {
	cout << dana << endl;
}

void element::get2() {
	cout << dana << "," << dana2 << endl;
}

void sortuj(element *_tablica_wejsciowa, int _rozmiar, int _max_element, element *_tablica_wyjsciowa) {
	
	// Utwoprzenie tablicy pomocniczej - przechowywane są tu ilości wystąpieć wartości z TAB. WEJSCIOWEJ
	int *tmp = new int [_max_element + 1];

	// Wyzerowanie pomocniczej tablicy
	for (int i = 0; i < _max_element + 1; i++)
	{
		tmp[i] = 0;
	}
	// Wpisanie liczby wystąpień wartości z TAB. WEJSCIOWEJ
	for (int i = 0; i < _rozmiar; i++)
	{
		int x = _tablica_wejsciowa[i].dana;
		tmp[x]++;
	}
	// Ustalenie pozycji kolejnych liczb - zaczynamy od elementu 1
	for (int i = 1; i < _max_element + 1; i++)
	{
		tmp[i] += tmp[i - 1];
	}
	// Sortowanie odbywa się od końca aby zachować kolejność 
	for (int i = _rozmiar - 1; i >= 0; i--)
	{
		int a = _tablica_wejsciowa[i].dana;
		int b = tmp[a];
		_tablica_wyjsciowa[b-1] = _tablica_wejsciowa[i];
		tmp[a]--;
	}

}

// Poszukiwanie największego elementu w tablicy wejsciowej 
int max_element(element *_tablica_wejsciowa, int _rozmiar) {
	int max = _tablica_wejsciowa[0].dana;
	for (int i = 0; i < _rozmiar; i++)
	{
		if (max < _tablica_wejsciowa[i].dana)
		{
			max = _tablica_wejsciowa[i].dana;
		}
	}
	return max;
}

//
//struct lista
//{
//	element *glowa;
//	void push(int dana);
//	void show();
//	void pop();
//
//	lista();
//};
//
//lista::lista() : glowa(nullptr) {}
//
//void lista::push(int _dana)
//{
//	element *nowy = new element;
//
//	nowy->dana = _dana;
//	nowy->next = glowa;
//	glowa = nowy;
//}
//
//void lista::show()
//{
//	element * tmp;
//	tmp = this->glowa;
//	if (tmp)
//	{
//		do {
//			cout << tmp->dana << " ";
//			tmp = tmp->next;
//		} while (tmp != nullptr);
//		cout << endl;
//	}
//	else {
//		cout << endl;
//	}
//}
//
//void lista::pop()
//{
//	element * tmp;
//	tmp = this->glowa;
//	glowa = tmp->next;
//	delete tmp;
//}


int main()
{ 
	/*tablica[0].push(1);
	tablica[0].show();*/

	
	//tablica[0].push(1,2);
	int rozmiar, // n - ilosc liczb czyli rozmiar tablicy
		a, b, //para liczb
		opcja;

	cin >> rozmiar; 

	element *tablica_wejsciowa = new element[rozmiar];
	element *tablica_wyjsciowa = new element[rozmiar];

	for (int i = 0; i < rozmiar; i++)
	{

		cin >> a >> b;
		tablica_wejsciowa[i].push(a, b);
	}

	//odnalezienie najwiekszej wartosci w podanym zbiorze liczb
	int _max_element = max_element(tablica_wejsciowa, rozmiar);

	sortuj(tablica_wejsciowa, rozmiar, _max_element, tablica_wyjsciowa);

	cin >> opcja;
	switch (opcja)
	{
	case 0:
		for (int i = 0; i < rozmiar; i++)
		{
			tablica_wyjsciowa[i].get();
		}
		break;
	case 1:
		for (int i = 0; i < rozmiar; i++)
			//for (int i = rozmiar - 1; i >= 0; i--)
		{
			tablica_wyjsciowa[i].get2();
		}
	default:
		break;
	}

	return 0;
}
