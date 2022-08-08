#include "StackChangedObserver.h"
namespace broker
{
	StackUpdatedObserver::StackUpdatedObserver(view::UserInterface& ui)
		: Observer("StackUpdatedObserver")
		, m_ui(ui)
	{ }

	void StackUpdatedObserver::notifyImpl(std::shared_ptr<utility::EventData>d)
	{
		auto data = d;
		// todo

		m_ui.onStackChanged();

		return;
	}

}
