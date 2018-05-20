/* 
 * File:   cont.h
 * Author: Nathan Duma
 *
 * Created on May 17, 2018, 5:42 PM
 */

#ifndef CONT_H
#define CONT_H

#ifdef __cplusplus
extern "C" {
#endif

#include <nusys.h>
    
NUContData contdata[1]; 
u8 contPattern;

void initController(void);

#ifdef __cplusplus
}
#endif

#endif /* CONT_H */

