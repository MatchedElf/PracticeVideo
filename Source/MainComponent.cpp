#include "../Include/MainComponent.h"
#include <iostream>
//
MainComponent::MainComponent(void)
    : Component("MainComponent"),
    MainLabel(0), 
    play1(0)
{
    //setLookAndFeel(&LaF);
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
    front1->setEnabled(false);
    //
    Image backLogo = ImageCache::getFromFile(File::getCurrentWorkingDirectory().getChildFile("backBut.png"));
    back1 = new ImageButton();
    addAndMakeVisible(back1);
    back1->setImages(false, true, true, backLogo, 1, Colours::transparentWhite, backLogo, 0.3, Colours::transparentWhite, backLogo, 1, Colours::transparentWhite);
    back1->addListener(this);
    back1->setEnabled(false);
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
    Image fsLogo = ImageCache::getFromFile(File::getCurrentWorkingDirectory().getChildFile("fsBut.png"));
    FS = new ImageButton();
    FS->setImages(false, true, true, fsLogo, 1, Colours::transparentWhite, fsLogo, 0.3, Colours::transparentWhite, fsLogo, 1, Colours::transparentWhite);
    FS->addListener(this);
    addAndMakeVisible(FS);
    // 
    Image chLogo = ImageCache::getFromFile(File::getCurrentWorkingDirectory().getChildFile("addBut.png"));
    chFile1 = new ImageButton();
    //addAndMakeVisible(chFile1);
    chFile1->setImages(false, true, true, chLogo, 1, Colours::transparentWhite, chLogo, 0.3, Colours::transparentWhite, chLogo, 1, Colours::transparentWhite);
    chFile1->addListener(this);
    //
    vid = new VideoComponent(true);
    addAndMakeVisible(chFile1);
    addAndMakeVisible(vid);
    vid->setVisible(false);
    vid->setAlwaysOnTop(false);
    vid->toBack();
    f1 = File::getCurrentWorkingDirectory().getChildFile("Videoo.mp4");
    //check = f1.exists();
    //auto url = URL(f1);
    //auto result = vid->load(url);
    //
    Image speakerImage = ImageCache::getFromFile(File::getCurrentWorkingDirectory().getChildFile("speaker.png"));
    speaker = new ImageComponent();
    addAndMakeVisible(speaker);
    speaker->setImage(speakerImage);
    //
    slid = new Slider();
    //slid->createSliderTextBox(*slid);
    slid->setSliderStyle(Slider::LinearHorizontal);
    slid->setTextBoxStyle(Slider::TextBoxLeft, true, 50, 20);
    slid->setNumDecimalPlacesToDisplay(0);
    slid->addListener(this);
    slid->setEnabled(false);
    slid->setColour(Slider::thumbColourId, Colour::fromRGB(198, 89, 28));
    slid->setColour(Slider::textBoxOutlineColourId, Colour::fromFloatRGBA(0, 0, 0, 0));
    addAndMakeVisible(slid);
    //slid->setLookAndFeel(LaF);
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
    //LaF.createSliderTextBox(*slid);
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
    deleteAndZero(FS);
    deleteAndZero(chFile1);
    deleteAndZero(myLayout);
    deleteAndZero(slid);
    deleteAndZero(vol);
    deleteAndZero(speed);
    deleteAndZero(speaker);
    //slid->setLookAndFeel(nullptr);
    myChooser.reset();
    queue.clear();
    setLookAndFeel(nullptr);
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
    if (fullS == false) {
        title->setVisible(true);
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
        FS->setBounds(propWv1 + propW8 - 2 * propH1 - dist, propH8, propH1, propH1);
        chFile1->setBounds(propW1 * 9 - propH1, 0, propH1, propH1);
        play1->setBounds(centreW - propH1 / 2, propH8, propH1, propH1);
        pause->setBounds(centreW - propH1 / 2, propH8, propH1, propH1);
        back1->setBounds(centreW - propH1 / 2 - propH1 - dist, propH8, propH1, propH1);
        front1->setBounds(centreW + propH1 / 2 + dist, propH8, propH1, propH1);
        title->setBounds(propW1 - propH1, 0, 5 * propH1, propH1);
        logo->setBounds(centreW - 100, centreH - 150, 200, 200);
        pop1->setBounds(propWv1 + propW8 - propH1, propH8, propH1, propH1);
        //slid->setValue(vid->getPlayPosition());
        slid->setBounds(propWv1, propH1 * 8 - dist / 2, propW8, propH1);
        vol->setBounds(propW1 * 9, centreH - propH6 / 4, propH1, propH6 / 2);
        speaker->setBounds(propW1 * 9 + dist / 2, centreH - propH6 / 3 - dist - dist / 4, propH1, propH1);
        speed->setBounds(centreW - 3 * propH1 - propH1 / 2 - 3 * dist, propH8, 2 * propH1, propH1);
        vid->setBounds(propWv1, propH1, propW8, propH6);
        //myLayout->layOutComponents(comps, 3, 150, 350, proportionOfWidth(0.5), proportionOfHeight(0.1), false, true);
    }
    else {
        title->setVisible(false);
        long propW1 = proportionOfWidth(0.1);
        long propW10 = proportionOfWidth(0.05);
        long propWv1 = proportionOfWidth(0.075);
        long propH1 = proportionOfHeight(0.1);
        long propH10 = proportionOfHeight(0.05);
        long propH6 = proportionOfHeight(0.7);
        long propH8 = proportionOfHeight(0.85);
        long propW8 = proportionOfWidth(0.85);
        long centreW = getWidth() / 2;
        long centreH = getHeight() / 2;
        int dist = 10;
        FS->setBounds(propWv1 + propW8 - 2 * propH1 - dist, propH1 * 9.5 + propH10 / 5, propH10, propH10);
        back1->setBounds(centreW - propH10 / 2 - propH10 - dist, propH1 * 9.5 + propH10 / 5, propH10, propH10);
        chFile1->setBounds(propW1 * 9.5 + dist / 2, 0, propH10, propH10);
        play1->setBounds(centreW - propH10 / 2, propH1 * 9.5 + propH10 / 5, propH10, propH10);
        pause->setBounds(centreW - propH10 / 2, propH1 * 9.5 + propH10 / 5, propH10, propH10);
        front1->setBounds(centreW + propH10 / 2 + dist, propH1 * 9.5 + propH10 / 5, propH10, propH10);
        pop1->setBounds(propWv1 + propW8 - propH1, propH1 * 9.5 + propH10 / 5, propH10, propH10);
        vid->setBounds(0, 0, proportionOfWidth(1.0), propH1 * 9.5);
        speed->setBounds(centreW - 3 * propH1 - propH1 / 2 - 3 * dist, propH1 * 9.5 + propH10 / 5, 2 * propH1, propH10 / 3);
        slid->setBounds(propWv1, propH1 * 9.5, propW8, propH10 / 3);
        vol->setBounds(propW1 * 9.5, centreH - propH6 / 4, propH10, propH6 / 2);
        speaker->setBounds(propW1 * 9.5 + dist / 2, centreH - propH6 / 3 - dist - dist / 4, propH10, propH10);
    }

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
        front1->setEnabled(true);
        play1->setVisible(true);
        pause->setVisible(false);
        curI--;
        title->setText(queue[curI].getFileName(), dontSendNotification);
        vid->load(queue[curI]);
        slid->setValue(0);
        if (curI == 0) back1->setEnabled(false);
        VideoProcessing();
    }
    else if((butt == front1) && (curI < (queue.size() - 1) ) ){
        back1->setEnabled(true);
        play1->setVisible(true);
        pause->setVisible(false);
        curI++;
        title->setText(queue[curI].getFileName(), dontSendNotification);
        vid->load(queue[curI]);
        slid->setValue(0);
        if (curI == (queue.size() - 1)) front1->setEnabled(false);
        VideoProcessing();

    }
    else if (butt == chFile1) {
        loadFile();
    }
    else if (butt == pop1){
        MainLabel->setColour(Label::textColourId, juce::Colours::white);
        PopupMenu menu1;
        int test = queue.size();
        for (int i = 1; i <= queue.size(); i++) {
            menu1.addItem(i, queue[i - 1].getFileName());

        }
        menu1.showMenuAsync(PopupMenu::Options().withMinimumWidth(100)
            .withPreferredPopupDirection(PopupMenu::Options::PopupDirection(0))
            .withTargetComponent(pop1),
            [this](int result) {
                if (result != 0) {
                    back1->setEnabled(true);
                    front1->setEnabled(true);
                    play1->setVisible(true);
                    pause->setVisible(false);
                    curI = result - 1;
                    title->setText(queue[curI].getFileName(), dontSendNotification);
                    vid->load(queue[curI]);
                    slid->setValue(0);
                    if (curI == 0) back1->setEnabled(false);
                    if (curI == (queue.size() - 1)) front1->setEnabled(false);
                    VideoProcessing();
                }
            });
    }
    else if (butt == FS) {
        if (fullS == true) {
            fullS = false;
        }
        else {
            fullS = true;
        }
        resized();
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
    slid->setValue(0);
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
            curI = queue.size() - 1;
            VideoProcessing();
            if(curI > 0) back1->setEnabled(true);
            front1->setEnabled(false);
            play1->setVisible(true);
            pause->setVisible(false);
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
    //slid->createSliderTextBox(*slid);
}

