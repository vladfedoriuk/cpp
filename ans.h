#pragma once
#include<string>
#include<cmath>
#include<fstream>
#include<vector>
#include<iostream>

class ANS {
private:
	std::size_t number_of_states;
	std::size_t alphavite_size;
	std::vector<char> data;
	std::vector<char> letters;
	std::vector<char> alphavite;
	std::vector<std::size_t> temp_freq;
	std::vector<int> frequency;
	std::vector<int> k;
	std::vector<int> nb;
	std::vector<int> temp_nb;
	std::vector<int> states;
	std::vector<int> start;
	std::vector<std::size_t> next;
	std::vector<int> encoding;
	inline double bits_needed(std::size_t length);
	inline void create_alphavite();
	inline void spread();
	inline void calculate_k();
	inline void calculate_nb();
	inline void create_states_table();
	inline void create_start_table();
	inline void create_encoding_table();
	inline int calculate_number_of_bits(int state_index, char symbol);
	inline int get_next_state_encoder(std::size_t number_of_bits, std::size_t state_index, char letter);
	std::vector<char> use_bits(std::size_t state_index, std::size_t number_of_bits);
public:
	static constexpr int MAXSIZE = 5000;
	std::vector<char> encode(const std::string& file_name);
	ANS(const std::string& file_name, std::size_t expected_size = 0);

};
