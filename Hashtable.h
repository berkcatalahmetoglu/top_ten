#include <iostream> 
#include<string> 
#include<fstream>
#include <chrono>
#include<sstream>

using namespace std;

const unsigned long int Table_Size= 600000;


class HashEntry
{

public:

	string key;
	string value;//countu string olarak almýþtýk hata yaratabýlýr
	string description;
	HashEntry(string key,string description, string value )
	{
		this->key = key;
		this->description = description;
		this->value = value;
	}

	string getKey()	{return key;}
	//int getValue()	{return value;}
	/*void setValue(int value)
	{
		this->value = value;
	}*/


};

class HashMap
{
private:
	HashEntry **table;
	HashEntry **sortedArray;

public:
	int a[100];
	HashMap();
	bool indexhashtablebosmu(string);
	unsigned long int Hashfunc(string);//we use djb2 function from www.cse.yorku.ca/~oz/hash.html
	void Insert(string,string,int);
	void print();
	void search();
	void printa();
	void topTen();

	void swap(HashEntry**, HashEntry**);
	void quickSort(int* , int , int );
	void printArray(int* , int );
	void printTopTen();
};


