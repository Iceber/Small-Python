/*
 * =====================================================================================
 *
 *       Filename:  dictobject.h
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2018/08/22 09时36分05秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (), 
 *   Organization:  
 *
 * =====================================================================================
 */

typedef struct _dictkeysobject PyDictKeysObject;

typedef struct {
        PyObjct_HEAD
        
        // Number of items in the dictionary
        Py_ssize_t mas_used;
        uint64_t ma_version_tag;
        PyDcitKeysObject *ma_keys;
        PYObject **ma_values;
}PyDictViewObject;
