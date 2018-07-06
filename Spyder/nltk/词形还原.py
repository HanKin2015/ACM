# -*- coding: utf-8 -*-
"""
Created on Mon Apr  9 22:02:33 2018

@author: HanKin

[Python nltk.WordNetLemmatizer() Examples](https://www.programcreek.com/python/example/81649/nltk.WordNetLemmatizer)
词干提取和词形还原
[在线词形还原](http://text-processing.com/demo/stem/)
[nltk教程](http://textminingonline.com/dive-into-nltk-part-iv-stemming-and-lemmatization)
https://www.cnblogs.com/itdyb/p/5914467.html
"""

import nltk
from nltk.stem import WordNetLemmatizer 
from nltk.corpus import stopwords
import time

def crawl_lemmas(vocab):
        """Add Wordnet lemmas as definitions."""
        spwords=stopwords.words('english')
        lemmatizer = nltk.WordNetLemmatizer()
        ret = []
        for word in vocab:
            definitions = []
            word = word.lower()
            try:
                for part_of_speech in ['a', 's', 'r', 'n', 'v']:
                    lemma = lemmatizer.lemmatize(word, part_of_speech)
                    if lemma != word and not lemma in definitions:
                        if lemma not in spwords:
                            definitions.append(lemma)
                            #print(lemma)
                if len(definitions) == 0:
                    #print(word)
                    definitions.append(word)
            except:
                print('lemmatizer crashed')
            if definitions:
                #self._data[word] = definitions
                for num in definitions:
                    ret.append(num)
        return ret
        #self.save()
        
def file_open(filename):
    with open(filename, 'r') as file_to_read:
        #print(file_to_read.encoding) #文件编码
        #print(file_to_read.mode) #打开模式
        print(file_to_read.name) #文件名
        while True:
            line = file_to_read.readline()
            if not line: break
            content = line.split('\t')
            print(content)
        pass #Python pass是空语句，是为了保持程序结构的完整性。pass 不做任何事情，一般用做占位语句。
    #当你在编写一个程序时，执行语句部分思路还没有完成，这时你可以用pass语句来占位，也可以当做是一个标记，是要过后来完成的代码。
    #file_to_read.close()  python的with语句能处理异常并且会自动关闭文件句柄
    
def dblp_process(file_in, file_out):
    with open(file_out, 'w') as fout:
        with open(file_in, 'r') as fin:
            print('fin: ' + fin.name)
            print('fout: ' + fout.name)
            print('start lemmas......')
            while True:
                line = fin.readline()
                if not line: break
                #print(line)
                content = line.split('\t')
                fout.write(content[0] + '\t')
                #print(len(content))
                #print(content[1])
                #print(content[1][:-1])
                content[1] = content[1][:-1]
                content = content[1].split(',')
                #print('hejian')
                content = crawl_lemmas(content)
                #print(type(content))
                #print(content)
                
                dic = {}
                for attr in content:
                    if attr in dic:
                        dic[attr] += 1
                    else:
                        dic[attr] = 1
                dic = sorted(dic.items(),key = lambda x:x[1],reverse = True)
                
                flag = True  #处理末尾不添加逗号
                cnt = 0
                for key, val in dic:
                    if cnt == 20: break    #选取前20频繁属性
                    cnt += 1
                    if flag:
                        fout.write(key)
                        flag = False
                    else:
                        fout.write(',' + key)
                fout.write('\n')
                
if __name__ == '__main__':
    '''
    lis = ['a', 'b', 'a', 'c', 'd', 'c', 'a']
    dic = {}
    for elem in lis:
        if elem in dic:
            dic[elem] += 1
        else:
            dic[elem] = 1
    print(sorted(dic.items(),key = lambda x:x[1],reverse = True))
    dic = sorted(dic.items(),key = lambda x:x[1],reverse = True)
    for key, val in dic:
        print(key + ' ' + str(val))
    '''
    
    sestence = 'Stemming is funnier than a bummer says the sushi loving computer scientist doing nets are crying parsing problem affix grammars best better does were'
    words = sestence.split(' ')
    #words = ['stemming']
    #print(words)
    #crawl_lemmas(words)
    
    #NLTK词性tag含义https://blog.csdn.net/john159151/article/details/50255101
    #print(nltk.help.upenn_tagset())
    
    start_time = time.time()
    dblp_process('dblp_author_attr_original.txt', 'dblp_author_attributes.txt')
    #dblp_process('fin.txt', 'fout.txt')
    print('total time = %lf s' %(time.time() - start_time)) 
    
    #nltk.WordNetLemmatizer().lemmatize('mapping')
    
    
    
    
    