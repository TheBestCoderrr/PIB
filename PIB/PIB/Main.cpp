#include <iostream>
#include <string>
using namespace std;

string ConvertPIB(const string& str) {
	if (str.empty()) throw exception("string empty");
	size_t i;
	for(i = 0; str[i] == ' '; i++) {}
	size_t j;
	for(j = i; str[j] != ' '; j++) {}
	string result(str.begin() + i, str.begin() + j);
	result.push_back(' ');
	for(; str[j] == ' '; j++) {}
	result.push_back(str[j]);
	result.push_back('.');
	for(; str[j] != ' '; j++) {}
	for(; str[j] == ' '; j++) {}
	result.push_back(str[j]);
	result.push_back('.');
	return result;
}

int main() {
	try {
		cout << ConvertPIB("Ivanenko Petro Stepanovich") << endl;
		cout << ConvertPIB("   Ivanenko Petro Stepanovich") << endl;
		cout << ConvertPIB("   Ivanenko Petro Stepanovich    ") << endl;
		cout << ConvertPIB("   Ivanenko    Petro      Stepanovich    ") << endl;
	}
	catch (exception ex) { cout << ex.what() << endl; }
}