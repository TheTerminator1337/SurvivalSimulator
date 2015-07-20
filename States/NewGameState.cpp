#include <NewGameState.hpp>
#include <ResourceHolder.hpp>
#include <Application.hpp>
#include <Player.hpp>

NewGameState::NewGameState(StateStack& stack, Context context) :
State(stack, context)
{
    setStateId(States::NewGame);

    auto& guiManager = *context.guiManager;

    auto tempMainWindow = guiManager.createWindow(States::NewGame, "mainWindow", sfg::Window::Style::BACKGROUND);
    tempMainWindow->SetPosition(sf::Vector2f(100, 50));

    auto box = sfg::Box::Create(sfg::Box::Orientation::VERTICAL, 25.f);

    nameLabel = sfg::Label::Create("Player Name: ");
    nameLabel->SetId("nameLabel");
    guiManager.setDesktopProperty(std::string("#nameLabel"), std::string("FontSize"), 20.f);

    nameEntry = sfg::Entry::Create();
    nameEntry->SetId("nameEntry");
    nameEntry->SetRequisition(sf::Vector2f(495.f, 0.f));
    nameEntry->SetMaximumLength(35);
    guiManager.setDesktopProperty(std::string("#nameEntry"), std::string("FontSize"), 25.f);

    genderBox = sfg::ComboBox::Create();
    genderBox->SetId("genderBox");
    genderBox->AppendItem("Male");
    genderBox->AppendItem("Female");
    genderBox->SelectItem(0);
    guiManager.setDesktopProperty(std::string("#genderBox"), std::string("FontSize"), 20.f);

    goButton = sfg::Button::Create("Start Exploring");
    goButton->SetRequisition(sf::Vector2f(200, 100));
    goButton->GetSignal(sfg::Button::OnLeftClick).Connect([&] { requestStackChange(States::Loading); } );
    goButton->SetId("goButton");
    guiManager.setDesktopProperty(std::string("#goButton"), std::string("FontSize"), 20.f);

    box->Pack(nameLabel);
    box->Pack(nameEntry);
    box->Pack(genderBox);
    box->Pack(goButton);

    tempMainWindow->Add(box);
}

bool NewGameState::handleEvent(const sf::Event& event)
{
    if (getContext().keyboardMap->isActive(Keys::ESCAPEPRESS))
        requestStackChange(States::Intro);

    return true;
}

bool NewGameState::update(sf::Time dt)
{
    return true;
}

void NewGameState::draw()
{
    sf::RenderWindow& window = *getContext().window;
}
