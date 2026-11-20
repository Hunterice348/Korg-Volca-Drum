#include "PluginProcessor.h"
#include "PluginEditor.h"

VDrumLabAudioProcessorEditor::VDrumLabAudioProcessorEditor(VDrumLabAudioProcessor& p)
    : AudioProcessorEditor(&p), audioProcessor(p)
{
    setSize(800, 600);
}

VDrumLabAudioProcessorEditor::~VDrumLabAudioProcessorEditor()
{
}

void VDrumLabAudioProcessorEditor::paint(juce::Graphics& g)
{
    // Тёмный industrial фон
    g.fillAll(juce::Colour::fromRGB(30, 30, 35));
    
    // Заголовок
    g.setColour(juce::Colours::white);
    g.setFont(32.0f);
    g.drawText("V-DRUM LAB", getLocalBounds().removeFromTop(60).reduced(20),
               juce::Justification::centredLeft, true);
    
    // Подзаголовок
    g.setFont(14.0f);
    g.setColour(juce::Colours::grey);
    g.drawText("Advanced Digital Percussion Synthesizer",
               getLocalBounds().removeFromTop(100).removeFromTop(30).reduced(20),
               juce::Justification::centredLeft, true);
    
    // Центральное сообщение
    g.setColour(juce::Colour::fromRGB(100, 150, 200));
    g.setFont(20.0f);
    g.drawText("Этап 1 завершён: Базовый VST3 плагин успешно собран",
               getLocalBounds().withTrimmedTop(200).withTrimmedBottom(200),
               juce::Justification::centred, true);
    
    g.setColour(juce::Colours::grey);
    g.setFont(14.0f);
    g.drawText("Следующий этап: Создание 6 Drum Parts и базового аудиодвижка",
               getLocalBounds().withTrimmedTop(300).withTrimmedBottom(150),
               juce::Justification::centred, true);
}

void VDrumLabAudioProcessorEditor::resized()
{
    // Layout будет реализован на этапе создания UI
}
