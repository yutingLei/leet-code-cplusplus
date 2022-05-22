//
//  main.cpp
//  leet-code-cplusplus
//
//  Created by admin on 2022/5/16.
//

#include <iostream>

using namespace std;

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    int testTimes = 100000000;
    int count = 0;
    for (int i = 0; i < testTimes; i++) {
        if (random() > 300) {
            count++;
        }
    }
    printf("%f\n", (double)count / (double)testTimes);
    return 0;
}
