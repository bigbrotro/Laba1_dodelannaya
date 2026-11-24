#include "Quene.h"


int main()
{
    std::setlocale(LC_ALL, "Rus");
    std::cout << std::endl << "Демонстрация работы очереди" << std::endl;
    Queue<int> queue;
    for (int i = 0; i < 5; i++)
    {
        int val = std::rand() % 100;
        queue.Push(val);
        std::cout << "Добавлено значение: " << val << std::endl;
        queue.Print();
    }

    std::cout << std::endl;

    while (queue.Size() > 0)
    {
        std::cout << "Извлечено значение: " << queue.Pop() << std::endl;
        queue.Print();
    }
}