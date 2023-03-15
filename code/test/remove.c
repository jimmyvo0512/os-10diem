#include "syscall.h"

int main() {
    int fileId, length;
    char fileName[256];

    PrintString("Enter file name length: ");
    length = ReadNum();
    PrintString("Input file name to remove: ");
    ReadString(fileName, length);

    fileId = Open(fileName, 0);
    if (fileId == -1) {
        PrintString("404: File Not Found, ...\n");
        Halt();
    }
    PrintString("Open file successfully, ...\n");
    Close(fileId);

    if (Remove(fileName) == 0) {
        PrintString("File ");
        PrintString(fileName);
        PrintString(" is deleted successfully\n");
    } else {
        PrintString("400: Bad Request, ...\n");
    }

    return 0;
}