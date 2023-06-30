#include <iostream>
using namespace std;
#include <string>
#include <vector>
#include <deque>
#include <algorithm>

/*
案例需求
一场比赛有五名选手，由十名评委给其打分，去掉最低分和最高分，得到每名选手的平均分
*/

//选手类
template <class T1, class T2>
class Person
{

public:
    //1.选手类构造函数
    Person(T1 name, T2 score)
    {
        this->m_name = name;
        this->m_score = score;
    }

public:
    T1 m_name;
    T2 m_score;
};

//将选手姓名导入vector容器中
template <class T1, class T2>
void CreatePerson(vector<Person<T1, T2> > &v)
{   
    string nameArr[5] = {"zhang","zhao", "li", "wang", "tao"};

    for(int i = 0; i < 5;i++)
    {
        T1 name = " ";
        name += nameArr[i];

        T2 score = 0;

        Person<T1,T2> p (name, score);

        v.push_back(p);
    }


}

//将分数导入deque容器中
template <class T1, class T2>
void CresteScore(vector<Person<T1, T2> > &v)
{
    for(typename::vector<Person<T1, T2>>::iterator it = v.begin(); it !=v.end();it++)
    {
        deque<T2> d;

        for(int i=0;i<10;i++)
        {
            T2 score = rand()%41+60;
            d.push_back(score);
        }

        sort(d.begin(),d.end());

        d.pop_back();
        d.pop_front();

        T2 sum =0;

        for(typename::deque<T2>:: iterator dit = d.begin();dit !=d.end();dit++)
        {
            sum += *dit;
        }

        T2 avg = sum / d.size();

        it->m_score = avg;
    }

}


int main()
{
    //1.创建五名选手
    vector<Person<string, int>> v;
    CreatePerson(v);

    //2.创建十名评委的分数
    CresteScore(v);

    //3.求出每名选手的平均分
    //测试
    for(vector<Person<string, int>>::iterator it = v.begin();it != v.end();it++)
    {
        cout << "name: " << (*it).m_name << " score: " << (*it).m_score << endl;
    }

    system("pause");

    return 0;
}