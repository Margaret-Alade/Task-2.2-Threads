//
//  main.cpp
//  Task-2.2-Threads
//
//  Created by Маргарет  on 09.06.2024.
//

#include <iostream>
#include <thread>
#include <mutex>
#include <vector>


std::mutex m;

void func(int num) {
    std::lock_guard lk(m);
    num += 4;
    num -= 3;
    num *= 15;
}


int main(int argc, const char * argv[]) {
    
    std::vector<std::thread> v;
    for (int i = 0; i < 4; ++i) {
        v.push_back(std::thread(func, i + 1));
    }
    for (auto &el : v) {
        el.join();
    }
    
    std::cout << "#\t\t" << "id\t\t" <<  "Progress bar" << "\t" << "Time" << "\n";
    int i = 0;
    
    for (auto &el : v) {
        std::cout << i << "\t\t" << el.get_id() << "\n";
        i++;
    }
    
    return 0;
}
