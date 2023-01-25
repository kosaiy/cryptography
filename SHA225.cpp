int main(int argc, char* argv[])
{
	AutoSeededRandomPool prng;
	SecByteBlock key(16);
	prng.GenerateBlock(key, key.size());

	string plain = "HMAC Text";
	string mac, encoded;

	// print key
	encoded.clear();
	StringSource(key, key.size(), true,
		new HexEncoder(
			new StringSink(encoded)
		) // HexEncoder
	); // StringSource
	cout << "key: " << encoded << endl;
	cout << "plain text: " << plain << endl;

    HMAC<SHA256> hmac(key, key.size());
    StringSource(plain, true,
			new HashFilter(hmac,
				new StringSink(mac)
			) // HashFilter
    ); // StringSource

    // print
    encoded.clear();
    StringSource ss3(mac, true,
        new HexEncoder(
            new StringSink(encoded)
        ) // HexEncoder
    ); // StringSource

    cout << "hmac: " << encoded << endl;
}
