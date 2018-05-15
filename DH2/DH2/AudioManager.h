#pragma once
#include <SFML/Audio.hpp>
#include <map>

enum ListOfAudio
{
	COUNT // List Audio Files Here to use for the Map Below
};

class AudioManager
{
public:
	AudioManager();
	sf::Sound PlaySound(ListOfAudio Audio);

private: // Functions
	void GenerateFileNames();
	void GenerateBuffers();
	void GenerateSounds();

private: // Variables
	std::map<ListOfAudio, sf::SoundBuffer> m_SoundBuffers;
	std::map<ListOfAudio, sf::Sound> m_Sounds;
	std::vector<std::string> m_FileNames;
	sf::SoundBuffer m_TempBuffer;
	sf::Sound m_TempSound;
};