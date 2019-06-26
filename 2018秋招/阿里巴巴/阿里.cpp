#include <bits/stdc++.h>
#include <io.h>
using namespace std;

//void listFiles(const char * dir)
//{
//    intptr_t handle;
//    _finddata_t findData;
//
//    handle = _findfirst(dir, &findData);    // ����Ŀ¼�еĵ�һ���ļ�
//    if (handle == -1) {
//        cout << "Failed to find first file!\n";
//        return;
//    }
//
//    do {
//        if (findData.attrib & _A_SUBDIR
//                && strcmp(findData.name, ".") == 0
//                && strcmp(findData.name, "..") == 0
//           )    // �Ƿ�����Ŀ¼���Ҳ�Ϊ"."��".."
//            cout << findData.name << "\t<dir>\n";
//        else
//            cout << findData.name << "\t" << findData.size << endl;
//    } while (_findnext(handle, &findData) == 0);    // ����Ŀ¼�е���һ���ļ�
//
//    cout << "Done!\n";
//    _findclose(handle);    // �ر��������
//}

void listFiles(const char * dir)
{
    char dirNew[200];
    strcpy(dirNew, dir);
    strcat(dirNew, "\\*.*");    // ��Ŀ¼�������"\\*.*"���е�һ������

    intptr_t handle;
    _finddata_t findData;

    handle = _findfirst(dirNew, &findData);
    if (handle == -1)        // ����Ƿ�ɹ�
        return;

    do
    {
        if (findData.attrib & _A_SUBDIR)
        {
            if (strcmp(findData.name, ".") == 0 || strcmp(findData.name, "..") == 0)
                continue;

            cout << findData.name << "\t<dir>\n";

            // ��Ŀ¼�������"\\"����������Ŀ¼��������һ������
            strcpy(dirNew, dir);
            strcat(dirNew, "\\");
            strcat(dirNew, findData.name);

            listFiles(dirNew);
        }
        else
            cout << findData.name << "\t" << findData.size << " bytes.\n";
    } while (_findnext(handle, &findData) == 0);

    _findclose(handle);    // �ر��������
}

int main()
{
    FILE * pFile;
    long long file_size;
    pFile = fopen ("���������㷨.md", "rb");
    if (pFile == NULL) perror ("Error opening file");
    else {
        fseek (pFile, 0, SEEK_END);   ///���ļ�ָ���ƶ��ļ���β
        file_size = ftell (pFile); ///�����ǰ�ļ�ָ������ļ���ʼ���ֽ���
        fclose (pFile);
        printf ("Size of ���������㷨.md: %ld bytes.\n", file_size);
    }

    char dir[200];
    cout << "Enter a directory (ends with \'\\\'): ";
    cin.getline(dir, 200);

    //strcat(dir, "*.*");        // ��Ҫ������Ŀ¼�����ͨ���
    listFiles(dir);
    return 0;
}
