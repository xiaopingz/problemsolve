#include "TemplateClass.h"


template<typename T1,typename T2>
TemplateClass<T1,T2>::TemplateClass(T1 i,T2 j)
:a(i),b(j)
{
}


TemplateClass<typename T1,typename T2>
void TemplateClass<T1,T2>::showContents()
{
	std::cout<<"<"<<a<<","<<b<<">"<<std::endl;
}
