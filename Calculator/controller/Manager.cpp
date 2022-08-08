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

#include "Manager.h"
#include<stack>
#include<memory>

using std::unique_ptr;
using std::shared_ptr;

namespace controller
{
	// abstract ManagerImpl
	class Manager::ManagerImpl
	{
	public:
		virtual ~ManagerImpl() = default;

		virtual void manageCommand(CommandPtr cmd) = 0;
		virtual void manageUndo() = 0;
		virtual void manageRedo() = 0;
		virtual size_t getUndoSize()const = 0;
		virtual size_t getRedoSize()const = 0;

	};
	//class Manager::ListStrategy : public Manager::ManagerImpl {}; // to do
	//class Manager::ListVectorStrategy : public Manager::ManagerImpl {}; // to do
	class Manager::StackStrategy : public Manager::ManagerImpl
	{
	public:

		void manageCommand(CommandPtr cmd)override;
		void manageUndo() override;
		void manageRedo() override;
		size_t getUndoSize()const override;
		size_t getRedoSize()const override;

	private:
		void flush(std::stack<CommandPtr>& stk);
	private:
		using UndoStack = std::stack<CommandPtr>;
		using RedoStack = std::stack<CommandPtr>;

		UndoStack m_undoRegistry;
		RedoStack m_redoRegistry;
	};


	// parent implementation
	Manager::Manager(HistoryStrategy his)
	{
		switch (his)
		{
		case controller::Manager::STACK_STRATEGY:
			pImpl = std::make_unique<StackStrategy>();
			break;
		case controller::Manager::LIST_STRATEGY:
			//pImpl = std::make_unique<ListStrategy>();
			break;
		case controller::Manager::LIST_VECTOR_STRATEGY:
			//pImpl = std::make_unique<ListVectorStrategy>();
			break;
		default:
			break;
		}
	}
	Manager::~Manager()	{}
	void Manager::manageCommand(CommandPtr cmd)
	{
	}
	void Manager::manageUndo()
	{
		pImpl->manageUndo();
	}
	void Manager::manageRedo()
	{
		pImpl->manageRedo();
	}
	size_t Manager::getUndoSize() const
	{
		return pImpl->getUndoSize();
	}
	size_t Manager::getRedoSize() const
	{
		return pImpl->getRedoSize();
	}
	
	// Concrete stact strategy history implementation
	void Manager::StackStrategy::manageCommand(CommandPtr cmd)
	{
		cmd->execute();

		m_undoRegistry.push(cmd);		// push the Command in the undo stack
		flush(m_redoRegistry);			// reinitialize the redo history.
	}
	void Manager::StackStrategy::manageUndo()
	{
		// redo the first command on the redo stack
		if (m_redoRegistry.size() == 0) return;
		auto& cmd = m_redoRegistry.top();
		cmd->undo();

		// update the 2 Registries accordingly...
		m_undoRegistry.push(cmd);
		m_redoRegistry.pop();
	}
	void Manager::StackStrategy::manageRedo()
	{
		if (m_redoRegistry.size() == 0)return;
		auto& cmd = m_redoRegistry.top();
		cmd->execute();

		m_undoRegistry.push(cmd);
		m_redoRegistry.pop();
	}
	size_t Manager::StackStrategy::getUndoSize() const
	{
		return m_undoRegistry.size();
	}
	size_t Manager::StackStrategy::getRedoSize() const
	{
		return m_redoRegistry.size();
	}
	void Manager::StackStrategy::flush(std::stack<CommandPtr>& stk)
	{
		// clear the redo stack registry!
		while (!stk.empty())
			stk.pop();
	}
}