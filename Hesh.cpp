#include "List.h"
#include<time.h>
#include <Windows.h>

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	srand(time(0));
	const int size = 10;
	int mas[size];
	genRandMas(mas, size);
	cout << "Исходный массив:" << endl;
	for (int i = 0; i < size; i++)
	{
		cout << mas[i] << " ";
	}
	const int hesh1 = 7; 



#pragma region PryamoyeS
	List* hesh_tab1[hesh1]{ };
	for (int i = 0; i < size; i++)
	{
		int num = mas[i] % hesh1;
		add(hesh_tab1[num], mas[i]);
	}
	cout << endl<<"Списки:" << endl;
	for (int i = 0; i < hesh1; i++)
	{
		cout << i << ": ";
		print_list(hesh_tab1[i]);
		cout << endl;
	}
	//Количество коллизий
	int kolliz = 0;
	for (int i = 0; i <hesh1; i++)
	{
		List* tmp = hesh_tab1[i];
		if (tmp)
			kolliz--;
		while(tmp){
			kolliz++;
			tmp = tmp->next;
		}
	}
	cout << "Количество коллизий: " << kolliz << endl ;
	
	//Поиск в методе прямого связывания
	cout << "Введите элемент который нужно найти: ";
	int chislo;
	cin >> chislo;
	int hesh_chislo = chislo % hesh1;
	int cnt = 0;
	if (hesh_tab1[hesh_chislo] == NULL) cout << "Элемент не найден!" << endl;
	while (hesh_tab1[hesh_chislo])
	{
		cnt++;
		if (chislo == hesh_tab1[hesh_chislo]->var) {
			cout << "Элемент найден!" << endl;
			cout << cnt<<"-й элемент в " << hesh_chislo << "-м списке" << endl;
			break;
		}
		hesh_tab1[hesh_chislo] = hesh_tab1[hesh_chislo]->next;
		if (hesh_tab1[hesh_chislo] == NULL) cout << "Элемент не найден!" << endl;
	}

#pragma endregion Метод прямого связывания

	cout << "----------------------------------------------------------------------" << endl;


#pragma region SQRT
	int hesh_tab2[hesh1]{};
	int kolliz2 = 0;
	//Вставка элемента (квадратичные пробы)
	for (int i = 0; i < size; i++)
	{
		int h = mas[i] % hesh1;
		int d = 1;
		while (true)
		{
			if (hesh_tab2[h] == 0) {
				hesh_tab2[h] = mas[i];
				break;
			}
			else
			{
				kolliz2++;
			}
			if (d >= hesh1) break;
			h += d;
			if (h >= hesh1) h -= hesh1;
			d += 2;
		}
	}

	//Вывод 
	cout << "Квадратичные пробы" << endl;
	for (int i = 0; i < hesh1; i++)
	{
		cout.width(2);
		cout << i << " ";
	}
	cout << endl << endl;
	for (int i = 0; i < hesh1; i++)
	{
		cout.width(2);
		cout << hesh_tab2[i] << " ";
	}
	cout << endl << "Количество коллизий: " << kolliz2 << endl;

	//Поиск в методе квадратичных проб
	cout << endl<<"Введите число для поиска: " << endl;
	int x = 0;
	cin >> x;
	int h = x% hesh1;
	int d = 1;
	while (true)
	{
		if (x == hesh_tab2[h]) {
			cout <<"Элемент найден" << endl;
			cout<<"index: " << h << endl;
			break;
		}
		if (d >= hesh1) {
			cout<<"Элемент не найден!" << endl;
			break; 
		}
		h += d;
		if (h >= hesh1) h -= hesh1;
		d += 2;
	}
#pragma endregion Метод открытой адресации

	cout << "----------------------------------------------------------------------" << endl;


#pragma region Line
	int hesh_tab3[hesh1]{};
	int kolliz3 = 0;

	//Вставка элемента (линейные пробы)
	for (int i = 0; i < size; i++)
	{
		int h = mas[i] % hesh1;
		while (true)
		{
			if (hesh_tab3[h] == 0) {
				hesh_tab3[h] = mas[i];
				break;
			}
			else
			{
				kolliz3++;
			}
			h++;
			if (h >= hesh1) break;
		}
	}

	//Вывод 
	cout << "Линейные пробы" << endl;
	for (int i = 0; i < hesh1; i++)
	{
		cout.width(2);
		cout << i << " ";
	}
	cout << endl << endl;
	for (int i = 0; i < hesh1; i++)
	{
		cout.width(2);
		cout << hesh_tab3[i] << " ";
	}
	cout << endl << "Количество коллизий: " << kolliz2 << endl;

	//Поиск в линейных пробах
	cout << endl << "Введите число для поиска: " << endl;
	x = 0;
	cin >> x;
	h = x % hesh1;
	while (true)
	{
		if (x == hesh_tab3[h]) {
			cout << "Элемент найден" << endl;
			cout << "index: " << h << endl;
			break;
		}
		h++;
		if (h >= hesh1) {
			cout << "Элемент не найден!" << endl;
			break;
		}
	}
#pragma endregion Метод линейных проб

	cout << endl << "Размер хэш-таблицы = " << hesh1 << endl;
	cout << "Количество элементов = " << size << endl << endl;
	cout << "Кол-во коллизий (метод линейных проб) - " << kolliz3 << endl;
	cout << "Кол-во коллизий (метод квадратичных проб) - " << kolliz2 << endl;
}
