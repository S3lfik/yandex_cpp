#include <vector>
#include <string>
#include <iostream>

void WORRY(std::vector<bool>& vec, const int& val);
void QUIET(std::vector<bool>& vec, const int& val);
void COME(std::vector<bool>& vec, const int& val);
void WORRY_COUNT(const std::vector<bool>& vec);
void runCommand(const std::string& command, std::vector<bool>& vec);

int main()
{
	std::string command;
	std::vector<bool> queue;
	int commandsNumber = 0;

	std::cin >> commandsNumber;
	for (int i = 0; i < commandsNumber; ++i)
	{
		std::cin >> command;
		runCommand(command, queue);
	}
	
	return 0;
}

void runCommand(const std::string& command, std::vector<bool>& vec)
{
	int arg = 0;
	if (command == "WORRY")
	{		
		std::cin >> arg;
		WORRY(vec, arg);
	}
	else if (command == "QUIET")
	{
		std::cin >> arg;
		QUIET(vec, arg);
	}
	else if (command == "COME")
	{
		std::cin >> arg;
		COME(vec, arg);
	}
	else if (command == "WORRY_COUNT")
	{
		WORRY_COUNT(vec);
	}
}

void WORRY(std::vector<bool>& vec, const int& val)
{
	vec[val] = true;
}

void QUIET(std::vector<bool>& vec, const int& val)
{
	vec[val] = false;
}

void COME(std::vector<bool>& vec, const int& val)
{
	vec.resize(vec.size() + val);
}

void WORRY_COUNT(const std::vector<bool>& vec)
{
	int res = 0;
	for (auto itr : vec)
	{
		if (itr)
		{
			res++;
		}
	}

	std::cout << res << std::endl;
}