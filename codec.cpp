/*
1.这里有个坑，必须要读写文本 
2.自己打错字了，data打成了date
3.解决了重复读写的问题
主要是：
3.1 如果读取进那个容器的话，会不断将容器里的内容放进去，所以读取之前应该清空一次
3.2 在写数据的时候，最开始是直接写，但是同样的读取之后再写有会重复。如果不读取不会有。
为了解决这个问题，首先那就采用直接新写一个完整的文本，但是有可能你没有读取文本，所以会导致之前的删除
故在写数据的时候要读一次，可以保证在添加元素的时候是在原基础上添加的，然后也不采用后add的方式，直接创建一个新的


如果写文件用一个临时的也可以，但是写了之后再去打印排序不能立即生效，需要再读取一次文件
*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <time.h>
#include <Windows.h>
#include <string>
#include <fstream>//读写内容
using namespace std;
void printinf();
void writedata(vector<float>&vec);
void printdata(vector<float>vec);
void readdata(vector<float>&vec);
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
        case '0':
        readdata(vec1);
        break;
        case '1':
        char choose;
        readdata(vec1);
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
            cout << "读取数据中……" << endl;
        writedata(vec1);

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
    cout << "                   *       0：读取数据库数据     *" << endl;
    cout << "                   *       1：储存新数据         *" << endl;
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
void writedata(vector<float>&vec)
{
    fstream file;
    file.open("C:\\Users\\ASUS\\Documents\\VS code\\interator_data.txt");
    if(!file.is_open())
    {
        cout << "打开文件失败!" << endl;
        Sleep(2000);
        exit(-1);
    }
    string temp;
    for(vector<float>::iterator it=vec.begin();it!=vec.end();it++)
    {
        temp = to_string(*it);              //将数值转换为文本stirng类型
        file << temp << endl;
    }
    Sleep(1000);
    cout << "写入数据成功!" << endl;
    file.close();
}
void readdata(vector<float>&vec)
{
    vec.clear();
    ifstream file;
    file.open("C:\\Users\\ASUS\\Documents\\VS code\\interator_data.txt");
    if(!file.is_open())
    {
        cout << "打开文件失败!" << endl;
        Sleep(2000);
        exit(-1);
    }
    string data;
    while (!file.eof())
	{
		file >> data;
		vec.push_back(stof(data));
	}
    vec.pop_back();
    cout << "读取数据成功!" << endl;
    file.close();
}
