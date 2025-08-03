#include<iostream>
#include<string.h>
using namespace std;

class STR
{
char *ptr;
public:
STR() 					//Default constructor
{
this->ptr=NULL;
}

STR(const char *s)                    //parametrized constructor
{
if(!s)
{
this->ptr=NULL;
return;
}
this->ptr=new char[strlen(s)+1];
if(!this->ptr) cout<<"Memory Full !!!";

if(this->ptr)
{
strcpy(this->ptr,s);
}
}

STR(const STR &other)            //copy constructor
{
this->ptr=NULL;
if(other.ptr)
{
this->ptr = new char[strlen(other.ptr)+1];
}
if(this->ptr)
{
strcpy(this->ptr,other.ptr);
}
}

STR(STR &&other)              //move constructor
{
this->ptr=other.ptr;
other.ptr=NULL;
}

STR & operator=(STR const &other) 	//copy-assignment operator        STR & operator=(STR &other, STR *this)  f.=(i,&f)
{
if(this->ptr) delete [] this->ptr;
this->ptr=NULL;

if(other.ptr)
{
this->ptr = new char[strlen(other.ptr)+1];
if(this->ptr)
{
strcpy(this->ptr,other.ptr);
}
}
return *this;
}

STR & operator=(STR &&other)     //Move-assignment operator
{
if(this->ptr) delete [] this->ptr;
this->ptr=NULL;     //  <-- We should have a habit of assigning the ptr to NULL after releasing the memory.
this->ptr=other.ptr;
other.ptr=NULL;
return *this;
}

// By writing const we are promising that the address 
// you are giving us we wont change the values using 
// the pointer we are using to access your data.
STR & operator=(const char *s)   
{
if(this->ptr) delete [] this->ptr;
this->ptr = NULL;
if(s) this->ptr = new char[strlen(s)+1];
if(this->ptr) strcpy(this->ptr,s);
return *this;
}

//string1.<(string2,&string1);
int operator<(const STR &other)
{
if(this->ptr==NULL && other.ptr==NULL) return 0;
if(this->ptr == NULL) return 1;
if(other.ptr == NULL) return 0;  
if(strcmp(this->ptr,other.ptr) < 0) return 1;
else return 0;
}

int operator<=(const STR &other)
{
if(this->ptr==NULL && other.ptr==NULL) return 1;
if(this->ptr == NULL) return 1;
if(other.ptr == NULL) return 0;  
if(strcmp(this->ptr,other.ptr) <= 0) return 1;
else return 0;
}

int operator>(const STR &other)
{
if(this->ptr==NULL && other.ptr==NULL) return 0;
if(this->ptr == NULL) return 0;
if(other.ptr == NULL) return 1;  
if(strcmp(this->ptr,other.ptr) > 0) return 1;
else return 0;
}

int operator>=(const STR &other)
{
if(this->ptr==NULL && other.ptr==NULL) return 1;
if(this->ptr == NULL) return 0;
if(other.ptr == NULL) return 1;  
if(strcmp(this->ptr,other.ptr) >= 0) return 1;
else return 0;
}

int operator==(const STR &other)
{
if(this->ptr==NULL && other.ptr==NULL) return 0;
if(this->ptr == NULL) return 1;
if(other.ptr == NULL) return 0;  
if(strcmp(this->ptr,other.ptr) == 0) return 1;
else return 0;
}

int operator!=(const STR &other)
{
if(this->ptr==NULL && other.ptr==NULL) return 0;
if(this->ptr == NULL) return 1;
if(other.ptr == NULL) return 1;  
if(strcmp(this->ptr,other.ptr) != 0) return 1;
else return 0;
}

~STR()
{
if(this->ptr) delete [] this->ptr;
}

friend ostream &operator<<(ostream &, STR &);
};

ostream &operator<<(ostream &other1, STR &other2)
{
if(other2.ptr==NULL) return other1;   
other1<<other2.ptr;   
return other1;
}

int main()
{
return 0;
}
