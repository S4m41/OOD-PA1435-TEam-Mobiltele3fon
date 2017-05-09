#ifndef OBSERVER_PATTERN_HPP
#define OBSERVER_PATTERN_HPP
#include <vector>

class Subject;
class Observer;

//===================================================================
class Observer
{
public:
	virtual ~Observer();
	virtual void UpdateObserver() = 0;

	void SetSubject(Subject* subject);

protected:
	Observer();

private:
	Subject* m_subject;
};

//===================================================================
class Subject
{
public:
	virtual ~Subject();

	void AttachObserver(Observer* observer);
	void DetachObserver(Observer* observer);

	void SetValue(int value);

protected:
	Subject();

private:
	std::vector<Observer*> m_observers;

	int m_value;

	void UpdateObservers();
};


#endif