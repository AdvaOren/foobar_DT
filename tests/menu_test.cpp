#include "gtest/gtest.h"
#include "../src/Menu.cpp"
#include <vector>
#include <fstream>

using std::vector;
using std::string;

//This test check the function getInitParm() in the Menu class
TEST(GetInitParmTest, BasicTest) {
    std::ifstream ifs;
    ifs.open("../tests/test_menu_input.txt");
    if(!ifs.is_open())
        std::cout << "ERROR cant open file test_menu_input.txt";
    Menu menu1(ifs);
    vector<int> test1 {8,2,1};
    EXPECT_EQ(menu1.getInitParm(),test1);

    Menu menu2(ifs);
    vector<int> test2 {8,1};
    EXPECT_EQ(menu2.getInitParm(),test2);

    Menu menu3(ifs);
    vector<int> test3 {125,2};
    EXPECT_EQ(menu3.getInitParm(),test3);

    //in this test the file contain also illegal lines: "a" "fd" "\n" "5 1 a"
    Menu menu4(ifs);
    vector<int> test4 {9,1,2};
    EXPECT_EQ(menu4.getInitParm(),test4);

    Menu menu5(ifs);
    vector<int> test5 {8,1};
    EXPECT_EQ(menu5.getInitParm(),test5);

    Menu menu6(ifs);
    vector<int> test6 {8,2};
    EXPECT_EQ(menu6.getInitParm(),test6);

    Menu menu7(ifs);
    vector<int> test7 {8,1,2};
    EXPECT_EQ(menu7.getInitParm(),test7);

    Menu menu8(ifs);
    vector<int> test8 {8,1,2};
    EXPECT_EQ(menu7.getInitParm(),test8);
    ifs.close();
}

//This test check the function getNextTask() in the Menu class
TEST(GetTaskTest, BasicTest) {
    std::ifstream ifs;
    ifs.open("../tests/test_menu_input.txt");
    if (!ifs.is_open())
        std::cout << "ERROR cant open file test_menu_input.txt";
    Menu menu(ifs);
    EXPECT_EQ(menu.getNextTask(ifs),1);
    EXPECT_EQ(menu.getNextTask(ifs),1);
    EXPECT_EQ(menu.getNextTask(ifs),1);
    EXPECT_EQ(menu.getNextTask(ifs),2);
    EXPECT_EQ(menu.getNextTask(ifs),2);
    EXPECT_EQ(menu.getNextTask(ifs),2);
    ifs.close();
}

//This test check the function getURL() in the Menu class
TEST(GetURLTest, AdvanceTest) {
    std::ifstream ifs;
    ifs.open("../tests/test_menu_input_url.txt");
    if (!ifs.is_open())
        std::cout << "ERROR cant open file test_menu_input_url.txt";
    Menu menu(ifs);
    menu.getNextTask(ifs);
    EXPECT_EQ(menu.getURL(),"www.example.com");
    menu.getNextTask(ifs);
    EXPECT_EQ(menu.getURL(),"www.aaa,co.il");
    menu.getNextTask(ifs);
    EXPECT_EQ(menu.getURL(),"www.foo.il");
    menu.getNextTask(ifs);
    EXPECT_EQ(menu.getURL(),"www.todo.org");
    menu.getNextTask(ifs);
    EXPECT_EQ(menu.getURL(),"www.exaa mple.com1");
    menu.getNextTask(ifs);
    EXPECT_EQ(menu.getURL(),"aa");
    menu.getNextTask(ifs);
    EXPECT_EQ(menu.getURL(),"www.ad.");
    menu.getNextTask(ifs);
    EXPECT_EQ(menu.getURL(),"ww.example.com www.example.com");
    menu.getNextTask(ifs);
    EXPECT_EQ(menu.getURL(),"www.cl");
    menu.getNextTask(ifs);
    EXPECT_EQ(menu.getURL(),"ww.no.com");
    menu.getNextTask(ifs);
    EXPECT_EQ(menu.getURL(),"www.enough.com");
}
