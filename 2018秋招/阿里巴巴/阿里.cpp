#include <bits/stdc++.h>
#include <io.h>
using namespace std;

//void listFiles(const char * dir)
//{
//    intptr_t handle;
//    _finddata_t findData;
//
//    handle = _findfirst(dir, &findData);    // 查找目录中的第一个文件
//    if (handle == -1) {
//        cout << "Failed to find first file!\n";
//        return;
//    }
//
//    do {
//        if (findData.attrib & _A_SUBDIR
//                && strcmp(findData.name, ".") == 0
//                && strcmp(findData.name, "..") == 0
//           )    // 是否是子目录并且不为"."或".."
//            cout << findData.name << "\t<dir>\n";
//        else
//            cout << findData.name << "\t" << findData.size << endl;
//    } while (_findnext(handle, &findData) == 0);    // 查找目录中的下一个文件
//
//    cout << "Done!\n";
//    _findclose(handle);    // 关闭搜索句柄
//}

void listFiles(const char * dir)
{
    char dirNew[200];
    strcpy(dirNew, dir);
    strcat(dirNew, "\\*.*");    // 在目录后面加上"\\*.*"进行第一次搜索

    intptr_t handle;
    _finddata_t findData;

    handle = _findfirst(dirNew, &findData);
    if (handle == -1)        // 检查是否成功
        return;

    do
    {
        if (findData.attrib & _A_SUBDIR)
        {
            if (strcmp(findData.name, ".") == 0 || strcmp(findData.name, "..") == 0)
                continue;

            cout << findData.name << "\t<dir>\n";

            // 在目录后面加上"\\"和搜索到的目录名进行下一次搜索
            strcpy(dirNew, dir);
            strcat(dirNew, "\\");
            strcat(dirNew, findData.name);

            listFiles(dirNew);
        }
        else
            cout << findData.name << "\t" << findData.size << " bytes.\n";
    } while (_findnext(handle, &findData) == 0);

    _findclose(handle);    // 关闭搜索句柄
}

int main()
{
    FILE * pFile;
    long long file_size;
    pFile = fopen ("社区发现算法.md", "rb");
    if (pFile == NULL) perror ("Error opening file");
    else {
        fseek (pFile, 0, SEEK_END);   ///将文件指针移动文件结尾
        file_size = ftell (pFile); ///求出当前文件指针距离文件开始的字节数
        fclose (pFile);
        printf ("Size of 社区发现算法.md: %ld bytes.\n", file_size);
    }

    char dir[200];
    cout << "Enter a directory (ends with \'\\\'): ";
    cin.getline(dir, 200);

    //strcat(dir, "*.*");        // 在要遍历的目录后加上通配符
    listFiles(dir);
    return 0;
}
