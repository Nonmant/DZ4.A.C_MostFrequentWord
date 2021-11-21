#define CATCH_CONFIG_MAIN
#define CATCH_CONFIG_ENABLE_BENCHMARKING
#include "catch.hpp"

TEST_CASE("Catch operability", "[simple]"){
    REQUIRE(1+1 == 2);
}

#include "funcs.h"

TEST_CASE("test 1, file", "[simple]"){
    std::ofstream inputPrepare;
    inputPrepare.open ("input.txt", std::ofstream::trunc);
    inputPrepare<<
                "apple orange banana banana orange"
            ;
    inputPrepare.close();

    std::ifstream input( "input.txt", std::ofstream::in);
    std::ofstream output("output.txt", std::ofstream::trunc);
    parseFile(input,output);
    input.close();
    output.close();

    std::ifstream outputCheck("output.txt", std::ofstream::in);
    std::stringstream buffer;
    buffer<<outputCheck.rdbuf();
    outputCheck.close();
    REQUIRE(buffer.str() ==
            "banana"
    );
}

TEST_CASE("test 2", ""){
    std::stringstream input(
            "oh you touch my tralala mmm my ding ding dong"
    );
    std::stringstream output;
    parseFile(input,output);
    REQUIRE(output.str() ==
            "ding"
    );
}

TEST_CASE("test 3", ""){
    std::stringstream input(
            "q w e r t y u i o p\n"
            "a s d f g h j k l\n"
            "z x c v b n m"
    );
    std::stringstream output;
    parseFile(input,output);
    REQUIRE(output.str() ==
            "0 0 1 0 "
    );
}
