#pragma once
#include <iostream>

class NewString {    
	class  CountReferences {                                
		public:
			CountReferences (const char *);
			~CountReferences ();
			int count;               
			char* sz;
	};     

	public:
		NewString (const char *str = "");
		NewString (const NewString &);
		~NewString ();
		const NewString& operator = (const NewString &);
		
		void operator += (const NewString &);
		friend NewString operator + (const char *, const NewString &);
		
		char& operator[] (int);
		const char operator[] (int) const;
		operator const char* () const;
		operator NewString* () const;
		void resize (int);
		friend std::istream& operator >> (std::istream &, NewString &);
		friend std::ostream& operator << (std::ostream &, const NewString &);

	private:
		CountReferences* pCountRef;
};
