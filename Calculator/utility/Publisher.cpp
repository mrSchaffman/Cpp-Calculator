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

#include "Publisher.h"
#include"Exception.h"
#include"Observer.h"

#include<unordered_map>
#include<sstream>
using std::unordered_map;
using std::string;
using std::unique_ptr;
using std::shared_ptr;
using std::ostringstream;

namespace utility
{
	class Publisher::PublisherImpl
	{
	public:
		PublisherImpl() = default;
		~PublisherImpl() = default;

		void subscribe(const string& eventName, unique_ptr<Observer> observer);
		void unsubscribe(const string& eventName, const string& observerName);
		void notify(const string eventName, shared_ptr<EventData> data)const;
		void registerEvent(const string&eventName);
	private:
		// the publisher hold the list of the observers
		using ObserberList = unordered_map<string, unique_ptr<Observer>>;
		using Observers = unordered_map<string, ObserberList>;

		Observers m_observers;
	};

	Publisher::Publisher()
	{
		pImpl = std::make_unique<PublisherImpl>();
	}

	void Publisher::subscribe(const std::string & eventName, std::unique_ptr<Observer> observer)
	{
		pImpl->subscribe(eventName, std::move(observer));
	}
	void Publisher::unsubscribe(const std::string & eventName, const std::string & observerName)
	{
		pImpl->unsubscribe(eventName, observerName);
	}
	Publisher::~Publisher()
	{
	}
	void Publisher::notify(const std::string eventName, std::shared_ptr<EventData> data) const
	{
		pImpl->notify(eventName, data);
	}
	void Publisher::registerEvent(const std::string & eventName)
	{
		pImpl->registerEvent(eventName);
	}
	void Publisher::PublisherImpl::subscribe(const string & eventName, unique_ptr<Observer> observer)
	{
		auto ptr = m_observers.find(eventName);
		if (ptr == std::end(m_observers))
		{
			ostringstream oss;
			oss << "Event: " << eventName << " not supported!";
			throw utility::Exception(oss.str());
		}

		string observerName = observer->getName();
		auto iter = m_observers[eventName].insert(std::make_pair(observerName, std::move(observer)));
		if (!iter.second)
		{
			ostringstream oss;
			oss << "Observer: " << observerName << "already registered!";
			throw utility::Exception(oss.str());

		}
	}
	void Publisher::PublisherImpl::unsubscribe(const string & eventName, const string & observerName)
	{
		auto count = m_observers.count(eventName);
		if (!count)
		{
			ostringstream oss;
			oss << "Event ' " << eventName << " ' not supported!";
			throw utility::Exception(oss.str());

		}

		auto found = m_observers[eventName].erase(observerName);
		if (!found)
		{
			ostringstream oss;
			oss << "Observer ' " << observerName << " ' not registered!";
			throw utility::Exception(oss.str());

		}
	}
	void Publisher::PublisherImpl::notify(const string eventName, shared_ptr<EventData> data) const
	{
		const auto& ptr = m_observers.find(eventName);
		if (ptr != std::end(m_observers))
		{
			for (const auto& ob : ptr->second)
			{
				ob.second->notify(data);
			}
		}
		else
		{
			ostringstream oss;
			oss << "Event ' " << eventName << " ' not supported!";
			throw utility::Exception(oss.str());
		}
	}
	void Publisher::PublisherImpl::registerEvent(const string & eventName)
	{
		const auto& ptr = m_observers.find(eventName);
		if (ptr != std::end(m_observers))
		{
			ostringstream oss;
			oss << "Event ' " << eventName << " ' already registered!";
			throw utility::Exception(oss.str());
		}
		m_observers[eventName] = ObserberList{};

	}
}