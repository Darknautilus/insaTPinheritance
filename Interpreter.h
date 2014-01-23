// =====
// INSA Lyon, Département Informatique
// TP C++ 3IF :  Héritage et polymorphisme
// Auteur : B3229
// =====

#ifndef INTERPRETER_H
#define INTERPRETER_H

#include <iostream>
#include <string>
#include <list>
#include <deque>
#include <map>
#include <algorithm>
#include <sstream>
#include <iterator>

enum CommandCode
{
	NULLC,
	CIRCLE,
	RECTANGLE,
	LINE,
	POLYLINE,
	AO,
	DELETE,
	MOVE,
	LIST,
	UNDO,
	REDO,
	LOAD,
	SAVE,
	CLEAR,
	EXIT
};

enum CommandStatus
{
	OK,
	GENERIC_ERROR,
	BAD_COMMAND,
	BAD_PARAM_NB
};

inline void printMessage(std::string pMessage)
{
	std::cout << "#" << pMessage << std::endl;
}

inline void printStatus(CommandStatus pStatus)
{
	if(pStatus ==  CommandStatus::OK)
	{
		std::cout << "OK" << std::endl;
	}
	else
	{
		std::cout << "ERR" << std::endl;
		switch(pStatus)
		{
			case CommandStatus::GENERIC_ERROR:
				//printMessage("an error occured");
				break;
			case CommandStatus::BAD_COMMAND:
				printMessage("invalid command");
				break;
			case CommandStatus::BAD_PARAM_NB:
				printMessage("invalid parameters");
				break;
			default:
				break;
		}
	}
}

struct CommandInfo
{
	CommandInfo(int pParamNb) : ParamNb(pParamNb) {}
	int ParamNb;
};

struct CommandFeedback
{
	CommandCode Code;
	std::deque<std::string> Args;
	CommandStatus Status;
};

class Interpreter
{
	public:
		Interpreter();
		virtual ~Interpreter();

		CommandFeedback* Read(std::string);
	
	private:
		CommandCode getCodeFromStr(std::string);

		std::map<std::string,CommandCode> commandName;
		std::map<CommandCode,CommandInfo*> commandInfos;
		
};

#endif
