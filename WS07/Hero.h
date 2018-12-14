/* W07
* Hero.h
* Ivy Leano
*/

#ifndef SICT_HERO_H
#define SICT_HERO_H
#include<iostream>

namespace sict 
{
	//Predefined Constant
	const int _MAX_ROUNDS = 100;
	const int MAX_CHAR = 40;

	class Hero 
	{
	protected:
		char h_Name[MAX_CHAR];
		int h_Health;
		int h_Attack_Strength;

	public:
		//Constructors
		Hero();
		Hero(const char * Name, int Health, int Attack_Strength);
		void operator-=(int attack);
		bool isAlive();
		int attackStrength() const;
		friend std::ostream& operator<<(std::ostream& os, const Hero& hero);

	};
	//Helper Function - Non-Friend
	const Hero& operator*(const Hero& first, const Hero& second);

}
#endif // !SICT_HERO_H