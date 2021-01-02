#include <iostream>
#include <vector>
#include <algorithm>
#include <time.h>
#include <Windows.h>
using namespace std;
void printinf();
void printdata(vector<float>vec);
void deletedate(vector<float>&vec1);
void Select(vector<float> vec1);
int main()
{
    vector<float> vec;
    Select(vec);
    system("pause");
    return 0;
}
void Select(vector<float> vec1)
{
    while (true)
    {
        float data;
        printinf();
        char sel = '0';
        int left = 0;
        int right = vec1.capacity()-1;
        int mid;
        cin >> sel;
        switch (sel)
        {
        case '1':
        char choose;
        while(true)
            {
                cout << "输入你想要存储的数据:data= " ;
                cin >> data;
                vec1.push_back(data);
                cout << "数据插入成功" << endl;
                cout <<"是否继续插入数据？是=Y or y，否=其它" << endl;
                cin >> choose;
                if (choose!='Y' && choose != 'y'){break;}
            }
        printdata(vec1);

        break;
        case '2':
            cout << "输入你想要查找的数据:data= " ;
            cin >> data;
            /*用二分法查找数据*/
            sort(vec1.begin(),vec1.end()); //默认升序
            while (left < right)
            {
                mid = (left+right)/2;
                if(data < vec1.at(mid))
                {
                    right = mid;
                }
                else if(data==vec1.at(mid))
                {
                     cout << "找到该数据!" << endl;
                     cout << vec1.at(mid) << "的下标是" << mid << endl;
                     break;
                }
                else
                {
                   left = mid;
                }
            }
            break;
        case '3':
            deletedate(vec1);
            break;
        case '4':
            sort(vec1.begin(),vec1.end()); //默认升序
            printdata(vec1);
            break;
        case '5':
            sort(vec1.rbegin(),vec1.rend()); //降序
            printdata(vec1);
            break;
        case '6':
            cout << *(max_element(vec1.begin(),vec1.end())) << endl;
            break;
        case '7':
            cout << *(min_element(vec1.begin(),vec1.end()));
            break;
        case '8':
        cout<<"             欢迎下次使用,系统将在3秒内关闭！" << endl;
            cout << "                            3……" << endl;
            Sleep(1000);
            cout << "                            2……" << endl;
            Sleep(1000);
            cout << "                            1……" ;
            Sleep(1000);
            exit(0);
        default:
            break;
        }
    }
    
}
void printinf()
{
    cout << "                   *******************************" << endl;
    cout << "                   *软件功能：测试版数据存储     *" << endl;
    cout << "                   *创建时间：2021/1/1/21:13     *" << endl;
    cout << "                   *版本信息：1.0                *" << endl;
    cout << "                   *版权所有：HITszer@mycs       *" << endl;
    cout << "                   **---------------------------**"  <<endl;
    cout << "                   *       1：储存数据           *" << endl;
    cout << "                   *       2：查找数据           *" << endl;
    cout << "                   *       3：删除数据           *" << endl;
    cout << "                   *       4：升序打印           *" << endl;
    cout << "                   *       5：降序打印           *" << endl;
    cout << "                   *       6：数据最大值         *" << endl;
    cout << "                   *       7：数据最小值         *" << endl;
    cout << "                   *       8：退出程序           *" << endl;
    cout << "                   *******************************" << endl;
}
void printdata(vector<float>vec)
{
    vector<float>::iterator it;
    cout << endl;
    for(it = vec.begin();it!=vec.end();it++)
    {
        cout << *it << '\t';
    }
    cout << endl;
}
void deletedate(vector<float>&vec1)
{
            float data;
            cout << "输入你想要删除的数据:data= " ;
            cin >> data;
            for(vector<float>::iterator it=vec1.begin(); it!=vec1.end();)
            {
                if(*it == data)
                {
                    it = vec1.erase(it); //不能写成arr.erase(it);
                }
                else
                {
                 ++it;
                }
            }
            cout << "当前的数据为: ";
            printdata(vec1);
}
