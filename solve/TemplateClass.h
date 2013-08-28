#pragma once

template<typename T1,typename T2>
class TemplateClass
{
public:
	TemplateClass(T1 i,T2 j):a(i),b(j){};
	void showContents(){
		std::cout<<"<"<<a<<","<<b<<">"<<std::endl;
	};

protected:
	T1	a;
	T2	b;
};


template<class T>
void printBinary(T a)
{
	for ( int i=sizeof(a)*8-1;i>=0;--i )
	{
		if ( (a>>i)&1 )
			std::cout<<'1';
		else
			std::cout<<'0';
		if ( i%8==0 )
			std::cout<<' ';
	}
	std::cout<<std::endl;
}