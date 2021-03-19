#include "GTimer.h"

GTimer::GTimer()
{

}

GTimer::~GTimer()
{

}

void GTimer::init(int fps)
{
	QueryPerformanceFrequency(&timerFreq);
	QueryPerformanceCounter(&timeNow);
	QueryPerformanceCounter(&timePrevious);

	Requested_FPS = fps;

	intervalsPerFrame = ((float)timerFreq.QuadPart / Requested_FPS);
}

int GTimer::framesToUpdate()
{
	int framesToUpdate = 0;
	QueryPerformanceCounter(&timeNow);

	float intervalsSinceLastUpdate = (float)timeNow.QuadPart - (float)timePrevious.QuadPart;

	framesToUpdate = (int)(intervalsSinceLastUpdate / intervalsPerFrame);

	if (framesToUpdate != 0)
	{
		QueryPerformanceCounter(&timePrevious);
	}
	return framesToUpdate;
}

