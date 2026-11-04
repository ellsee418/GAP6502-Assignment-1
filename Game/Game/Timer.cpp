#include "Timer.h"

Timer::Timer()
	: m_deltaTime(0.f), m_totalTime(0.f)
{
	m_startTime = Clock::now();
	m_lastTime = m_startTime;
}

void Timer::Tick()
{
	TimePoint currentTime = Clock::now();

	Duration deltaDuration = currentTime - m_lastTime;
	m_deltaTime = deltaDuration.count();

	Duration totalDuration = currentTime - m_startTime;
	m_totalTime = totalDuration.count();

	m_lastTime = currentTime;
}

float Timer::GetDeltaTime() const { return m_deltaTime; }
float Timer::GetTotalTime() const { return m_totalTime; }

void Timer::Reset()
{
	m_startTime = Clock::now();
	m_lastTime = m_startTime;
	m_deltaTime = 0.f;
	m_totalTime = 0.f;
}
