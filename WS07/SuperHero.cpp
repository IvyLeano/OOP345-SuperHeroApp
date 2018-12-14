/* W07
* SuperHero.cpp
* Ivy Leano
*/

#include<iostream>
#include<cstring>
#include"SuperHero.h"
using namespace std;

namespace sict 
{
	SuperHero::SuperHero() :
		Hero() {
		s_Attack_Bonus = 0;
		s_Defend_Strength = 0;
	}
	SuperHero::SuperHero(const char * Name, int Health, int Attack_Strength, int Attack_Bonus, int Defend_Strength) :
		Hero(Name, Health, Attack_Strength) 
	{
		bool invalidAttack_Bonus = Attack_Bonus < 0;
		bool invalidDefend_Strength = Defend_Strength < 0;

		if (!invalidAttack_Bonus && !invalidDefend_Strength) 
		{
			s_Attack_Bonus = Attack_Bonus;
			s_Defend_Strength = Defend_Strength;
		}
	}
	int SuperHero::attackStrength() const
	{
		return h_Attack_Strength + s_Attack_Bonus;
	}
	int SuperHero::defend() const
	{
		return s_Defend_Strength;
	}
	const SuperHero& operator*(const SuperHero &first, const SuperHero &second)
	{
		const SuperHero * winner = nullptr;
		SuperHero copyFirst = first;
		SuperHero copySecond = second;
		int round;

		//Battle Iteration
		round = 0;
		for (int i = 0; i < _MAX_ROUNDS - 1; i++) 
		{
			bool isAlive = copyFirst.isAlive() && copySecond.isAlive();

			if (isAlive) 
			{
				copyFirst.operator-=(copySecond.attackStrength() - copyFirst.defend());
				copySecond.operator-=(copyFirst.attackStrength() - copySecond.defend());
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
		cout << "Super Fight! " << (copyFirst) << " vs " << (copySecond)
			<< " : Winner is " << (*winner)
			<< " in " << round << " rounds."
			<< endl;

		return *winner;
	}
}