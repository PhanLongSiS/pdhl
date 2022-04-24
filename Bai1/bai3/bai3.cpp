// bai3.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include<stdio.h>
#define _WINSOCK_DEPRECATED_NO_WARNINGS
#include<winsock2.h>
#pragma comment(lib, "ws2_32")

int main()
{
    DWORD mydrives = 20;
    char lpBuffer[20];
    char buffer[20];
    GetLogicalDriveStringsA(mydrives, (LPSTR)lpBuffer);
    for (int i = 0; i < 20; i++)
        buffer[i] = lpBuffer[i];
    printf("\n");
    printf("%s", buffer);
}

