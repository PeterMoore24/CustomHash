//The goal of this solution is to be able to hash or crack hashes specified by part 4 of assignment 4 for CSE365.
//The hash function takes input, hashes the input with md5 100 times, then with sha256 100 times, then with sha512 100 times.
//In its first revision, it will probably just have the hash I need to crack hard-coded in, but eventually I'd like
//	to expand it to be able to hash and crack based on character sets.
//
//I'm using code from zedwood.com to implement md5, sha256, and sha512, links here:
//md5: http://www.zedwood.com/article/cpp-md5-function
//sha256: http://www.zedwood.com/article/cpp-sha256-function
//sha512: http://www.zedwood.com/article/cpp-sha512-function

#include <string>
#include <iostream>
#include "md5.h"
#include "sha256.h"
#include "sha512.h"
using namespace std;

void printInput(string input) {
	for (int i = 0; i <= input.length(); i++) {
		printf("%c", input[i]);
	}
	printf("\n");
}

string recursiveInc(string input) {
	if (input.length() == 0) {
		return "";
	}
	else if (input[input.length()-1] == 'z') {
		return recursiveInc(input.substr(0, (input.length() - 1))) + "a";
	}
	else {
		input[input.length() - 1]++;
		return input;
	}
}

int main() {
	const string crack = "4aaa1b3dfb4fc47bf2986a07eea3ef78ebb449dd370a5db55c07b8b55d9c7a6d9d9cb7dd0097b9f7c1950feab91ea29f72802538192546a7bc39b71139c91753";
	string input = "aaaa`";
	string result;
	//cout << "beginning to crack\n";
	while (result != crack && input != "" && input != "zzzzz") {
		input = recursiveInc(input);
		///*
		if (input[2] == 'a') {
			cout << "input = " << input << "\n";
		}
		//*/
		result = input;
		//cout << "beginning md5 on " << input << "\n";
		for (int m = 0; m < 100; m++) {
			result = md5(result);
		}
		//cout << "beginning sha2\n";
		for (int s2 = 0; s2 < 100; s2++) {
			result = sha256(result);
		}
		//cout << "beginning sha5\n";
		for (int s5 = 0; s5 < 100; s5++) {
			result = sha512(result);
		}
	}
	if (input == "") {
		printf("Hash could not be cracked.");
		return 0;
	}
	cout << "input: \n" << input;
	return 0;
}
