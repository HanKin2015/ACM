/*
1、打表找规律
2、按位找规律
*/
#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
LL GCD(LL a, LL b)
{
    return b ? GCD(b, a % b) : a;
}
LL LCM(LL a, LL b)
{
    a = a / GCD(a, b) * b;
    return a;
}

int main()
{
    int n;
    while (cin >> n) {
        LL a = 1, b = 1;
        for (int i = 1; i <= n; i++) {
            b = LCM(b, i);
        }
        for (int i = n + 1; ; i++) {
            a = LCM(a, i);
            b = LCM(b, i);
            if (a == b) {
                cout << i << endl;
                break;
            }
        }
    }
    return 0;
}

import java.util.*;
public class Main{

	public static void main(String[] args){
    	 Scanner sc = new Scanner(System.in);
    	 int k = sc.nextInt();
    	 String A = sc.nextLine();
    	 String B = sc.nextLine();

    	 //方法1：替换法
    	 int ans = 0;
    	 for (int i = 0; i < A.length() - k; i++) {
    	     String s = A.substring(i, k);
    	     String tmp = B.replace(s, "");
    	     ans += B.length() - tmp.length();
    	 }
         System.out.println(ans);
	}
}
