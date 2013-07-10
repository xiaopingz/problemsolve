#include<fstream>
#include<iostream>
#include<math.h>	//sumOfPrim

int	findGreatestConsecutive(int a[], int len)
{
	int	i, pos=0, posTmp=0,flag=0;

	for( i=0;i<len-4;++i )
	{
		if( a[i+1]==a[i]+1 && a[i+2]==a[i]+2 && a[i+3]==a[i]+3 && a[i+4]==a[i]+4 )
		{
			posTmp = i;
			if( a[posTmp+4] > a[pos] )
			{
				pos = posTmp;
				flag = 1;
			}
			i = i+3;
		}
		else if( a[i+1]==a[i]-1 && a[i+2]==a[i]-2 && a[i+3]==a[i]-3 && a[i+4]==a[i]-4 )
		{
			posTmp = i;
			if( a[posTmp] > a[pos] )
			{
				pos = posTmp;
				flag = 1;
			}
		}
	}
	if( flag )
		return pos;
	else return -1;
}


long int sumOfPrime(long int n )
{
	long int sum = 0;
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

void main()
{
	//findGreatestConsecutive
	/*int		a[1000], i=0, pos;
	std::ifstream file("digits.txt");
	char	c;

	while( !file.eof() && i<1000 )
	{
		file>>c;
		a[i] = c-48;
		++i;
	}

	pos = findGreatestConsecutive(a,1000);
	if( pos!=-1 )
		std::cout<<a[pos]<<a[pos+1]<<a[pos+2]<<a[pos+3]<<a[pos+4];
	else
		std::cout<<"Not found!"<<std::endl;*/

	std::cout<<sumOfPrime((long int)2000000)<<std::endl;
}