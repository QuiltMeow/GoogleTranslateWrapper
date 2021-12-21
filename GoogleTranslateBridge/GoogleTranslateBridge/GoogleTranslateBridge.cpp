#include <string>

using namespace System;
using namespace System::Runtime::InteropServices;
using namespace GoogleTranslateAPI;

using namespace std;

string toNativeString(String^ manageString) {
	const char* cString = (const char*)(Marshal::StringToHGlobalAnsi(manageString)).ToPointer();
	string ret = cString;
	Marshal::FreeHGlobal(IntPtr((void*)cString));
	return ret;
}

__declspec(dllexport) string googleTranslate(string text, string origin, string target) {
	return toNativeString(GoogleTranslate::translate(gcnew String(text.c_str()), gcnew String(origin.c_str()), gcnew String(target.c_str())));
}

__declspec(dllexport) string getGoogleTTSRequest(string text, string language) {
	return toNativeString(GoogleTTS::getTTSRequest(gcnew String(text.c_str()), gcnew String(language.c_str())));
}

__declspec(dllexport) bool playGoogleTTS(string text, string language) {
	return GoogleTTS::playTTS(gcnew String(text.c_str()), gcnew String(language.c_str()));
}