/*
* © Yuliya S. Artishevskaya
* e-mail: lapl4rt@gmail.com
*/

#ifndef CWSTRING_H
#define CWSTRING_H
#include <iostream>

class CWString : public String {    
	class  CountReferences {                                
		public:
			CountReferences (const char *sz);
			~CountReferences ();
			int count;               
			char* sz;
	};     

	public:

		CWString (const char *str = "");
		CWString (const CWString &ns);
		~CWString ();
		const CWString& operator = (const CWString &ns);

		void operator += (const char *sz);
		friend CWString operator + (const char *, const CWString &ns);
		
		char& operator[] (int index);
		const char operator[] (int index) const;
		operator const char* () const;
		operator CWString* () const;

		friend std::istream& operator >> (std::istream &in, CWString &ns);
		friend std::ostream& operator << (std::ostream &out, const CWString &ns);

	private:
		CountReferences* pCountRef;
};
#endif