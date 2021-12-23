#include <iostream>
#include <locale>
#include "TList.h"


using namespace std;

void main()
{
	setlocale(LC_ALL, "Russian");
	TList<double> list;
	list.insFirst(2);
	list.insFirst(12);
	for (int i = 0; i < 11; i++)
	{
		list.insFirst(i);
	}
	list.insFirst(13);
	list.insFirst(4);
	list.insFirst(8);
	list.PrintList();
	list.delElements();
	list.PrintList();
}