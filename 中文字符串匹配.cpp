include <iostream>
#include <string>
#include <algorithm>
using namespace std;
vector<int> stringToVecInt(const string &str)
{
    union {
        char c[2];
        int  i;
    } convert;

    // 段位清零
    convert.i = 0;

    vector<int> vec;

    for (unsigned i = 0; i < str.length(); i++) {
        // GBK编码首字符大于0x80
        if ((unsigned)str[i] > 0x80) {
            // 利用union进行转化，注意是大端序
            convert.c[1] = str[i];
            convert.c[0] = str[i + 1];
            vec.push_back(convert.i);
            i++;
        } else
            // 小于0x80，为ASCII编码，一个字节
            vec.push_back(str[i]);
    }
    return vec;
}
bool include(const string &str, const string &msg)
{
    auto sour = stringToVecInt(str);
    auto find = stringToVecInt(msg);
    return search(sour.begin(), sour.end(), find.begin(), find.end()) != sour.end();
}
bool inclus(const string &str,const string &msg)
{
    auto sour = stringToVecInt(str);
    auto find = stringToVecInt(msg);
    for(int i=0;i<sour.size();i++)
    {
      // cout<<sour[i]<<"<-->"<<find[i]<<endl;
       if(sour[i]==find[i]&&i==2)
        return true;
    }

    return false;
}
int main()
{
    int i,j;
    string city1[4]={"哈尔滨","长春","北京","上海"};
    string city2[5]={"哈尔滨","哈尔滨东","北京","北京东","上海虹桥"};
   // inclus("哈尔滨东","哈尔滨东");
    if(inclus("上海","上海东"))
        cout<<"ok"<<endl;
    else
        cout<<"default"<<endl;

    for(i=0;i<4;i++)
    {
        for(j=0;j<5;j++)
        {
            cout<<city1[i]<<" --> "<<city2[j]<<" "<<inclus(city1[i],city2[j])<<endl;
        }
    }

    return 0;
}
