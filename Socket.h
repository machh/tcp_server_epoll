//
// Created by machh on 2020/12/23.
//
#ifndef EPOLL_SOCKET_H
#define EPOLL_SOCKET_H

#include "SocketAPI.h"

typedef unsigned long IP_t;

const int IP_SIZE = 24;

class Socket {
public:
    Socket();

    // 内部调用create
    Socket(const char* host, unsigned int port);

    virtual ~Socket();

public:
    bool create();
    void close();

    bool listen(int backlog);

    SOCKET accept(struct sockaddr* addr, unsigned int* addrlen);

    bool bind();
    bool bind(unsigned int port);

    // try connect to remote host
    bool connect();
    bool connect(const char* host, unsigned int port);

    // close previous connection and connect to another socket
    bool reconnect(const char* host, unsigned int port);

    // send data to peer
    unsigned int send(const void* buf, unsigned int len, unsigned int flags = 0);

    // receive data from peer
    unsigned int receive(void* buf, unsigned int len, unsigned int flags = 0);

    unsigned int available()const;

public:

    // get/set socket's linger status
    unsigned int getLinger()const;
    bool setLinger(unsigned int lingertime);

    bool isReuseAddr()const;
    bool setReuseAddr(bool on = true);

    // get is Error
    unsigned int getSockError()const;

    // get/set socket's nonblocking status
    bool isNonBlocking()const;
    bool setNonBlocking(bool on = true);

    // get/set receive buffer size
    unsigned int getReceiveBufferSize()const;
    bool setReceiveBufferSize(unsigned int size);

    // get/set send buffer size
    unsigned int getSendBufferSize()const;
    bool setSendBufferSize(unsigned int size);

    unsigned int getPort()const;
    IP_t getHostIP()const;

    // check if socket is valid
    bool isValid()const;

    // get socket descriptor
    SOCKET getSOCKET()const;

    bool isSockError()const;

public:
    SOCKET m_SocketID;
    SOCKADDR_IN m_SockAddr;

    char m_Host[IP_SIZE];
    unsigned int m_Port;
};


#endif //EPOLL_SOCKET_H
