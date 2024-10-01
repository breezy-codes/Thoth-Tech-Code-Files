using SplashKitSDK;

namespace RESTfulAPIApp
{
    public class Program
    {
        public static void Main()
        {
            // Get a list of a JSON web resource
            HttpResponse getData = SplashKit.HttpGet("https://jsonplaceholder.typicode.com/posts/", 443);
            string response = SplashKit.HttpResponseToString(getData);
            SplashKit.FreeResponse(getData);

            // To access each JSON key value pair the string should be split to an vector<json>
            // objects for simplicity sake we output just the string here.
            SplashKit.WriteLine(response);
        }
    }
}