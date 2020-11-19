/*
Plugin-SDK (Grand Theft Auto San Andreas) header file
Authors: GTA Community. See more here
https://github.com/DK22Pac/plugin-sdk
Do not delete this comment block. Respect others' work!
*/
#pragma once

#include "PluginBase.h"

class PLUGIN_API CTimer
{
public:
    typedef std::uint64_t(__cdecl* TimerFunction_t)();
    static TimerFunction_t& ms_fnTimerFunction;

    // class variables
    static bool& m_sbEnableTimeDebug;
    static bool& bSkipProcessThisFrame;
    static bool& bSlowMotionActive;
    static float& game_FPS;

    static bool& m_CodePause;
    static bool& m_UserPause;
    static unsigned int& m_FrameCounter;
    static float& ms_fTimeStepNonClipped;
    static float& ms_fTimeStep;
    static unsigned int& m_snTimerDivider;

    static float& ms_fOldTimeStep;
    static float& ms_fSlowMotionScale;

    // game speed
    static float& ms_fTimeScale;
    static unsigned int& m_snTimeInMillisecondsPauseMode;
    static unsigned int& m_snTimeInMillisecondsNonClipped;
    static unsigned int& ms_nPreviousTimeInMillisecondsNonClipped;
    static unsigned int& m_snTimeInMilliseconds;
    static std::uint64_t& m_snRenderStartTime;

    // Freshly from R*:
    static unsigned int& m_snPPPPreviousTimeInMilliseconds;
    static unsigned int& m_snPPPreviousTimeInMilliseconds;
    static unsigned int& m_snPPreviousTimeInMilliseconds;
    static unsigned int& m_snPreviousTimeInMilliseconds;

    static void InjectHooks();

    // class functions
    static void Initialise();
    static void Shutdown();
    static void UpdateVariables(float timeStep);
    static void Suspend();
    static void Resume();
    static int GetCyclesPerMillisecond();
    // cycles per ms * 20
    static int GetCyclesPerFrame();
    static unsigned int GetCurrentTimeInCycles();
    static void Stop();
    static bool GetIsSlowMotionActive();
    static void StartUserPause();
    static void EndUserPause();
    static bool GetIsPaused() { return m_UserPause || m_CodePause; }
    static void Update();
    static void UpdateTimeStep(float fTimeStep);
};
