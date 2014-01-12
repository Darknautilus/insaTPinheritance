#include <iostream>

#include "Interpreter.h"
#include "Executor.h"

int main(int argc, const char **argv)
{
	std::string input;
	Interpreter inter;
	Executor executor(&inter);
	CommandFeedback *feedback;
	while(true)
	{
		std::cout << ">>" << std::flush;
		std::getline(std::cin,input);
		if(!input.empty())
		{
			feedback = inter.Read(input);
			executor.Execute(feedback);
			delete feedback;
		}
	}

	return 0;
}
