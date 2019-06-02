#define _CRT_SECURE_NO_WARNINGS

#include "MyString.h"
#include <string.h>
String::String()
{
	cout << "无参构造函数" << endl;
}
	
String::String(const char * src)
{
	if (!src) return;
	cout << "有参构造函数" << endl;
	int len = strlen(src) + 1;
	this->pString = new char[len];
	this->Size = len;
	strcpy(this->pString,src);
}

String::String(const String & cp)
{

	cout << "拷贝构造函数" << endl;
}

String::~String()
{
	cout << "析构函数" << endl;
	if (this->pString)
	{
		delete[] this->pString;
		this->pString = NULL;
	}
}

String& String::operator=(const char* src)
{
	int len = strlen(src) + 1;
	if (!this->pString)
	{
		this->pString = new char[len];
		memset(pString, 0,len);
		strcpy(this->pString, src);
	}
	else 
	{
		if (strcmp(this->pString,src) == 0)
		{
			return *this;
		}
		memset(this->pString,0, len);
		strcpy(this->pString,src);
	}
	return *this;
}

String& String::operator=(String& src)
{
	if (!this->pString)
	{
		this->pString = new char[src.Size];
		memset(pString, 0, Size);
		strcpy(this->pString, src.pString);
	}
	else
	{
		if (strcmp(this->pString, src.pString) == 0)
		{
			return *this;
		}
		memset(this->pString, 0, src.Size);
		strcpy(this->pString, src.pString);
	}
	return *this;

}

ostream& operator<<(ostream& cout, String & src)
{
	cout << src.pString;
	return cout;
}
