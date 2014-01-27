// =====
// INSA Lyon, Département Informatique
// TP C++ 3IF :  Héritage et polymorphisme
// Auteur : B3229
// =====

#include "Interpreter.h"

// trim from start
static inline std::string &ltrim(std::string &s)
{
	s.erase(s.begin(), std::find_if(s.begin(), s.end(), std::not1(std::ptr_fun<int, int>(std::isspace))));
	return s;
}

// trim from end
static inline std::string &rtrim(std::string &s)
{
	s.erase(std::find_if(s.rbegin(), s.rend(), std::not1(std::ptr_fun<int, int>(std::isspace))).base(), s.end());
	return s;
}

// trim from both ends
static inline std::string &trim(std::string &s)
{
	return ltrim(rtrim(s));
}

Interpreter::Interpreter()
{
	// Initialise la base de données de commandes connues
	commandName[std::string("C")] = CommandCode::CIRCLE;
		commandInfos[CommandCode::CIRCLE] = new CommandInfo(4);
	commandName[std::string("R")] = CommandCode::RECTANGLE;
		commandInfos[CommandCode::RECTANGLE] = new CommandInfo(5);
	commandName[std::string("L")] = CommandCode::LINE;
		commandInfos[CommandCode::LINE] = new CommandInfo(5);
	commandName[std::string("PL")] = CommandCode::POLYLINE;
		commandInfos[CommandCode::POLYLINE] = new CommandInfo(-1);
	commandName[std::string("OA")] = CommandCode::AO;
		commandInfos[CommandCode::AO] = new CommandInfo(-1);
	commandName[std::string("DELETE")] = CommandCode::DELETE;
		commandInfos[CommandCode::DELETE] = new CommandInfo(-1);
	commandName[std::string("MOVE")] = CommandCode::MOVE;
		commandInfos[CommandCode::MOVE] = new CommandInfo(3);
	commandName[std::string("LIST")] = CommandCode::LIST;
		commandInfos[CommandCode::LIST] = new CommandInfo(0);
	commandName[std::string("UNDO")] = CommandCode::UNDO;
		commandInfos[CommandCode::UNDO] = new CommandInfo(0);
	commandName[std::string("REDO")] = CommandCode::REDO;
		commandInfos[CommandCode::REDO] = new CommandInfo(0);
	commandName[std::string("LOAD")] = CommandCode::LOAD;
		commandInfos[CommandCode::LOAD] = new CommandInfo(1);
	commandName[std::string("SAVE")] = CommandCode::SAVE;
		commandInfos[CommandCode::SAVE] = new CommandInfo(1);
	commandName[std::string("CLEAR")] = CommandCode::CLEAR;
		commandInfos[CommandCode::CLEAR] = new CommandInfo(0);
	commandName[std::string("EXIT")] = CommandCode::EXIT;
		commandInfos[CommandCode::EXIT] = new CommandInfo(0);	
}

Interpreter::~Interpreter()
{
	for(std::map<CommandCode,CommandInfo*>::iterator it = commandInfos.begin();
			it != commandInfos.end();
			++it)
	{
		delete it->second;
	}
}

CommandFeedback* Interpreter::Read(std::string pLine)
{
	trim(pLine);
	std::istringstream iss(pLine);
	CommandFeedback *feedback = new CommandFeedback();
	// Splitte la chaîne en deque de string selon les espaces
	std::copy(std::istream_iterator<std::string>(iss),
							std::istream_iterator<std::string>(),
							std::back_inserter<std::deque<std::string>>(feedback->Args));
	
	feedback->Code = getCodeFromStr(feedback->Args.front());
	if(feedback->Code == CommandCode::NULLC)
	{
		feedback->Status = CommandStatus::BAD_COMMAND;
	}
	else
	{
		feedback->Args.pop_front();
		CommandInfo *info = commandInfos[feedback->Code];
		if(info->ParamNb >= 0 && info->ParamNb != feedback->Args.size())
		{
			feedback->Status = CommandStatus::BAD_PARAM_NB;
		}
		else
		{
			feedback->Status = CommandStatus::OK;
		}
	}
	return feedback;
}

CommandCode Interpreter::getCodeFromStr(std::string pKey)
{
	// Dé-sensibilise à la casse
	std::transform(pKey.begin(),pKey.end(),pKey.begin(),::toupper);
	std::map<std::string,CommandCode>::iterator it = commandName.find(pKey);
	if(it == commandName.end())
	{
		return CommandCode::NULLC;
	}
	else
	{
		return it->second;
	}
}

