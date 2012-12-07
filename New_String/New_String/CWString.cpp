/*
* © Yuliya S. Artishevskaya
* e-mail: lapl4rt@gmail.com
*/

#define _CRT_SECURE_NO_WARNINGS
#include "String.h"
#include "CWString.h"
#include <string>


CWString::CountReferences::CountReferences (const char* sz_) {
	sz = new char[strlen(sz_) + 1];
	strcpy (sz, sz_); 
	count = 1;              
}

CWString::CountReferences::~CountReferences () { 
	delete[] sz; 
}       

CWString::CWString (const char* sz) { 
	pCountRef = new CountReferences (sz); 
}

CWString::CWString (const CWString &ns) {
	pCountRef = ns.pCountRef;
	pCountRef->count++;
}

CWString::~CWString () {
	if (pCountRef->count == 1)       
		delete pCountRef;            
	else                    
		pCountRef->count--;       
}

const CWString& CWString::operator = (const CWString& ns) {
	if (pCountRef == ns.pCountRef) 
		return *this;

	if (pCountRef->count == 1)        
		delete pCountRef;         
	else  
		pCountRef->count--;    

	pCountRef = ns.pCountRef;         
	pCountRef->count++;       
	return *this;            
}

char& CWString::operator[] (int index) {
	if (pCountRef->count > 1) {
		CountReferences *new_ref = new CountReferences (pCountRef->sz);
		--pCountRef->count;
		pCountRef = new_ref;
	}
	return pCountRef->sz[index];
}

const char CWString::operator[] (int index) const {
	return pCountRef->sz[index];
}

CWString::operator const char * () const {
	return pCountRef->sz;
}

void CWString::operator += (const char *_sz) {
	if (pCountRef->count > 1) {
		CountReferences *new_ref = new CountReferences (pCountRef->sz);
		--pCountRef->count;
		pCountRef = new_ref;
	}
	
	char *new_sz = new char [strlen (pCountRef->sz) + strlen (_sz) + 1];

	strcpy (new_sz, pCountRef->sz);
	strcat (new_sz, _sz);
	delete[] pCountRef->sz;
	pCountRef->sz = new_sz;
}


CWString operator + (const char *sz, const CWString &ns1) {
	CWString ns (sz);
	ns += ns1;
	return ns;
}

std::istream &operator >> (std::istream &in, CWString &ns) {
	std::string sz;
	in >> sz;
	ns = sz.c_str();
	return in;
}

std::ostream &operator << (std::ostream &out, const CWString &ns) {
	return out << ns.pCountRef->sz;
}
