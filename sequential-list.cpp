#include "sequential-list.h"
#include <iostream>
#include <list>
using namespace std;

SequentialList::SequentialList(unsigned int cap)
{
    //Setting capacity and size of the list and creating a new list
    capacity_ = cap;
    size_ = 0;
    data_ = new int[cap];
}

SequentialList::~SequentialList()
{
    delete[] data_;
    data_ = NULL;
}

unsigned int SequentialList::size() const
{
    return size_;
}

unsigned int SequentialList::capacity() const
{
    return capacity_;
}

bool SequentialList::empty() const
{
    if (size_ == 0)
        return true;

    return false;
}

bool SequentialList::full() const
{
    if (size_ == capacity_)
        return true;

    return false;
}

SequentialList::DataType SequentialList::select(unsigned int index) const
{
    if (index > size_ -1 || index < 0)
        return data_[size_-1];
    else
        return(data_[index]);
}

unsigned int SequentialList::search(DataType val) const
{
    for (int i = 0; i< size_-1; i++){
        if (data_[i] == val)
            return i;
    }
    return size_;
}

void SequentialList::print() const
{
    cout<<"Your SequentialList:"<<endl;
    for (int i = 0; i < size_ -1; i++)
        cout<<data_[i]<<" ";
}

bool SequentialList::insert(DataType val, unsigned int index)
{
    if (size_ < capacity_){
        if (size_ == index) //essentially an "insert_back()"
            data_[index] = val;
        else if (index > size_)
            return false;
        else {
            for (int i = size_; i > index; i--) {
                data_[i] = data_[i - 1];
            }
            data_[index] = val;
        }
        size_++;
        return true;
    }
    return false;
}

bool SequentialList::insert_front(DataType val)
{
    if (size_ < capacity_){
        for (int i = size_; i > 0; i--){
            data_[i] = data_[i-1];
        }
        data_[0] = val;
        size_++;
        return true;
    }
    return false;
}

bool SequentialList::insert_back(DataType val)
{
    if (size_ < capacity_){
        data_[size_] = val;
        size_++;
        return true;
    }
    else
        return false;
}

bool SequentialList::remove(unsigned int index)
{
    if ((index <= size_-1) && size_ != 0){
        for (int i = index; i < size_-1; i++) {
            if (i < size_-2)
                data_[i] = data_[i + 1];
            else if (i == size_-2)
                data_[i] = NULL;
        }
        return true;
    }
    return false;
}

bool SequentialList::remove_front()
{
    if (size_ > 0){
        for (int i = 0; i < size_-1; i++)
            data_[i] = data_[i+1];
        data_[size_-1] = NULL;
        size_--;
        return true;
    }
    return false;
}

bool SequentialList::remove_back()
{
    if (size_ > 0){
        data_[size_-1] = NULL;
        size_--;
        return true;
    }
    return false;
}

bool SequentialList::replace(unsigned int index, DataType val)
{
    if ((index <= size_-1) && size_ != 0){
        data_[index] = val;
        return true;
    }
    return false;
}
