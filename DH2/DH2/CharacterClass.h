#pragma once
#include <vector>
//===========================================================================================================================================
//	The base class for character jobs, IE: Warrior Mage Rogue ETC.
//	This class will contain a skill tree, made for assigning points
//	This class *may* also contain the list of equipped skills, unless we make all unlocked skills available
//	Depending on the layout, may also have certain equippable passives, to further customize.
//===========================================================================================================================================
class CharacterClass
{
public:
	CharacterClass();
	~CharacterClass();

protected:
	//std::vector<Skills> m_skillList; //List of skills (to be made)
	//JobTree* m_jobTree; //The job tree, on level up character will recieve skill/stat points. May apply there or whatever
	std::string m_className;
};

