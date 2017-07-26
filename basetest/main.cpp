#include <iostream>

int testFor() {
    int result = 0;
    for (int i = 0; i < 10; ++i) {
        result = result + 1;
    }
    return result;
}

int main() {
    int result=testFor();
    printf("out put for test=%d and printf keyword \n",result);
//    std::cout << "Hello, World!" << std::endl;
    return 0;
}