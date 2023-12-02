    #include<iostream>
    using namespace std;
    int temp=0;
    void sort_array()
    {
         int ptr_array[5]={10,20,30,4,50};
         int num=5;
        for(int i=0;i<num;i++)
        {
            for(int j=i+1;j<num;j++)
            {
                if(ptr_array[i]>ptr_array[j])
                {
                    temp=ptr_array[i];
                    ptr_array[i]=ptr_array[j];
                    ptr_array[j]=temp;
                }
                else
                    continue;
            }
        }
        for(int i=0;i<num;i++)
        {
            cout<<ptr_array[i]<<" ";
        }
    }
    int main()
    {
        sort_array();
    }