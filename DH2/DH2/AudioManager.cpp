#include "AudioManager.h"
#include <fstream>
#include <iostream>

AudioManager::AudioManager()
	: m_TextFileName("Name.txt") // Change "Name.txt" to the correct file name that has the names of the Audio File
	                             // Make sure, in the Text File, that each line does not end with a "Space (White Space)"
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
	std::ifstream s_InFile;
	s_InFile.open(m_TextFileName);

	if (s_InFile.is_open())
	{
		int s_Tick = 0;
		while (!s_InFile.eof())
		{
			std::getline(s_InFile, m_FileNames[s_Tick]);
			s_InFile.get(); // Gets rid of the "/n" at the end of each line

			if (!s_InFile)
			{
				break;
			}

			s_Tick++;
		}
	}
	else
	{
		std::cout << "Cannot Open File: " << m_TextFileName << std::endl;
	}
}

void AudioManager::GenerateBuffers()
{
	ListOfAudio s_Temp = ListOfAudio::FIRST;

	for (int i = 0; i < m_FileNames.size(); i++)
	{
		if (!m_TempBuffer.loadFromFile(m_FileNames[i]))
		{
			m_SoundBuffers[s_Temp] = m_TempBuffer;
			static_cast<ListOfAudio>(s_Temp + 1);
		}
	}
}

void AudioManager::GenerateSounds()
{

	for (ListOfAudio i = ListOfAudio::FIRST; i < ListOfAudio::COUNT; static_cast<ListOfAudio>(i + 1))
	{
		m_TempSound.setBuffer(m_SoundBuffers[i]);
		m_Sounds[i] = m_TempSound;
	}
}
