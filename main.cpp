#include <iostream>
#include <vector>
#include <CRC16_32.h>

int main()
{
    // CRC32 for array
    int N = 0;
    std::cout << "Input N: ";
    std::cin >> N;

    std::vector<float> vec;
    for (int i=0; i<N; ++i)
    {
        float input;
        std::cin >> input;
        vec.push_back(input);
    }

    char buf[14];
    unsigned crc32 = 0xffffffff;

    for (int i=0; i<static_cast<int>(vec.size()); ++i)
    {
       crc32 = CalcCRC32(crc32, (unsigned char *)&vec[i], sizeof(vec[0]));
    }
    snprintf(buf, 13, "CRC=%08X", crc32);
    std::cout << buf << std::endl;

    // CRC32 for file
    char *filename;
    std::cout << "Input filename: ";
    std::cin >> filename;

    crc32 = CalcFileCRC(filename);
    snprintf(buf, 13, "CRC=%08X", crc32);
    std::cout << buf << std::endl;

    return 0;
}
