#include"tennis_player.h"
#include<iostream>
#include<cstdio>
#include"ratedplayer.h"

Rated_player::Rated_player(std::size_t r, const string& fn, const string& ln, bool ht) :Tennis_player(fn, ln,ht), rating(r) {

};

Rated_player::Rated_player(std::size_t r, const Tennis_player& a): rating(r)

