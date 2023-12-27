#include"helper_function.hpp"

int main(int argc, char** argv){
    while(true){
        std::string inp;
        std::cout<<"Integer: ";
        std::cin>>inp;
        std::vector<int> v = char_to_vec(inp);
        if(v.size()>0){
            print(factorial(v));
        }
    }
    return 0;
}