#!/usr/bin/env python
# -*- coding:utf-8 -*-

import string
import random
import sys

def GenRandomName(length):
    #随机出数字的个数
    numOfNum = random.randint(1,length-1)
    numOfLetter = length - numOfNum
    #选中numOfNum个数字
    slcNum = [random.choice(string.digits) for i in range(numOfNum)]
    #选中numOfLetter个字母
    slcLetter = [random.choice(string.ascii_letters) for i in range(numOfLetter)]
    #打乱这个组合
    slcChar = slcNum + slcLetter
    random.shuffle(slcChar)
    #生成密码
    genPwd = ''.join([i for i in slcChar])
    return genPwd.upper()

def encryptStr(str):
    bytes = bytearray(str.encode('utf-8'));

    rnum = random.randint(0,99)

    enstr = ""

    for b in bytes:
        b = b ^ rnum;
        enstr += hex(b)+","

    enstr += hex(rnum);

    rname = GenRandomName(20)

    result = "static unsigned char _%s[] = {%s};\nstatic EncodedString _%s = { (char *)_%s, sizeof(_%s)};" % (rname,enstr,rname[:15],rname,rname);

    print (result)

if __name__ == "__main__":
    encryptStr(sys.argv[1])
