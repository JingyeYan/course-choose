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
	size_type m_size;                   //��¼����Ԫ�ظ���
	size_type m_max;                     //���ڴ�
public:

	MyVector();                              //Ĭ�Ϲ��캯��
	~MyVector() { delete[]m_arr; };                          //��������
	MyVector(const MyVector&vec);              //�������캯��
	MyVector(size_type range, const value_type& val);    //��һ������Ϊ������С���ڶ�������Ϊ��ʼ����ֵ
	value_type& operator[](size_type pos);   //�����±������
	const value_type& operator[](size_type pos)const;
	MyVector&operator=(const MyVector&vec);      //���ظ�ֵ�����
	value_type& at(size_type pos);               //at����
	const value_type& at(size_type pos)const;
	value_type& front();                         //����������һ��Ԫ��
	const value_type&front()const;
	value_type& back();                          //�����������һ��Ԫ��
	const value_type&back()const;
	size_type size()const;                       //��������Ԫ�ظ���
	void resize(size_type n, value_type val = value_type());   //���¶���������С�����������ӵ�Ԫ�ظ���ʼֵ
	bool empty() const;                                //�ж�����Ԫ���Ƿ�Ϊ��
	void push_back(const value_type& val);             //������������һ��Ԫ��
	void pop_back();                                   //�Ƴ������е����һ��Ԫ��
	void insert(const value_type&val, size_type pos);  //�������в���һ��Ԫ��
	void erase(size_type pos);                         //ɾ��һ��Ԫ��
	void clear();                                      //�������������Ԫ��  
	void sort();                                       //��������Ԫ�ذ���С��������
	size_type binarySearch(const value_type&val)const;                         //���ֲ���
	void show();                                      //�������Ԫ��
private:
	void quickSort(int, int);                         //��������
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
	int high = m_size - 1, low = 0, mid = -1;  // m_size-1 ��ǰ���������±�
	while (low <= high) {
		mid = (low + high) / 2;
		if (val<m_arr[mid])  high = mid - 1;  //������������
		else if (m_arr[mid]<val) low = mid + 1; // ������������	     	else return mid;
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
	int key = m_arr[first];             /*���ֱ�ĵ�һ����¼��Ϊ����*/
	while (first < last)
	{
		while (first < last && m_arr[last] >= key)
		{
			--last;
		}
		m_arr[first] = m_arr[last];               /*���ȵ�һ��С���Ƶ��Ͷ�*/

		while (first < last && m_arr[first] <= key)
		{
			++first;
		}
		m_arr[last] = m_arr[first];            /*���ȵ�һ������Ƶ��߶�*/
	}
	m_arr[first] = key;                       /*�����¼��λ*/
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
