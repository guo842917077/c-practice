#include <iostream>   //头文件
#include <string>//支持string
#include <cstring>
#include <array>
#include <vector>

using namespace std;

const int num = 4;
array<string, num> season = {"spring", "summer", "Fall", "Winter"};

int testFor(int num);//定义库函数
void testStruct();

void testUnion();

void testPoint();

void testArrayList();

void testPointCharArray();

void testArrayVector();

void testPointArray(int *arrPoint, const int arrConst[]);

void testStringArray(array<string, 4> *seasons);

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
int *arr = new int[6]{1, 2, 3, 4, 5, 6};
const int *arrConst = new int[6]{1, 2, 3, 4, 5, 6};

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
//    testPoint();
//    testArrayList();
//    testPointCharArray();
//    testArrayVector();
//    testPointArray(arr, arrConst);
    testStringArray(&season);
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
    Person *test = new Person;
    test->name = "guo";//访问结构成员的方式
    (*test).age = 32;
    cout << "output person name : " << test->name << endl;
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

/**
 * 访问指针数组的元素可以直接使用数组名加位置
 */
void testArrayList() {
    int staticArray[10];//声明一个静态数组，它的长度是在编译是分配的
    int size = 10;
    int *arrayList = new int[size];//创建一个动态数组，它的值可以在运行时设置
    for (int i = 0; i < 10; ++i) {
        arrayList[i] = i;
    }
    //获取数组中的值
    cout << "arrayList[3] : " << arrayList[3] << " 数组名表示数组第一个位置的地址 ： " << arrayList << endl;
    //访问数组的等价操作，表示移动数组的地址：增加数组当前表示的类型所占用的内存的n倍。比如double占用8个字节，那么+3代表向右移动3*8个字节。
    cout << "arrayList[3] 等价于 *(arrayList + 3） : " << *(arrayList + 3) << endl;
    //delete要和new配套使用
    delete[] arrayList;//删除数组用delete []
    cout << "reuse arrayList memory : " << arrayList[3] << endl;
    //??
}

//数组的名字将解释为第一个元素的地址,即t的地址，输出数组名首先会输出第一个元素，然后输出后面的字符，直到遇到空字符 \0，cout也是根据地址找到对应的字符串
void testPointCharArray() {
    char haha[] = "t\0est";
    cout << "char array name : " << haha << " char position " << &haha << endl;
    char *copyChar = new char[strlen(haha) + 1];
    strcpy(copyChar, haha);
    cout << "copychar use strcpy :" << copyChar << endl;
}

/**
 * c++ 提供了动态数组的实现
 * array vector 和java 一样一个线程安全 一个不安全
 */
void testArrayVector() {
    vector<int> vector1(10);
    array<int, 10> array1;
    vector1[0] = 0;
    array1[0] = 0;
    vector1.at(1) = 1;
    array1.at(1) = 1;
    cout << "array vector assign param : " << vector1[1] << endl;
}

/**
 *
 * @param arrPoint 当且当数组作为参数的时候 数组名代表整个数组，否则代表第一个元素的地址
 * @param arrConst const修饰数组 代表数组的值不可以修改
 */
void testPointArray(int *arrPoint, const int arrConst[]) {
    for (int i = 0; i < 6; i++) {
        cout << "使用const修饰的数组名不能被修改 : " << arrConst[i] << endl;
    }
    for (int j = 0; j < 6; ++j) {
        cout << "查询数组的值 : " << arrConst[j] << endl;
    }
}


/**
 *
 * @param seasons 参数优先使用指针，因为值传递方法会复制一份值的副本  而指针直接操作原数据 避免了复制
 */
void testStringArray(array<string, num> *seasons) {

    for (int i = 0; i < num; ++i) {
        cout << season[i] << endl;
    }
}