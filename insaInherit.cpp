// =====
// INSA Lyon, Département Informatique
// TP C++ 3IF :  Héritage et polymorphisme
// Auteur : B3229
// =====

#include <iostream>

#include "Executor.h"
#include "Interpreter.h"

int main(int argc, const char **argv)
{
	std::string input;
	Interpreter inter;
	Executor executor(&inter);
	CommandFeedback *feedback;
	bool again = true;
	while(again)
	{
		std::cout << ">>" << std::flush;
		std::getline(std::cin,input);
		if(!input.empty())
		{
			feedback = inter.Read(input);
			again = executor.Execute(feedback);
			delete feedback;
		}
	}

	return 0;
}
