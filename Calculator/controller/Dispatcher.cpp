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
namespace controller
{
	class Dispatcher::DispatcherImpl
	{
	public:
		explicit DispatcherImpl(view::UserInterface&ui) :m_ui{ ui } {}
		void onCommandEntered(const std::string& command);

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

	void Dispatcher::onCommandEntered(const std::string & command)
	{
		pImpl->onCommandEntered(command);
	}

	void Dispatcher::DispatcherImpl::onCommandEntered(const std::string & command)
	{
	}

}
