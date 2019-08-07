#include<iostream>
#include"Customer.h"
using namespace std;

Customer::Customer(string name, int age)
{
	m_strName = name;
	m_iAge = age;
}

void Customer::printfInfo()const
{
	cout << "ÐÕÃû£º" << m_strName << endl;
	cout << "ÄêÁä£º" << m_iAge << endl;
	cout << endl;
}