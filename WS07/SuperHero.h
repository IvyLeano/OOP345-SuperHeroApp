/* W07
* SuperHero.h
* Ivy Leano
*/

#ifndef SICT_SUPER_HERO_H
#define SICT_SUPER_HERO_H
#include<iostream>
#include "Hero.h" 

namespace sict 
{
	class SuperHero : public Hero 
	{
	protected:
		int s_Attack_Bonus;
		int s_Defend_Strength;

	public:
		SuperHero();
		SuperHero(const char * Name, int Health, int Attack_Strength, int Attack_Bonus, int Defend_Strength);

		int attackStrength() const;
		int defend() const;
	};
	const SuperHero& operator*(const SuperHero& first, const SuperHero& second);
}
#endif // !SICT_SUPER_HERO_H
