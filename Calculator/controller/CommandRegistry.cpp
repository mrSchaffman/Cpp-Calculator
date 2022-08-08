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

#include "CommandRegistry.h"
#include<unordered_map>
#include<sstream>
#include"Exception.h"
namespace controller
{
	class CommandRegistry::CommandRegistryImpl
	{
	public:
		CommandRegistryImpl() = default;
		~CommandRegistryImpl() = default;

		void addCommand(const string name, CommandPtr cmd);
		CommandPtr removeCommand(const string name);

		size_t count() { return m_commands.size(); }
		CommandPtr getCommandByName(const string& name)const;
		set<string>& getAllCommandNames()const;

	private:
		std::unordered_map< string, CommandPtr> m_commands;
	};

	CommandRegistry & CommandRegistry::getInstance()
	{
		static CommandRegistry instance;
		return instance;
	}
	void CommandRegistry::addCommand(const string name, CommandPtr cmd)
	{
		pImpl->addCommand(name, std::move(cmd));
	}
	CommandPtr CommandRegistry::removeCommand(const string name)
	{
		return pImpl->removeCommand(name);
	}
	size_t CommandRegistry::count()
	{
		return pImpl->count();
	}
	CommandPtr CommandRegistry::getCommandByName(const string & name) const
	{
		return pImpl->getCommandByName(name);
	}
	set<string>& CommandRegistry::getAllCommandNames() const
	{
		return pImpl->getAllCommandNames();
	}
	CommandRegistry::CommandRegistry()
	{
		pImpl = std::make_unique<CommandRegistryImpl>();
	}
	CommandRegistry::~CommandRegistry()
	{
	}
	void CommandRegistry::CommandRegistryImpl::addCommand(const string name, CommandPtr cmd)
	{
		auto pt = m_commands.find(name);
		if (pt == m_commands.end())
		{
			std::ostringstream oss;
			oss << "Command '" << name << "' not recognized!";
			throw utility::Exception(oss.str());
		}
		m_commands[name] = std::move(cmd);
	}
	CommandPtr CommandRegistry::CommandRegistryImpl::removeCommand(const string name)
	{
		auto pt = m_commands.find(name);
		if (pt != m_commands.end())
		{
			auto tmp = make_command_ptr(pt->second->clone());
			m_commands.erase(pt);
			return tmp;
		}
		return make_command_ptr(nullptr);
	}
	CommandPtr CommandRegistry::CommandRegistryImpl::getCommandByName(const string & name) const
	{
		auto pt = m_commands.find(name);
		if (pt != m_commands.end())
		{
			const auto& cmd = pt->second->clone();
			return make_command_ptr(cmd);
		}
		return make_command_ptr(nullptr);
	}
	set<string>& CommandRegistry::CommandRegistryImpl::getAllCommandNames() const
	{
		set<string> tmp;
		for (auto& cmd : m_commands)
			tmp.insert(cmd.first);
		return tmp;
	}
}