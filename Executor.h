#ifndef EXECUTOR_H
#define EXECUTOR_H

#include "Interpreter.h"
#include "Controller.h"

class Executor
{
	public:
		Executor(Interpreter*);
		virtual ~Executor();

		bool Execute(CommandFeedback*);

	private:
		Interpreter *interpreter;
		Controller controller;
};

#endif
