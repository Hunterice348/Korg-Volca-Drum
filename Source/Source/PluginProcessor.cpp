#include "PluginProcessor.h"
#include "PluginEditor.h"

VDrumLabAudioProcessor::VDrumLabAudioProcessor()
    : AudioProcessor(BusesProperties()
                     .withOutput("Output", juce::AudioChannelSet::stereo(), true))
{
}

VDrumLabAudioProcessor::~VDrumLabAudioProcessor()
{
}

const juce::String VDrumLabAudioProcessor::getName() const
{
    return JucePlugin_Name;
}

bool VDrumLabAudioProcessor::acceptsMidi() const
{
    return true;
}

bool VDrumLabAudioProcessor::producesMidi() const
{
    return false;
}

bool VDrumLabAudioProcessor::isMidiEffect() const
{
    return false;
}

double VDrumLabAudioProcessor::getTailLengthSeconds() const
{
    return 0.0;
}

int VDrumLabAudioProcessor::getNumPrograms()
{
    return 1;
}

int VDrumLabAudioProcessor::getCurrentProgram()
{
    return 0;
}

void VDrumLabAudioProcessor::setCurrentProgram(int index)
{
}

const juce::String VDrumLabAudioProcessor::getProgramName(int index)
{
    return {};
}

void VDrumLabAudioProcessor::changeProgramName(int index, const juce::String& newName)
{
}

void VDrumLabAudioProcessor::prepareToPlay(double sampleRate, int samplesPerBlock)
{
    // Инициализация DSP будет добавлена на следующих этапах
}

void VDrumLabAudioProcessor::releaseResources()
{
}

bool VDrumLabAudioProcessor::isBusesLayoutSupported(const BusesLayout& layouts) const
{
    if (layouts.getMainOutputChannelSet() != juce::AudioChannelSet::mono()
        && layouts.getMainOutputChannelSet() != juce::AudioChannelSet::stereo())
        return false;

    return true;
}

void VDrumLabAudioProcessor::processBlock(juce::AudioBuffer<float>& buffer, juce::MidiBuffer& midiMessages)
{
    juce::ScopedNoDenormals noDenormals;
    
    auto totalNumInputChannels = getTotalNumInputChannels();
    auto totalNumOutputChannels = getTotalNumOutputChannels();

    // Очищаем выходные каналы, которые не имеют входных данных
    for (auto i = totalNumInputChannels; i < totalNumOutputChannels; ++i)
        buffer.clear(i, 0, buffer.getNumSamples());

    // Обработка MIDI сообщений
    for (const auto metadata : midiMessages)
    {
        auto message = metadata.getMessage();
        if (message.isNoteOn())
        {
            // Здесь будет обработка нот для запуска Drum Parts
        }
    }

    // DSP обработка будет добавлена на следующих этапах
    // Пока просто пропускаем тишину
}

void VDrumLabAudioProcessor::getStateInformation(juce::MemoryBlock& destData)
{
    // Сохранение состояния будет реализовано позже
}

void VDrumLabAudioProcessor::setStateInformation(const void* data, int sizeInBytes)
{
    // Загрузка состояния будет реализована позже
}

juce::AudioProcessorEditor* VDrumLabAudioProcessor::createEditor()
{
    return new VDrumLabAudioProcessorEditor(*this);
}

bool VDrumLabAudioProcessor::hasEditor() const
{
    return true;
}

juce::AudioProcessor* JUCE_CALLTYPE createPluginFilter()
{
    return new VDrumLabAudioProcessor();
}
