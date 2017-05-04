/*
* Copyright(C) 2011-2012 Alibaba Group Holding Limited
* 
* This program is free software; you can redistribute it and/or modify
* it under the terms of the GNU General Public License version 2 as
* published by the Free Software Foundation.
*/


/**
 * 固定长度数组分配
 * 内部维护了一个内存池，因为元素为固定长度，故在删除元素后，为了
 * 重用已分配的内存，将其加入内部的list中，并优先进行下次分配
 * 为了能够加入list，限制objsize最小也得是easy_list_t的大小
 */

#include "easy_array.h"

easy_array_t *easy_array_create(int object_size)
{
    easy_pool_t     *pool;
    easy_array_t    *array;

    if ((pool = easy_pool_create(0)) == NULL)
        return NULL;

    if ((array = (easy_array_t *)easy_pool_alloc(pool, sizeof(easy_array_t))) == NULL)
        return NULL;

    easy_list_init(&array->list);
    array->count = 0;
    array->pool = pool;
    array->object_size = easy_max(object_size, (int)sizeof(easy_list_t));

    return array;
}

void easy_array_destroy(easy_array_t *array)
{
    easy_pool_destroy(array->pool);
}

void *easy_array_alloc(easy_array_t *array)
{
    if (easy_list_empty(&array->list) == 0) {
        array->count --;
        char *ptr = (char *)array->list.prev;
        easy_list_del((easy_list_t *)ptr);
        return ptr;
    }

    return easy_pool_alloc(array->pool, array->object_size);
}

void easy_array_free(easy_array_t *array, void *ptr)
{
    array->count ++;
    easy_list_add_tail((easy_list_t *)ptr, &array->list);
}
