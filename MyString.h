#pragma once
#ifndef __cplusplus
extern"C" {
#endif // !__cplusplus


#include <iostream>
using namespace std;
class String {

	
	public:
		friend	ostream& operator<< (ostream&cout, String& src);
		String();
		String(const char* src);
		String(const String& cp);

		String& operator= (const char* src);
		String& operator= (String& src);
		~String();
	private:
		char* pString;
		int Size;
	};

#ifndef __cplusplus
}
#endif // __cplusplus



