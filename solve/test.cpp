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
	//enum egg test; //����������Լ�д��egg test;  

	//test = c; //��ö�ٱ���test���и���Ԫ�ز���������֮���Խи�Ԫ�ز������и�ֵ��������Ϊ���ô������ö�ٱ����ǲ���ֱ�Ӹ�������ֵ�ģ�����(test=1;)�����Ĳ������ǲ��������������ܵģ���ȷ�ķ�ʽ���Ƚ���ǿ������ת������(test = (enum egg) 0;)��  

	//if (test==c)  
	//{  
	//	std::cout <<"ö�ٱ����ж�:testö�ٶ�Ӧ��ö��Ԫ����c" << std::endl;  
	//}  

	//if (test==2)  
	//{  
	//	std::cout <<"ö�ٱ����ж�:testö��Ԫ�ص�ֵ��2" << std::endl;  
	//}  

	//std::cout << a << "|" << b << "|" << test <<std::endl;  

	//test = (enum egg) 0; //ǿ������ת��  
	//std::cout << "ö�ٱ���testֵ�ı�Ϊ:" << test <<std::endl; 

	/*TemplateClass<int,int> a(1,2);
	a.showContents();
	TemplateClass<int,char> b(1,70);
	b.showContents();
	TemplateClass<double,char> c(3.2,'c');
	c.showContents();*/
}


#endif