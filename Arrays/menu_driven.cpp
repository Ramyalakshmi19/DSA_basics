#include<iostream>
using namespace std;
int max_array,num_array=0;
int num_set1,num_set2;
class array_operation
{
    private:
        int flag,max,min,i,count,k=0;
        int sort_flag,linear_flag,dupl_flag,temp=0;
        int mid_element,low,high,binary_flag;
        int *ptr_array=new int[max_array];
        int *ptr_duplicate=new int[max_array];
        int *ptr_count=new int[max_array];
    public:
    void get_data(int num_array)
    {
        for(int i=0;i<num_array;i++)
        {
            dupl_flag=0;
            cin>>ptr_array[i];
            for(int j=0;j<i;j++)
            {
                if(ptr_array[i]==ptr_duplicate[j])
                {
                    dupl_flag+=1;
                    ptr_count[j]=dupl_flag+1;
                }
            }
            if(dupl_flag==0)
            {
                ptr_duplicate[i]=ptr_array[i];
                k++;
            }
        }
    }
    int find_max()
    {
        max=ptr_array[0];
        for(int i=0;i<num_array;i++)
        {
            if(ptr_array[i]>max)
                max=ptr_array[i];
        }
        return max;
    }
    int find_min()
    {
        min=ptr_array[0];
        for(int i=0;i<num_array;i++)
        {
            if(ptr_array[i]<min)
                min=ptr_array[i];
        }
        return min;
    }
    void insert_element(int value,int pos)
    {
        
        if(num_array!=max_array)
        {
            for(int i=num_array;i>=pos;i--)
            {
                ptr_array[i]=ptr_array[i-1];
            }
            ptr_array[pos-1]=value;
            num_array+=1;
        }
        else
            cout<<"Array is full";
    }
    void display()
    {
        for(int i=0;i<num_array;i++)
        {
            cout<<ptr_array[i]<<" ";
        }

    }
    void delete_elem(int pos)
    {
        
        for(int i=pos-1;i<num_array;i++)
        {
            ptr_array[i]=ptr_array[i+1];
        }
        num_array-=1;
    }
    void update_elem(int old_value,int new_value)
    {
        flag=0;
        for(int i=0;i<num_array;i++)
            {
                if(ptr_array[i]==old_value)
                {
                    ptr_array[i]=new_value;
                    flag+=1;
                }
            }
            if(flag==0)
                cout<<"Element not found";

    }   
    void update_pos(int position,int new_value)         
    {
        ptr_array[position-1]=new_value;
    }
    void sort_array()
    {
        for(int i=0;i<num_array;i++)
        {
            for(int j=i+1;j<num_array;j++)
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
    }
    int sort_check()
    {
        sort_flag=0;
        for(int i=0;i<num_array;i++)
        {
            for(int j=i+1;j<num_array;j++)
            {
                if(ptr_array[i]>ptr_array[j])
                    return 0;
            }
        }
    }
    void binary_search(int element)
    {
        i=0;
        binary_flag=0;
        low=0;
        high=num_array-1;
        while(i<num_array)
        {
            mid_element=(low+high)/2;
            if(ptr_array[mid_element]==element)
            {
                cout<<"Element found at index:"<<mid_element;
                binary_flag+=1;
                break;
            }
            else if(ptr_array[mid_element]<element)
                low=mid_element+1;
            else
                high=mid_element-1;
        }
        if(binary_flag==0)
            cout<<"Element not found";
    }
    void linear_search(int element)
    {
        linear_flag=0;
        for(int i=0;i<num_array;i++)
        {
            if(ptr_array[i]==element)
            {
                cout<<"Element found at the index:"<<i<<endl;
                linear_flag+=1;
            }      
        }
        if(linear_flag==0)
        {
            cout<<"Element not found";
        }
    }
    void count_elem()
    {
        for(int i=0;i<k;i++)
        {
            cout<<"Frequency of "<<ptr_duplicate[i]<<":"<<ptr_count[i]<<endl;
        }
    }
};
class set_operation
{
    private:
        int  flag,diff_flag=0,k=0,j=0;
        int union_len=0,intersec_len=0,diff_len=0;
        int* ptr_duplicate1=new int[num_set1];
        int* ptr_duplicate2=new int[num_set2];
        int* ptr_union=new int[num_set1+num_set2];
        int* union_duplicate=new int[num_set1+num_set2];
        int* ptr_intersec=new int[num_set1];
        int* intersec_duplicate=new int[num_set1];
        int* ptr_diff=new int[num_set1];
        int* diff_duplicate=new int[num_set1];
    public:
        void get_data1()
        {
            cout<<"Enter the number of elements in set 1:";
            cin>>num_set1;
            int* ptr_set1=new int[num_set1];
            for(int i=0;i<num_set1;i++)
            {
                cin>>ptr_set1[i];
            }
            num_set1=unique_elements(ptr_set1,num_set1,ptr_duplicate1);
            cout<<num_set1;
            cout<<"SET 1:";
            //display(ptr_duplicate1,num_set1);
        }
        void get_data2()
        {
            cout<<"Enter the number of elements in set 2:";
            cin>>num_set2;
            int* ptr_set2=new int[num_set2];
            for(int i=0;i<num_set2;i++)
            {
                cin>>ptr_set2[i];
            }
            num_set2=unique_elements(ptr_set2,num_set2,ptr_duplicate2);
            cout<<"SET 2:";
            display(ptr_duplicate2,num_set2);
        }
        int unique_elements(int* set,int num,int* dupl_set)
        {
            for(int i=0;i<num;i++)
            {
                for(int j=i+1;j<num;j++)
                {
                    if(set[i]==set[j])
                    {
                        flag+=1;
                        break;
                    }
                }
                if(flag==0)
                {
                    dupl_set[k]=set[i];
                    k++;
                }

            }
            cout<<"Value of k:"<<k;
            return k;
        }
        void set_union()
        {
            union_len=num_set1+num_set2;
            for(int i=0;i<(num_set1+num_set2);i++)
            {
                if(i<num_set1)
                    ptr_union[i]=ptr_duplicate1[i];
                else    
                {
                    ptr_union[i]=ptr_duplicate1[j];
                    j++;
                }
            }
            union_len=unique_elements(ptr_union,union_len,union_duplicate);
            cout<<"SET UNION:";
            display(union_duplicate,union_len);

        }
        void set_intersection()
        {
            for(int i=0;i<num_set1;i++)
            {
                for(int j=0;j<num_set2;j++)
                {
                    if(ptr_duplicate1[i]==ptr_duplicate2[j])
                        ptr_intersec[intersec_len]=ptr_duplicate1[i];
                        intersec_len+=1;
                }
            }
            intersec_len=unique_elements(ptr_intersec,intersec_len,intersec_duplicate);
            cout<<"SET INTERSECTION:";
            display(intersec_duplicate,intersec_len);
        }
        void set_difference()
        {
            for(int i=0;i<num_set1;i++)
            {
                for(int j=0;j<num_set2;j++)
                {
                    if(ptr_duplicate1[i]==ptr_duplicate2[j])
                        diff_flag+=1;
                        break;
                }
                if(diff_flag==0)
                {
                    ptr_diff[diff_len]=ptr_duplicate1[i];
                    diff_len+=1;
                }
            }
            diff_len=unique_elements(ptr_diff,diff_len,diff_duplicate);
            cout<<"SET DIFFERENCE:";
            display(diff_duplicate,diff_len);

        }
        void display(int* set,int len)
        {
            for(int i=0;i<len;i++)
            {
                cout<<set[i]<<" ";
            }
        }

};

int main()
{
    int prime_choice,set_choice,choice;
    int arr_max,arr_min;
    int delete_pos,search_element;
    int old_value,new_value,check;
    int insert_value,insert_pos;
    int choice_update,position;
    char wish='y',wish_array='y',wish_set='y';
    array_operation *ptr_object=new array_operation;
    set_operation *ptr_set=new set_operation;
    while(wish=='y')
    {
    cout<<"Do you want to perform\n1.Array operation\n2.Set operation\n";
    cin>>prime_choice;
    switch(prime_choice)
    {
        case 1:
            cout<<"Enter the max size of an array:";
            cin>>max_array;
            wish_array='y';
            while(wish_array=='y')
            {
                cout<<"_________________________________________________________\n";
                cout<<"1.Enter the array\n2. Find the maximum element\n3.Find the minimum element\n4.Insert an element\n5.Delete an element\n6.Update an element\n7.Sort the array\n8.Binary search(Only if array sorting is opted before)\n9.Linear search\n10.Count\n";
                cout<<"---------------------------------------------------\n";
                cout<<"Enter your choice:";
                cin>>choice;
                while((num_array==0)&(choice!=1))
                {
                    cout<<"Enter an array first to continue with array operations\n Press 1\n";
                    cin>>choice;
                }
                switch(choice)
                {
                    case 1:
                        cout<<"Enter the number of elements in the array:";
                        cin>>num_array;
                        ptr_object->get_data(num_array);
                        break;
                    case 2:
                        arr_max=ptr_object->find_max();
                        cout<<"The greatest element in the array:"<<arr_max;
                        break;
                    case 3:
                        arr_min=ptr_object->find_min();
                        cout<<"The smallest element in the array:"<<arr_min;
                        break;
                    case 4:
                        cout<<"Enter the value to be inserted:";
                        cin>>insert_value;
                        cout<<"Enter the position to be inserted:";
                        cin>>insert_pos;
                        ptr_object->insert_element(insert_value,insert_pos);
                        ptr_object->display();
                        break;
                    case 5:
                        cout<<"Enter the position of the element to be deleted:";
                        cin>>delete_pos;
                        ptr_object->delete_elem(delete_pos);
                        ptr_object->display();
                        break;
                    case 6:
                        cout<<"Your input\n1.The element to be updated\n2.The position of the element to be updated\n";
                        cin>>choice_update;
                        switch(choice_update)
                        {
                            case 1:
                                cout<<"Enter the old value of the element:";
                                cin>>old_value;
                                cout<<"Enter the new value to be updated:";
                                cin>>new_value;
                                ptr_object->update_elem(old_value,new_value);
                                ptr_object->display();
                                break;
                            case 2:
                                cout<<"Enter the position of the element to be update:";
                                cin>>position;
                                cout<<"Enter the new value to be updated:";
                                cin>>new_value;
                                ptr_object->update_pos(position,new_value);
                                break;
                            default:
                                cout<<"Invalid input";
                                ptr_object->display();

                        }
                    case 7:
                        ptr_object->sort_array();
                        ptr_object->display();
                        break;
                    case 8:
                        cout<<"Enter an element to search:";
                        cin>>search_element;
                        check=ptr_object->sort_check();
                        if(check==0)
                        {
                            cout<<"Array is not sorted(Binary search can't be performed)\n";
                            cout<<"By Linear search:\n";
                            ptr_object->linear_search(search_element);
                        }
                        else
                        {
                            ptr_object->binary_search(search_element);    
                        }
                        break;
                    case 9:
                        cout<<"Enter an element to search:";
                        cin>>search_element;
                        ptr_object->linear_search(search_element);
                        break;
                     case 10:
                        ptr_object->count_elem();
                        break;
                    default:
                        cout<<"Invalid input";    
                }
                cout<<"\nDo you want to continue array operations?(y/n)";
                cin>>wish_array;
        
            }
            break;
        case 2:
            wish_set='y';
            while(wish_set=='y')
            {
            cout<<"1.Enter the set 1\n2.Enter the set 2\n3. Set Union\n4.Set Intersection\n5.Set Difference\n";
            cout<<"Enter your choice:";
            cin>>set_choice;
            switch(set_choice)
            {
                case 1:
                    ptr_set->get_data1();
                    break;
                case 2:
                    ptr_set->get_data2();
                    break;
                case 3:
                    ptr_set->set_union();
                    break;
                case 4:
                    ptr_set->set_intersection();
                case 5:
                    ptr_set->set_difference();
                    break;
                default:
                    cout<<"Invalid input";

            }
            cout<<"Do you want to continue set operations(y/n)";
            cin>>wish_set;
            }
        default:
            cout<<"Invalid input:";

    }
    cout<<"Do you want to continue (y/n)";
    cin>>wish;
    }

}
