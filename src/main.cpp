#include <iostream>
#include <string>
#include <sstream>
#include <algorithm>
#include <spdlog/spdlog.h>

std::string createGetRequest(std::string url, std::string content);

int main(int argc, char *argv[])
{
    for (int i = 1; i < argc; i++)
    {
        std::string arg = argv[i];
        std::transform(arg.begin(), arg.end(), arg.begin(), ::tolower);
        if (arg == "-h" || arg == "--help")
        {
            std::cout << "Help" << std::endl;
        }
        else
        {
            std::cout << "Git gud"
                      << "\n";
        }
    }

    createGetRequest("google.com/test/test", "");
}

std::string createGetRequest(std::string url, std::string content)
{
    std::stringstream request;
    size_t end_of_domain = url.find("/");
    std::string domain = url.substr(0, end_of_domain);
    std::string path = url.substr(end_of_domain);
    spdlog::info("DOMAINSS {}", domain);
    spdlog::info("PATH {}", path);

    // request << "GET "<< url << "HTTP"
    return "";
}