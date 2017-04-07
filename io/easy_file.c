/*
* Copyright(C) 2011-2012 Alibaba Group Holding Limited
* 
* This program is free software; you can redistribute it and/or modify
* it under the terms of the GNU General Public License version 2 as
* published by the Free Software Foundation.
*/


#undef _XOPEN_SOURCE
#define _XOPEN_SOURCE 500
#include <unistd.h>
#ifndef __APPLE__
#include <sys/sendfile.h>
#endif
#include "easy_io.h"
#include "easy_file.h"
#include "easy_connection.h"
#include "easy_message.h"
#include "easy_request.h"
#include "easy_file.h"
#include "easy_client.h"
#include "easy_socket.h"
#include "easy_log.h"
#undef _XOPEN_SOURCE
#define _XOPEN_SOURCE 600
#include <fcntl.h>

easy_file_task_t *easy_file_task_create(easy_request_t *r, int fd, int bufsize)
{
    struct stat             fs;
    easy_file_task_t        *ft;

    ft = (easy_file_task_t *)easy_pool_calloc(r->ms->pool, sizeof(easy_file_task_t));

    if (ft == NULL)
        return NULL;

    ft->fd = fd;

    if (fstat(fd, &fs) == 0)
        ft->count = fs.st_size;

    if (bufsize == 0) bufsize = EASY_MAX_FILE_BUFFER;

    ft->bufsize = easy_min(ft->count, bufsize);
    ft->b = easy_buf_create(r->ms->pool, ft->bufsize);
    ft->buffer = ft->b->pos;

    if (ft->b == NULL)
        return NULL;

    return ft;
}

void easy_file_task_reset(easy_file_task_t *ft, int type)
{
    easy_list_init(&ft->b->node);
    ft->b->pos = ft->buffer;
    ft->b->last = ft->b->pos;
    ((easy_file_buf_t *)ft->b)->flags = type;
}

/**
 * file_task process
 */
/*
int easy_file_task_process(easy_file_task_t *ft)
{
    int64_t     rc = 0;
    long        offset = ft->offset;

    do {
        switch(ft->type) {
        case EASY_FILE_WRITE:
            rc = pwrite(ft->fd, ft->buf, ft->count, offset);
            break;

        case EASY_FILE_READ:
            rc = pread(ft->fd, ft->buf, ft->count, offset);
            break;

        case EASY_FILE_SENDFILE:
        case EASY_FILE_WILLNEED:
            rc = posix_fadvise(ft->fd, offset, ft->count, POSIX_FADV_WILLNEED);
            break;
        }
    } while(rc == -1 && errno == EINTR);

    // 结果处理
    if (rc == -1) {
        ft->ret = (errno > 0) ? -errno : EASY_ERROR;
    } else {
        ft->ret = rc;
    }

    ft->done = 1;
    return rc;
}
*/
