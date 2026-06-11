#include <iostream>
#include <windows.h>    // 加这行
using namespace std;
int main() {
    SetConsoleOutputCP(65001);  // 加这行：把控制台设为UTF-8
    cout << "你好" << endl;
}