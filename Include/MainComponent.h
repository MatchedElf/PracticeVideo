#pragma once
//
#include "../JuceLibraryCode/JuceHeader.h"
/*!
    \brief Класс, хранящий главную компоненту со всеми элементами программы

    Все элементы программы хранятся в данном классе
*/
class MainComponent : public Component, public Button::Listener, public Slider::Listener, public Timer
{
public:
    /*!
        Конструктор
    */
    MainComponent(void);
    /*!
        Деструктор
    */
    ~MainComponent(void) override;
    /*!
        Функция для отрисовки фона компоненты
    */
    void paint(Graphics&) override;
    /*!
        \brief Функция, вызываемая при изменении размеров компоненты

        Функция перераспределяет положения и размеры элементов в зависимости от размера окна
    */
    void resized(void) override;
    /*
        Функция вызываемая при нажатии на какую либо кнопку

        \param butt Нажатая кнопка
    */
    void buttonClicked(Button* butt) override;
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
    ImageComponent* speaker;
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