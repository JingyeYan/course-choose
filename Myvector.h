#ifndef MYVECTOR_H
#define MYVECTOR_H

#include<iostream>
#include<string>

using namespace std;

template<typename value_type>class MyVector {
public:
	typedef  unsigned size_type;
private:
	value_type *m_arr;
	size_type m_size;                   //记录容器元素个数
	size_type m_max;                     //总内存
public:

	MyVector();                              //默认构造函数
	~MyVector() { delete[]m_arr; };                          //析构函数
	MyVector(const MyVector&vec);              //拷贝构造函数
	MyVector(size_type range, const value_type& val);    //第一个参数为容器大小，第二个参数为初始化的值
	value_type& operator[](size_type pos);   //重载下标运算符
	const value_type& operator[](size_type pos)const;
	MyVector&operator=(const MyVector&vec);      //重载赋值运算符
	value_type& at(size_type pos);               //at函数
	const value_type& at(size_type pos)const;
	value_type& front();                         //返回容器第一个元素
	const value_type&front()const;
	value_type& back();                          //返回容器最后一个元素
	const value_type&back()const;
	size_type size()const;                       //返回容器元素个数
	void resize(size_type n, value_type val = value_type());   //重新定义容器大小，并对新增加的元素赋初始值
	bool empty() const;                                //判断容器元素是否为空
	void push_back(const value_type& val);             //向容器中增加一个元素
	void pop_back();                                   //移除容器中的最后一个元素
	void insert(const value_type&val, size_type pos);  //向容器中插入一个元素
	void erase(size_type pos);                         //删除一个元素
	void clear();                                      //清除容器中所有元素  
	void sort();                                       //将容器中元素按从小到大排序
	size_type binarySearch(const value_type&val)const;                         //二分查找
	void show();                                      //输出所有元素
private:
	void quickSort(int, int);                         //快速排序
};






template<typename value_type>
MyVector<value_type>::MyVector() :m_size(0), m_max(1)
{
	m_arr = new value_type[m_max];
}



template<typename value_type>
MyVector<value_type>::MyVector(const MyVector&vec) :m_size(vec.m_size), m_max(vec.m_max)
{
	m_arr = new value_type[m_max];
	for (int i = 0;i < m_size;i++) {
		m_arr[i] = vec.m_arr[i];
	}
}



template<typename value_type>
MyVector<value_type>::MyVector(size_type range, const value_type& val) :m_size(range), m_max(range)
{
	if (range < 0) throw;
	m_arr = new value_type[m_size];
	for (int i = 0;i < m_size;i++) {
		m_arr[i] = val;
	}
}

template<typename value_type>
value_type& MyVector<value_type>::operator[](size_type pos)
{
	if (pos >= m_size || pos<0) throw;
	return m_arr[pos];
}

template<typename value_type>
const value_type& MyVector<value_type>::operator[](size_type pos)const
{
	if (pos >= m_size || pos<0) throw;
	else return m_arr[pos];
}



template<typename value_type>
MyVector<value_type>&MyVector<value_type>::operator=(const MyVector&vec)
{
	if (this == &vec) return *this;
	if (m_arr != NULL) delete[]m_arr;
	m_max = vec.m_max;
	m_size = vec.m_size;
	m_arr = new value_type[m_max];
	for (int i = 0;i < m_size;i++) {
		m_arr[i] = vec.m_arr[i];
	}
	return *this;
}


template<typename value_type>
value_type& MyVector<value_type>::at(size_type pos)
{
	if (pos >= m_size || pos<0) throw;
	else return m_arr[pos];
}


template<typename value_type>
const value_type& MyVector<value_type>::at(size_type pos)const
{
	if (pos >= m_size || pos<0) throw;
	else return m_arr[pos];
}


template<typename value_type>
value_type&MyVector<value_type>::front()
{
	return m_arr[0];
}


template<typename value_type>
const value_type&MyVector<value_type>::front()const
{
	return m_arr[0];
}


template<typename value_type>
value_type&MyVector<value_type>::back()
{
	return m_arr[m_size - 1];
}


template<typename value_type>
const value_type&MyVector<value_type>::back()const
{
	return m_arr[m_size - 1];
}


template<typename value_type>
unsigned  MyVector<value_type>::size() const
{
	return m_size;
}



template<typename value_type>
bool MyVector<value_type>::empty() const
{
	if (m_size > 0) return false;
	if (m_size == 0) return true;
}


template<typename value_type>
void MyVector<value_type>::push_back(const value_type& val)
{
	if (m_size < m_max)
	{
		m_arr[m_size] = val;
	}
	else
	{
		m_max = m_max * 2;
		value_type * temp = new value_type[m_max];
		for (int i = 0;i < m_size;i++) {
			temp[i] = m_arr[i];
		}
		temp[m_size] = val;
		delete[]m_arr;
		m_arr = temp;
	}
	++m_size;
}


template<typename value_type>
void MyVector<value_type>::pop_back()
{
	m_size--;

}

template<typename value_type>
void MyVector<value_type>::insert(const value_type&val, size_type pos)
{
	if (pos < 0 || pos>m_size) throw;
	m_max = m_max * 2;
	value_type *temp = new value_type[m_max];
	for (int i = 0;i < pos;i++) {
		temp[i] = m_arr[i];
	}
	temp[pos] = val;
	for (int j = pos + 1;j < m_size + 1;j++) {
		temp[j] = m_arr[j - 1];
	}
	delete[]m_arr;
	m_arr = temp;
	m_size++;
}

template<typename value_type>
void MyVector<value_type>::erase(size_type pos) {
	if (pos < 0 || pos >= m_size) throw;
	for (int i = pos; i<m_size; ++i)
		m_arr[i] = m_arr[i + 1];
	m_arr[m_size - 1] = value_type();
	--m_size;
}

template<typename value_type>
void MyVector<value_type>::clear() {
	delete[]m_arr;
	m_arr = new value_type[1];
	m_size = 0;
	m_max = 1;
}

template<typename value_type>
void MyVector<value_type>::sort() {
	value_type temp;
	int low, high, mid, i, j;
	for (i = 1;i < m_size;i++) {
		temp = m_arr[i];
		low = 0;
		high = i - 1;
		while (low <= high) {
			mid = (low + high) / 2;
			if (temp < m_arr[mid])  high = mid - 1;
			else  low = mid + 1;
		}
		for (j = i - 1;j >= low;j--) m_arr[j + 1] = m_arr[j];
		m_arr[low] = temp;
	}
}


template <typename value_type>
unsigned MyVector<value_type>::binarySearch(const value_type&val)const {
	sort();
	int high = m_size - 1, low = 0, mid = -1;  // m_size-1 当前有序表最大下标
	while (low <= high) {
		mid = (low + high) / 2;
		if (val<m_arr[mid])  high = mid - 1;  //左缩查找区间
		else if (m_arr[mid]<val) low = mid + 1; // 右缩查找区间	     	else return mid;
	}
	if (mid != -1 && m_arr[mid] != val) mid = -1;
	return mid;
}


template<typename value_type>
void MyVector<value_type>::show() {
	for (int i = 0;i < m_size;i++) {
		cout << m_arr[i] << '\t';
	}

}

template<typename value_type>
void MyVector<value_type>::quickSort(int low, int high) {
	if (low >= high)
	{
		return;
	}
	int first = low;
	int last = high;
	int key = m_arr[first];             /*用字表的第一个记录作为枢轴*/
	while (first < last)
	{
		while (first < last && m_arr[last] >= key)
		{
			--last;
		}
		m_arr[first] = m_arr[last];               /*将比第一个小的移到低端*/

		while (first < last && m_arr[first] <= key)
		{
			++first;
		}
		m_arr[last] = m_arr[first];            /*将比第一个大的移到高端*/
	}
	m_arr[first] = key;                       /*枢轴记录到位*/
	quickSort(low, first - 1);
	quickSort(first + 1, high);
}




template<typename Vector, typename DateTape>

void test(Vector&v, const DateTape& val) {

	v.show();
	cout << endl;

	cout << v.at(0) << endl;

	v.push_back(val); v.show();
	cout << endl;

	v.sort(); v.show();
	cout << endl;

	v.insert(val, 0); v.show();
	cout << endl;
}



#endif
