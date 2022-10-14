#include <cstdio>
#include "vector.h"

using namespace bitndev;

int main(int argc, char* argv[])
{
    Vector vector = Vector();
    vector.insert(0);
    vector.insert(4);
    vector.insert(1);
    vector.insert(5);
    vector.insert(2);
    vector.insert(3);

    printf("Before get\n");
    for(int i = 0; i < vector.length(); i++)
    {
        printf("Element at %d is: %.0lf\n",i,vector.get(i));
    }
    printf("\n");

    printf("after get\n");
    vector.removeFrom(vector.length()-1);
    for(int i = 0; i < vector.length(); i++)
    {
        printf("Element at %d is: %.0lf\n",i,vector.get(i));
    }

    for(int i = 0; i < 4; i++)
    return 0;
}
