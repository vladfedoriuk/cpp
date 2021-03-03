#ifndef _TENNIS_PLAYER_
#define _TENNIS_PLAYER_
#include<string>

using std::string;

class Tennis_player {
private:
	string firstname;
	string lastname;
	bool hastable;
public:
	Tennis_player(const string& fn = "none", const string& ln = "none", bool ht = false);
	string name() const;
	bool has_table() const { return hastable; };
	void reset_table(bool v) { hastable = v; };
	friend std::ostream& operator<<(std::ostream& os,const Tennis_player& a);
};
#endif