
#include"Command.h"
namespace controller
{
	void Command::execute()
	{
		// like the Template Methode Pattern
		checkPreCondition();
		executeImpl();
		checkPostCondition();
	}
	void Command::undo()
	{
		undoImpl();
	}
	Command * Command::clone() const
	{
		return cloneImpl();
	}
	const char * Command::getHelp() const
	{
		return getHelpImpl();
	}
	void Command::release()
	{
		delete this;
	}
}