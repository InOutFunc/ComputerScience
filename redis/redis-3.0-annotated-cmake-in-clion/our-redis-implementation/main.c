#include <stdio.h>
#include "my_sds.h"

typedef struct Test_Struct{
    int a;
    int b;
}Test_Struct;

int pointerDemo();

int main() {
    return pointerDemo();

}

int simpleServer(){

}
int pointerDemo() {
    void *pVoid = malloc(4);
    memset(pVoid,0x01,4);

    int *pInt = pVoid;
    char *pChar = pVoid;
    short *pShort = pVoid;
    Test_Struct *pTestStruct = pVoid;

    printf("address:%p, point to %d\n", pChar, *(pChar));
    printf("address:%p, point to %d\n", pShort, *pShort);
    printf("address:%p, point to %d\n", pInt, *pInt);
    printf("address:%p, point to %d\n", pTestStruct, pTestStruct->a);

    printf("Hello, World!\n");
    PcMySdsBuf pcMySdsBuf = myNewSdsWithLen("hahahha", 6);
    printf("sds:%s",pcMySdsBuf);

    freeMySds(pcMySdsBuf);
    printf("sds:%s",pcMySdsBuf);

    struct MySdsHdr *pHdr = (struct MySdsHdr *) ((char *) pcMySdsBuf - sizeof(struct MySdsHdr));

    return 0;
}
