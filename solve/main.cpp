#if 1
#include<fstream>
#include<iostream>
#include<math.h>	//sumOfPrim
#include<memory>	//shared_ptr
#include<vector>
#include"largeNum.h"	//13.


int	findGreatestConsecutive(int a[], int len)
{
	int	i, pro=0;

	for( i=0;i<len-4;++i )
	{
		int product = a[i+1]*a[i]*a[i+2]*a[i+3]*a[i+4];
		if( product>pro )
		{
			pro	=	product;
		}
	}
	return pro;
}


long long int sumOfPrime(long int n )
{
	long long int sum = 0;	//类型很重要
	int flag ,a,b;
	
	for( int i=2;i<n;++i )
	{
		a = sqrt((double)i);
		flag = 1;
		for( b=2;b<=a;++b )
		{
			if( i%b == 0 )
			{
				flag = 0;
				break;
			}
		}
		if( flag )
		{
			sum += i;
		}
	}
	return sum;
}

int primeNumber(int n)
{
	int		count = 0;	//第几个素数，要求第n个素数是多少
	int		prime = 0;
	int		flag = 1;
	int		a = 2, b, m;
	m = sqrt( (double)a);
	
	while( count<n )
	{
		flag = 1;
		for( b=2; b<=m ;b++ )
		{
			if( a%b == 0 )
			{
				flag	=	0;
				break;
			}
		}
		if( flag )
		{
			count++;
			prime = a;
		}
		a++;
		m = sqrt( (double)a);
	}
	return prime;
}

//将二维的数组的下标转换为对应的一维数组的下标
int transform(int n, int i, int j )
{
	//n为方阵的阶数，就方阵为n*n的
	int k;
	k	=	i * n + j;
	return k;
}

//11.同一排相邻位置四个数的乘积最大的
int	greatestProduct(int *a, int n)
{
	//n为方阵的阶数，就方阵为n*n的
	int pro = 0, proTmp = 0;
	int i,j;
	for( i=0;i<n;++i )
	{
		for( j=0;j<n;++j )
		{
			if( j<n-3 )
			{
				proTmp	=	a[transform(n,i,j)] * a[transform(n,i,j+1)] * a[transform(n,i,j+2)] * a[transform(n,i,j+3)];
				if( proTmp>pro )
				{
					pro	=	proTmp;
				}
			}
			if( i<n-3 )
			{
				proTmp	=	a[transform(n,i,j)] * a[transform(n,i+1,j)] * a[transform(n,i+2,j)] * a[transform(n,i+3,j)];
				if( proTmp>pro )
				{
					pro	=	proTmp;
				}
			}
			if( i<n-3 && j<n-3 )
			{
				proTmp	=	a[transform(n,i,j)] * a[transform(n,i+1,j+1)] * a[transform(n,i+2,j+2)] * a[transform(n,i+3,j+3)];
				if( proTmp>pro )
				{
					pro	=	proTmp;
				}
			}
			if( i>3 && j<n-3 )
			{
				proTmp	=	a[transform(n,i,j)] * a[transform(n,i-1,j+1)] * a[transform(n,i-2,j+2)] * a[transform(n,i-3,j+3)];
				if( proTmp>pro )
				{
					pro	=	proTmp;
				}
			}
		}
	}
	return	pro;
}

//求n的因数的个数
int divisorNum(int n)
{
	int count=0;
	for( int i=1;i<=sqrt((double)n);++i )
	{
		if( n%i==0 )
			++count;
	}
	return count*2;
}

//求n的因数之和(不大于n/2)(21.)
int sumOfDivisor(int n)
{
	int	sum	=	0;
	for( int i=1;i<=sqrt((double)n);++i )
	{
		if( n%i==0 )
			sum	+=	i + n/i;
	}
	sum	=	sum - n;	//因为不大于n/2，所以不包括自身
	return	sum;
}

//21.小于n的amicable numbers的和(题中n为10000)
int	sumOfAmicableNumbers(int n)
{
	int sum=0;
	for( int i=2;i<n;++i )
	{
		int	a = sumOfDivisor(i);
		if(sumOfDivisor(a)==i)
			sum += i+a;
}

//第n个...
int triangleNum(int n)
{
	return n*(n+1)/2;
}
//12.
int highlyDivisibleTriangularNumber()
{
	unsigned int a=0;
	int MAX = (~a)/2;	//求int最大值
	int res, i=1;
	while(i<MAX)
	{
		res = divisorNum(triangleNum(i));
		if( res>500 )
			break;
		else ++i;
	}
	return triangleNum(i);
}

//14.
int	maxChain()
{
	char	a[1000000];
	int		max=0,count, countMax=0;
	long	long	tmp;	//

	for( int j=999999;j>=00;--j )
	{
		a[j]	=	0;
	}
	for( int i=999999;i>0;--i )
	{
		if( a[i]==1 )
			continue;
		a[i]	=	1;
		tmp		=	i;
		count	=	0;
		while(tmp!=1)
		{
			if( tmp%2==0 )	//even
			{
				tmp	=	tmp/2;
				++count;
				if( tmp<1000000 )
					a[tmp]	=	1;
			}
			else	//odd
			{
				tmp	=	tmp*3+1;
				++count;
				if( tmp<1000000 )
					a[tmp]	=	1;
			}
		}
		if( count>countMax )
		{
			countMax	=	count;
			max			=	i;
		}
	}
	return max;
}

//1000以内（包括）的任意数字，英文表示时的字母和
int	numberLetterCounts(int n)
{
	//记录需要用到的数字的英文长度
	int numLen[31],i;	
	int res=0;	//	result
	for ( i=0;i<31;++i )
	{
		switch(i)
		{
		case 1: case 2: case 6: case 10: 
			numLen[i]	=	3;break;
		case 4: case 5: case 9:
			numLen[i]	=	4;break;
		case 3: case 7: case 8: case 22: case 23: case 24:
			numLen[i]	=	5;break;
		case 11: case 12: case 20: case 21: case 26: case 27:
			numLen[i]	=	6;break;
		case 15: case 16: case 25: case 28:
			numLen[i]	=	7;break;
		case 13: case 14:case 18: case 19: 	//	29-thousand
			numLen[i]	=	8;break;
		case 17:	//seventeen
			numLen[i]	=	9;break;
		case 29:	//hundred and
			numLen[i]	=	10;break;
		case 30:
			numLen[i]	=	11;break;
		default:
			numLen[i]	=	0;
			break;
		}
	}

	//真纠结！！！
	if ( n<20 )
	{
		res	=	numLen[n];
	}
	else if ( n<100 )
	{
		res	=	numLen[n/10+18]+numLen[n%10];
	}
	else if ( n==1000 )
	{
		res	=	numLen[30];
	}
	else if ( n%100==0 )
	{
		res	=	numLen[n/100]+numLen[28];
	}
	else if ( n%100>0 && n%100<20 )
	{
		res	=	numLen[n/100]+numLen[29]+numLen[n%100];
	}
	else if ( n<1000 )
	{
		res	=	numLen[n/100]+numLen[29]+numLen[(n%100)/10+18]+numLen[n%10];
	}	

	return	res;
}

//17.1~1000的数字，字母个数总和
int	sumOfLetterCounts()
{
	int	count=0;
	for ( int i=1;i<=1000;++i )
	{
		count	+=	numberLetterCounts(i);
	}
	return	count;
}

//18.
int	maxPathSum(int * a, int n)
{
	//n为方阵的阶数，就方阵为n*n的；此处a为三角矩阵，如果只知道a的长度，则需要换算
	int	i,j,sum1,sum2;
	for ( i=n-2;i>=0;--i )
	{
		for ( j=0;j<=i;++j )
		{
			a[transform(n,i,j)]	+=	(a[transform(n,i+1,j)]>a[transform(n,i+1,j+1)]?a[transform(n,i+1,j)]:a[transform(n,i+1,j+1)]);
		}
	}
	return a[0];
}

int isLeapYear(int year)
{
	if ( year%400==0 || year%4==0 && year%100!=0 )
	{
		return	1;
	}
	else return 0;
}
//19.
int sundayCounts()
{
	int	count = 0;
	int	sum = 1;
	for ( int i=1901;i<=2000;++i )
	{
		if (isLeapYear(i-1))
		{
			sum	+= 366;
		}
		else	sum+=365;
		int	t	=	sum;
		for ( int j=1;j<13;++j )
		{
			switch(j)
			{
			case 2:case 4:case 6:case 8:case 9:case 11:
				t	+=	31;break;
			case 3:
				if (isLeapYear(i))
				{
					t	+=	29;
					break;
				}
				else
				{
					t	+=	28;
					break;
				}
			case 5:case 7:case 10:case 12:
				t	+=	30;break;
			}
			t	=	t%7;
			if (!t)
			{
				++count;
			}
		}
	}
	return	count;
}

void main()
{
	//19.
	std::cout<<sundayCounts()<<std::endl;

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
	/*std::cout<<sumOfPrime((long int)2000000)<<std::endl;*/

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