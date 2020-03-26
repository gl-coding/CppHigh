#include <iostream>
#include <omp.h>

int test(){
    #pragma omp parallel for
    for (char i = 'a'; i <= 'z'; i++)
        std::cout << i << std::endl;
    return 0;
}

int test1(){
    int initValue = 0;
    int numElements = 100;
    int array[100] = {0};
    #pragma omp parallel for
    for (int i = 0; i  < numElements; i++) {
        array[i] = initValue;
        initValue++;
    }
    return 0;
}

int test2(){
    int initValue = 0;
    int numElements = 100;
    int array[100];
    #pragma omp parallel for
    for (int i = 0; i  < numElements; i++) {
        array[i] = initValue + i;
    }
    return 0;
}

int test3(){
    int sum = 0;
    int array[100] = {0};
    #pragma omp parallel for reduction(+:sum)
    for (int i = 0; i < 100; i++) {
        sum += array[i];
    }
    return 0;
}

int doSomething(int a){
    return a;
}

int test4(){
    // 2. 通过OpenMP指令说明私有变量
    int temp;
    int array[100] = {0};
    #pragma omp parallel for private(temp)
    for (int i = 0; i < 100; i++) {
        temp = array[i];
        array[i] = doSomething(temp);
    }
    return 0;
}

int main()
{
    //test();
    //test1();
    //test2();
    //test3();
    test4();
    return 0;
}
