// Buoi2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include<stdio.h>
#define _WINSOCK_DEPRECATED_NO_WARNINGS
#include<winsock2.h>
#pragma comment(lib, "ws2_32")

int main(int agr,char*argv[])
{
    WSADATA wsa;
    WSAStartup(MAKEWORD(2, 2), &wsa);

    SOCKET client = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);

	int port= cStringToInt(argv[2]);
    SOCKADDR_IN addr;
    addr.sin_family = AF_INET;
    addr.sin_addr.s_addr = inet_addr(argv[1]);
    addr.sin_port = htons(port);

	int ret = connect(client, (SOCKADDR*)&addr, sizeof(addr));
	if (ret == SOCKET_ERROR)
	{
		printf("Loi ket noi!");
		system("pause");
		return 1;
	}
	char buf[256];
	while (1)
	{
		printf("Nhap xau ky tu: ");
		fgets(buf, sizeof(buf), stdin);

		if (strncmp(buf, "exit", 4) == 0)
			break;

		send(client, buf, strlen(buf), 0);
	}
	// Dong ket noi va giai phong thu vien
	closesocket(client);
	WSACleanup();

}
int cStringToInt(char* str)
{
	int temp = 0;
	int sign = 1;
	if (*str == '-')
	{
		sign = -1;
		str++;
	}
	while (*str >= '0' && *str <= '9')
	{
		temp *= 10;
		temp += (int)(*str - '0');
		str++;
	}
	return temp * sign;
}


