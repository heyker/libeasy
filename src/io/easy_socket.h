#ifndef EASY_SOCKET_H_
#define EASY_SOCKET_H_

#include <easy_define.h>
#include "easy_io_struct.h"
#include "easy_log.h"
#include <netinet/in.h>

/**
 * socket处理
 */

EASY_CPP_START

#define EASY_FLAGS_DEFERACCEPT 0x001
#define EASY_FLAGS_REUSEPORT   0x002
#define EASY_FLAGS_SREUSEPORT  0x004
#ifndef SO_REUSEPORT
#define SO_REUSEPORT 15
#endif

/**
 * 创建一个socket，监听端口
 */
int easy_socket_listen(int udp, easy_addr_t *address, int *flags);
/**
 * 把buf_chain_t上的内容通过writev写到socket上
 */
int easy_socket_write(easy_connection_t *c, easy_list_t *l);
int easy_socket_read(easy_connection_t *c, char *buf, int size, int *pending);

/*
 * 设置socket为非阻塞模式
 */
int easy_socket_non_blocking(int fd);
/*
 * 设置指定的tcp参数(IPPROTO_TCP)
 */
int easy_socket_set_tcpopt(int fd, int option, int value);
/*
 * 设置指定的socket参数(SOL_SOCKET)
 */
int easy_socket_set_opt(int fd, int option, int value);
int easy_socket_support_ipv6();
int easy_socket_usend(easy_connection_t *c, easy_list_t *l);

int easy_socket_udpwrite(int fd, struct sockaddr *addr, easy_list_t *l);
int easy_socket_tcpwrite(int fd, easy_list_t *l);

EASY_CPP_END

#endif
