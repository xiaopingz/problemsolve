#pragma once

template<typename T1,typename T2>
class TemplateClass
{
public:
	TemplateClass(T1 i,T2 j);
	void showContents();

protected:
	T1	a;
	T2	b;
};

