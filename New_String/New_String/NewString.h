#pragma once
#include <iostream>

class NewString {    
	class  CountReferences {                                
		public:
			CountReferences (const char *sz);
			~CountReferences ();
			int count;               
			char* sz;
	};     

	public:
		NewString (const char *str = "");
		NewString (const NewString &ns);
		~NewString ();
		const NewString& operator = (const NewString &ns);
		
		void operator += (const char *sz);
		friend NewString operator + (const char *, const NewString &ns);
		
		char& operator[] (int index);
		const char operator[] (int index) const;
		operator const char* () const;
		operator NewString* () const;

		friend std::istream& operator >> (std::istream &in, NewString &ns);
		friend std::ostream& operator << (std::ostream &out, const NewString &ns);

	private:
		CountReferences* pCountRef;
};
