 #pragma once
#include "stdafx.h"

template <typename T>
class MA_MyArray//不带移动语义
{
public:
    MA_MyArray() : m_pData(nullptr), m_nSize(0) {}//ctor 构造函数 
    MA_MyArray(size_t nsize);//创建数组时，直接给定多少个元素  
    MA_MyArray(size_t nsize, T obj); //创建数组的时候，直接给定元素的个数和元素的初始值
    MA_MyArray(const MA_MyArray& obj); //copy ctor
    MA_MyArray(MA_MyArray&& obj)noexcept;//带有移动语义的拷贝构造
    ~MA_MyArray();//dtor

    T& operator [](size_t i) const; //获取数组中第N个元素 这里采用的是引用的形式 
    MA_MyArray& operator = (MA_MyArray&& obj)noexcept; //带有移动语义的赋值拷贝
    MA_MyArray& operator = (const MA_MyArray& obj);//赋值拷贝
    bool operator<(MA_MyArray<T>obj)const; //重载小于

    T* getData() const { return m_pData; } //获取整个数据的指针 
    T getAt(size_t i) const; //获取数组中第N个元素的值，注意，这里不是引用，如果是引用，则需要用[]来访问 

    size_t getSize() const { return m_nSize; }//返回数组中元素的个数
    bool empty() { return m_nSize == 0 ? true : false; } //判断数组是否为空
    bool reset(size_t nsize);//重置数组个数 
    void Append(const T& elem);//在末尾增加一个元素 
    void DeleteAll();//删除所有元素 
    void reset(size_t nsize, T obj);//重置对象个数，并给定所有元素的初始值

private:
    T* m_pData = nullptr;
    size_t m_nSize = 0;
};

template<typename T>
inline MA_MyArray<T>::MA_MyArray(size_t nsize)
{
    if (nsize > 0)
    {
        m_pData = new T[nsize]; m_nSize = nsize;
    }
}

template<typename T>
inline MA_MyArray<T>::MA_MyArray(size_t nsize, T obj)
{
    if (nsize > 0)
    {
        m_pData = new T[nsize];
        for (size_t i = 0; i < nsize; ++i) { m_pData[i] = obj; }
        m_nSize = nsize;
    }
}

template<typename T>
inline MA_MyArray<T>::MA_MyArray(const MA_MyArray& obj)
{
    //开辟新的空间用来存放
    m_pData = new T[obj.getSize()];
    //拷贝原有数据到新的空间
    memcpy(m_pData, obj.m_pData, sizeof(T) * obj.m_nSize);
    m_nSize = obj.m_nSize;
}

template<typename T>
inline MA_MyArray<T>::MA_MyArray(MA_MyArray<T>&& obj) noexcept
{
    if (obj.m_pData == NULL) { return; }
    m_pData = obj.m_pData;
    m_nSize = obj.m_nSize;
    obj.m_pData = NULL;
    obj.m_nSize = 0;
}

template<typename T>
inline MA_MyArray<T>::~MA_MyArray()
{
    if (m_pData)
    {
        delete[] m_pData;
        m_pData = nullptr;
        m_nSize = 0;
    }
}

template<typename T>
inline T MA_MyArray<T>::getAt(size_t i) const
{
    if (m_pData != nullptr && i >= 0 && i < m_nSize)
    {
        return m_pData[i];
    }
}

template<typename T>
inline T& MA_MyArray<T>::operator[](size_t i) const
{
    if (m_pData != nullptr && i >= 0 && i < m_nSize)
    {
        return m_pData[i];
    }
}

template<typename T>
inline MA_MyArray<T>& MA_MyArray<T>::operator=(MA_MyArray<T>&& obj) noexcept
{
    if (m_pData == obj.m_pData) { return *this; }
    m_pData = obj.m_pData;
    m_nSize = obj.m_nSize;
    obj.m_pData = NULL;
    obj.m_nSize = 0;
    return *this;
}

template<typename T>
bool MA_MyArray<T>::operator<(const MA_MyArray<T> obj)const
{
    if (m_nSize < obj.getSize())//首先根据所含元素个数判断
        return true;
    else if (m_nSize == obj.getSize())//两者元素个数相等，依次比较元素大小
    {
        for (int i = 0; i < m_nSize; i++)
        {
            if (m_pData[i] < obj[i])//如果当前元素更小
                return true;
            else if (m_pData[i] == obj[i])//元素相等
                continue;//进行下一次比较
            else
                return false;//否则直接退出
        }
    }
    return false;//捕捉数目大以及全部相等情况
}

template<typename T>
inline MA_MyArray<T>& MA_MyArray<T>::operator=(const MA_MyArray<T>& obj)
{
    if (m_pData == obj.m_pData) { return *this; }
    if (obj.m_pData == nullptr)
    {
        if (m_pData) { delete[] m_pData; m_pData = nullptr; m_nSize = 0; }
        return *this;
    }
    if (m_pData) {
        //清除原有数组
        delete[] m_pData; m_pData = nullptr;
    }
    //开辟新的空间用来存放
    m_pData = new T[obj.getSize()];
    //拷贝原有数据到新的空间
    memcpy(m_pData, obj.m_pData, sizeof(T) * obj.m_nSize);
    m_nSize = obj.m_nSize;
    return *this;
}

template<typename T>
inline void MA_MyArray<T>::Append(const T& elem)
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
inline void MA_MyArray<T>::DeleteAll()
{
    if (m_pData)
    {
        delete[] m_pData;
        m_pData = nullptr;
        m_nSize = 0;
    }
}

template<typename T>
inline bool MA_MyArray<T>::reset(size_t nsize)
{
    if (nsize < 1) { return false; }
    if (m_pData) { delete[] m_pData; m_pData = nullptr; }
    m_pData = new T[nsize];
    m_nSize = nsize;
    return true;
}

template<typename T>
inline void MA_MyArray<T>::reset(size_t nsize, T obj)
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




