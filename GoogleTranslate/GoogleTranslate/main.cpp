#include <iostream>
#include <sstream>
#include "GoogleTranslateBridge.h"

using namespace std;

string source, target;

int parseInt(string value) {
	stringstream ss;
	ss << value;

	int ret;
	if ((ss >> ret).fail()) {
		throw exception("輸入數值無效");
	}
	return ret;
}

void inputMode(string prefix) {
	string input;
	while (true) {
		cout << prefix << " : ";
		getline(cin, input);

		int value;
		try {
			value = parseInt(input);
		}
		catch (exception& ex) {
			cerr << ex.what() << endl;
			system("pause");
			cout << endl;
			continue;
		}

		switch (value) {
		case 1: {
			source = "en";
			target = "zh-TW";
			cout << endl;
			return;
		}
		case 2: {
			source = "zh-TW";
			target = "en";
			cout << endl;
			return;
		}
		default: {
			cerr << "輸入數值範圍錯誤" << endl;
			system("pause");
			cout << endl;
		}
		}
	}
}

int main() {
	cout << "===== Google 翻譯 API =====" << endl;
	cout << "1 英翻中" << endl;
	cout << "2 中翻英" << endl;
	cout << endl;
	inputMode("請輸入模式");

	string input;
	while (true) {
		cout << "請輸入原文 : ";
		getline(cin, input);
		cout << "翻譯結果 : " << googleTranslate(input, source, target) << endl;
		cout << endl;
	}
	return EXIT_SUCCESS;
}