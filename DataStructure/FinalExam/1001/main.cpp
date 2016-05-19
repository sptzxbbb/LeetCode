void hashInit(int* hashTable, const int hashSize) {
  for (int i = 0; i < hashSize; ++i) {
    hashTable[i] = -1;
  }
}

void hashInsertWithLinearCollision(int* hashTable, const int hashSize, const int val) {
  int pos = val % hashSize;
  for (int i = 0; i < hashSize; ++i) {
    if (hashTable[pos] == -1) {
      hashTable[pos] = val;
      break;
    } else {
      pos = (pos + 1) % hashSize;
    }
  }
}
