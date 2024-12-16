using SplashKitSDK;

namespace RESTfulAPIApp
{
    public class Program
    {
        public static void Main()
        {
            // Create a JSON Web resource
            // Create the JSON body for the http post call
            Json body = SplashKit.CreateJson();
            SplashKit.JsonSetString(body, "title", "foo");
            SplashKit.JsonSetString(body, "body", "test entry");
            SplashKit.JsonSetNumber(body, "userId", 1);

            // Create the headers for the HTTP POST call
            List<string> headers = new List<string>
            {
            "Content-type: application/json; charset=UTF-8"
            };

            // Send the request
            HttpResponse getData = SplashKit.HttpPost("https://jsonplaceholder.typicode.com/posts", 443, SplashKit.JsonToString(body), headers);
            string response = SplashKit.HttpResponseToString(getData);
            SplashKit.FreeResponse(getData);

            // Output the response
            Json jsonResponse = SplashKit.JsonFromString(response);
            SplashKit.WriteLine("Following resource has been created");
            SplashKit.WriteLine("UserID => " + SplashKit.JsonReadNumberAsInt(jsonResponse, "userId"));
            SplashKit.WriteLine("ID     => " + SplashKit.JsonReadNumberAsInt(jsonResponse, "id"));
            SplashKit.WriteLine("Title  => " + SplashKit.JsonReadString(jsonResponse, "title"));
            SplashKit.WriteLine("Body   => " + SplashKit.JsonReadString(jsonResponse, "body"));
            SplashKit.WriteLine("================");
        }
    }
}