#ifndef SHAREDMEMORY_H
#define SHAREDMEMORY_H

#include <windows.h>
#include <string>

#ifdef SHAREDMEMORY_EXPORTS
#define SHAREDMEMORY_API __declspec(dllexport)
#else
#define SHAREDMEMORY_API __declspec(dllimport)
#endif

#pragma pack(push, 1) // Ensure no unexpected padding
struct SharedMemory {
    int32_t cmd = -1;
    int32_t option = -1;
    int32_t isMessageSet = 0; // Using int32_t instead of bool to ensure compatibility
};
#pragma pack(pop)

class SHAREDMEMORY_API SharedMemoryHandler {
private:
    HANDLE hMapFile;
    HANDLE hEventFull;
    HANDLE hEventEmpty;
    SharedMemory* shm;

    bool isProducer;
    void cleanup();
    void initProducer(const TCHAR* shmName);
    void initConsumer(const TCHAR* shmName);
    void printEventStatus(HANDLE hEvent, const std::wstring& eventName);

public:
    SharedMemoryHandler(const TCHAR* shmName, const int isProducer);

    ~SharedMemoryHandler();

    bool setMessage(int cmd, int option);

    SharedMemory* getMessage();

    void resetEvent();

    HANDLE getFullEvent();

    HANDLE getEmptyEvent();
};

#endif // SHAREDMEMORY_H
