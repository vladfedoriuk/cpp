#include"ans.h"
#include"decoder.h"
int main() {
	std::string file_name = "data.txt";
	ANS tans(file_name, 18);
	std::string encoded_file = "encoded.txt";
	std::vector<char> bits = tans.encode(encoded_file);
	//std::string decoded_file = "decoded.txt";
	Decoder decoder(encoded_file);
	std::vector<char> dec = decoder.decode();
	for (char c : dec) {
		std::cout << c;
	}
	std::cout << std::endl;
	system("pause");
	return 0;
}