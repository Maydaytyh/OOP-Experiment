/*
* @Author: CucumicsMelon
* @Date: 2019-04-01 10:57:22
 * @Last Modified by: CucumicsMelon
 * @Last Modified time: 2019-04-02 08:56:53
*/
#include <bits/stdc++.h>
#include"MyString.h"
using namespace std;
int main()
{
	MyString s1("China"), s2;
	MyString s3(s1);
	cout << s3 << endl;
	s2 = "Love";
	cout << "I "+ s2 + s1;

	int pos = s1.Find('a'); // pos is 4, or -1 if  'a'  is not found.

	int a = 1, b = 3;
	MyString my = s2.Mid(a, b); // a represents starting position, b represents the length. So Mid can get a substring.
}