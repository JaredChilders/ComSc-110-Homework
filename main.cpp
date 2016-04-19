#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <cctype>

using namespace std;

string encode(string inp1, int inp2) {
	string temp(inp1);
	for (int i = 0; i < temp.size(); i++) {
		if (isalpha(temp.at(i))) {
			char c = tolower(temp.at(i));
			temp.at(i) = ( ( ( c - 'a' ) + (inp2) ) % 26) + 'a';
		}
	}
	return temp;
}

string decypher(string inp1, int inp2) {
	string temp(inp1);
	for (int i = 0; i < temp.size(); i++) {
		if (isalpha(temp.at(i))) {
			char c = tolower(temp.at(i));
			temp.at(i) = ( ( ( c - 'a') + (26-inp2) ) % 26) + 'a';
		}
	}
	return temp;
}

int main() {

	string input, input2, output;
	int num;

	cout << "Enter a message: " << endl;
	getline(cin, input);

	cout << "Enter the amount you want to decode: " << endl;
	getline(cin, input2);
	stringstream(input2) >> num;

	output = encode(input, num);

	cout << "Encode message: " << output << endl;
	cout << "Decypher message: " << decypher(output, num) << endl;

	system("pause");
	return 0;
}
