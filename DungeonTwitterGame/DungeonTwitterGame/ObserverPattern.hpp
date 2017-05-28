#ifndef OBSERVER_PATTERN_HPP
#define OBSERVER_PATTERN_HPP
#include <vector>
#include <SFML\Window\Keyboard.hpp>

struct Event
{
protected:
	Event()
	{
	}
	virtual ~Event()
	{
	}
};

struct KeyDownEvent : public Event
{
	KeyDownEvent(sf::Keyboard::Key key, bool onlyPressed) : Event()
	{
		m_key = key;
		m_onlyPressed = onlyPressed;
	}
	~KeyDownEvent()
	{
	}

	sf::Keyboard::Key m_key;
	bool m_onlyPressed;
};

class Subject;


//===================================================================
class Observer
{
public:
	Observer();
	virtual ~Observer();
	virtual void Notify(/*EventType*/ Event* _event) = 0;

	void SetSubject(Subject* subject);
	Subject* GetSubject() const;

private:
	Subject* m_subject;
};

//===================================================================
class Subject
{
protected:
	Subject();

public:
	virtual ~Subject();

	void AttachObserver(Observer/*<EventType>*/* observer);
	void DetachObserver(Observer/*<EventType>*/* observer);
	void NotifyObservers(Event* _event);

private:
	std::vector<Observer/*<EventType>*/*> m_observers;
};

#endif