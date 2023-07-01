
uchar ReadBit(uchar* bit, uchar* byte, FILE* in);

uchar ReadByte(uchar* bit, uchar* byte, FILE* in);

void ReadHeader(int* sizeMessage, FILE* in);

TTree* ReadTree(TTree* node, uchar* bit, uchar* byte, FILE* in);

void ReadMessage(TTree* root, int* sizeMessage, uchar* bit, uchar* byte, FILE* in, FILE* out);
