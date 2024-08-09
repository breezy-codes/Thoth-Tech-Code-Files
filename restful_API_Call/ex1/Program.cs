﻿using SplashKitSDK;

// Get a single JSON web resource
HttpResponse getData = SplashKit.HttpGet("https://jsonplaceholder.typicode.com/posts/1", 443);
string response = SplashKit.HttpResponseToString(getData);
SplashKit.FreeResponse(getData);

// Output the response
Json jsonResponse = SplashKit.JsonFromString(response);
SplashKit.WriteLine("UserID => " + SplashKit.JsonReadNumberAsInt(jsonResponse, "userId"));
SplashKit.WriteLine("ID     => " + SplashKit.JsonReadNumberAsInt(jsonResponse, "id"));
SplashKit.WriteLine("Title  => " + SplashKit.JsonReadString(jsonResponse, "title"));
SplashKit.WriteLine("Body   => " + SplashKit.JsonReadString(jsonResponse, "body"));
SplashKit.WriteLine("================");

SplashKit.FreeJson(jsonResponse);