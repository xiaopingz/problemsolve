#if 1

//#define WIN32_LEAN_AND_MEAN
//#include <WinSock2.h>
//#include <Ws2tcpip.h>
//#include "TemplateClass.h"
#include <iostream>
//#pragma comment(lib, "Ws2_32.lib")
#include <time.h>
typedef unsigned long long ULONGLONG;	

ULONGLONG	count1InAnInteger(ULONGLONG n)
{
	ULONGLONG	iNum = 0;
	while(n)
	{
		iNum += (n%10==1)?1:0;
		n /= 10;
	}
	return iNum;
}

//从1到n的所有整数中，1出现的次数
ULONGLONG	sum1(ULONGLONG n)
{
	ULONGLONG	iCount = 0,i;
	for ( i=1;i<=n;++i )
	{
		iCount += count1InAnInteger(i);
	}
	return iCount;
}

ULONGLONG	sum2(ULONGLONG n)
{
	ULONGLONG	iCount = 0;
	ULONGLONG	iFactor = 1;
	ULONGLONG	iLower = 0;
	ULONGLONG	iCurrent = 0;
	ULONGLONG	iHigher = 0;
	while( n/iFactor )
	{
		iLower	=	n - n/iFactor*iFactor;
		iCurrent	=	(n/iFactor)%10;
		iHigher	=	n/(iFactor*10);
		switch(iCurrent)
		{
		case 0:
			iCount	+=	iHigher*iFactor;
			break;
		case 1:
			iCount	+=	iLower+1+iHigher*iFactor;
			break;
		default:
			iCount	+=	(iHigher+1)*iFactor;
			break;
		}
		iFactor	*=	10;
	}
	return iCount;
}

class CObject{
public:
	virtual void serialize()
	{
		std::cout<<"CObject::serialize()\n"<<std::endl;
	}
};
class CDocument:public CObject{
public:
	int m_data1;
	virtual void serialize()
	{
		std::cout<<"CDocument::serialize()\n"<<std::endl;
	}
};
class CMyDoc:public CDocument{
public:
	int m_data2;
	CMyDoc(CObject & obj)
	{
		m_data2 = 0;
	}
	void f()
	{
		std::cout<<"CMyDoc::f()\n"<<std::endl;
		serialize();
	}
	void serialize()
	{
		std::cout<<"CMyDoc::serialize()\n"<<std::endl;
	}
};

void main()
{
	CObject obj;
	((CMyDoc)obj).f();

	//int a;
	//long int b;	//same as int
	//std::cout<<sizeof(a)<<" "<<sizeof(b)<<std::endl;
	
	/*ULONGLONG	n	=	100000000;
	clock_t	clockBegin,clockEnd;
	ULONGLONG	s1,s2;

	clockBegin	=	clock();
	s2			=	sum2(n);
	clockEnd	=	clock();
	std::cout<<s2<<" "<<clockEnd-clockBegin<<std::endl;
	clockBegin	=	clock();
	s1			=	sum1(n);
	clockEnd	=	clock();
	std::cout<<s1<<" "<<clockEnd-clockBegin<<std::endl;*/
	
	/* 阻塞地接受一个客户端连接 */
	//SOCKET s = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
	//SOCKET con = accept( s, 0, 0 ); 
	///* recv request */
	//char request[1024] = { 0 };
	//int		ret = recv( con, request, sizeof( request ), 0 );
	//printf( request );
	///* whatever we recv, we send 200 response */
	//{
	//	char content[] = "<head><head><title>index.html</title></head><body>index.html</body>";
	//	char response[512];
	//	sprintf( response, "HTTP/1.1 200 OK\r\nContent-Type: text/html\r\nContent-Length: %d\r\n\r\n%s", strlen( content ), content );
	//	ret = send( con, response, strlen( response ), 0 );
	//}
	//closesocket( con ); 



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