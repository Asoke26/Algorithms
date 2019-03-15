#include <iostream>
#include <vector>

void counting_sort(int* intput_array,int* output_array,int k,int input_array_size);
void raddix_sort(std::vector<std::vector<int> > input_vec,int digits);
void print_vector(std::vector<std::vector<int> > input_vecs);

int main() {

    /////////////////////////////Input Area/////////////////////////////////////////
    int number_of_inputs{};

    std::cin>>number_of_inputs;

    int vector_length{10};
    int input_number{};
    std::vector< std::vector<int> > input_vecs;
    std::vector<int> input_vec;

    for(int i{};i<number_of_inputs;i++){
        for(int j{};j<vector_length;j++){
            std::cin>>input_number;
            input_vec.push_back(input_number);
            //std::cout<<"Done for inside"<<std::endl;
        }
        input_vecs.push_back(input_vec);
        input_vec.clear();
        //std::cout<<"Vector Size : "<<input_vecs.size()<<std::endl;
    }
//    input_vecs[0].swap(input_vecs[2]);

    print_vector(input_vecs);
    /////////////////////////////////////////////////////////////////////////////////
    // std::cout<<"Final Vector Size : "<<input_vecs.size()<<std::endl;
    raddix_sort(input_vecs,number_of_inputs);

    return 0;
}

void print_vector(std::vector<std::vector<int> > input_vecs)
{
    std::cout<<"------------------------Printing the vector----------------"<<std::endl;
    for(int i{};i<input_vecs.size();i++){
        for(int j{};j<input_vecs[i].size();j++){
            std::cout<<input_vecs[i][j]<<";";
        }
        std::cout<<std::endl;
    }
}

void raddix_sort(std::vector<std::vector<int> > input_vecs,int number_of_inputs)
{
    int input_array_cs[number_of_inputs]{};
    int count_array[4]{};

    int vec_length{9},counter{9};

        for(int i{};i<input_vecs.size();i++){
            input_array_cs[i]=input_vecs[i][counter];
        }
        counting_sort(input_array_cs,count_array,4,number_of_inputs);
        for(int i{};i<3;i++)std::cout<<count_array[i]<<";";
        std::cout<<std::endl;
        /// Rebuilding vector by sorting digits from right to left

//        int vec_size=5;
        for(int i{input_vecs.size()-1};i>=0;i--){

            int cur_index= count_array[input_array_cs[number_of_inputs-- -1]]-- -1;
            std::cout<<"Current index is : "<<cur_index<< "  i "<<i<<std::endl;
            std::cout<<std::endl;

            std::cout<<"-------Printing Input array----------"<<std::endl;
            for(int i{};i<input_array_size;i++)std::cout<<intput_array[i]<<";";
            std::cout<<"-------Printing Count array----------"<<std::endl;
            for(int i{};i<3;i++)std::cout<<count_array[i]<<";";
            std::cout<<std::endl;

            if(cur_index==i && cur_index<=1) continue;
            input_vecs[cur_index].swap(input_vecs[i]);
            print_vector(input_vecs);


        }
        counter--;
//    }

//    print_vector(input_vecs);
}



void counting_sort(int* intput_array,int* count_array,int k,int input_array_size)
{


    for(int j{};j<input_array_size;j++)count_array[intput_array[j]]=count_array[intput_array[j]]+1;
    for(int _ii{1};_ii<k;_ii++)count_array[_ii]=count_array[_ii]+count_array[_ii-1];

}
