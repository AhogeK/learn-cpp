//
// Created by ahogek on 1/3/22.
//

#include <cstdio>
#include <cstring>

int main() {
    char szInput[256];
    std::FILE *tmpFile = std::tmpfile();
    std::fputs("Just Testing", tmpFile);

    std::rewind(tmpFile);
    char buf[8];
    int index = 0;
    while (std::fgets(buf, sizeof buf, tmpFile) != nullptr) {
        if (index != 0 && buf[index--] == '\000') index--;
        for (char i: buf) {
            szInput[index++] = i;
        }
    }
    printf("The sentence entered is %u characters long.\n", (unsigned) strlen(szInput));
    printf("szInput length is %u\n", (unsigned) (sizeof szInput / sizeof szInput[0]));
    return 0;
}