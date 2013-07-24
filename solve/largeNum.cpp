#include "largeNum.h"
#include<iostream>

largeNum::largeNum()
{
	for ( int i=0;i<N-1;++i )
	{
		m_cNum[i]	=	0;
	}
	m_cNum[N-1]	=	1;
}

largeNum::largeNum(std::string str)
{
	int len	=	str.length(), i;
	for( i=0;i<N-len;++i)
	{
		m_cNum[i]	=	0;
	}
	for( i=0;i<len;++i )
	{
		m_cNum[N-len+i]	=	str[i]-'0';
	}
}

largeNum::largeNum(const largeNum &n)
{
	for ( int i=0;i<N;++i )
	{
		m_cNum[i]	=	n.m_cNum[i];
	}
}

largeNum::~largeNum(void)
{
}

void	largeNum::add(largeNum &caNum)
{
	for( int 	i=N-1;i>=0;--i )
	{
		int	t	=m_cNum[i]+caNum.m_cNum[i];
		m_cNum[i]	=	t%10;
		m_cNum[i-1] += t/10;
	}
}

int		largeNum::sumOfBit()
{
	int	sum=0;
	for( int i=0;i<N;++i )
	{
		sum+=m_cNum[i];
	}
	return	sum;
}

void	largeNum::showFirstTen()
{
	int pos, i ;
	for( i=0;i<N;++i )
	{
		if( m_cNum[i]!=0 )
		{
			pos	=	i;
			break;
		}
	}
	for( i=pos;i<pos+10;++i )
	{
		std::cout<<m_cNum[i]+'0'-48<<std::endl;
	}
}

void	largeNum::copy(largeNum n)
{
	for ( int i=0;i<N;++i )
	{
		m_cNum[i]	=	n.m_cNum[i];
	}
}

int		largeNum::firstBit()
{
	int i	=	m_cNum[0];
	return	i;
}

