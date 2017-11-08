# -*- coding: utf-8 -*-

"""
Created on Tue Sep  5 16:13:36 2017

@author: HanKin
"""

'''
import zipfile,sys
zFile = zipfile.ZipFile("./dict/hejian.zip","r",zipfile.zlib.DEFLATED)
password = '11223344'
# password = bytes(password,"utf-8")

#password = password.encode("utf-8")
#print(type(password))
#print(password)
#tmp = b'11223344'
#print(len(password))
#if tmp == password:
#    print("yes")

try:
    # zFile.setpassword(password)
    zFile.extractall(pwd=b"11223344")

except (RuntimeError, TypeError, NameError):
    raise
    pass

#except:
#    print(sys.exc_info())
#    pass
zFile.close()
'''
import zipfile

def get_pwd():
    #密码字典的路径
    pwdPath='pwd.txt'
    pwdFile=open(pwdPath,'r')
    for line in pwdFile.readlines():
        password=line.strip('\n')
        print 'Try the password %s' % password
        if pojie_zip('hejian.zip', password):
            break
    pwdFile.close()
 
def pojie_zip(path, password):
    if path[-4:]=='.zip':
        #path = dir+ '\\' +file
        #print path
        zFile = zipfile.ZipFile(path, "r",zipfile.zlib.DEFLATED)
        #print zip.namelist()
        try:
            #若解压成功，则返回True,和密码
            zFile.extractall(pwd=password)
            print ' ----success!,The password is %s' % password
            zFile.close()
            return True
        except:
            pass #如果发生异常，不报错
    print 'error'

if __name__ == "__main__":
    get_pwd()
