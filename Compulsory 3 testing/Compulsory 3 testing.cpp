#include"File.h"
#include"Folder.h"
#include<iostream>
#include<vector>




int main()
{
	bool Running = true;
	int start = 0;
	
	//Creats a seed for random
	srand(time(NULL));
	std::vector<Folder*>backTrack{};
	std::string fileName;
	std::string folderName;

	//Makes the "root" folder and sets it to local
	Folder root("Root");
	Folder* Local = &root;

	//Make folders and files
	root.addFile("File1");
	root.addFile("File2");
	
	root.addFolder("Big");
	root.addFolder("Gunnar");


	do
	{
		
		std::cout << "You are in: " << Local->getFolderName() << "\n";
		std::cout << "1. Create a new folder\n";
		std::cout << "2. Create new files\n";
		std::cout << "3. Select a folder\n";
		std::cout << "4. Rename a folder/file\n";
		std::cout << "5. Find the largest file\n";
		std::cout << "6. Print folders and files\n";
		std::cout << "7. Back\n";
		std::cout << "8. Quit\n";
		std::cin >> start;
		switch (start)
		{
		case 1:
			//Creats a new folder
			std::cout << "Folder name: \n";
			std::cin >> folderName;
			Local->addFolder(folderName);

			break;
		case 2:
			//Creats a new file 
			std::cout << "File name: \n";
			std::cin >> fileName;
			Local->addFile(fileName);

			break;

		case 3:
			//select a folder
			
			std::cout << "Select a folder: \n";
			backTrack.push_back(Local);
			Local = Local->selectFolder();
			
			break;
		case 4:
			//rename folder/file
			Local->reName();

			break;
		case 5:
			//Largest file
			std::cout << "The largest file is: " << Local->largestFile() << "\n";

			break;
		case 6:
			//Prints out all the folders and files
			Local->print();

			break;

		case 7:
			//Goes back one step
			Local = backTrack.back();

			break;
		case 8:
			//Quits the program
			return false;

		default:
			//Prints out 4 "errors" 
			for (int i = 0; i < 4; i++)
			{
				std::cout << "\x1b[31m""Error!""\x1b[0m""\n";
			}
			std::cout << "Select a valid option \n";
			//Clears out cin value and resetts it (This took me a while to figure out)
			std::cin.clear();
			std::cin.ignore(100, '\n');

		}

	}

	while (start !=8);

}

