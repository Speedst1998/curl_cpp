#pragma once

#include <string>
#include <unordered_map>

enum HttpMethod
{
    GET,
    POST,
};

struct RequestLine
{
    HttpMethod method;
    std::string path;
    std::string protocol;
};

typedef std::unordered_map<std::string, std::string> Headers;
struct Request
{
    RequestLine requestLine;
    Headers headers;
    std::string body;
};