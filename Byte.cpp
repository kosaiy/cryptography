void GenerateBlock(CryptoPP::byte* block, size_t size)
{
  CryptoPP::OS_GenerateRandomBlock(false, block, size);
}

int main(int argc, char* argv[])
{
  CryptoPP::HexEncoder encoder(new CryptoPP::FileSink(std::cout));
  CryptoPP::SecByteBlock block1(16);

  std::byte block2[16];

  GenerateBlock(block1, block1.size());
  GenerateBlock(reinterpret_cast<CryptoPP::byte*>(block2), sizeof(block2));

  std::cout << "Block 1: ";
  encoder.Put(block1, block1.size());
  encoder.MessageEnd();
  std::cout << std::endl;

  std::cout << "Block 2: ";
  encoder.Put(reinterpret_cast<const byte*>(block2), sizeof(block2));
  encoder.MessageEnd();
  std::cout << std::endl;

  return 0;
}
