#include <catch2/catch_test_macros.hpp>
#include "get_request.hpp"

TEST_CASE("Get requests are built from url")
{
    GetRequest request("google.com");

    std::string expected_request = "GET google.com HTTP/1.1\r\n\r\n";
    REQUIRE(request == expected_request);
}