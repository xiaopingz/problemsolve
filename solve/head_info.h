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

//�������
int isPrimeNum(int n);					// n�Ƿ�Ϊ����,�ǣ�����1���񣬷���0
long long int sumOfPrime(long int n );	//	С��n����������֮��				//10.
int primeNumber(int n);					//���������У���n�������Ƕ���			//7.
bool	isCirclePrime(int n);			//n�ĸ�λȫ����֮������־�Ϊ����
int		numOfCirclePrimes(int n);		//С��n��circle prime�ĸ���			//35.
bool	isTrancatablePrime(int n);		//���������νض��Ƿ���������37��

//��ѧ��ʽ���
bool	isPentagonalNumber(int n);		//pentagonal number:Pn=n(3n?1)/2
bool	isHexagonalNumber(int n);		//Hexagonal number:	Hn=n(2n?1)

//����ά��������±�ת��Ϊ��Ӧ��һά������±�
int transform(int n, int i, int j );	//nΪ����Ľ�����������Ϊn*n��

//�������
int divisorNum(int n);					//��n�������ĸ���
int sumOfDivisor(int n);				//��n������֮��(������n/2)			//21.
int	sumOfAmicableNumbers();				//С��10000.����֮�͵�������			//22.
int isAbundantNumber(int n);
int sumOfNonANSum();					//��������abundant number�ĺ͵�����������֮��	//23.

//��n��...
int triangleNum(int n);
int highlyDivisibleTriangularNumber();	//12.

//��ĸ������֮�����ת��
int		digitNumbers(int d);			//��d��λ����10���ƣ�
char *	intToStr(int n);
int		strToInt(char * a, int len);
void	printCharArray(char * a, int len);

int	numberLetterCounts(int n);			//1000���ڣ����������������֣�Ӣ�ı�ʾʱ����ĸ������
int	sumOfLetterCounts();				//1~1000���������֣���ĸ�����ܺ�		//17.
int worthOfWord(std::string str);											//22.
//MapWWPtr	makeWordsMap(std::string str);	//���ɴ��и����ʼ���worth��map
//long long	int	sumOfNameScores(MapWWPtr pMapWW);	//����map�����ַ�����λ�õ��ܺ�	//22.

bool	isPalindromic(char * a,int len);	//�Ƿ����
bool	isPalBothBases(int n);			//n��ʮ���ƺͶ����Ʊ�ʾ����Ҫǰ���0���Ƿ�Ϊ����
int		sumOfPal(int n);				//С��n�Ļ��ģ�ʮ���ƺͶ����ƣ�����֮��
bool	isSubStrDivisible(char *a,int len);	//(43.)

//�������
int isLeapYear(int year);				//�Ƿ�Ϊ����
int sundayCounts();						//����������һ���µĵ�һ��ĸ���		//19.


int		numOfRecurringCycle(int d);		//��1/d��ѭ��λ��

void	fullPermut(char * a,int k, int n);	//ȫ����
int		factorial(int n);					//��׳�


void	lexicographicPermutations(char *a, int n);							//24.
void	setTheBit(int &t, int i, char *a);
int		findChar(char *a, int n, char c);
void	lexicographicPermutations2(char *a, int n);							//24_2.
void	findLargestPandigitalPrime(char *a, int n);							//41.
void	sumOfSubStrDivisible(char *a, int n);								//43.

//����ʱĩβ����(��n���㣬���һ��10)
void	mutliplyTen(int &a, int n);

//26.��С����ѭ��С����λ������һλ��1/d��dС��1000��
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

//34.��λ֮�׳�֮���Ƿ����������
int isDigitFactorial(int a);

//34.
int sumOfDigitFactorials();


int	findGreatestConsecutive(int a[], int len);	//8.
int	greatestProduct(int *a, int n);		//ͬһ������λ���ĸ����ĳ˻�����		//11.
int	maxChain();							//14.
int	maxPathSum(int * a, int n);			//18.
int sumOfTrancatablePrimes(int n);		//37.
int minDOfPentagonPairs();				//44.ʧ�ܣ�
int minDOfPentagonPairs2();				//44.
int nextTriangleNumber();				//45.
int minGoldbachOtherConjecture();		//46.