#pragma once

#include <string.h>
//vector��ģ��ʵ��
#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <assert.h>
using namespace std;
namespace tao
{
	template <class T>//����һ��ģ��T
	class vector
	{
		
	public:
		typedef T* iterator;//��T* ������Ϊiterator
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
		//��Ա����
		vector()//��ֵ����
			: _start(nullptr)
			, _finish(nullptr)
			, _endstroage(nullptr)
		{}
		vector(const vector<T>& v)//���
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
				T* temp = new T[n];//���ȿ��ռ�
				if (_start != nullptr)
				{
					//�����ݿ�����tempȥ
					memcpy(temp, _start, sizeof(T) * sz);
					//ɾ��ԭ���ռ�
					delete[] _start;
				}
				//��󽫿ռ丳ֵ��_start
				_start = temp;
				_finish = _start + sz;
				//������һ�����⣬size()�ļ�������_finish -start �������start�Ѿ��ı䣬��finish��û�иı�
				//������finish�ͱ�ɿ��ˣ����յ���������start�ı��ˣ�������֮ǰҪ����һ��size()������
				_endstroage = _start + n;
			}
		}
		void push_back(const T& val)
		{
			//����Ҫ�����Ƿ�����
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
			//���ȿ�������----������һ�����⣺������ʧЧ
			//������������ʱ�������pos���������൱��ʧЧ�ˣ���Ϊԭ���Ŀռ䱻�ͷ��ˣ�posҲ�ͱ��Ұָ���ˡ�
			//��Ҫ����pos�������ָ�����Ҫ����pos����λ�á�
			if (_finish == _endstroage)
			{
				size_t len = pos - _start;
				size_t newcapacity = (capacity() == 0 ? 4 : capacity() * 2);
				reserve(newcapacity);
				pos = _start + len;
			}
			//ʹ�õ������ĺô����ǿ��Ա���string����ͷ��ʱ��Ų�����ݣ��±�ҪС��0�����⣬��Ϊ��������һ����ַ��������Ϊ0��
			iterator end = _finish - 1;
			while (end >= pos)
			{
				*(end + 1) = *end;
				end--;
			}
			*pos = val;
			_finish++;
			//insert �е����ݵ�����ʧЧ���ⲿ�������Ľ��������ʹ�÷���ֵ����posλ�÷��ع�ȥ�����õ��������գ��Ϳ��Զ�posλ���ϵ������ٷ�����
			return pos;
			//ָ���²���λ�õĵ�����
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
			//���ص���ɾ��Ԫ�ص���һ��λ�õĵ�����
		}
		void pop_back()
		{
			erase(--end());
		}
		void resize(size_t n, const T& val=T())//�����val���Ը�ȱʡֵ�ģ�������ʱ��ʹ�ø���ֵ��������ʱʹ��ȱʡֵ��ȱʡֵ������T���͵Ĺ��캯��
		{
			if (n < size())
			{
				_finish = _start + n;
			}
			else
			{
				reserve(n);//���ù�ԭ�����������٣�reserve���ж��Ƿ���Ҫ����
				//��ֵ
				while (_finish != n + _start)
				{
					*_finish = val;
					++_finish;
				}
			}
		}
	private:
       //��Ա����
		iterator _start;//ָ��ͷλ�õĵ�����
		iterator _finish;//ָ����ʵ���ݵ����λ��
		iterator _endstroage;//ָ�������ĵ����λ��

	};

}