#pragma once

#ifdef HIKARU_PLATFORM_WINDOWS
	#ifdef HIKARU_BUILD_DLL
		#define HIKARU_API __declspec(dllexport)
	#else
		#define HIKARU_API __declspec(dllimport)
	#endif 
#else 
	#error just support windows now!
#endif 