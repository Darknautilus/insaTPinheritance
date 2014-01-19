// =====
// INSA Lyon, Département Informatique
// TP C++ 3IF :  Héritage et polymorphisme
// Auteur : B3229
// =====

#ifndef EXECUTOR_H
#define EXECUTOR_H

#include <fstream>

#include "Interpreter.h"
#include "FileCommand.h"

class Controller;

class Executor
{
	public:
		Executor(Interpreter*);
		virtual ~Executor();

		bool Execute(CommandFeedback*,FileCommand* = 0);

	private:
		Interpreter *interpreter;
		Controller *controller;
};

#endif
