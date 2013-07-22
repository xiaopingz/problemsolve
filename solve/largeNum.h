#pragma once
#include<string>
#define	N	200

class largeNum
{
public:
	largeNum();	//	16.初始化为1，2^0
	largeNum(std::string str);
	largeNum(const largeNum &n);	//注意拷贝构造函数的参数写法
	~largeNum(void);

	void	add(largeNum &caNum);
	int		sumOfBit();	//	16.
	void	showFirstTen();

protected:
	char	m_cNum[N];
};

