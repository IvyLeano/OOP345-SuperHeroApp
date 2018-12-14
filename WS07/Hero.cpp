/* W07
* Hero.cpp
* Ivy Leano
*/
#include<iostream>
#include<cstring>
#include"Hero.h"
using namespace std;

namespace sict 
{
	Hero::Hero()
	{
		h_Name[0] = '\0';
		h_Health = 0;
		h_Attack_Strength = 0;
	}

	Hero::Hero(const char * Name, int Health, int Attack_Strength)
	{
		bool invalidName = Name[0] == ' ' || Name == nullptr;
		bool invalidHealth = Health < 0;
		bool invalidAttackStrength = Attack_Strength < 0;

		if (!invalidName && !invalidHealth && !invalidAttackStrength) 
		{
			//Copy Name
			strncpy(h_Name, Name, sict::MAX_CHAR);
			h_Name[sict::MAX_CHAR - 1] = '\0';

			//Copy Health & Attack Strength
			h_Health = Health;
			h_Attack_Strength = Attack_Strength;
		}
		else
		{
			Hero();
		}
	}

	void Hero::operator-=(int attack)
	{
		bool negative = attack < 0;

		if (!negative) 
		{
			h_Health = h_Health - attack;
			negative = h_Health < 0;

			if (negative) 
			{
				Hero();
			}
		}
	}
	bool Hero::isAlive()
	{
		return h_Health > 0;
	}

	int Hero::attackStrength() const
	{
		return h_Attack_Strength;
	}

	std::ostream& operator<<(std::ostream &os, const Hero &hero) 
	{
		if (hero.h_Name[0] == '\0')
		{
			os << "No hero";
		}
		else 
		{
			os << hero.h_Name;
		}
		return os;
	}

	const Hero& operator*(const Hero &first, const Hero &second)
	{
		const Hero * winner = nullptr;
		Hero copyFirst = first;
		Hero copySecond = second;
		int round;

		//Battle Iteration
		round = 0;
		for (int i = 0; i < _MAX_ROUNDS - 1; i++) 
		{
			bool isAlive = copyFirst.isAlive() && copySecond.isAlive();

			if (isAlive) 
			{
				copyFirst.operator-=(copySecond.attackStrength());
				copySecond.operator-=(copyFirst.attackStrength());
			}
			else 
			{
				round = i;
				i = _MAX_ROUNDS;
			}
		}

		//Determining the Winner
		//Setting Winner Obj = copyFirst or copySecond
		if (copyFirst.isAlive() && copySecond.isAlive()) 
		{
			winner = &first;
		}
		else if (copyFirst.isAlive()) 
		{
			winner = &first;
		}
		else 
		{
			winner = &second;
		}
		//Winner Output
		cout << "Ancient Battle! " << (copyFirst) << " vs " << (copySecond)
			<< " : Winner is " << (*winner)
			<< " in " << round << " rounds."
			<< endl;

		return *winner;
	}

}
