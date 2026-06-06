#include <iostream>
#include "wavfile.h"
#include <cstring>
using namespace std;

void playfile(char* str) {
	if (playWavFile(str) == 0)
		cout << "Error: File not found!" << endl;
}

// Sample function for reading and storing sound data
void read_data(char* str) {
	int sampleRate = 0;
	int size = 100000;

	unsigned char* ptr = new unsigned char[size];

	if (readWavFile(str, ptr, size, sampleRate)) {
		cout << "File read successfully!" << endl;
		cout << "Sampling Rate: " << sampleRate << endl;
		cout << "Data size: " << size << endl;

		cout << "First 20 samples: ";
		for (int i = 0; i < 20 && i < size; i++) {
			cout << (int)ptr[i] << " ";
		}
		cout << endl;
	}
	else {
		cout << "Error reading file!" << endl;
	}

	delete[] ptr;
}

int main() {

	char str[50] = "";
	bool flag = true;

	while (flag) {

		cout << "Enter file name with (.wav) or exit: ";
		cin >> str;

		if (strcmp(str, "exit") != 0) {

			read_data(str);
			playfile(str);

		}
		else {
			flag = false;
		}
	}

	return 0;
}