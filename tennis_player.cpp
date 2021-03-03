#include"tennis_player.h"
#include<iostream>

Tennis_player::Tennis_player(const string& fn, const string& ln, bool ht) :firstname(fn), lastname(ln), hastable(ht) {

};

string Tennis_player::name() const {
	return firstname;
}

std::ostream& operator<<(std::ostream& os,const Tennis_player& a) {
	os << a.firstname << " " << a.lastname << " " << "has table: " << a.hastable << '\n';
	return os;
}