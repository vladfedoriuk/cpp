#ifndef RATED_PLAYER
#define RATED_PLAYER
#include"tennis_player.h"
#include<iostream>
#include<cstdio>

class Rated_player : public Tennis_player {
private:
	std::size_t rating;
public:
	Rated_player(std::size_t r = 0, const string& fn = "none", const string& ln = "none", bool ht = false);
	Rated_player(std::size_t r, const Tennis_player& a);
	std::size_t Rating() const { return rating; };
	void reset_rating(std::size_t r) { rating = r; };
	friend std::ostream& operator<<(std::ostream& os, const Rated_player& a);
};

#endif
