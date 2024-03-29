#include <stack>
#include <string>
#include <vector>

#include "mycrypto/sha256.h"
#include "utils.h"


// Description of Script opcodes: https://en.bitcoin.it/wiki/Script
using namespace std;


typedef bool (*OpFunc)(stack<vector<uint8_t>>&);

struct OpFuncStruct {
  char func_name[32];
  OpFunc func_ptr ;   
}; 

bool op_notimplemented(stack<vector<uint8_t>>& data_stack) {
  return false;
} 

bool op_disabled(stack<vector<uint8_t>>& data_stack) {
  fprintf(stderr, "Disabled function called\n");
  return false;
}

bool op_invalid(stack<vector<uint8_t>>& data_stack) {
  return false;
}

bool op_0(stack<vector<uint8_t>>& data_stack) {
  return false;
}

bool op_dup(stack<vector<uint8_t>>& data_stack) {
  if (data_stack.empty()) {
    return false;
  }
  data_stack.push(data_stack.top());
  return true;
}

bool op_hash256(stack<vector<uint8_t>>& data_stack) {
  if (data_stack.empty()) {
    return false;
  }
  vector<uint8_t> ele = data_stack.top();
  data_stack.pop();
  uint8_t hash_bytes[SHA256_HASH_SIZE];
  cal_sha256_hash(ele.data(), ele.size(), hash_bytes);
  cal_sha256_hash(hash_bytes, SHA256_HASH_SIZE, hash_bytes);
  vector<uint8_t> hash(SHA256_HASH_SIZE);
  memcpy(hash.data(), hash_bytes, SHA256_HASH_SIZE * sizeof(uint8_t));
  data_stack.push(hash);
  return true;
}

bool op_hash160(stack<vector<uint8_t>>& data_stack) {
  if (data_stack.empty()) {
    return false;
  }
  vector<uint8_t> ele = data_stack.top();
  // #include'ing ripemd160 introduce a conflict...so we use 20 instead of RIPEMD160_HASH_SIZE
  data_stack.pop();
  uint8_t hash_bytes[20];
  hash160(ele.data(), ele.size(), hash_bytes);
  vector<uint8_t> hash(20);
  memcpy(hash.data(), hash_bytes, 20 * sizeof(uint8_t));
  data_stack.push(hash);
  return true;
}


OpFuncStruct get_opcode(size_t op_id) {

  if (op_id > 256) {
    return OpFuncStruct{"OP_NOTIMPLEMENTED", &op_notimplemented};
  }
  if (op_id > 254) {
    // Some silly/malicious clients could invoke this
    // we follow the format used by https://blockstream.info/api/tx/
    OpFuncStruct tmp = {"", &op_invalid};
    sprintf(tmp.func_name, "OP_INVALIDOPCODE");
    return tmp;
  }
  if (op_id > 186) {
    // Some silly/malicious clients could invoke this
    // we follow the format used by https://blockstream.info/api/tx/
    OpFuncStruct tmp = {"", &op_notimplemented};
    sprintf(tmp.func_name, "OP_RETURN_%ld", op_id);
    return tmp;
  }
  OpFuncStruct Ops[187];
  for (size_t i = 0; i < sizeof(Ops) / sizeof(Ops[0]); ++i) {
    Ops[i] = OpFuncStruct{"OP_NOTIMPLEMENTED", &op_notimplemented};
  }
  Ops[  0] = OpFuncStruct{"OP_0",                   &op_0};
  Ops[ 76] = OpFuncStruct{"OP_PUSHDATA1",           &op_notimplemented};
  Ops[ 77] = OpFuncStruct{"OP_PUSHDATA2",           &op_notimplemented};
  Ops[ 78] = OpFuncStruct{"OP_PUSHDATA4",           &op_notimplemented};
  Ops[ 79] = OpFuncStruct{"OP_PUSHNUM_NEG1",        &op_notimplemented}; // a.k.a. OP_1NEGATE
  Ops[ 80] = OpFuncStruct{"OP_RESERVED",            &op_notimplemented};
  Ops[ 81] = OpFuncStruct{"OP_PUSHNUM_1",           &op_notimplemented};
  Ops[ 82] = OpFuncStruct{"OP_PUSHNUM_2",           &op_notimplemented};
  Ops[ 83] = OpFuncStruct{"OP_PUSHNUM_3",           &op_notimplemented};
  Ops[ 84] = OpFuncStruct{"OP_PUSHNUM_4",           &op_notimplemented};
  Ops[ 85] = OpFuncStruct{"OP_PUSHNUM_5",           &op_notimplemented};
  Ops[ 86] = OpFuncStruct{"OP_PUSHNUM_6",           &op_notimplemented};
  Ops[ 87] = OpFuncStruct{"OP_PUSHNUM_7",           &op_notimplemented};
  Ops[ 88] = OpFuncStruct{"OP_PUSHNUM_8",           &op_notimplemented};
  Ops[ 89] = OpFuncStruct{"OP_PUSHNUM_9",           &op_notimplemented};
  Ops[ 90] = OpFuncStruct{"OP_PUSHNUM_10",          &op_notimplemented};
  Ops[ 91] = OpFuncStruct{"OP_PUSHNUM_11",          &op_notimplemented};
  Ops[ 92] = OpFuncStruct{"OP_PUSHNUM_12",          &op_notimplemented};
  Ops[ 93] = OpFuncStruct{"OP_PUSHNUM_13",          &op_notimplemented};
  Ops[ 94] = OpFuncStruct{"OP_PUSHNUM_14",          &op_notimplemented};
  Ops[ 95] = OpFuncStruct{"OP_PUSHNUM_15",          &op_notimplemented};
  Ops[ 96] = OpFuncStruct{"OP_PUSHNUM_16",          &op_notimplemented};

  // Flow control
  Ops[ 97] = OpFuncStruct{"OP_NOP",                 &op_notimplemented};
  Ops[ 98] = OpFuncStruct{"OP_VER",                 &op_invalid};
  Ops[ 99] = OpFuncStruct{"OP_IF",                  &op_notimplemented};
  Ops[100] = OpFuncStruct{"OP_NOTIF",               &op_notimplemented};
  Ops[101] = OpFuncStruct{"OP_VERIF",               &op_invalid};
  Ops[103] = OpFuncStruct{"OP_ELSE",                &op_notimplemented};
  Ops[104] = OpFuncStruct{"OP_ENDIF",               &op_notimplemented};  
  Ops[106] = OpFuncStruct{"OP_RETURN",              &op_notimplemented};
  
  // Stack operation
  Ops[107] = OpFuncStruct{"OP_TOALTSTACK",          &op_notimplemented};
  Ops[108] = OpFuncStruct{"OP_FROMALTSTACK",        &op_notimplemented};
  Ops[109] = OpFuncStruct{"OP_2DROP",               &op_notimplemented};
  Ops[110] = OpFuncStruct{"OP_2DUP",                &op_notimplemented};
  Ops[111] = OpFuncStruct{"OP_3DUP",                &op_notimplemented};
  Ops[112] = OpFuncStruct{"OP_2OVER",               &op_notimplemented};
  Ops[113] = OpFuncStruct{"OP_2ROT",                &op_notimplemented};
  Ops[114] = OpFuncStruct{"OP_2SWAP",               &op_notimplemented};
  Ops[115] = OpFuncStruct{"OP_IFDUP",               &op_notimplemented};
  Ops[116] = OpFuncStruct{"OP_DEPTH",               &op_notimplemented};
  Ops[117] = OpFuncStruct{"OP_DROP",                &op_notimplemented};
  Ops[118] = OpFuncStruct{"OP_DUP",                 &op_dup};
  Ops[119] = OpFuncStruct{"OP_NIP",                 &op_notimplemented};  
  Ops[120] = OpFuncStruct{"OP_OVER",                &op_notimplemented};
  Ops[121] = OpFuncStruct{"OP_PICK",                &op_notimplemented};
  Ops[122] = OpFuncStruct{"OP_ROLL",                &op_notimplemented};  
  Ops[123] = OpFuncStruct{"OP_ROT",                 &op_notimplemented};
  Ops[124] = OpFuncStruct{"OP_SWAP",                &op_notimplemented};  
  Ops[125] = OpFuncStruct{"OP_TUCK",                &op_notimplemented};

  // Splice operation
  Ops[126] = OpFuncStruct{"OP_CAT",                 &op_notimplemented};
  Ops[127] = OpFuncStruct{"OP_SUBSTR",              &op_disabled};
  Ops[128] = OpFuncStruct{"OP_LEFT",                &op_disabled};
  Ops[129] = OpFuncStruct{"OP_RIGHT",               &op_disabled};
  Ops[130] = OpFuncStruct{"OP_SIZE",                &op_notimplemented};
  Ops[131] = OpFuncStruct{"OP_INVERT",              &op_notimplemented};
  Ops[132] = OpFuncStruct{"OP_AND",                 &op_notimplemented};
  Ops[133] = OpFuncStruct{"OP_OR",                  &op_notimplemented};
  Ops[134] = OpFuncStruct{"OP_XOR",                 &op_notimplemented};
  Ops[135] = OpFuncStruct{"OP_EQUAL",               &op_notimplemented};
  Ops[136] = OpFuncStruct{"OP_EQUALVERIFY",         &op_notimplemented};
  Ops[137] = OpFuncStruct{"OP_RESERVED1",           &op_invalid};
  Ops[138] = OpFuncStruct{"OP_RESERVED2",           &op_invalid};
    
  // Arithmetic operation
  Ops[139] = OpFuncStruct{"OP_1ADD",                &op_notimplemented};
  Ops[140] = OpFuncStruct{"OP_1SUB",                &op_notimplemented};
  Ops[141] = OpFuncStruct{"OP_2MUL",                &op_disabled};
  Ops[142] = OpFuncStruct{"OP_2DIV",                &op_notimplemented};
  Ops[143] = OpFuncStruct{"OP_NEGATE",              &op_notimplemented};
  Ops[144] = OpFuncStruct{"OP_ABS",                 &op_notimplemented};
  Ops[145] = OpFuncStruct{"OP_NOT",                 &op_notimplemented};
  Ops[146] = OpFuncStruct{"OP_0NOTEQUAL",           &op_notimplemented};
  Ops[147] = OpFuncStruct{"OP_ADD",                 &op_notimplemented};
  Ops[148] = OpFuncStruct{"OP_SUB",                 &op_notimplemented};
  Ops[149] = OpFuncStruct{"OP_MUL",                 &op_notimplemented};
  Ops[150] = OpFuncStruct{"OP_DIV",                 &op_disabled};
  Ops[151] = OpFuncStruct{"OP_MOD",                 &op_disabled};
  Ops[152] = OpFuncStruct{"OP_LSHIFT",              &op_disabled};
  Ops[153] = OpFuncStruct{"OP_RSHIFT",              &op_notimplemented};
  Ops[154] = OpFuncStruct{"OP_BOOLAND",             &op_notimplemented};
  Ops[155] = OpFuncStruct{"OP_BOOLOR",              &op_notimplemented};
  Ops[156] = OpFuncStruct{"OP_NUMEQUAL",            &op_notimplemented};
  Ops[157] = OpFuncStruct{"OP_NUMEQUALVERIFY",      &op_notimplemented};
  Ops[158] = OpFuncStruct{"OP_NUMNOTEQUAL",         &op_notimplemented};
  Ops[159] = OpFuncStruct{"OP_LESSTHAN",            &op_notimplemented};
  Ops[160] = OpFuncStruct{"OP_GREATERTHAN",         &op_notimplemented};
  Ops[161] = OpFuncStruct{"OP_LESSTHANOREQUAL",     &op_notimplemented};
  Ops[162] = OpFuncStruct{"OP_GREATERTHANOREQUAL",  &op_notimplemented};
  Ops[163] = OpFuncStruct{"OP_MIN",                 &op_notimplemented};
  Ops[164] = OpFuncStruct{"OP_MAX",                 &op_notimplemented};
  Ops[165] = OpFuncStruct{"OP_WITHIN",              &op_notimplemented};
  
  // Crypto operation  
  Ops[166] = OpFuncStruct{"OP_RIPEMD160",           &op_notimplemented};
  Ops[167] = OpFuncStruct{"OP_SHA1",                &op_notimplemented};
  Ops[168] = OpFuncStruct{"OP_SHA256",              &op_notimplemented};
  Ops[169] = OpFuncStruct{"OP_HASH160",             &op_hash160};
  Ops[170] = OpFuncStruct{"OP_HASH256",             &op_hash256};
  Ops[171] = OpFuncStruct{"OP_CODESEPARATOR",       &op_notimplemented};
  Ops[172] = OpFuncStruct{"OP_CHECKSIG",            &op_notimplemented};
  Ops[173] = OpFuncStruct{"OP_CHECKSIGVERIFY",      &op_notimplemented};
  Ops[174] = OpFuncStruct{"OP_CHECKMULTISIG",       &op_notimplemented};
  Ops[175] = OpFuncStruct{"OP_CHECKMULTISIGVERIFY", &op_notimplemented};
  Ops[176] = OpFuncStruct{"OP_NOP1",                &op_notimplemented};
  Ops[177] = OpFuncStruct{"OP_CLTV",                &op_notimplemented}; // a.k.a. OP_CHECKLOCKTIMEVERIFY
  Ops[178] = OpFuncStruct{"OP_CSV",                 &op_notimplemented}; // a.k.a. OP_CHECKSEQUENCEVERIFY
  Ops[179] = OpFuncStruct{"OP_NOP4",                &op_notimplemented};
  Ops[180] = OpFuncStruct{"OP_NOP5",                &op_notimplemented};
  Ops[181] = OpFuncStruct{"OP_NOP6",                &op_notimplemented};
  Ops[182] = OpFuncStruct{"OP_NOP7",                &op_notimplemented};
  Ops[183] = OpFuncStruct{"OP_NOP8",                &op_notimplemented};
  Ops[184] = OpFuncStruct{"OP_NOP9",                &op_notimplemented};
  Ops[185] = OpFuncStruct{"OP_NOP10",               &op_notimplemented};
  Ops[186] = OpFuncStruct{"OP_CHECKSIGADD",         &op_notimplemented};

  // Reserved words
  Ops[102] = OpFuncStruct{"OP_VERNOTIF",            &op_invalid};
  Ops[105] = OpFuncStruct{"OP_VERIFY",              &op_invalid};
  return Ops[op_id];
}
