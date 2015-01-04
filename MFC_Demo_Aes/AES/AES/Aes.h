#pragma once
#include <iostream>
#include <fstream>
#include <bitset>
#include <string>
#define Nr 10   // AES-128��Ҫ 10 �ּ���
#define Nk 4    // Nk ��ʾ������Կ�� Word ����
using namespace std; 
typedef bitset<8> Byte;
typedef bitset<32> Word;

class Aes
{
private:
	static Byte S_Box[16][16];         // S��
	static Byte Inv_S_Box[16][16];     // ��S��
	static Byte Mul_02[256];           // GF(2^8)�˷���
	static Byte Mul_03[256];
	static Byte Mul_09[256];
	static Byte Mul_0b[256];
	static Byte Mul_0d[256];
	static Byte Mul_0e[256];
	static Word Rcon[10];              // �ֳ���

public:
	void SubBytes(Byte mtx[]);               // S�б任
	void ShiftRows(Byte mtx[]);              // �б任
	void MixColumns(Byte mtx[]);             // �б任
	void AddRoundKey(Byte mtx[], Word k[]);  // ����Կ�ӱ任

	void InvSubBytes(Byte mtx[]);            // ��S�б任
	void InvShiftRows(Byte mtx[]);           // ���б任
	void InvMixColumns(Byte mtx[]);          // ���б任

	Word word(Byte&, Byte&, Byte&, Byte&);   // �ϲ��ĸ�ByteΪһ��Word
	Word RotWord(Word& rw);                  // ���ֽ�ѭ������
	Word SubWord(Word& sw);                  // ��ÿ���ֽڽ���S-�б任
	void KeyExpansion(Byte key[], Word w[]); // ��Կ��չ����

	void encrypt(Byte in[], Word w[]);       // ����
	void decrypt(Byte in[], Word w[]);       // ����

	void charToByte(Byte out[], const char s[]);
	void divideByte(Byte out[], bitset<128>&);
	bitset<128> mergeByte(Byte in[]);
};

