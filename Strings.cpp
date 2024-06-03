#include <iostream>
#include <array>
#include <cstring>
using namespace std;

int main() {

   char name[] = "Charaf"; 
   char b[] = "jjajajja";

   string fn = "Charaf"; 
   string lastname = " jajjajajaj";

   
   cout << strcat(name,b) << endl;
   cout << fn + lastname << endl;

   cout << fn.append(lastname) << endl; 
   
    return 0;
}
