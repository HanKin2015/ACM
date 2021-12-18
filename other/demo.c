#include "json.h"
#include "xtest.h"
#include <stdio.h>

//  完成使用场景的测试
TEST(test, scene)
{
    JSON *json = json_new(JSON_OBJ);
    ASSERT_TRUE(json != NULL);
    JSON *basic = json_new(JSON_OBJ);
    ASSERT_TRUE(basic != NULL);

    EXPECT_EQ(0, json_obj_set_value(json, "basic", basic));

    EXPECT_EQ(0, json_obj_set_value(basic, "enable", json_new_bool(TRUE)));
    EXPECT_EQ(TRUE, json_obj_get_bool(basic, "enable"));

    EXPECT_EQ(0, json_obj_set_value(basic, "port", json_new_num(389)));
    EXPECT_EQ(389, json_obj_get_num(basic, "port", 0));
//...
    EXPECT_EQ(0, json_obj_set_value(basic, "ip", json_new_str("200.200.3.61")));
    const char *ip = json_obj_get_str(basic, "ip", NULL);
    ASSERT_STRCASEEQ("200.200.3.61", ip);

    json_free(json);
}

//  测试键值对存在的情况
TEST(json_obj_get_str, exist)
{
    JSON *json = json_new(JSON_OBJ);
    ASSERT_TRUE(json != NULL);

    EXPECT_EQ(0, json_obj_set_value(json, "ip", json_new_str("200.200.3.61")));
    const char *ip = json_obj_get_str(json, "ip", NULL);
    ASSERT_TRUE(ip != NULL);
    ASSERT_STRCASEEQ("200.200.3.61", ip);

    json_free(json);
}

//  测试键值对不存在的情况
TEST(json_obj_get_str, notexist)
{
    JSON *json = json_new(JSON_OBJ);
    ASSERT_TRUE(json != NULL);

    EXPECT_EQ(0, json_obj_set_value(json, "ip", json_new_str("200.200.3.61")));
    const char *ip = json_obj_get_str(json, "ip2", NULL);
    ASSERT_TRUE(ip == NULL);

    ip = json_obj_get_str(json, "ip3", "default");
    ASSERT_TRUE(ip != NULL);
    ASSERT_STRCASEEQ("default", ip);

    json_free(json);
}

#if 0
int main(int argc, char **argv)
{
	return xtest_start_test(argc, argv);
}
#endif

#if 1
//---------------------------------------------------------------------------
//  方案1
//---------------------------------------------------------------------------


int main(int argc, char *argv[])
{
    int ret = 0;
    JSON *json = json_new(JSON_OBJ);
    if (!json)
        goto failed_;
    JSON *basic = json_new(JSON_OBJ);
    if (!json) {
        json_free(basic);
        goto failed_;
    }

    json_obj_set_value(json, "basic", basic);
    json_obj_set_value(basic, "enable", json_new_bool(TRUE));
    ret = json_obj_set_value(basic, "ip", json_new_str("200.200.3.61"));
    if (ret != 0)
        goto failed_;

    json_obj_set_value(basic, "port", json_new_num(389));
    json_obj_set_value(basic, "port", json_new_num(10));
    ret = json_obj_set_value(basic, "ip", json_new_str("aaa"));
    json_obj_set_value(basic, "port", json_new_num(-1));
    json_obj_set_value(basic, "port", json_new_num(133333333333));
    json_arr_add_str(basic, "dns", json_new_str("200.200.0.1"));
    json_arr_add_str(basic, "dns", json_new_str("200.0.0.254"));

    JSON *basic2 = json_new(JSON_OBJ);
    json_obj_add_value(json, "basic", basic2);
    
    

    const char *ip = json_obj_get_str(basic, "ip", NULL);
    if (!ip)
        goto failed_;

    
    return 0;
failed_:
    json_free(json);
    return 1;
}
#endif


#if 0
//---------------------------------------------------------------------------
//  方案2
//---------------------------------------------------------------------------

int main()
{
    JSON *json = json_new(JSON_OBJ);

    json_eval(json, "basic = {}");
    json_eval(json, "basic.ip = \"200.200.3.61\"");
    json_eval(json, "basic.enable = true");
    json_eval(json, "basic.port = 389");
    json_eval(json, "basic.timeout = 10");
    json_eval(json, "basic.dns[0] = \"200.200.0.1\"");
    json_eval(json, "basic.dns[1] = \"200.0.0.254\"");

...
    JSON *val = json_get(json, "basic.port");
    int port = json_get_int(json, "basic.port");
    bool enable = json_get_bol(json, "basic.enable");
    const char *ip = json_get_str(json, "basic.ip");

...
    json_free(json);
    return 0;
}


//---------------------------------------------------------------------------
//  方案3
//---------------------------------------------------------------------------

int main()
{
    JSON *json = json_new(JSON_OBJ);

    json_set(json, "basic", json_new(JSON_OBJ));
    json_set(json, "basic.ip", json_new_str("200.200.3.61"));
    json_set(json, "basic.enable", json_new_bol(true));
    json_set(json, "basic.port", json_new_int(389));
    json_set(json, "basic.timeout", json_new_int(10));
    json_set(json, "basic.dns[0]", json_new_str("200.200.0.1"));
    json_set(json, "basic.dns[1]", json_new_str("200.0.0.254"));

    JSON *val = json_get(json, "basic.port");
    int port = json_get_int(json, "basic.port");
    bool enable = json_get_bol(json, "basic.enable");
    const char *ip = json_get_str(json, "basic.ip");

...
    json_free(json);
    return 0;
}
#endif
