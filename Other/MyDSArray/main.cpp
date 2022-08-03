#include <iostream>
using namespace std;


class Array
{
    int *ARRAY;
    int SIZE;
    int LENGTH;
    int INDEX;
    int VALUE;
public:
    int DELETE_ARRAY(int INDEX);
    int APPEND_ARRAY(int VALUE);
    int INSERT_ARRAY(int INDEX,int VALUE);
    void SET_LENGTH();
    void SET_VALUES();
    void DISPLAY_ARRAY();
    void REVERSE_ARRAY();
    void INSERT_SORTEDLIST(int VALUE);
    bool isSorted();
    Array MERGE_ARRAY(Array &A,Array &B);
    Array MERGE_UNION(Array &A, Array &B);
    Array MERGE_INTERSECTION(ARRAY &A,Array &B);
    Array MERGE_DIFFERENCE(Array &A, Array &B);

    Array()
    {
        int S;
        cout<<"Enter the maximum size: ";
        cin>>S;
        this->SIZE=S;
        ARRAY=new int[this->SIZE];
    }

    int GET_LENGTH()
    {
        return LENGTH;
    }
    int GET_INDEX()
    {
        return INDEX;
    }
    int GET_VALUE()
    {
        return VALUE;
    }
    /*
    ~Array()
    {
        delete []ARRAY;
        cout<<endl<<"The Array was destroyed"<<endl;
    } */
};

int Array::DELETE_ARRAY(int INDEX)
{
    int i;
    for (i=INDEX;i<LENGTH-1;++i)
    {
        ARRAY[i]=ARRAY[i+1];
    }
    --LENGTH;
    return 0;
}

int Array::APPEND_ARRAY(int VALUE)
{
    if (LENGTH<this->SIZE)
    {
        ARRAY[LENGTH++]=VALUE;
    }
    return 0;
}

int Array::INSERT_ARRAY(int INDEX,int VALUE)
{
    int i;
    if (INDEX >=0 && INDEX <= LENGTH)
    {
        for (i=LENGTH;i>=INDEX;--i)
        {
            ARRAY[i]=ARRAY[i-1];
        }
        ARRAY[INDEX]=VALUE;
        ++LENGTH;
    }
    return 0;
}

void Array::SET_LENGTH()
{
    cout<<"Enter LENGTH: "<<flush;
    cin>>LENGTH;
}

void Array::SET_VALUES()
{
    for (int i=0;i<LENGTH;++i)
    {
        cout<<"Enter Element "<<i<<": "<<flush;
        cin>>ARRAY[i];
    }
}

void Array::DISPLAY_ARRAY()
{
    for (int i=0;i<LENGTH;++i)
    {
        cout<<ARRAY[i]<<" ";
    }
    cout<<endl;
}

void Array::REVERSE_ARRAY()
{
    for (int i=0,j=LENGTH-1;i<j;++i,--j)
    {
        int temp=ARRAY[i];
        ARRAY[i]=ARRAY[j];
        ARRAY[j]=temp;
    }
}

void Array::INSERT_SORTEDLIST(int VALUE)
{
    if (isSorted()==false || LENGTH>SIZE)
    {
        return;
    }
    int i=LENGTH-1;
    while (i>=0 && ARRAY[i]>VALUE)
    {
        ARRAY[i+1]=ARRAY[i];
        --i;
    }
    ARRAY[i+1]=VALUE;
    ++LENGTH;
}

bool Array::isSorted()
{
    for (int i=0;i<LENGTH-1;++i)
    {
        if (ARRAY[i]>ARRAY[i+1])
        {
            return false;
        }
    }
    return true;
}

Array Array::MERGE_ARRAY(Array &A,Array &B)
{
    Array C;
    C.SET_LENGTH();
    int i=0,j=0,k=0;
    while (i<A.LENGTH && j<B.LENGTH)
    {
        if (A.ARRAY[i]<B.ARRAY[j])
        {
            C.ARRAY[k++]=A.ARRAY[i++];
        }
        else
        {
            C.ARRAY[k++]=B.ARRAY[j++];
        }
    }
    for (;i<A.LENGTH;i++)
    {
        C.ARRAY[k++]=A.ARRAY[i];
    }
    for (;j<B.LENGTH;j++)
    {
        C.ARRAY[k++]=B.ARRAY[j];
    }

    C.LENGTH=A.LENGTH+B.LENGTH;
    return C;
}

Array Array::MERGE_UNION(Array &A,Array &B)
{
    Array C;
    C.LENGTH=A.LENGTH+B.LENGTH;
    int i=0,j=0,k=0;
    while (i<A.LENGTH && j<B.LENGTH)
    {
        if (A.ARRAY[i] < B.ARRAY[j])
        {
            C.ARRAY[k++]=A.ARRAY[i++];
        }
        else if (A.ARRAY[i] > B.ARRAY[j])
        {
            C.ARRAY[k++]=B.ARRAY[j++];
        }
        else
        {
            C.ARRAY[k++]=A.ARRAY[i++];
            ++j;
        }
    }
    for (;i<A.LENGTH;)
    {
        C.ARRAY[k++]=A.ARRAY[i++];
    }
    for (;j<B.LENGTH;)
    {
        C.ARRAY[k++]=B.ARRAY[j++];
    }
    return C;
}

Array Array::MERGE_INTERSECTION(Array &A,Array &B)
{
    Array C;
    int i=0,j=0,k=0;
    while (i<A.LENGTH && j<B.LENGTH)
    {
        if (A.ARRAY[i]<B.ARRAY[j])
        {
            ++i;
        }
        else if (A.ARRAY[i]>B.ARRAY[j])
        {
            ++j;
        }
        else
        {
            C.ARRAY[k++]=A.ARRAY[i++];
            ++j;
        }
    }
    return C;
}

Array Array::MERGE_DIFFERENCE(Array &A, Array &B)
{
    Array C;
    int i=0,j=0,k=0;
    while (i<A.LENGTH && j<B.LENGTH)
    {
        if (A.ARRAY[i]<B.ARRAY[j])
        {
            C.ARRAY[k++]=A.ARRAY[i++];
        }
        else if (A.ARRAY[i]>B.ARRAY[j])
        {
            ++j;
        }
        else
        {
            ++i;
            ++j;
        }
    }
    for (;i<A.LENGTH;)
    {
        C.ARRAY[k++]=A.ARRAY[i++];
    }
    return C;
}

int main()
{
    Array A1;
    A1.SET_LENGTH();
    A1.SET_VALUES();
    A1.APPEND_ARRAY(5);
    A1.APPEND_ARRAY(2);
    A1.INSERT_ARRAY(2,3);
    A1.INSERT_ARRAY(1,2);
    A1.DELETE_ARRAY(2);
    A1.REVERSE_ARRAY();
    A1.DELETE_ARRAY(0);
    A1.INSERT_SORTEDLIST(-7);
    A1.INSERT_SORTEDLIST(4);
    A1.INSERT_SORTEDLIST(10);
    A1.DISPLAY_ARRAY();

    Array A2;
    A2.SET_LENGTH();
    A2.SET_VALUES();
    A2.DISPLAY_ARRAY();

    Array Z;
    Z.SET_LENGTH();
    Z=Z.MERGE_ARRAY(A1,A2);
    Z.DISPLAY_ARRAY();
    return 0;
}
