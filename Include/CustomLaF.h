#pragma once
//
#include "../JuceLibraryCode/JuceHeader.h"
class CustomLaF : public LookAndFeel_V2
{
public:
    CustomLaF();
    Label* createSliderTextBox(Slider&) override;
};