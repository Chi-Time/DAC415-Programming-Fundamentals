#include <iostream>
#include <string>
#include <conio.h>

struct WarriorInfo
{
	std::string Name;
	int Health;
	float WeightKG;
	int Defense;
	int Attack;

	WarriorInfo ()
	{
		Name = "";
		Health = 100;
		WeightKG = 0.0f;
		Defense = 0;
		Attack = 0;
	}

	WarriorInfo (std::string name, int health, float weight, int defense, int attack)
	{
		Name = name;
		Health = health;
		WeightKG = weight;
		Defense = defense;
		Attack = attack;
	}
};

struct BossInfo
{
	WarriorInfo Info;
	int Multiplier;

	BossInfo (WarriorInfo info, int multiplier)
	{
		Info = info;
		Multiplier = multiplier;
	}
};

void WaitForKeypress ();
void DisplayWarriorInfo (const WarriorInfo& info);
void DisplayBossInfo (const BossInfo& info);

int main ()
{
	WarriorInfo warriorInfo = WarriorInfo ("Chenzira", 100, 4.5f, 30, 54);
	BossInfo bossInfo = BossInfo (WarriorInfo ("Nek", 150, 12.5f, 54, 23), 34);

	DisplayWarriorInfo (warriorInfo);
	DisplayBossInfo (bossInfo);

	WaitForKeypress ();

	return 0;
}

void DisplayWarriorInfo (const WarriorInfo& info)
{
	std::cout << "Name is: " << info.Name << std::endl;
	std::cout << "Current health: " << info.Health << std::endl;
	std::cout << "Current weight: " << info.WeightKG << std::endl;
	std::cout << "Defense rating is: " << info.Defense << std::endl;
	std::cout << "Attack rating is: " << info.Attack << std::endl;
}

void DisplayBossInfo (const BossInfo& info)
{
	DisplayWarriorInfo (info.Info);
	std::cout << "Multipler is: " << info.Multiplier << std::endl;
}

void WaitForKeypress ()
{
	std::cout << std::endl << "Press any key to continue..." << std::endl;

	_getch ();
}