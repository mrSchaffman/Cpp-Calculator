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
#include "Stack.h"
#include"Exception.h"
#include"StackEventData.h"
#include<deque>

namespace model
{
	const std::string Stack::stackChanged = "stackChanged";
	const std::string Stack::stackError = "stackError";
	class Stack::StackImpl
	{
	public:
		explicit StackImpl(const Stack&);
		void push(double, bool notify = true);
		double pop(bool notify = true);
		double top()const;
		void swap();

		std::vector<double> getElements(size_t n)const;
		void getElements(size_t n, std::vector<double>&elms)const;

		size_t size()const;
		void clear();

	private:
		std::deque<double> m_deque;
		const Stack& m_stack;
	};

	Stack & Stack::getInstance()
	{
		static Stack instance;
		return instance;
	}
	void Stack::push(double d, bool notify)
	{
		pImpl->push(d, notify);
	}
	double Stack::pop(bool notify)
	{
		return pImpl->pop(notify);
	}
	double Stack::top() const
	{
		return pImpl->top();
	}
	void Stack::swap()
	{
		pImpl->swap();
	}
	std::vector<double> Stack::getElements(size_t n) const
	{
		return pImpl->getElements(n);
	}
	void Stack::getElements(size_t n, std::vector<double>& elms) const
	{
		pImpl->getElements(n, elms);
	}
	size_t Stack::size() const
	{
		return pImpl->size();
	}
	void Stack::clear()
	{
		pImpl->clear();
	}
	Stack::Stack()
	{
		pImpl = std::make_unique<StackImpl>(*this);
		registerEvent(stackChanged);
		registerEvent(stackError);
	}
	Stack::~Stack()
	{
	}

	Stack::StackImpl::StackImpl(const Stack & s):m_stack{s}
	{
	}
	void Stack::StackImpl::push(double n, bool notify)
	{
	}
	double Stack::StackImpl::pop(bool notify)
	{
		if (m_deque.empty())
		{
			m_stack.notify(
				Stack::stackError,
				std::make_shared<StackEventData>(StackEventData::ErrorType::EMPTY)
			);

			throw utility::Exception{
				StackEventData::getMessage(StackEventData::ErrorType::EMPTY)
			};

		}
		else
		{
			double v = m_deque.back();
			m_deque.pop_back();
			m_stack.notify(Stack::stackChanged, nullptr);

			return v;
		}

		return 0.0;
	}
	double Stack::StackImpl::top() const
	{
		return m_deque.back();
	}
	void Stack::StackImpl::swap()
	{
		if (m_deque.size()<2)
		{
			m_stack.notify(
				Stack::stackError,
				std::make_shared<StackEventData>(StackEventData::ErrorType::TOO_FEW_ARGUMENT)
			);

			throw utility::Exception{
				StackEventData::getMessage(StackEventData::ErrorType::TOO_FEW_ARGUMENT) 
			};

		}
		else
		{
			double d1 = m_deque.back();
			m_deque.pop_back();
			// m_stack.notify(Stack::stackChanged, nullptr);

			double d2 = m_deque.back();
			m_deque.pop_back();
			// m_stack.notify(Stack::stackChanged, nullptr);

			m_deque.push_back(d1);
			// m_stack.notify(Stack::stackChanged, nullptr);

			m_deque.push_back(d2);
			m_stack.notify(Stack::stackChanged, nullptr);

		}
	}
	std::vector<double> Stack::StackImpl::getElements(size_t n) const
	{
		std::vector<double> v;
		getElements(n);
		return v;
	}
	void Stack::StackImpl::getElements(size_t n, std::vector<double>& elms) const
	{
		if (n > m_deque.size()) n = m_deque.size();
		elms.insert(elms.end(), m_deque.rbegin(), m_deque.rbegin() + n);
	}
	size_t Stack::StackImpl::size() const
	{
		return m_deque.size();
	}
	void Stack::StackImpl::clear()
	{
		m_deque.clear();
		m_stack.notify(Stack::stackChanged, nullptr);
	}
}