#include<iostream>
#include<string.h>
using namespace std;

class STR
{
char *ptr;

public:
STR()
{
this->ptr=NULL;
}

STR(const char *s)
{
if(!s)
{
this->ptr=NULL;
return;
}
this->ptr=new char[strlen(s)+1];
if(!this->ptr) return;
if(this->ptr)
{
strcpy(this->ptr,s);
}
}

STR(const STR &other)
{
this->ptr=NULL;
if(other.ptr)
{
this->ptr = new char[strlen(other.ptr)+1];
}
if(!this->ptr) return; //Low-memory case
if(this->ptr)
{
strcpy(this->ptr,other.ptr);
}
}

STR(STR &&other)
{
this->ptr=other.ptr;
other.ptr=NULL;
}

STR & operator=(STR const &other)
{
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

STR & operator=(STR &&other)
{
this->ptr=other.ptr;
other.ptr=NULL;
return *this;
}


STR & operator=(const char *s)
{
if(this->ptr) delete [] this->ptr;
this->ptr = NULL;
if(s) this->ptr = new char[strlen(s)+1];
if(this->ptr) strcpy(this->ptr,s);
return *this;
}

~STR()
{
if(this->ptr) delete this->ptr;
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
