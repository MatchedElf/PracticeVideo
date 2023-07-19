#pragma once
//
#include "../JuceLibraryCode/JuceHeader.h"
//
class MainComponent : public Component, public Button::Listener, public Slider::Listener, public Timer
{
public:
    MainComponent(void);
    ~MainComponent(void) override;
    //
    void paint(Graphics&) override;
    void resized(void) override;
    void buttonClicked(Button*) override;
    //void mouseDown(const MouseEvent& event);
    void VideoProcessing();
    void loadFile();
    void sliderValueChanged(Slider*);
    void timerCallback();
    //
private:
    std::vector<File> queue;
    int curI = -1;
    std::unique_ptr<FileChooser> myChooser;
    bool check = false;
    Label* MainLabel;
    Label* title;
    ImageButton* play1;
    ImageButton* pause;
    ImageButton* front1;
    //TextButton* back;
    ImageButton* back1;
    //TextButton* front;
    //TextButton* pop;
    ImageButton* pop1;
    //TextButton* chFile;
    ImageButton* chFile1;
    VideoComponent* vid;
    PopupMenu* menu;
    ImageComponent* logo;
    File f1;
    File ObtainedFile;
    StretchableLayoutManager* myLayout;
    Slider* slid;
    Slider* vol;
    Slider* speed;
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (MainComponent)
};