#include <iostream>
#include <string>
#include <algorithm>

int main(int argc, char* argv[])
{
    for (int i = 1; i < argc; i++)
    {
        std::string arg = argv[i];
        std::transform(arg.begin(), arg.end(), arg.begin(), ::tolower);
        if (arg == "-h" || arg == "--help")
        {
            std::cout << "Help" << std::endl;
        }
        else {
            std::cout << "Git gud" << "\n";
        }
    }
}