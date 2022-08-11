#include <iostream>
#include <iterator>

using namespace std;

template<class T>
class Predicate
{
public:
	virtual bool operator () (T x) = 0;
};

template <class T>
class Positive : public Predicate<T>
{
public:
	virtual bool operator () (T x)
	{
		return x > 0;
	}
};

template <class T>
class Negative : public Predicate<T>
{
public:
	virtual bool operator () (T x)
	{
		return x < 0;
	}
};

template <class T>
class Even : public Predicate<T>
{
public:
	virtual bool operator () (T x)
	{
		return x % 2 == 0;
	}
};

template <class T>
class Odd : public Predicate<T>
{
public:
	virtual bool operator () (T x)
	{
		return x % 2 != 0;
	}
};

template<class T>
T* Search_End(T* begin, T* end, T* begin2, T* end2)
{
	T* from = begin;
	T* from2 = begin2;
	T* found = end;
	for (T* from = begin; from < end; from++)
	{
		if (*from == *from2)
		{
			from2++;
		}
		else
		{
			from2 = begin2;
		}
		if (*from2 == *(end2 - 1))
		{
			found = from - 2;
			from2 = begin2;
		}
	}
	return found;
}

template<class T>
T* Search_End_If(T* begin, T* end, T* begin2, T* end2, Predicate<T>& p)
{
	T* from = begin;
	T* from2 = begin2;
	T* found = end;
	for (T* from = begin; from < end; from++)
	{
		if (p(*from))
		{
			if (*from == *from2)
			{
				from2++;
			}
			else
			{
				from2 = begin2;
			}
			if (*(from + 1) != *(end2 - 1))
			{
				from2 = begin2;
			}
			if (*from2 == *(end2 - 1))
			{
				found = from;
				from2 = begin2;
			}
		}
	}
	return found;
}

void Print(int* v, const int size)
{
	cout << "Array = { ";
	for (int i = 0; i < size; i++)
		cout << v[i] << ' ';
	cout << "}" << endl;
}

template<class T>
int Index(T* begin, T* end, int* found)
{
	int c = 0;
	T* from = begin;
	for (T* from = begin; from < end; from++)
	{
		if (from == found)
		{
			break;
		}
		c++;
	}
	return c;
}

int main()
{
	const int n = 14;
	int a[n] = { -4, 1, 5, -1, 2, 3, -4, 9, -7, -6, -1, 2, 3, -4 };
	Print(a, n);

	const int k = 4;
	int a2[k] = { -1, 2, 3, -4 };
	Print(a2, k);

	const int p = 16;
	int a3[p] = { -1, 3, 2, -4, 2, 3, 2, -4, -1, -4, 2, 3, -1, -4, -1, 3 };
	Print(a3, p);

	const int l = 2;
	int b[l] = { 2, 3 };
	int c[l] = { -1, -4 };
	int d[l] = { 2, -4 };
	int e[l] = { -1, 3 };

	int* begin = &a[0];
	int* end = &a[n];
	int* begin2 = &a2[0];
	int* end2 = &a2[k];
	int* begin3 = &a3[0];
	int* end3 = &a3[p];
	int* begB = &b[0];
	int* endB = &b[l];
	int* begC = &c[0];
	int* endC = &c[l];
	int* begD = &d[0];
	int* endD = &d[l];
	int* begE = &e[0];
	int* endE = &e[l];

	int* found = Search_End(begin, end, begin2, end2);

	if (found == end)
		cout << "Sequence a2 not found" << endl;
	else
		cout << "Last occurrence of a sequence a2 in a1 found at position: " << Index(begin, end, found) << endl;

	Predicate<int>* pos = new Positive<int>();
	int* FoundPositive = Search_End_If(begin3, end3, begB, endB, *pos);

	if (FoundPositive == end3)
		cout << "Sequence a2 not found" << endl;
	else
		cout << "Last occurrence of a sequence a2 in a1 found at position(Positive): " << Index(begin, end, FoundPositive) << endl;

	Predicate<int>* neg = new Negative<int>();
	int* FoundNegative = Search_End_If(begin3, end3, begC, endC, *neg);

	if (FoundNegative == end3)
		cout << "Sequence a2 not found" << endl;
	else
		cout << "Last occurrence of a sequence a2 in a1 found at position(Negative): " << Index(begin3, end3, FoundNegative) << endl;

	Predicate<int>* even = new Even<int>();
	int* FoundEven = Search_End_If(begin3, end3, begD, endD, *even);

	if (FoundEven == end3)
		cout << "Sequence a2 not found" << endl;
	else
		cout << "Last occurrence of a sequence a2 in a1 found at position(Even): " << Index(begin3, end3, FoundEven) << endl;

	Predicate<int>* odd = new Odd<int>();
	int* FoundOdd = Search_End_If(begin3, end3, begE, endE, *odd);

	if (FoundOdd == end3)
		cout << "Sequence a2 not found" << endl;
	else
		cout << "Last occurrence of a sequence a2 in a1 found at position(0dd): " << Index(begin3, end3, FoundOdd) << endl;

}