#pragma once

#include <string.h>
//vector的模拟实现
#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <assert.h>
using namespace std;
namespace tao
{
	template <class T>//定义一个模板T
	class vector
	{
		
	public:
		typedef T* iterator;//将T* 重命名为iterator
		typedef const T* const_iterator;
		iterator begin()
		{
			return _start;
		}
		iterator end()
		{
			return _finish;
		}
		const_iterator begin()const
		{
			return _start;
		}
		const_iterator end()const
		{
			return _finish;
		}
		//成员函数
		vector()//空值构造
			: _start(nullptr)
			, _finish(nullptr)
			, _endstroage(nullptr)
		{}
		vector(const vector<T>& v)//深拷贝
			: _start(nullptr)
			, _finish(nullptr)
			, _endstroage(nullptr)
		{
			_start = new T[v.size()];
			memcpy(_start, v._start, sizeof(T) * v.size());
			_finish = _start+v.size();
			_endstroage = _start+v.capacity();
		}
		void swap(vector<T> v)
		{
			std::swap(_start , v._start);
			std::swap(_finish ,v._finish);
			std::swap(_endstroage ,v._endstroage);
		}
		vector<T>& operator=(vector<T> v)
		{
			swap(v);
			return *this;
		}
		~vector()
		{
			if (_start)
			{
				delete[] _start;
				_start = _finish = _endstroage = nullptr;
			}
		}
		void reserve(size_t n)
		{
			size_t sz = size();
			if (n > capacity())
			{
				T* temp = new T[n];//首先开空间
				if (_start != nullptr)
				{
					//将数据拷贝到temp去
					memcpy(temp, _start, sizeof(T) * sz);
					//删除原来空间
					delete[] _start;
				}
				//最后将空间赋值给_start
				_start = temp;
				_finish = _start + sz;
				//这里有一个问题，size()的计算是用_finish -start 而这里的start已经改变，而finish还没有改变
				//最后计算finish就变成空了，最终的问题在于start改变了，所有在之前要保留一份size()的数据
				_endstroage = _start + n;
			}
		}
		void push_back(const T& val)
		{
			//首先要考虑是否扩容
			if (_finish == _endstroage)
			{
				size_t newcapacity = (capacity() == 0 ? 4 : capacity() * 2);
				reserve(newcapacity);
			}
			*_finish = val;
			++_finish;

		 }
		size_t capacity() const
		{
			return _endstroage - _start;
		}
		size_t size() const
		{
			return _finish - _start;
		}
		T& operator[](size_t pos)
		{
			assert(pos <= size());
			return _start[pos];
		}
		const T& operator[](size_t pos) const
		{
			assert(pos <= size());
			return _start[pos];
		}
		iterator insert(iterator pos,const T &val)
		{
			assert(pos >= _start && pos <= _finish);
			//首先考虑扩容----这里有一个问题：迭代器失效
			//当迭代器扩容时，这里的pos迭代器就相当于失效了，因为原来的空间被释放了，pos也就变成野指针了。
			//需要将将pos迭代器恢复，需要更新pos的新位置。
			if (_finish == _endstroage)
			{
				size_t len = pos - _start;
				size_t newcapacity = (capacity() == 0 ? 4 : capacity() * 2);
				reserve(newcapacity);
				pos = _start + len;
			}
			//使用迭代器的好处就是可以避免string那样头插时，挪动数据，下标要小于0的问题，因为迭代器是一个地址，不可以为0的
			iterator end = _finish - 1;
			while (end >= pos)
			{
				*(end + 1) = *end;
				end--;
			}
			*pos = val;
			_finish++;
			//insert 中的扩容迭代器失效，外部迭代器的解决方法是使用返回值，将pos位置返回过去，再用迭代器接收，就可以对pos位置上的内容再访问了
			return pos;
			//指向新插入位置的迭代器
		}
		iterator erase(iterator pos)
		{
			assert(pos >= _start && pos <= _finish);

			iterator it = pos + 1;
			while (it != _finish)
			{
				*(it - 1) = *it;
				it++;
			}
			--_finish;
			return pos;
			//返回的是删除元素的下一个位置的迭代器
		}
		void pop_back()
		{
			erase(--end());
		}
		void resize(size_t n, const T& val=T())//这里的val可以给缺省值的，当给定时，使用给定值，不给定时使用缺省值，缺省值给的是T类型的构造函数
		{
			if (n < size())
			{
				_finish = _start + n;
			}
			else
			{
				reserve(n);//不用管原来的容量多少，reserve会判断是否需要扩容
				//填值
				while (_finish != n + _start)
				{
					*_finish = val;
					++_finish;
				}
			}
		}
	private:
       //成员变量
		iterator _start;//指向开头位置的迭代器
		iterator _finish;//指向真实数据的最后位置
		iterator _endstroage;//指向容量的的最后位置

	};

}