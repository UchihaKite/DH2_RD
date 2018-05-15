#include "AudioManager.h"

AudioManager::AudioManager()
{
	GenerateFileNames();
	GenerateBuffers();
	GenerateSounds();
}

sf::Sound AudioManager::PlaySound(ListOfAudio Audio)
{
	return m_Sounds[Audio];
}

void AudioManager::GenerateFileNames()
{
}

void AudioManager::GenerateBuffers()
{
}

void AudioManager::GenerateSounds()
{
}
