#pragma once

#include<iostream>


class Folder
{
private:
	Folder* parent = nullptr; 
	int fileAmount;
	int folderAmount;
	std::string name;
	int size;
	struct tm* ti;
	File files[10];
	Folder* folders[5]; 

public:
	Folder(std::string newName)
	{
		name = newName;

		//Selects a random number from 1-100
		size = rand() % 100 + 1;

		//Sets the time and date
		time_t tt;

		time(&tt);

		ti = localtime(&tt);
	}
	std::string getFolderName()
	{
		return name;
	}

	int getSize()
	{
		return size;
	}

	std::string getDate()
	{
		return asctime(ti);
	}

	int getFileAmount()
	{
		return fileAmount;
	}

	int getFolderAmount()
	{
		return folderAmount;
	}


	void changeFolderName(std::string newName)
	{
		name = newName;
	}


	// Prints the folder info
	void printFolder()
	{
		std::cout << name << " ";
		std::cout << size << " ";
		std::cout << asctime(ti) << " \n";

	}

	//Adds files
	void addFile(std::string newName)
	{
		//If there are less then 10 files in a filder
		if (fileAmount < 10)
		{
			files[fileAmount] = File(newName);
			fileAmount++;
		}
		//If there is more then 10 files
		else
		{
			//"\x1b[31m" sets the color to red and "\x1b[0m" resets the color.
			std::cout << "\x1b[31m""Error max files is 10""\x1b[0m""\n";
		}
	}

	void addFolder(std::string newName)
	{
		//If there is less then 5 folders
		if (folderAmount < 5)
		{
			folders[folderAmount] = new Folder(newName);
			folderAmount++;
		}
		//If there is more then 5 folders
		else
		{
			//"\x1b[31m" sets the color to red and "\x1b[0m" resets the color.
			std::cout << "\x1b[31m""Error max folder is 5""\x1b[0m""\n";
		}
	}



	void print()
	{
		//If the folder is the "Root folder
		if (parent == nullptr)
		{
			std::cout << "Folder: " << name << " \n";
		}
		//If the folder is inside another folder
		else
		{
			std::cout << "Folder: " << parent->getFolderName() << "/" << name;
		}
		//Prints out the files
		for (int i = 0; i < fileAmount; i++)
		{
			std::cout << "File: " << files[i].getName() << " Size: " << files[i].getSize() << " Date: ";
			files[i].getDate();

		}
		//Prints out the folders inside
		for (int i = 0; i < folderAmount; i++)
		{
			if (folders[i])
			{
				std::cout << "\n";
				folders[i]->print();
			}
		}
	}

	//Select the next folder
	Folder* selectFolder()
	{
		for (int i = 0; i < folderAmount; i++)
		{
			std::cout << i + 1 <<" " << folders[i]->name <<"\n";
		}
		int input;
		std::cin >> input;
		return folders[input-1];

	}

	//Prints out the largest file
	std::string largestFile() 
	{
		int largest = 0;

		for (int i = 0; i < fileAmount; i++)
		{
			if (files[i].getSize() > largest) 
			{
				largest = files[i].getSize();
			}
		}
		for (int i = 0; i < fileAmount; i++)
		{
			if (files[i].getSize() == largest) 
			{
				return files[i].getName();
			}
		}

	}

	void reName()
	{
		std::cout << "Select a folder or file: \n";

		//Prints out folders
		for (int i = 0; i < folderAmount; i++)
		{
			std::cout << i+1 << ". " << folders[i]->name << "\n";
		}

		//Print out files
		for (int i = 0; i < fileAmount; i++)
		{
			std::cout << i + folderAmount +1 << ". " << files[i].getName() << "\n";
		}
		int input;
		std::cin >> input;
		if (input<folderAmount)
		{
			std::cout << "Rename ";
			std::string newName;
			std::cin >> newName;
			for (int i = 0; i < folderAmount; i++)
			{
			folders[input-1]->name = newName;
			}
		}
		if (input > folderAmount)
		{
			std::cout << "Rename ";
			std::string newName;
			std::cin >> newName;
			for (int i = 0; i < fileAmount; i++)
			{
				files[input-folderAmount-1].fileReName(newName);
			}
		}
	}
};