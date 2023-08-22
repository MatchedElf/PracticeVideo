#pragma once
//
#include "../JuceLibraryCode/JuceHeader.h"
class MySlider : public Slider, public LookAndFeel_V4
{
public:
    MySlider();
    Label* createSliderTextBox(Slider&) override;
};