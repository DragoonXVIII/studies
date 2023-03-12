#ifndef TabliceDyn_H
#define TabliceDyn_H



//function declaration
//int add(int a, int b);
void losuj(int*, int, int, int ,int);

float *new_tab_1D(int);

float *new_tab_2D(int, int);

float *new_tab_2D_f(int ,int );

void delete_tab(float *);

void print_tab(float *, int, int);

void print_tab_d(int *, int, int);

void f1(float *, int, int);

void f2(int *, int, int);

//macro declaration
//#define ADD(a,b) a + b

//typedef declaration (not this time)
#endif // TABLICEDYN_H
