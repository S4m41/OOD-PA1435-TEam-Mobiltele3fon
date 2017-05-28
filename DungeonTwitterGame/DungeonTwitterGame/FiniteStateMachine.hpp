#ifndef FINITE_STATE_MACHINE_HPP
#define FINITE_STATE_MACHINE_HPP

class GameState;

class FiniteStateMachine final
{
public:
	FiniteStateMachine()
	{
		m_top = nullptr;
	}
	~FiniteStateMachine()
	{
		Clear();
	}

	template<typename StateType> void Push()
	{
		Node* newNode = new Node;
		newNode->state = new StateType(this);
		newNode->next = m_top;
		m_top = newNode;
	}

	void Pop(int x = 1)
	{
		if (m_top && x > 0 )
		{
			Node* active = m_top;
			m_top = m_top->next;

			for (int i = 1; i < x; i++)
			{
				if (m_top) {
					Node* next = m_top->next;
					delete m_top->state;
					delete m_top;
					m_top = next;
				}
			}

			delete active->state;
			delete active;
		}
	}

	GameState* Peek() const
	{
		return m_top ? m_top->state : nullptr;
	}
	void Clear()
	{
		while (m_top)
		{
			Pop();
		}
	}

private:
	struct Node
	{
		GameState* state = nullptr;
		Node* next = nullptr;
	};
	Node* m_top;
};


#endif