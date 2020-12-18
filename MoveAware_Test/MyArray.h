#pragma once
#include "stdafx.h"

template <typename T>
class MyArray//�����ƶ�����
{
public:  
    MyArray() : m_pData(nullptr), m_nSize(0) {}//ctor ���캯�� 
    MyArray(size_t nsize);//��������ʱ��ֱ�Ӹ������ٸ�Ԫ��  
    MyArray(size_t nsize, T obj); //���������ʱ��ֱ�Ӹ���Ԫ�صĸ�����Ԫ�صĳ�ʼֵ
    MyArray(const MyArray& obj); //copy ctor
    ~MyArray();//dtor

    T* getData() const { return m_pData; } //��ȡ�������ݵ�ָ��
    size_t getSize() const { return m_nSize; }//����������Ԫ�صĸ���
    bool empty() { return m_nSize == 0 ? true : false; } //�ж������Ƿ�Ϊ��
    T getAt(size_t i) const; //��ȡ�����е�N��Ԫ�ص�ֵ��ע�⣬���ﲻ�����ã���������ã�����Ҫ��[]������ 
    T& operator [](size_t i) const; //��ȡ�����е�N��Ԫ�� ������õ������õ���ʽ 
    bool operator<(MyArray<T>obj)const; //����С��
    MyArray& operator = (const MyArray& obj);//��ֵ����
    void Append(const T& elem);//��ĩβ����һ��Ԫ�� 
    void DeleteAll();//ɾ������Ԫ��
    bool reset(size_t nsize);//����������� 
    void reset(size_t nsize, T obj);//���ö������������������Ԫ�صĳ�ʼֵ

private:
    T* m_pData = nullptr;
    size_t m_nSize = 0;
};

template<typename T>
inline MyArray<T>::MyArray(size_t nsize)
{ 
    if (nsize > 0)
    {
        m_pData = new T[nsize]; m_nSize = nsize;
    }
}

template<typename T>
inline MyArray<T>::MyArray(size_t nsize, T obj)
{
    if (nsize > 0)
    {
        m_pData = new T[nsize];
        for (size_t i = 0; i < nsize; ++i) { m_pData[i] = obj; }
        m_nSize = nsize;
    }
}

template<typename T>
inline MyArray<T>::MyArray(const MyArray& obj)
{
    //�����µĿռ��������
    m_pData = new T[obj.getSize()];
    //����ԭ�����ݵ��µĿռ�
    memcpy(m_pData, obj.m_pData, sizeof(T) * obj.m_nSize);
    m_nSize = obj.m_nSize;
}

template<typename T>
inline MyArray<T>::~MyArray()
{
    if (m_pData)
    {
        delete[] m_pData;
        m_pData = nullptr;
        m_nSize = 0;
    }
}

template<typename T>
inline T MyArray<T>::getAt(size_t i) const
{
    if (m_pData != nullptr && i >= 0 && i < m_nSize)
    {
        return m_pData[i];
    }
}

template<typename T>
inline T& MyArray<T>::operator[](size_t i) const
{
    if (m_pData != nullptr && i >= 0 && i < m_nSize)
    {
        return m_pData[i];
    }
}

template<typename T>
bool MyArray<T>::operator<( MyArray<T> obj)const
{
    if (m_nSize < obj.getSize())//���ȸ�������Ԫ�ظ����ж�
        return true;
    else if (m_nSize == obj.getSize())//����Ԫ�ظ�����ȣ����αȽ�Ԫ�ش�С
    {
        for (int i = 0; i < m_nSize; i++)
        {
            if (m_pData[i] < obj[i])//�����ǰԪ�ظ�С
                return true;
            else if (m_pData[i] == obj[i])//Ԫ�����
                continue;//������һ�αȽ�
            else
                return false;//����ֱ���˳�
        }
    }
    return false;//��׽��Ŀ���Լ�ȫ��������
}

template<typename T>
inline MyArray<T>& MyArray<T>::operator=(const MyArray<T>& obj)
{
    if (m_pData == obj.m_pData) { return *this; }
    if (obj.m_pData == nullptr)
    {
        if (m_pData) { delete[] m_pData; m_pData = nullptr; m_nSize = 0; }
        return *this;
    }
    if (m_pData) {
        //���ԭ������
        delete[] m_pData; m_pData = nullptr;
    }
    //�����µĿռ��������
    m_pData = new T[obj.getSize()];
    //����ԭ�����ݵ��µĿռ�
    memcpy(m_pData, obj.m_pData, sizeof(T) * obj.m_nSize);
    m_nSize = obj.m_nSize;
    return *this;
}

template<typename T>
inline void MyArray<T>::Append(const T& elem)
{
    if (m_pData)
    {
        T* ptmp = new T[m_nSize + 1];
        for (size_t i = 0; i < m_nSize; i++)
        {
            ptmp[i] = m_pData[i];
        }
        delete[] m_pData;
        m_pData = ptmp;
    }
    else
    {
        m_pData = new T[1];
    }
    m_pData[m_nSize] = elem;
    ++m_nSize;
}

template<typename T>
inline void MyArray<T>::DeleteAll()
{
    if (m_pData)
    {
        delete[] m_pData;
        m_pData = nullptr;
        m_nSize = 0;
    }
}

template<typename T>
inline bool MyArray<T>::reset(size_t nsize)
{
    if (nsize < 1) { return false; }
    if (m_pData) { delete[] m_pData; m_pData = nullptr; }
    m_pData = new T[nsize];
    m_nSize = nsize;
    return true;
}

template<typename T>
inline void MyArray<T>::reset(size_t nsize, T obj)
{
    bool isset = reset(nsize);
    if (isset)
    {
        for (size_t i = 0; i < nsize; ++i)
        {
            m_pData[i] = obj;
        }
    }
}
