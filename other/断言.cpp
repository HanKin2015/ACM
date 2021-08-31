#include <bits/stdc++.h>
#define error -1
using namespace std;

int read_file(char **str, const char *fname)
{
    FILE *fp;
    long len;
    long realsize;
    char *buf;

    fp = fopen(fname, "r");
    if (!fp) {
        fprintf(stderr, "open file [%s] failed, error: %d\n", fname, error);
        return -1;
    }
    fseek(fp, 0, SEEK_END);
    len = ftell(fp);
    if (len <= 0) {
        fclose(fp);
        fprintf(stderr, "ftell failed, error: %d\n", error);
        return -1;
    }
    fseek(fp, 0, SEEK_SET);
    buf = (char *)malloc(len + 1);
    if (!buf) {
        fclose(fp);
        fprintf(stderr, "malloc(%ld) failed\n", len + 1);
        return -1;
    }
    realsize = fread(buf, 1, len, fp);
    fclose(fp);

    buf[realsize] = '\0';
    *str = strdup(buf);
    assert(*str);
    free(buf);
    return 0;
}


void TestAssert()
{
	int a = 2, b = 4;
	int c =  a + b;
	assert(c == 6);  // 如果true无任何反应

	const char *str = ""
	"house:\n"
	"  family:\n"
	"    name: Doe\n"
	"    parents:\n"
	"      - John\n"
	"      - Jane\n"
	"    children:\n"
	"      - Paul\n"
	"      - Mark\n"
	"      - Simone\n"
	"  address:\n"
	"    number: 34\n"
	"    street: Main Street\n"
	"    city: Nowheretown\n"
	"    zipcode: 12345\n";
	cout << str << endl;
	return;
}

// 枚举json的六种可变类型
typedef enum json_e {
    JSON_NONE,
    JSON_BOL,
    JSON_STR,
    JSON_ARR,
    JSON_OBJ,
    JSON_NUM,
} json_e;

typedef unsigned int BOOL;
typedef unsigned int U32;
typedef struct value JSON;

struct arrayy {
    value **elems;      /* 想想: 这里如果定义为'value *elems'会怎样？ */
    U32 count;
};

struct keyvalue {
    char *key;
    value *val;
};

struct object {
    keyvalue *kvs;      //这是一个keyvalue的数组，可以通过realloc的方式扩充的动态数组
    U32 count;          //数组kvs中有几个键值对
};

struct value {
    json_e type;
    union {          
        double num;
        BOOL bol;
        char *str;
        arrayy arr;
        object obj;
    };
};

JSON *json_new(json_e type)
{
    JSON *json = (JSON *)calloc(1, sizeof(JSON));
    if (!json)
        return NULL;
    json->type = type;
    return json;
}

void json_free(JSON *json)
{
    //TODO:
    U32 i, j;
    assert(json);

    switch(json->type) {
        case JSON_ARR:
            //assert(json->arr.count == 0);
            for (i = 0; i < json->arr.count; ++i) {
                json_free(json->arr.elems[i]);
            }
            free(json->arr.elems);
            break;
        case JSON_OBJ:
            //assert(json->obj.count == 0 || json->obj.kvs);
            for (i = 0; i < json->obj.count; ++i) {
                //printf("\"%s\":\n", json->obj.kvs[i].key);
                for (j = 0; j < json->obj.kvs[i].val->arr.count; ++j) {
                    json_free(json->obj.kvs[i].val->arr.elems[j]);
                }
                free(json->obj.kvs[i].val->arr.elems);
                json->obj.kvs[i].val->arr.elems = NULL;

                free(json->obj.kvs[i].val);
                json->obj.kvs[i].val = NULL;    // 注意释放内存后置NULL
            }
            free(json->obj.kvs);
            break;
        default:
            break;
    }
    free(json);
    json = NULL;
    return;
}

int json_obj_set_value(JSON *json, const char *key, JSON *val)
{
    //TODO:
    U32 i;
    assert(json);
    if (json->type != JSON_OBJ)
        return -1;
    assert(json->obj.count == 0 || json->obj.kvs);

    keyvalue kv;  // 封装
    kv.key = strdup(key);  
    kv.val = val;

    //cout << "******  = " << json->obj.count << endl;

    for (i = 0; i < json->obj.count; ++i) {
        if (strcmp(json->obj.kvs[i].key, key) == 0) {
            json->obj.kvs[i] = kv;
            return 0;
        }
    }
    json->obj.kvs = (keyvalue *)realloc(json->obj.kvs, (json->obj.count + 1) * sizeof(keyvalue));
    if (!json->obj.kvs) {
        cout << "calloc failed!!!" << endl;
        return -1;
    }
    json->obj.kvs[json->obj.count] = kv;
    json->obj.count++;
    //cout << json->obj.count << endl;
    return 0;
}

JSON *json_new_num(double val)
{
    //TODO:
    JSON *json = json_new(JSON_NUM);
    if (!json) {
        return json;
    }
    json->num = val;
    return json;
}

U32 cnt = 0;
int json_display(const JSON *json)
{
    U32 i, j;

    assert(json);
    //printf("json type = %d\n", json->type);

    switch(json->type) {
        case JSON_NONE:
            printf("json none\n");
            break;
        case JSON_BOL:
            printf("%d", json->bol);
            break;
        case JSON_STR:
            printf("\"%s\"", json->str);
            break;
        case JSON_ARR:
            assert(json->arr.count != 0);
            printf("[");
            json_display(json->arr.elems[0]);
            for (i = 1; i < json->arr.count; ++i) {
                printf(",");
                json_display(json->arr.elems[i]);
            }
            printf("]");
            break;
        case JSON_OBJ:
            assert(json->obj.count == 0 || json->obj.kvs);
            if (json->obj.count > 1) printf("{");

            for (i = 0; i < json->obj.count; ++i) {
                if (i) printf(",");
                printf("\n");
                for (j = 0; j < cnt; j++) printf("\t");
                printf("\"%s\":", json->obj.kvs[i].key);
                cnt++;
                json_display(json->obj.kvs[i].val);
                cnt--;
            }

            if (json->obj.count > 1) printf("\n}\n");
            break;
        case JSON_NUM:
            printf("%.0lf", json->num);
            break;
    }
    return 0;
}

json_e json_type(const JSON *json)
{
    assert(json);
    return json ? json->type : JSON_NONE;
}

int json_arr_add_value(JSON *json, JSON *val)
{
    assert(json);
    assert(json_type(json) == JSON_ARR);

    if (!json->arr.count) {
        json->arr.elems = (value **)calloc(1, sizeof(value **));
        if (!json->arr.elems) {
            return 0;
        }
    }
    json->arr.elems = (value **)realloc(json->arr.elems, (json->arr.count + 1) * sizeof(value **));

    json->arr.elems[json->arr.count] = val;
    json->arr.count++;
    return 0;
}

// JSON数组添加
int json_arr_add_num(JSON *json, double val) 
{
    int ret = json_arr_add_value(json, json_new_num(val));
    return ret;
} 

double json_arr_get_num(const JSON *json, U32 idx, double def)
{
    assert(json);
    assert(json_type(json) == JSON_ARR);
    if (json->arr.count <= idx) {
        return def;
    }

    return json->arr.elems[idx]->num;
}

int json_obj_set_num(JSON *json, const char *key, double val)
{
    int ret = json_obj_set_value(json, key, json_new_num(val));
    return ret;
}

const JSON *json_get_element(const JSON *json, U32 idx)
{
    assert(json);
    assert(json->type == JSON_ARR);

    if (json->type != JSON_ARR)
        return NULL;
    if (idx >= json->arr.count)
        return NULL;
    return json->arr.elems[idx];
}

JSON *json_new_str(const char *str)
{
    JSON *json = json_new(JSON_STR);
    if (!json)
        return json;
    json->str = strdup(str);
    if (!json->str) {
        fprintf(stderr, "strdup(%s) failed", str);
        json_free(json);
        return NULL;
    }
    return json;
}


int json_arr_add_str(JSON *json, const char *val)
{
    int ret = json_arr_add_value(json, json_new_str(val));
    return ret;
}

#define error -1
int json_save(const JSON *json, const char *fname, U32 cnt = 0)
{
    FILE *fp;
    long len;
    long realsize;
    char *buf;

    fp = fopen(fname, "w");
    if (!fp) {
        fprintf(stderr, "open file [%s] failed, error: %d\n", fname, error);
        return -1;
    }

    U32 i, j;
    assert(json);

    switch(json->type) {
        case JSON_NONE:
            printf("json none\n");
            break;
        case JSON_BOL:
            printf("%s", json->bol ? "true" : "false");
            break;
        case JSON_STR:
            printf("%s", json->str);
            break;
        case JSON_ARR:
            assert(json->arr.count != 0);

            for (i = 0; i < json->arr.count; ++i) {
                printf("\n");
                for (j = 0; j < cnt; j++) printf("  ");
                printf("- ");
                json_save(json->arr.elems[i], fname);
            }
            break;
        case JSON_OBJ:
            assert(json->obj.count == 0 || json->obj.kvs);

            for (i = 0; i < json->obj.count; ++i) {
                printf("\n");
                for (j = 0; j < cnt; j++) printf("  ");
                printf("%s: ", json->obj.kvs[i].key);
                cnt++;
                json_save(json->obj.kvs[i].val, fname);
                cnt--;
            }
            printf("\n");
            break;
        case JSON_NUM:
            printf("%.0lf", json->num);
            break;
        default:
            break;
    }
    return 0;
}


void TestDisplay()
{
    JSON *json = json_new(JSON_OBJ);
    JSON *basic = json_new(JSON_OBJ);
    json_obj_set_value(json, "basic", basic);

    int ret = json_obj_set_value(basic, "maxcnt", json_new_num(133333333333));
    if (ret) {
        cout << "obj error!!" << endl;
    }
    cout << "ok" << endl;

    JSON *dns_arr1 = json_new(JSON_ARR);
    json_arr_add_num(dns_arr1, 27888);
    json_arr_add_num(dns_arr1, 1314);
    cout << "from array get num = " << json_arr_get_num(dns_arr1, 1, 999) << endl;
    ret = json_obj_set_value(basic, "dns", dns_arr1);
    if (ret) {
        cout << "arr error!!" << endl;
    }

    json_display(json);
    json_obj_set_num(basic, "maxcnt", 123456);
    cout << "\n\n------------------------------\n" << endl;
    json_display(json);

    const JSON *json_tmp = json_get_element(dns_arr1, 0);
    cout << json_tmp->num << endl;    //27888
    JSON *json_arr = json_new(JSON_ARR);
    json_arr_add_str(json_arr, "200.200.0.1");
    cout << '1' << endl;
    const JSON *json_tmp2 = json_new(JSON_OBJ);
    json_tmp2 = json_get_element(json_arr, 0);
    cout << json_tmp2->str << endl;   //200.200.0.1

    cout << "\n\n********************************\n\n";
    json_save(json, "data.txt");
    return;
}

int read_file2(string *str, const char *fname)
{
    FILE *fp;
    long len;
    long realsize;
    char *buf;

    fp = fopen(fname, "r");
    if (!fp) {
        fprintf(stderr, "open file [%s] failed, errno: %d\n", fname, error);
        return -1;
    }
    fseek(fp, 0, SEEK_END);
    len = ftell(fp);
    if (len <= 0) {
        fclose(fp);
        fprintf(stderr, "ftell failed, errno: %d\n", errno);
        return -1;
    }
    fseek(fp, 0, SEEK_SET);
    buf = (char *)malloc(len + 1);
    if (!buf) {
        fclose(fp);
        fprintf(stderr, "malloc(%ld) failed\n", len + 1);
        return -1;
    }
    realsize = fread(buf, 1, len, fp);
    fclose(fp);

    buf[realsize] = '\0';
    *str = buf;
    free(buf);
    return 0;
}

int main()
{
	//TestAssert();

    string s = "";
    read_file2(&s, "data.txt");
    printf("%s", s.data());
    cout << "ok" << endl;
    //cout << s << endl;
    cout << "\n\n2333333333333333333333333333333333\n\n" << endl;

	char *str = NULL;
	string fname = "data.txt";
	read_file(&str, fname.data());
	cout << str << endl;

    return 0;
    json_e t = JSON_STR;
    cout << t << endl;

    int *arr = (int *)calloc(2, sizeof(int));
    arr[0] = 1;
    arr[1] = 2;
    arr = (int *)realloc(arr, 3 * sizeof(int));
    arr[2] = 3;
    arr[3] = 4;
    cout << "array = " << arr[0] << endl;
    cout << "array = " << arr[1] << endl;
    cout << "array = " << arr[2] << endl;
    cout << "array = " << arr[3] << endl;

    TestDisplay();






    int **easy;
    int a = 4, b = 2, c = 9;
    //int *p = new int(3);  // 这就是一个普通长度为3的数组
    int **p = (int **)malloc(3 *sizeof(int **));
    p[0] = &a;
    p[1] = &b;
    p[2] = &c;
    easy = (int **)calloc(1, sizeof(int **));
    for (int i = 0; i < 3; i++) {
        cout << *p[i] << endl;
        easy = (int **)realloc(easy, (i + 1) * sizeof(int **));
        easy[i] = p[(i + 1) % 3];
    }
    for (int i = 0; i < 3; i++) {
        cout << *easy[i] << endl;
    }
	return 0;
}











