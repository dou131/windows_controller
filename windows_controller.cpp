#include <windows.h>
#include <iostream>

int main() {
    std::cout << "�Զ����س�����\n";
    std::cout << "�뽫��������Ҫ���س���λ��\n";
    std::cout << "��F8��ʼִ��,��ESCֹͣ\n";

    // ����ʱ����
    int interval;
    std::cout << "�����밴�س���ʱ����(��): ";
    std::cin >> interval;

    // ת��Ϊ����
    interval *= 1000;

    bool running = false;

    while (true) {
        // ���F8����ʼ
        if (GetAsyncKeyState(VK_F8) & 0x8000) {
            running = true;
            std::cout << "��ʼִ���Զ����س�...\n";
        }

        // ���ESC��ֹͣ
        if (GetAsyncKeyState(VK_ESCAPE) & 0x8000) {
            std::cout << "������ֹͣ\n";
            break;
        }

        // �������������״̬��ִ�лس�����
        if (running) {
            // ģ�ⰴ�»س���
            keybd_event(VK_RETURN, 0, 0, 0);
            // ģ���ͷŻس���
            keybd_event(VK_RETURN, 0, KEYEVENTF_KEYUP, 0);

            // �ȴ�ָ����ʱ����
            Sleep(interval);
        }

        Sleep(100); // ����CPUʹ����
    }

    return 0;
}
