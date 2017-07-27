#include <iostream>   //头文件

using namespace std;

/**
 * 学习命名空间和头文件
 * 1.include 引入头文件，可以使用头文件中定义的函数
 * 2.using 语句定义命名空间 类似于java中的包名 和namespace一起用表示使用头文件中的所有函数
 * 单独声明使用一种函数：using std::count
 * **/
int testFor(int num) {
    int result = 1;
    for (int i = 0; i < 10; i++) {
        result++;
    }
    return result;
}



int main() {
    int a1;
    cout<<"please input a number "<<endl;
    std::cin >> a1;//输入语句将控制台的数据赋值给一个引用。
    int result = testFor(a1);
    /**
     * 输出语句cout
     * << ：插入预算符 可以自动检查数据类型 传递给cout
     */
    cout << "a1 times cumulative result :  " << result << endl;
    return 0;
}