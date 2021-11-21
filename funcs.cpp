//https://contest.yandex.ru/contest/27665/problems/C/

#include "funcs.h"
#include <bits/stdc++.h>

void parseFile(std::istream & input, std::ostream & output){

    std::map<std::string, unsigned int> dict;
    std::string word;
    while (input >> word){
        dict[word] += 1;
    }
    auto ans = std::max_element(dict.begin(),dict.end(),[](
            const std::pair<std::string, unsigned int > & a,
            const std::pair<std::string, unsigned int > & b){
        if(a.second == b.second)
            return a.first > b.first;
        return a.second < b.second;
    });
    output << ans->first;
}
