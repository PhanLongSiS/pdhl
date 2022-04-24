// Bai2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include<stdio.h>
#define _WINSOCK_DEPRECATED_NO_WARNINGS
#include<winsock2.h>
#pragma comment(lib, "ws2_32")

int main()
{
 
    // Khoi tao winsock
    WSADATA wsa;
    WSAStartup(MAKEWORD(2, 2), &wsa);
    // Tao socket cho ket noi
    SOCKET listener = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
    // Tao dia chi server
    printf("Nhap cong muon ket noi:");
    int port;
    scanf_s("%d",&port);
    SOCKADDR_IN addr;
    addr.sin_family = AF_INET;
    addr.sin_addr.s_addr = htonl(INADDR_ANY);
    addr.sin_port = htons(port);

    // Gan socket voi cau truc dia chi
    bind(listener, (SOCKADDR*)&addr, sizeof(addr));
    // Chuyen socket sang trang thai cho ket noi
    listen(listener, 5);
    // Chap nhan ket noi
    printf("\nDang cho ket noi...\n");

    SOCKET s1 = accept(listener, NULL, NULL);

    char buf[256];

    while (1)
    {
        int ret = recv(s1, buf, sizeof(buf), 0);

        if (ret <= 0)
        {
            if (ret == -1)
                ret = WSAGetLastError();
            break;
        }


        if (ret < sizeof(buf))
            buf[ret] = 0;
        printf("Chuoi ki tu nhan tu client:%s", buf);
    }

    printf("Ket thuc nhan du lieu");

    // Dong ket noi
    closesocket(s1);
}


