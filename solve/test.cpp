#if 1

#include "TemplateClass.h"
#include <iostream>
#include <WinSock2.h>

void main()
{
	/* �����ؽ���һ���ͻ������� */
	SOCKET con = accept( s, 0, 0 ); 
	/* recv request */
	char request[1024] = { 0 };
	ret = recv( con, request, sizeof( request ), 0 );
	printf( request );
	/* whatever we recv, we send 200 response */
	{
		char content[] = "<head><head><title>index.html</title></head><body>index.html</body>";
		char response[512];
		sprintf( response, "HTTP/1.1 200 OK\r\nContent-Type: text/html\r\nContent-Length: %d\r\n\r\n%s", strlen( content ), content );
		ret = send( con, response, strlen( response ), 0 );
	}
	closesocket( con ); 

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