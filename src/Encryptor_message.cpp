template <class EncryptorType>
std::string Encrypt(EncryptorType &encryptor, const std::string &PlainText)
{
	std::string CipherText;
	CryptoPP::StringSource(PlainText, true,
		new CryptoPP::StreamTransformationFilter(
			encryptor, new CryptoPP::Base64Encoder(new CryptoPP::StringSink(CipherText), false) /* default padding */
		)
	);
	return CipherText;
}

template <class DecryptorType>
std::string Decrypt(DecryptorType &decryptor, const std::string &EncText)
{
	std::string PlainText;
	CryptoPP::StringSource(EncText, true,
		new CryptoPP::Base64Decoder(
			new CryptoPP::StreamTransformationFilter(
				decryptor, new CryptoPP::StringSink(PlainText)
			)
		)
	);
	return PlainText;
}

int main(int argc, char* argv[]) {
	using namespace std;
	using AES = CryptoPP::AES;

	CryptoPP::SecByteBlock KEY(AES::DEFAULT_KEYLENGTH);
	CryptoPP::SecByteBlock IV(AES::DEFAULT_KEYLENGTH);

	for (auto &c : KEY) c = 0;
	for (auto &c : IV) c = 0;

	CryptoPP::CBC_Mode<AES>::Encryption Encryptor { KEY, KEY.size(), IV };
	CryptoPP::CBC_Mode<AES>::Decryption Decryptor { KEY, KEY.size(), IV };

    string sText = "This Text will be Encryted";
    string sEnc, sDec;

    while(getline (cin, sText)){
        try {
            sEnc = Encrypt(Encryptor, sText);
            sDec = Decrypt(Decryptor, sEnc);
        } catch (exception &ex) {
            cerr << ex.what() << endl;
        }

        cout<<"Text: "<<sDec<<endl;
        cout<<"Encryted: "<<sEnc<<endl;
        cout<<"Decryted: "<<sDec<<endl;
    }

	return 0;
}
