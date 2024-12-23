#include <iostream>
#include <regex>
#include <fstream>

int main()
{
	std::ifstream input_file("input.txt");
	std::regex pattern(R"((mul\((\d+),(\d+)\))|do\(\)|don't\(\))");

	int answer = 0;
	bool valid = true;
	std::string line;

	while (std::getline(input_file, line))
	{
		std::sregex_iterator begin(line.begin(), line.end(), pattern);
		std::sregex_iterator end;
		
		for (std::sregex_iterator it = begin; it != end; ++it)
		{
			if ((*it)[0].str() == "do()")
				valid = true;

			if ((*it)[0].str() == "don't()")
				valid = false;

			if ((*it)[1].matched)
			{
				int x = std::stoi((*it)[2].str());
				int y = std::stoi((*it)[3].str());
				
				if (valid)
					answer += (x * y);
			}
		}	
	}

	input_file.close();
	std::cout << answer << std::endl;

	return 0;
}
