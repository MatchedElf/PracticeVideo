#include "MySlider.h"

MySlider::MySlider() : Slider(), LookAndFeel_V4()
{

}

Label* MySlider::createSliderTextBox(Slider& slid)
{
    Label* text = new Label("time label", "hhh");
    text->setVisible(true);
    String s;
    int h = slid.getValue() / 3600;
    int min = slid.getValue() / 3600;
    int sec = slid.getValue() / 3600;
    s.append(std::to_string(h), 20);
    s.append(":", 2);
    s.append(std::to_string(min), 20);
    s.append(":", 2);
    s.append(std::to_string(sec), 20);
    text->setText(s, sendNotification);
    return text;
}
