#include <iostream>
#include <ctime>
#include "TArrayTable.h"
#include "TScanTable.h"
#include "TSortTable.h"
#include "TArrayHash.h"
#include "TListHash.h"
#include "TAVLTree.h"

using std::cout;
using std::cin;
using std::endl;

int main()
{
	srand(time(0));
	int tabsize, keyrange; // размер таблицы, диапазон ключей
	int tabtype = 1; // тип таблицы
	int op = 1; // выбор операции
	int key; // ключ для поиска, удаления
	
	cout << "Enter number of records in the table: ";
	cin >> tabsize;
	cout << "Enter the range of the keys for the records: ";
	cin >> keyrange;
	
	while (tabtype != 0)
	{
		cout << "Enter the type of the table: 1. Unsorted\n2.Sorted\n3. Hash (array)\n4. Hash (list)\n5. Tree\n6. AVL Tree\n\nEnter 0 to exit" << endl;
		switch (tabtype)
		{
		case 1:
		{
			while (op != 0)
			{
				cout << "Enter the operation: 1. Create\n2. Save into the file\n3. Find\n4. Insert\n5. Delete\n\nEnter 0 to end to go back to the table list" << endl;
				switch (op)
				{
				case 1:
				{
					TArrayTable tab(tabsize);
				} break;
				case 2:
				{
					tab.printTab();
				} break;
				case 3:
				{
					cout << "Enter the key to find" << endl;
					tab.findRec(key);
					// запись (не) найдена
					// вывести эффективность
				}
				case 4:
				{
					tab.insertRec();
					// запись успешно вставлена
				}
				case 5:
				{
					cout << "Enter the key to delete" << endl;
					tab.deleteRec(key);
					// запись успешно удалена
				}
				}
				cout << endl;
			}
		} break;
		case 2:
		{
			//
		} break;
		case 3:
		{
			//
		} break;
		case 4:
		{
			//
		} break;
		case 5:
		{
			//
		} break;
		case 6:
		{
			//
		} break;
		case 0:
		{
			break;
		} break;
		default: cout << "There is no such option" << endl;
		}
		cout << endl;
	}
}