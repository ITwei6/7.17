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
	//�����it������ʧЧ�ˣ����ʵĲ��ǵ�����λ���ˡ�
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
	//ɾ��v���ȫ��ż��
	//for (auto e : v)
	//{
	//	if (*it % 2 == 0)
	//	{
	//		v.erase(it);//����erase�꣬it��������ʧЧ�ˣ����޷��ٷ�����������
	//	}
	//	else
	//	{
	//		++it;//�������Ѿ�ʧЧ�ˣ������ٶ���������������ˡ�
	//	}
	//}
	//for (auto e : v)
	//{
	//	if (e % 2 == 0)
	//	{
	//		it=v.erase(it);//����erase�꣬it��������ʧЧ�ˣ����޷��ٷ�����������
	//		//��һ��Ҫ������һ��Ԫ�ظ���ô���أ������ṩ��������ɾ��Ԫ�ص���һ��λ�õĵ���������ȥ�������������Ϳ��Լ���ʹ����
	//	}
	//	else
	//	{
	//		++it;//�������Ѿ�ʧЧ�ˣ������ٶ���������������ˡ�
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
	//����ģ����������������ˣ�int()����������int��Ĺ��캯��Ĭ����0
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



