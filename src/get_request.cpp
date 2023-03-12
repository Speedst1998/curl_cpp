#include <sstream>
#include <algorithm>
#include "get_request.hpp"

std::ostream &operator<<(std::ostream &os, const GetRequest& get_request) {
    auto request = get_request.request;
    os << "GET " << request.requestLine.path << " " << request.requestLine.protocol << "\r\n";
    std::for_each(request.headers.begin(), request.headers.end(), [&os] (const std::string& header){
        os << header << "\r\n";
    });
    os << "\r\n";

    return os;
}