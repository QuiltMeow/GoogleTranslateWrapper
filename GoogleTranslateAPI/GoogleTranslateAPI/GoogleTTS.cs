using System;
using System.IO;
using System.Net;
using System.Text;
using WMPLib;

namespace GoogleTranslateAPI
{
    public static class GoogleTTS
    {
        private static int fileCount;
        private static readonly string path = Path.GetTempPath();

        public static string getTTSRequest(string text, string language = "zh-tw")
        {
            StringBuilder sb = new StringBuilder("http://translate.google.com/translate_tts?ie=UTF-8&total=1&idx=0&textlen=32&client=tw-ob&q=");
            sb.Append(Uri.EscapeUriString(text));
            sb.Append("&tl=");
            sb.Append(language);
            return sb.ToString();
        }

        public static bool playTTS(string text, string language = "zh-tw")
        {
            string currentFileName = path + "TTSSound" + fileCount + ".mp3";
            ++fileCount;

            using (WebClient webClient = new WebClient())
            {
                try
                {
                    webClient.DownloadFile(new Uri(getTTSRequest(text, language)), currentFileName);
                }
                catch
                {
                    return false;
                }
            }

            WindowsMediaPlayer wmp = new WindowsMediaPlayer();
            try
            {
                wmp.URL = currentFileName;
                wmp.settings.volume = 100;
                wmp.controls.play();
                return true;
            }
            catch
            {
                return false;
            }
        }
    }
}