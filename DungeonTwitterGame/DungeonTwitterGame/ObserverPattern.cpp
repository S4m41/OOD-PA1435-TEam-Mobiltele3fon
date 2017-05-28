#include "ObserverPattern.hpp"

Observer::Observer()
{
	m_subject = nullptr;
}
Observer::~Observer()
{
}
void Observer::SetSubject(Subject* subject)
{
	m_subject = subject;
	subject->AttachObserver(this);
}
Subject* Observer::GetSubject() const
{
	return m_subject;
}


Subject::Subject()		// Protected constructor makes the class abstract without having to override a function
{
}
Subject::~Subject()
{
}
void Subject::AttachObserver(Observer/*<EventType>*/* observer)
{
	m_observers.push_back(observer);
}
void Subject::DetachObserver(Observer/*<EventType>*/* observer)
{
	m_observers.erase(std::find(m_observers.begin(), m_observers.end(), observer));
}
void Subject::NotifyObservers(Event* event)
{
	for (unsigned int i = 0; i < m_observers.size(); i++)
	{
		m_observers[i]->Notify(/*EventType*/ event);
	}
}