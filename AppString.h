//
//  AppString.h
//  StringDemo
//
//  Created by monkey on 2016/12/2.
//  Copyright © 2016年 netease. All rights reserved.
//

//没有开启优化的情况下gcc默认不展开inline函数，简单的说就是不优化的情况下，inline没有任何作用。

#ifndef AppString_h
#define AppString_h

#ifndef DecodeCString
#define DecodeCString         _5C276984_F31_B643CA_7A2_4E6C4F369CE4
#endif

#ifndef DecodeOcString
#define DecodeOcString        _B97DE2E4_175_F0C445_2D3_29549CFFE480
#endif

#ifdef __cplusplus
extern "C" {
#endif
    
    typedef struct _EncodedString{
        char* origstr;
        int size;
    }EncodedString;
    
    static inline char * DecodeCString(EncodedString *str) {
        
        char seed = str->origstr[str->size-1];
        
        int j = 0;
        
        do{
            str->origstr[j] ^= seed;
            j++;
        }while(j < str->size);
        
        return str->origstr;
    }
#ifdef __OBJC__
#import <Foundation/Foundation.h>
    static inline NSString * DecodeOcString(EncodedString *str) {
        
        char seed = str->origstr[str->size-1];
        
        int j = 0;
        
        do{
            str->origstr[j] ^= seed;
            j++;
        }while(j < str->size);
        
        return [[NSString alloc] initWithBytesNoCopy:str->origstr length:str->size-1 encoding:NSUTF8StringEncoding freeWhenDone:0];
    }
#endif
    
#ifdef __cplusplus
}
#endif

#endif

