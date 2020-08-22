
#include <stdio.h>
#include <string.h>
#include "../src/setproctitle.c"
#include "../src/zmalloc.h"
#include "my_sds.h"



PcMySdsBuf myNewSdsWithLen(void *initPtr, size_t initLen){
    struct MySdsHdr *mySdsHdr;
    if (initPtr) {
        mySdsHdr = zmalloc(sizeof(struct MySdsHdr) + initLen + 1);
    } else {
        mySdsHdr = zcalloc(sizeof(struct MySdsHdr) + initLen + 1);
    }

    if (mySdsHdr == NULL) {
        return NULL;
    }

    /**
     * 给这个结构体的属性设置值
     * 1:设置长度
     **/
     mySdsHdr->len = initLen;
     /**
      * 设置空闲空间
      */
      mySdsHdr->free = 0;

      /**
       * 如果参数中指定的初始化字符串不为空，则要设置到
       * 结构体的buf中
       */
    if (initPtr && initLen) {
        memcpy(mySdsHdr->buf, initPtr, initLen);
    }

    // 以 \0 结尾
    mySdsHdr->buf[initLen] = '\0';

    // 返回 buf 部分，而不是整个 sdshdr
    return (char *) mySdsHdr->buf;
}

PcMySdsBuf myNewSds(void *initPtr){
    if (initPtr) {
        return myNewSdsWithLen(initPtr, strlen(initPtr));
    } else {
        return myNewSdsWithLen("", 0);
    }
}


void freeMySds(PcMySdsBuf ptr) {
    /**
     * 如果指针为null，啥都不做
     */
    if (!ptr){
        return;
    }

    MySdsHdr *pHdr = (MySdsHdr*) (ptr - sizeof(MySdsHdr));
    zfree((char *)pHdr);
}

