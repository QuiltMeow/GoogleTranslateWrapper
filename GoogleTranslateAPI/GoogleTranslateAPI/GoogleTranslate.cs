using System;
using System.Collections;
using System.Collections.Generic;
using System.Net.Http;
using System.Web.Script.Serialization;

namespace GoogleTranslateAPI
{
    public static class GoogleTranslate
    {
        private static readonly HttpClient httpClient = new HttpClient();

        public static string translate(string text, string origin = "en", string target = "zh-TW")
        {
            string url = string.Format("https://translate.googleapis.com/translate_a/single?client=gtx&sl={0}&tl={1}&dt=t&q={2}", origin, target, Uri.EscapeUriString(text));
            try
            {
                string result = httpClient.GetStringAsync(url).Result;
                if (result[1] == 'n')
                {
                    return string.Empty;
                }

                IList<dynamic> jsonData = new JavaScriptSerializer().Deserialize<List<dynamic>>(result);
                dynamic translationItem = jsonData[0];

                string translation = string.Empty;
                foreach (dynamic item in translationItem)
                {
                    IEnumerable translationLineObject = item as IEnumerable;
                    IEnumerator translationLineString = translationLineObject.GetEnumerator();
                    translationLineString.MoveNext();
                    translation += string.Format(" {0}", Convert.ToString(translationLineString.Current));
                }
                return translation.Substring(1);
            }
            catch (Exception ex)
            {
                return ex.Message;
            }
        }
    }
}