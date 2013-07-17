#pragma once
#include<string>

class largeNum
{
public:
	//largeNum();
	largeNum(std::string str);
	~largeNum(void);

	void	add(largeNum &caNum);
	void	showFirstTen();

protected:
	char	m_cNum[60];
};

