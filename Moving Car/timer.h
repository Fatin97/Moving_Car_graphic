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

 #ifndef TIMER_H
 #define TIMER_H

 #include <cstdio>

 #if defined(_WIN32)
 #else
 #include <sys/time.h>
 #endif

class Timer
{
private:
	int frameCount;
	float fps;
	float lastTime;
#if defined(_WIN32)
	double resetStamp;
	double invFreq;
	float lastInterval;
	float lastFpsUpdate;
#else
	timeval startTime;
	timeval currentTime;
	float lastIntervalTime;
	float fpsTime;
#endif
public:
	Timer();

	void reset();

	float getTime();

	float getInterval();

	float getFPS();

	bool isTimePassed(float seconds = 1.0f);
};

	   
 #endif /* TIMER_H */