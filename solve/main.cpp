#include<fstream>
#include<iostream>
#include<math.h>	//sumOfPrim

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

int	greatestProduct(int **a, int n)
{
	int pro = 0, proTmp = 0;
	int i,j;
	for( i=0;i<n-4;++i )
	{
		for( j=0;j<n-4;++j )
		{
			proTmp	=	a[i][j] * a[i][j+1] * a[i][j+2] * a[i][j+3];
			if( proTmp>pro )
			{
				pro	=	proTmp;
			}
			proTmp	=	a[i][j] * a[i+1][j] * a[i+2][j] * a[i+3][j];
			if( proTmp>pro )
			{
				pro	=	proTmp;
			}
			proTmp	=	a[i][j] * a[i+1][j+1] * a[i+2][j+2] * a[i+3][j+3];
			if( proTmp>pro )
			{
				pro	=	proTmp;
			}
		}
	}
	return	pro;
}

void main()
{
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
	int		**a, res;
	a	=	(int **)malloc(400*sizeof(int));
	std::ifstream file("digits11.txt");
	int		c;

	for( int i=0;i<20;++i )
	{
		for( int j=0;j<20;++j )
		{
			file>>c;
			a[i][j]	== c;
		}
	}

	res = greatestProduct(a,20);
	std::cout<<res<<std::endl;
}