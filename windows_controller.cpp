#include <windows.h>
#include <iostream>

int main() {
    std::cout << "自动按回车程序\n";
    std::cout << "请将光标放在需要按回车的位置\n";
    std::cout << "按F8开始执行,按ESC停止\n";

    // 设置时间间隔
    int interval;
    std::cout << "请输入按回车的时间间隔(秒): ";
    std::cin >> interval;

    // 转换为毫秒
    interval *= 1000;

    bool running = false;

    while (true) {
        // 检测F8键开始
        if (GetAsyncKeyState(VK_F8) & 0x8000) {
            running = true;
            std::cout << "开始执行自动按回车...\n";
        }

        // 检测ESC键停止
        if (GetAsyncKeyState(VK_ESCAPE) & 0x8000) {
            std::cout << "程序已停止\n";
            break;
        }

        // 如果程序在运行状态，执行回车操作
        if (running) {
            // 模拟按下回车键
            keybd_event(VK_RETURN, 0, 0, 0);
            // 模拟释放回车键
            keybd_event(VK_RETURN, 0, KEYEVENTF_KEYUP, 0);

            // 等待指定的时间间隔
            Sleep(interval);
        }

        Sleep(100); // 减少CPU使用率
    }

    return 0;
}
