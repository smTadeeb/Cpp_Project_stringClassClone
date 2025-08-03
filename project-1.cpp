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
if(!this->ptr) cout<<"Memory Full !!!";
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
cout<<"Phase-1"<<endl;
STR a("GOOD");
STR g="Sheikh Tadeeb";
STR j(NULL);
STR r = NULL;
cout<<a<<endl;
cout<<g<<endl;
cout<<j<<endl;
cout<<r<<endl;


cout<<"Phase-2"<<endl;
STR z=a;
STR y=j;
cout<<z<<endl;
cout<<y<<endl;
STR i(std::move(a));    
STR h=std::move(j);    
cout<<"String value for i: "<<i<<endl;           
cout<<"String value for h: "<<h<<endl;          

cout<<endl<<"Phase-3"<<endl;
STR f;
f=i;
cout<<"String against f is: "<<f<<endl;
STR e;
e=std::move(f);
cout<<"String against e is: "<<e<<endl;
cout<<"String against f is: "<<f<<endl;

return 0;
}
