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
	if(DEBUG)
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
					std::cout << "Fichier exitant, écraser ? (o/N)";
					std::string input;
					std::getline(std::cin,input);
					if(input.compare("o") != 0)
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
					std::cout << "# save cancelled" << std::endl;
				}
				else
				{
					std::cout << "Error" << std::endl;
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
						std::cout << "Error 2" << std::endl;
					}
				}
				else
				{
					std::cout << "Error 1" << std::endl;
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
				bool moved = controller->Move(feedback->Args[0],&direction,pFCommand);
				if(pFCommand == 0 && moved)
				{
					printStatus(feedback->Status);
				}
			}
			else
			{
				std::cout << "Error" << std::endl;
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
			}
			else
			{
				std::cout << "Vide" << std::endl;
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
					std::cout << "bad values" << std::endl;
				}
				else
				{
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
							for(int i = 0; i < intArgs.size(); i+=2)
							{
								((Polyline*)element)->Add(new Point(intArgs.at(i),intArgs.at(i+1)));
							}
							break;
						case CommandCode::AO:
							break;
						default:
							break;
					}
					bool added = controller->Add(feedback->Args.at(0),element,pFCommand);
					if(pFCommand == 0 && added)
					{
						printStatus(feedback->Status);
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
