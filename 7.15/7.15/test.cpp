#include "test.h"


void Test1()
{
    tao::vector<int> v;
	v.push_back(1);
	v.push_back(2);
	v.push_back(3);
	v.push_back(4);
	for (auto e : v)
	{
		cout << e<<" ";
	}
	cout << endl;
	/*for (int i = 0; i < v.size(); i++)
	{
		cout << ++v[i]<<" ";
	}*/
	tao::vector<int>::iterator it = v.begin()+3;
	it=v.insert(it, 800);
	//这里的it迭代器失效了，访问的不是第三个位置了。
	*it += 1000;
	for (auto e : v)
	{
		cout << e << " ";
	}
	cout << endl;
	/*v.erase(v.begin()+4);
	for (auto e : v)
	{
		cout << e << " ";
	}*/
	//删除v里的全部偶数
	//for (auto e : v)
	//{
	//	if (*it % 2 == 0)
	//	{
	//		v.erase(it);//这里erase完，it迭代器就失效了，就无法再访问其内容了
	//	}
	//	else
	//	{
	//		++it;//迭代器已经失效了，不能再对这个迭代器操作了。
	//	}
	//}
	//for (auto e : v)
	//{
	//	if (e % 2 == 0)
	//	{
	//		it=v.erase(it);//这里erase完，it迭代器就失效了，就无法再访问其内容了
	//		//但一定要访问下一个元素该怎么办呢？库里提供方法：将删除元素的下一个位置的迭代器传回去，这样迭代器就可以继续使用了
	//	}
	//	else
	//	{
	//		++it;//迭代器已经失效了，不能再对这个迭代器操作了。
	//	}
	//}
	
}
void Test2()
{
	tao::vector<int> v;
	v.push_back(1);
	v.push_back(2);
	v.push_back(3);
	v.push_back(4);
	v.push_back(4);
	v.push_back(4);
	v.push_back(4);
	v.push_back(6);
	for (auto e : v)
	{
		cout << e << " ";
	}
	cout << endl;
	tao::vector<int>::iterator it = v.begin();
	while (it != v.end())
	{
		if ((*it) % 2 == 0)
		{
			it = v.erase(it);
		}
		else
		{
			++it;
		}
	}
	for (auto e : v)
	{
		cout << e << " ";
	}
	cout << endl;
}
void Test3()
{
	int i = int();
	//加入模板后，内置类型升级了，int()这样代表这int类的构造函数默认是0
	int j = int(1);
	cout << i << j << endl;
	tao::vector<int> v;
	v.resize(10, 0);
	for (auto e : v)
	{
		cout << e << " ";
	}
	cout << endl;
	tao::vector<int> v1(v);
	for (auto e : v1)
	{
		cout << e << " ";
	}
	cout << endl;
	v1.resize(20, 1);
	v = v1;
	for (auto e : v)
	{
		cout << e << " ";
	}
}

int main()
{
	Test3();
}



