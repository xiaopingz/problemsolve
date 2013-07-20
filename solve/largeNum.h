#pragma once
#include<string>
#define	N	200

class largeNum
{
public:
	largeNum();	//	16.³õÊ¼»¯Îª1£¬2^0
	largeNum(std::string str);
	largeNum(const largeNum &n);
	~largeNum(void);

	void	add(largeNum &caNum);
	int		sumOfBit();	//	16.
	void	showFirstTen();

protected:
	char	m_cNum[N];
};

