#include "vector.h"
#include <iostream>
#include <cstdlib>
#include <cstdio>

#define CAPACITY 255
float elements[CAPACITY];
int lastIndex = -1;

void leftShiftFrom(const int index)
{
    for(int i = lastIndex; i >= index; i--)
        elements[i+1] = elements[i];
}

void rightShiftFrom(const int index)
{
    for(int i = index; i <= lastIndex; i++)
        elements[i] = elements[i+1];
}
namespace bitndev
{
    void Vector::insert(const float element)
    {
        if(lastIndex == CAPACITY){
            char message[80];
            sprintf(message, "[Vector::insert] Can't insert more than %d elements in array",CAPACITY);
            throw std::runtime_error(message);
        }

        if(lastIndex < 0){
            lastIndex++;
            elements[lastIndex] = element;
            return;
        }

        int index = 0;
        for(; index <= lastIndex;index++)
        {
            if(element < elements[index])
                break;
        }
        leftShiftFrom(index);
        elements[index] = element;
        lastIndex+=1;
    }

    float Vector::get(const int index)
    {
        if(index > lastIndex)
            throw std::runtime_error("[get] Index out of range");
        return elements[index];
    }

    void Vector::removeFrom(const int index)
    {
        if(index > lastIndex)
            throw std::runtime_error("[removeFrom] Index out of range");
        rightShiftFrom(index);
        lastIndex-=1;
    }

    int Vector::length()
    { 
        return lastIndex+1;
    }
}
