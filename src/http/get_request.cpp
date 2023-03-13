#include <sstream>
#include <algorithm>
#include <cstring>
#include "get_request.hpp"

GetRequest::GetRequest(std::string url)
{
    request.requestLine.method = HttpMethod::GET;
    request.requestLine.path = url;
    request.requestLine.protocol = "HTTP/1.1";
}

// TODO : move to request class and use inheritance
void GetRequest::addHeader(std::string key, std::string value)
{
    request.headers[key] = value;
}

bool operator==(const std::string &lhs_request, const GetRequest &rhs_request)
{
    return cstd::to_string(rhs_request) == lhs_request;
}

bool operator==( const GetRequest &lhs_request, const std::string &rhs_request)
{
    return rhs_request == cstd::to_string(lhs_request);
}

// TODO move operator overloads to request object and use inheritance instead of composition
std::ostream &operator<<(std::ostream &os, const GetRequest &get_request)
{
    auto request = get_request.request;
    os << "GET " << request.requestLine.path << " " << request.requestLine.protocol << "\r\n";
    std::for_each(request.headers.begin(), request.headers.end(), [&os](const auto &header)
                  { os << header.first << " " << header.second << "\r\n"; });
    os << "\r\n";
    return os;
}
