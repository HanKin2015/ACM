﻿1. [编程|100分] 字符串去重及排序
时间限制：C/C++ 1秒，其他语言 2秒
空间限制：C/C++ 32768K，其他语言 65536K
题目描述
输入一个长度不超过10位的正整数，从左向右阅读，去除重复的数字，再从右向左阅读，返回一个新的整数。

输入描述:
一个长度不超过10位的正整数
输出描述:
去重重排后的一个正整数
示例1
输入
98766730
输出
36789

2. [编程|200分] 线性插值
时间限制：C/C++ 1秒，其他语言 2秒
空间限制：C/C++ 32768K，其他语言 65536K
题目描述
设备输出的频偏和温度相关，每个温度对应一个频偏值。已有5组温度和对应频偏值的样本(0.1℃精度)，采用简单的一阶插值方法,由已有的样本两头的温度-频偏关系，根据当前温度所在区间，计算出当前温度对应的频偏值。超出温度范围的，则输出边界温度对应的频偏值。

给定条件及样本如下：

温度范围：-40℃<=temp<=100℃

温度-频偏样本：(-150,-1000),(0,700),(40,940), (300, 3000),(650,7500)

 

所有输入输出均为整数

输入描述:
当前温度(0.1℃精度),如100表示10℃
输出描述:
温度对应的频偏
示例1
输入
100
输出
1300

3. [编程|300分] ini文件解析
时间限制：C/C++ 1秒，其他语言 2秒
空间限制：C/C++ 32768K，其他语言 65536K
题目描述
在项目开发过程中，经常会遇到需要读写各类配置文件的场景。ini就是一种比较场景、通用的配置文件格式，要求考生实现一个ini文件解析工具，并按照指定格式输出解析结果
输入描述:
符合ini规则的文件内容(考生不需要考虑非法输入问题)，例如:
;test case
[section1]
key1 = value1
[section2]
key1 = value1
说明:
1. 以分号“;”起始部分为注释，可能独占一行注释一个段落；也可能出现在行尾，注释某一行
2. section名称已中括号包裹
3. 每个section内有1个或者多个key/value对
4. key和value以等号“=”分割，等号前后允许有空格
输出描述:
通过输入解析出所有配置，每个配置应该包含三个部分：section、key、value；要求按照如下规则输出所有字段:
输出所有解析后的配置，三个字段分别用大括号“{}”包裹，其中不同section按照section名称排序，同一section内按照key值排序(排序规则同一使用ASCII码表从小到大排列)
{section}{key}{value}
示例1
输入
;test case
[section1]
key2=value2
key1=value1
输出
{section1}{key1}{value1}
{section1}{key2}{value2}
备注:
INI文件由节、键、值组成。
节
[section]
参数（键=值）
name=value
注解
注解使用分号表示（;）。在分号后面的文字，直到该行结尾都全部为注解。


我自己附加的一道题：
输入一个正整数数组，把数组里所有数字拼接起来排成一个数，打印能拼接出的所有数字中最小的一个。例如输入数组{3，32，321}，则打印出这三个数字能排成的最小数字为321323。


//其中最重要的就是比较策略：

//排序规则如下：
 * 若ab > ba 则 a > b，
 * 若ab < ba 则 a < b，
 * 若ab = ba 则 a = b；

//* 比如 "3" < "31"但是 "331" > "313"，所以要将二者拼接起来进行比较

