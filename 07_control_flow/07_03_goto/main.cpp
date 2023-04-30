#include <iostream>

int main() {
    int a = 5;
    creiker:    // statement label. These labels have function scope, that is, they are available in the whole function even before of them being declared
    std::cout << ++a << '\n';
    if(a < 10) {
        goto creiker;   // goto statement label. Its use is discouraged as usually leads to spaguetti code.
    }



}