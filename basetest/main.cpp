#include <iostream>   //头文件
#include <string>//支持string
#include <cstring>

using namespace std;

int testFor(int num);//定义库函数
void testStruct();

void testUnion();

void testPoint();

void testArray() {
    int array[3] = {20, 30, 40};
    std::cout << "数组中第3个元素是：" << array[2] << endl;
    char bozz[] = "bozz";
    std::cout << "bozz 数组中第3个元素是：" << bozz[2] << " and size of array " << strlen(bozz)
              << endl;
    //面向行输入
    char cinCity[10];
    cout << "please input a city name \n";
    cin.getline(cinCity, 10);
    cout << "the city name : " << cinCity << endl;

    string a = "aaa";
    cout << a << endl;
}

void joinString() {
    //空白分隔分拼接string
    cout << "what's wrong with" " me" << endl;
}

void stringTest() {
    using namespace std;
    char a[] = "is a full string";
    char b[] = "";
    strcpy(b, a);
    cout << b << endl;
    string c = "c and new string : ";
    string d = "d";
    cout << c + d << endl;
}

/**
 * 学习命名空间和头文件
 * 1.include 引入头文件，可以使用头文件中定义的函数
 * 2.using 语句定义命名空间 类似于java中的包名 和namespace一起用表示使用头文件中的所有函数
 * 单独声明使用一种函数：using std::count
 * 3.static_cast<long> 来做类型转换。
 * 4.数组的使用
 * 5.字符串的拼接 使用空白分隔符
 * **/


const int ZERO = 0;//定义常量

int main() {
    using namespace std;
    unsigned int max_int = 10000;//使用unsigned 定义无负数的类型。
//    int a1;
//    cout << "please input a number " << endl;
//    std::cin >> a1;//输入语句将控制台的数据赋值给一个引用。
//    int result = testFor(a1);
//    /**
//     * 输出语句cout
//     * << ：插入预算符 可以自动检查数据类型 传递给cout
//     */
//    cout << "a1 times cumulative result :  " << static_cast<long>(result) << endl;
//    cout << "-----------------------------" << endl;
//    testArray();
//    joinString();
//    stringTest();
//    testStruct();
//    testUnion();
    testPoint();
    return 0;
}

int testFor(int num) {
    int result = 1;
    for (int i = 0; i < num; i++) {
        result++;
    }
    return result;
}

/**
 * 结构：类似于类，将多种类型拼接到一起组成结构。同一时刻可以是任何值
 * 共用体：类似于结构，它更像是给使用者提供了多种可选的类型，同一时刻只能为一种类型。
 * 1.共用体不能在初始化赋值 2。不能有string类型 3。不能作为参数。
 */
struct Person {
    string name;
    int age;
};
union HH {
    int id_val;
    char myName;
};

void testStruct() {
    Person p = {"guo", 12};
    cout << "output person name : " << p.name << endl;
}

void testUnion() {
    HH id2;
    id2.myName = static_cast<char>('ccc');
    cout << "output id  : " << id2.myName << endl;
}

/**
 * 指针练习  声明一个指针变量 typename* name；
 * 1。指针变量存储的是 地址----值所在的地址
 * 2。*name：解除引用-----通过指针变量存储的地址 获取到对应的值
 * 3。name：拿到的是存储的地址
 * 4。一定要先初始化指针变量，再赋值否则不知道值存储在哪个地址上了。
 * 5。初始化指针的方式 new typename---分配一块没有名字的内存  &typename 将已经声明的引用的地址付给指针。
 *
 */
void testPoint() {
    int *p_point = new int;
    *p_point = 1000;
    int data = 1001;
    int *p = &data;
    cout << "use new to assign a space : " << p_point << " and value is " << (*p_point) << endl;
    cout << " address of p " << p << " and value is " << (*p) << endl;
}