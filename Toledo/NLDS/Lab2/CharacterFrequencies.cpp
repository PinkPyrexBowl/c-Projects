#include "CharacterFrequencies.h"
#include <iostream>

using namespace std;
CharacterFrequencies::CharacterFrequencies()
{
	
}

CharacterFrequencies::CharacterFrequencies(string line)
{
	readString(line);
}

void CharacterFrequencies::readString(string line)
{
	for(int i = 0; i < line.length(); i++)
	{
		int j = 0;
		for(j = 0; j < frequencies.size(); j++)
		{
		
			if(frequencies[j].first == line[i])
			{
				frequencies[j].second++;
				break;
			}
		}
		if(j == frequencies.size())
		{
			frequencies.push_back(make_pair(line[i],1));
		}
	}
}

int CharacterFrequencies::getFrequency(char c)
{
	for(auto pair : frequencies)
	{
		if(pair.first == c)
			return pair.second;
	}
	return -1;
}

void CharacterFrequencies::reset()
{
	for(auto pair : frequencies)
	{
		pair.second = 0;
	}
}
void CharacterFrequencies::printFrequencies()
{
	for(auto pair : frequencies)
	{
		if(pair.second == 0)
			continue;
		cout << pair.first << ": " << pair.second << "\n";
	}
	cout << flush;
}
int main()
{
	string line2 = "Twinkle twinkle little star, how I wonder what you are.";
	cout << line2 << endl;
	CharacterFrequencies line2CharFreq(line2);
	line2CharFreq.printFrequencies();
	line2CharFreq.readString(line2);
	line2CharFreq.printFrequencies();
}
