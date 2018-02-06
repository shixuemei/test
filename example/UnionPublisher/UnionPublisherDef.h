//
//  UnionPublisherDef.h
//  UnionPublisher
//
//  Created by shixuemei on 10/28/17.
//  Copyright © 2017 ksyun. All rights reserved.
//

#ifndef _UNIONPUBLISHERDEF_H_
#define _UNIONPUBLISHERDEF_H_

#ifdef __cplusplus
extern "C"
{
#endif
    
#include <stdint.h>

/**
 * 发送端状态
 */
typedef enum _UnionPublisherStatus{
    /// 初始化状态
    UnionPublisher_Status_Idle      = 0,
    /// 推流中
    UnionPublisher_Status_Started   = 1,
    /// 推流结束
    UnionPublisher_Status_Stopped   = 2,
    /// 推流错误
    UnionPublisher_Status_Error     = 3,
}UnionPublisherStatus;
    
/**
 * 发送端错误码
 */
typedef enum _UnionPublisherError{
    /// 初始化状态
    UnionPublisher_Error_Unknown                = -10000,
    /// 无效的地址
    UnionPublisher_Error_Invalid_Address        = -10001,
    /// 链接服务器失败
    UnionPublisher_Error_ConnectServer_Failed   = -10002,
    /// 推流失败
    UnionPublisher_Error_ConnectStream_Failed   = -10003,
    /// 发送数据失败
    UnionPublisher_Error_Send_Failed            = -10004,
}UnionPublisherError;
    

/**
 * 数据类型
 */
typedef enum _UnionDataType
{
    UnionDataType_Number  = 0,
    UnionDataType_String,
}UnionDataType;

/**
 * 字典元素
 */
typedef struct _UnionDictElem
{
    uint8_t *name;
    UnionDataType type;
    union
    {
        double  number;
        char    *string;
    } val;
}UnionDictElem;

/**
 * 字典
 */
typedef struct _UnionDict
{
    int             number;
    UnionDictElem   *elems;
}UnionDict;

#ifdef __cplusplus
}
#endif

#endif //_UNIONPUBLISHERDEF_H_
