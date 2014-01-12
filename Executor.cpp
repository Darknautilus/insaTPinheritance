#include "Executor.h"

Executor::Executor(Interpreter *pInterpreter) : interpreter(pInterpreter)
{}

Executor::~Executor()
{}

void Executor::Execute(CommandFeedback *feedback)
{
	if(feedback->Status == CommandStatus::OK)
	{
		// OK
		if(feedback->Args.size() == 0)
		std::cout << "Result: " << feedback->Status << std::endl;
	}
	else
	{
		printStatus(feedback->Status);
	}
}
