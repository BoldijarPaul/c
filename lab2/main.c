#include <stdio.h>
#include <stdlib.h>
#include "view.h"
#include "test.h"

int main()
{

     test t;
    runTest(t);

    controller contr;
    start(&contr);



    return 0;
}
