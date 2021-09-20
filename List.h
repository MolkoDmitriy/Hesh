#pragma once

#include <iostream>
using namespace std;

struct List
{
    int var;
    List* next;
};
void genRandMas(int* mas, int size);
void init(List*& ptr, int var);
void add(List*& ptr, int var);
void print_list(List* ptr);
void FillInc(List*& ptr, int size);