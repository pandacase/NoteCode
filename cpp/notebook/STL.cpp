#include<iostream>
#include<set>
#include<map>
#include<queue>
using namespace std;

void set_test();
void map_pair_test();

// string.find() 返回的是int下标


///////////////一些tips//////////////////////////////////////////////////
//cbegin()和cend()返回的是const iterator
//rbegin()和rend()是逆序iterator

int main(){
    set_test();
    map_pair_test();

    system("pause");
    return 0;
}


void set_test(){
    //set内部通过红黑树实现
    //会自动排序        // unordered_set 则不会自动排序
    //元素值唯一        // multiset 元素可以重复
    //查找时间复杂度为O(logn)
    set<int> st;
    set<int>::iterator it;
    int arr[10] = {9,8,7,6,5,4,3,2,1,0};
    
    //插入和删除
    st.insert(arr,arr+10);
    it = st.begin();
    st.erase(it);

    //查找元素
    cout << "查找元素9:" << *st.find(9) << endl;
    cout << "元素9出现次数:" << st.count(9) << endl;

    cout << "查找>=1的第一个元素:" << *st.lower_bound(1) << endl;
    cout << "查找> 1的第一个元素:" << *st.upper_bound(1) << endl;

    //遍历
    for(auto it = st.begin(); it != st.end(); it++){
        cout << *it << " ";
    } cout << endl;
}

void map_pair_test(){
    //map通过红黑树实现，键值对key-value，提供一对一的hash
    //不能修改key的值，可以修改value的值
    //查找时间复杂度为O(logn)
    map<int,string> mp;
    map<int,string>::iterator it;

    //插入
    mp.insert(pair<int,string>(0,"student_zero"));
    //map可以直接使用下标来读取一个元素。且如果是未出现过的下标，会自动新建一个pair
    //这种方法还有个好处，遇到重复key时会进行覆盖
    mp[1] = "student_one"; 

    //查找 如果找不到则返回尾迭代器
    cout << mp.find(1)->first << " : " << mp.find(1)->second << endl;

    //删除
    it = mp.find(1);
    mp.erase(it); //当然了，也可以范围删除
    it = mp.find(1);
    if(it != mp.end()) cout << "find it!" << endl;
    else cout << "not find!" << endl;
}