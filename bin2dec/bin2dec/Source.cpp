/*
	Gani Sagiev
	01/01/2024
	binary to decimal converter
	program gathers a binary number of 8 digits from user and converts the binary into decimal format.
*/

#include <iostream>
#include <string>
#include <regex>
using namespace std;

int binaryToDecimal(const string& binary) {
	int decimal = 0;
	int binarySize = binary.size();
	for (int i = 0;i < binary.size();++i) {
		int digit = binary[i]-'0';
		decimal += digit * pow(2, binarySize - 1 - i);
	}
	return decimal;
}

bool isValidBinary(string binary) {
	regex binaryPattern("^[01]{8}$");
	return regex_match(binary, binaryPattern);
}

string userInput() {
	string userBin;
	bool validBinary = false;
	do{
		cout << "Enter a 8 value binary: ";
		cin >> userBin;
		if (isValidBinary(userBin))
			validBinary = true;
		else
			cout << "incorrect format detected! please input a binary of 0s and 1s up to 8 digits. (example: 01100111)" << endl;
	} while (validBinary == false);

	return userBin;
}

int main() {
	string binary = userInput();
	int decimal = binaryToDecimal(binary);
	cout << "Binary format: " << binary<<endl;
	cout << "Decimal format: " << decimal;
	return 0;
}