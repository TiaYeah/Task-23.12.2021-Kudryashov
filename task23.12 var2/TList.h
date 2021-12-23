#pragma once
#include<iostream>
#include <cstddef>
using namespace std;

template <class T>
struct TNode
{
	T Value;
	TNode* pNext;
};


template <class T>
class TList
{
protected:
	TNode<T>* pFirst;
public:
	TList()
	{
		pFirst = NULL;
	}
	~TList()
	{
		while (pFirst != NULL)
		{
			TNode<T>* pDel = pFirst;
			pFirst = pFirst->pNext;
			delete pDel;
		}
	}

	void PrintList()
	{
		TNode<T>* cur = pFirst;
		while (cur->pNext != NULL)
		{
			cout << cur->Value << " ";
			cur = cur->pNext;
		}
		cout << cur->Value << " " << endl;
	}
	
	void delElements()
	{
		TNode<T>* del;
		TNode<T>* prev = NULL;
		TNode<T>* cur = pFirst;
		while (cur->pNext != NULL)
		{
			if (prev == NULL)
			{
				if ((int)(cur->Value) % 2 == 0)
				{
					del = pFirst;
					pFirst = pFirst->pNext;
					cur = pFirst;
					delete del;
				}
				else
				{
					prev = cur;
					cur = cur->pNext;
				}
			}
			else
				if ((int)(cur->Value) % 2 == 0)
				{
					del = cur;
					prev->pNext = del->pNext;
					cur = prev->pNext;
					delete del;
				}
				else
				{
					prev = cur;
					cur = cur->pNext;
				}
		}
		if ((int)(cur->Value) % 2 == 0)
		{
			del = cur;
			prev->pNext = del->pNext;
			cur = prev->pNext;;
			delete del;
		}

	}

	void insFirst(T el)
	{
		TNode<T>* newFirst = new TNode<T>;
		newFirst->Value = el;
		newFirst->pNext = pFirst;
		pFirst = newFirst;
	}

};

