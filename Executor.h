// =====
// INSA Lyon, Département Informatique
// TP C++ 3IF :  Héritage et polymorphisme
// Auteur : B3229
// =====

#ifndef EXECUTOR_H
#define EXECUTOR_H

#include <stdexcept>

#include "Config.h"

#include "Agregated.h"
#include "Circle.h"
#include "Rectangle.h"
#include "Line.h"
#include "Polyline.h"

class Controller;
class Interpreter;
class CommandFeedback;
class FileCommand;

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
