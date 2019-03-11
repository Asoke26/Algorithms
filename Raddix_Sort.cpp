#include <iostream>
#include <vector>

void counting_sort(int* intput_array,int* output_array,int k,int input_array_size);
void raddix_sort(std::vector<std::vector<int> > input_vec);


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

    /////////////////////////////////////////////////////////////////////////////////
   // std::cout<<"Final Vector Size : "<<input_vecs.size()<<std::endl;

//    for(int i{};i<input_vecs.size();i++){
//        for(int j{};j<input_vecs[i].size();j++) {
//            std::cout << input_vecs[i][j]<<";";
//           // input_vec.push_back(input_number);
//            //std::cout<<"Done for inside"<<std::endl;
//        }
//        std::cout<<std::endl;
//    }
    raddix_sort(input_vecs);

    return 0;
}

void raddix_sort(std::vector<std::vector<int> > input_vecs)
{

    int input_array_cs[5]{};
    int output_array_cs[5]{};

    int vec_length{9},counter{9};

    for(int i{};i<input_vecs.size();i++){
        input_array_cs[i]=input_vecs[i][counter];
    }

    for(int i=0;i<5;i++){
        std::cout<<input_array_cs[i]<<";";
    }
    std::cout<<std::endl;
    counting_sort(input_array_cs,output_array_cs,4,5);

    for(int i{};i<5;i++)
        std::cout<<output_array_cs[i]<<";";
}


void counting_sort(int* intput_array,int* output_array,int k,int input_array_size)
{
    //int k=k_val;
    //std::cout<<k<<" "<<k_val;
    int count_array[k]{};
//
//    for(int i{};i<k;i++)count_array[i]=0;
    for(int j{};j<input_array_size;j++)count_array[intput_array[j]]=count_array[intput_array[j]]+1;
    for(int _ii{1};_ii<k;_ii++)count_array[_ii]=count_array[_ii]+count_array[_ii-1];
//
    for(int _jj{input_array_size-1};_jj>=0;_jj--){
        int count=count_array[intput_array[_jj]]-1;
        output_array[count]=intput_array[_jj];
        count_array[intput_array[_jj]]--;
    }

    ////Print
//    for(int i{};i<input_array_size;i++)
//        std::cout<<output_array[i]<<";";

}
