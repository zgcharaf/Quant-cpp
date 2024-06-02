#include <iostream> 
#include <limits> 


 int main(){
    std::cout<<"charad";
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::cin.get();
    return 0;

 }