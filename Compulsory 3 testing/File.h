#pragma once
#pragma warning (disable : 4996)
#include<iostream>
#include<stdlib.h>
#include<stdio.h>
#include<time.h>

class File
{
private:
	std::string name;
	int size;
	struct tm* ti;



public:

	File()
	{
		name = "";

		size = rand() % 100 + 1;

		time_t tt;

		time(&tt);

		ti = localtime(&tt);
	}

File(std::string newName)
{
	name = newName;

	size = rand() % 100 + 1;

	time_t tt;

	time(&tt);

	ti = localtime(&tt);
}

std::string getName()
{
	return name;
}

int getSize()
{
	return size;
}

void getDate()
{
	std::cout<< asctime(ti);
}

void fileReName(std::string newName)
{
	name = newName;
}

void printFileData()
{
	std::cout << name << " ";
	std::cout << size << " ";
	std::cout << asctime(ti) << " \n";

}
};




