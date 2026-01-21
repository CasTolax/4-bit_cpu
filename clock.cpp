#include <iostream>
#include <chrono>
#include <thread>
using namespace std;

int main(){

    bool clk1x = 0; // 1 saniye (s) = 1
    bool clk2x = 0; // 1 milisaniye (ms) = 10⁻³ saniye = 1 / 1 000
    bool clk3x = 0; // 1 mikrosaniye (µs) = 10⁻⁶ saniye = 1 / 1 000 000
    bool clk4x = 0; // 1 nanosaniye (ns) = 10⁻⁹ saniye = 1 / 1 000 000 000

    int ask_time; // input

    cout << "clk1x(1) clk2x(2) clk3x(3) clk4x(4) ? = ";
    cin >> ask_time;

    if(ask_time == 1){
        while(true){
            clk1x = !clk1x;
            cout << clk1x << endl;
            std::this_thread::sleep_for(std::chrono::seconds(1));
        }
    }else if(ask_time == 2){
        while(true){
            clk2x = !clk2x;
            cout << clk2x << endl;
            std::this_thread::sleep_for(std::chrono::milliseconds(500));
        }
    }else if(ask_time == 3){
        while(true){
            clk3x = !clk3x;
            cout << clk3x << endl;
            std::this_thread::sleep_for(std::chrono::microseconds(1000));
        }
    }else if(ask_time == 4){
        while(true){
            clk4x = !clk4x;
            cout << clk4x << endl;
            std::this_thread::sleep_for(std::chrono::nanoseconds(10000));
        }
    }
}

