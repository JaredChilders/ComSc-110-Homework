#include <iostream>
#include <string>
#include <sstream>
#include <fstream>

using namespace std;

void encrypt(){
	int n;
	string input,
		   key;
	ifstream inFile;
	ofstream outFile;
	cout << "Input a key: ";
	getline(cin, key);
	stringstream(key) >> n;

	inFile.open("message.txt");
	outFile.open("encrypted.txt");

	while (getline(inFile, input)) {
		string encryption(input);
		for (int i = 0; i < input.size(); i++) {
			if (isalpha(input.at(i))) {
				char c = tolower(input.at(i));
				encryption.at(i) = (((c - 'a') + n) % 26) + 'a';
			}
		}
		cout << encryption << endl;
		outFile << encryption << endl;
	}
	inFile.close();
	outFile.close();
}

void decrypt(){
	int n;
	string input,
		key;
	ifstream inFile;
	ofstream outFile;
	cout << "Input a key: ";
	getline(cin, key);
	stringstream(key) >> n;

	inFile.open("encrypted.txt");
	outFile.open("decrypted.txt");
	while (getline(inFile, input)) {
		string decryption(input);
		for (int i = 0; i < input.size(); i++) {

			if (isalpha(input.at(i))) {
				char c = tolower(input.at(i));
				decryption.at(i) = (((c - 'a') + (26 - n)) % 26) + 'a';
			}
		}
		cout << decryption << endl;
		outFile << decryption << endl;
	}
	inFile.close();
	outFile.close();
}

int main(){
	string input;
	cout << "Menu" << endl
		<< "1. Encrypt" << endl
		<< "2. Decrypt" << endl
		<< "3. Exit" << endl;
	getline(cin, input);

	do {
		cout << "Input the desired operation: " << endl;
		switch (input.at(0)) {
		case '1': encrypt();
			break;
		case '2': decrypt();
			break;
		case '3': cout << endl << "You hace exited the program" << endl;
			break;
		default: cout << endl << "Invalid Input! Enter a number from 1 to 3!" << endl;
			break;
		}

	} while (input.at(0) != '3');
    
    return 0;
}
