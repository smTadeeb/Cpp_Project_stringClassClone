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







~STR()
{
if(this->ptr) delete this->ptr;
}

friend ostream &operator<<(ostream &, STR &);
};

ostream &operator<<(ostream &other1, STR &other2)
{
other1<<other2.ptr;
return other1;
}

int main()
{
STR a("GOOD");
STR g="Sheikh Tadeeb";
STR j(NULL);
STR r = NULL;
cout<<a<<endl;
cout<<g<<endl;
cout<<j<<endl;
cout<<r<<endl;

return 0;
}
