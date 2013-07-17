#include "largeNum.h"
#include<iostream>


largeNum::largeNum(std::string str)
{
	int len	=	str.length(), i;
	for( i=0;i<60-len;++i)
	{
		m_cNum[i]	=	0;
	}
	for( i=0;i<len;++i )
	{
		m_cNum[60-len+i]	=	str[i]-'0';
	}
}


largeNum::~largeNum(void)
{
}

void	largeNum::add(largeNum &caNum)
{
	for( int 	i=59;i>=0;--i )
	{
		int	t	=m_cNum[i]+caNum.m_cNum[i];
		m_cNum[i]	=	t%10;
		if( t%10!=0 )
			m_cNum[i-1] += t/10;
	}
}

void	largeNum::showFirstTen()
{
	int pos, i ;
	for( i=0;i<60;++i )
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
