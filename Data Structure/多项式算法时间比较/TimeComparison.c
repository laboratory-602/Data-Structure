//
//  main.c
//  Data Structure
//
//  Created by Derek Chan on 2020/9/11.
//

#include <stdio.h>
#include <time.h>
#include <math.h>

#define MAXN 10//多项式最大项数，即多项式阶数加1
#define MAXK 1e7//被测函数最大重复调用次数
clock_t start, stop;
double duration;

double Standard(int n, double a[], double x);
double Qin(int n, double a[], double x);
void run(double(*f)(int, double *, double), double a[], int case_n);

int main() {
    int i;
    double a[MAXN];
    
    //多项式系数赋值，即a[i] = i*
    for (i = 0; i < MAXN; i++) {
        a[i] = (double)i;
    }
    
    run(Standard, a, 1);
    run(Qin, a, 2);
    
    return 0;
}

//此函数用于测试被测函数运行时间
void run(double(*f)(int, double *, double), double a[], int case_n){ /*在C语言中，如果函数名想要作为函数参数，必须定义函数指针*/
    int i;

    start = clock();//开始计时
    for (i = 0; i < MAXK; i++) {
        (*f)(MAXN - 1, a, 1.1);
    }
    stop = clock();//结束技术

    //“CLOCKS_PER_SEC”是机器每秒所走的时钟打点数，在某些IDE下“CLOCKS_PER_SEC”也可被写作“CLK_TCK”
    duration = ((double)(stop - start)) / CLOCKS_PER_SEC / MAXK;
    printf("ticks %d = %f\n", case_n, (double)(stop - start)); //输出1代表函数Standard，2代表函数Qin
    printf("duration %d =% 6.2e\n", case_n, duration);
}

//多项式标准表达式
double Standard(int n, double a[], double x){
    int i;
    double p = a[0];
    for(i = 1; i <= n; i++){
        p += a[i] * pow(x, i);
    }
    return p;
}

//秦九韶算法
double Qin(int n, double a[], double x){
    int i;
    double p = a[n];
    for (i = n; i > 0; i--){
        p = a[i-1] + x * p;
    }
    return p;
}
