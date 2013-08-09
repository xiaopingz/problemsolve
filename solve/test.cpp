#if 0

#include "TemplateClass.h"
#include <iostream>

int toInt(std::string str)
{
	int len = str.length();
	int sum = 0;
	for ( int i=0;i<len;++i )
	{
		if ( str[i]>='0' && str[i]<='9')
		{
			str[i]	-=	'0';
			for ( int j=0;j<i;++j )
			{
				str[j]	*= 10;
			}
		}
		else return 0;
	}
	for ( int i=0;i<len;++i )
		sum	+= str[i];
	return sum;
}

void main()
{
	std::string nMale;
	std::cout<<"Please input the numbers of Male & Female to match:"<<std::endl;
	std::cin>>nMale;
	int m, f;
	m = toInt(nMale);
	//f = toInt(nFemale);
	std::cout<<m<<std::endl;

	//enum egg {a,b,c};  
	//enum egg test; //在这里你可以简写成egg test;  

	//test = c; //对枚举变量test进行赋予元素操作，这里之所以叫赋元素操作不叫赋值操作就是为了让大家明白枚举变量是不能直接赋予算数值的，例如(test=1;)这样的操作都是不被编译器所接受的，正确的方式是先进行强制类型转换例如(test = (enum egg) 0;)！  

	//if (test==c)  
	//{  
	//	std::cout <<"枚举变量判断:test枚举对应的枚举元素是c" << std::endl;  
	//}  

	//if (test==2)  
	//{  
	//	std::cout <<"枚举变量判断:test枚举元素的值是2" << std::endl;  
	//}  

	//std::cout << a << "|" << b << "|" << test <<std::endl;  

	//test = (enum egg) 0; //强制类型转换  
	//std::cout << "枚举变量test值改变为:" << test <<std::endl; 

	/*TemplateClass<int,int> a(1,2);
	a.showContents();
	TemplateClass<int,char> b(1,70);
	b.showContents();
	TemplateClass<double,char> c(3.2,'c');
	c.showContents();*/
}


#endif