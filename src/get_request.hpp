#include "request.hpp"

class GetRequest
{
public:
    GetRequest(std::string url);
    void addHeader(std::string key, std::string value);

private:
    Request request;
    friend std::ostream &operator<<(std::ostream &os, const GetRequest &request);
};
