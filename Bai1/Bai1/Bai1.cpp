// Bai1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include<stdio.h>
#define _WINSOCK_DEPRECATED_NO_WARNINGS
#include<winsock2.h>
#pragma comment(lib, "ws2_32")

int main()
{
    WSADATA wsa;
    WSAStartup(MAKEWORD(2, 2), &wsa);

    SOCKET client = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);

    char IPUrl[32];
    int port;

    printf("Nhap dia chi ten mien:");
    scanf_s("%s", &IPUrl);
    printf("\n Nhap cong:%d");
    scanf_s("%d", &port);

    SOCKADDR_IN addr;
    addr.sin_family = AF_INET;
    addr.sin_addr.s_addr = inet_addr(IPUrl);
    addr.sin_port = htons(port);

    int ret = connect(client, (SOCKADDR*)&addr, sizeof(addr));
    if (ret == SOCKET_ERROR)
    {
        ret = WSAGetLastError();
        printf("Ket noi khong thanh cong - %d\n", ret);
        return 1;
    }
    //
    char name[MAX_COMPUTERNAME_LENGTH + 1];
    DWORD size = sizeof(name);
    GetComputerNameA(name, &size);
    send(client, name, strlen(name), 0);
    //
    DWORD mydrives = 20;
    char lpBuffer[20];
    GetLogicalDriveStringsA(mydrives, (LPSTR)lpBuffer);
    send(client, lpBuffer, strlen(lpBuffer), 0);
    closesocket(client);
    WSACleanup();
}


