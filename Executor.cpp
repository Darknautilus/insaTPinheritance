// =====
// INSA Lyon, Département Informatique
// TP C++ 3IF :  Héritage et polymorphisme
// Auteur : B3229
// =====

#include "Controller.h"
#include "Executor.h"

Executor::Executor(Interpreter *pInterpreter) : interpreter(pInterpreter)
{
	controller = new Controller();
}

Executor::~Executor()
{
	if(constants::DEBUG)
		std::cout << "Executor destroyed" << std::endl;
	delete controller;
}

bool Executor::Execute(CommandFeedback *feedback, FileCommand *pFCommand)
{
	if(feedback->Status == CommandStatus::OK)
	{
		if(feedback->Code == CommandCode::EXIT)
		{
			return false;
		}
		else if(feedback->Code == CommandCode::CLEAR)
		{
			if(pFCommand == 0)
			{
				controller->Clear();
				printStatus(feedback->Status);
			}
		}
		else if(feedback->Code == CommandCode::UNDO)
		{
			if(pFCommand == 0)
			{
				controller->Undo();
				printStatus(feedback->Status);
			}
		}
		else if(feedback->Code == CommandCode::REDO)
		{
			if(pFCommand == 0)
			{
				controller->Redo();
				printStatus(feedback->Status);
			}
		}
		else if(feedback->Code == CommandCode::LIST)
		{
			controller->List();
		}
		else if(feedback->Code == CommandCode::SAVE)
		{
			if(pFCommand == 0)
			{
				bool write = true;
				if(std::ifstream(feedback->Args.front()).good())
				{
					std::cout << "File already exists, overwrite? (y/N)";
					std::string input;
					std::getline(std::cin,input);
					if(input.compare("y") != 0)
					{
						write = false;
					}
				}
				if(write && controller->SaveInFile(feedback->Args.front()))
				{
					printStatus(feedback->Status);
				}
				else if(!write)
				{
					printMessage("writing cancelled by user");
				}
				else
				{
					printStatus(CommandStatus::GENERIC_ERROR);
					printMessage("error writing in the file");
				}
			}
		}
		else if(feedback->Code == CommandCode::LOAD)
		{
			if(pFCommand == 0)
			{
				if(std::ifstream(feedback->Args.front()).good())
				{
					if(controller->LoadFromFile(feedback->Args.front(), interpreter, this))
					{
						printStatus(feedback->Status);
					}
					else
					{
						printStatus(CommandStatus::GENERIC_ERROR);
						printMessage("error loading the file");
					}
				}
				else
				{
					printStatus(CommandStatus::GENERIC_ERROR);
					printMessage("file could't be opened");
				}
			}
		}
		else if(feedback->Code == CommandCode::MOVE)
		{
			int x,y;
			bool isInt = true;
			try
			{
				x = std::stoi(feedback->Args[1]);
				y = std::stoi(feedback->Args[2]);
			}
			catch(std::invalid_argument ia)
			{
				isInt = false;
			}
			catch(std::out_of_range oor)
			{
				isInt = false;
			}
			if(isInt)
			{
				Point direction(x,y);
				bool moved = controller->Move(feedback->Args[0],direction,pFCommand);
				if(pFCommand == 0 && moved)
				{
					printStatus(feedback->Status);
				}
				else if(!moved)
				{
					printStatus(CommandStatus::GENERIC_ERROR);
					printMessage("error moving the element");
				}
			}
			else
			{
				printStatus(CommandStatus::GENERIC_ERROR);
				printMessage("some arguments aren't in good format");
			}
		}
		else if(feedback->Code == CommandCode::DELETE)
		{
			if(!feedback->Args.empty())
			{
				std::vector<std::string> names;
				for(int i = 0; i < feedback->Args.size(); i++)
				{
					names.push_back(feedback->Args.at(i));
				}
				bool deleted = controller->Delete(names,pFCommand);
				if(pFCommand == 0 && deleted)
				{
					printStatus(feedback->Status);
				}
				else if(!deleted)
				{
					printStatus(CommandStatus::GENERIC_ERROR);
					printMessage("some elements couldn't be deleted");
				}
			}
			else
			{
				printStatus(CommandStatus::BAD_PARAM_NB);
			}
		}
		else
		{
			// ADD command
			GeoElt *element;
			
			int argsNb = feedback->Args.size();
			// Cas ou la commande est valide :
			// 	Il y a au moins 2 arguments (nom + autre)
			// 		ET
			// 		C'est une polyligne et il y a un nombre impair d'arguments
			// 			OU
			// 		C'est un autre objet
			//
			if(	argsNb >= 2
						&&
					(
						(feedback->Code == CommandCode::POLYLINE && argsNb % 2 == 1)
							||
						feedback->Code != CommandCode::POLYLINE
					)
				)
			{
				std::vector<int> intArgs;
				bool parsageError = false;
				// Si ce n'est pas un Objet Agrégé, les paramètres sont des int, et on les extrait
				if(feedback->Code != CommandCode::AO)
				{
					for(int i = 1; i < argsNb; i++)
					{
						try
						{
							intArgs.push_back(std::stoi(feedback->Args.at(i)));
						}
						catch(std::invalid_argument ia)
						{
							parsageError = true;
						}
						catch(std::out_of_range oor)
						{
							parsageError = true;
						}
						if(parsageError)
							break;
					}
				}
				if(parsageError)
				{
					printStatus(CommandStatus::GENERIC_ERROR);
					printMessage("some arguments aren't in the good format");
				}
				else
				{
					bool isError = false;
					int addError;
					switch(feedback->Code)
					{
						case CommandCode::CIRCLE:
							element = new Circle(intArgs.at(0),intArgs.at(1),intArgs.at(2));
							break;
						case CommandCode::RECTANGLE:
							element = new Rectangle(new Point(intArgs.at(0),intArgs.at(1)), new Point(intArgs.at(2), intArgs.at(3)));
							break;
						case CommandCode::LINE:
							element = new Line(new Point(intArgs.at(0),intArgs.at(1)), new Point(intArgs.at(2),intArgs.at(3)));
							break;
						case CommandCode::POLYLINE:
							element = new Polyline();
							addError = 0;
							for(int i = 0; i < intArgs.size(); i+=2)
							{
								if(!((Polyline*)element)->Add(new Point(intArgs.at(i),intArgs.at(i+1))))
									addError++;
							}
							if(addError > 0)
							{
								printStatus(CommandStatus::GENERIC_ERROR);
								printMessage("some points couldn't be added");
								isError = true;
							}
							break;
						case CommandCode::AO:
							element = new Agregated();
							GeoElt *nElement;
							addError = 0;
							for(int i = 1; i < feedback->Args.size(); i++)
							{
								if((nElement = controller->Exists(feedback->Args.at(i))) != 0)
								{
									if(!((Agregated*)element)->Add(feedback->Args.at(i), nElement))
										addError++;
								}
								else
								{
									addError++;
								}
							}
							if(addError > 0)
							{
								printStatus(CommandStatus::GENERIC_ERROR);
								printMessage("some elements couldn't be agregated");
								isError = true;
							}
							break;
						default:
							break;
					}
					if(!isError)
					{
						bool added = controller->Add(feedback->Args.at(0),element,pFCommand);
						if(pFCommand == 0 && added)
						{
							printStatus(feedback->Status);
						}
						else if(!added)
						{
							printStatus(CommandStatus::GENERIC_ERROR);
						}
					}
				}
			}
			else
			{
				printStatus(CommandStatus::BAD_PARAM_NB);
			}
		}
	}
	else
	{
		printStatus(feedback->Status);
	}
	return true;
}
