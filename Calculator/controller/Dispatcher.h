#pragma once
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
#ifndef DISPATCHER_H
#define DISPATCHER_H
#include<string>
#include"UserInterface.h"
namespace controller
{
	class Dispatcher
	{
	public:
		explicit Dispatcher(view::UserInterface&ui);
		~Dispatcher();

		void onCommandEntered(const std::string& command);
	private:
		class DispatcherImpl;
		std::unique_ptr<DispatcherImpl> pImpl;

	private:
		// not needed
		Dispatcher(const Dispatcher&) = delete;
		Dispatcher(Dispatcher&&) = delete;
		Dispatcher& operator=(const Dispatcher&) = delete;
		Dispatcher& operator=(Dispatcher&&) = delete;
	};
}
#endif // !DISPATCHER_H


