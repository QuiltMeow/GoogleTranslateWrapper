#include <string>

__declspec(dllimport) std::string googleTranslate(std::string, std::string, std::string);
__declspec(dllimport) std::string getGoogleTTSRequest(std::string, std::string);
__declspec(dllimport) bool playGoogleTTS(std::string, std::string);