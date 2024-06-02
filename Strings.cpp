#include <iostream>
#include <array>
#include <cstring>
using namespace std;

int main() {

   char name[] = "Charaf"; 
   char b[] = "Ilyes";

   string fn = "Charaf"; 
   string lastname = "Ilyes";

   
   cout << strcat(name,b) << endl;
   cout << fn + lastname << endl;

   cout << fn.append(lastname) << endl; 
   
    return 0;
}