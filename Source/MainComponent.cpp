#include "../Include/MainComponent.h"
#include <iostream>
//
MainComponent::MainComponent(void) : Component("MainComponent"), MainLabel(0), play1(0)
{
    setOpaque(true);
    MainLabel = new Label("First label", "FONT LOGO");
    addAndMakeVisible(MainLabel);
    MainLabel->setFont(Font(38, Font::bold));
    //
    title = new Label("title label", "");
    addAndMakeVisible(title);
    title->setFont(Font(18, Font::bold));
    //
    //play = new TextButton("Play button");
    //addAndMakeVisible(play);
    //play->setButtonText("|>");
    //play->addListener(this);
    //play->setEnabled(false);
    //
    Image playLogo = ImageCache::getFromFile(File::getCurrentWorkingDirectory().getChildFile("playBut.png"));
    play1 = new ImageButton();
    addAndMakeVisible(play1);
    play1->setImages(false, true, true, playLogo, 1, Colours::transparentWhite, playLogo, 0.3, Colours::transparentWhite, playLogo, 1, Colours::transparentWhite);
    play1->addListener(this);
    play1->setEnabled(false);
    //
    Image pauseLogo = ImageCache::getFromFile(File::getCurrentWorkingDirectory().getChildFile("pauseBut.png"));
    pause = new ImageButton();
    addAndMakeVisible(pause);
    pause->setVisible(false);
    pause->setImages(false, true, true, pauseLogo, 1, Colours::transparentWhite, pauseLogo, 0.3, Colours::transparentWhite, pauseLogo, 1, Colours::transparentWhite);
    pause->addListener(this);
    //
    //back = new TextButton("back button");
    //addAndMakeVisible(back);
    //back->setButtonText("<<");
    //back->addListener(this);
    //
    //front = new TextButton("next button");
    //addAndMakeVisible(front);
    //front->setButtonText(">>");
    //front->addListener(this);
    //
    Image frontLogo = ImageCache::getFromFile(File::getCurrentWorkingDirectory().getChildFile("frontBut.png"));
    front1 = new ImageButton();
    addAndMakeVisible(front1);
    front1->setImages(false, true, true, frontLogo, 1, Colours::transparentWhite, frontLogo, 0.3, Colours::transparentWhite, frontLogo, 1, Colours::transparentWhite);
    front1->addListener(this);
    //
    Image backLogo = ImageCache::getFromFile(File::getCurrentWorkingDirectory().getChildFile("backBut.png"));
    back1 = new ImageButton();
    addAndMakeVisible(back1);
    back1->setImages(false, true, true, backLogo, 1, Colours::transparentWhite, backLogo, 0.3, Colours::transparentWhite, backLogo, 1, Colours::transparentWhite);
    back1->addListener(this);
    //
    //pop = new TextButton("Popup menu");
    //addAndMakeVisible(pop);
    //pop->setButtonText("...");
    //pop->addMouseListener(this, false);
    //pop->addListener(this);
    //
    Image popLogo = ImageCache::getFromFile(File::getCurrentWorkingDirectory().getChildFile("popBut.png"));
    pop1 = new ImageButton();
    addAndMakeVisible(pop1);
    pop1->setImages(false, true, true, popLogo, 1, Colours::transparentWhite, popLogo, 0.3, Colours::transparentWhite, popLogo, 1, Colours::transparentWhite);
    pop1->addListener(this);
    //
    menu = new PopupMenu();
    menu->addItem(PopupMenu::Item("Item"));
    //
    logo = new ImageComponent("Play image");
    addAndMakeVisible(logo);
    logo->setImage(ImageCache::getFromFile(File::getCurrentWorkingDirectory().getChildFile("logop.png")));
    //
    //chFile = new TextButton("Choose file");
    //chFile->setButtonText("+");
    //chFile->addListener(this);
    // 
    Image chLogo = ImageCache::getFromFile(File::getCurrentWorkingDirectory().getChildFile("addBut.png"));
    chFile1 = new ImageButton();
    //addAndMakeVisible(chFile1);
    chFile1->setImages(false, true, true, chLogo, 0.6, Colours::white, chLogo, 0.3, Colours::white, chLogo, 1, Colours::white);
    chFile1->addListener(this);
    //
    vid = new VideoComponent(true);
    addAndMakeVisible(vid);
    vid->setVisible(false);
    addAndMakeVisible(chFile1);
    f1 = File::getCurrentWorkingDirectory().getChildFile("Videoo.mp4");
    //check = f1.exists();
    //auto url = URL(f1);
    //auto result = vid->load(url);
    //
    slid = new Slider(Slider::LinearHorizontal, Slider::TextBoxLeft);
    slid->setTextBoxStyle(Slider::TextBoxLeft, true, 50, 20);
    slid->setNumDecimalPlacesToDisplay(0);
    slid->addListener(this);
    slid->setEnabled(false);
    slid->setColour(Slider::thumbColourId, Colour::fromRGB(198, 89, 28));
    slid->setColour(Slider::textBoxOutlineColourId, Colour::fromFloatRGBA(0, 0, 0, 0));
    addAndMakeVisible(slid);
    //
    vol = new Slider(Slider::LinearVertical, Slider::TextBoxBelow);
    vol->setTextBoxStyle(Slider::NoTextBox, true, 50, 20);
    vol->setNumDecimalPlacesToDisplay(0);
    vol->addListener(this);
    vol->setEnabled(false);
    vol->setRange(0, 100, 1);
    vol->setValue(100);
    vol->setColour(Slider::thumbColourId, Colour::fromRGB(198, 89, 28));
    vol->setColour(Slider::textBoxOutlineColourId, Colour::fromFloatRGBA(0, 0, 0, 0));
    addAndMakeVisible(vol);
    //
    speed = new Slider(Slider::LinearHorizontal, Slider::TextBoxLeft);
    speed->setTextBoxStyle(Slider::TextBoxLeft, true, 50, 20);
    speed->setNumDecimalPlacesToDisplay(2);
    speed->addListener(this);
    speed->setEnabled(false);
    speed->setRange(0.25, 4, 0.25);
    speed->setValue(1);
    speed->setColour(Slider::thumbColourId, Colour::fromRGB(198, 89, 28));
    speed->setColour(Slider::textBoxOutlineColourId, Colour::fromFloatRGBA(0, 0, 0, 0));
    addAndMakeVisible(speed);

    //
    setSize(500, 500);
    //
    myLayout = new StretchableLayoutManager();
    myLayout->setItemLayout(0, 10, 100, 50);
    myLayout->setItemLayout(1, 10, 100, 50);
    myLayout->setItemLayout(2, 10, 100, 50);
}
//
MainComponent::~MainComponent(void)
{
    deleteAndZero(MainLabel);
    deleteAndZero(play1);
    deleteAndZero(pause);
    deleteAndZero(back1);
    deleteAndZero(front1);
    deleteAndZero(title);
    deleteAndZero(menu);
    deleteAndZero(logo);
    deleteAndZero(vid);
    deleteAndZero(pop1);
    deleteAndZero(chFile1);
    deleteAndZero(myLayout);
    deleteAndZero(slid);
    deleteAndZero(vol);
    deleteAndZero(speed);
    myChooser.reset();
    queue.clear();
}
//
void MainComponent::paint(Graphics& g)
{
    g.fillAll(Colour::fromRGB(0, 3, 71));
    ColourGradient bg(Colour::fromRGB(198, 89, 28), 0.0, 0.0, Colour::fromRGB(0, 3, 71), 300.0, 300.0, false);
    //bg.vertical(Colour::fromRGB(198, 89, 28), 0.0, Colour::fromRGB(0, 3, 71), 1.0);
    //bg.addColour(1.0, Colour::fromRGB(198, 89, 28));
    //bg = ColourGradient::vertical(Colour::fromRGB(198, 89, 28), -250.0, Colour::fromRGB(0, 3, 71), 500.0);
    bg = ColourGradient::vertical(Colour::fromRGB(198, 89, 28), -250.0, Colour::fromRGB(0, 0, 0), 500.0);
    g.setGradientFill(bg);
    g.fillAll();
}
//
void MainComponent::resized(void)
{
    long propW1 = proportionOfWidth(0.1);
    long propWv1 = proportionOfWidth(0.075);
    long propH1 = proportionOfHeight(0.1);
    long propH6 = proportionOfHeight(0.7);
    long propH8 = proportionOfHeight(0.85);
    long propW8 = proportionOfWidth(0.85);
    long centreW = getWidth() / 2;
    long centreH = getHeight() / 2;
    //long height = getHeight();
    int dist = 20;
    //if (check == true) {
    //    double sec = vid->getVideoDuration();
    //    slid->setRange(0, sec, 1);
    //}

    //Component* comps[]{play, back, front};
    //if(check == true) title->setText("true", dontSendNotification);
    //else if(check == false) title->setText("false", dontSendNotification);
    //MainLabel->setBounds(getWidth() / 2 - 50, getHeight() / 2 - 150, 100, 100);
    chFile1->setBounds(propW1 * 9 - propH1, 0, propH1, propH1);
    play1->setBounds(centreW - propH1 / 2, propH8, propH1, propH1);
    pause->setBounds(centreW - propH1 / 2, propH8, propH1, propH1);
    back1->setBounds(centreW - propH1 / 2 - propH1 - dist, propH8, propH1, propH1);
    front1->setBounds(centreW + propH1 / 2 + dist, propH8, propH1, propH1);
    title->setBounds(propW1 - propH1, 0, 5 * propH1, propH1);
    logo->setBounds(centreW - 100, centreH - 150, 200, 200);
    pop1->setBounds(propWv1 + propW8 - propH1, propH8, propH1, propH1);
    //slid->setValue(vid->getPlayPosition());
    slid->setBounds(propWv1, propH1 * 8 - dist, propW8, propH1);
    vol->setBounds(propW1 * 9 + dist, centreH - propH6 / 4, propH1, propH6 / 2);
    speed->setBounds(centreW - 3 * propH1 - propH1 / 2 - 3 * dist, propH8, 2 * propH1, propH1);
    vid->setBounds(propWv1, propH1, propW8, propH6);
    //myLayout->layOutComponents(comps, 3, 150, 350, proportionOfWidth(0.5), proportionOfHeight(0.1), false, true);
}
//
void MainComponent::buttonClicked(Button* butt)
{
    if ( (butt == play1) || (butt == pause) ) {
        if (vid->isPlaying()) {
            play1->setVisible(true);
            pause->setVisible(false);
            this->stopTimer();
            vid->stop();
        }
        else {
            play1->setVisible(false);
            pause->setVisible(true);
            this->startTimer(1000);
            vid->play();
        }
    }
    else if ( (butt == back1) && (curI > 0) ) {
        play1->setVisible(true);
        pause->setVisible(false);
        curI--;
        title->setText(queue[curI].getFileName(), dontSendNotification);
        vid->load(queue[curI]);
        slid->setValue(0);
        VideoProcessing();
    }
    else if((butt == front1) && (curI < (queue.size() - 1) ) ){
        play1->setVisible(true);
        pause->setVisible(false);
        curI++;
        title->setText(queue[curI].getFileName(), dontSendNotification);
        vid->load(queue[curI]);
        slid->setValue(0);
        VideoProcessing();

    }
    else if (butt == chFile1) {
        loadFile();
    }
    else if (butt == pop1){
        MainLabel->setColour(Label::textColourId, juce::Colours::white);
        PopupMenu menu1;
        menu1.addItem(PopupMenu::Item("Item"));
        menu1.addItem(PopupMenu::Item("Item2"));
        menu1.showMenuAsync(PopupMenu::Options().withMinimumWidth(100)
            .withMaximumNumColumns(3)
            .withPreferredPopupDirection(PopupMenu::Options::PopupDirection(0))
            .withTargetComponent(pop1));
    }
}
//
//void MainComponent::mouseDown(const MouseEvent& event)
//{
//    MainLabel->setColour(Label::textColourId, juce::Colours::white);
//    PopupMenu menu1;
//    menu1.addItem(PopupMenu::Item("Item"));
//    menu1.addItem(PopupMenu::Item("Item2"));
//    menu1.showMenuAsync(PopupMenu::Options().withMinimumWidth(100)
//        .withMaximumNumColumns(3)
//        .withPreferredPopupDirection(PopupMenu::Options::PopupDirection(0))
//        .withTargetComponent(pop));
//}

void MainComponent::VideoProcessing()
{
    check = true;
    //
    vid->setVisible(true);
    logo->setVisible(false);
    slid->setEnabled(true);
    play1->setEnabled(true);
    vol->setEnabled(true);
    speed->setEnabled(true);
    //
    double sec = vid->getVideoDuration();
    slid->setRange(0, sec, 1);
    //
    resized();
}


void MainComponent::loadFile()
{
    myChooser = std::make_unique<FileChooser>("Please select the moose you want to load...",
        File::getSpecialLocation(File::currentExecutableFile).getChildFile("..//..//..//..//..//..//Resources"),
        "*.mp4");

    auto folderChooserFlags = FileBrowserComponent::openMode | FileBrowserComponent::canSelectFiles;

    myChooser->launchAsync(folderChooserFlags, [this](const FileChooser& chooser)
    {
        File choosedFile(chooser.getResult());
        if (choosedFile.getFullPathName().isEmpty()) {
            //check = false;
            //vid->setVisible(false);
            //logo->setVisible(true);
            return;
        }
        //loadMoose(mooseFile);
        auto url = URL(choosedFile);
        auto result = vid->load(url);
        title->setText(choosedFile.getFileName(), dontSendNotification);
        if (result.wasOk()) {
            queue.push_back(choosedFile);
            curI++;
            VideoProcessing();
        }
        else {
            //check = false;
            //vid->setVisible(false);
            //logo->setVisible(true);
            AlertWindow::showMessageBoxAsync(MessageBoxIconType::WarningIcon, "Couldn't load the file!", result.getErrorMessage());
        }
    });
}

void MainComponent::sliderValueChanged(Slider* s)
{
    if (s == slid) {
        vid->setPlayPosition(s->getValue());
    }
    else if (s == vol) {
        vid->setAudioVolume(s->getValue() / 100);
    }
    else if (s == speed) {
        vid->setPlaySpeed(s->getValue());
    }
}
//
void MainComponent::timerCallback()
{
    slid->setValue(vid->getPlayPosition(), dontSendNotification);

}

