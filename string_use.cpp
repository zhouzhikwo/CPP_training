// string_use.cpp: 定义控制台应用程序的入口点。
//

#define _CRT_SECURE_NO_WARNINGS
#define _CRT_NONSDTC_NO_DEPRECATE
#include <iostream>
#include <stdlib.h>
#include <string>
using namespace std;

int main()
{
	string str1;
	cout << "Input str1:";
	cin >> str1;
	cout << "Length of str1:" << str1.size() << endl;

	for (int i = 0; i < str1.size(); i++) {
		cout << str1[i] << ' ';
	}
	cout << endl;

	string str2 = "Visual", str3 = "C++";
	str2.append(1, ' ');
	str2 += str3;
	cout << str2 << endl;

	string str4 = "I am a student", str5 = "student", str6 = "teacher";
	if (str4.find(str5) != -1)
		cout << "find " << str5 << endl;
	if (str4.find(str6) == -1)
		cout << "not find " << str6 << endl;
	str5.swap(str6);
	cout << "str5:" << str5 << endl;
	cout << "str6:" << str6 << endl;

	system("pause");
    return 0;
}

