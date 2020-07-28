/* Copyright (c) 2012-2017, ARM Limited and Contributors
2  *
3  * SPDX-License-Identifier: MIT
4  *
5  * Permission is hereby granted, free of charge,
6  * to any person obtaining a copy of this software and associated documentation files (the "Software"),
7  * to deal in the Software without restriction, including without limitation the rights to
8  * use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of the Software,
9  * and to permit persons to whom the Software is furnished to do so, subject to the following conditions:
10  *
11  * The above copyright notice and this permission notice shall be included in all copies or substantial portions of the Software.
12  *
13  * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED,
14  * INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
15  * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.
16  * IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY,
17  * WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
18  * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
19  */

#include "stdafx.h"
 #include "timer.h"

 #if defined(_WIN32)

 #include <cstdio>
 #include <windows.h>

Timer::Timer()
{
	LARGE_INTEGER l;
	QueryPerformanceFrequency(&l);
	invFreq = 1.0f / l.QuadPart;
	lastInterval = 0.0f;
	frameCount = 0;
	lastFpsUpdate = 0.0f;
	reset();
	fps = 0.0f;
	lastTime = 0.0f;
}

void Timer::reset()
{
	LARGE_INTEGER l;
	QueryPerformanceCounter(&l);
	resetStamp = (((double)l.QuadPart) * invFreq);
}

float Timer::getTime()
{
	LARGE_INTEGER l;
	QueryPerformanceCounter(&l);
	return (float)(((double)l.QuadPart) * invFreq - resetStamp);
}

float Timer::getInterval()
{
	float time = getTime();
	float interval = time - lastInterval;
	lastInterval = time;
	return interval;
}

float Timer::getFPS()
{
	float time = getTime();
	frameCount++;
	if (time - lastFpsUpdate > 1.0f)
	{
		fps = (float)frameCount / (time - lastFpsUpdate);
		lastFpsUpdate = time;
		frameCount = 0;
	}
	return fps;
}
	 
 #else

 #include <sys/time.h>

Timer::Timer()
: startTime()
, currentTime()
, lastIntervalTime(0.0f)
, frameCount(0)
, fpsTime(0.0f)
, fps(0.0f)
{
	startTime.tv_sec = 0;
	startTime.tv_usec = 0;
	currentTime.tv_sec = 0;
	currentTime.tv_usec = 0;

	reset();
}

void Timer::reset()
{
	gettimeofday(&startTime, NULL);
	lastIntervalTime = 0.0;

	frameCount = 0;
	fpsTime = 0.0f;
}

float Timer::getTime()
{
	gettimeofday(&currentTime, NULL);
	float seconds = (currentTime.tv_sec - startTime.tv_sec);
	float milliseconds = (float(currentTime.tv_usec - startTime.tv_usec)) / 1000000.0f;
	return seconds + milliseconds;
}

float Timer::getInterval()
{
	float time = getTime();
	float interval = time - lastIntervalTime;
	lastIntervalTime = time;
	return interval;
}

float Timer::getFPS()
{
	if (getTime() - fpsTime > 1.0f)
	{
		fps = static_cast<float>(frameCount) / (getTime() - fpsTime);
		frameCount = 0;
		fpsTime = getTime();
	}
	++frameCount;
	return fps;
}
	 
 #endif

 
bool Timer::isTimePassed(float seconds)
{
	float time = getTime();
	if (time - lastTime > seconds)
	{
		lastTime = time;
		return true;
	}
	return false;
}
	 

