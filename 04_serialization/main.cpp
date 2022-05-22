#include "ecc.h"
#include "utils.h"
#include "misc.h"
#include "sha256.h"
#include "hmac.h"

void test_uncompressed_sec_format() {
  cout << "test_uncompressed_sec_format():" << endl;
  unsigned char private_key_bytes3[] = { 0x0d, 0xea, 0xdb, 0xee, 0xf1, 0x23, 0x45 };
  ECDSAKey pk3 = ECDSAKey(private_key_bytes3, sizeof(private_key_bytes3));
  unsigned char* sec = pk3.public_key().get_sec_format(false);
  for (int i = 0; i < (32 * 2 + 1); ++i)
    cout << hex << setfill('0') << setw(2) << (int)sec[i] << "";
  cout << endl;
  delete sec;
}

void test_compressed_sec_format() {
  cout << "test_compressed_sec_format():" << endl;
  unsigned char private_key_bytes3[] = { 0x0d, 0xea, 0xdb, 0xee, 0xf5, 0x43, 0x21 };
  ECDSAKey pk3 = ECDSAKey(private_key_bytes3, sizeof(private_key_bytes3));
  unsigned char* sec = pk3.public_key().get_sec_format(true);
  for (int i = 0; i < (32 + 1); ++i)
    cout << hex << setfill('0') << setw(2) << (int)sec[i] << "";
  cout << endl;
  delete sec;
}

int main() {
  test_uncompressed_sec_format();
  cout << endl;
  test_compressed_sec_format();
  cout << endl;
  int256_t a = 12345;
  unsigned char a_bytes[32];
  get_bytes_from_int256(a, false, a_bytes);
  for (int i = 0; i < (32); ++i)
    cout << hex << setfill('0') << setw(2) << (int)a_bytes[i] << "";
  cout << endl;
}