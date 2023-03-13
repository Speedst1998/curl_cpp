#pragma once

#include <sstream>
#include "request.hpp"

class GetRequest
{
public:
    GetRequest(std::string url);
    void addHeader(std::string key, std::string value);

private:
    Request request;
    friend std::ostream &operator<<(std::ostream &os, const GetRequest &request);
    friend bool operator==(const std::string &lhs_request,  const GetRequest &rhs_request);
    friend bool operator==(const GetRequest &lhs_request, const std::string &rhs_request);
};

namespace cstd
{
    inline std::string to_string(const GetRequest &request)
    {
        std::stringstream result;
        result << request;
        return result.str();
    }
} // namespace cstd