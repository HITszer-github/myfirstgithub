#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
void printinf();
void inputdata();
void Select(vector<float> vec1);
int main()
{
    vector<float> vec;
    printinf();
    inputdata();
    Select(vec);
    



    system("pause");
    return 0;



}
void Select(vector<float> vec1)
{
    while (true)
    {
        printinf();
        int sel;
        switch (sel)
        {
        case 1:
            cout << "输入你想要存储的数据:data= " ;
            float data;
            cin >> data;
            vec1.push_back(data);
            break;
            /*
                cout << "               1：储存数据" << endl;
    cout << "               2：查找数据" << endl;
    cout << "               3：删除数据" << endl;
    cout << "               4：升序打印" << endl;
    cout << "               5：降序打印" << endl;
    cout << "               6：数据最大值" << endl;
    cout << "               7：数据最小值" << endl;
    cout << "               8：退出程序" << endl;
    */
        case 2:
            cout << "输入你想要查找的数据:data= " ;
            float data;
            cin >> data;
            /*用二分法查找数据*/
            int left = 0;
            int right = vec1.capacity()-1;
            int mid = (left+right)/2;
            while (true)
            {
                 if(data<=vec1.at(mid))
            {
                left = mid;
            }
            else if(data>=vec1.at(mid))
            {
                right = mid;
            }
            else if(left>right)
            {
                cout << "没找到该数据" << endl;
                break;
            }
            else
            {
                cout << "没找到该数据" << endl;
            }
            }
            
            
        
            break;
        case 3:
            cout << "输入你想要存储的数据:data= " ;
            int data;
            cin >> data;
            vec1.push_back(data);
            break;
        case 4:
            sort(vec1.begin(),vec1.end()); //默认升序
            break;
        
        case 5:
            sort(vec1.rbegin(),vec1.rend()); //降序
            break;


        case 6:
            max_element(vec1.begin(),vec1.end());
            break;

        case 7:
            min_element(vec1.begin(),vec1.end());
            break;

        case 8:
            break;

        default:
            break;
        }
    }
    
}
void inputdata()
{
    char choose;
    while(true)
    {
        int n;
        cin >> n;
        cout << "数据插入成功" << endl;
        cout <<"是否继续插入数据？是=Y or y，否=其它" << endl;
        cin >> choose;
        if (choose!='Y' && choose != 'y'){break;}
    }
}
void printinf()
{
    cout << "******************************" << endl;
    cout << "软件功能：测试版数据存储          " << endl;
    cout << "创建时间：2021/1/1/21:13" << endl;
    cout << "版本信息：1.0" << endl;
    cout << "版权所有：HITszer@mycs" << endl;
    cout << "               1：储存数据" << endl;
    cout << "               2：查找数据" << endl;
    cout << "               3：删除数据" << endl;
    cout << "               4：升序打印" << endl;
    cout << "               5：降序打印" << endl;
    cout << "               6：数据最大值" << endl;
    cout << "               7：数据最小值" << endl;
    cout << "               8：退出程序" << endl;
    cout << "******************************" << endl;
}
