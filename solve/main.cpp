#if 1
#include <algorithm>//swap
#include<fstream>
#include<iostream>
#include<math.h>	//sumOfPrim
#include <cmath>	//abs
#include<memory>	//shared_ptr
#include<vector>
#include <map>		//22.
#include <set>		//29.
#include <cstdint>
#include"largeNum.h"	//13.
#include "TemplateClass.h"


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

//n是否为素数
int isPrimeNum(int n)
{
	int flag=1, a;
	a = sqrt((double)n);
	for ( int i=2;i<=a;++i )
	{
		if ( n%i==0 )
		{
			flag = 0;
			break;
		}
	}
	return flag;
}

//10.
long long int sumOfPrime(long int n )
{
	long long int sum = 0;	//类型很重要
	
	for( int i=2;i<n;++i )
	{
		if( isPrimeNum(i) )
		{
			sum += i;
		}
	}
	return sum;
}

//7.第n个素数是多少
int primeNumber(int n)
{
	int		count = 0;	//第几个素数，求第n个素数是多少
	int		prime = 0;
	int		a = 2;
	
	while( count<n )
	{
		if( isPrimeNum(a) )
		{
			count++;
			prime = a;
		}
		a++;
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
		{
			if ( n/i!=i )
			{
				sum	+=	i + n/i;
			}
			else
				sum	+=	i;
		}
	}
	sum	=	sum - n;	//因为不大于n/2，所以不包括自身
	return	sum;
}

//21.小于10000的amicable numbers的和
int	sumOfAmicableNumbers()
{
	int sum=0, a[10000]={0};
	for( int i=2;i<10000;++i )
	{
		if ( isPrimeNum(i) )
			continue;
		if (a[i])
			continue;	//	数字已经是amicable numbers，则跳过
		int	j = sumOfDivisor(i);
		if( sumOfDivisor(j)==i && j!=i )
		{
			sum += i+j;
			a[i] = j;
			a[j] = i;
		}
	}
	return	sum;
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

//22.
int worthOfWord(std::string str)
{
	int len	=	str.length();
	int	worth	=	0;
	for ( int i=0;i<len;++i )
	{
		if ( str[i]>64 && str[i]<91 )
		{
			worth	+=	str[i]-64;
		}
	}
	return	worth;
}

typedef std::map<std::string,int> MapWW;
typedef std::shared_ptr<MapWW>	MapWWPtr;

//生成存有各单词及其worth的map
MapWWPtr	makeWordsMap(std::string str)
{
	MapWWPtr	pMapWW	=	std::make_shared<MapWW>();
	int			flag	=	1;
	std::size_t	startPos=0, endPos=0,tmp;

	while ( endPos!=str.length()-1 )
	{
		char		tc[20]	=	"";
		if (flag)
		{
			tmp	=	str.find('"',startPos+1 );
			endPos	=	tmp;
			str.copy(tc,endPos-startPos-1,startPos+1);
			std::string strTmp(tc);
			int iTmp	=	worthOfWord(strTmp);
			(*pMapWW)[strTmp]	=	iTmp;
			flag	=	0;
		}
		else
		{
			tmp	=	str.find('"',endPos+1 );
			startPos	=	tmp;
			flag		=	1;
		}
	}
	return	pMapWW;
}

//22.计算map中名字分数乘位置的总和
long long	int	sumOfNameScores(MapWWPtr pMapWW)
{
	int count	=	1;
	long long int sum	=	0;
	MapWW::iterator it;

	for ( it=pMapWW->begin();it!=pMapWW->end();++it )
	{
		sum	+=	it->second * count;
		++count;
	}
	return	sum;
}

int isAbundantNumber(int n)
{
	if (sumOfDivisor(n)>n)
		return	1;
	else	return 0;
}

//23.不是两个abundant number的和的所有正整数之和
int sumOfNonANSum()
{
	int	a[28124]	=	{0};
	int	i, t;
	int	sum=0;

	for ( i=12;i<28124;++i )
	{
		if ( isAbundantNumber(i) )
			a[i]	=	1;
	}
	for( i=12;i<28124;++i )
	{
		if ( a[i]==1 || a[i]==3 )
		{
			for( int j=i;j<28124;++j )
			{
				if ( a[j]==1 || a[j]==3 )
				{
					t	=	i+j;
					if ( t<28124 )
					{
						if ( a[t]==1 )
						{
							a[t] = 3;
						}
						else if ( a[t]==0 )
						{
							a[t]	=	2;
						}
					}
				}
			}
		}
	}
	for ( i=1;i<28124;++i )
	{
		if ( a[i]==0 || a[i]==1 )
		{
			sum	+=	i;
		}
	}
	return	sum;
}

//全排列
void	fullPermut(char * a,int k, int n)
{
	static int count	=	0;
	if (k==n)
	{
		++count;
		std::cout<<a<<std::endl;
	}
	else
	{
		for ( int i=k;i<n;++i )
		{
			std::swap(a[k],a[i]);
			fullPermut(a,k+1,n);
			std::swap(a[k],a[i]);
		}
	}
}

//24.algorithm中sort 和 next_permutation函数
void	lexicographicPermutations(char *a, int n)
{
	int		count=0;
	std::sort(a,a+n);
	do 
	{
		++count;
		if( count==1000000 )
		{
			std::cout<<a<<std::endl;
			break;
		}
	} while (std::next_permutation(a,a+n));

}

//求阶乘
int		factorial(int n)
{
	if ( !n )
	{
		return 1;
	}
	else
		return n * factorial(n-1);
}

//
void	setTheBit(int &t, int i, char *a)
{
	int b[10],count=0;
	
	for (int j=0;j<i;++j)
	{
		b[a[j]-'0']	=	1;
	}
	for ( int k=0;k<10;++k )
	{
		if ( b[k]!=1 )
		{
			++count;
			if ( count==t+1 )
			{
				t = k;
				break;
			}
		}
	}
}

//数组a，长度为n，找字符c是否存在。
int findChar(char *a, int n, char c)
{
	for ( int i=0;i<n;++i )
	{
		if ( a[i]==c )
			return 1;
	}
	return 0;
}

//24_2.
void	lexicographicPermutations2(char *a, int n)
{
	int r=1000000;	//余数
	int t;	//记录每一位初步计算应填入的数
	char	c[11] = "";	//??????????初始化为0？写成{'0'}怎么也只是第一位初始化了，其他位都为0呢……
	for ( int i=0;i<n;++i )
	{
		if ( r==0 )
		{
			for ( int k=n-1;k>=0;--k )
			{
				if ( !findChar(c,n,a[k]) )
				{
					c[i]	=	a[k];
					break;
				}
			}
		}

		for ( int j=n-1-i;j>0;--j )
		{
			if ( factorial(j)<r && factorial(j+1)>r )
			{
				int f	=	factorial(j);
				t	=	r/f;
				if ( r%f==0 )
					--t;	//!!!!!!!!!!!!!!!
				r	=	r%f;
				setTheBit(t,i,c);
				c[i]	=	t + '0';
				break;
			}
		}
	}
	std::cout<<c<<std::endl;
}

//求d的位数（10进制）----未用到
int		digitNumbers(int d)
{
	char	a[8];
	int		n;
	n	=	sprintf(a,"%d",d);
	return	n;
}

//除法时末尾补零(补n个零，则乘一次10)
void	mutliplyTen(int &a, int n)
{
	for ( int i=0;i<n;++i )
	{
		a = a*10;
	}
}

//求1/d的循环位数
int		numOfRecurringCycle(int d)
{
	int count = 0;
	std::vector<int>		vRem;	//	保存每一位余数,如果重复，则能计算出循环的位数。
	int	r	=	1;		//余数
	std::vector<int>::iterator it	=	find(vRem.begin(),vRem.end(),r);
	while(it==vRem.end())
	{
		vRem.push_back(r);
		int i	=	digitNumbers(d) - digitNumbers(r)+1;
		mutliplyTen(r,i);
		r	=	r%d;
		it	=	find(vRem.begin(),vRem.end(),r);
	}
	for ( ;it!=vRem.end();++it )
	{
		++count;
	}
	
	return count;
}

//26.求纯小数中循环小数的位数最多的一位（1/d，d小于1000）
int		longestRecurringCycle()
{
	int iMax, nT,nMax=0;
	for ( int i=3;i<1000;++i )
	{
		nT	=	numOfRecurringCycle(i);
		if ( nT>nMax )
		{
			nMax	=	nT;
			iMax	=	i;
		}
	}
	return	iMax;
}

//27.
int		formulaOfQuadraticPrimes()
{
	int aMax,bMax,nMax=0;
	int	p;
	for ( int a=-1000;a<=1000;++a )
	{
		for ( int b=-1000;b<=1000;++b )
		{
			int n = 0;
			while( isPrimeNum(abs(n*n+a*n+b)) )
				++n;
			if ( n>nMax )
			{
				nMax	=	n;
				aMax	=	a;
				bMax	=	b;
			}
		}
	}
	p	=	aMax * bMax;
	return	p;
}

//28.
int		sumOfNumberSpiralDiagonals()
{
	int i=1, sum=1,a,b=1;

	while( b<1002001 )
	{
		int d = i*2;
		a = b+d;
		b = a+3*d;
		sum += 2*(a+b);
		++i;
	}
	return sum;
}

int		isPowerEqual(std::pair<int64_t,int64_t> pa, std::pair<int64_t,int64_t> pb)
{
			return 0;
}
//29.
int	distinctPowers()
{
	std::vector<std::pair<int64_t,int64_t>>	powers;
	std::vector<std::pair<int64_t,int64_t>>::iterator it;
	int flag = 1;
	for ( int64_t a=2;a<=100;++a )
	{
		for ( int64_t b=2;b<=100;++b )
		{
			std::pair<int64_t,int64_t>	pn	=	std::make_pair(a,b);
			if ( powers.size()==0 )
			{
				powers.push_back(pn);
			}
			else
			{
				flag = 1;
				for ( it=powers.begin();it!=powers.end();++it )
				{
					if(isPowerEqual(*it,pn))
					{
						flag	=	0;
						break;
					}
				}
				if ( flag )
				{
					powers.push_back(pn);
				}
			}
		}
	}
	//std::cout<<ct<<std::endl;
	return	powers.size();
}

int isFifthPowersDigits(int n)
{
	int a,b,c,d,e,f;
	a = n/100000;
	b = n%100000/10000;
	c = n%10000/1000;
	d = n%1000/100;
	e = n%100/10;
	f = n%10;
	if ( pow((double)a,5)+pow((double)b,5)+pow((double)c,5)+pow((double)d,5)+pow((double)e,5)+pow((double)f,5)==n )
	{
		return 1;
	}
	else
		return 0;
}

//30.
int	sumOfDigitFifthPowers()
{
	std::vector<int>	v;
	int sum = 0;
	for ( int i=2;i<900000;++i )	//	上界问题？The maximum value for one digit is 9^5 = 59049.Let's say we're gonna check the number 123456789. That's 9 digits, so the maximum sum would be 9*59049 = 531441
	{
		if ( isFifthPowersDigits(i) )
		{
			v.push_back(i);
		}
	}
	for ( std::vector<int>::iterator it = v.begin();it!=v.end();++it )
	{
		std::cout<<*it<<" ";
		sum += *it;
	}
	return sum;
}

//31.( steal!!!!!   http://www.mathblog.dk/project-euler-31-combinations-english-currency-denominations/ )
int waysOfCoinSums()
{
	int targetNum	=	200;
	int engCorrency[]	=	{1,2,5,10,20,50,100,200};
	//int way[targetNum+1]=	{0};
	int *way	 =	new int[targetNum + 1];
	way[0]	=	1;
	for ( int i = 1;i<=targetNum;++i )
	{
		way[i]	=	0;
	}
	int len	=	sizeof(engCorrency)/sizeof(engCorrency[0]);
	for ( int i = 0;i<len;++i )
	{
		for ( int j=engCorrency[i];j<=targetNum;++j )
		{
			if ( j==200 )
			{	//展示一下部分计算过程
				std::cout<<"way[200]="<<way[200]<<" ,way["<<j-engCorrency[i]<<"]="<<way[j-engCorrency[i]]<<std::endl;
			}
			way[j] += way[j-engCorrency[i]];
		}
	}
	return	way[targetNum];
}

//34.各位之阶乘之和是否等于其自身
int isDigitFactorial(int a)
{
	int n =	digitNumbers(a);
	int sum = 0, t = a;
	for (int i=n;i>0;--i)
	{
		sum	+= factorial(t/pow((double)10,i-1));
		t	=	t%(int)pow((double)10,i-1);
	}
	if ( sum==a )
		return	1;
	else
		return	0;
}

//34.
int sumOfDigitFactorials()
{
	int	n	=	1000000;	//	上界是多少？
	int sum =	0;
	for ( int i=3;i<n;++i )
	{
		if (isDigitFactorial(i))
		{
			sum		+=	i;
		}
	}
	return	sum;
}

void main()
{

	/*TemplateClass<int,int> a(1,2);
	a.showContents();
	TemplateClass<int,char> b(1,70);
	b.showContents();
	TemplateClass<double,char> c(3.2,'c');
	c.showContents();*/

	std::cout<<sumOfDigitFactorials()<<std::endl;

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

	//24.
	/*char a[11]	=	{ '0','1','2','3','4','5','6','7','8','9','\0' };
	lexicographicPermutations2(a,10);*/

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
	//std::cout<<sumOfPrime((long int)2000000)<<std::endl;

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