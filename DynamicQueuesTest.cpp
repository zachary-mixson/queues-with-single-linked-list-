#include <iostream>
#include <fstream>
#include <string>
#include "DynamicQueue.h"

int main()
{

    const int N = 4;
    DynamicQueue queue0 = DynamicQueue();
    DynamicQueue queue1 = DynamicQueue();
    DynamicQueue queue2 = DynamicQueue();
    DynamicQueue queue3 = DynamicQueue();

    DynamicQueue queueList[N] = { queue0 , queue1 , queue2 , queue3 };

    std::string key;
    std::ifstream myfile("data.txt");//2 is index 0 is info
    //if (myfile.is_open())
    //{
    //    while (getline(myfile, key))
    //    {
    //        int index = static_cast<int>(key[2]);
    //       // int index = atoi(key[2]);
    //        std::cout << index << '\n';
    //        char info = key[0];
    //        std::cout << info << '\n';
    //
    //        if (index == 49) {
    //            index = 1;
    //        }
    //        if (index == 51) {
    //            index = 2;
    //        }
    //        
    //        queueList[index].insertOrMove(info);
    //
    //        queueList[index].print();
    //        //key[0];
    //        //key[1];
    //        //key[2];
    //        
    //    }
    //    myfile.close();
    //}



    int index;
    char info;
    while (myfile.good()) {
        myfile >> info >> index;
        std::cout << "Read key " << info << " for queue " << index << ". ";
        //std::cout << index;
        queueList[index].insertOrMove(info);
        queueList[index].print(index);
    }
    myfile.close();

    //queueList[0].insert('a');
    //queueList[0].insert('b');
    //queueList[0].insert('c');
    //queueList[0].insertOrMove('d');

}

