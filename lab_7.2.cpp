#include <iostream>
#include <initializer_list>

using namespace std;


int min(initializer_list<int> il) {
    int min = *il.begin();

    for (auto x : il) {
        if (x < min)
            min = x;
    }

    return min;
}


double min(initializer_list<double> il) {
    double min = *il.begin();

    for (auto x : il) {
        if (x < min)
            min = x;
    }

    return min;
}




int main() {

    cout << min({1, 2, 10, 100, -100}) << endl;
    cout << min({1, 2, 10, 100, -100, 545, 34, 65, 878, 86, -1943, -43843}) << endl;
    cout << min({1, 2, 10, 100, -100, 34, 54, 54, 34, -3223}) << endl;

    cout << min({-32.434, -435454.243, 12.343, 43.43, 54.545}) << endl;

    return 0;
}