#pragma once

//////////////////////////////////////////////////////////////////
// DO NOT EDIT THIS FILE										//
// This file will be replaced with a new version during marking //
//////////////////////////////////////////////////////////////////

#include <fstream>
#include <vector>
#include <chrono>

// Converts latitude/longitude into eastings/northings
extern void LLtoUTM(const double Lat, const double Long, double& UTMEasting, double& UTMNorthing);

class ACW_Wrapper {
	std::chrono::steady_clock::time_point _startTime;
	int _currentTimer;

public:
	explicit ACW_Wrapper();
	~ACW_Wrapper();

	void startTimer();
	double stopTimer();
};

#ifdef _M_IX86
#ifdef _DEBUG
#pragma comment(lib,"ACW_WrapperD.lib")
#else
#pragma comment(lib,"ACW_Wrapper.lib")
#endif
#else
#ifdef _DEBUG
#pragma comment(lib,"ACW_Wrapperx64D.lib")
#else
#pragma comment(lib,"ACW_Wrapperx64.lib")
#endif
#endif