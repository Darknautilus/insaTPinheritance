// =====
// INSA Lyon, Département Informatique
// TP C++ 3IF :  Héritage et polymorphisme
// Auteur : B3229
// =====

#include <unistd.h>
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
		// Permet de n'afficher les >> que si c'est un humain qui utilise le programme
		// Attention, isatty n'est pas portable sur Windows
		if(isatty(STDOUT_FILENO))
		{
			std::cout << constants::INPUT_MARK << std::flush;
		}
		std::getline(std::cin,input);
		if(!input.empty() && input.at(0) != constants::COMMENT_CHAR)
		{
			feedback = inter.Read(input);
			again = executor.Execute(feedback);
			delete feedback;
		}
	}

	return 0;
}
