#include <iostream>

int main()
{
    const int count = 6;
    int values[count] = {1, 4, 11, 99, -12, 6};

    std::cout << "Foreach:\n";
    for (const auto value : values) 
    {
        std::cout << value << '\n';
    }
    std::cout << "\nClassic for:\n";
    for (size_t i = 0; i < count; ++i) {
        printf("%d\n", values[i]);
    }
    return 0;
}