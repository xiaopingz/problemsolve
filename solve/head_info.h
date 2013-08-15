#pragma once
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
typedef std::map<std::string,int> MapWW;
typedef std::shared_ptr<MapWW>	MapWWPtr;

//素数相关
int isPrimeNum(int n);					// n是否为素数,是，返回1：否，返回0
long long int sumOfPrime(long int n );	//	小于n的所有素数之和				//10.
int primeNumber(int n);					//所以素数中，第n个素数是多少			//7.
bool	isCirclePrime(int n);			//n的各位全排列之后的数字均为素数
int		numOfCirclePrimes(int n);		//小于n的circle prime的个数			//35.
bool	isTrancatablePrime(int n);		//从左右依次截断是否都是素数（37）

//数学公式相关
bool	isPentagonalNumber(int n);		//pentagonal number:Pn=n(3n?1)/2
bool	isHexagonalNumber(int n);		//Hexagonal number:	Hn=n(2n?1)

//将二维的数组的下标转换为对应的一维数组的下标
int transform(int n, int i, int j );	//n为方阵的阶数，即方阵为n*n的

//因数相关
int divisorNum(int n);					//求n的因数的个数
int sumOfDivisor(int n);				//求n的因数之和(不大于n/2)			//21.
int	sumOfAmicableNumbers();				//小于10000.因数之和等于自身			//22.
int isAbundantNumber(int n);
int sumOfNonANSum();					//不是两个abundant number的和的所有正整数之和	//23.

//第n个...
int triangleNum(int n);
int highlyDivisibleTriangularNumber();	//12.

//字母与数字之间相关转换
int		digitNumbers(int d);			//求d的位数（10进制）
char *	intToStr(int n);
int		strToInt(char * a, int len);
void	printCharArray(char * a, int len);

int	numberLetterCounts(int n);			//1000以内（包括）的任意数字，英文表示时其字母个数和
int	sumOfLetterCounts();				//1~1000的所有数字，字母个数总和		//17.
int worthOfWord(std::string str);											//22.
//MapWWPtr	makeWordsMap(std::string str);	//生成存有各单词及其worth的map
//long long	int	sumOfNameScores(MapWWPtr pMapWW);	//计算map中名字分数乘位置的总和	//22.

bool	isPalindromic(char * a,int len);	//是否回文
bool	isPalBothBases(int n);			//n的十进制和二进制表示（不要前面的0）是否都为回文
int		sumOfPal(int n);				//小于n的回文（十进制和二进制）的数之和
bool	isSubStrDivisible(char *a,int len);	//(43.)

//日期相关
int isLeapYear(int year);				//是否为闰年
int sundayCounts();						//星期天落在一个月的第一天的个数		//19.


int		numOfRecurringCycle(int d);		//求1/d的循环位数

void	fullPermut(char * a,int k, int n);	//全排列
int		factorial(int n);					//求阶乘


void	lexicographicPermutations(char *a, int n);							//24.
void	setTheBit(int &t, int i, char *a);
int		findChar(char *a, int n, char c);
void	lexicographicPermutations2(char *a, int n);							//24_2.
void	findLargestPandigitalPrime(char *a, int n);							//41.
void	sumOfSubStrDivisible(char *a, int n);								//43.

//除法时末尾补零(补n个零，则乘一次10)
void	mutliplyTen(int &a, int n);

//26.求纯小数中循环小数的位数最多的一位（1/d，d小于1000）
int		longestRecurringCycle();

//27.
int		formulaOfQuadraticPrimes();

//28.
int		sumOfNumberSpiralDiagonals();

int		isPowerEqual(std::pair<int64_t,int64_t> pa, std::pair<int64_t,int64_t> pb);
//29.
int	distinctPowers();

int isFifthPowersDigits(int n);

//30.
int	sumOfDigitFifthPowers();

//31.( steal!!!!!   http://www.mathblog.dk/project-euler-31-combinations-english-currency-denominations/ )
int waysOfCoinSums();

//34.各位之阶乘之和是否等于其自身
int isDigitFactorial(int a);

//34.
int sumOfDigitFactorials();


int	findGreatestConsecutive(int a[], int len);	//8.
int	greatestProduct(int *a, int n);		//同一排相邻位置四个数的乘积最大的		//11.
int	maxChain();							//14.
int	maxPathSum(int * a, int n);			//18.
int sumOfTrancatablePrimes(int n);		//37.
int minDOfPentagonPairs();				//44.失败！
int minDOfPentagonPairs2();				//44.
int nextTriangleNumber();				//45.
int minGoldbachOtherConjecture();		//46.