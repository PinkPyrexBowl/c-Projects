#include <fstream>
#include <iostream>
#include <vector>

int main()
{
	std::ifstream file;
	file.open("input.txt");
	std::vector<char> chars;
	if (!file.is_open())
	{
		std::cout << "The input file input.txt could not be opened.";
		std::flush(std::cout);
		return EXIT_FAILURE;
	}
	char temp;
	while (!file.eof())
	{
		file.get(temp);
		chars.push_back(temp);
	}
	std::cout << "Enter the character to search for: ";
	std::cin >> temp;
	int count = 0;
	std::string locs;
	for (int i = 0; i < chars.size(); i++)
	{
		if(temp == chars.at(i))
		{
			count++;
			locs += std::to_string(i) + " ";
		}
	}
	std::cout << "The number of occurrences of the character " << temp << " is " << count;
	if(0 != count)
	{
		std::cout << "\nThe indices of the character positions are " << locs;
		std::flush(std::cout);
	}
	file.close();
	return 0;
}
