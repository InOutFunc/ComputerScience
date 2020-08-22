#ifndef __SDS_H
#define __SDS_H

#include <stdio.h>
#include <string.h>
#include "../src/setproctitle.c"
#include "../src/zmalloc.h"


/**
 * 命名规范：
 * 如果是指针，则最前面的字母为p，表示该类型，是一个指针，pointer
 * 第二个字母，为指向的指针的类型，这里pc，表示指向char的指针
 * ps：指向结构体的指针
 * 以此类推
 */
typedef char* PcMySdsBuf;

/**
 * 定义我们的简单动态字符串结构体
 */
typedef struct MySdsHdr{
    // buf 中已占用空间的长度
    int len;

    // buf 中剩余可用空间的长度
    int free;

    // 数据空间
    char buf[];
}MySdsHdr;

/**
 * 新建一个mySdsHdr结构体
 * 参数：initPtr，初始化字符串的指针
 * size_t，该初始化字符串的长度，或者你可以自己指定一个长度，该长度要大于初始化字符串的长度
 * 返回： 新建的mySdsHdr结构体的，指向buf位置的指针
 */
PcMySdsBuf myNewSdsWithLen(void *initPtr, size_t initLen);

/**
 * 重载函数，重载了myNewSdsWithLen，默认使用初始化字符串的长度
 */
PcMySdsBuf myNewSds(void *initPtr);

/**
 * 释放该pcMySdsBuf所在的结构体的空间,会包括其header，一起释放
 */
void freeMySds(PcMySdsBuf ptr);


#endif