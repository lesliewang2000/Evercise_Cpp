#include <iostream>
using namespace std;
#include <string>
#include <list>
#include <algorithm>


/*
将person自定义排序，person中属性有姓名、年龄、身高
要求：
1、按照年龄进行升序，若年龄相同按照身高进行降序
*/

//person模板类
template <class T1, class T2, class T3>
class Person
{
public:
    Person(T1 name, T2 age, T3 height)
    {
        this->m_name = name;
        this ->m_age = age;
        this ->m_height = height;
    }

public:
    T1 m_name;
    T2 m_age;
    T3 m_height;
};


template <class T1, class T2, class T3>
void CreaPerson(list <Person<T1, T2, T3>> &L)
{
    

    Person<T1, T2, T3> p1("zhang", 20, 171);
    Person<T1, T2, T3> p2("zhao",24,178);
    Person<T1, T2, T3> p3("sun",19,180);
    Person<T1, T2, T3> p4("zhou",30,165);
    Person<T1, T2, T3> p5("wu",19,178);

    L.push_back(p1);
    L.push_back(p2);
    L.push_back(p3);
    L.push_back(p4);
    L.push_back(p5);
}

template <class T1, class T2, class T3>

bool ComparePerson(Person<T1, T2, T3> &p1, Person<T1, T2, T3> &p2)
{
    if(p1.m_age == p2.m_age)
    {
        return p1.m_height > p2.m_height;
    }
    else
    {
        return p1.m_age <p2.m_age;
    }


}

int main()
{
    //1、创建person类

    //2、导入数据
    list <Person<string, int, int>> L1;

    CreaPerson(L1);

    //测试
    cout << "before line" << endl;
    for(list<Person<string, int, int>>::iterator lit = L1.begin(); lit != L1.end();lit++)
    {
        cout << "name: " << (*lit).m_name << " \tage: " << (*lit).m_age << " \theight: " << (*lit).m_height <<endl;
    }

    cout << "--------------------" << endl;
    //3、进行排序

    L1.sort(ComparePerson);
    
    for(list<Person<string, int, int>>::iterator lit = L1.begin(); lit != L1.end();lit++)
    {
        cout << "name: " << (*lit).m_name << " \tage: " << (*lit).m_age << " \theight: " << (*lit).m_height <<endl;
    }
    

    system("pause");

    return 0;
}