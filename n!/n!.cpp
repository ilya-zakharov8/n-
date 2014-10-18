// n!.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <iostream>
using namespace std;

int* result(int*,int&, int, int);
int capacity(int);

int* result(int *a, int &capOfA, int num, int capOfNum){
	int capOfB = capOfA + capOfNum - 1;
	int *b = new int [capOfB];
	int k = 0;
	int *result;
	int capOfResult;
	for(int i = 0; i < capOfB; i++)
		b[i] = 0;
	while (k < capOfNum)
	{
		for(int i = 0; i < capOfA; i++)
			b[i + k] = a[i] * (num % 10) + b[i + k];
		k++;
		num = num / 10;
	}
	int rest;

	b[0] = b[0] % 10;
	rest = b[0] / 10;

	for(int i = 0; i < capOfB; i++){
		b[i] = (b[i] + rest) % 10;
		rest = b[i] / 10;
	}

	if(capOfB != capacity(rest)){
		capOfResult = capOfB + capacity(rest) - 1;
		result = new int[capOfResult];		
		for(int i = capOfB - 1; i < capOfResult; i++){
			result[i] = rest % 10;
			rest = rest / 10;
		}

		for(int i = 0; i < capOfB; i++)
			result[i] = b[i];
	}
	else{
		result = b;
		capOfResult = capOfB;
	}
	capOfA = capOfResult;
	return result;	
}
int capacity(int n){
	int k = 0;
	while(n > 0){
		if(n / 10 > 0){
			n = n / 10;
			k++;
		}
		else break;
	}
	return ++k;
}

int main()
{
	int n, cap;
	int *multiplication;	
	cin >> n;
	if(n == 0)
	{
		cout << 1;
	}
	else{
		cap = 1;
		multiplication = new int[cap];
		multiplication[0] = 1;		
		for(int i = 1; i <= n; i++){			
			multiplication = result(multiplication, cap, i, capacity(i));			
		}

		for(int i = 0; i < cap; i++)
			cout << multiplication[i];
	}	
}

