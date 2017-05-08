#ifndef STATE_HPP
#define STATE_HPP

class State
{
public:
	State();
	virtual ~State();

	virtual bool Initialize() = 0;

	virtual void ProcessKeyDown(int i) = 0;
	virtual void ProcessKeyPressed(int i) = 0;

	virtual void Update() = 0;
};

#endif