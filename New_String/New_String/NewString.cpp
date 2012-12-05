#define _CRT_SECURE_NO_WARNINGS
#include "NewString.h"
#include <string>


NewString::CountReferences::CountReferences (const char* sz_) {
	sz = new char[strlen(sz_) + 1];
	strcpy (sz, sz_); 
	count = 1;              
}

NewString::CountReferences::~CountReferences () { 
	delete[] sz; 
}       

NewString::NewString (const char* sz) { 
	pCountRef = new CountReferences (sz); 
}

NewString::NewString (const NewString &ns) {
	pCountRef = ns.pCountRef;
	pCountRef->count++;
}

NewString::~NewString () {
	if (pCountRef->count == 1)       
		delete pCountRef;            
	else                    
		pCountRef->count--;       
}

const NewString& NewString::operator = (const NewString& ns) {
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

char& NewString::operator[] (int index) {
	if (pCountRef->count > 1) {
		CountReferences *new_ref = new CountReferences (pCountRef->sz);
		--pCountRef->count;
		pCountRef = new_ref;
	}
	return pCountRef->sz[index];
}

const char NewString::operator[] (int index) const {
	return pCountRef->sz[index];
}

NewString::operator const char * () const {
	return pCountRef->sz;
}

void NewString::operator += (const char *_sz) {
	if (pCountRef->count > 1) {
		CountReferences *new_ref = new CountReferences (pCountRef->sz);
		--pCountRef->count;
		pCountRef = new_ref;
	}
	
	char *new_sz = new char [strlen (pCountRef->sz) + strlen (_sz) + 1];
	strcpy (new_sz, pCountRef->sz);
	delete[] pCountRef->sz;

	pCountRef->sz = new_sz;
	strcat (pCountRef->sz, _sz);
}


NewString operator + (const char *sz, const NewString &ns1) {
	NewString ns (sz);
	ns += ns1;
	return ns;
}

std::istream &operator >> (std::istream &in, NewString &ns) {
	std::string sz;
	in >> sz;
	ns = sz.c_str();
	return in;
}

std::ostream &operator << (std::ostream &out, const NewString &ns) {
	return out << ns.pCountRef->sz;
}
