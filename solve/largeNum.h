#pragma once
#include<string>
#define	N	1000

class largeNum
{
public:
	largeNum();	//	16.��ʼ��Ϊ1��2^0
	largeNum(std::string str);
	largeNum(const largeNum &n);	//ע�⿽�����캯���Ĳ���д��
	~largeNum(void);

	void	add(largeNum &caNum);
	int		sumOfBit();	//	16.
	void	showFirstTen();
	void	copy(largeNum n);
	int		firstBit();

protected:
	char	m_cNum[N];
};

