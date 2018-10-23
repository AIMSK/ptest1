#!/usr/bin/python
import os
#import socket
import struct
import re
#import binascii
#import dpkt
#import pcap
#import thread
#from Tkinter import *
#import Tkinter



class GUITest:
    def __init__(self):
        pass

if __name__ == "__main__":
    print "Hello world!"
    fh = open('./unicodech.txt')
    fh.seek(0,0)
    for num in range(0x4e00,0x9fa5):
        line = fh.readline()
        if ( num%0x100 == 0 ):
            print line, 
        if ( num == 0x9fa4 ):
            print line
    print "-------------------"
    fw = open("piny.dat","wb")
    fw.seek(0,0)
    fh.seek(0,0)
    for line in fh:
        #print line
        ma = re.match(r'\w+\s+\((\w+)\W.*',line )
        if ma:
            print line
            print ma.group(1)
            str = ma.group(1)
            fw.write(str[0])        
    
    fw.close()
    fh.close()
    

