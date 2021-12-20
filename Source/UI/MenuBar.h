/*
  ==============================================================================

    MenuBar.h
    Created: 5 Dec 2021 9:24:22pm
    Author:  Vincenzo

  ==============================================================================
*/

#pragma once
#include <JuceHeader.h>

class MenuBarModel : public juce::MenuBarModel
{
protected:

    enum MenuNames
    {
        File
    };


public:

    MenuBarModel(juce::ApplicationCommandManager* cmdManagerIn = nullptr) : cmdManager(cmdManagerIn) {}
    ~MenuBarModel() override {}

    juce::StringArray getMenuBarNames() override
    {
        return menuNames;
    }

    juce::PopupMenu getMenuForIndex(int topLevelMenuIndex, const juce::String& menuName) override
    {
        juce::PopupMenu menu;

        switch (topLevelMenuIndex)
        {
        case MenuNames::File:
            menu.addCommandItem(cmdManager, Everytone::Commands::NewTuning, "New Tuning");
            menu.addCommandItem(cmdManager, Everytone::Commands::OpenTuning, "Open Tuning (.scl, .tun)");
            menu.addCommandItem(cmdManager, Everytone::Commands::NewMapping, "New Mapping");
            menu.addCommandItem(cmdManager, Everytone::Commands::ShowOptions, "Preferences");
            menu.addCommandItem(cmdManager, Everytone::Commands::Back, "Back");
        default:
            break;
        }

        return menu;
    }

    void menuItemSelected(int menuItemID, int topLevelMenuIndex) override
    {

    }

private:

    juce::ApplicationCommandManager* cmdManager;

    juce::StringArray menuNames = { "File", "Options" };

    juce::PopupMenu::Options fileMenu;
    juce::PopupMenu::Options optionsMenu;
};
