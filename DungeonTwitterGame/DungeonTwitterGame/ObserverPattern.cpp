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
	m_subject->AttachObserver(this);
}


Subject::Subject()
{
}
Subject::~Subject()
{
}
void Subject::AttachObserver(Observer* observer)
{
	m_observers.push_back(observer);
}
void Subject::DetachObserver(Observer* observer)
{
	m_observers.erase(std::find(m_observers.begin(), m_observers.end(), observer));
}
void Subject::SetValue(int value)
{
	m_value = value;
	UpdateObservers();
}
void Subject::UpdateObservers()
{
	for (unsigned int i = 0; i < m_observers.size(); i++)
	{
		m_observers[i]->UpdateObserver();
	}
}