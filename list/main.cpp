#include <iostream>
#include "List.h"
using namespace std;

int main()
{
List<int> list1;
list1.push_front(100);
list1.push_front(200);
list1.push_front(300);
list1.push_back(777);
cout << list1.back() << endl; //777
list1.pop_back();
cout << list1.back() << endl; //100
cout << list1.front() << endl; //300
list1.pop_front();
cout << list1.front() << endl; //200
List<int> list2;
list2.push_back(616);
list2.push_front(515);
list2.push_front(313);
list2.push_back(777);
//Извежда 313 515 616 777
{   List<int>::Iterator it = list2.begin();
    cout<<*it<<" ";
    do{
    it++;
    cout<<*it<<" ";
    }while (it != list2.end());
    /*for (List<int>::Iterator it = list2.begin(); it != list2.end(); it++)
    {
    cout << *it << " ";
    }*/
    cout << endl;
}

List<string> list3;
list3.push_back("vidi");
list3.push_back("vici");
List<string>::Iterator iter = list3.begin();
list3.insert(iter, "Veni");

//Извежда Veni vidi vici
List<string>::Iterator it = list3.begin();
cout<<*it<<" ";
do{
it++;
cout<<*it<<" ";
}while (it != list3.end());

/*for (List<string>::Iterator it = list3.begin(); it != list3.end(); it++)
{
cout << *it << " ";
}*/
cout << endl;


List<string> list4;
list4.push_back("Divide");
list4.push_back("et");
list4.push_back("impera");


//Извежда Divide et impera
List<string>::Iterator iter1 = list4.begin();
cout<<*iter1<<" ";
do{
iter1++;
cout<<*iter1<<" ";
}while (iter1 != list4.end());
/*for (List<string>::Iterator it = list4.begin(); it != list4.end(); it++)
{
cout << *it << " ";
}*/
cout<<endl;

List<string>::Iterator mid = ++list4.begin();
list4.erase(mid);
//Извежда Divide impera
List<string>::Iterator iter12 = list4.begin();
cout<<*iter12<<" ";
do{
iter12++;
cout<<*iter12<<" ";
}while (iter12 != list4.end());
/*for (List<string>::Iterator it = list4.begin(); it != list4.end(); it++)
{
cout << *it << " ";
}*/
cout<<endl;
return 0;
}

/*int main()
{
    List<int> list2;
    list2.push_back(616);
    list2.push_front(515);
    list2.push_front(313);
    list2.push_back(777);

    List<int>::Iterator iter = list2.begin();
    iter++;
    cout<<*iter<<endl;
    list2.erase(iter);
    //Извежда 313 515 616 777
    for (List<int>::Iterator it = list2.begin(); it != list2.end(); it++)
    {
    cout << *it << " ";
    }
    cout << endl;
    List<int>::Iterator iter1 = list2.begin();
    list2.insert(iter1,34);
    for (List<int>::Iterator it = list2.begin(); it != list2.end(); it++)
    {
    cout << *it << " ";
    }
    cout << endl;
	return 0;
}*/
