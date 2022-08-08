#include "Dispatcher.h"
/*
	Copyright (C) 2022  Barth.Feudong
	Author can be contacted here: <https://github.com/mrSchaffman/Cpp-Calculator>

	This file is part of the Calculator project.
	using the COM, the win32 API for the GUI,
	the MVC Architecture.

	Calculator is free software: you can redistribute it and/or modify
	it under the terms of the GNU General Public License as published by
	the Free Software Foundation, either version 3 of the License, or
	(at your option) any later version.

	Calculator is distributed in the hope that it will be useful,
	but WITHOUT ANY WARRANTY; without even the implied warranty of
	MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
	GNU General Public License for more details.

	You should have received a copy of the GNU General Public License
	along with this program.  If not, see <https://www.gnu.org/licenses/>.

*/

#include"Command.h"
#include"CommandRegistry.h"
#include"Exception.h"
#include<regex>
#include<sstream>
namespace controller
{
	class Dispatcher::DispatcherImpl
	{
	public:
		explicit DispatcherImpl(view::UserInterface&ui) :m_ui{ ui } {}
		void execute(const std::string& command);
		void printHelp()const;
		bool isDigit(const std::string&cmd, double&d);
	private:
		view::UserInterface&m_ui;
	};

	Dispatcher::Dispatcher(view::UserInterface & ui)
	{
		pImpl = std::make_unique<DispatcherImpl>(ui);
	}

	Dispatcher::~Dispatcher()
	{
	}

	void Dispatcher::onCommandEntered(const std::string & cmd)
	{
		pImpl->execute(cmd);
	}

	void Dispatcher::DispatcherImpl::execute(const std::string & cmd)
	{
		double d;
		if (cmd == "help")
			printHelp();
		//else if (isDigit(cmd,d))
		//	// todo
		//else if (cmd == "undo")
		//	// todo
		//else if (cmd == "redo")
		//	// todo
		else
		{
			auto c = CommandRegistry::getInstance().getCommandByName(cmd);
			if (!c)
			{
				std::ostringstream oss;
				oss << "Command '" << cmd << "' is undefined";
				m_ui.updateDisplay(oss.str());
			}

			try
			{
				// pass the Command to the Manager...
				// to do
			}
			catch (utility::Exception&e)
			{
				m_ui.updateDisplay(e.what());
			}
		}
	}

	void Dispatcher::DispatcherImpl::printHelp() const
	{
		std::ostringstream oss;
		oss << "-----------------------------------\n"
			<< "----undo: undo last operation.\n---"
			<< "----redo: redo last operation.\n---";
		set<string> cmdNames = CommandRegistry::getInstance().getAllCommandNames;
		for (auto& name : cmdNames)
			oss << "----" << CommandRegistry::getInstance().getCommandByName(name)->getHelp() << "---\n";

		m_ui.updateDisplay(oss.str());
	}

	bool Dispatcher::DispatcherImpl::isDigit(const std::string & cmd, double & d)
	{
		if (cmd == "+" || cmd == "-") return false;

		std::regex dpRegex("((\\+|-)?[[:digit:]]*)(\\.(([[:digit:]]+)?))?((e|E)((\\+|-)?)[[:digit:]]+)?");
		bool isNumber{ std::regex_match(cmd, dpRegex) };

		if (isNumber)
		{
			d = std::stod(cmd);
		}

		return isNumber;
	}

}
