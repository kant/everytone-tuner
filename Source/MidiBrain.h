/*
  ==============================================================================

    MidiBrain.h
    Created: 19 Nov 2021 6:23:15pm
    Author:  vincenzo

  ==============================================================================
*/

#pragma once
#include <JuceHeader.h>
#include "MidiNoteTuner.h"

class MidiBrain
{
public:

    MidiBrain();

    ~MidiBrain();

    void processMidi(juce::MidiBuffer& buffer);

    void setTuningSource(const Tuning& tuning);
    void setTuningTarget(const Tuning& tuning);

    
private:

    void preTuningChange(const Tuning& tuning);
    void postTuningChange();

private:

    juce::MidiKeyboardState state;

    int pitchbendRange = 2;

    std::unique_ptr<Tuning> tuningSource;
    std::unique_ptr<Tuning> tuningTarget;

    std::unique_ptr<MidiNoteTuner> tuner;

    //==============================================================================
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (MidiBrain)
};
