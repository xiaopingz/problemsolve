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

