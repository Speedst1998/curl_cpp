#include <string>
#include <vector>

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

typedef std::vector<std::string> Headers;
struct Request
{
    RequestLine requestLine;
    Headers headers;
    std::string body;
};