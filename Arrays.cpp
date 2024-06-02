#include <iostream>
#include <array>
using namespace std;

int main() {

    array<int, 4> points={1,2,3,4};
    cout << points.size() << endl;

    cout << points[0] << endl;
    cout << points[1] << endl;
    cout << points[2] << endl;
    cout << points[3] << endl;

    points.fill(true);

    cout << points[0] << endl;
    cout << points[1] << endl;
    cout << points[2] << endl;
    cout << points[3] << endl;

    points.fill(false);

    cout << points[0] << endl;
    cout << points[1] << endl;
    cout << points[2] << endl;
    cout << points[3] << endl;

    return 0;
}