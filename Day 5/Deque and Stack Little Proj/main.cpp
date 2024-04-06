// Section 20
// Challenge 1
// Identifying palindrome strings using a deque
#include <cctype>
#include <deque>
#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
#include <stack>
#include <queue>


bool is_palindrome(const std::string& s)
{
    // You must implement this function.
    // Since we are learning the STL - use queue and stack to solve the problem.

    std::stack<char> stk;
    std::queue<char> que;
    for(const auto &c:s){
        if(isalpha(c)){
            stk.push(toupper(c));
            que.push(toupper(c));
        }
    }

    while(!stk.empty()){
        if(stk.top()==que.front()){
            stk.pop();
            que.pop();
            continue;
        }
        else
            return false;
    }
    return true;
}

int main()
{
    std::vector<std::string> test_strings{ "a", "aa", "aba", "abba", "abbcbba", "ab", "abc", "radar", "bob", "ana",
        "avid diva", "Amore, Roma", "A Toyota's a toyota", "A Santa at NASA", "C++",
        "A man, a plan, a cat, a ham, a yak, a yam, a hat, a canal-Panama!", "This is a palindrome", "palindrome" };
   
    std::cout << std::boolalpha;
    std::cout << std::setw(8) << std::left << "Result" << "String" << std::endl;
    for(const auto& s : test_strings) {
        std::cout << std::setw(8) << std::left << is_palindrome(s)  << s << std::endl;
    }
    std::cout << std::endl;
    return 0;
}