#if 0

#include <time.h>
#include"largeNum.h"	//13.
#include "TemplateClass.h"
#include "head_info.h"

void main()
{
	/*int a = -12;
	printBinary(a);*/
	/*TemplateClass<int,int> a(1,2);
	a.showContents();
	TemplateClass<int,char> b(1,70);
	b.showContents();
	TemplateClass<double,char> c(3.2,'c');
	c.showContents();*/

	/*std::cout<<minGoldbachOtherConjecture()<<std::endl;*/

	//25.
	/*largeNum	sum, t,k;
	int			count = 3;
	sum.add(t);
	while ( sum.firstBit()==0 )
	{
	t.copy(k);
	k.copy(sum);
	sum.add(t);
	++count;
	}
	std::cout<<count<<std::endl;*/

	//24.41.43.
	clock_t clockbegin,clockend;
	clockbegin = clock();
	char a[11]	=	{ '0','1','2','3','4','5','6','7','8','9','\0' };
	sumOfSubStrDivisible(a,10);
	clockend = clock();
	std::cout<<"time:"<<clockend-clockbegin<<std::endl;

	//std::cout<<a<<std::endl;
	
	//22.
	/*std::ifstream	file("names.txt");
	std::string	str;
	file>>str;
	MapWWPtr	pMapWW	=	makeWordsMap(str);
	std::cout<<sumOfNameScores(pMapWW)<<std::endl;*/

	//20.
	//largeNum	num;	//	N=200, init stores 1. (LargeNum is so wonderful!!)
	//for ( int i=1;i<100;++i )
	//{
	//	largeNum	tmp(num);
	//	for( int j=1;j<=i;++j )
	//	{
	//		num.add(tmp);
	//	}
	//}
	//std::cout<<num.sumOfBit()<<std::endl;

	//18.
	/*std::ifstream	file("digits18.txt");
	int k,n=15,a[225];
	for ( int i = 0;i<n;++i )
	{
	for ( int j=0;j<=i;++j )
	{
	file>>k;
	a[transform(n,i,j)]	=	k;
	}
	}
	std::cout<<maxPathSum(a,n)<<std::endl;
	*/
	//17.
	/*int i=1;
	while ( i )
	{
		std::cin>>i;
		std::cout<<numberLetterCounts(i)<<std::endl;
	}
	std::cout<<sumOfLetterCounts()<<std::endl;*/

	//16.
	/*largeNum	num;//	N=400
	for ( int i=0;i<1000;++i )
	{
	largeNum	tmp(num);
	num.add(tmp);
	}
	std::cout<<num.sumOfBit()<<std::endl;*/


	//8.findGreatestConsecutive
	/*int		a[1000], i=0, res;
	std::ifstream file("digits.txt");
	char	c;

	while( !file.eof() && i<1000 )
	{
		file>>c;
		a[i] = c-48;
		++i;
	}

	res = findGreatestConsecutive(a,1000);
	std::cout<<res<<std::endl;*/

	//10.
	/*std::cout<<sumOfPrime2(2000000)<<std::endl;*/

	//7.	
	/*int n = 10001;
	int m = primeNumber(n);
	std::cout<<m<<std::endl;*/

	//9.
	/*int a, b, c;

	for( a=1;a<500;++a )
	{
		for( b=1; b<500;++b )
		{
			c = 1000-a-b;

			if( (a*a + b*b) == c*c)
			{
				std::cout<<a<<" "<<b<<" "<<c<<std::endl;
				return;
			}
		}
	}*/

	//11.
	/*int		*a, res;
	a	=	new int[400];
	std::ifstream file("digits11.txt");
	int		c;

	for( int i=0;i<400;++i )
	{
		file>>c;
		a[i] = c;
	}

	res = greatestProduct(a,20);
	std::cout<<res<<std::endl;
	file.close();*/

	//12.
	/*std::cout<<highlyDivisibleTriangularNumber()<<std::endl;*/

	//14.
	/*std::cout<<maxChain()<<std::endl;*/

	//13.大数字求和（100个50位）
	//类中数组设置为60位的，初始化时初始为0(N=60)
	/*std::ifstream	file("digits13.txt");
	std::string		str;
	file>>str;
	largeNum		num(str);
	while( !file.eof() )
	{
	file>>str;
	largeNum	n(str);
	num.add(n);
	}
	num.showFirstTen();*/

}

#endif