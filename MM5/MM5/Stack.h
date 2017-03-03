#define STRING_LENGTH 100

typedef long HANDLE;
typedef char String[STRING_LENGTH+1];

HANDLE createStack(int);
void destroyStack(HANDLE);
void Peek(HANDLE,String);
void Pop(HANDLE,String);
void Push(HANDLE,String);
