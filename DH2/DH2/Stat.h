#pragma once
#include <string>
class Stat
{
public:
	Stat(float current, float max); 
	
	float GetCurrent() { return m_current; }
	float GetMax() { return m_max; }

	void SetMax(float val) { m_max = val; }
	void SetCurrent(float val) { m_current = val; }
	void SetStatToMax() { m_current = m_max; }

	void SubtractCurrent(float val);
	void AddCurrent(float val);
	void MultiplyCurrent(float val);
	void DivideCurrent(float val);

	void AddMax(float val) { m_current += val; }

private:
	float m_current;
	float m_max;
};

