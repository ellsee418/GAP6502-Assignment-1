#pragma once
#include <chrono>

class Timer
{
	using Clock = std::chrono::high_resolution_clock;
	using TimePoint = std::chrono::time_point<Clock>;
	using Duration = std::chrono::duration<float>;
public:
	Timer();

	void Tick(); // call on frame start
	float GetDeltaTime() const;
	float GetTotalTime() const;
	void Reset();
private:
	TimePoint m_lastTime;
	TimePoint m_startTime;
	float m_deltaTime;
	float m_totalTime;
};

