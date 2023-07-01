
void WriteBit(uchar bit, uchar* bitpos, uchar* byte, FILE* out);

void WriteByte(uchar symbol, uchar* bitpos, uchar* byte, FILE* out);

void WriteHeader(int sizeMessage, FILE* out);

void WriteTree(TTree* node, FILE* out, uchar* bitpos, uchar* byte);

void WriteMessage(FILE* in, FILE* out, uchar** HuffmanTable, uchar* bitpos, uchar* byte, int sizeMessage);
