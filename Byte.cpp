/*
MIT License

Copyright (c) 2023 izal

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.
*/

void GenerateBlock(CryptoPP::byte* block, size_t size) {
  CryptoPP::OS_GenerateRandomBlock(false, block, size);
}

int main(int argc, char* argv[]) {
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
}
